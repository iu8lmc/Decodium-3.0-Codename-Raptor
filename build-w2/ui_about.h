/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAboutDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTxt;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CAboutDlg)
    {
        if (CAboutDlg->objectName().isEmpty())
            CAboutDlg->setObjectName(QString::fromUtf8("CAboutDlg"));
        CAboutDlg->setWindowModality(Qt::NonModal);
        verticalLayout = new QVBoxLayout(CAboutDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelTxt = new QLabel(CAboutDlg);
        labelTxt->setObjectName(QString::fromUtf8("labelTxt"));
        labelTxt->setAlignment(Qt::AlignCenter);
        labelTxt->setOpenExternalLinks(true);

        horizontalLayout_2->addWidget(labelTxt);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(CAboutDlg);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CAboutDlg);
        QObject::connect(okButton, SIGNAL(clicked()), CAboutDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(CAboutDlg);
    } // setupUi

    void retranslateUi(QDialog *CAboutDlg)
    {
        CAboutDlg->setWindowTitle(QCoreApplication::translate("CAboutDlg", "About Decodium Shannon v3.0 \342\200\224 Build 2603221027", nullptr));
        labelTxt->setText(QString());
        okButton->setText(QCoreApplication::translate("CAboutDlg", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAboutDlg: public Ui_CAboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
