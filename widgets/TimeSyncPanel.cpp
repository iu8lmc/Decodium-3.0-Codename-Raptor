// -*- Mode: C++ -*-
#include "TimeSyncPanel.h"
#include "ui_TimeSyncPanel.h"
#include "Network/NtpClient.hpp"
#include "PrecisionTime.hpp"

#include <QSettings>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QCoreApplication>
#include <QFile>
#include <QPixmap>
#include <cmath>

TimeSyncPanel::TimeSyncPanel(QSettings *settings, NtpClient *ntpClient, QWidget *parent)
  : QDialog{parent}
  , settings_{settings}
  , ntpClient_{ntpClient}
  , ui{new Ui::TimeSyncPanel}
{
  ui->setupUi(this);
  setWindowTitle("Time Synchronization");
  setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);

  // Sync initial state from NtpClient
  if (ntpClient_) {
    lastOffsetMs_ = ntpClient_->offsetMs();
    synced_ = ntpClient_->isSynced();
    ui->cbNtpEnabled->setChecked(true);  // will be overridden by syncNtpEnabled()
  }

  // Clock timer — update every 100ms
  connect(&clockTimer_, &QTimer::timeout, this, &TimeSyncPanel::onClockTick);
  clockTimer_.start(100);

  // Initial clock display
  onClockTick();

  // ChronoGPS icon
  QString iconPath = QCoreApplication::applicationDirPath() + "/chronogps_icon.ico";
  if (QFile::exists(iconPath)) {
    QPixmap iconPix(iconPath);
    if (!iconPix.isNull()) {
      ui->lblChronoIcon->setPixmap(iconPix.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
  }

  // ChronoGPS status timer — check every 2s
  connect(&chronoStatusTimer_, &QTimer::timeout, this, &TimeSyncPanel::checkChronoStatus);
  chronoStatusTimer_.start(2000);

  // Initial status check
  checkChronoStatus();

  read_settings();
}

TimeSyncPanel::~TimeSyncPanel()
{
  write_settings();
  delete ui;
}

void TimeSyncPanel::onClockTick()
{
  // System raw time
  qint64 sysMs = preciseCurrentMSecsSinceEpoch();
  QDateTime sysUtc = QDateTime::fromMSecsSinceEpoch(sysMs, Qt::UTC);

  // NTP-corrected time
  qint64 correctedMs = sysMs - qRound64(lastOffsetMs_);
  QDateTime correctedUtc = QDateTime::fromMSecsSinceEpoch(correctedMs, Qt::UTC);

  int fracMs = static_cast<int>(correctedMs % 1000);
  if (fracMs < 0) fracMs += 1000;

  ui->lblUtcClock->setText(
    correctedUtc.toString("hh:mm:ss") +
    QString(".%1 UTC").arg(fracMs, 3, 10, QLatin1Char('0')));

  ui->lblUtcDate->setText(correctedUtc.toString("yyyy-MM-dd"));

  int sysFracMs = static_cast<int>(sysMs % 1000);
  if (sysFracMs < 0) sysFracMs += 1000;
  ui->lblSystemClock->setText(
    QString("System: %1.%2")
    .arg(sysUtc.toString("hh:mm:ss"))
    .arg(sysFracMs, 3, 10, QLatin1Char('0')));
}

void TimeSyncPanel::updateNtpOffset(double offsetMs, int serverCount)
{
  lastOffsetMs_ = offsetMs;

  int rounded = qRound(offsetMs);
  QString text = QString("%1%2 ms  (%3 servers)")
    .arg(rounded > 0 ? "+" : "")
    .arg(rounded)
    .arg(serverCount);
  ui->lblNtpOffset->setText(text);

  // Color-code the offset
  if (qAbs(offsetMs) < 20.0)
    ui->lblNtpOffset->setStyleSheet("color: #00ff00; font-weight: bold;");
  else if (qAbs(offsetMs) < 100.0)
    ui->lblNtpOffset->setStyleSheet("color: #ffff00; font-weight: bold;");
  else
    ui->lblNtpOffset->setStyleSheet("color: #ff4444; font-weight: bold;");

  // Update last sync time
  QDateTime now = QDateTime::currentDateTimeUtc();
  ui->lblLastSync->setText(now.toString("hh:mm:ss") + " UTC");

  // Add to history
  OffsetEntry entry;
  entry.time = now;
  entry.offsetMs = offsetMs;
  entry.serverCount = serverCount;
  history_.prepend(entry);
  if (history_.size() > MAX_HISTORY) {
    history_.resize(MAX_HISTORY);
  }

  // Update history list widget
  QString histLine = QString("%1  %2%3 ms  (%4 srv)")
    .arg(now.toString("hh:mm:ss"))
    .arg(rounded > 0 ? "+" : "")
    .arg(rounded)
    .arg(serverCount);

  auto *item = new QListWidgetItem(histLine);
  if (qAbs(offsetMs) < 20.0)
    item->setForeground(QColor("#00ff00"));
  else if (qAbs(offsetMs) < 100.0)
    item->setForeground(QColor("#ffff00"));
  else
    item->setForeground(QColor("#ff4444"));

  ui->listHistory->insertItem(0, item);
  if (ui->listHistory->count() > MAX_HISTORY) {
    delete ui->listHistory->takeItem(ui->listHistory->count() - 1);
  }
}

void TimeSyncPanel::updateNtpSyncStatus(bool synced, QString const& statusText)
{
  synced_ = synced;
  if (synced) {
    ui->lblNtpStatus->setText("Synced");
    ui->lblNtpStatus->setStyleSheet("color: #00ff00; font-weight: bold;");
  } else {
    ui->lblNtpStatus->setText("Not synced");
    ui->lblNtpStatus->setStyleSheet("color: #ff4444; font-weight: bold;");
  }
  ui->lblNtpStatus->setToolTip(statusText);
}

void TimeSyncPanel::syncNtpEnabled(bool enabled)
{
  ui->cbNtpEnabled->blockSignals(true);
  ui->cbNtpEnabled->setChecked(enabled);
  ui->cbNtpEnabled->blockSignals(false);
}

void TimeSyncPanel::syncCustomServer(QString const& server)
{
  ui->editCustomServer->blockSignals(true);
  ui->editCustomServer->setText(server);
  ui->editCustomServer->blockSignals(false);
}

void TimeSyncPanel::on_btnSyncNow_clicked()
{
  Q_EMIT syncNowRequested();
}

void TimeSyncPanel::on_btnClearHistory_clicked()
{
  history_.clear();
  ui->listHistory->clear();
}

void TimeSyncPanel::on_cbNtpEnabled_toggled(bool checked)
{
  Q_EMIT ntpEnableToggled(checked);
}

void TimeSyncPanel::on_editCustomServer_editingFinished()
{
  Q_EMIT customServerChanged(ui->editCustomServer->text().trimmed());
}

void TimeSyncPanel::on_btnLaunchChrono_clicked()
{
  QString chronoPath = QCoreApplication::applicationDirPath() + "/ChronoGPS.exe";
  if (QFile::exists(chronoPath)) {
    QProcess::startDetached(chronoPath, QStringList{});
    // Check status after a short delay to let the process start
    QTimer::singleShot(1000, this, &TimeSyncPanel::checkChronoStatus);
  } else {
    ui->lblChronoStatus->setText("Not found");
    ui->lblChronoStatus->setStyleSheet("font-size: 12pt; font-weight: bold; color: #ff8800;");
  }
}

void TimeSyncPanel::on_btnStopChrono_clicked()
{
  QProcess taskkill;
  taskkill.start("taskkill", QStringList{"/IM", "ChronoGPS.exe"});
  taskkill.waitForFinished(3000);
  QTimer::singleShot(500, this, &TimeSyncPanel::checkChronoStatus);
}

void TimeSyncPanel::on_cbChronoAutoLaunch_toggled(bool checked)
{
  chronoAutoLaunch_ = checked;
}

void TimeSyncPanel::checkChronoStatus()
{
  QProcess tasklist;
  tasklist.start("tasklist", QStringList{"/FI", "IMAGENAME eq ChronoGPS.exe", "/NH"});
  tasklist.waitForFinished(2000);
  QString output = QString::fromLocal8Bit(tasklist.readAllStandardOutput());
  bool running = output.contains("ChronoGPS.exe", Qt::CaseInsensitive);
  updateChronoButtons(running);
}

void TimeSyncPanel::updateChronoButtons(bool running)
{
  if (running) {
    ui->lblChronoStatus->setText("Running");
    ui->lblChronoStatus->setStyleSheet("font-size: 12pt; font-weight: bold; color: #00ff00;");
    ui->btnLaunchChrono->setEnabled(false);
    ui->btnStopChrono->setEnabled(true);
  } else {
    ui->lblChronoStatus->setText("Stopped");
    ui->lblChronoStatus->setStyleSheet("font-size: 12pt; font-weight: bold; color: #ff4444;");
    ui->btnLaunchChrono->setEnabled(true);
    ui->btnStopChrono->setEnabled(false);
  }
}

void TimeSyncPanel::closeEvent(QCloseEvent *event)
{
  write_settings();
  QDialog::closeEvent(event);
}

void TimeSyncPanel::read_settings()
{
  settings_->beginGroup("TimeSyncPanel");
  restoreGeometry(settings_->value("geometry").toByteArray());
  chronoAutoLaunch_ = settings_->value("chronoAutoLaunch", false).toBool();
  ui->cbChronoAutoLaunch->setChecked(chronoAutoLaunch_);
  settings_->endGroup();
}

void TimeSyncPanel::write_settings()
{
  settings_->beginGroup("TimeSyncPanel");
  settings_->setValue("geometry", saveGeometry());
  settings_->setValue("chronoAutoLaunch", chronoAutoLaunch_);
  settings_->endGroup();
}
