#include "DecoderController.hpp"
#include "commons.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QThread>
#include <cstring>
#include <cmath>

// Shared data — defined in main.cpp
extern dec_data_t dec_data;

// Fortran decoder and spectrum functions
typedef int fortran_charlen_t;
extern "C" {
    // Main decoder dispatch (decoder.f90)
    void multimode_decoder_(float ss[], short id2[], void *params, int *nfsample);

    // Spectrum computation (symspec.f90)
    void symspec_(void *dd, int *k, double *trperiod, int *nsps, int *ingain,
                  bool *bLowSidelobes, int *minw, float *px, float s[], float *df3,
                  int *nhsym, int *npts8, float *pxmax, int *npct);
}

DecoderController::DecoderController(QObject *parent)
    : QObject(parent)
{
    // Ensure temp directory exists for decoded.txt
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir().mkpath(dataDir);

    // Decoder watchdog timer
    m_watchdogTimer = new QTimer(this);
    m_watchdogTimer->setSingleShot(true);
    connect(m_watchdogTimer, &QTimer::timeout, this, &DecoderController::onWatchdogTimeout);
}

DecoderController::~DecoderController()
{
    // Stop watchdog
    if (m_watchdogTimer) m_watchdogTimer->stop();

    // Wait for decoder thread to finish
    if (m_decoderThread.joinable()) {
        // Give it a reasonable time, then detach if still running
        auto start = std::chrono::steady_clock::now();
        while (m_decoderRunning.load()) {
            QThread::msleep(10);
            auto elapsed = std::chrono::steady_clock::now() - start;
            if (std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() > 5) {
                m_decoderThread.detach();
                return;
            }
        }
        m_decoderThread.join();
    }
}

double DecoderController::period() const
{
    return m_period;
}

void DecoderController::setPeriod(double p)
{
    if (!qFuzzyCompare(m_period, p) && p > 0.0) {
        m_period = p;
        emit periodChanged();
    }
}

bool DecoderController::decoding() const
{
    return m_decoding;
}

int DecoderController::nDecodes() const
{
    return m_nDecodes;
}

int DecoderController::deepSearch() const
{
    return m_deepSearch;
}

void DecoderController::setDeepSearch(int level)
{
    if (m_deepSearch != level && level >= 0 && level <= 3) {
        m_deepSearch = level;
        emit deepSearchChanged();
    }
}

QString DecoderController::currentMode() const
{
    return m_currentMode;
}

void DecoderController::setCurrentMode(const QString &mode)
{
    if (m_currentMode != mode) {
        m_modeChanged = true;
        m_currentMode = mode;
        emit currentModeChanged();
        updatePeriodForMode();
    }
}

void DecoderController::setMyCall(const QString &call)
{
    m_myCall = call.toUpper().trimmed();
}

void DecoderController::setMyGrid(const QString &grid)
{
    m_myGrid = grid.toUpper().trimmed();
}

void DecoderController::setNfqso(int freq)
{
    m_nfqso = freq;
}

void DecoderController::clearDecodes()
{
    m_nDecodes = 0;
    emit nDecodesChanged();
}

void DecoderController::setFt2AsyncMode(bool v)
{
    if (m_ft2AsyncMode != v) {
        m_ft2AsyncMode = v;
        emit ft2AsyncModeChanged();
        qDebug() << "DecoderController: FT2 async mode" << (v ? "ON" : "OFF");
    }
}

void DecoderController::resetFt2SoftAvg()
{
    m_ft2SoftAvgPeriods = 0;
    m_ft2HasBufferedData = false;
    std::memset(m_ft2BitmetricsBuffer, 0, sizeof(m_ft2BitmetricsBuffer));
}

void DecoderController::decode()
{
    if (m_decoding || m_decoderRunning.load())
        return;

    m_decoding = true;
    emit decodingChanged();
    emit decodingStarted();

    // Run decoder in background thread
    m_decoderRunning.store(true);
    m_decodeElapsed.start();

    // Start watchdog: timeout = max(5s, 2× period)
    int watchdogMs = qMax(5000, static_cast<int>(2.0 * m_period * 1000));
    m_watchdogTimer->start(watchdogMs);

    // Join previous thread if still joinable
    if (m_decoderThread.joinable()) {
        m_decoderThread.join();
    }
    m_decoderThread = std::thread(&DecoderController::runDecoder, this);
}

void DecoderController::runDecoder()
{
    qDebug() << "DecoderController: starting decode for" << m_currentMode
             << "kin=" << m_lastKin << "nfqso=" << m_nfqso;

    // Prepare decoder params
    // Make a local copy of params to avoid race with audio thread
    auto params = dec_data.params;

    // Set mode
    if (m_currentMode == QLatin1String("FT8"))           params.nmode = 8;
    else if (m_currentMode == QLatin1String("FT2"))      params.nmode = 2;
    else if (m_currentMode == QLatin1String("FT4"))      params.nmode = 5;
    else if (m_currentMode == QLatin1String("JT65"))     params.nmode = 65;
    else if (m_currentMode == QLatin1String("JT9"))      params.nmode = 9;
    else if (m_currentMode == QLatin1String("WSPR"))     params.nmode = 28;
    else if (m_currentMode == QLatin1String("FST4"))     params.nmode = 240;
    else if (m_currentMode == QLatin1String("FST4W"))    params.nmode = 241;
    else if (m_currentMode == QLatin1String("Q65"))      params.nmode = 66;
    else if (m_currentMode == QLatin1String("MSK144"))   params.nmode = 144;
    else if (m_currentMode == QLatin1String("Echo"))     params.nmode = 7;
    else if (m_currentMode == QLatin1String("FreqCal"))  params.nmode = -1;
    else                                                  params.nmode = 8;

    // Set TR period
    params.ntrperiod = static_cast<int>(m_period);

    // Sample position (use last known kin before reset)
    // Clamp to valid buffer range: d2 is NTMAX*12000 = 21600000 samples
    static constexpr int MAX_KIN = NTMAX * RX_SAMPLE_RATE;
    params.kin = qBound(0, static_cast<int>(m_lastKin), MAX_KIN - 1);
    if (params.kin <= 0) params.kin = qMin(static_cast<int>(m_period * 12000), MAX_KIN - 1);

    // Need minimum samples for a valid decode
    int minSamples = static_cast<int>(m_period * 12000 * 0.5);
    if (params.kin < minSamples) {
        qDebug() << "DecoderController: not enough samples for decode, kin=" << params.kin
                 << "need at least" << minSamples;
        m_decoderRunning.store(false);
        QMetaObject::invokeMethod(m_watchdogTimer, "stop", Qt::QueuedConnection);
        QMetaObject::invokeMethod(this, "onDecodingComplete", Qt::QueuedConnection);
        return;
    }

    // Decode timing
    int utcNow = QDateTime::currentDateTimeUtc().time().hour() * 10000
               + QDateTime::currentDateTimeUtc().time().minute() * 100
               + QDateTime::currentDateTimeUtc().time().second();
    params.nutc = utcNow;

    // Decode parameters
    params.newdat = true;
    params.nagain = false;
    params.ndepth = m_deepSearch;
    params.nfqso = m_nfqso;
    params.nftx = m_nfqso;  // TX freq = RX freq unless split
    params.nfa = 200;       // low decode limit (Hz)
    params.nfb = 5000;      // high decode limit (Hz)
    params.ntol = 20;       // frequency tolerance

    // Compute nzhsym: number of half-symbols received
    // nzhsym = kin / (nsps/2), clamped to valid range
    {
        int nsps = 1920; // FT8 default
        if (params.nmode == 5)       nsps = 576;   // FT4
        else if (params.nmode == 2)  nsps = 288;   // FT2
        else if (params.nmode == 65) nsps = 4096;  // JT65
        else if (params.nmode == 9)  nsps = 6912;  // JT9

        int halfNsps = nsps / 2;
        if (halfNsps > 0)
            params.nzhsym = qBound(1, params.kin / halfNsps, 184);
        else
            params.nzhsym = 41;
    }

    // Callsigns (Fortran expects space-padded char arrays)
    std::memset(params.mycall, ' ', 12);
    std::memset(params.hiscall, ' ', 12);
    std::memset(params.mygrid, ' ', 6);
    std::memset(params.hisgrid, ' ', 6);
    if (!m_myCall.isEmpty()) {
        QByteArray mc = m_myCall.toLatin1();
        std::memcpy(params.mycall, mc.constData(), qMin(mc.size(), 12));
    }
    if (!m_myGrid.isEmpty()) {
        QByteArray mg = m_myGrid.toLatin1();
        std::memcpy(params.mygrid, mg.constData(), qMin(mg.size(), 6));
    }
    if (!m_hisCall.isEmpty()) {
        QByteArray hc = m_hisCall.toLatin1();
        std::memcpy(params.hiscall, hc.constData(), qMin(hc.size(), 12));
    }

    // AP decoding flags
    params.lft8apon = true;
    params.lapcqonly = false;
    params.napwid = 50;
    params.n2pass = 2;
    params.nranera = 6;
    params.naggressive = 0;
    params.nrobust = false;
    params.nexp_decode = 0;

    // ── FASE 1: Use member variables instead of hard-coded values ──
    params.lmultift8 = m_multithreadFT8;
    params.nft8cycles = m_ft8Cycles;
    params.nmt = m_ft8Threads;
    params.lft8lowth = (m_ft8Sensitivity == 0);
    params.lft8subpass = (m_ft8Sensitivity == 2);
    params.nft8rxfsens = (m_ft8Sensitivity == 0) ? 1 : 3;
    params.ltxing = m_txing && m_enableTx;
    params.lhideft8dupes = m_hideFT8Dupes;
    params.lenabledxcsearch = (!m_hisCall.isEmpty() && !m_enableTx);
    params.lwidedxcsearch = m_wideDxCallSearch;
    params.ndecoderstart = m_ft8DecoderStart;
    params.nft4depth = m_ft4Depth;
    params.ntrials10 = m_ntrials10;
    params.ntrialsrxf10 = m_ntrials10;
    params.ncandthin = 2;
    params.ndtcenter = 0;
    params.nharmonicsdepth = 0;
    params.ntopfreq65 = 0;
    params.nprepass = 1;
    params.nsdecatt = 0;
    params.nlasttx = 0;
    params.ndelay = 0;

    // Mode/band change tracking
    params.lmodechanged = m_modeChanged;
    params.lbandchanged = m_bandChanged;
    params.nsecbandchanged = m_nsecBandChanged;
    m_modeChanged = false;
    m_bandChanged = false;

    // Fox/Hound flags (set from TxController state via main.cpp wiring)
    params.lhound = m_houndMode;
    params.lcommonft8b = false;
    params.lmycallstd = true;
    params.lhiscallstd = true;
    params.lapmyc = false;
    params.lmultinst = false;
    params.lskiptx1 = false;
    params.nagainfil = false;
    params.nstophint = true;
    params.nhint = false;
    params.fmaskact = false;

    // Even/odd sequence from period timing
    params.b_even_seq = m_isEvenPeriod;

    // DateTime string for decoder
    QByteArray dt = QDateTime::currentDateTimeUtc().toString("yyyyMMdd_HHmmss").toLatin1();
    std::memset(params.datetime, ' ', 20);
    std::memcpy(params.datetime, dt.constData(), qMin(dt.size(), 20));

    // Date for superfox
    params.yymmdd = QDateTime::currentDateTimeUtc().toString("yyMMdd").toInt();
    params.b_superfox = m_superFoxMode;

    // Clear mybcall / hisbcall
    std::memset(params.mybcall, ' ', 12);
    std::memset(params.hisbcall, ' ', 12);

    // Write params back to shared struct (Fortran reads from dec_data.params)
    dec_data.params = params;

    // Call the Fortran decoder
    int nfsample = 12000;
    bool decoderCrashed = false;

    fprintf(stderr, "[Qt] DecoderController: calling multimode_decoder_ kin=%d nzhsym=%d nmode=%d\n",
            params.kin, params.nzhsym, params.nmode);
    fflush(stderr);

    multimode_decoder_(dec_data.ss, dec_data.d2, &dec_data.params, &nfsample);

    if (!decoderCrashed) {
        // Parse results from decoded.txt
        parseDecodedResults();
        qDebug() << "DecoderController: decode complete, found" << m_nDecodes << "decodes";
    } else {
        qWarning() << "DecoderController: decode aborted due to crash, kin=" << params.kin;
    }

    m_decoderRunning.store(false);

    // Stop watchdog from decoder thread (safe via queued)
    QMetaObject::invokeMethod(m_watchdogTimer, "stop", Qt::QueuedConnection);
    QMetaObject::invokeMethod(this, "onDecodingComplete", Qt::QueuedConnection);
}

void DecoderController::parseDecodedResults()
{
    // decoded.txt is written by decoder.f90 in the current working directory
    // Format: HHMMSS sync  SNR   DT     Freq  flag   message              mode
    //         i6.6   i4    i5    f6.1   f8.0  i4 3x  a37                  ' FT8'
    // Positions: 0-5  6-9  10-14 15-20  21-28 29-32  36-72

    QFile file(QStringLiteral("decoded.txt"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "DecoderController: could not open decoded.txt";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.length() < 40)
            continue;

        // Parse fixed-position fields
        QString utc = line.mid(0, 6).trimmed();
        int snr = line.mid(10, 5).trimmed().toInt();
        double dt = line.mid(15, 6).trimmed().toDouble();
        int freq = qRound(line.mid(21, 8).trimmed().toDouble());
        QString message = line.mid(36, 37).trimmed();

        if (utc.isEmpty() || message.isEmpty())
            continue;

        // Post result to GUI thread
        QMetaObject::invokeMethod(this, "onDecodeResult",
            Qt::QueuedConnection,
            Q_ARG(QString, utc), Q_ARG(int, snr),
            Q_ARG(double, dt), Q_ARG(int, freq),
            Q_ARG(QString, message));
    }
    file.close();
}

double DecoderController::periodForMode(const QString &mode) const
{
    if (mode == QLatin1String("FT8"))
        return 15.0;
    if (mode == QLatin1String("FT4"))
        return 7.5;
    if (mode == QLatin1String("FT2"))
        return 3.75;
    if (mode == QLatin1String("JT65"))
        return 60.0;
    if (mode == QLatin1String("JT9"))
        return 60.0;
    if (mode == QLatin1String("WSPR"))
        return 120.0;
    if (mode == QLatin1String("FST4"))
        return 15.0;  // Default FST4 period; can be 15/30/60/120/300/900/1800
    if (mode == QLatin1String("FST4W"))
        return 120.0;
    if (mode == QLatin1String("Echo"))
        return 6.0;
    if (mode == QLatin1String("FreqCal"))
        return 15.0;
    if (mode == QLatin1String("Q65"))
        return 60.0;
    if (mode == QLatin1String("MSK144"))
        return 15.0;
    return 15.0;
}

void DecoderController::onDecodeResult(const QString &utc, int snr, double dt, int freq, const QString &message)
{
    m_nDecodes++;
    emit nDecodesChanged();
    emit newDecode(utc, snr, dt, freq, message);

    // Track average DT for convergence monitoring
    m_dtSum += dt;
    m_dtCount++;
    double newAvgDt = m_dtSum / m_dtCount;
    if (!qFuzzyCompare(m_avgDt, newAvgDt)) {
        m_avgDt = newAvgDt;
        emit avgDtChanged();
    }
}

void DecoderController::onDecodingComplete()
{
    m_decoding = false;
    m_decodePending = false;
    m_watchdogTimer->stop();

    // Measure decode latency
    if (m_decodeElapsed.isValid()) {
        m_decodeLatencyMs = m_decodeElapsed.elapsed();
        emit decodeLatencyMsChanged();
    }

    emit decodingChanged();
    emit decodingFinished();
}

void DecoderController::onWatchdogTimeout()
{
    if (!m_decoderRunning.load())
        return;

    qWarning() << "DecoderController: WATCHDOG TIMEOUT - decoder hung after"
               << m_decodeElapsed.elapsed() << "ms, resetting state";

    // Force reset state so next period can decode
    m_decoderRunning.store(false);
    m_decoding = false;
    m_decodePending = false;

    // Detach the hung thread (safe: Fortran will eventually return)
    if (m_decoderThread.joinable()) {
        m_decoderThread.detach();
    }

    m_decodeLatencyMs = -1.0;  // Indicate timeout
    emit decodeLatencyMsChanged();
    emit decodingChanged();
    emit decodingFinished();
    emit decoderWatchdogTriggered();
}

// ── FASE 2: UTC-aligned period detection with early decode ──
void DecoderController::onFramesWritten(qint64 nFrames)
{
    // nFrames is dec_data.params.kin (cumulative samples in current period)
    m_lastKin = nFrames;

    // Compute UTC-based period timing
    QDateTime utcNow = QDateTime::currentDateTimeUtc();
    double currentSec = utcNow.time().minute() * 60.0
                      + utcNow.time().second()
                      + utcNow.time().msec() / 1000.0;

    double secInPeriod = std::fmod(currentSec, m_period);
    double progress = secInPeriod / m_period;

    // Determine even/odd period
    int periodIndex = static_cast<int>(currentSec / m_period);
    bool isEven = (periodIndex % 2 == 0);

    // Update properties
    if (!qFuzzyCompare(m_secInPeriod, secInPeriod)) {
        m_secInPeriod = secInPeriod;
        emit secInPeriodChanged();
    }
    if (!qFuzzyCompare(m_periodProgress, progress)) {
        m_periodProgress = progress;
        emit periodProgressChanged();
    }
    if (m_isEvenPeriod != isEven) {
        m_isEvenPeriod = isEven;
        emit isEvenPeriodChanged();
    }

    // Boundary detection: period wrapped around
    if (secInPeriod < m_lastSecInPeriod && m_lastSecInPeriod > m_period * 0.5) {
        emit periodBoundary(isEven);
        m_decodePending = false;  // Reset for new period
    }
    m_lastSecInPeriod = secInPeriod;

    // Early decode trigger: start decode m_decoderStartSec before period end
    // In FT2 async mode: decode continuously whenever enough samples are available
    if (m_ft2AsyncMode && m_currentMode == QLatin1String("FT2")) {
        // Async: trigger every period-length of samples, no time alignment
        int samplesPerPeriod = static_cast<int>(m_period * 12000);
        if (m_lastKin >= samplesPerPeriod && !m_decodePending && !m_decoding) {
            m_decodePending = true;
            qDebug() << "DecoderController: FT2 async decode at kin=" << m_lastKin;
            decode();
        }
    } else {
        double triggerPoint = m_period - m_decoderStartSec;
        if (secInPeriod >= triggerPoint && !m_decodePending && !m_decoding) {
            m_decodePending = true;
            qDebug() << "DecoderController: early decode trigger at" << secInPeriod
                     << "sec, kin=" << m_lastKin << "mode=" << m_currentMode;
            decode();
        }
    }

    // Compute spectrum for waterfall display (skip while decoder is running to avoid race)
    if (!m_decoderRunning.load())
        computeSpectrum(nFrames);
}

void DecoderController::computeSpectrum(qint64 k)
{
    if (k <= 0)
        return;

    // Determine nsps for current mode
    int nsps = 1920; // FT8 default
    if (m_currentMode == QLatin1String("FT2"))      nsps = 288;
    else if (m_currentMode == QLatin1String("FT4"))  nsps = 576;

    double trperiod = m_period;
    int ingain = 0;
    bool bLowSidelobes = false;
    int minw = 2;
    int npct = 0;
    int kk = static_cast<int>(k);

    float s[NSMAX];
    std::memset(s, 0, sizeof(s));

    symspec_(&dec_data, &kk, &trperiod, &nsps, &ingain,
             &bLowSidelobes, &minw, &m_px, s, &m_df3,
             &m_ihsym, &m_npts8, &m_pxmax, &npct);

    // Only emit if we got valid spectrum data
    if (m_df3 > 0.0f && m_ihsym > 0) {
        // Number of bins to cover 0–5000 Hz
        int nbins = qMin(static_cast<int>(5000.0 / m_df3), static_cast<int>(NSMAX));

        QList<float> bins;
        bins.reserve(nbins);
        for (int i = 0; i < nbins; i++) {
            bins.append(s[i]);
        }
        emit spectrumData(bins);
    }
}

void DecoderController::updatePeriodForMode()
{
    double newPeriod = periodForMode(m_currentMode);
    if (!qFuzzyCompare(m_period, newPeriod)) {
        m_period = newPeriod;
        emit periodChanged();
    }
    // Reset spectrum tracking on mode change
    m_ihsym = 0;
    m_pxmax = 0.0f;
}
