#include "asyncmodewidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QLinearGradient>
#include <QtMath>

namespace {
  constexpr int SNR_MIN  = -28;
  constexpr int SNR_MAX  =  10;
  constexpr qreal TWO_PI = 2.0 * M_PI;
  constexpr int FPS      =  30;
}

AsyncModeWidget::AsyncModeWidget (QWidget *parent)
  : QWidget {parent}
{
  setFixedSize (80, 40);
  m_animTimer.setInterval (1000 / FPS);
  connect (&m_animTimer, &QTimer::timeout, this, [this] {
    m_phase += 0.15;
    if (m_phase > TWO_PI) m_phase -= TWO_PI;
    update ();
  });
}

void AsyncModeWidget::setSnr (int value)
{
  if (m_snr != value) {
    m_snr = value;
    update ();
  }
}

void AsyncModeWidget::setTransmitting (bool tx)
{
  if (m_transmitting != tx) {
    m_transmitting = tx;
    update ();
  }
}

void AsyncModeWidget::start ()
{
  m_running = true;
  m_phase = 0.0;
  m_animTimer.start ();
  update ();
}

void AsyncModeWidget::stop ()
{
  m_running = false;
  m_animTimer.stop ();
  update ();
}

void AsyncModeWidget::paintEvent (QPaintEvent *)
{
  QPainter p (this);
  p.setRenderHint (QPainter::Antialiasing);

  int w = width ();   // 80

  // dark background with subtle border
  p.fillRect (rect (), QColor (0x12, 0x12, 0x20));
  p.setPen (QPen (QColor (0x33, 0x33, 0x44), 1.0));
  p.drawRect (rect ().adjusted (0, 0, -1, -1));

  if (!m_running) {
    p.setPen (QColor (0x44, 0x44, 0x44));
    p.setFont (QFont {"Segoe UI", 7, QFont::Bold});
    p.drawText (rect (), Qt::AlignCenter, "FT2");
    return;
  }

  // --- "ASINCRONO" header ---
  QColor waveColor = m_transmitting ? QColor (0xff, 0x44, 0x44) : QColor (0x00, 0xe6, 0x76);
  QString label = m_transmitting ? "TX" : "ASINCRONO";

  p.setFont (QFont {"Segoe UI", 6, QFont::Bold});
  p.setPen (waveColor);
  p.drawText (QRect (0, 1, w, 10), Qt::AlignCenter, label);

  // --- Sine wave area: y=11..28 (18px height) ---
  int waveTop = 11;
  int waveBot = 28;
  int waveH = waveBot - waveTop;
  int waveMid = waveTop + waveH / 2;
  qreal amp = waveH * 0.42;

  // draw sine wave
  QPainterPath wavePath;
  for (int x = 0; x <= w; ++x) {
    qreal t = static_cast<qreal>(x) / w;
    qreal y = waveMid - amp * qSin (TWO_PI * 2.5 * t + m_phase);
    if (x == 0) wavePath.moveTo (x, y);
    else wavePath.lineTo (x, y);
  }

  // glow fill under wave
  QPainterPath fillPath = wavePath;
  fillPath.lineTo (w, waveMid);
  fillPath.lineTo (0, waveMid);
  fillPath.closeSubpath ();
  QColor fillCol = waveColor;
  fillCol.setAlpha (30);
  p.fillPath (fillPath, fillCol);

  // wave line
  p.setPen (QPen (waveColor, 1.5));
  p.drawPath (wavePath);

  // --- S-Meter bar: y=30..37 (8px) ---
  int meterY = 30;
  int meterH = 7;
  int meterX = 2;
  int meterW = w - 4;

  // track background
  p.fillRect (meterX, meterY, meterW, meterH, QColor (0x28, 0x28, 0x28));

  if (m_snr > -99) {
    qreal norm = qBound (0.0, static_cast<qreal>(m_snr - SNR_MIN) / (SNR_MAX - SNR_MIN), 1.0);
    int barW = qMax (1, static_cast<int>(norm * meterW));

    QLinearGradient grad (meterX, 0, meterX + meterW, 0);
    grad.setColorAt (0.0, QColor (0xff, 0x33, 0x33));
    grad.setColorAt (0.4, QColor (0xff, 0xcc, 0x00));
    grad.setColorAt (0.7, QColor (0x66, 0xff, 0x33));
    grad.setColorAt (1.0, QColor (0x00, 0xff, 0x88));
    p.fillRect (meterX, meterY, barW, meterH, grad);

    // dB value right-aligned
    p.setFont (QFont {"Segoe UI", 6});
    p.setPen (Qt::white);
    p.drawText (QRect (meterX, meterY - 1, meterW, meterH + 1), Qt::AlignRight | Qt::AlignVCenter,
                QString::number (m_snr));
  }
}
