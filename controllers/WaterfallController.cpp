#include "WaterfallController.hpp"
#include <QSettings>
#include <algorithm>

WaterfallController::WaterfallController(QObject *parent)
    : QObject(parent)
{
    // Load persisted settings
    QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
    settings.beginGroup(QStringLiteral("Waterfall"));
    m_rxFreq = settings.value(QStringLiteral("RxFreq"), 1500).toInt();
    m_txFreq = settings.value(QStringLiteral("TxFreq"), 1500).toInt();
    m_startFreq = settings.value(QStringLiteral("StartFreq"), 200).toInt();
    m_bandwidth = settings.value(QStringLiteral("Bandwidth"), 5000).toInt();
    m_gain = settings.value(QStringLiteral("Gain"), 50).toInt();
    m_zero = settings.value(QStringLiteral("Zero"), 50).toInt();
    settings.endGroup();
}

int WaterfallController::rxFreq() const
{
    return m_rxFreq;
}

void WaterfallController::setRxFreq(int freq)
{
    int clamped = clampFreq(freq);
    if (m_rxFreq != clamped) {
        m_rxFreq = clamped;
        emit rxFreqChanged();

        // If frequencies are locked, move TX freq as well
        if (m_freqsLocked && !m_splitEnabled) {
            if (m_txFreq != clamped) {
                m_txFreq = clamped;
                emit txFreqChanged();
            }
        }

        // Persist
        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/RxFreq"), m_rxFreq);
        settings.setValue(QStringLiteral("Waterfall/TxFreq"), m_txFreq);
    }
}

int WaterfallController::txFreq() const
{
    return m_txFreq;
}

void WaterfallController::setTxFreq(int freq)
{
    int clamped = clampFreq(freq);
    if (m_txFreq != clamped) {
        m_txFreq = clamped;
        emit txFreqChanged();

        // If frequencies are locked, move RX freq as well
        if (m_freqsLocked && !m_splitEnabled) {
            if (m_rxFreq != clamped) {
                m_rxFreq = clamped;
                emit rxFreqChanged();
            }
        }

        // Persist
        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/TxFreq"), m_txFreq);
        settings.setValue(QStringLiteral("Waterfall/RxFreq"), m_rxFreq);
    }
}

int WaterfallController::startFreq() const
{
    return m_startFreq;
}

void WaterfallController::setStartFreq(int freq)
{
    if (m_startFreq != freq && freq >= 0) {
        m_startFreq = freq;
        emit startFreqChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/StartFreq"), m_startFreq);
    }
}

int WaterfallController::bandwidth() const
{
    return m_bandwidth;
}

void WaterfallController::setBandwidth(int bw)
{
    if (m_bandwidth != bw && bw > 0) {
        m_bandwidth = bw;
        emit bandwidthChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/Bandwidth"), m_bandwidth);
    }
}

int WaterfallController::gain() const
{
    return m_gain;
}

void WaterfallController::setGain(int g)
{
    int clamped = std::clamp(g, 0, 100);
    if (m_gain != clamped) {
        m_gain = clamped;
        emit gainChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/Gain"), m_gain);
    }
}

int WaterfallController::zero() const
{
    return m_zero;
}

void WaterfallController::setZero(int z)
{
    int clamped = std::clamp(z, 0, 100);
    if (m_zero != clamped) {
        m_zero = clamped;
        emit zeroChanged();

        QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
        settings.setValue(QStringLiteral("Waterfall/Zero"), m_zero);
    }
}

bool WaterfallController::splitEnabled() const
{
    return m_splitEnabled;
}

void WaterfallController::setSplitEnabled(bool on)
{
    if (m_splitEnabled != on) {
        m_splitEnabled = on;
        emit splitEnabledChanged();

        // When disabling split, sync TX to RX
        if (!on && m_txFreq != m_rxFreq) {
            m_txFreq = m_rxFreq;
            emit txFreqChanged();
        }
    }
}

int WaterfallController::nBins() const
{
    return m_nBins;
}

void WaterfallController::setFrequenciesLocked(bool locked)
{
    m_freqsLocked = locked;

    // When locking, sync TX to RX
    if (locked && !m_splitEnabled && m_txFreq != m_rxFreq) {
        m_txFreq = m_rxFreq;
        emit txFreqChanged();
    }
}

void WaterfallController::centerOnRxFreq()
{
    // Adjust startFreq so that rxFreq is in the center of the displayed bandwidth
    int newStart = m_rxFreq - (m_bandwidth / 2);
    if (newStart < 0)
        newStart = 0;

    if (m_startFreq != newStart) {
        m_startFreq = newStart;
        emit startFreqChanged();
    }
}

void WaterfallController::onSpectrumData(const QList<float> &bins)
{
    if (m_nBins != bins.size()) {
        m_nBins = bins.size();
        emit nBinsChanged();
    }
    emit spectrumDataReady(bins);
}

int WaterfallController::clampFreq(int freq) const
{
    // Clamp audio frequency offset to a reasonable range (0-6000 Hz)
    return std::clamp(freq, 0, 6000);
}

// ── Fox mode markers ──

void WaterfallController::setFoxSlotMarkers(const QVariantList &markers)
{
    if (m_foxSlotMarkers != markers) {
        m_foxSlotMarkers = markers;
        emit foxSlotMarkersChanged();
    }
}

void WaterfallController::setShowTxBrackets(bool v)
{
    if (m_showTxBrackets != v) {
        m_showTxBrackets = v;
        emit showTxBracketsChanged();
    }
}

void WaterfallController::updateFoxMarkers(int baseFreq, int nSlots, int spacing)
{
    QVariantList markers;
    for (int i = 0; i < nSlots; ++i) {
        markers.append(baseFreq + i * spacing);
    }
    setFoxSlotMarkers(markers);
}
