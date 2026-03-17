/********************************************************************************
** Form generated from reading UI file 'astro.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTRO_H
#define UI_ASTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Astro
{
public:
    QGridLayout *gridLayout;
    QWidget *doppler_widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbFullTrack;
    QRadioButton *rbOwnEcho;
    QRadioButton *rbConstFreqOnMoon;
    QRadioButton *rbOnDxEcho;
    QRadioButton *rbCallDx;
    QRadioButton *rbNoDoppler;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *sked_tx_frequency_label;
    QLabel *sked_frequency_label;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *sbRIT;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbDither;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *sbibShift;
    QCheckBox *cbEnableShift;
    QVBoxLayout *verticalLayout_3;
    QLabel *text_label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbDopplerTracking;

    void setupUi(QWidget *Astro)
    {
        if (Astro->objectName().isEmpty())
            Astro->setObjectName(QString::fromUtf8("Astro"));
        Astro->resize(356, 446);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Astro->sizePolicy().hasHeightForWidth());
        Astro->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Astro);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        doppler_widget = new QWidget(Astro);
        doppler_widget->setObjectName(QString::fromUtf8("doppler_widget"));
        doppler_widget->setStyleSheet(QString::fromUtf8("* {\n"
"	font-weight: normal;\n"
"}"));
        verticalLayout = new QVBoxLayout(doppler_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(doppler_widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rbFullTrack = new QRadioButton(groupBox);
        rbFullTrack->setObjectName(QString::fromUtf8("rbFullTrack"));
        rbFullTrack->setChecked(true);

        verticalLayout_2->addWidget(rbFullTrack);

        rbOwnEcho = new QRadioButton(groupBox);
        rbOwnEcho->setObjectName(QString::fromUtf8("rbOwnEcho"));

        verticalLayout_2->addWidget(rbOwnEcho);

        rbConstFreqOnMoon = new QRadioButton(groupBox);
        rbConstFreqOnMoon->setObjectName(QString::fromUtf8("rbConstFreqOnMoon"));
        rbConstFreqOnMoon->setChecked(false);

        verticalLayout_2->addWidget(rbConstFreqOnMoon);

        rbOnDxEcho = new QRadioButton(groupBox);
        rbOnDxEcho->setObjectName(QString::fromUtf8("rbOnDxEcho"));
        rbOnDxEcho->setChecked(false);

        verticalLayout_2->addWidget(rbOnDxEcho);

        rbCallDx = new QRadioButton(groupBox);
        rbCallDx->setObjectName(QString::fromUtf8("rbCallDx"));
        rbCallDx->setChecked(false);

        verticalLayout_2->addWidget(rbCallDx);

        rbNoDoppler = new QRadioButton(groupBox);
        rbNoDoppler->setObjectName(QString::fromUtf8("rbNoDoppler"));
        rbNoDoppler->setChecked(false);

        verticalLayout_2->addWidget(rbNoDoppler);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(doppler_widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sked_tx_frequency_label = new QLabel(groupBox_3);
        sked_tx_frequency_label->setObjectName(QString::fromUtf8("sked_tx_frequency_label"));
        sked_tx_frequency_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        sked_tx_frequency_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(sked_tx_frequency_label, 1, 1, 1, 1);

        sked_frequency_label = new QLabel(groupBox_3);
        sked_frequency_label->setObjectName(QString::fromUtf8("sked_frequency_label"));
        sked_frequency_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        sked_frequency_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(sked_frequency_label, 0, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 2);

        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(doppler_widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 50));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sbRIT = new QSpinBox(groupBox_2);
        sbRIT->setObjectName(QString::fromUtf8("sbRIT"));
        sbRIT->setEnabled(false);
        sbRIT->setAlignment(Qt::AlignCenter);
        sbRIT->setMinimum(-20000);
        sbRIT->setMaximum(20000);
        sbRIT->setSingleStep(100);

        horizontalLayout_2->addWidget(sbRIT);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cbDither = new QCheckBox(groupBox_2);
        cbDither->setObjectName(QString::fromUtf8("cbDither"));

        horizontalLayout_2->addWidget(cbDither);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(doppler_widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sbibShift = new QSpinBox(groupBox_4);
        sbibShift->setObjectName(QString::fromUtf8("sbibShift"));
        sbibShift->setMinimum(-30);
        sbibShift->setMaximum(30);
        sbibShift->setSingleStep(1);
        sbibShift->setValue(0);

        horizontalLayout_4->addWidget(sbibShift);

        cbEnableShift = new QCheckBox(groupBox_4);
        cbEnableShift->setObjectName(QString::fromUtf8("cbEnableShift"));
        cbEnableShift->setEnabled(true);

        horizontalLayout_4->addWidget(cbEnableShift);


        verticalLayout->addWidget(groupBox_4);


        gridLayout->addWidget(doppler_widget, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        text_label = new QLabel(Astro);
        text_label->setObjectName(QString::fromUtf8("text_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text_label->sizePolicy().hasHeightForWidth());
        text_label->setSizePolicy(sizePolicy1);
        text_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        text_label->setFrameShadow(QFrame::Sunken);
        text_label->setAlignment(Qt::AlignCenter);
        text_label->setMargin(6);

        verticalLayout_3->addWidget(text_label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbDopplerTracking = new QCheckBox(Astro);
        cbDopplerTracking->setObjectName(QString::fromUtf8("cbDopplerTracking"));
        cbDopplerTracking->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(cbDopplerTracking);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Astro);

        QMetaObject::connectSlotsByName(Astro);
    } // setupUi

    void retranslateUi(QWidget *Astro)
    {
        groupBox->setTitle(QCoreApplication::translate("Astro", "Doppler tracking", nullptr));
#if QT_CONFIG(tooltip)
        rbFullTrack->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>One station does all Doppler shift correction, their QSO partner receives and transmits on the sked frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbFullTrack->setText(QCoreApplication::translate("Astro", "Full Doppler to DX Grid", nullptr));
#if QT_CONFIG(tooltip)
        rbOwnEcho->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Transmit takes place on sked frequency and receive frequency is  corrected for own echoes. </p><p>This mode can be used for calling CQ, or when using Echo mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbOwnEcho->setText(QCoreApplication::translate("Astro", "Own Echo", nullptr));
#if QT_CONFIG(tooltip)
        rbConstFreqOnMoon->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Both stations correct for Doppler shift such that they would be heard on the moon at the sked frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p><p>Use this option also for Echo mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbConstFreqOnMoon->setText(QCoreApplication::translate("Astro", "Constant frequency on Moon", nullptr));
#if QT_CONFIG(tooltip)
        rbOnDxEcho->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>DX station announces their TX Freq, which is entered as the Sked Freq. Correction applied to RX and TX so you appear on the DX's station's own echo Freq.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbOnDxEcho->setText(QCoreApplication::translate("Astro", "On DX Echo", nullptr));
#if QT_CONFIG(tooltip)
        rbCallDx->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Tune radio manually and select this mode to put your echo on the same frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCallDx->setText(QCoreApplication::translate("Astro", "Call DX", nullptr));
#if QT_CONFIG(tooltip)
        rbNoDoppler->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>No Doppler shift correction is applied. This may be used when the QSO partner does full Doppler correction to your grid square.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbNoDoppler->setText(QCoreApplication::translate("Astro", "None", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Astro", "Sked frequency", nullptr));
        sked_tx_frequency_label->setText(QCoreApplication::translate("Astro", "0", nullptr));
        sked_frequency_label->setText(QCoreApplication::translate("Astro", "0", nullptr));
        label->setText(QCoreApplication::translate("Astro", "Rx:", nullptr));
        label_2->setText(QCoreApplication::translate("Astro", "Tx:", nullptr));
        label_3->setText(QCoreApplication::translate("Astro", "<html><head/><body><p>Press and hold the CTRL key to adjust the sked frequency manually with the rig's VFO dial or enter frequency directly into the band entry field on the main window.</p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Astro", "Echo Mode", nullptr));
        sbRIT->setSuffix(QCoreApplication::translate("Astro", "  Hz", nullptr));
        sbRIT->setPrefix(QCoreApplication::translate("Astro", "RIT  ", nullptr));
        cbDither->setText(QCoreApplication::translate("Astro", "Dither", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Astro", "Tx Shift relative to Rx Sked Freq", nullptr));
#if QT_CONFIG(tooltip)
        sbibShift->setToolTip(QCoreApplication::translate("Astro", "Enter large offset", nullptr));
#endif // QT_CONFIG(tooltip)
        sbibShift->setSuffix(QCoreApplication::translate("Astro", " MHz", nullptr));
        sbibShift->setPrefix(QCoreApplication::translate("Astro", "Shift ", nullptr));
        cbEnableShift->setText(QCoreApplication::translate("Astro", "Enable", nullptr));
        text_label->setText(QCoreApplication::translate("Astro", "Astro Data", nullptr));
        cbDopplerTracking->setText(QCoreApplication::translate("Astro", "Doppler tracking", nullptr));
        (void)Astro;
    } // retranslateUi

};

namespace Ui {
    class Astro: public Ui_Astro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTRO_H
