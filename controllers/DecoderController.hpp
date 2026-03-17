#ifndef DECODERCONTROLLER_HPP
#define DECODERCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QList>
#include <QTimer>
#include <QElapsedTimer>
#include <thread>
#include <atomic>

class DecoderController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(double period READ period WRITE setPeriod NOTIFY periodChanged)
    Q_PROPERTY(bool decoding READ decoding NOTIFY decodingChanged)
    Q_PROPERTY(int nDecodes READ nDecodes NOTIFY nDecodesChanged)
    Q_PROPERTY(int deepSearch READ deepSearch WRITE setDeepSearch NOTIFY deepSearchChanged)
    Q_PROPERTY(QString currentMode READ currentMode WRITE setCurrentMode NOTIFY currentModeChanged)

    // Period timing (FASE 2)
    Q_PROPERTY(double periodProgress READ periodProgress NOTIFY periodProgressChanged)
    Q_PROPERTY(double secInPeriod READ secInPeriod NOTIFY secInPeriodChanged)
    Q_PROPERTY(bool isEvenPeriod READ isEvenPeriod NOTIFY isEvenPeriodChanged)

    // FT2 async mode
    Q_PROPERTY(bool ft2AsyncMode READ ft2AsyncMode WRITE setFt2AsyncMode NOTIFY ft2AsyncModeChanged)

    // Decoder watchdog & timing stats
    Q_PROPERTY(double decodeLatencyMs READ decodeLatencyMs NOTIFY decodeLatencyMsChanged)
    Q_PROPERTY(double avgDt READ avgDt NOTIFY avgDtChanged)

public:
    explicit DecoderController(QObject *parent = nullptr);
    ~DecoderController() override;

    double period() const;
    void setPeriod(double p);

    bool decoding() const;

    int nDecodes() const;

    int deepSearch() const;
    void setDeepSearch(int level);

    QString currentMode() const;
    void setCurrentMode(const QString &mode);

    // Period timing
    double periodProgress() const { return m_periodProgress; }
    double secInPeriod() const { return m_secInPeriod; }
    bool isEvenPeriod() const { return m_isEvenPeriod; }

    // Decode timing stats
    double decodeLatencyMs() const { return m_decodeLatencyMs; }
    double avgDt() const { return m_avgDt; }

    // Decoder params (set from main.cpp wiring)
    void setMyCall(const QString &call);
    void setMyGrid(const QString &grid);
    void setNfqso(int freq);

    // FASE 1: Decoder tuning parameters
    void setFt8Sensitivity(int v) { m_ft8Sensitivity = v; }
    void setFt8Cycles(int v) { m_ft8Cycles = v; }
    void setFt8Threads(int v) { m_ft8Threads = v; }
    void setFt8DecoderStart(int v) { m_ft8DecoderStart = v; m_decoderStartSec = v; }
    void setFt4Depth(int v) { m_ft4Depth = v; }
    void setNtrials10(int v) { m_ntrials10 = v; }
    void setMultithreadFT8(bool v) { m_multithreadFT8 = v; }
    void setHideFT8Dupes(bool v) { m_hideFT8Dupes = v; }
    void setWideDxCallSearch(bool v) { m_wideDxCallSearch = v; }

    // QSO hint parameters
    void setHisCall(const QString &call) { m_hisCall = call.toUpper().trimmed(); }
    void setTxing(bool v) { m_txing = v; }
    void setEnableTx(bool v) { m_enableTx = v; }

    // Fox/Hound mode
    void setHoundMode(bool v) { m_houndMode = v; }
    void setSuperFoxMode(bool v) { m_superFoxMode = v; }

    // FT2 Async mode
    bool ft2AsyncMode() const { return m_ft2AsyncMode; }
    void setFt2AsyncMode(bool v);

    // FT2 Soft Averaging
    void setFt2SoftAvgEnabled(bool v) { m_ft2SoftAvgEnabled = v; }
    void resetFt2SoftAvg();

    Q_INVOKABLE void clearDecodes();
    Q_INVOKABLE void decode();
    Q_INVOKABLE double periodForMode(const QString &mode) const;

signals:
    void periodChanged();
    void decodingChanged();
    void nDecodesChanged();
    void deepSearchChanged();
    void currentModeChanged();
    void newDecode(const QString &utc, int snr, double dt, int freq, const QString &message);
    void decodingStarted();
    void decodingFinished();
    void spectrumData(const QList<float> &bins);

    // Period timing signals
    void periodProgressChanged();
    void secInPeriodChanged();
    void isEvenPeriodChanged();
    void periodBoundary(bool isEvenPeriod);
    void ft2AsyncModeChanged();

    // Watchdog & stats signals
    void decodeLatencyMsChanged();
    void avgDtChanged();
    void decoderWatchdogTriggered();

public slots:
    void onDecodeResult(const QString &utc, int snr, double dt, int freq, const QString &message);
    void onDecodingComplete();
    void onFramesWritten(qint64 nFrames);

private slots:
    void onWatchdogTimeout();

private:
    void updatePeriodForMode();
    void computeSpectrum(qint64 k);
    void runDecoder();
    void parseDecodedResults();

    double m_period = 15.0;
    bool m_decoding = false;
    int m_nDecodes = 0;
    int m_deepSearch = 1;
    QString m_currentMode = QStringLiteral("FT8");

    // Frame tracking for period detection
    qint64 m_lastKin = 0;

    // Period timing (FASE 2)
    double m_lastSecInPeriod = 0.0;
    bool m_decodePending = false;
    double m_decoderStartSec = 3.0;
    double m_periodProgress = 0.0;
    double m_secInPeriod = 0.0;
    bool m_isEvenPeriod = true;

    // Spectrum state (persistent across symspec_ calls)
    int m_ihsym = 0;
    float m_px = 0.0f;
    float m_pxmax = 0.0f;
    float m_df3 = 0.0f;
    int m_npts8 = 0;

    // Decoder params
    QString m_myCall;
    QString m_myGrid;
    int m_nfqso = 1500;

    // FASE 1: Decoder tuning parameters
    int m_ft8Sensitivity = 1;
    int m_ft8Cycles = 3;
    int m_ft8Threads = 0;
    int m_ft8DecoderStart = 3;
    int m_ft4Depth = 3;
    int m_ntrials10 = 3;
    bool m_multithreadFT8 = false;
    bool m_hideFT8Dupes = false;
    bool m_wideDxCallSearch = false;

    // QSO hint parameters
    QString m_hisCall;
    bool m_txing = false;
    bool m_enableTx = false;

    // Fox/Hound mode
    bool m_houndMode = false;
    bool m_superFoxMode = false;

    // FT2 async mode (free-running, no time alignment)
    bool m_ft2AsyncMode = false;

    // FT2 Soft Averaging (A5)
    bool m_ft2SoftAvgEnabled = false;
    int m_ft2SoftAvgPeriods = 0;
    static constexpr int FT2_BITMETRICS_COLS = 174;
    static constexpr int FT2_BITMETRICS_ROWS = 4;
    float m_ft2BitmetricsBuffer[FT2_BITMETRICS_ROWS][FT2_BITMETRICS_COLS] = {};
    bool m_ft2HasBufferedData = false;

    // Mode/band change tracking
    bool m_modeChanged = false;
    bool m_bandChanged = false;
    int m_nsecBandChanged = 0;

    // Background decode thread
    std::atomic<bool> m_decoderRunning{false};
    std::thread m_decoderThread;

    // Decoder watchdog
    QTimer *m_watchdogTimer = nullptr;
    QElapsedTimer m_decodeElapsed;

    // Decode timing stats
    double m_decodeLatencyMs = 0.0;
    double m_avgDt = 0.0;
    double m_dtSum = 0.0;
    int m_dtCount = 0;
};

#endif // DECODERCONTROLLER_HPP
