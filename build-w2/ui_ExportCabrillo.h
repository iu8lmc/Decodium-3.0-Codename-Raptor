/********************************************************************************
** Form generated from reading UI file 'ExportCabrillo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTCABRILLO_H
#define UI_EXPORTCABRILLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExportCabrillo
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *location_label;
    QLineEdit *location_line_edit;
    QLabel *contest_label;
    QLineEdit *contest_line_edit;
    QLabel *call_label;
    QLineEdit *call_line_edit;
    QLabel *category_op_label;
    QLineEdit *category_op_line_edit;
    QLabel *category_xmtr_label;
    QLineEdit *category_xmtr_line_edit;
    QLabel *category_pwr_label;
    QLineEdit *category_pwr_line_edit;
    QLabel *category_assisted_label;
    QLineEdit *category_assisted_line_edit;
    QLabel *category_band_label;
    QLineEdit *category_band_line_edit;
    QLabel *claimed_label;
    QLineEdit *claimed_line_edit;
    QLabel *operators_label;
    QLineEdit *operators_line_edit;
    QLabel *club_label;
    QLineEdit *club_line_edit;
    QLabel *name_label;
    QLineEdit *name_line_edit;
    QLabel *addr_1_label;
    QLineEdit *addr_1_line_edit;
    QLabel *addr_2_label;
    QLineEdit *addr_2_line_edit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExportCabrillo)
    {
        if (ExportCabrillo->objectName().isEmpty())
            ExportCabrillo->setObjectName(QString::fromUtf8("ExportCabrillo"));
        verticalLayout = new QVBoxLayout(ExportCabrillo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        location_label = new QLabel(ExportCabrillo);
        location_label->setObjectName(QString::fromUtf8("location_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, location_label);

        location_line_edit = new QLineEdit(ExportCabrillo);
        location_line_edit->setObjectName(QString::fromUtf8("location_line_edit"));
        location_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, location_line_edit);

        contest_label = new QLabel(ExportCabrillo);
        contest_label->setObjectName(QString::fromUtf8("contest_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, contest_label);

        contest_line_edit = new QLineEdit(ExportCabrillo);
        contest_line_edit->setObjectName(QString::fromUtf8("contest_line_edit"));
        contest_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, contest_line_edit);

        call_label = new QLabel(ExportCabrillo);
        call_label->setObjectName(QString::fromUtf8("call_label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, call_label);

        call_line_edit = new QLineEdit(ExportCabrillo);
        call_line_edit->setObjectName(QString::fromUtf8("call_line_edit"));
        call_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, call_line_edit);

        category_op_label = new QLabel(ExportCabrillo);
        category_op_label->setObjectName(QString::fromUtf8("category_op_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, category_op_label);

        category_op_line_edit = new QLineEdit(ExportCabrillo);
        category_op_line_edit->setObjectName(QString::fromUtf8("category_op_line_edit"));
        category_op_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, category_op_line_edit);

        category_xmtr_label = new QLabel(ExportCabrillo);
        category_xmtr_label->setObjectName(QString::fromUtf8("category_xmtr_label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, category_xmtr_label);

        category_xmtr_line_edit = new QLineEdit(ExportCabrillo);
        category_xmtr_line_edit->setObjectName(QString::fromUtf8("category_xmtr_line_edit"));
        category_xmtr_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, category_xmtr_line_edit);

        category_pwr_label = new QLabel(ExportCabrillo);
        category_pwr_label->setObjectName(QString::fromUtf8("category_pwr_label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, category_pwr_label);

        category_pwr_line_edit = new QLineEdit(ExportCabrillo);
        category_pwr_line_edit->setObjectName(QString::fromUtf8("category_pwr_line_edit"));
        category_pwr_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, category_pwr_line_edit);

        category_assisted_label = new QLabel(ExportCabrillo);
        category_assisted_label->setObjectName(QString::fromUtf8("category_assisted_label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, category_assisted_label);

        category_assisted_line_edit = new QLineEdit(ExportCabrillo);
        category_assisted_line_edit->setObjectName(QString::fromUtf8("category_assisted_line_edit"));
        category_assisted_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, category_assisted_line_edit);

        category_band_label = new QLabel(ExportCabrillo);
        category_band_label->setObjectName(QString::fromUtf8("category_band_label"));

        formLayout->setWidget(7, QFormLayout::LabelRole, category_band_label);

        category_band_line_edit = new QLineEdit(ExportCabrillo);
        category_band_line_edit->setObjectName(QString::fromUtf8("category_band_line_edit"));
        category_band_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, category_band_line_edit);

        claimed_label = new QLabel(ExportCabrillo);
        claimed_label->setObjectName(QString::fromUtf8("claimed_label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, claimed_label);

        claimed_line_edit = new QLineEdit(ExportCabrillo);
        claimed_line_edit->setObjectName(QString::fromUtf8("claimed_line_edit"));
        claimed_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, claimed_line_edit);

        operators_label = new QLabel(ExportCabrillo);
        operators_label->setObjectName(QString::fromUtf8("operators_label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, operators_label);

        operators_line_edit = new QLineEdit(ExportCabrillo);
        operators_line_edit->setObjectName(QString::fromUtf8("operators_line_edit"));
        operators_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(9, QFormLayout::FieldRole, operators_line_edit);

        club_label = new QLabel(ExportCabrillo);
        club_label->setObjectName(QString::fromUtf8("club_label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, club_label);

        club_line_edit = new QLineEdit(ExportCabrillo);
        club_line_edit->setObjectName(QString::fromUtf8("club_line_edit"));
        club_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(10, QFormLayout::FieldRole, club_line_edit);

        name_label = new QLabel(ExportCabrillo);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        formLayout->setWidget(11, QFormLayout::LabelRole, name_label);

        name_line_edit = new QLineEdit(ExportCabrillo);
        name_line_edit->setObjectName(QString::fromUtf8("name_line_edit"));
        name_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(11, QFormLayout::FieldRole, name_line_edit);

        addr_1_label = new QLabel(ExportCabrillo);
        addr_1_label->setObjectName(QString::fromUtf8("addr_1_label"));

        formLayout->setWidget(12, QFormLayout::LabelRole, addr_1_label);

        addr_1_line_edit = new QLineEdit(ExportCabrillo);
        addr_1_line_edit->setObjectName(QString::fromUtf8("addr_1_line_edit"));
        addr_1_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(12, QFormLayout::FieldRole, addr_1_line_edit);

        addr_2_label = new QLabel(ExportCabrillo);
        addr_2_label->setObjectName(QString::fromUtf8("addr_2_label"));

        formLayout->setWidget(13, QFormLayout::LabelRole, addr_2_label);

        addr_2_line_edit = new QLineEdit(ExportCabrillo);
        addr_2_line_edit->setObjectName(QString::fromUtf8("addr_2_line_edit"));
        addr_2_line_edit->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(13, QFormLayout::FieldRole, addr_2_line_edit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ExportCabrillo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        location_label->setBuddy(location_line_edit);
        contest_label->setBuddy(contest_line_edit);
        call_label->setBuddy(call_line_edit);
        category_op_label->setBuddy(category_op_line_edit);
        category_xmtr_label->setBuddy(category_xmtr_line_edit);
        category_pwr_label->setBuddy(category_pwr_line_edit);
        category_assisted_label->setBuddy(category_assisted_line_edit);
        category_band_label->setBuddy(category_band_line_edit);
        claimed_label->setBuddy(claimed_line_edit);
        operators_label->setBuddy(operators_line_edit);
        club_label->setBuddy(club_line_edit);
        name_label->setBuddy(name_line_edit);
        addr_1_label->setBuddy(addr_1_line_edit);
        addr_2_label->setBuddy(addr_2_line_edit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ExportCabrillo);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportCabrillo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportCabrillo, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportCabrillo);
    } // setupUi

    void retranslateUi(QDialog *ExportCabrillo)
    {
        ExportCabrillo->setWindowTitle(QCoreApplication::translate("ExportCabrillo", "Dialog", nullptr));
        location_label->setText(QCoreApplication::translate("ExportCabrillo", "Location:", nullptr));
        location_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "SNJ", nullptr));
        contest_label->setText(QCoreApplication::translate("ExportCabrillo", "Contest:", nullptr));
        contest_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "ARRL-RTTY", nullptr));
        call_label->setText(QCoreApplication::translate("ExportCabrillo", "Callsign:", nullptr));
        call_line_edit->setText(QString());
        category_op_label->setText(QCoreApplication::translate("ExportCabrillo", "Category-Operator: ", nullptr));
        category_op_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "SINGLE-OP", nullptr));
        category_xmtr_label->setText(QCoreApplication::translate("ExportCabrillo", "Category-Transmitter:", nullptr));
        category_xmtr_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "ONE", nullptr));
        category_pwr_label->setText(QCoreApplication::translate("ExportCabrillo", "Category-Power:", nullptr));
        category_pwr_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "LOW", nullptr));
        category_assisted_label->setText(QCoreApplication::translate("ExportCabrillo", "Category-Assisted:", nullptr));
        category_assisted_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "NON-ASSISTED", nullptr));
        category_band_label->setText(QCoreApplication::translate("ExportCabrillo", "Category-Band:", nullptr));
        category_band_line_edit->setText(QCoreApplication::translate("ExportCabrillo", "ALL", nullptr));
        claimed_label->setText(QCoreApplication::translate("ExportCabrillo", "Claimed-Score:", nullptr));
        claimed_line_edit->setText(QString());
        operators_label->setText(QCoreApplication::translate("ExportCabrillo", "Operators:", nullptr));
        operators_line_edit->setText(QString());
        club_label->setText(QCoreApplication::translate("ExportCabrillo", "Club:", nullptr));
        name_label->setText(QCoreApplication::translate("ExportCabrillo", "Name:", nullptr));
        name_line_edit->setText(QString());
        addr_1_label->setText(QCoreApplication::translate("ExportCabrillo", "Address:", nullptr));
        addr_2_label->setText(QCoreApplication::translate("ExportCabrillo", "Address:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExportCabrillo: public Ui_ExportCabrillo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTCABRILLO_H
