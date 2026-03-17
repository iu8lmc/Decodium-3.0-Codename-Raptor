#include "asyncmodewidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QLinearGradient>
#include <QMenu>
#include <QContextMenuEvent>
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
  setFixedSize (90, 50);
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

void AsyncModeWidget::setWaveEnabled (bool on)
{
  if (m_showWave != on) { m_showWave = on; update (); }
}

void AsyncModeWidget::setMeterEnabled (bool on)
{
  if (m_showMeter != on) { m_showMeter = on; update (); }
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

void AsyncModeWidget::contextMenuEvent (QContextMenuEvent *ev)
{
  QMenu menu (this);
  auto *actWave = menu.addAction (tr ("Sine Wave"));
  actWave->setCheckable (true);
  actWave->setChecked (m_showWave);
  auto *actMeter = menu.addAction (tr ("S-Meter"));
  actMeter->setCheckable (true);
  actMeter->setChecked (m_showMeter);
  menu.addSeparator ();
  auto *actHide = menu.addAction (tr ("Hide Widget"));

  auto *chosen = menu.exec (ev->globalPos ());
  if (chosen == actWave) setWaveEnabled (!m_showWave);
  else if (chosen == actMeter) setMeterEnabled (!m_showMeter);
  else if (chosen == actHide) setVisible (false);
}

void AsyncModeWidget::paintEvent (QPaintEvent *)
{
  QPainter p (this);
  p.setRenderHint (QPainter::Antialiasing);

  int w = width ();
  int h = height ();

  // dark background + border
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

  // --- header ---
  p.setFont (QFont {"Segoe UI", 6, QFont::Bold});
  p.setPen (waveColor);
  QString label = m_transmitting ? "TX" : "ASYNC";
  p.drawText (QRect (0, 1, w, 10), Qt::AlignCenter, label);

  // --- Sine wave ---
  if (m_showWave) {
    int waveTop = 12;
    int waveBot = m_showMeter ? h - 16 : h - 4;
    if (waveBot < waveTop + 6) waveBot = waveTop + 6;
    int waveH = waveBot - waveTop;
    int waveMid = waveTop + waveH / 2;
    qreal amp = waveH * 0.42;

    QPainterPath wavePath;
    for (int x = 1; x <= w - 1; ++x) {
      qreal t = static_cast<qreal>(x) / w;
      qreal y = waveMid - amp * qSin (TWO_PI * 2.5 * t + m_phase);
      if (x == 1) wavePath.moveTo (x, y);
      else wavePath.lineTo (x, y);
    }

    // glow
    QPainterPath fillPath = wavePath;
    fillPath.lineTo (w - 1, waveMid);
    fillPath.lineTo (1, waveMid);
    fillPath.closeSubpath ();
    QColor fillCol = waveColor;
    fillCol.setAlpha (25);
    p.fillPath (fillPath, fillCol);

    // wave line
    p.setPen (QPen (waveColor, 1.5));
    p.drawPath (wavePath);
  }

  // --- S-Meter always at bottom ---
  if (m_showMeter) {
    int meterH = 5;
    int meterY = h - meterH - 2;
    int meterX = 2;
    int meterW = w - 4;

    // Background bar
    p.fillRect (meterX, meterY, meterW, meterH, QColor (0x28, 0x28, 0x28));

    // Gradient fill based on SNR
    qreal norm = qBound (0.0, static_cast<qreal>(m_snr - SNR_MIN) / (SNR_MAX - SNR_MIN), 1.0);
    int barW = qMax (1, static_cast<int>(norm * meterW));

    QLinearGradient grad (meterX, 0, meterX + meterW, 0);
    grad.setColorAt (0.0, QColor (0xff, 0x33, 0x33));
    grad.setColorAt (0.4, QColor (0xff, 0xcc, 0x00));
    grad.setColorAt (0.7, QColor (0x66, 0xff, 0x33));
    grad.setColorAt (1.0, QColor (0x00, 0xff, 0x88));
    p.fillRect (meterX, meterY, barW, meterH, grad);

    // dB value text
    p.setFont (QFont {"Segoe UI", 6});
    p.setPen (Qt::white);
    QString dbText = (m_snr <= -99) ? "--- dB" : QString ("%1 dB").arg (m_snr);
    p.drawText (QRect (0, meterY - 9, w, 9), Qt::AlignCenter, dbText);
  }
}
