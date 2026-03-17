#include "NetworkAudioInput.hpp"
#include "Detector/Detector.hpp"
#include <QDebug>
#include <QDateTime>
#include <cstring>
#include <cmath>

NetworkAudioInput::NetworkAudioInput(QObject *parent)
    : QObject(parent)
    , m_socket(new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this))
{
    connect(m_socket, &QWebSocket::connected,
            this, &NetworkAudioInput::onConnected);
    connect(m_socket, &QWebSocket::disconnected,
            this, &NetworkAudioInput::onDisconnected);
    connect(m_socket, &QWebSocket::binaryMessageReceived,
            this, &NetworkAudioInput::onBinaryMessage);
    connect(m_socket, &QWebSocket::errorOccurred,
            this, &NetworkAudioInput::onError);

    m_heartbeatTimer.setInterval(5000);
    connect(&m_heartbeatTimer, &QTimer::timeout,
            this, &NetworkAudioInput::onHeartbeat);
}

NetworkAudioInput::~NetworkAudioInput()
{
    disconnect();
}

void NetworkAudioInput::connectToBridge(const QString &host, quint16 port)
{
    if (m_connected) disconnect();

    QUrl url;
    url.setScheme(QStringLiteral("ws"));
    url.setHost(host);
    url.setPort(port);
    url.setPath(QStringLiteral("/"));

    qDebug() << "NetworkAudioInput: connecting to" << url.toString();
    m_socket->open(url);
}

void NetworkAudioInput::disconnect()
{
    m_heartbeatTimer.stop();
    m_connected = false;
    if (m_socket->isValid()) {
        m_socket->close();
    }
}

bool NetworkAudioInput::isConnected() const
{
    return m_connected;
}

void NetworkAudioInput::setDetector(Detector *detector)
{
    m_detector = detector;
}

void NetworkAudioInput::sendCatFreq(quint64 freqHz)
{
    QByteArray payload(reinterpret_cast<const char*>(&freqHz), sizeof(freqHz));
    sendPacket(BridgeProtocol::CAT_FREQ, payload);
}

void NetworkAudioInput::sendCatMode(const QString &mode)
{
    sendPacket(BridgeProtocol::CAT_MODE, mode.toUtf8());
}

void NetworkAudioInput::sendCatPtt(bool on)
{
    uint8_t val = on ? 1 : 0;
    QByteArray payload(reinterpret_cast<const char*>(&val), 1);
    sendPacket(BridgeProtocol::CAT_PTT, payload);
}

void NetworkAudioInput::sendAudioTx(const QByteArray &pcm48kHz)
{
    sendPacket(BridgeProtocol::AUDIO_TX, pcm48kHz);
}

void NetworkAudioInput::onConnected()
{
    m_connected = true;
    m_heartbeatTimer.start();
    qDebug() << "NetworkAudioInput: connected to bridge";
    emit connected();
}

void NetworkAudioInput::onDisconnected()
{
    m_heartbeatTimer.stop();
    m_connected = false;
    qDebug() << "NetworkAudioInput: disconnected from bridge";
    emit disconnected();
}

void NetworkAudioInput::onBinaryMessage(const QByteArray &message)
{
    processPacket(message);
}

void NetworkAudioInput::onError(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err);
    emit error(m_socket->errorString());
}

void NetworkAudioInput::onHeartbeat()
{
    quint32 ts = static_cast<quint32>(
        QDateTime::currentMSecsSinceEpoch() & 0xFFFFFFFF);
    QByteArray payload(reinterpret_cast<const char*>(&ts), sizeof(ts));
    sendPacket(BridgeProtocol::HEARTBEAT, payload);
}

void NetworkAudioInput::sendPacket(BridgeProtocol::MessageType type,
                                   const QByteArray &payload)
{
    if (!m_connected) return;

    BridgeProtocol::PacketHeader hdr;
    hdr.magic = BridgeProtocol::MAGIC;
    hdr.type = static_cast<uint8_t>(type);
    hdr.reserved = 0;
    hdr.payloadSize = static_cast<uint16_t>(payload.size());

    QByteArray packet;
    packet.reserve(sizeof(hdr) + payload.size());
    packet.append(reinterpret_cast<const char*>(&hdr), sizeof(hdr));
    packet.append(payload);

    m_socket->sendBinaryMessage(packet);
}

void NetworkAudioInput::processPacket(const QByteArray &data)
{
    if (data.size() < static_cast<int>(sizeof(BridgeProtocol::PacketHeader)))
        return;

    BridgeProtocol::PacketHeader hdr;
    std::memcpy(&hdr, data.constData(), sizeof(hdr));

    if (hdr.magic != BridgeProtocol::MAGIC) return;

    QByteArray payload = data.mid(sizeof(hdr), hdr.payloadSize);

    switch (static_cast<BridgeProtocol::MessageType>(hdr.type)) {
    case BridgeProtocol::AUDIO_RX:
        // Write PCM 12kHz directly into Detector
        if (m_detector && m_detector->isOpen()) {
            m_detector->write(payload.constData(), payload.size());

            // Compute peak level for UI
            const qint16 *samples = reinterpret_cast<const qint16*>(
                payload.constData());
            int count = payload.size() / sizeof(qint16);
            float peak = 0.0f;
            for (int i = 0; i < count; ++i) {
                float v = std::abs(samples[i]) / 32768.0f;
                if (v > peak) peak = v;
            }
            emit levelChanged(peak);
        }
        break;

    case BridgeProtocol::CAT_STATUS:
        if (payload.size() >= static_cast<int>(sizeof(BridgeProtocol::CatStatusPayload))) {
            BridgeProtocol::CatStatusPayload status;
            std::memcpy(&status, payload.constData(), sizeof(status));
            emit catStatusReceived(status.frequency, status.mode,
                                   status.ptt != 0, status.sMeter);
        }
        break;

    case BridgeProtocol::SPECTRUM:
        emit spectrumReceived(payload);
        break;

    case BridgeProtocol::HEARTBEAT:
        // heartbeat acknowledged, connection alive
        break;

    default:
        break;
    }
}
