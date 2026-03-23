/********************************************************************************
** Form generated from reading UI file 'QSYMessage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSYMESSAGE_H
#define UI_QSYMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSYMessage
{
public:
    QLabel *label;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QWidget *QSYMessage)
    {
        if (QSYMessage->objectName().isEmpty())
            QSYMessage->setObjectName(QString::fromUtf8("QSYMessage"));
        QSYMessage->resize(449, 300);
        QSYMessage->setMinimumSize(QSize(449, 300));
        QSYMessage->setMaximumSize(QSize(449, 300));
        label = new QLabel(QSYMessage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(3, 10, 443, 231));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        yesButton = new QPushButton(QSYMessage);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(20, 240, 75, 51));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        yesButton->setFont(font1);
        noButton = new QPushButton(QSYMessage);
        noButton->setObjectName(QString::fromUtf8("noButton"));
        noButton->setGeometry(QRect(360, 240, 75, 51));
        noButton->setFont(font1);

        retranslateUi(QSYMessage);

        QMetaObject::connectSlotsByName(QSYMessage);
    } // setupUi

    void retranslateUi(QWidget *QSYMessage)
    {
        QSYMessage->setWindowTitle(QCoreApplication::translate("QSYMessage", "Decodium v3.0 Shannon 2603161508", nullptr));
        label->setText(QCoreApplication::translate("QSYMessage", "TextLabel", nullptr));
        yesButton->setText(QCoreApplication::translate("QSYMessage", "Reply \n"
"Yes", nullptr));
        noButton->setText(QCoreApplication::translate("QSYMessage", "Reply \n"
"No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSYMessage: public Ui_QSYMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSYMESSAGE_H
