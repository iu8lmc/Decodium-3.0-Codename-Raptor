/********************************************************************************
** Form generated from reading UI file 'activeStations.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVESTATIONS_H
#define UI_ACTIVESTATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActiveStations
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *score;
    QLineEdit *rate;
    QCheckBox *cbReadyOnly;
    QCheckBox *cbWantedOnly;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *sbMaxAge;
    QSpinBox *sbMaxRecent;
    QLineEdit *bandChanges;
    QPlainTextEdit *RecentStationsPlainTextEdit;
    QLabel *header_label2;

    void setupUi(QWidget *ActiveStations)
    {
        if (ActiveStations->objectName().isEmpty())
            ActiveStations->setObjectName(QString::fromUtf8("ActiveStations"));
        ActiveStations->resize(400, 340);
        verticalLayout = new QVBoxLayout(ActiveStations);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(ActiveStations);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        score = new QLineEdit(ActiveStations);
        score->setObjectName(QString::fromUtf8("score"));
        score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        score->setReadOnly(true);

        gridLayout_2->addWidget(score, 1, 5, 1, 1);

        rate = new QLineEdit(ActiveStations);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setMaximumSize(QSize(16777215, 16777215));
        rate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rate->setReadOnly(true);

        gridLayout_2->addWidget(rate, 0, 5, 1, 1);

        cbReadyOnly = new QCheckBox(ActiveStations);
        cbReadyOnly->setObjectName(QString::fromUtf8("cbReadyOnly"));

        gridLayout_2->addWidget(cbReadyOnly, 0, 3, 1, 1);

        cbWantedOnly = new QCheckBox(ActiveStations);
        cbWantedOnly->setObjectName(QString::fromUtf8("cbWantedOnly"));
        cbWantedOnly->setVisible(false);

        gridLayout_2->addWidget(cbWantedOnly, 0, 1, 1, 1);

        label_2 = new QLabel(ActiveStations);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 4, 1, 1);

        label = new QLabel(ActiveStations);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 4, 1, 1);

        sbMaxAge = new QSpinBox(ActiveStations);
        sbMaxAge->setObjectName(QString::fromUtf8("sbMaxAge"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbMaxAge->sizePolicy().hasHeightForWidth());
        sbMaxAge->setSizePolicy(sizePolicy);
        sbMaxAge->setMinimumSize(QSize(0, 0));
        sbMaxAge->setMaximumSize(QSize(16777215, 16777215));
        sbMaxAge->setAlignment(Qt::AlignCenter);
        sbMaxAge->setMinimum(0);
        sbMaxAge->setMaximum(60);
        sbMaxAge->setValue(4);

        gridLayout_2->addWidget(sbMaxAge, 0, 0, 1, 1);

        sbMaxRecent = new QSpinBox(ActiveStations);
        sbMaxRecent->setObjectName(QString::fromUtf8("sbMaxRecent"));
        sizePolicy.setHeightForWidth(sbMaxRecent->sizePolicy().hasHeightForWidth());
        sbMaxRecent->setSizePolicy(sizePolicy);
        sbMaxRecent->setMinimumSize(QSize(0, 0));
        sbMaxRecent->setAlignment(Qt::AlignCenter);
        sbMaxRecent->setMaximum(50);
        sbMaxRecent->setValue(10);

        gridLayout_2->addWidget(sbMaxRecent, 0, 2, 1, 1);

        bandChanges = new QLineEdit(ActiveStations);
        bandChanges->setObjectName(QString::fromUtf8("bandChanges"));
        bandChanges->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bandChanges->setReadOnly(true);

        gridLayout_2->addWidget(bandChanges, 1, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(5, 1);

        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        RecentStationsPlainTextEdit = new QPlainTextEdit(ActiveStations);
        RecentStationsPlainTextEdit->setObjectName(QString::fromUtf8("RecentStationsPlainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(RecentStationsPlainTextEdit->sizePolicy().hasHeightForWidth());
        RecentStationsPlainTextEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(RecentStationsPlainTextEdit, 1, 0, 1, 1);

        header_label2 = new QLabel(ActiveStations);
        header_label2->setObjectName(QString::fromUtf8("header_label2"));

        gridLayout->addWidget(header_label2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ActiveStations);

        QMetaObject::connectSlotsByName(ActiveStations);
    } // setupUi

    void retranslateUi(QWidget *ActiveStations)
    {
        ActiveStations->setWindowTitle(QCoreApplication::translate("ActiveStations", "Message Averaging", nullptr));
        label_3->setText(QCoreApplication::translate("ActiveStations", "Band Changes:", nullptr));
#if QT_CONFIG(tooltip)
        score->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Total score accumulated since most recent reset of Cabrillo log.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        score->setText(QCoreApplication::translate("ActiveStations", "0", nullptr));
#if QT_CONFIG(tooltip)
        rate->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Points logged during the past hour.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rate->setText(QCoreApplication::translate("ActiveStations", "0", nullptr));
#if QT_CONFIG(tooltip)
        cbReadyOnly->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Check this box to show only stations ready to be called.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbReadyOnly->setText(QCoreApplication::translate("ActiveStations", "Ready only", nullptr));
        cbWantedOnly->setText(QCoreApplication::translate("ActiveStations", "# Wanted only", nullptr));
        label_2->setText(QCoreApplication::translate("ActiveStations", "Score:", nullptr));
        label->setText(QCoreApplication::translate("ActiveStations", "Rate:", nullptr));
#if QT_CONFIG(tooltip)
        sbMaxAge->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Set maximum elapsed number of T/R sequences.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbMaxAge->setPrefix(QCoreApplication::translate("ActiveStations", "Max Age  ", nullptr));
#if QT_CONFIG(tooltip)
        sbMaxRecent->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Set maximum number of displayed lines.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbMaxRecent->setPrefix(QCoreApplication::translate("ActiveStations", "Max N  ", nullptr));
#if QT_CONFIG(tooltip)
        bandChanges->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Number of band changes during the past hour.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        bandChanges->setText(QCoreApplication::translate("ActiveStations", "0", nullptr));
#if QT_CONFIG(tooltip)
        RecentStationsPlainTextEdit->setToolTip(QCoreApplication::translate("ActiveStations", "<html><head/><body><p>Click on a line to call that station. </p><p>When using QMAP, single click to transfer QSO data and sked frequency to Decodium v3.0 FT2 Raptor 2603161508, and double click to call that station.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        header_label2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActiveStations: public Ui_ActiveStations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVESTATIONS_H
