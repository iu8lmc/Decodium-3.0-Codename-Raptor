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
  constexpr int FPS      =  25;
}

AsyncModeWidget::AsyncModeWidget (QWidget *parent)
  : QWidget {parent}
{
  setSizePolicy (QSizePolicy::Fixed, QSizePolicy::Expanding);
  setMinimumWidth (48);
  setMaximumWidth (60);
  m_animTimer.setInterval (1000 / FPS);
  connect (&m_animTimer, &QTimer::timeout, this, [this] {
    m_phase += 0.18;
    if (m_phase > TWO_PI) m_phase -= TWO_PI;
    update ();
  });
}

void AsyncModeWidget::setSnr (int value)
{
  if (m_snr != value) { m_snr = value; update (); }
}

void AsyncModeWidget::setTransmitting (bool tx)
{
  if (m_transmitting != tx) { m_transmitting = tx; update (); }
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

  int w = width ();
  int h = height ();

  // dark background
  p.fillRect (rect (), QColor (0x14, 0x14, 0x22));
  p.setPen (QPen (QColor (0x33, 0x33, 0x44), 1.0));
  p.drawRect (rect ().adjusted (0, 0, -1, -1));

  if (!m_running) {
    p.setPen (QColor (0x44, 0x44, 0x44));
    p.setFont (QFont {"Segoe UI", 7, QFont::Bold});
    p.drawText (rect (), Qt::AlignCenter, "FT2");
    return;
  }

  QColor waveColor = m_transmitting ? QColor (0xff, 0x44, 0x44) : QColor (0x00, 0xe6, 0x76);

  // --- "ASINCRONO" header (vertical text area, top 12px) ---
  p.setFont (QFont {"Segoe UI", 5, QFont::Bold});
  p.setPen (waveColor);
  p.drawText (QRect (0, 1, w, 11), Qt::AlignCenter, "ASINCRONO");

  // --- RX/TX indicator ---
  {
    QString stateLabel = m_transmitting ? "TX" : "RX";
    p.setFont (QFont {"Segoe UI", 6, QFont::Bold});
    p.setPen (waveColor);
    p.drawText (QRect (0, 12, w, 10), Qt::AlignCenter, stateLabel);
  }

  // --- Sine wave area: from y=24 to y=(h-18) ---
  int waveTop = 24;
  int waveBot = h - 18;
  if (waveBot <= waveTop + 8) waveBot = waveTop + 8;
  int waveH = waveBot - waveTop;
  qreal amp = waveH * 0.42;

  // sine wave: draw vertically-oriented (x=phase, y=position in widget)
  QPainterPath wavePath;
  for (int y = waveTop; y <= waveBot; ++y) {
    qreal t = static_cast<qreal>(y - waveTop) / waveH;
    qreal x = (w / 2.0) + amp * qSin (TWO_PI * 2.0 * t + m_phase);
    if (y == waveTop) wavePath.moveTo (x, y);
    else wavePath.lineTo (x, y);
  }

  // glow fill
  QPainterPath fillPath = wavePath;
  fillPath.lineTo (w / 2.0, waveBot);
  fillPath.lineTo (w / 2.0, waveTop);
  fillPath.closeSubpath ();
  QColor fillCol = waveColor;
  fillCol.setAlpha (25);
  p.fillPath (fillPath, fillCol);

  // wave line
  p.setPen (QPen (waveColor, 1.5));
  p.drawPath (wavePath);

  // --- S-Meter bar at bottom (horizontal, 6px tall) ---
  int meterH = 6;
  int meterY = h - meterH - 3;
  int meterX = 3;
  int meterW = w - 6;

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

    // dB number centered below meter
    p.setFont (QFont {"Segoe UI", 6});
    p.setPen (Qt::white);
    p.drawText (QRect (0, meterY - 9, w, 9), Qt::AlignCenter, QString::number (m_snr));
  }
}
