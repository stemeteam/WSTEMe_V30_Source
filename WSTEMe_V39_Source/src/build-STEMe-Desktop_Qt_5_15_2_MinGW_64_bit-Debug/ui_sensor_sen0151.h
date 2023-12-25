/********************************************************************************
** Form generated from reading UI file 'sensor_sen0151.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0151_H
#define UI_SENSOR_SEN0151_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor_SEN0151
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_Infor_4;
    QLCDNumber *lcdNumber_Value;
    QPushButton *pushButton_3;
    QComboBox *comboBox_Temp_Unit;
    QSpinBox *spinBox_setSample;
    QPushButton *pushButton_getSamples;
    QLabel *label_sampleInfo;
    QWidget *verticalLayoutWidget_16;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_22;
    QLabel *label_29;
    QLabel *label_30;
    QWidget *verticalLayoutWidget_17;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_ValueMax;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMin;
    QCheckBox *checkBox_setMathAvg;
    QPushButton *pushButton_SetZero;
    QWidget *tab_8;
    QWidget *verticalLayoutWidget_18;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_Name;
    QLabel *label_Address;
    QLabel *label_SerialNumber;
    QWidget *verticalLayoutWidget_19;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QWidget *verticalLayoutWidget_20;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_Description;
    QWidget *tab_9;
    QLabel *label_35;
    QLabel *label_36;
    QPushButton *pushButton_SetSampleTime;
    QSpinBox *spinBox_SampleTime;
    QFrame *line_4;
    QPushButton *pushButton_Calib;
    QLabel *label_37;
    QLabel *label_calibInfo;
    QFrame *line;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_ChartZoom;

    void setupUi(QWidget *Sensor_SEN0151)
    {
        if (Sensor_SEN0151->objectName().isEmpty())
            Sensor_SEN0151->setObjectName(QString::fromUtf8("Sensor_SEN0151"));
        Sensor_SEN0151->resize(600, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/CUR0151_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0151->setWindowIcon(icon);
        Sensor_SEN0151->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        tabWidget = new QTabWidget(Sensor_SEN0151);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-2, 0, 607, 238));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        tabWidget->setElideMode(Qt::ElideNone);
        tab_Infor_4 = new QWidget();
        tab_Infor_4->setObjectName(QString::fromUtf8("tab_Infor_4"));
        lcdNumber_Value = new QLCDNumber(tab_Infor_4);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(10, 10, 281, 71));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 70, 102);\n"
"color: rgb(255, 0, 0);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        pushButton_3 = new QPushButton(tab_Infor_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 110, 32, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(32, 32));
        comboBox_Temp_Unit = new QComboBox(tab_Infor_4);
        comboBox_Temp_Unit->addItem(QString());
        comboBox_Temp_Unit->addItem(QString());
        comboBox_Temp_Unit->setObjectName(QString::fromUtf8("comboBox_Temp_Unit"));
        comboBox_Temp_Unit->setGeometry(QRect(43, 110, 248, 32));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        comboBox_Temp_Unit->setFont(font1);
        comboBox_Temp_Unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_Temp_Unit->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);\n"
"color: rgb(255, 255, 255);"));
        comboBox_Temp_Unit->setEditable(false);
        spinBox_setSample = new QSpinBox(tab_Infor_4);
        spinBox_setSample->setObjectName(QString::fromUtf8("spinBox_setSample"));
        spinBox_setSample->setGeometry(QRect(340, 130, 128, 51));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        spinBox_setSample->setFont(font2);
        spinBox_setSample->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QSpinBox::up-button\n"
"{\n"
"    min-width:40px;\n"
"    min-height: 20px;\n"
"}\n"
"QSpinBox::down-button\n"
"{\n"
"    min-width: 40px;\n"
"    min-height: 20px;\n"
"}\n"
""));
        spinBox_setSample->setMinimum(10);
        spinBox_setSample->setMaximum(9999999);
        spinBox_setSample->setValue(100);
        pushButton_getSamples = new QPushButton(tab_Infor_4);
        pushButton_getSamples->setObjectName(QString::fromUtf8("pushButton_getSamples"));
        pushButton_getSamples->setGeometry(QRect(480, 130, 101, 51));
        pushButton_getSamples->setFont(font);
        pushButton_getSamples->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_sampleInfo = new QLabel(tab_Infor_4);
        label_sampleInfo->setObjectName(QString::fromUtf8("label_sampleInfo"));
        label_sampleInfo->setGeometry(QRect(320, 0, 261, 26));
        label_sampleInfo->setFont(font2);
        label_sampleInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalLayoutWidget_16 = new QWidget(tab_Infor_4);
        verticalLayoutWidget_16->setObjectName(QString::fromUtf8("verticalLayoutWidget_16"));
        verticalLayoutWidget_16->setGeometry(QRect(340, 30, 128, 92));
        verticalLayout_16 = new QVBoxLayout(verticalLayoutWidget_16);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(verticalLayoutWidget_16);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_16->addWidget(label_22);

        label_29 = new QLabel(verticalLayoutWidget_16);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_16->addWidget(label_29);

        label_30 = new QLabel(verticalLayoutWidget_16);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_16->addWidget(label_30);

        verticalLayoutWidget_17 = new QWidget(tab_Infor_4);
        verticalLayoutWidget_17->setObjectName(QString::fromUtf8("verticalLayoutWidget_17"));
        verticalLayoutWidget_17->setGeometry(QRect(480, 30, 101, 92));
        verticalLayout_17 = new QVBoxLayout(verticalLayoutWidget_17);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_17);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_ValueMax->setFont(font3);
        label_ValueMax->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_17->addWidget(label_ValueMax);

        label_ValueAvg = new QLabel(verticalLayoutWidget_17);
        label_ValueAvg->setObjectName(QString::fromUtf8("label_ValueAvg"));
        label_ValueAvg->setFont(font3);
        label_ValueAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_17->addWidget(label_ValueAvg);

        label_ValueMin = new QLabel(verticalLayoutWidget_17);
        label_ValueMin->setObjectName(QString::fromUtf8("label_ValueMin"));
        label_ValueMin->setFont(font3);
        label_ValueMin->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        verticalLayout_17->addWidget(label_ValueMin);

        checkBox_setMathAvg = new QCheckBox(tab_Infor_4);
        checkBox_setMathAvg->setObjectName(QString::fromUtf8("checkBox_setMathAvg"));
        checkBox_setMathAvg->setGeometry(QRect(10, 82, 281, 27));
        checkBox_setMathAvg->setFont(font2);
        checkBox_setMathAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetZero = new QPushButton(tab_Infor_4);
        pushButton_SetZero->setObjectName(QString::fromUtf8("pushButton_SetZero"));
        pushButton_SetZero->setGeometry(QRect(10, 150, 281, 41));
        pushButton_SetZero->setFont(font);
        pushButton_SetZero->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tab_Infor_4, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        verticalLayoutWidget_18 = new QWidget(tab_8);
        verticalLayoutWidget_18->setObjectName(QString::fromUtf8("verticalLayoutWidget_18"));
        verticalLayoutWidget_18->setGeometry(QRect(150, 10, 291, 101));
        verticalLayout_18 = new QVBoxLayout(verticalLayoutWidget_18);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_18);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        QFont font4;
        font4.setPointSize(10);
        label_Name->setFont(font4);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_18->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_18);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setFont(font4);
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_18->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_18);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setFont(font4);
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_18->addWidget(label_SerialNumber);

        verticalLayoutWidget_19 = new QWidget(tab_8);
        verticalLayoutWidget_19->setObjectName(QString::fromUtf8("verticalLayoutWidget_19"));
        verticalLayoutWidget_19->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_19 = new QVBoxLayout(verticalLayoutWidget_19);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(verticalLayoutWidget_19);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_19->addWidget(label_31);

        label_32 = new QLabel(verticalLayoutWidget_19);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font2);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_19->addWidget(label_32);

        label_33 = new QLabel(verticalLayoutWidget_19);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_19->addWidget(label_33);

        label_34 = new QLabel(verticalLayoutWidget_19);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_19->addWidget(label_34);

        verticalLayoutWidget_20 = new QWidget(tab_8);
        verticalLayoutWidget_20->setObjectName(QString::fromUtf8("verticalLayoutWidget_20"));
        verticalLayoutWidget_20->setGeometry(QRect(150, 110, 291, 61));
        verticalLayout_20 = new QVBoxLayout(verticalLayoutWidget_20);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_20);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setFont(font4);
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_20->addWidget(label_Description);

        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        label_35 = new QLabel(tab_9);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(277, 40, 41, 22));
        label_35->setFont(font2);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_36 = new QLabel(tab_9);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(20, 40, 141, 22));
        label_36->setFont(font2);
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime = new QPushButton(tab_9);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(320, 20, 161, 61));
        pushButton_SetSampleTime->setFont(font);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_SampleTime = new QSpinBox(tab_9);
        spinBox_SampleTime->setObjectName(QString::fromUtf8("spinBox_SampleTime"));
        spinBox_SampleTime->setGeometry(QRect(160, 10, 111, 81));
        spinBox_SampleTime->setFont(font2);
        spinBox_SampleTime->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QSpinBox::up-button\n"
"{\n"
"    min-width:40px;\n"
"    min-height: 20px;\n"
"}\n"
"QSpinBox::down-button\n"
"{\n"
"    min-width: 40px;\n"
"    min-height: 20px;\n"
"}\n"
""));
        spinBox_SampleTime->setMinimum(10);
        spinBox_SampleTime->setMaximum(9999999);
        spinBox_SampleTime->setValue(100);
        line_4 = new QFrame(tab_9);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 100, 581, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_Calib = new QPushButton(tab_9);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(320, 120, 161, 61));
        pushButton_Calib->setFont(font);
        pushButton_Calib->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_37 = new QLabel(tab_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(20, 139, 231, 22));
        label_37->setFont(font2);
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_calibInfo = new QLabel(tab_9);
        label_calibInfo->setObjectName(QString::fromUtf8("label_calibInfo"));
        label_calibInfo->setGeometry(QRect(40, 160, 271, 22));
        label_calibInfo->setFont(font1);
        label_calibInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        tabWidget->addTab(tab_9, QString());
        line = new QFrame(Sensor_SEN0151);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-2, 233, 605, 5));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 64, 56);"));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);
        pushButton_Exit = new QPushButton(Sensor_SEN0151);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(320, 250, 271, 41));
        pushButton_Exit->setFont(font);
        pushButton_Exit->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_ChartZoom = new QPushButton(Sensor_SEN0151);
        pushButton_ChartZoom->setObjectName(QString::fromUtf8("pushButton_ChartZoom"));
        pushButton_ChartZoom->setGeometry(QRect(11, 250, 281, 41));
        pushButton_ChartZoom->setFont(font);
        pushButton_ChartZoom->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        retranslateUi(Sensor_SEN0151);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0151);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0151)
    {
        Sensor_SEN0151->setWindowTitle(QCoreApplication::translate("Sensor_SEN0151", "Form", nullptr));
        pushButton_3->setText(QString());
        comboBox_Temp_Unit->setItemText(0, QCoreApplication::translate("Sensor_SEN0151", "\304\220o theo Amp (A)", nullptr));
        comboBox_Temp_Unit->setItemText(1, QCoreApplication::translate("Sensor_SEN0151", "\304\220o theo milliAmp (mA)", nullptr));

        pushButton_getSamples->setText(QCoreApplication::translate("Sensor_SEN0151", "B\341\272\257t \304\221\341\272\247u", nullptr));
        label_sampleInfo->setText(QCoreApplication::translate("Sensor_SEN0151", "C\303\241c tham s\341\273\221 c\306\241 b\341\272\243n", nullptr));
        label_22->setText(QCoreApplication::translate("Sensor_SEN0151", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t", nullptr));
        label_29->setText(QCoreApplication::translate("Sensor_SEN0151", "Gi\303\241 tr\341\273\213 trung b\303\254nh", nullptr));
        label_30->setText(QCoreApplication::translate("Sensor_SEN0151", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Sensor_SEN0151", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Sensor_SEN0151", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Sensor_SEN0151", "0", nullptr));
        checkBox_setMathAvg->setText(QCoreApplication::translate("Sensor_SEN0151", "S\341\273\255 d\341\273\245ng gi\303\241 tr\341\273\213 trung b\303\254nh c\341\273\231ng", nullptr));
        pushButton_SetZero->setText(QCoreApplication::translate("Sensor_SEN0151", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m 0 (Zero)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor_4), QCoreApplication::translate("Sensor_SEN0151", "            Hi\341\273\203n th\341\273\213            ", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_31->setText(QCoreApplication::translate("Sensor_SEN0151", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_32->setText(QCoreApplication::translate("Sensor_SEN0151", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_33->setText(QCoreApplication::translate("Sensor_SEN0151", "M\303\243 s\303\252-ri:", nullptr));
        label_34->setText(QCoreApplication::translate("Sensor_SEN0151", "M\303\264 t\341\272\243:", nullptr));
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("Sensor_SEN0151", "            Thi\341\272\277t b\341\273\213            ", nullptr));
        label_35->setText(QCoreApplication::translate("Sensor_SEN0151", "(ms)", nullptr));
        label_36->setText(QCoreApplication::translate("Sensor_SEN0151", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Sensor_SEN0151", "C\303\240i \304\221\341\272\267t", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Sensor_SEN0151", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_37->setText(QCoreApplication::translate("Sensor_SEN0151", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213 :", nullptr));
        label_calibInfo->setText(QCoreApplication::translate("Sensor_SEN0151", "(ch\306\260a hi\341\273\207u chu\341\272\251n)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("Sensor_SEN0151", "           C\303\240i \304\221\341\272\267t            ", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0151", "Tho\303\241t", nullptr));
        pushButton_ChartZoom->setText(QCoreApplication::translate("Sensor_SEN0151", "\304\220\341\273\223 th\341\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0151: public Ui_Sensor_SEN0151 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0151_H
