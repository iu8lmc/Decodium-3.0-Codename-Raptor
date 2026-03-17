#include "PSKReporterLite.hpp"
#include <QHostInfo>
#include <QtEndian>
#include <QDebug>

PSKReporterLite::PSKReporterLite(QObject *parent)
    : QObject(parent)
{
    // Flush pending spots every 5 minutes
    m_flushTimer.setInterval(300000);
    connect(&m_flushTimer, &QTimer::timeout, this, &PSKReporterLite::onFlushTimer);
}

PSKReporterLite::~PSKReporterLite()
{
    // Send any remaining spots
    if (!m_spots.isEmpty() && m_enabled) {
        sendReport();
    }
    m_socket.close();
}

void PSKReporterLite::setEnabled(bool enabled)
{
    m_enabled = enabled;
    if (enabled) {
        if (m_socket.state() == QAbstractSocket::UnconnectedState) {
            m_socket.bind();
        }
        resolveHost();
        m_flushTimer.start();
    } else {
        m_flushTimer.stop();
    }
}

void PSKReporterLite::setLocalStation(const QString &call, const QString &grid,
                                       const QString &antenna, const QString &programInfo)
{
    m_myCall = call;
    m_myGrid = grid;
    m_antenna = antenna;
    m_programInfo = programInfo;
}

void PSKReporterLite::addSpot(const QString &call, const QString &grid,
                               quint64 freqHz, const QString &mode, int snr)
{
    if (!m_enabled || m_myCall.isEmpty() || call.isEmpty())
        return;

    Spot spot;
    spot.call = call;
    spot.grid = grid;
    spot.freqHz = freqHz;
    spot.mode = mode;
    spot.snr = snr;
    spot.timestamp = static_cast<quint32>(QDateTime::currentDateTimeUtc().toSecsSinceEpoch());

    m_spots.append(spot);

    // Auto-flush when we have 50+ spots
    if (m_spots.size() >= 50) {
        sendReport();
    }
}

void PSKReporterLite::sendReport()
{
    if (m_spots.isEmpty() || !m_enabled)
        return;

    if (!m_hostResolved) {
        resolveHost();
        return;
    }

    // Build IPFIX message with template + sender + receiver data sets
    QByteArray payload;
    payload.append(buildTemplateSet());
    payload.append(buildSenderDataSet());
    payload.append(buildReceiverDataSet(m_spots));

    QByteArray msg = buildIpfixMessage(payload);

    qint64 sent = m_socket.writeDatagram(msg, m_serverAddr, m_serverPort);
    if (sent < 0) {
        emit errorOccurred(QStringLiteral("PSK Reporter send failed: %1").arg(m_socket.errorString()));
    } else {
        qDebug() << "PSKReporterLite: sent" << m_spots.size() << "spots,"
                 << msg.size() << "bytes";
        emit reportSent(m_spots.size());
    }

    m_spots.clear();
}

void PSKReporterLite::onFlushTimer()
{
    if (!m_spots.isEmpty()) {
        sendReport();
    }
}

void PSKReporterLite::resolveHost()
{
    QHostInfo::lookupHost(QStringLiteral("report.pskreporter.info"),
                          this, SLOT(onDnsResult(QHostInfo)));
}

void PSKReporterLite::onDnsResult(QHostInfo info)
{
    if (info.error() != QHostInfo::NoError || info.addresses().isEmpty()) {
        emit errorOccurred(QStringLiteral("PSK Reporter DNS failed: %1").arg(info.errorString()));
        return;
    }
    m_serverAddr = info.addresses().first();
    m_hostResolved = true;
    qDebug() << "PSKReporterLite: resolved to" << m_serverAddr.toString();
}

// ── IPFIX message building ──

QByteArray PSKReporterLite::buildIpfixMessage(const QByteArray &payload)
{
    QByteArray msg;
    msg.reserve(16 + payload.size());

    // IPFIX Message Header (16 bytes)
    quint16 version = qToBigEndian(IPFIX_VERSION);
    quint16 length = qToBigEndian(static_cast<quint16>(16 + payload.size()));
    quint32 exportTime = qToBigEndian(static_cast<quint32>(
        QDateTime::currentDateTimeUtc().toSecsSinceEpoch()));
    quint32 seqNum = qToBigEndian(m_sequenceNumber++);
    quint32 domain = qToBigEndian(OBSERVATION_DOMAIN);

    msg.append(reinterpret_cast<const char*>(&version), 2);
    msg.append(reinterpret_cast<const char*>(&length), 2);
    msg.append(reinterpret_cast<const char*>(&exportTime), 4);
    msg.append(reinterpret_cast<const char*>(&seqNum), 4);
    msg.append(reinterpret_cast<const char*>(&domain), 4);
    msg.append(payload);

    return msg;
}

QByteArray PSKReporterLite::buildTemplateSet()
{
    // Template Set header: SetID=2, Length=TBD
    QByteArray set;

    // ── Sender (Receiver station) Template ──
    QByteArray senderTpl;
    quint16 tplId = qToBigEndian(SENDER_TEMPLATE_ID);
    quint16 fieldCount = qToBigEndian(static_cast<quint16>(4));
    senderTpl.append(reinterpret_cast<const char*>(&tplId), 2);
    senderTpl.append(reinterpret_cast<const char*>(&fieldCount), 2);

    // Field: senderCallsign (variable length)
    auto addField = [](QByteArray &buf, quint16 id, quint16 len, quint32 pen) {
        quint16 fieldId = qToBigEndian(static_cast<quint16>(id | 0x8000)); // PEN bit
        quint16 fieldLen = qToBigEndian(len);
        quint32 fieldPen = qToBigEndian(pen);
        buf.append(reinterpret_cast<const char*>(&fieldId), 2);
        buf.append(reinterpret_cast<const char*>(&fieldLen), 2);
        buf.append(reinterpret_cast<const char*>(&fieldPen), 4);
    };

    addField(senderTpl, FIELD_SENDER_CALL, 0xFFFF, PSK_PEN);  // variable
    addField(senderTpl, FIELD_SENDER_GRID, 0xFFFF, PSK_PEN);  // variable
    addField(senderTpl, FIELD_SENDER_SOFT, 0xFFFF, PSK_PEN);  // variable
    addField(senderTpl, FIELD_SENDER_ANT,  0xFFFF, PSK_PEN);  // variable

    // ── Receiver (Decoded station) Template ──
    QByteArray rxTpl;
    tplId = qToBigEndian(RECEIVER_TEMPLATE_ID);
    fieldCount = qToBigEndian(static_cast<quint16>(6));
    rxTpl.append(reinterpret_cast<const char*>(&tplId), 2);
    rxTpl.append(reinterpret_cast<const char*>(&fieldCount), 2);

    addField(rxTpl, FIELD_RX_CALL, 0xFFFF, PSK_PEN);  // variable
    addField(rxTpl, FIELD_RX_GRID, 0xFFFF, PSK_PEN);  // variable
    addField(rxTpl, FIELD_RX_FREQ, 4, PSK_PEN);       // uint32
    addField(rxTpl, FIELD_RX_SNR,  1, PSK_PEN);       // int8
    addField(rxTpl, FIELD_RX_MODE, 0xFFFF, PSK_PEN);  // variable

    // dateTimeSeconds (IANA field 150, no PEN)
    {
        quint16 fid = qToBigEndian(static_cast<quint16>(150));
        quint16 flen = qToBigEndian(static_cast<quint16>(4));
        rxTpl.append(reinterpret_cast<const char*>(&fid), 2);
        rxTpl.append(reinterpret_cast<const char*>(&flen), 2);
    }

    // Build the Template Set
    QByteArray content = senderTpl + rxTpl;
    quint16 setId = qToBigEndian(static_cast<quint16>(2));  // Template Set
    quint16 setLen = qToBigEndian(static_cast<quint16>(4 + content.size()));
    set.append(reinterpret_cast<const char*>(&setId), 2);
    set.append(reinterpret_cast<const char*>(&setLen), 2);
    set.append(content);

    return set;
}

QByteArray PSKReporterLite::buildSenderDataSet()
{
    QByteArray data;
    appendVarString(data, m_myCall);
    appendVarString(data, m_myGrid);
    appendVarString(data, m_programInfo);
    appendVarString(data, m_antenna);

    // Data Set header
    QByteArray set;
    quint16 setId = qToBigEndian(SENDER_TEMPLATE_ID);
    quint16 setLen = qToBigEndian(static_cast<quint16>(4 + data.size()));
    set.append(reinterpret_cast<const char*>(&setId), 2);
    set.append(reinterpret_cast<const char*>(&setLen), 2);
    set.append(data);

    return set;
}

QByteArray PSKReporterLite::buildReceiverDataSet(const QList<Spot> &spots)
{
    QByteArray data;
    for (const auto &spot : spots) {
        appendVarString(data, spot.call);
        appendVarString(data, spot.grid);

        quint32 freq = qToBigEndian(static_cast<quint32>(spot.freqHz));
        data.append(reinterpret_cast<const char*>(&freq), 4);

        qint8 snr = static_cast<qint8>(qBound(-128, spot.snr, 127));
        data.append(reinterpret_cast<const char*>(&snr), 1);

        appendVarString(data, spot.mode);

        quint32 ts = qToBigEndian(spot.timestamp);
        data.append(reinterpret_cast<const char*>(&ts), 4);
    }

    QByteArray set;
    quint16 setId = qToBigEndian(RECEIVER_TEMPLATE_ID);
    quint16 setLen = qToBigEndian(static_cast<quint16>(4 + data.size()));
    set.append(reinterpret_cast<const char*>(&setId), 2);
    set.append(reinterpret_cast<const char*>(&setLen), 2);
    set.append(data);

    return set;
}

void PSKReporterLite::appendVarString(QByteArray &buf, const QString &str)
{
    QByteArray utf8 = str.toUtf8();
    int len = utf8.size();

    if (len < 255) {
        buf.append(static_cast<char>(len));
    } else {
        buf.append(static_cast<char>(0xFF));
        quint16 bigLen = qToBigEndian(static_cast<quint16>(len));
        buf.append(reinterpret_cast<const char*>(&bigLen), 2);
    }
    buf.append(utf8);
}
