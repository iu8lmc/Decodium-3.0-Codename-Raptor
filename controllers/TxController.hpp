#ifndef TXCONTROLLER_HPP
#define TXCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QStringList>

class TxController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool transmitting READ transmitting NOTIFY transmittingChanged)
    Q_PROPERTY(bool autoCQ READ autoCQ WRITE setAutoCQ NOTIFY autoCQChanged)
    Q_PROPERTY(bool autoSequence READ autoSequence WRITE setAutoSequence NOTIFY autoSequenceChanged)
    Q_PROPERTY(int activeTxMessage READ activeTxMessage WRITE setActiveTxMessage NOTIFY activeTxMessageChanged)
    Q_PROPERTY(QString hisCall READ hisCall WRITE setHisCall NOTIFY hisCallChanged)
    Q_PROPERTY(QString hisGrid READ hisGrid WRITE setHisGrid NOTIFY hisGridChanged)
    Q_PROPERTY(QString txReport READ txReport WRITE setTxReport NOTIFY txReportChanged)
    Q_PROPERTY(QString tx1 READ tx1 WRITE setTx1 NOTIFY tx1Changed)
    Q_PROPERTY(QString tx2 READ tx2 WRITE setTx2 NOTIFY tx2Changed)
    Q_PROPERTY(QString tx3 READ tx3 WRITE setTx3 NOTIFY tx3Changed)
    Q_PROPERTY(QString tx4 READ tx4 WRITE setTx4 NOTIFY tx4Changed)
    Q_PROPERTY(QString tx5 READ tx5 WRITE setTx5 NOTIFY tx5Changed)
    Q_PROPERTY(QString tx6 READ tx6 WRITE setTx6 NOTIFY tx6Changed)
    Q_PROPERTY(QString txState READ txState NOTIFY txStateChanged)
    Q_PROPERTY(int txPeriod READ txPeriod WRITE setTxPeriod NOTIFY txPeriodChanged)
    Q_PROPERTY(int qsoProgress READ qsoProgress NOTIFY qsoProgressChanged)
    Q_PROPERTY(bool txEnabled READ txEnabled WRITE setTxEnabled NOTIFY txEnabledChanged)
    Q_PROPERTY(int txWatchdog READ txWatchdog NOTIFY txWatchdogChanged)

    // Fox/Hound mode
    Q_PROPERTY(bool foxMode READ foxMode WRITE setFoxMode NOTIFY foxModeChanged)
    Q_PROPERTY(bool houndMode READ houndMode WRITE setHoundMode NOTIFY houndModeChanged)
    Q_PROPERTY(bool superFoxMode READ superFoxMode WRITE setSuperFoxMode NOTIFY superFoxModeChanged)
    Q_PROPERTY(QStringList callerQueue READ callerQueue NOTIFY callerQueueChanged)
    Q_PROPERTY(int callerQueueSize READ callerQueueSize NOTIFY callerQueueChanged)
    Q_PROPERTY(bool noB4Filter READ noB4Filter WRITE setNoB4Filter NOTIFY noB4FilterChanged)

public:
    // QSO state machine (FASE 4)
    enum QSOProgress {
        CALLING = 0,       // TX6: CQ myCall myGrid
        REPORT = 1,        // TX2: hisCall myCall report
        ROGER_REPORT = 2,  // TX3: hisCall myCall R+report
        ROGERS = 3,        // TX4: hisCall myCall RR73
        SIGNOFF = 4,       // TX5: hisCall myCall 73
        IDLE_QSO = 5
    };
    Q_ENUM(QSOProgress)

    explicit TxController(QObject *parent = nullptr);
    ~TxController() override = default;

    bool transmitting() const;

    bool autoCQ() const;
    void setAutoCQ(bool on);

    bool autoSequence() const;
    void setAutoSequence(bool on);

    int activeTxMessage() const;
    void setActiveTxMessage(int num);

    QString hisCall() const;
    void setHisCall(const QString &call);

    QString hisGrid() const;
    void setHisGrid(const QString &grid);

    QString txReport() const;
    void setTxReport(const QString &report);

    QString tx1() const;
    void setTx1(const QString &msg);
    QString tx2() const;
    void setTx2(const QString &msg);
    QString tx3() const;
    void setTx3(const QString &msg);
    QString tx4() const;
    void setTx4(const QString &msg);
    QString tx5() const;
    void setTx5(const QString &msg);
    QString tx6() const;
    void setTx6(const QString &msg);

    QString txState() const;

    int txPeriod() const;
    void setTxPeriod(int period);

    int qsoProgress() const { return m_qsoProgress; }
    void setQsoProgress(int p);

    bool txEnabled() const { return m_txEnabled; }
    void setTxEnabled(bool v);

    int txWatchdog() const { return m_txWatchdog; }

    Q_INVOKABLE void startCQ();
    Q_INVOKABLE void halt();
    Q_INVOKABLE void enableTx();
    Q_INVOKABLE void sendMessage(int num);
    Q_INVOKABLE void genStdMsgs(const QString &myCall, const QString &myGrid,
                                 const QString &hisCall, const QString &hisGrid,
                                 const QString &rptSent, const QString &rptRcvd);

    // FASE 4: Auto-sequence QSO
    Q_INVOKABLE void processDecodedMessage(const QString &utc, int snr, double dt,
                                            int freq, const QString &message,
                                            const QString &myCall, const QString &myGrid);
    Q_INVOKABLE void handleDoubleClick(const QString &message, int freq,
                                        const QString &myCall, const QString &myGrid);

    // Fox/Hound mode
    bool foxMode() const { return m_foxMode; }
    void setFoxMode(bool v);
    bool houndMode() const { return m_houndMode; }
    void setHoundMode(bool v);
    bool superFoxMode() const { return m_superFoxMode; }
    void setSuperFoxMode(bool v);
    QStringList callerQueue() const { return m_callerQueue; }
    int callerQueueSize() const { return m_callerQueue.size(); }
    bool noB4Filter() const { return m_noB4Filter; }
    void setNoB4Filter(bool v);

    Q_INVOKABLE void enqueueStation(const QString &call);
    Q_INVOKABLE void dequeueStation(const QString &call);
    Q_INVOKABLE void clearCallerQueue();
    Q_INVOKABLE QString dequeueNextStation();

    // Called by guiUpdate timer
    void tickWatchdog();
    void resetWatchdog();
    QString currentTxMessage() const;

signals:
    void transmittingChanged();
    void autoCQChanged();
    void autoSequenceChanged();
    void activeTxMessageChanged();
    void hisCallChanged();
    void hisGridChanged();
    void txReportChanged();
    void tx1Changed();
    void tx2Changed();
    void tx3Changed();
    void tx4Changed();
    void tx5Changed();
    void tx6Changed();
    void txStateChanged();
    void txPeriodChanged();
    void txRequested(const QString &message);
    void haltRequested();
    void qsoProgressChanged();
    void txEnabledChanged();
    void txWatchdogChanged();
    void qsoComplete(const QString &call, const QString &grid,
                     const QString &rptSent, const QString &rptRcvd);
    void rxFreqRequested(int freq);
    void foxModeChanged();
    void houndModeChanged();
    void superFoxModeChanged();
    void callerQueueChanged();
    void noB4FilterChanged();

private:
    void setTransmitting(bool on);
    void setTxState(const QString &state);
    void advanceQsoState(int nextTxNum);

    bool m_transmitting = false;
    bool m_autoCQ = false;
    bool m_autoSequence = false;
    int m_activeTxMessage = 1;
    QString m_hisCall;
    QString m_hisGrid;
    QString m_txReport;
    QString m_rptRcvd;
    QString m_tx1;
    QString m_tx2;
    QString m_tx3;
    QString m_tx4;
    QString m_tx5;
    QString m_tx6;
    QString m_txState = QStringLiteral("Idle");
    int m_txPeriod = 1;  // 0 = even, 1 = odd (first period)
    int m_qsoProgress = IDLE_QSO;
    bool m_txEnabled = false;
    int m_txWatchdog = 0;
    static constexpr int TX_WATCHDOG_MAX = 600; // 60 seconds at 100ms ticks

    // Fox/Hound mode
    bool m_foxMode = false;
    bool m_houndMode = false;
    bool m_superFoxMode = false;
    bool m_noB4Filter = false;
    QStringList m_callerQueue;
    static constexpr int MAX_CALLER_QUEUE = 20;
};

#endif // TXCONTROLLER_HPP
