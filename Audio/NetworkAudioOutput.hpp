#ifndef NETWORK_AUDIO_OUTPUT_HPP
#define NETWORK_AUDIO_OUTPUT_HPP

#include <QObject>
#include <QByteArray>
#include <QTimer>

class NetworkAudioInput;
class Modulator;

// Captures TX audio from the Modulator and sends it to the bridge
// via the NetworkAudioInput's WebSocket connection (reuses the same socket).
//
// Two modes of operation:
// 1. Push mode: external code calls writeTxAudio() directly
// 2. Pull mode: startPulling(modulator) uses a timer to read from Modulator's
//    QIODevice::readData() at 48kHz rate and sends chunks over WebSocket.
//    This replaces the SoundOutput/QAudioSink pull in WiFi mode.
class NetworkAudioOutput : public QObject
{
    Q_OBJECT

public:
    explicit NetworkAudioOutput(QObject *parent = nullptr);
    ~NetworkAudioOutput() override;

    void setNetworkInput(NetworkAudioInput *input);

    // Pull mode: read from Modulator via timer (replaces SoundOutput in WiFi mode)
    void startPulling(Modulator *modulator);
    void stopPulling();
    bool isPulling() const;

public slots:
    // Push mode: directly write TX audio data
    void writeTxAudio(const QByteArray &pcm48kHz);

private slots:
    void onPullTimer();

private:
    NetworkAudioInput *m_networkInput = nullptr;
    Modulator *m_modulator = nullptr;
    QTimer m_pullTimer;

    // 40ms at 48kHz = 1920 samples * 2 bytes = 3840 bytes per chunk
    static constexpr int TX_SAMPLE_RATE = 48000;
    static constexpr int CHUNK_MS = 40;
    static constexpr int CHUNK_SAMPLES = TX_SAMPLE_RATE * CHUNK_MS / 1000; // 1920
    static constexpr int CHUNK_BYTES = CHUNK_SAMPLES * sizeof(qint16);     // 3840
};

#endif // NETWORK_AUDIO_OUTPUT_HPP
