#include "QSOProgressWidget.h"
#include <QPaintEvent>

QSOProgressWidget::QSOProgressWidget(QWidget *parent)
  : QWidget(parent)
{
  setAttribute(Qt::WA_TranslucentBackground);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void QSOProgressWidget::setStep(int step)
{
  if (m_step != step) {
    m_step = qBound(0, step, m_maxSteps);
    update();
  }
}

void QSOProgressWidget::setMaxSteps(int n)
{
  if (n > 0 && n != m_maxSteps) {
    m_maxSteps = n;
    m_step = qMin(m_step, m_maxSteps);
    update();
  }
}

void QSOProgressWidget::setSlotInfo(int slot, const QString &call, int step)
{
  if (slot >= 0 && slot < MAX_SLOTS) {
    m_slots[slot].call = call;
    m_slots[slot].step = qBound(0, step, m_maxSteps);
    update();
  }
}

void QSOProgressWidget::setNumSlots(int n)
{
  m_numSlots = qBound(0, n, MAX_SLOTS);
  update();
}

void QSOProgressWidget::reset()
{
  m_step = 0;
  for (int i = 0; i < MAX_SLOTS; ++i) {
    m_slots[i].call.clear();
    m_slots[i].step = 0;
  }
  update();
}

void QSOProgressWidget::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);
  QRect r = rect().adjusted(1, 1, -1, -1);

  if (m_numSlots > 0)
    drawMultiSlot(p, r);
  else
    drawSingleMode(p, r);
}

void QSOProgressWidget::drawSingleMode(QPainter &p, const QRect &r)
{
  const QStringList labels = stepLabels();
  const int n = qMin(m_maxSteps, labels.size());
  if (n <= 0) return;

  const int spacing = 2;
  const qreal segW = (r.width() - spacing * (n - 1)) / static_cast<qreal>(n);
  const qreal segH = r.height();
  const qreal radius = 4.0;

  const QColor completedFill(0x06, 0x5a, 0x6e);      // #065a6e
  const QColor activeFill(0x08, 0x91, 0xb2);          // #0891b2
  const QColor activeBorder(0x22, 0xd3, 0xee);        // #22d3ee lighter cyan
  const QColor futureFill(0x2a, 0x2a, 0x2a);          // #2a2a2a
  const QColor textLight(0xe0, 0xe0, 0xe0);
  const QColor textDim(0x88, 0x88, 0x88);
  const QColor textActive(0xff, 0xff, 0xff);

  QFont font = p.font();
  font.setPointSize(8);

  for (int i = 0; i < n; ++i) {
    qreal x = r.x() + i * (segW + spacing);
    QRectF seg(x, r.y(), segW, segH);

    bool isCompleted = (i < m_step);
    bool isActive = (i == m_step - 1) || (m_step == 0 && i == 0);
    // When step > 0: active = current step (m_step-1 index, since step 1 = index 0)
    // When step == 0 (idle): highlight first segment subtly
    if (m_step == 0) {
      isActive = (i == 0);
      isCompleted = false;
    } else {
      isActive = (i == m_step - 1);
      isCompleted = (i < m_step - 1);
    }

    // Fill
    if (isActive && m_step > 0) {
      p.setBrush(activeFill);
      p.setPen(QPen(activeBorder, 1.5));
    } else if (isCompleted) {
      p.setBrush(completedFill);
      p.setPen(Qt::NoPen);
    } else {
      p.setBrush(futureFill);
      p.setPen(Qt::NoPen);
    }
    p.drawRoundedRect(seg, radius, radius);

    // Text
    font.setBold(isActive && m_step > 0);
    p.setFont(font);
    if (isActive && m_step > 0)
      p.setPen(textActive);
    else if (isCompleted)
      p.setPen(textLight);
    else
      p.setPen(textDim);

    p.drawText(seg, Qt::AlignCenter, labels.value(i));
  }
}

void QSOProgressWidget::drawMultiSlot(QPainter &p, const QRect &r)
{
  const QStringList labels = stepLabels();
  const int n = qMin(m_maxSteps, labels.size());
  if (n <= 0 || m_numSlots <= 0) return;

  const int rowSpacing = 2;
  const qreal rowH = (r.height() - rowSpacing * (m_numSlots - 1))
                      / static_cast<qreal>(m_numSlots);
  const int callLabelW = 70;
  const qreal dotR = qMin(rowH * 0.35, 5.0);

  const QColor completedFill(0x06, 0x5a, 0x6e);
  const QColor activeFill(0x08, 0x91, 0xb2);
  const QColor futureFill(0x3a, 0x3a, 0x3a);
  const QColor emptySlot(0x22, 0x22, 0x22);
  const QColor textLight(0xe0, 0xe0, 0xe0);
  const QColor textDim(0x66, 0x66, 0x66);

  QFont font = p.font();
  font.setPointSize(8);
  p.setFont(font);

  for (int s = 0; s < m_numSlots; ++s) {
    qreal y = r.y() + s * (rowH + rowSpacing);
    const SlotInfo &si = m_slots[s];

    // Callsign label
    QRectF labelRect(r.x(), y, callLabelW, rowH);
    p.setPen(si.call.isEmpty() ? textDim : textLight);
    font.setBold(!si.call.isEmpty());
    p.setFont(font);
    QString label = si.call.isEmpty() ? QStringLiteral("---") : si.call;
    p.drawText(labelRect, Qt::AlignVCenter | Qt::AlignLeft, label);

    // Progress dots
    qreal dotsX = r.x() + callLabelW + 4;
    qreal dotsW = r.width() - callLabelW - 4;
    qreal dotStep = dotsW / n;

    for (int i = 0; i < n; ++i) {
      qreal cx = dotsX + dotStep * i + dotStep * 0.5;
      qreal cy = y + rowH * 0.5;

      bool isCompleted = (si.step > 0 && i < si.step - 1);
      bool isActive = (si.step > 0 && i == si.step - 1);

      if (si.call.isEmpty()) {
        p.setBrush(emptySlot);
        p.setPen(Qt::NoPen);
      } else if (isActive) {
        p.setBrush(activeFill);
        p.setPen(QPen(QColor(0x22, 0xd3, 0xee), 1.0));
      } else if (isCompleted) {
        p.setBrush(completedFill);
        p.setPen(Qt::NoPen);
      } else {
        p.setBrush(futureFill);
        p.setPen(Qt::NoPen);
      }
      p.drawEllipse(QPointF(cx, cy), dotR, dotR);
    }
  }
}
