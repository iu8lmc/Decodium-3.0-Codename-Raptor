/********************************************************************************
** Form generated from reading UI file 'wf_palette_design_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WF_PALETTE_DESIGN_DIALOG_H
#define UI_WF_PALETTE_DESIGN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_wf_palette_design_dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *colour_table_widget;
    QDialogButtonBox *button_box;

    void setupUi(QDialog *wf_palette_design_dialog)
    {
        if (wf_palette_design_dialog->objectName().isEmpty())
            wf_palette_design_dialog->setObjectName("wf_palette_design_dialog");
        wf_palette_design_dialog->resize(219, 209);
        horizontalLayout = new QHBoxLayout(wf_palette_design_dialog);
        horizontalLayout->setObjectName("horizontalLayout");
        colour_table_widget = new QTableWidget(wf_palette_design_dialog);
        if (colour_table_widget->columnCount() < 1)
            colour_table_widget->setColumnCount(1);
        colour_table_widget->setObjectName("colour_table_widget");
        colour_table_widget->setContextMenuPolicy(Qt::CustomContextMenu);
        colour_table_widget->setSelectionMode(QAbstractItemView::NoSelection);
        colour_table_widget->setColumnCount(1);
        colour_table_widget->horizontalHeader()->setVisible(false);
        colour_table_widget->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(colour_table_widget);

        button_box = new QDialogButtonBox(wf_palette_design_dialog);
        button_box->setObjectName("button_box");
        button_box->setOrientation(Qt::Vertical);
        button_box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(button_box);


        retranslateUi(wf_palette_design_dialog);
        QObject::connect(button_box, &QDialogButtonBox::accepted, wf_palette_design_dialog, qOverload<>(&QDialog::accept));
        QObject::connect(button_box, &QDialogButtonBox::rejected, wf_palette_design_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(wf_palette_design_dialog);
    } // setupUi

    void retranslateUi(QDialog *wf_palette_design_dialog)
    {
        wf_palette_design_dialog->setWindowTitle(QCoreApplication::translate("wf_palette_design_dialog", "Palette Designer", nullptr));
#if QT_CONFIG(tooltip)
        colour_table_widget->setToolTip(QCoreApplication::translate("wf_palette_design_dialog", "<html><head/><body><p>Double click a color to edit it.</p><p>Right click to insert or delete colors.</p><p>Colors at the top represent weak signals</p><p>and colors at the bottom represent strong</p><p>signals. You can have up to 256 colors.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class wf_palette_design_dialog: public Ui_wf_palette_design_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WF_PALETTE_DESIGN_DIALOG_H
