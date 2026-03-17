#include "AudioController.hpp"
#include "Audio/soundin.h"
#include "Audio/soundout.h"
#include "Detector/Detector.hpp"
#include "Modulator/Modulator.hpp"
#include "Audio/NetworkAudioInput.hpp"
#include "Audio/NetworkAudioOutput.hpp"
#include "bridge/DiscoveryService.hpp"

#include <QSettings>
#include <QMediaDevices>
#include <QHostAddress>
#include <QtMath>
#include <QDebug>
#include <algorithm>

AudioController::AudioController(QObject *parent)
    : QObject(parent)
{
    // Load saved audio settings
    QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
    settings.beginGroup(QStringLiteral("Audio"));
    m_rxDevice = settings.value(QStringLiteral("RxDevice"), QString()).toString();
    m_txDevice = settings.value(QStringLiteral("TxDevice"), QString()).toString();
    m_rxLevel = settings.value(QStringLiteral("RxLevel"), 50.0f).toFloat();
    m_txLevel = settings.value(QStringLiteral("TxLevel"), 50.0f).toFloat();
    settings.endGroup();

    // Load WiFi bridge settings
    settings.beginGroup(QStringLiteral("WiFiBridge"));
    m_wifiMode = settings.value(QStringLiteral("Enabled"), false).toBool();
    m_bridgeAddress = settings.value(QStringLiteral("Address"), QString()).toString();
    settings.endGroup();
}

AudioController::~AudioController()
{
    if (m_initialized) {
        // Stop monitoring if active
        if (m_monitoring) {
            QMetaObject::invokeMethod(m_soundInput, "stop", Qt::BlockingQueuedConnection);
        }

        // Stop audio thread
        m_audioThread.quit();
        m_audioThread.wait(3000);
    }
}

void AudioController::initialize()
{
    if (m_initialized) return;

    qDebug() << "AudioController: initializing audio subsystem";

    // Create audio objects
    m_soundInput = new SoundInput;
    m_soundOutput = new SoundOutput;
    m_detector = new Detector(RX_SAMPLE_RATE, DEFAULT_PERIOD, DOWN_SAMPLE_FACTOR);
    m_modulator = new Modulator(TX_SAMPLE_RATE, DEFAULT_PERIOD);

    // Move audio objects to audio thread
    m_soundInput->moveToThread(&m_audioThread);
    m_detector->moveToThread(&m_audioThread);
    m_soundOutput->moveToThread(&m_audioThread);
    m_modulator->moveToThread(&m_audioThread);

    // Connect SoundInput signals
    connect(m_soundInput, &SoundInput::error,
            this, &AudioController::onAudioError);
    connect(m_soundInput, &SoundInput::status,
            this, &AudioController::onAudioStatus);

    // Connect Detector framesWritten → relay to our signal
    connect(m_detector, &Detector::framesWritten,
            this, &AudioController::onFramesWritten);

    // Connect SoundOutput signals
    connect(m_soundOutput, &SoundOutput::error,
            this, &AudioController::onAudioError);
    connect(m_soundOutput, &SoundOutput::status,
            this, &AudioController::onAudioStatus);

    // Connect Modulator stateChanged for WiFi TX forwarding
    connect(m_modulator, &Modulator::stateChanged,
            this, &AudioController::onModulatorStateChanged);

    // Clean up when thread finishes
    connect(&m_audioThread, &QThread::finished, m_soundInput, &QObject::deleteLater);
    connect(&m_audioThread, &QThread::finished, m_soundOutput, &QObject::deleteLater);
    connect(&m_audioThread, &QThread::finished, m_detector, &QObject::deleteLater);
    connect(&m_audioThread, &QThread::finished, m_modulator, &QObject::deleteLater);

    // Start audio thread
    m_audioThread.start(QThread::HighPriority);

    // Resolve initial audio devices
    if (!m_rxDevice.isEmpty()) {
        m_inputDevice = findInputDevice(m_rxDevice);
    }
    if (m_inputDevice.isNull()) {
        m_inputDevice = QMediaDevices::defaultAudioInput();
        m_rxDevice = m_inputDevice.description();
        emit rxDeviceChanged();
    }

    if (!m_txDevice.isEmpty()) {
        m_outputDevice = findOutputDevice(m_txDevice);
    }
    if (m_outputDevice.isNull()) {
        m_outputDevice = QMediaDevices::defaultAudioOutput();
        m_txDevice = m_outputDevice.description();
        emit txDeviceChanged();
    }

    // Configure SoundOutput for TX (mono, 48kHz — format set before first restart)
    if (!m_outputDevice.isNull()) {
        QMetaObject::invokeMethod(m_soundOutput, "setFormat",
            Qt::QueuedConnection,
            Q_ARG(QAudioDevice, m_outputDevice),
            Q_ARG(unsigned, 1),
            Q_ARG(int, 0));
    }

    m_initialized = true;

    qDebug() << "AudioController: initialized"
             << "RX:" << m_inputDevice.description()
             << "TX:" << m_outputDevice.description();
}

// --- Property getters/setters ---

bool AudioController::monitoring() const { return m_monitoring; }

void AudioController::setMonitoring(bool on)
{
    if (m_monitoring != on) {
        if (on) startMonitoring();
        else stopMonitoring();
    }
}

bool AudioController::txEnabled() const { return m_txEnabled; }

void AudioController::setTxEnabled(bool on)
{
    if (m_txEnabled != on) {
        m_txEnabled = on;
        emit txEnabledChanged();
    }
}

float AudioController::rxLevel() const { return m_rxLevel; }

void AudioController::setRxLevel(float level)
{
    float clamped = std::clamp(level, 0.0f, 100.0f);
    if (!qFuzzyCompare(m_rxLevel, clamped)) {
        m_rxLevel = clamped;
        emit rxLevelChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Audio/RxLevel"), m_rxLevel);
    }
}

float AudioController::txLevel() const { return m_txLevel; }

void AudioController::setTxLevel(float level)
{
    float clamped = std::clamp(level, 0.0f, 100.0f);
    if (!qFuzzyCompare(m_txLevel, clamped)) {
        m_txLevel = clamped;
        emit txLevelChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Audio/TxLevel"), m_txLevel);
    }
}

float AudioController::rxPeakLevel() const { return m_rxPeakLevel; }

QString AudioController::rxDevice() const { return m_rxDevice; }

void AudioController::setRxDevice(const QString &device)
{
    if (m_rxDevice != device) {
        m_rxDevice = device;
        emit rxDeviceChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Audio/RxDevice"), m_rxDevice);

        // Update actual audio device
        m_inputDevice = findInputDevice(device);
        if (m_inputDevice.isNull()) {
            m_inputDevice = QMediaDevices::defaultAudioInput();
        }

        // Restart monitoring if active
        if (m_monitoring && m_initialized) {
            QMetaObject::invokeMethod(m_soundInput, "stop", Qt::QueuedConnection);
            startMonitoring();
        }
    }
}

QString AudioController::txDevice() const { return m_txDevice; }

void AudioController::setTxDevice(const QString &device)
{
    if (m_txDevice != device) {
        m_txDevice = device;
        emit txDeviceChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Audio/TxDevice"), m_txDevice);

        m_outputDevice = findOutputDevice(device);
        if (m_outputDevice.isNull()) {
            m_outputDevice = QMediaDevices::defaultAudioOutput();
        }
    }
}

int AudioController::sampleRate() const { return m_sampleRate; }

// --- Monitoring control ---

void AudioController::startMonitoring()
{
    if (!m_initialized) {
        qWarning() << "AudioController: not initialized, call initialize() first";
        return;
    }

    // WiFi mode: connect to bridge instead of local audio
    if (m_wifiMode) {
        connectToBridge();
        return;
    }

    // Local audio mode
    if (m_inputDevice.isNull()) {
        emit audioError(tr("No audio input device available"));
        return;
    }

    qDebug() << "AudioController: starting monitoring on" << m_inputDevice.description();

    // Initialize detector for receiving
    m_detector->initialize(QIODevice::WriteOnly, AudioDevice::Mono);

    // Start audio input in audio thread
    QMetaObject::invokeMethod(m_soundInput, "start",
        Qt::QueuedConnection,
        Q_ARG(QAudioDevice, m_inputDevice),
        Q_ARG(int, 8192),
        Q_ARG(AudioDevice*, m_detector),
        Q_ARG(unsigned, DOWN_SAMPLE_FACTOR),
        Q_ARG(AudioDevice::Channel, AudioDevice::Mono));

    // Reset drift measurement on start
    m_driftClock.invalidate();
    m_driftFrameCount = 0;
    m_lastDriftCheckFrames = 0;
    m_driftPpm = 0.0;
    m_driftMsPerPeriod = 0.0;

    m_monitoring = true;
    emit monitoringChanged();
}

void AudioController::stopMonitoring()
{
    if (!m_initialized) return;

    qDebug() << "AudioController: stopping monitoring";

    if (m_wifiMode) {
        disconnectFromBridge();
    } else {
        QMetaObject::invokeMethod(m_soundInput, "stop", Qt::QueuedConnection);
    }

    m_monitoring = false;
    m_rxPeakLevel = 0.0f;
    emit rxPeakLevelChanged();
    emit monitoringChanged();
}

// --- Device enumeration ---

QStringList AudioController::availableInputDevices() const
{
    QStringList list;
    for (auto const& dev : QMediaDevices::audioInputs()) {
        list << dev.description();
    }
    return list;
}

QStringList AudioController::availableOutputDevices() const
{
    QStringList list;
    for (auto const& dev : QMediaDevices::audioOutputs()) {
        list << dev.description();
    }
    return list;
}

// --- Slots ---

void AudioController::updateRxPeakLevel(float peak)
{
    float clamped = std::clamp(peak, 0.0f, 100.0f);
    if (!qFuzzyCompare(m_rxPeakLevel, clamped)) {
        m_rxPeakLevel = clamped;
        emit rxPeakLevelChanged();
    }
}

void AudioController::onModeChanged(const QString &mode)
{
    double period = DEFAULT_PERIOD;
    if (mode == QLatin1String("FT8"))       period = 15.0;
    else if (mode == QLatin1String("FT4"))  period = 7.5;
    else if (mode == QLatin1String("FT2"))  period = 3.75;
    else if (mode == QLatin1String("JT65")) period = 60.0;
    else if (mode == QLatin1String("JT9"))  period = 60.0;
    else if (mode == QLatin1String("WSPR")) period = 120.0;

    qDebug() << "AudioController: mode changed to" << mode << "TR period:" << period;

    m_currentPeriod = period;
    if (m_detector) m_detector->setTRPeriod(period);
    if (m_modulator) m_modulator->setTRPeriod(period);
}

void AudioController::onAudioError(const QString &msg)
{
    qWarning() << "Audio error:" << msg;
    emit audioError(msg);
}

void AudioController::onAudioStatus(const QString &msg)
{
    qDebug() << "Audio status:" << msg;
    emit audioStatus(msg);
}

void AudioController::onFramesWritten(qint64 nFrames)
{
    emit framesWritten(nFrames);

    // Soundcard drift detection
    m_driftFrameCount += (nFrames - m_lastDriftCheckFrames > 0)
        ? (nFrames - m_lastDriftCheckFrames) : nFrames;

    if (!m_driftClock.isValid()) {
        m_driftClock.start();
        m_driftFrameCount = 0;
        m_lastDriftCheckFrames = nFrames;
        return;
    }

    m_lastDriftCheckFrames = nFrames;
    qint64 elapsedMs = m_driftClock.elapsed();

    // Compute drift every ~5 seconds (minimum data for meaningful calculation)
    if (elapsedMs >= 5000) {
        // The detector runs at 12 kHz (after downsampling)
        constexpr double EFFECTIVE_RATE = 12000.0;
        double expectedSamples = (elapsedMs / 1000.0) * EFFECTIVE_RATE;
        double actualSamples = static_cast<double>(nFrames); // kin is cumulative in period

        if (expectedSamples > 0.0 && actualSamples > 1000.0) {
            double newPpm = (actualSamples - expectedSamples) / expectedSamples * 1.0e6;
            double newMsPerPeriod = newPpm * m_currentPeriod / 1000.0;

            if (std::abs(m_driftPpm - newPpm) > 0.1) {
                m_driftPpm = newPpm;
                m_driftMsPerPeriod = newMsPerPeriod;
                emit soundcardDriftPpmChanged();
                emit soundcardDriftMsPerPeriodChanged();
                emit driftSeverityChanged();
            }
        }
    }
}

QString AudioController::driftSeverity() const
{
    double absPpm = std::abs(m_driftPpm);
    if (absPpm < 10.0) return QStringLiteral("green");
    if (absPpm < 50.0) return QStringLiteral("yellow");
    return QStringLiteral("red");
}

// --- Helpers ---

QAudioDevice AudioController::findInputDevice(const QString &name) const
{
    for (auto const& dev : QMediaDevices::audioInputs()) {
        if (dev.description() == name) return dev;
    }
    return {};
}

QAudioDevice AudioController::findOutputDevice(const QString &name) const
{
    for (auto const& dev : QMediaDevices::audioOutputs()) {
        if (dev.description() == name) return dev;
    }
    return {};
}

// --- WiFi Bridge ---

bool AudioController::wifiMode() const { return m_wifiMode; }

void AudioController::setWifiMode(bool on)
{
    if (m_wifiMode != on) {
        m_wifiMode = on;
        emit wifiModeChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("WiFiBridge/Enabled"), m_wifiMode);

        if (m_monitoring) {
            stopMonitoring();
            startMonitoring();
        }
    }
}

QString AudioController::bridgeAddress() const { return m_bridgeAddress; }

void AudioController::setBridgeAddress(const QString &addr)
{
    if (m_bridgeAddress != addr) {
        m_bridgeAddress = addr;
        emit bridgeAddressChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("WiFiBridge/Address"), m_bridgeAddress);
    }
}

bool AudioController::bridgeConnected() const { return m_bridgeConnected; }

void AudioController::connectToBridge()
{
    if (!m_initialized) {
        qWarning() << "AudioController: not initialized";
        return;
    }

    if (m_bridgeAddress.isEmpty()) {
        emit audioError(tr("No bridge address configured"));
        return;
    }

    // Create network audio objects if needed
    if (!m_networkInput) {
        m_networkInput = new NetworkAudioInput(this);
        connect(m_networkInput, &NetworkAudioInput::connected,
                this, &AudioController::onBridgeConnected);
        connect(m_networkInput, &NetworkAudioInput::disconnected,
                this, &AudioController::onBridgeDisconnected);
        connect(m_networkInput, &NetworkAudioInput::error,
                this, &AudioController::onAudioError);
        connect(m_networkInput, &NetworkAudioInput::levelChanged,
                this, &AudioController::updateRxPeakLevel);
    }
    if (!m_networkOutput) {
        m_networkOutput = new NetworkAudioOutput(this);
        m_networkOutput->setNetworkInput(m_networkInput);
    }

    // Set up detector for WiFi mode (12kHz, no downsampling)
    if (m_detector) {
        delete m_detector;
    }
    m_detector = new Detector(12000, DEFAULT_PERIOD, WIFI_DOWN_SAMPLE_FACTOR);
    m_detector->initialize(QIODevice::WriteOnly, AudioDevice::Mono);
    m_networkInput->setDetector(m_detector);

    connect(m_detector, &Detector::framesWritten,
            this, &AudioController::onFramesWritten);

    m_networkInput->connectToBridge(m_bridgeAddress);
    emit audioStatus(tr("Connecting to bridge: %1").arg(m_bridgeAddress));
}

void AudioController::disconnectFromBridge()
{
    if (m_networkInput) {
        m_networkInput->disconnect();
    }
}

void AudioController::startBridgeDiscovery()
{
    if (!m_discovery) {
        m_discovery = new DiscoveryService(this);
        connect(m_discovery, &DiscoveryService::bridgeDiscovered,
                this, &AudioController::onBridgeDiscovered);
    }
    m_discovery->startListening();
    emit audioStatus(tr("Scanning for bridges on LAN..."));
}

void AudioController::onBridgeConnected()
{
    m_bridgeConnected = true;
    m_monitoring = true;
    emit bridgeConnectedChanged();
    emit monitoringChanged();
    emit audioStatus(tr("Connected to bridge"));
    qDebug() << "AudioController: bridge connected, WiFi audio active";
}

void AudioController::onBridgeDisconnected()
{
    m_bridgeConnected = false;
    m_monitoring = false;
    emit bridgeConnectedChanged();
    emit monitoringChanged();
    emit audioStatus(tr("Disconnected from bridge"));
    qDebug() << "AudioController: bridge disconnected";
}

void AudioController::onBridgeDiscovered(const QHostAddress &address, quint16 port)
{
    QString addr = address.toString();
    qDebug() << "AudioController: bridge discovered at" << addr << ":" << port;
    emit bridgeDiscovered(addr, port);
}

// --- WiFi TX ---

void AudioController::startWifiTx()
{
    if (!m_wifiMode || !m_networkOutput || !m_modulator) return;

    qDebug() << "AudioController: starting WiFi TX (pulling from Modulator)";
    m_networkOutput->startPulling(m_modulator);
}

void AudioController::stopWifiTx()
{
    if (m_networkOutput) {
        m_networkOutput->stopPulling();
        qDebug() << "AudioController: stopped WiFi TX";
    }
}

void AudioController::onModulatorStateChanged(Modulator::ModulatorState state)
{
    if (!m_wifiMode || !m_networkOutput) return;

    if (state == Modulator::Synchronizing || state == Modulator::Active) {
        // Modulator starting → begin pulling and sending over WiFi
        if (!m_networkOutput->isPulling()) {
            startWifiTx();
        }
    } else {
        // Modulator idle → stop pulling
        stopWifiTx();
    }
}

// --- WiFi CAT ---

void AudioController::sendCatFreqToBridge(quint64 freqHz)
{
    if (m_wifiMode && m_networkInput && m_bridgeConnected) {
        m_networkInput->sendCatFreq(freqHz);
    }
}

void AudioController::sendCatModeToBridge(const QString &mode)
{
    if (m_wifiMode && m_networkInput && m_bridgeConnected) {
        m_networkInput->sendCatMode(mode);
    }
}

void AudioController::sendCatPttToBridge(bool on)
{
    if (m_wifiMode && m_networkInput && m_bridgeConnected) {
        m_networkInput->sendCatPtt(on);
    }
}
