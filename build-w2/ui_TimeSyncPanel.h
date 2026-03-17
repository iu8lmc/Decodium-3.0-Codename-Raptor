/********************************************************************************
** Form generated from reading UI file 'TimeSyncPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESYNCPANEL_H
#define UI_TIMESYNCPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeSyncPanel
{
public:
    QHBoxLayout *mainHLayout;
    QVBoxLayout *leftColumn;
    QLabel *lblUtcClock;
    QLabel *lblUtcDate;
    QLabel *lblSystemClock;
    QGroupBox *groupNtp;
    QFormLayout *formLayoutNtp;
    QLabel *labelStatus;
    QLabel *lblNtpStatus;
    QLabel *labelOffset;
    QLabel *lblNtpOffset;
    QLabel *labelLastSync;
    QLabel *lblLastSync;
    QGroupBox *groupDecodeTiming;
    QFormLayout *formLayoutDecodeTiming;
    QLabel *labelAvgDt;
    QLabel *lblAvgDt;
    QLabel *labelDtCorrection;
    QLabel *lblDtCorrection;
    QLabel *labelDecodeCount;
    QLabel *lblDecodeCount;
    QLabel *labelDecodeLatency;
    QLabel *lblDecodeLatency;
    QLabel *labelLastDts;
    QLabel *lblLastDts;
    QLabel *labelConvergence;
    QLabel *lblConvergence;
    QLabel *labelEmaFactor;
    QLabel *lblEmaFactor;
    QLabel *labelWarning;
    QLabel *lblWarning;
    QGroupBox *groupControls;
    QVBoxLayout *verticalLayoutControls;
    QHBoxLayout *horizontalLayoutControls;
    QCheckBox *cbNtpEnabled;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSyncNow;
    QHBoxLayout *horizontalLayoutServer;
    QLabel *labelServer;
    QLineEdit *editCustomServer;
    QGroupBox *groupHistory;
    QVBoxLayout *verticalLayoutHistory;
    QListWidget *listHistory;
    QPushButton *btnClearHistory;
    QVBoxLayout *rightColumn;
    QGroupBox *groupChronoGPS;
    QVBoxLayout *verticalLayoutChrono;
    QLabel *lblChronoIcon;
    QLabel *lblChronoTitle;
    QLabel *lblChronoDesc;
    QLabel *lblChronoAuthor;
    QSpacerItem *chronoSpacer1;
    QLabel *lblChronoStatus;
    QSpacerItem *chronoSpacer2;
    QPushButton *btnLaunchChrono;
    QPushButton *btnStopChrono;
    QSpacerItem *chronoSpacer3;
    QCheckBox *cbChronoAutoLaunch;
    QGroupBox *groupChronoInfo;
    QVBoxLayout *verticalLayoutChronoInfo;
    QLabel *lblChronoInfo;
    QLabel *lblChronoLink;
    QSpacerItem *rightColumnSpacer;

    void setupUi(QDialog *TimeSyncPanel)
    {
        if (TimeSyncPanel->objectName().isEmpty())
            TimeSyncPanel->setObjectName(QString::fromUtf8("TimeSyncPanel"));
        TimeSyncPanel->resize(720, 580);
        TimeSyncPanel->setStyleSheet(QString::fromUtf8("QDialog { background-color: #2b2b2b; color: #ddd; }\n"
"QGroupBox { border: 1px solid #555; border-radius: 4px; margin-top: 8px; padding-top: 12px; color: #ccc; }\n"
"QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 4px; }\n"
"QPushButton { background-color: #444; color: #ddd; border: 1px solid #666; border-radius: 3px; padding: 4px 12px; }\n"
"QPushButton:hover { background-color: #555; }\n"
"QPushButton:disabled { background-color: #333; color: #666; border: 1px solid #444; }\n"
"QCheckBox { color: #ddd; }\n"
"QLineEdit { background-color: #333; color: #ddd; border: 1px solid #555; border-radius: 2px; padding: 2px 4px; }\n"
"QLabel { color: #ddd; }"));
        mainHLayout = new QHBoxLayout(TimeSyncPanel);
        mainHLayout->setSpacing(10);
        mainHLayout->setObjectName(QString::fromUtf8("mainHLayout"));
        mainHLayout->setContentsMargins(10, 10, 10, 10);
        leftColumn = new QVBoxLayout();
        leftColumn->setSpacing(6);
        leftColumn->setObjectName(QString::fromUtf8("leftColumn"));
        lblUtcClock = new QLabel(TimeSyncPanel);
        lblUtcClock->setObjectName(QString::fromUtf8("lblUtcClock"));
        lblUtcClock->setAlignment(Qt::AlignCenter);
        lblUtcClock->setStyleSheet(QString::fromUtf8("font-family: Consolas, 'Courier New', monospace; font-size: 24pt; font-weight: bold; color: #00ff00; background-color: #1a1a1a; padding: 8px; border-radius: 4px;"));

        leftColumn->addWidget(lblUtcClock);

        lblUtcDate = new QLabel(TimeSyncPanel);
        lblUtcDate->setObjectName(QString::fromUtf8("lblUtcDate"));
        lblUtcDate->setAlignment(Qt::AlignCenter);
        lblUtcDate->setStyleSheet(QString::fromUtf8("font-size: 14pt; color: #aaa;"));

        leftColumn->addWidget(lblUtcDate);

        lblSystemClock = new QLabel(TimeSyncPanel);
        lblSystemClock->setObjectName(QString::fromUtf8("lblSystemClock"));
        lblSystemClock->setAlignment(Qt::AlignCenter);
        lblSystemClock->setStyleSheet(QString::fromUtf8("font-size: 10pt; color: #888;"));

        leftColumn->addWidget(lblSystemClock);

        groupNtp = new QGroupBox(TimeSyncPanel);
        groupNtp->setObjectName(QString::fromUtf8("groupNtp"));
        formLayoutNtp = new QFormLayout(groupNtp);
        formLayoutNtp->setObjectName(QString::fromUtf8("formLayoutNtp"));
        labelStatus = new QLabel(groupNtp);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

        formLayoutNtp->setWidget(0, QFormLayout::LabelRole, labelStatus);

        lblNtpStatus = new QLabel(groupNtp);
        lblNtpStatus->setObjectName(QString::fromUtf8("lblNtpStatus"));

        formLayoutNtp->setWidget(0, QFormLayout::FieldRole, lblNtpStatus);

        labelOffset = new QLabel(groupNtp);
        labelOffset->setObjectName(QString::fromUtf8("labelOffset"));

        formLayoutNtp->setWidget(1, QFormLayout::LabelRole, labelOffset);

        lblNtpOffset = new QLabel(groupNtp);
        lblNtpOffset->setObjectName(QString::fromUtf8("lblNtpOffset"));

        formLayoutNtp->setWidget(1, QFormLayout::FieldRole, lblNtpOffset);

        labelLastSync = new QLabel(groupNtp);
        labelLastSync->setObjectName(QString::fromUtf8("labelLastSync"));

        formLayoutNtp->setWidget(2, QFormLayout::LabelRole, labelLastSync);

        lblLastSync = new QLabel(groupNtp);
        lblLastSync->setObjectName(QString::fromUtf8("lblLastSync"));

        formLayoutNtp->setWidget(2, QFormLayout::FieldRole, lblLastSync);


        leftColumn->addWidget(groupNtp);

        groupDecodeTiming = new QGroupBox(TimeSyncPanel);
        groupDecodeTiming->setObjectName(QString::fromUtf8("groupDecodeTiming"));
        formLayoutDecodeTiming = new QFormLayout(groupDecodeTiming);
        formLayoutDecodeTiming->setObjectName(QString::fromUtf8("formLayoutDecodeTiming"));
        labelAvgDt = new QLabel(groupDecodeTiming);
        labelAvgDt->setObjectName(QString::fromUtf8("labelAvgDt"));

        formLayoutDecodeTiming->setWidget(0, QFormLayout::LabelRole, labelAvgDt);

        lblAvgDt = new QLabel(groupDecodeTiming);
        lblAvgDt->setObjectName(QString::fromUtf8("lblAvgDt"));

        formLayoutDecodeTiming->setWidget(0, QFormLayout::FieldRole, lblAvgDt);

        labelDtCorrection = new QLabel(groupDecodeTiming);
        labelDtCorrection->setObjectName(QString::fromUtf8("labelDtCorrection"));

        formLayoutDecodeTiming->setWidget(1, QFormLayout::LabelRole, labelDtCorrection);

        lblDtCorrection = new QLabel(groupDecodeTiming);
        lblDtCorrection->setObjectName(QString::fromUtf8("lblDtCorrection"));

        formLayoutDecodeTiming->setWidget(1, QFormLayout::FieldRole, lblDtCorrection);

        labelDecodeCount = new QLabel(groupDecodeTiming);
        labelDecodeCount->setObjectName(QString::fromUtf8("labelDecodeCount"));

        formLayoutDecodeTiming->setWidget(2, QFormLayout::LabelRole, labelDecodeCount);

        lblDecodeCount = new QLabel(groupDecodeTiming);
        lblDecodeCount->setObjectName(QString::fromUtf8("lblDecodeCount"));

        formLayoutDecodeTiming->setWidget(2, QFormLayout::FieldRole, lblDecodeCount);

        labelDecodeLatency = new QLabel(groupDecodeTiming);
        labelDecodeLatency->setObjectName(QString::fromUtf8("labelDecodeLatency"));

        formLayoutDecodeTiming->setWidget(3, QFormLayout::LabelRole, labelDecodeLatency);

        lblDecodeLatency = new QLabel(groupDecodeTiming);
        lblDecodeLatency->setObjectName(QString::fromUtf8("lblDecodeLatency"));

        formLayoutDecodeTiming->setWidget(3, QFormLayout::FieldRole, lblDecodeLatency);

        labelLastDts = new QLabel(groupDecodeTiming);
        labelLastDts->setObjectName(QString::fromUtf8("labelLastDts"));

        formLayoutDecodeTiming->setWidget(4, QFormLayout::LabelRole, labelLastDts);

        lblLastDts = new QLabel(groupDecodeTiming);
        lblLastDts->setObjectName(QString::fromUtf8("lblLastDts"));
        lblLastDts->setWordWrap(true);

        formLayoutDecodeTiming->setWidget(4, QFormLayout::FieldRole, lblLastDts);

        labelConvergence = new QLabel(groupDecodeTiming);
        labelConvergence->setObjectName(QString::fromUtf8("labelConvergence"));

        formLayoutDecodeTiming->setWidget(5, QFormLayout::LabelRole, labelConvergence);

        lblConvergence = new QLabel(groupDecodeTiming);
        lblConvergence->setObjectName(QString::fromUtf8("lblConvergence"));

        formLayoutDecodeTiming->setWidget(5, QFormLayout::FieldRole, lblConvergence);

        labelEmaFactor = new QLabel(groupDecodeTiming);
        labelEmaFactor->setObjectName(QString::fromUtf8("labelEmaFactor"));

        formLayoutDecodeTiming->setWidget(6, QFormLayout::LabelRole, labelEmaFactor);

        lblEmaFactor = new QLabel(groupDecodeTiming);
        lblEmaFactor->setObjectName(QString::fromUtf8("lblEmaFactor"));

        formLayoutDecodeTiming->setWidget(6, QFormLayout::FieldRole, lblEmaFactor);

        labelWarning = new QLabel(groupDecodeTiming);
        labelWarning->setObjectName(QString::fromUtf8("labelWarning"));

        formLayoutDecodeTiming->setWidget(7, QFormLayout::LabelRole, labelWarning);

        lblWarning = new QLabel(groupDecodeTiming);
        lblWarning->setObjectName(QString::fromUtf8("lblWarning"));
        lblWarning->setWordWrap(true);

        formLayoutDecodeTiming->setWidget(7, QFormLayout::FieldRole, lblWarning);


        leftColumn->addWidget(groupDecodeTiming);

        groupControls = new QGroupBox(TimeSyncPanel);
        groupControls->setObjectName(QString::fromUtf8("groupControls"));
        verticalLayoutControls = new QVBoxLayout(groupControls);
        verticalLayoutControls->setObjectName(QString::fromUtf8("verticalLayoutControls"));
        horizontalLayoutControls = new QHBoxLayout();
        horizontalLayoutControls->setObjectName(QString::fromUtf8("horizontalLayoutControls"));
        cbNtpEnabled = new QCheckBox(groupControls);
        cbNtpEnabled->setObjectName(QString::fromUtf8("cbNtpEnabled"));

        horizontalLayoutControls->addWidget(cbNtpEnabled);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutControls->addItem(horizontalSpacer);

        btnSyncNow = new QPushButton(groupControls);
        btnSyncNow->setObjectName(QString::fromUtf8("btnSyncNow"));

        horizontalLayoutControls->addWidget(btnSyncNow);


        verticalLayoutControls->addLayout(horizontalLayoutControls);

        horizontalLayoutServer = new QHBoxLayout();
        horizontalLayoutServer->setObjectName(QString::fromUtf8("horizontalLayoutServer"));
        labelServer = new QLabel(groupControls);
        labelServer->setObjectName(QString::fromUtf8("labelServer"));

        horizontalLayoutServer->addWidget(labelServer);

        editCustomServer = new QLineEdit(groupControls);
        editCustomServer->setObjectName(QString::fromUtf8("editCustomServer"));

        horizontalLayoutServer->addWidget(editCustomServer);


        verticalLayoutControls->addLayout(horizontalLayoutServer);


        leftColumn->addWidget(groupControls);

        groupHistory = new QGroupBox(TimeSyncPanel);
        groupHistory->setObjectName(QString::fromUtf8("groupHistory"));
        verticalLayoutHistory = new QVBoxLayout(groupHistory);
        verticalLayoutHistory->setObjectName(QString::fromUtf8("verticalLayoutHistory"));
        listHistory = new QListWidget(groupHistory);
        listHistory->setObjectName(QString::fromUtf8("listHistory"));
        listHistory->setMinimumHeight(80);
        listHistory->setStyleSheet(QString::fromUtf8("QListWidget { background-color: #1a1a1a; color: #ddd; border: 1px solid #444; font-family: Consolas, 'Courier New', monospace; font-size: 9pt; }"));
        listHistory->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayoutHistory->addWidget(listHistory);


        leftColumn->addWidget(groupHistory);

        btnClearHistory = new QPushButton(TimeSyncPanel);
        btnClearHistory->setObjectName(QString::fromUtf8("btnClearHistory"));

        leftColumn->addWidget(btnClearHistory);


        mainHLayout->addLayout(leftColumn);

        rightColumn = new QVBoxLayout();
        rightColumn->setSpacing(8);
        rightColumn->setObjectName(QString::fromUtf8("rightColumn"));
        groupChronoGPS = new QGroupBox(TimeSyncPanel);
        groupChronoGPS->setObjectName(QString::fromUtf8("groupChronoGPS"));
        groupChronoGPS->setStyleSheet(QString::fromUtf8("QGroupBox#groupChronoGPS { border: 1px solid #4a7a9b; }"));
        verticalLayoutChrono = new QVBoxLayout(groupChronoGPS);
        verticalLayoutChrono->setSpacing(8);
        verticalLayoutChrono->setObjectName(QString::fromUtf8("verticalLayoutChrono"));
        lblChronoIcon = new QLabel(groupChronoGPS);
        lblChronoIcon->setObjectName(QString::fromUtf8("lblChronoIcon"));
        lblChronoIcon->setAlignment(Qt::AlignCenter);
        lblChronoIcon->setMinimumSize(QSize(64, 64));

        verticalLayoutChrono->addWidget(lblChronoIcon);

        lblChronoTitle = new QLabel(groupChronoGPS);
        lblChronoTitle->setObjectName(QString::fromUtf8("lblChronoTitle"));
        lblChronoTitle->setAlignment(Qt::AlignCenter);
        lblChronoTitle->setStyleSheet(QString::fromUtf8("font-size: 14pt; font-weight: bold; color: #fff;"));

        verticalLayoutChrono->addWidget(lblChronoTitle);

        lblChronoDesc = new QLabel(groupChronoGPS);
        lblChronoDesc->setObjectName(QString::fromUtf8("lblChronoDesc"));
        lblChronoDesc->setAlignment(Qt::AlignCenter);
        lblChronoDesc->setStyleSheet(QString::fromUtf8("color: #aaa;"));

        verticalLayoutChrono->addWidget(lblChronoDesc);

        lblChronoAuthor = new QLabel(groupChronoGPS);
        lblChronoAuthor->setObjectName(QString::fromUtf8("lblChronoAuthor"));
        lblChronoAuthor->setAlignment(Qt::AlignCenter);
        lblChronoAuthor->setStyleSheet(QString::fromUtf8("color: #888; font-style: italic;"));

        verticalLayoutChrono->addWidget(lblChronoAuthor);

        chronoSpacer1 = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayoutChrono->addItem(chronoSpacer1);

        lblChronoStatus = new QLabel(groupChronoGPS);
        lblChronoStatus->setObjectName(QString::fromUtf8("lblChronoStatus"));
        lblChronoStatus->setAlignment(Qt::AlignCenter);
        lblChronoStatus->setStyleSheet(QString::fromUtf8("font-size: 12pt; font-weight: bold; color: #ff4444;"));

        verticalLayoutChrono->addWidget(lblChronoStatus);

        chronoSpacer2 = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayoutChrono->addItem(chronoSpacer2);

        btnLaunchChrono = new QPushButton(groupChronoGPS);
        btnLaunchChrono->setObjectName(QString::fromUtf8("btnLaunchChrono"));
        btnLaunchChrono->setStyleSheet(QString::fromUtf8("QPushButton { padding: 8px 16px; font-size: 11pt; }"));

        verticalLayoutChrono->addWidget(btnLaunchChrono);

        btnStopChrono = new QPushButton(groupChronoGPS);
        btnStopChrono->setObjectName(QString::fromUtf8("btnStopChrono"));
        btnStopChrono->setEnabled(false);
        btnStopChrono->setStyleSheet(QString::fromUtf8("QPushButton { padding: 8px 16px; font-size: 11pt; }"));

        verticalLayoutChrono->addWidget(btnStopChrono);

        chronoSpacer3 = new QSpacerItem(0, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayoutChrono->addItem(chronoSpacer3);

        cbChronoAutoLaunch = new QCheckBox(groupChronoGPS);
        cbChronoAutoLaunch->setObjectName(QString::fromUtf8("cbChronoAutoLaunch"));

        verticalLayoutChrono->addWidget(cbChronoAutoLaunch);


        rightColumn->addWidget(groupChronoGPS);

        groupChronoInfo = new QGroupBox(TimeSyncPanel);
        groupChronoInfo->setObjectName(QString::fromUtf8("groupChronoInfo"));
        verticalLayoutChronoInfo = new QVBoxLayout(groupChronoInfo);
        verticalLayoutChronoInfo->setObjectName(QString::fromUtf8("verticalLayoutChronoInfo"));
        lblChronoInfo = new QLabel(groupChronoInfo);
        lblChronoInfo->setObjectName(QString::fromUtf8("lblChronoInfo"));
        lblChronoInfo->setWordWrap(true);
        lblChronoInfo->setStyleSheet(QString::fromUtf8("color: #aaa; font-size: 9pt;"));

        verticalLayoutChronoInfo->addWidget(lblChronoInfo);

        lblChronoLink = new QLabel(groupChronoInfo);
        lblChronoLink->setObjectName(QString::fromUtf8("lblChronoLink"));
        lblChronoLink->setOpenExternalLinks(true);
        lblChronoLink->setStyleSheet(QString::fromUtf8("font-size: 9pt;"));

        verticalLayoutChronoInfo->addWidget(lblChronoLink);


        rightColumn->addWidget(groupChronoInfo);

        rightColumnSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rightColumn->addItem(rightColumnSpacer);


        mainHLayout->addLayout(rightColumn);


        retranslateUi(TimeSyncPanel);

        QMetaObject::connectSlotsByName(TimeSyncPanel);
    } // setupUi

    void retranslateUi(QDialog *TimeSyncPanel)
    {
        TimeSyncPanel->setWindowTitle(QCoreApplication::translate("TimeSyncPanel", "Time Synchronization", nullptr));
        lblUtcClock->setText(QCoreApplication::translate("TimeSyncPanel", "00:00:00.000 UTC", nullptr));
        lblUtcDate->setText(QCoreApplication::translate("TimeSyncPanel", "2026-01-01", nullptr));
        lblSystemClock->setText(QCoreApplication::translate("TimeSyncPanel", "System: 00:00:00.000", nullptr));
        groupNtp->setTitle(QCoreApplication::translate("TimeSyncPanel", "NTP Status", nullptr));
        labelStatus->setText(QCoreApplication::translate("TimeSyncPanel", "Status:", nullptr));
        lblNtpStatus->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelOffset->setText(QCoreApplication::translate("TimeSyncPanel", "Offset:", nullptr));
        lblNtpOffset->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelLastSync->setText(QCoreApplication::translate("TimeSyncPanel", "Last sync:", nullptr));
        lblLastSync->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        groupDecodeTiming->setTitle(QCoreApplication::translate("TimeSyncPanel", "Decode Timing", nullptr));
        labelAvgDt->setText(QCoreApplication::translate("TimeSyncPanel", "Avg DT:", nullptr));
        lblAvgDt->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelDtCorrection->setText(QCoreApplication::translate("TimeSyncPanel", "DT Correction:", nullptr));
        lblDtCorrection->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelDecodeCount->setText(QCoreApplication::translate("TimeSyncPanel", "Decodes used:", nullptr));
        lblDecodeCount->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelDecodeLatency->setText(QCoreApplication::translate("TimeSyncPanel", "Decode latency:", nullptr));
        lblDecodeLatency->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelLastDts->setText(QCoreApplication::translate("TimeSyncPanel", "Last DTs:", nullptr));
        lblLastDts->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelConvergence->setText(QCoreApplication::translate("TimeSyncPanel", "Convergence:", nullptr));
        lblConvergence->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelEmaFactor->setText(QCoreApplication::translate("TimeSyncPanel", "EMA factor:", nullptr));
        lblEmaFactor->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        labelWarning->setText(QCoreApplication::translate("TimeSyncPanel", "Warning:", nullptr));
        lblWarning->setText(QCoreApplication::translate("TimeSyncPanel", "--", nullptr));
        groupControls->setTitle(QCoreApplication::translate("TimeSyncPanel", "Controls", nullptr));
        cbNtpEnabled->setText(QCoreApplication::translate("TimeSyncPanel", "NTP Enabled", nullptr));
        btnSyncNow->setText(QCoreApplication::translate("TimeSyncPanel", "Sync Now", nullptr));
        labelServer->setText(QCoreApplication::translate("TimeSyncPanel", "Server:", nullptr));
        editCustomServer->setPlaceholderText(QCoreApplication::translate("TimeSyncPanel", "(auto - pool.ntp.org)", nullptr));
        groupHistory->setTitle(QCoreApplication::translate("TimeSyncPanel", "Offset History", nullptr));
        btnClearHistory->setText(QCoreApplication::translate("TimeSyncPanel", "Clear History", nullptr));
        groupChronoGPS->setTitle(QCoreApplication::translate("TimeSyncPanel", "ChronoGPS v2.4.6", nullptr));
        lblChronoIcon->setText(QString());
        lblChronoTitle->setText(QCoreApplication::translate("TimeSyncPanel", "ChronoGPS v2.4.6", nullptr));
        lblChronoDesc->setText(QCoreApplication::translate("TimeSyncPanel", "GPS/NTP Time Synchronization", nullptr));
        lblChronoAuthor->setText(QCoreApplication::translate("TimeSyncPanel", "by Yoshiharu Tsukuura, JP1LRT", nullptr));
        lblChronoStatus->setText(QCoreApplication::translate("TimeSyncPanel", "Stopped", nullptr));
        btnLaunchChrono->setText(QCoreApplication::translate("TimeSyncPanel", "Launch ChronoGPS", nullptr));
        btnStopChrono->setText(QCoreApplication::translate("TimeSyncPanel", "Stop ChronoGPS", nullptr));
        cbChronoAutoLaunch->setText(QCoreApplication::translate("TimeSyncPanel", "Auto-launch with Decodium", nullptr));
        groupChronoInfo->setTitle(QCoreApplication::translate("TimeSyncPanel", "Info", nullptr));
        lblChronoInfo->setText(QCoreApplication::translate("TimeSyncPanel", "ChronoGPS provides precise GPS/NTP time synchronization for digital modes (FT2/FT4/FT8).\n"
"\n"
"Supports GPS, GLONASS, BeiDou, Galileo, SBAS, QZSS receivers + NTP.", nullptr));
        lblChronoLink->setText(QCoreApplication::translate("TimeSyncPanel", "<a href=\"https://github.com/jp1lrt/ChronoGPS\" style=\"color: #5dade2;\">github.com/jp1lrt/ChronoGPS</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeSyncPanel: public Ui_TimeSyncPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESYNCPANEL_H
