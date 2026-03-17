#ifndef PSKREPORTERLITE_HPP
#define PSKREPORTERLITE_HPP

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>
#include <QHostInfo>
#include <QDateTime>
#include <QList>
#include <QByteArray>

// Lightweight PSK Reporter IPFIX client for Android
// Uses only QUdpSocket — no Boost, no Configuration dependency
class PSKReporterLite : public QObject
{
    Q_OBJECT

public:
    explicit PSKReporterLite(QObject *parent = nullptr);
    ~PSKReporterLite() override;

    void setLocalStation(const QString &call, const QString &grid,
                         const QString &antenna, const QString &programInfo);
    void addSpot(const QString &call, const QString &grid,
                 quint64 freqHz, const QString &mode, int snr);
    void sendReport();
    void setEnabled(bool enabled);
    bool isEnabled() const { return m_enabled; }

signals:
    void errorOccurred(const QString &msg);
    void reportSent(int spotCount);

private slots:
    void onFlushTimer();
    void onDnsResult(QHostInfo info);

private:
    // IPFIX constants
    static constexpr quint16 IPFIX_VERSION = 10;
    static constexpr quint32 OBSERVATION_DOMAIN = 3;
    // Template IDs
    static constexpr quint16 SENDER_TEMPLATE_ID = 0x50E3;     // 20707
    static constexpr quint16 RECEIVER_TEMPLATE_ID = 0x50E2;   // 20706
    // PEN (Private Enterprise Number) for PSK Reporter
    static constexpr quint32 PSK_PEN = 0x00004004;            // 16388
    // Field IDs (with PEN bit set)
    static constexpr quint16 FIELD_SENDER_CALL = 1;
    static constexpr quint16 FIELD_SENDER_GRID = 2;
    static constexpr quint16 FIELD_SENDER_SOFT = 3;
    static constexpr quint16 FIELD_SENDER_ANT  = 4;
    static constexpr quint16 FIELD_RX_CALL     = 1;
    static constexpr quint16 FIELD_RX_GRID     = 2;
    static constexpr quint16 FIELD_RX_FREQ     = 3;
    static constexpr quint16 FIELD_RX_SNR      = 4;
    static constexpr quint16 FIELD_RX_MODE     = 5;
    static constexpr quint16 FIELD_RX_INFO_SRC = 6;
    static constexpr quint16 FIELD_RX_TIME     = 150; // dateTimeSeconds

    struct Spot {
        QString call;
        QString grid;
        quint64 freqHz;
        QString mode;
        int snr;
        quint32 timestamp; // seconds since epoch
    };

    QByteArray buildTemplateSet();
    QByteArray buildSenderDataSet();
    QByteArray buildReceiverDataSet(const QList<Spot> &spots);
    QByteArray buildIpfixMessage(const QByteArray &payload);
    void appendVarString(QByteArray &buf, const QString &str);
    void resolveHost();

    QUdpSocket m_socket;
    QTimer m_flushTimer;
    QHostAddress m_serverAddr;
    quint16 m_serverPort = 4739;
    bool m_hostResolved = false;
    bool m_enabled = false;

    // Local station info
    QString m_myCall;
    QString m_myGrid;
    QString m_antenna;
    QString m_programInfo;

    // Pending spots
    QList<Spot> m_spots;

    // IPFIX sequence counter
    quint32 m_sequenceNumber = 0;
};

#endif // PSKREPORTERLITE_HPP
