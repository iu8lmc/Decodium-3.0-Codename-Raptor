/********************************************************************************
** Form generated from reading UI file 'qsymonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSYMONITOR_H
#define UI_QSYMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSYMonitor
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *qsyMonitorLabel;
    QTextBrowser *QSYMonitorTextBrowser;
    QPushButton *clearButton;

    void setupUi(QWidget *QSYMonitor)
    {
        if (QSYMonitor->objectName().isEmpty())
            QSYMonitor->setObjectName(QString::fromUtf8("QSYMonitor"));
        QSYMonitor->resize(380, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QSYMonitor->sizePolicy().hasHeightForWidth());
        QSYMonitor->setSizePolicy(sizePolicy);
        QSYMonitor->setMinimumSize(QSize(380, 0));
        QSYMonitor->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(QSYMonitor);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qsyMonitorLabel = new QLabel(QSYMonitor);
        qsyMonitorLabel->setObjectName(QString::fromUtf8("qsyMonitorLabel"));

        verticalLayout->addWidget(qsyMonitorLabel);

        QSYMonitorTextBrowser = new QTextBrowser(QSYMonitor);
        QSYMonitorTextBrowser->setObjectName(QString::fromUtf8("QSYMonitorTextBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QSYMonitorTextBrowser->sizePolicy().hasHeightForWidth());
        QSYMonitorTextBrowser->setSizePolicy(sizePolicy1);
        QSYMonitorTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(QSYMonitorTextBrowser);

        clearButton = new QPushButton(QSYMonitor);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        verticalLayout->addWidget(clearButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QSYMonitor);

        QMetaObject::connectSlotsByName(QSYMonitor);
    } // setupUi

    void retranslateUi(QWidget *QSYMonitor)
    {
        QSYMonitor->setWindowTitle(QCoreApplication::translate("QSYMonitor", "QSYMonitor", nullptr));
        qsyMonitorLabel->setText(QString());
        clearButton->setText(QCoreApplication::translate("QSYMonitor", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSYMonitor: public Ui_QSYMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSYMONITOR_H
