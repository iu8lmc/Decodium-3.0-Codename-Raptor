#include "NetworkAudioOutput.hpp"
#include "NetworkAudioInput.hpp"
#include "Modulator/Modulator.hpp"
#include <QDebug>

NetworkAudioOutput::NetworkAudioOutput(QObject *parent)
    : QObject(parent)
{
    m_pullTimer.setInterval(CHUNK_MS);
    connect(&m_pullTimer, &QTimer::timeout,
            this, &NetworkAudioOutput::onPullTimer);
}

NetworkAudioOutput::~NetworkAudioOutput()
{
    stopPulling();
}

void NetworkAudioOutput::setNetworkInput(NetworkAudioInput *input)
{
    m_networkInput = input;
}

void NetworkAudioOutput::startPulling(Modulator *modulator)
{
    if (!modulator) return;
    m_modulator = modulator;
    m_pullTimer.start();
    qDebug() << "NetworkAudioOutput: started pulling from Modulator";
}

void NetworkAudioOutput::stopPulling()
{
    m_pullTimer.stop();
    m_modulator = nullptr;
}

bool NetworkAudioOutput::isPulling() const
{
    return m_pullTimer.isActive();
}

void NetworkAudioOutput::writeTxAudio(const QByteArray &pcm48kHz)
{
    if (m_networkInput) {
        m_networkInput->sendAudioTx(pcm48kHz);
    }
}

void NetworkAudioOutput::onPullTimer()
{
    if (!m_modulator || !m_modulator->isOpen() || !m_modulator->isActive())
        return;

    // Read a 40ms chunk from the Modulator (same as QAudioSink would do)
    QByteArray buffer(CHUNK_BYTES, 0);
    qint64 bytesRead = m_modulator->read(buffer.data(), CHUNK_BYTES);
    if (bytesRead > 0) {
        buffer.resize(bytesRead);
        writeTxAudio(buffer);
    }

    // If the Modulator went Idle, stop pulling
    if (!m_modulator->isActive()) {
        qDebug() << "NetworkAudioOutput: Modulator finished, stopping pull";
        stopPulling();
    }
}
