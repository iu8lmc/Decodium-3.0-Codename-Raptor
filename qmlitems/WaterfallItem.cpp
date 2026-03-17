#include "WaterfallItem.hpp"
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <cmath>

WaterfallItem::WaterfallItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton);
    setRenderTarget(QQuickPaintedItem::FramebufferObject);
    setOpaquePainting(true);
    setAntialiasing(false);
    initPalette();
}

void WaterfallItem::initPalette()
{
    m_palette.resize(256);
    for (int i = 0; i < 256; ++i) {
        float t = i / 255.0f;
        if (t < 0.2f) {
            // Dark blue to blue
            float s = t / 0.2f;
            m_palette[i] = QColor::fromRgbF(0.0, 0.0, 0.1 + 0.4 * s);
        } else if (t < 0.4f) {
            // Blue to cyan
            float s = (t - 0.2f) / 0.2f;
            m_palette[i] = QColor::fromRgbF(0.0, s * 0.8, 0.5 + 0.3 * s);
        } else if (t < 0.6f) {
            // Cyan to green
            float s = (t - 0.4f) / 0.2f;
            m_palette[i] = QColor::fromRgbF(0.0, 0.8 + 0.2 * s, 0.8 * (1.0 - s));
        } else if (t < 0.8f) {
            // Green to yellow
            float s = (t - 0.6f) / 0.2f;
            m_palette[i] = QColor::fromRgbF(s, 1.0, 0.0);
        } else {
            // Yellow to red
            float s = (t - 0.8f) / 0.2f;
            m_palette[i] = QColor::fromRgbF(1.0, 1.0 - s, 0.0);
        }
    }
}

QColor WaterfallItem::spectrumColor(float value) const
{
    float gainFactor = m_gain / 50.0f;
    float zeroOffset = (m_zero - 50) / 50.0f;
    float adjusted = (value + zeroOffset) * gainFactor;
    int idx = qBound(0, static_cast<int>(adjusted * 255.0f), 255);
    return m_palette[idx];
}

int WaterfallItem::freqToX(int freq) const
{
    if (m_bandwidth <= 0) return 0;
    return static_cast<int>((freq - m_startFreq) * width() / m_bandwidth);
}

int WaterfallItem::xToFreq(int x) const
{
    if (width() <= 0) return m_startFreq;
    return m_startFreq + x * m_bandwidth / static_cast<int>(width());
}

void WaterfallItem::paint(QPainter *painter)
{
    int w = static_cast<int>(width());
    int h = static_cast<int>(height());
    if (w <= 0 || h <= 0) return;

    painter->setRenderHint(QPainter::Antialiasing, false);

    // Background
    painter->fillRect(0, 0, w, h, QColor("#0a0e18"));

    // Spectrum area (top portion)
    drawSpectrum(painter, 0, m_spectrumHeight);

    // Waterfall area (below spectrum)
    int wfY = m_spectrumHeight;
    int wfH = h - m_spectrumHeight;
    drawWaterfall(painter, wfY, wfH);

    // Frequency markers
    drawMarkers(painter, 0, h);

    // TX brackets overlay
    if (m_showTxBrackets)
        drawTxBrackets(painter, 0, h);

    // Fox slot markers overlay
    if (!m_foxSlotMarkers.isEmpty())
        drawFoxSlotMarkers(painter, 0, h);

    // Frequency scale
    painter->setPen(QColor("#808890"));
    painter->setFont(QFont("Consolas", 8));
    int step = 500;
    if (m_bandwidth > 3000) step = 500;
    else if (m_bandwidth > 1000) step = 200;
    else step = 100;

    for (int f = ((m_startFreq / step) + 1) * step; f < m_startFreq + m_bandwidth; f += step) {
        int x = freqToX(f);
        painter->drawLine(x, m_spectrumHeight - 5, x, m_spectrumHeight);
        painter->drawText(x - 20, m_spectrumHeight - 7, 40, 12, Qt::AlignCenter, QString::number(f));
    }
}

void WaterfallItem::drawSpectrum(QPainter *painter, int y, int h)
{
    QMutexLocker lock(&m_mutex);
    if (m_currentSpectrum.isEmpty()) return;

    int w = static_cast<int>(width());
    int nBins = m_currentSpectrum.size();

    // Draw spectrum line
    QPainterPath path;
    bool first = true;
    for (int x = 0; x < w; ++x) {
        int bin = x * nBins / w;
        if (bin >= nBins) bin = nBins - 1;
        float val = m_currentSpectrum[bin];
        float gainFactor = m_gain / 50.0f;
        float zeroOffset = (m_zero - 50) / 50.0f;
        float adjusted = qBound(0.0f, (val + zeroOffset) * gainFactor, 1.0f);
        int py = y + h - static_cast<int>(adjusted * h);
        if (first) {
            path.moveTo(x, py);
            first = false;
        } else {
            path.lineTo(x, py);
        }
    }

    // Fill under spectrum
    QPainterPath fillPath = path;
    fillPath.lineTo(w, y + h);
    fillPath.lineTo(0, y + h);
    fillPath.closeSubpath();

    QLinearGradient grad(0, y, 0, y + h);
    grad.setColorAt(0.0, QColor(0, 212, 255, 60));
    grad.setColorAt(1.0, QColor(0, 212, 255, 10));
    painter->fillPath(fillPath, grad);

    // Spectrum line
    painter->setPen(QPen(QColor("#00d4ff"), 1));
    painter->drawPath(path);
}

void WaterfallItem::drawWaterfall(QPainter *painter, int y, int h)
{
    if (m_waterfallImage.isNull()) return;

    QRect target(0, y, static_cast<int>(width()), h);
    QRect source(0, 0, m_waterfallImage.width(), m_waterfallImage.height());
    painter->drawImage(target, m_waterfallImage, source);
}

void WaterfallItem::drawMarkers(QPainter *painter, int y, int h)
{
    // RX frequency marker (red)
    int rxX = freqToX(m_rxFreq);
    painter->setPen(QPen(QColor("#ff3333"), 2));
    painter->drawLine(rxX, y, rxX, y + h);

    // TX frequency marker (green, only if different from RX)
    if (m_txFreq != m_rxFreq) {
        int txX = freqToX(m_txFreq);
        painter->setPen(QPen(QColor("#00ff00"), 2));
        painter->drawLine(txX, y, txX, y + h);
    }

    // RX label
    painter->setPen(QColor("#ff3333"));
    painter->setFont(QFont("Consolas", 9, QFont::Bold));
    painter->drawText(rxX + 3, y + 12, QString("RX %1").arg(m_rxFreq));

    if (m_txFreq != m_rxFreq) {
        int txX = freqToX(m_txFreq);
        painter->setPen(QColor("#00ff00"));
        painter->drawText(txX + 3, y + 24, QString("TX %1").arg(m_txFreq));
    }
}

void WaterfallItem::drawTxBrackets(QPainter *painter, int y, int h)
{
    // Draw red brackets [ ] around TX frequency band (±50 Hz)
    int txX = freqToX(m_txFreq);
    int halfBw = freqToX(m_startFreq + 50) - freqToX(m_startFreq);  // 50 Hz in pixels
    int bracketLeft = txX - halfBw;
    int bracketRight = txX + halfBw;
    int bracketH = 16;

    QPen bracketPen(QColor("#ff3333"), 2, Qt::SolidLine);
    painter->setPen(bracketPen);

    // Left bracket [
    painter->drawLine(bracketLeft, y + 2, bracketLeft, y + bracketH);
    painter->drawLine(bracketLeft, y + 2, bracketLeft + 4, y + 2);
    painter->drawLine(bracketLeft, y + bracketH, bracketLeft + 4, y + bracketH);

    // Right bracket ]
    painter->drawLine(bracketRight, y + 2, bracketRight, y + bracketH);
    painter->drawLine(bracketRight, y + 2, bracketRight - 4, y + 2);
    painter->drawLine(bracketRight, y + bracketH, bracketRight - 4, y + bracketH);

    // TX label between brackets
    painter->setFont(QFont("Consolas", 7));
    painter->drawText(bracketLeft + 6, y + bracketH - 3, "TX");
}

void WaterfallItem::drawFoxSlotMarkers(QPainter *painter, int y, int h)
{
    // Draw dashed orange markers for Fox multi-slot frequencies
    QPen foxPen(QColor("#FF9800"), 1, Qt::DashLine);
    painter->setPen(foxPen);

    for (const auto &marker : m_foxSlotMarkers) {
        int freq = marker.toInt();
        int x = freqToX(freq);
        painter->drawLine(x, y, x, y + h);
    }

    // Label first slot
    if (!m_foxSlotMarkers.isEmpty()) {
        painter->setFont(QFont("Consolas", 7));
        painter->setPen(QColor("#FF9800"));
        int x0 = freqToX(m_foxSlotMarkers.first().toInt());
        painter->drawText(x0 + 3, y + m_spectrumHeight + 12, "FOX");
    }
}

void WaterfallItem::initPaletteRaptor()
{
    // Raptor military green palette
    m_palette.resize(256);
    for (int i = 0; i < 256; ++i) {
        float t = i / 255.0f;
        if (t < 0.25f) {
            float s = t / 0.25f;
            m_palette[i] = QColor::fromRgbF(0.0, 0.05 + 0.1 * s, 0.0);
        } else if (t < 0.5f) {
            float s = (t - 0.25f) / 0.25f;
            m_palette[i] = QColor::fromRgbF(0.1 * s, 0.15 + 0.35 * s, 0.05 * s);
        } else if (t < 0.75f) {
            float s = (t - 0.5f) / 0.25f;
            m_palette[i] = QColor::fromRgbF(0.1 + 0.4 * s, 0.5 + 0.3 * s, 0.05 + 0.15 * s);
        } else {
            float s = (t - 0.75f) / 0.25f;
            m_palette[i] = QColor::fromRgbF(0.5 + 0.5 * s, 0.8 + 0.2 * s, 0.2 + 0.3 * s);
        }
    }
}

void WaterfallItem::initPaletteGrayscale()
{
    m_palette.resize(256);
    for (int i = 0; i < 256; ++i) {
        float t = i / 255.0f;
        m_palette[i] = QColor::fromRgbF(t, t, t);
    }
}

void WaterfallItem::setShowTxBrackets(bool v)
{
    if (m_showTxBrackets != v) {
        m_showTxBrackets = v;
        emit showTxBracketsChanged();
        update();
    }
}

void WaterfallItem::setPaletteIndex(int idx)
{
    if (m_paletteIndex != idx && idx >= 0 && idx <= 2) {
        m_paletteIndex = idx;
        switch (idx) {
        case 0: initPalette(); break;
        case 1: initPaletteRaptor(); break;
        case 2: initPaletteGrayscale(); break;
        }
        emit paletteIndexChanged();
        update();
    }
}

void WaterfallItem::setFoxSlotMarkers(const QVariantList &markers)
{
    if (m_foxSlotMarkers != markers) {
        m_foxSlotMarkers = markers;
        emit foxSlotMarkersChanged();
        update();
    }
}

void WaterfallItem::setSpectrumMode(int mode)
{
    if (m_spectrumMode != mode && mode >= 0 && mode <= 2) {
        m_spectrumMode = mode;
        m_cumulativeSpectrum.clear();
        emit spectrumModeChanged();
        update();
    }
}

void WaterfallItem::addSpectrumData(const QVector<float> &data)
{
    QMutexLocker lock(&m_mutex);

    // Apply spectrum mode processing
    if (m_spectrumMode == 1) {
        // Cumulative: max-hold
        if (m_cumulativeSpectrum.size() != data.size()) {
            m_cumulativeSpectrum = data;
        } else {
            for (int i = 0; i < data.size(); ++i)
                m_cumulativeSpectrum[i] = qMax(m_cumulativeSpectrum[i], data[i]);
        }
        m_currentSpectrum = m_cumulativeSpectrum;
    } else if (m_spectrumMode == 2) {
        // Smooth: exponential moving average (alpha=0.3)
        if (m_cumulativeSpectrum.size() != data.size()) {
            m_cumulativeSpectrum = data;
        } else {
            const float alpha = 0.3f;
            for (int i = 0; i < data.size(); ++i)
                m_cumulativeSpectrum[i] = alpha * data[i] + (1.0f - alpha) * m_cumulativeSpectrum[i];
        }
        m_currentSpectrum = m_cumulativeSpectrum;
    } else {
        m_currentSpectrum = data;
    }

    int w = static_cast<int>(width());
    int wfH = static_cast<int>(height()) - m_spectrumHeight;
    if (w <= 0 || wfH <= 0) return;

    // Initialize waterfall image if needed
    if (m_waterfallImage.isNull() || m_waterfallImage.width() != w || m_waterfallImage.height() != wfH) {
        m_waterfallImage = QImage(w, wfH, QImage::Format_RGB32);
        m_waterfallImage.fill(QColor("#0a0e18"));
    }

    // Scroll waterfall down (single memmove instead of per-line memcpy)
    if (wfH > 1) {
        int bytesPerLine = m_waterfallImage.bytesPerLine();
        uchar *bits = m_waterfallImage.bits();
        std::memmove(bits + bytesPerLine, bits, bytesPerLine * (wfH - 1));
    }

    // Paint new line at top using direct pixel access (much faster than setPixelColor)
    int nBins = data.size();
    if (nBins > 0) {
        QRgb *line = reinterpret_cast<QRgb*>(m_waterfallImage.scanLine(0));
        float gainFactor = m_gain / 50.0f;
        float zeroOffset = (m_zero - 50) / 50.0f;
        for (int x = 0; x < w; ++x) {
            int bin = x * nBins / w;
            if (bin >= nBins) bin = nBins - 1;
            float adjusted = (data[bin] + zeroOffset) * gainFactor;
            int idx = qBound(0, static_cast<int>(adjusted * 255.0f), 255);
            line[x] = m_palette[idx].rgb();
        }
    }

    lock.unlock();
    update();
}

void WaterfallItem::scrollWaterfall()
{
    if (m_waterfallImage.isNull()) return;
    int h = m_waterfallImage.height();
    int w = m_waterfallImage.width();
    int bytesPerLine = m_waterfallImage.bytesPerLine();

    // Scroll down by 1 pixel (copy from bottom up)
    for (int y = h - 1; y > 0; --y) {
        memcpy(m_waterfallImage.scanLine(y), m_waterfallImage.scanLine(y - 1), bytesPerLine);
    }
}

void WaterfallItem::mousePressEvent(QMouseEvent *event)
{
    int freq = xToFreq(static_cast<int>(event->position().x()));
    if (event->button() == Qt::LeftButton) {
        setRxFreq(freq);
    } else if (event->button() == Qt::RightButton) {
        setTxFreq(freq);
    }
    emit frequencySelected(freq);
}

void WaterfallItem::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int freq = xToFreq(static_cast<int>(event->position().x()));
        setRxFreq(freq);
    }
}

void WaterfallItem::setRxFreq(int f)
{
    if (m_rxFreq != f) {
        m_rxFreq = f;
        emit rxFreqChanged();
        update();
    }
}

void WaterfallItem::setTxFreq(int f)
{
    if (m_txFreq != f) {
        m_txFreq = f;
        emit txFreqChanged();
        update();
    }
}

void WaterfallItem::setStartFreq(int f)
{
    if (m_startFreq != f) {
        m_startFreq = f;
        emit startFreqChanged();
        update();
    }
}

void WaterfallItem::setBandwidth(int bw)
{
    if (m_bandwidth != bw) {
        m_bandwidth = bw;
        emit bandwidthChanged();
        update();
    }
}

void WaterfallItem::setGain(int g)
{
    if (m_gain != g) {
        m_gain = g;
        emit gainChanged();
        update();
    }
}

void WaterfallItem::setZero(int z)
{
    if (m_zero != z) {
        m_zero = z;
        emit zeroChanged();
        update();
    }
}

void WaterfallItem::setRunning(bool r)
{
    if (m_running != r) {
        m_running = r;
        emit runningChanged();
    }
}
