#ifndef NETWORK_AUDIO_INPUT_HPP
#define NETWORK_AUDIO_INPUT_HPP

#include <QObject>
#include <QWebSocket>
#include <QUrl>
#include <QByteArray>
#include <QTimer>
#include "../bridge/BridgeProtocol.hpp"

class Detector;

// Receives RX audio (PCM Int16 mono 12kHz) from DecodiumBridge via WebSocket
// and writes it into Detector, replacing local SoundInput on Android.
class NetworkAudioInput : public QObject
{
    Q_OBJECT

public:
    explicit NetworkAudioInput(QObject *parent = nullptr);
    ~NetworkAudioInput() override;

    void connectToBridge(const QString &host,
                         quint16 port = BridgeProtocol::WEBSOCKET_PORT);
    void disconnect();
    bool isConnected() const;

    void setDetector(Detector *detector);

signals:
    void connected();
    void disconnected();
    void error(const QString &message);
    void levelChanged(float peak);
    void catStatusReceived(quint64 freq, quint8 mode, bool ptt, qint16 sMeter);
    void spectrumReceived(const QByteArray &fftBins);

public slots:
    // Send commands to bridge
    void sendCatFreq(quint64 freqHz);
    void sendCatMode(const QString &mode);
    void sendCatPtt(bool on);
    void sendAudioTx(const QByteArray &pcm48kHz);

private slots:
    void onConnected();
    void onDisconnected();
    void onBinaryMessage(const QByteArray &message);
    void onError(QAbstractSocket::SocketError err);
    void onHeartbeat();

private:
    void sendPacket(BridgeProtocol::MessageType type,
                    const QByteArray &payload);
    void processPacket(const QByteArray &data);

    QWebSocket *m_socket = nullptr;
    QTimer m_heartbeatTimer;
    Detector *m_detector = nullptr;
    bool m_connected = false;
};

#endif // NETWORK_AUDIO_INPUT_HPP
