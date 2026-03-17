#ifndef AUDIOCONTROLLER_HPP
#define AUDIOCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QAudioDevice>
#include <QHostAddress>
#include <QElapsedTimer>

class SoundInput;
class SoundOutput;
class Detector;
class NetworkAudioInput;
class NetworkAudioOutput;
class DiscoveryService;

#include "Modulator/Modulator.hpp"

class AudioController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool monitoring READ monitoring WRITE setMonitoring NOTIFY monitoringChanged)
    Q_PROPERTY(bool txEnabled READ txEnabled WRITE setTxEnabled NOTIFY txEnabledChanged)
    Q_PROPERTY(float rxLevel READ rxLevel WRITE setRxLevel NOTIFY rxLevelChanged)
    Q_PROPERTY(float txLevel READ txLevel WRITE setTxLevel NOTIFY txLevelChanged)
    Q_PROPERTY(float rxPeakLevel READ rxPeakLevel NOTIFY rxPeakLevelChanged)
    Q_PROPERTY(QString rxDevice READ rxDevice WRITE setRxDevice NOTIFY rxDeviceChanged)
    Q_PROPERTY(QString txDevice READ txDevice WRITE setTxDevice NOTIFY txDeviceChanged)
    Q_PROPERTY(int sampleRate READ sampleRate NOTIFY sampleRateChanged)

    // WiFi Bridge properties
    Q_PROPERTY(bool wifiMode READ wifiMode WRITE setWifiMode NOTIFY wifiModeChanged)
    Q_PROPERTY(QString bridgeAddress READ bridgeAddress WRITE setBridgeAddress NOTIFY bridgeAddressChanged)
    Q_PROPERTY(bool bridgeConnected READ bridgeConnected NOTIFY bridgeConnectedChanged)

    // Soundcard drift detection
    Q_PROPERTY(double soundcardDriftPpm READ soundcardDriftPpm NOTIFY soundcardDriftPpmChanged)
    Q_PROPERTY(double soundcardDriftMsPerPeriod READ soundcardDriftMsPerPeriod NOTIFY soundcardDriftMsPerPeriodChanged)
    Q_PROPERTY(QString driftSeverity READ driftSeverity NOTIFY driftSeverityChanged)

public:
    explicit AudioController(QObject *parent = nullptr);
    ~AudioController() override;

    void initialize();

    bool monitoring() const;
    void setMonitoring(bool on);

    bool txEnabled() const;
    void setTxEnabled(bool on);

    float rxLevel() const;
    void setRxLevel(float level);

    float txLevel() const;
    void setTxLevel(float level);

    float rxPeakLevel() const;

    QString rxDevice() const;
    void setRxDevice(const QString &device);

    QString txDevice() const;
    void setTxDevice(const QString &device);

    int sampleRate() const;

    // WiFi Bridge
    bool wifiMode() const;
    void setWifiMode(bool on);

    QString bridgeAddress() const;
    void setBridgeAddress(const QString &addr);

    bool bridgeConnected() const;

    Detector *detector() const { return m_detector; }
    Modulator *modulator() const { return m_modulator; }
    SoundOutput *soundOutput() const { return m_soundOutput; }

    // Drift detection accessors
    double soundcardDriftPpm() const { return m_driftPpm; }
    double soundcardDriftMsPerPeriod() const { return m_driftMsPerPeriod; }
    QString driftSeverity() const;
    void setCurrentPeriod(double period) { m_currentPeriod = period; }

    Q_INVOKABLE void startMonitoring();
    Q_INVOKABLE void stopMonitoring();
    Q_INVOKABLE QStringList availableInputDevices() const;
    Q_INVOKABLE QStringList availableOutputDevices() const;

    // WiFi Bridge methods
    Q_INVOKABLE void connectToBridge();
    Q_INVOKABLE void disconnectFromBridge();
    Q_INVOKABLE void startBridgeDiscovery();

    // WiFi TX: start/stop pulling audio from Modulator to send via bridge
    void startWifiTx();
    void stopWifiTx();

    // WiFi CAT: forward freq/mode/ptt to bridge
    void sendCatFreqToBridge(quint64 freqHz);
    void sendCatModeToBridge(const QString &mode);
    void sendCatPttToBridge(bool on);

    // Accessor for network input (used to wire CAT status in main.cpp)
    NetworkAudioInput *networkInput() const { return m_networkInput; }

signals:
    void monitoringChanged();
    void txEnabledChanged();
    void rxLevelChanged();
    void txLevelChanged();
    void rxPeakLevelChanged();
    void rxDeviceChanged();
    void txDeviceChanged();
    void sampleRateChanged();
    void wifiModeChanged();
    void bridgeAddressChanged();
    void bridgeConnectedChanged();
    void audioError(const QString &message);
    void audioStatus(const QString &message);
    void framesWritten(qint64 nFrames);
    void bridgeDiscovered(const QString &address, quint16 port);
    void soundcardDriftPpmChanged();
    void soundcardDriftMsPerPeriodChanged();
    void driftSeverityChanged();

public slots:
    void updateRxPeakLevel(float peak);
    void onModeChanged(const QString &mode);

private slots:
    void onAudioError(const QString &msg);
    void onAudioStatus(const QString &msg);
    void onFramesWritten(qint64 nFrames);
    void onBridgeConnected();
    void onBridgeDisconnected();
    void onBridgeDiscovered(const QHostAddress &address, quint16 port);
    void onModulatorStateChanged(Modulator::ModulatorState state);

private:
    QAudioDevice findInputDevice(const QString &name) const;
    QAudioDevice findOutputDevice(const QString &name) const;

    bool m_monitoring = false;
    bool m_txEnabled = false;
    bool m_initialized = false;
    float m_rxLevel = 50.0f;
    float m_txLevel = 50.0f;
    float m_rxPeakLevel = 0.0f;
    QString m_rxDevice;
    QString m_txDevice;
    int m_sampleRate = 48000;

    // WiFi Bridge state
    bool m_wifiMode = false;
    QString m_bridgeAddress;
    bool m_bridgeConnected = false;

    // Audio backend objects
    QThread m_audioThread;
    SoundInput *m_soundInput = nullptr;
    SoundOutput *m_soundOutput = nullptr;
    Detector *m_detector = nullptr;
    Modulator *m_modulator = nullptr;
    QAudioDevice m_inputDevice;
    QAudioDevice m_outputDevice;

    // WiFi audio objects
    NetworkAudioInput *m_networkInput = nullptr;
    NetworkAudioOutput *m_networkOutput = nullptr;
    DiscoveryService *m_discovery = nullptr;

    static constexpr unsigned RX_SAMPLE_RATE = 48000;
    static constexpr unsigned TX_SAMPLE_RATE = 48000;
    static constexpr unsigned DOWN_SAMPLE_FACTOR = 4;
    static constexpr unsigned WIFI_DOWN_SAMPLE_FACTOR = 1; // data arrives at 12kHz
    static constexpr double DEFAULT_PERIOD = 15.0;  // FT8

    // Soundcard drift detection
    QElapsedTimer m_driftClock;
    qint64 m_driftFrameCount = 0;
    double m_driftPpm = 0.0;
    double m_driftMsPerPeriod = 0.0;
    double m_currentPeriod = DEFAULT_PERIOD;
    qint64 m_lastDriftCheckFrames = 0;
};

#endif // AUDIOCONTROLLER_HPP
