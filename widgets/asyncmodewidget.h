#ifndef ASYNCMODEWIDGET_H
#define ASYNCMODEWIDGET_H

#include <QWidget>
#include <QTimer>

class AsyncModeWidget : public QWidget
{
  Q_OBJECT
  Q_PROPERTY (int snr READ snr WRITE setSnr)
  Q_PROPERTY (bool transmitting READ transmitting WRITE setTransmitting)

public:
  explicit AsyncModeWidget (QWidget *parent = nullptr);

  int snr () const { return m_snr; }
  bool transmitting () const { return m_transmitting; }

  QSize sizeHint () const override { return {56, 80}; }
  QSize minimumSizeHint () const override { return {48, 60}; }

public slots:
  void setSnr (int value);
  void setTransmitting (bool tx);
  void start ();
  void stop ();

protected:
  void paintEvent (QPaintEvent *) override;

private:
  QTimer m_animTimer;
  qreal  m_phase {0.0};
  int    m_snr {-99};
  bool   m_transmitting {false};
  bool   m_running {false};
};

#endif // ASYNCMODEWIDGET_H
