/********************************************************************************
** Form generated from reading UI file 'CabrilloLogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABRILLOLOGWINDOW_H
#define UI_CABRILLOLOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CabrilloLogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *log_table_view;
    QLineEdit *nQSO_lineEdit;

    void setupUi(QWidget *CabrilloLogWindow)
    {
        if (CabrilloLogWindow->objectName().isEmpty())
            CabrilloLogWindow->setObjectName(QString::fromUtf8("CabrilloLogWindow"));
        CabrilloLogWindow->resize(493, 210);
        verticalLayout = new QVBoxLayout(CabrilloLogWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        log_table_view = new QTableView(CabrilloLogWindow);
        log_table_view->setObjectName(QString::fromUtf8("log_table_view"));
        log_table_view->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(log_table_view);

        nQSO_lineEdit = new QLineEdit(CabrilloLogWindow);
        nQSO_lineEdit->setObjectName(QString::fromUtf8("nQSO_lineEdit"));
        nQSO_lineEdit->setMaximumSize(QSize(100, 16777215));
        nQSO_lineEdit->setReadOnly(true);
        nQSO_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(nQSO_lineEdit);


        retranslateUi(CabrilloLogWindow);

        QMetaObject::connectSlotsByName(CabrilloLogWindow);
    } // setupUi

    void retranslateUi(QWidget *CabrilloLogWindow)
    {
        CabrilloLogWindow->setWindowTitle(QCoreApplication::translate("CabrilloLogWindow", "Contest Log", nullptr));
#if QT_CONFIG(tooltip)
        log_table_view->setToolTip(QCoreApplication::translate("CabrilloLogWindow", "<html><head/><body><p>Right-click here for available actions.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        log_table_view->setAccessibleDescription(QCoreApplication::translate("CabrilloLogWindow", "Right-click here for available actions.", nullptr));
#endif // QT_CONFIG(accessibility)
        nQSO_lineEdit->setText(QCoreApplication::translate("CabrilloLogWindow", "0  QSOs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CabrilloLogWindow: public Ui_CabrilloLogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABRILLOLOGWINDOW_H
