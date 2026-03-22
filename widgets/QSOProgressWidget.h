#ifndef QSOPROGRESSWIDGET_H
#define QSOPROGRESSWIDGET_H

#include <QWidget>
#include <QPainter>

class QSOProgressWidget : public QWidget
{
  Q_OBJECT
public:
  explicit QSOProgressWidget(QWidget *parent = nullptr);

  // Step names: 0=Idle, 1=CQ, 2=Reply, 3=Report, 4=R+Report, 5=RR73, 6=73
  void setStep(int step);
  void setMaxSteps(int n);  // default 6
  void setSlotInfo(int slot, const QString &call, int step); // for DXped multi-slot
  void setNumSlots(int n);  // 0 = single QSO mode, 1-4 = DXped slots
  void reset();

  QSize minimumSizeHint() const override { return QSize(200, 24); }
  QSize sizeHint() const override { return QSize(400, 28); }

protected:
  void paintEvent(QPaintEvent *) override;

private:
  static constexpr int MAX_SLOTS = 4;
  int m_step {0};
  int m_maxSteps {6};
  int m_numSlots {0};  // 0 = single mode
  struct SlotInfo { QString call; int step {0}; };
  SlotInfo m_slots[MAX_SLOTS];

  static QStringList stepLabels() { return {"CQ", "Reply", "Rpt", "R+Rpt", "RR73", "73\xe2\x9c\x93"}; }
  void drawSingleMode(QPainter &p, const QRect &r);
  void drawMultiSlot(QPainter &p, const QRect &r);
};

#endif
