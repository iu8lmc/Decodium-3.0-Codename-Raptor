#include "asyncmodewidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QLinearGradient>
#include <QtMath>

namespace {
  constexpr int SNR_MIN  = -28;
  constexpr int SNR_MAX  =  10;
  constexpr int METER_H  =  10;   // s-meter bar height
  constexpr int WAVE_TOP =   2;   // top margin
  constexpr int GAP      =   4;   // gap between wave and meter
  constexpr qreal TWO_PI = 2.0 * M_PI;
  constexpr int FPS      =  30;
}

AsyncModeWidget::AsyncModeWidget (QWidget *parent)
  : QWidget {parent}
{
  setMinimumSize (minimumSizeHint ());
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

  int w = width ();
  int h = height ();

  // background
  p.fillRect (rect (), QColor (0x1a, 0x1a, 0x2e));

  if (!m_running) {
    // idle: just show "FT2" centered
    p.setPen (QColor (0x55, 0x55, 0x55));
    p.setFont (QFont {"Segoe UI", 10, QFont::Bold});
    p.drawText (rect (), Qt::AlignCenter, "FT2");
    return;
  }

  // --- Sine wave area ---
  int waveH = h - METER_H - GAP - WAVE_TOP;
  if (waveH < 10) waveH = 10;
  int waveMid = WAVE_TOP + waveH / 2;
  qreal amp = waveH * 0.38;

  // wave color: green (RX) / red (TX)
  QColor waveColor = m_transmitting ? QColor (0xff, 0x44, 0x44) : QColor (0x00, 0xe6, 0x76);

  // draw filled sine wave
  QPainterPath wavePath;
  wavePath.moveTo (0, waveMid);
  for (int x = 0; x <= w; ++x) {
    qreal t = static_cast<qreal>(x) / w;
    qreal y = waveMid - amp * qSin (TWO_PI * 2.0 * t + m_phase);
    if (x == 0) wavePath.moveTo (x, y);
    else wavePath.lineTo (x, y);
  }

  // glow effect: semi-transparent fill under curve
  QPainterPath fillPath = wavePath;
  fillPath.lineTo (w, waveMid);
  fillPath.lineTo (0, waveMid);
  fillPath.closeSubpath ();
  QColor fillCol = waveColor;
  fillCol.setAlpha (40);
  p.fillPath (fillPath, fillCol);

  // main wave line
  QPen wavePen (waveColor, 2.0);
  p.setPen (wavePen);
  p.drawPath (wavePath);

  // RX/TX label on the wave
  {
    QString label = m_transmitting ? "TX" : "RX";
    p.setFont (QFont {"Segoe UI", 8, QFont::Bold});
    p.setPen (waveColor);
    p.drawText (4, WAVE_TOP + 12, label);

    // FT2 label right-aligned
    p.setPen (QColor (0xcc, 0xcc, 0xcc));
    p.drawText (w - 28, WAVE_TOP + 12, "FT2");
  }

  // --- S-Meter bar ---
  int meterY = h - METER_H - 1;
  int meterW = w - 4;
  int meterX = 2;

  // background track
  p.fillRect (meterX, meterY, meterW, METER_H, QColor (0x33, 0x33, 0x33));

  if (m_snr > -99) {
    // normalize SNR to 0..1
    qreal norm = qBound (0.0, static_cast<qreal>(m_snr - SNR_MIN) / (SNR_MAX - SNR_MIN), 1.0);
    int barW = static_cast<int>(norm * meterW);

    // gradient: red → yellow → green
    QLinearGradient grad (meterX, 0, meterX + meterW, 0);
    grad.setColorAt (0.0, QColor (0xff, 0x33, 0x33));   // -28 dB: red
    grad.setColorAt (0.4, QColor (0xff, 0xcc, 0x00));   // ~-13 dB: yellow
    grad.setColorAt (0.7, QColor (0x66, 0xff, 0x33));   //  ~-2 dB: green
    grad.setColorAt (1.0, QColor (0x00, 0xff, 0x88));   // +10 dB: bright green
    p.fillRect (meterX, meterY, barW, METER_H, grad);

    // dB text
    p.setFont (QFont {"Segoe UI", 7});
    p.setPen (Qt::white);
    QString dbText = QString {"%1 dB"}.arg (m_snr);
    p.drawText (meterX + 2, meterY + METER_H - 2, dbText);
  } else {
    p.setFont (QFont {"Segoe UI", 7});
    p.setPen (QColor (0x66, 0x66, 0x66));
    p.drawText (meterX + 2, meterY + METER_H - 2, "-- dB");
  }

  // thin border
  p.setPen (QPen (QColor (0x44, 0x44, 0x55), 1.0));
  p.drawRect (rect ().adjusted (0, 0, -1, -1));
}
