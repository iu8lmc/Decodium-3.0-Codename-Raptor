/********************************************************************************
** Form generated from reading UI file 'messageaveraging.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEAVERAGING_H
#define UI_MESSAGEAVERAGING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageAveraging
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPlainTextEdit *msgAvgPlainTextEdit;
    QLabel *header_label;

    void setupUi(QWidget *MessageAveraging)
    {
        if (MessageAveraging->objectName().isEmpty())
            MessageAveraging->setObjectName(QString::fromUtf8("MessageAveraging"));
        MessageAveraging->resize(405, 268);
        verticalLayout = new QVBoxLayout(MessageAveraging);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        msgAvgPlainTextEdit = new QPlainTextEdit(MessageAveraging);
        msgAvgPlainTextEdit->setObjectName(QString::fromUtf8("msgAvgPlainTextEdit"));
        msgAvgPlainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        gridLayout->addWidget(msgAvgPlainTextEdit, 1, 0, 1, 1);

        header_label = new QLabel(MessageAveraging);
        header_label->setObjectName(QString::fromUtf8("header_label"));
        header_label->setMargin(3);

        gridLayout->addWidget(header_label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MessageAveraging);

        QMetaObject::connectSlotsByName(MessageAveraging);
    } // setupUi

    void retranslateUi(QWidget *MessageAveraging)
    {
        MessageAveraging->setWindowTitle(QCoreApplication::translate("MessageAveraging", "Message Averaging", nullptr));
        header_label->setText(QCoreApplication::translate("MessageAveraging", "   UTC  Sync    DT  Freq   ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageAveraging: public Ui_MessageAveraging {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEAVERAGING_H
