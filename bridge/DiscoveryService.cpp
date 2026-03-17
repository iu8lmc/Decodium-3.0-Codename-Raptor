#include "DiscoveryService.hpp"
#include <QNetworkDatagram>
#include <QDebug>
#include <cstring>

DiscoveryService::DiscoveryService(QObject *parent)
    : QObject(parent)
{
    m_broadcastTimer.setInterval(3000); // beacon every 3s
    connect(&m_broadcastTimer, &QTimer::timeout,
            this, &DiscoveryService::onBroadcastTimer);
}

DiscoveryService::~DiscoveryService()
{
    stopBroadcast();
    stopListening();
}

void DiscoveryService::startBroadcast(quint16 wsPort)
{
    if (m_broadcasting) return;

    m_wsPort = wsPort;

    if (!m_socket) {
        m_socket = new QUdpSocket(this);
    }

    m_broadcasting = true;
    m_broadcastTimer.start();
    onBroadcastTimer(); // send first beacon immediately
    qDebug() << "DiscoveryService: broadcasting on port"
             << BridgeProtocol::DISCOVERY_PORT;
}

void DiscoveryService::stopBroadcast()
{
    m_broadcastTimer.stop();
    m_broadcasting = false;
}

void DiscoveryService::startListening()
{
    if (!m_socket) {
        m_socket = new QUdpSocket(this);
    }

    if (!m_socket->bind(QHostAddress::Any, BridgeProtocol::DISCOVERY_PORT,
                        QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        qWarning() << "DiscoveryService: failed to bind UDP port"
                   << BridgeProtocol::DISCOVERY_PORT;
        return;
    }

    connect(m_socket, &QUdpSocket::readyRead,
            this, &DiscoveryService::onReadyRead);
    qDebug() << "DiscoveryService: listening on port"
             << BridgeProtocol::DISCOVERY_PORT;
}

void DiscoveryService::stopListening()
{
    if (m_socket && !m_broadcasting) {
        m_socket->close();
        delete m_socket;
        m_socket = nullptr;
    }
}

void DiscoveryService::onBroadcastTimer()
{
    if (!m_socket) return;

    // Beacon format: "DECODIUM_BRIDGE:<wsPort>"
    QByteArray beacon = QByteArray(BridgeProtocol::DISCOVERY_MAGIC)
                        + ":" + QByteArray::number(m_wsPort);

    m_socket->writeDatagram(beacon, QHostAddress::Broadcast,
                            BridgeProtocol::DISCOVERY_PORT);
}

void DiscoveryService::onReadyRead()
{
    while (m_socket && m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        QByteArray data = datagram.data();

        // Parse "DECODIUM_BRIDGE:<port>"
        if (data.startsWith(BridgeProtocol::DISCOVERY_MAGIC)) {
            int colonIdx = data.indexOf(':');
            if (colonIdx >= 0) {
                quint16 port = data.mid(colonIdx + 1).toUShort();
                if (port > 0) {
                    emit bridgeDiscovered(datagram.senderAddress(), port);
                }
            }
        }
    }
}
