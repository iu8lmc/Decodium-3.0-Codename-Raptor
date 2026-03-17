/********************************************************************************
** Form generated from reading UI file 'logqso.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGQSO_H
#define UI_LOGQSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogQSO
{
public:
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lab1;
    QLineEdit *call;
    QVBoxLayout *verticalLayout_2;
    QLabel *lab2;
    QDateTimeEdit *start_date_time;
    QVBoxLayout *verticalLayout_3;
    QLabel *lab2_3;
    QDateTimeEdit *end_date_time;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *lab4;
    QLineEdit *mode;
    QVBoxLayout *verticalLayout_6;
    QLabel *lab5;
    QLineEdit *band;
    QVBoxLayout *verticalLayout_7;
    QLabel *lab6;
    QLineEdit *sent;
    QVBoxLayout *verticalLayout_8;
    QLabel *lab7;
    QLineEdit *rcvd;
    QVBoxLayout *verticalLayout_9;
    QLabel *lab8;
    QLineEdit *grid;
    QVBoxLayout *verticalLayout_10;
    QLabel *lab9;
    QLineEdit *name;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *addButton;
    QCheckBox *cbTxPower;
    QCheckBox *cbComments;
    QLabel *lab10;
    QLabel *operatorLabel;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *exchSent;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *exchRcvd;
    QLineEdit *txPower;
    QComboBox *comments;
    QLineEdit *loggedOperator;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *cbSatMode;
    QCheckBox *cbPropMode;
    QLabel *label_8;
    QCheckBox *cbSatellite;
    QComboBox *comboBoxSatMode;
    QLabel *label_7;
    QCheckBox *cbFreqRx;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBoxPropMode;
    QComboBox *comboBoxSatellite;
    QLineEdit *freqRx;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LogQSO)
    {
        if (LogQSO->objectName().isEmpty())
            LogQSO->setObjectName(QString::fromUtf8("LogQSO"));
        LogQSO->resize(480, 420);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogQSO->sizePolicy().hasHeightForWidth());
        LogQSO->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(LogQSO);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(LogQSO);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lab1 = new QLabel(LogQSO);
        lab1->setObjectName(QString::fromUtf8("lab1"));
        lab1->setFont(font);
        lab1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lab1);

        call = new QLineEdit(LogQSO);
        call->setObjectName(QString::fromUtf8("call"));

        verticalLayout->addWidget(call);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lab2 = new QLabel(LogQSO);
        lab2->setObjectName(QString::fromUtf8("lab2"));
        lab2->setFont(font);
        lab2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lab2);

        start_date_time = new QDateTimeEdit(LogQSO);
        start_date_time->setObjectName(QString::fromUtf8("start_date_time"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(start_date_time->sizePolicy().hasHeightForWidth());
        start_date_time->setSizePolicy(sizePolicy1);
        start_date_time->setTimeSpec(Qt::UTC);

        verticalLayout_2->addWidget(start_date_time);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lab2_3 = new QLabel(LogQSO);
        lab2_3->setObjectName(QString::fromUtf8("lab2_3"));
        lab2_3->setFont(font);
        lab2_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lab2_3);

        end_date_time = new QDateTimeEdit(LogQSO);
        end_date_time->setObjectName(QString::fromUtf8("end_date_time"));
        sizePolicy1.setHeightForWidth(end_date_time->sizePolicy().hasHeightForWidth());
        end_date_time->setSizePolicy(sizePolicy1);
        end_date_time->setTimeSpec(Qt::UTC);

        verticalLayout_3->addWidget(end_date_time);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lab4 = new QLabel(LogQSO);
        lab4->setObjectName(QString::fromUtf8("lab4"));
        lab4->setFont(font);
        lab4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lab4);

        mode = new QLineEdit(LogQSO);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(mode);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lab5 = new QLabel(LogQSO);
        lab5->setObjectName(QString::fromUtf8("lab5"));
        lab5->setFont(font);
        lab5->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lab5);

        band = new QLineEdit(LogQSO);
        band->setObjectName(QString::fromUtf8("band"));
        band->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(band);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lab6 = new QLabel(LogQSO);
        lab6->setObjectName(QString::fromUtf8("lab6"));
        lab6->setFont(font);
        lab6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(lab6);

        sent = new QLineEdit(LogQSO);
        sent->setObjectName(QString::fromUtf8("sent"));
        sent->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_7->addWidget(sent);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lab7 = new QLabel(LogQSO);
        lab7->setObjectName(QString::fromUtf8("lab7"));
        lab7->setFont(font);
        lab7->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(lab7);

        rcvd = new QLineEdit(LogQSO);
        rcvd->setObjectName(QString::fromUtf8("rcvd"));
        rcvd->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_8->addWidget(rcvd);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lab8 = new QLabel(LogQSO);
        lab8->setObjectName(QString::fromUtf8("lab8"));
        lab8->setFont(font);
        lab8->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(lab8);

        grid = new QLineEdit(LogQSO);
        grid->setObjectName(QString::fromUtf8("grid"));
        grid->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_9->addWidget(grid);


        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lab9 = new QLabel(LogQSO);
        lab9->setObjectName(QString::fromUtf8("lab9"));
        lab9->setEnabled(true);
        lab9->setFont(font);
        lab9->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(lab9);

        name = new QLineEdit(LogQSO);
        name->setObjectName(QString::fromUtf8("name"));
        name->setEnabled(true);

        verticalLayout_10->addWidget(name);


        horizontalLayout_4->addLayout(verticalLayout_10);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 2);

        verticalLayout_5->addLayout(horizontalLayout_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(LogQSO);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        addButton = new QPushButton(LogQSO);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_2->addWidget(addButton, 1, 4, 1, 1);

        cbTxPower = new QCheckBox(LogQSO);
        cbTxPower->setObjectName(QString::fromUtf8("cbTxPower"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbTxPower->sizePolicy().hasHeightForWidth());
        cbTxPower->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(cbTxPower, 0, 5, 1, 1);

        cbComments = new QCheckBox(LogQSO);
        cbComments->setObjectName(QString::fromUtf8("cbComments"));

        gridLayout_2->addWidget(cbComments, 1, 5, 1, 1);

        lab10 = new QLabel(LogQSO);
        lab10->setObjectName(QString::fromUtf8("lab10"));
        lab10->setEnabled(true);
        lab10->setFont(font);

        gridLayout_2->addWidget(lab10, 1, 0, 1, 1);

        operatorLabel = new QLabel(LogQSO);
        operatorLabel->setObjectName(QString::fromUtf8("operatorLabel"));
        operatorLabel->setFont(font);

        gridLayout_2->addWidget(operatorLabel, 2, 0, 1, 1);

        label_3 = new QLabel(LogQSO);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        exchSent = new QLineEdit(LogQSO);
        exchSent->setObjectName(QString::fromUtf8("exchSent"));
        exchSent->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(exchSent);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_4 = new QLabel(LogQSO);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        exchRcvd = new QLineEdit(LogQSO);
        exchRcvd->setObjectName(QString::fromUtf8("exchRcvd"));
        exchRcvd->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(exchRcvd);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 1, 1, 5);

        txPower = new QLineEdit(LogQSO);
        txPower->setObjectName(QString::fromUtf8("txPower"));

        gridLayout_2->addWidget(txPower, 0, 1, 1, 4);

        comments = new QComboBox(LogQSO);
        comments->setObjectName(QString::fromUtf8("comments"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comments->sizePolicy().hasHeightForWidth());
        comments->setSizePolicy(sizePolicy3);
        comments->setEditable(true);

        gridLayout_2->addWidget(comments, 1, 1, 1, 3);

        loggedOperator = new QLineEdit(LogQSO);
        loggedOperator->setObjectName(QString::fromUtf8("loggedOperator"));
        loggedOperator->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(loggedOperator, 2, 1, 1, 4);

        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout_5->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(LogQSO);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(LogQSO);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        cbSatMode = new QCheckBox(LogQSO);
        cbSatMode->setObjectName(QString::fromUtf8("cbSatMode"));

        gridLayout->addWidget(cbSatMode, 2, 3, 1, 1);

        cbPropMode = new QCheckBox(LogQSO);
        cbPropMode->setObjectName(QString::fromUtf8("cbPropMode"));

        gridLayout->addWidget(cbPropMode, 0, 3, 1, 1);

        label_8 = new QLabel(LogQSO);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        cbSatellite = new QCheckBox(LogQSO);
        cbSatellite->setObjectName(QString::fromUtf8("cbSatellite"));

        gridLayout->addWidget(cbSatellite, 1, 3, 1, 1);

        comboBoxSatMode = new QComboBox(LogQSO);
        comboBoxSatMode->setObjectName(QString::fromUtf8("comboBoxSatMode"));

        gridLayout->addWidget(comboBoxSatMode, 2, 1, 1, 1);

        label_7 = new QLabel(LogQSO);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        cbFreqRx = new QCheckBox(LogQSO);
        cbFreqRx->setObjectName(QString::fromUtf8("cbFreqRx"));

        gridLayout->addWidget(cbFreqRx, 3, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        comboBoxPropMode = new QComboBox(LogQSO);
        comboBoxPropMode->setObjectName(QString::fromUtf8("comboBoxPropMode"));

        gridLayout->addWidget(comboBoxPropMode, 0, 1, 1, 2);

        comboBoxSatellite = new QComboBox(LogQSO);
        comboBoxSatellite->setObjectName(QString::fromUtf8("comboBoxSatellite"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBoxSatellite->sizePolicy().hasHeightForWidth());
        comboBoxSatellite->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(comboBoxSatellite, 1, 1, 1, 2);

        freqRx = new QLineEdit(LogQSO);
        freqRx->setObjectName(QString::fromUtf8("freqRx"));

        gridLayout->addWidget(freqRx, 3, 1, 1, 2);

        gridLayout->setColumnStretch(1, 2);

        verticalLayout_5->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(LogQSO);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        lab1->setBuddy(call);
        lab2->setBuddy(start_date_time);
        lab2_3->setBuddy(end_date_time);
        lab4->setBuddy(mode);
        lab5->setBuddy(band);
        lab6->setBuddy(sent);
        lab7->setBuddy(rcvd);
        lab8->setBuddy(grid);
        lab9->setBuddy(name);
        label_2->setBuddy(txPower);
        operatorLabel->setBuddy(loggedOperator);
        label_3->setBuddy(exchSent);
        label_4->setBuddy(exchRcvd);
        label_5->setBuddy(comboBoxPropMode);
        label_6->setBuddy(comboBoxSatellite);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(call, start_date_time);
        QWidget::setTabOrder(start_date_time, end_date_time);
        QWidget::setTabOrder(end_date_time, mode);
        QWidget::setTabOrder(mode, band);
        QWidget::setTabOrder(band, sent);
        QWidget::setTabOrder(sent, rcvd);
        QWidget::setTabOrder(rcvd, grid);
        QWidget::setTabOrder(grid, name);

        retranslateUi(LogQSO);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogQSO, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogQSO, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogQSO);
    } // setupUi

    void retranslateUi(QDialog *LogQSO)
    {
        label->setText(QCoreApplication::translate("LogQSO", "Click OK to confirm the following QSO:", nullptr));
        lab1->setText(QCoreApplication::translate("LogQSO", "Call", nullptr));
        lab2->setText(QCoreApplication::translate("LogQSO", "Start", nullptr));
        start_date_time->setDisplayFormat(QCoreApplication::translate("LogQSO", "dd/MM/yyyy HH:mm:ss", nullptr));
        lab2_3->setText(QCoreApplication::translate("LogQSO", "End", nullptr));
        end_date_time->setDisplayFormat(QCoreApplication::translate("LogQSO", "dd/MM/yyyy HH:mm:ss", nullptr));
        lab4->setText(QCoreApplication::translate("LogQSO", "Mode", nullptr));
        lab5->setText(QCoreApplication::translate("LogQSO", "Band", nullptr));
        lab6->setText(QCoreApplication::translate("LogQSO", "Rpt Sent", nullptr));
        lab7->setText(QCoreApplication::translate("LogQSO", "Rpt Rcvd", nullptr));
        lab8->setText(QCoreApplication::translate("LogQSO", "Grid", nullptr));
        lab9->setText(QCoreApplication::translate("LogQSO", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("LogQSO", "Tx power", nullptr));
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("LogQSO", "<html><head/><body><p>Add comment to the comments list.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addButton->setText(QCoreApplication::translate("LogQSO", "Add", nullptr));
        cbTxPower->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        cbComments->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        lab10->setText(QCoreApplication::translate("LogQSO", "Comments", nullptr));
        operatorLabel->setText(QCoreApplication::translate("LogQSO", "Operator", nullptr));
        label_3->setText(QCoreApplication::translate("LogQSO", "Exch sent", nullptr));
        label_4->setText(QCoreApplication::translate("LogQSO", "Rcvd", nullptr));
        label_5->setText(QCoreApplication::translate("LogQSO", "Prop Mode", nullptr));
        label_6->setText(QCoreApplication::translate("LogQSO", "Satellite", nullptr));
        cbSatMode->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        cbPropMode->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        label_8->setText(QCoreApplication::translate("LogQSO", "Sat Mode", nullptr));
        cbSatellite->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        label_7->setText(QCoreApplication::translate("LogQSO", "RX Frequency", nullptr));
        cbFreqRx->setText(QCoreApplication::translate("LogQSO", "Retain", nullptr));
        (void)LogQSO;
    } // retranslateUi

};

namespace Ui {
    class LogQSO: public Ui_LogQSO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGQSO_H
