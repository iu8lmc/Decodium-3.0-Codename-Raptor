#ifndef DISCOVERY_SERVICE_HPP
#define DISCOVERY_SERVICE_HPP

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>
#include "BridgeProtocol.hpp"

// UDP broadcast discovery so Android clients can find the bridge on LAN.
// Server mode: broadcasts beacon periodically.
// Client mode: listens for beacons and reports discovered bridges.
class DiscoveryService : public QObject
{
    Q_OBJECT

public:
    explicit DiscoveryService(QObject *parent = nullptr);
    ~DiscoveryService() override;

    // Server-side: start broadcasting
    void startBroadcast(quint16 wsPort = BridgeProtocol::WEBSOCKET_PORT);
    void stopBroadcast();

    // Client-side: start listening
    void startListening();
    void stopListening();

signals:
    void bridgeDiscovered(const QHostAddress &address, quint16 wsPort);

private slots:
    void onBroadcastTimer();
    void onReadyRead();

private:
    QUdpSocket *m_socket = nullptr;
    QTimer m_broadcastTimer;
    quint16 m_wsPort = BridgeProtocol::WEBSOCKET_PORT;
    bool m_broadcasting = false;
};

#endif // DISCOVERY_SERVICE_HPP
