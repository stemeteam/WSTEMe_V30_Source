/********************************************************************************
** Form generated from reading UI file 'sensor_sen0104.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0104_H
#define UI_SENSOR_SEN0104_H

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

class Ui_Sensor_SEN0104
{
public:
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_ChartZoom;
    QTabWidget *tabWidget;
    QWidget *tab_Infor_3;
    QLCDNumber *lcdNumber_Value;
    QPushButton *pushButton_2;
    QSpinBox *spinBox_setSample;
    QPushButton *pushButton_getSamples;
    QLabel *label_sampleInfo;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_15;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_ValueMax;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMin;
    QComboBox *comboBox_Value_Unit;
    QCheckBox *checkBox_setMathAvg;
    QPushButton *pushButton_SetZero;
    QWidget *tab_5;
    QWidget *verticalLayoutWidget_13;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_Name;
    QLabel *label_Address;
    QLabel *label_SerialNumber;
    QWidget *verticalLayoutWidget_14;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *verticalLayoutWidget_15;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_Description;
    QWidget *tab_7;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *pushButton_SetSampleTime;
    QSpinBox *spinBox_SampleTime;
    QFrame *line_3;
    QPushButton *pushButton_Calib;
    QLabel *label_28;
    QLabel *label_calibInfo;
    QFrame *line;

    void setupUi(QWidget *Sensor_SEN0104)
    {
        if (Sensor_SEN0104->objectName().isEmpty())
            Sensor_SEN0104->setObjectName(QString::fromUtf8("Sensor_SEN0104"));
        Sensor_SEN0104->resize(600, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/PSR0104_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0104->setWindowIcon(icon);
        Sensor_SEN0104->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        pushButton_Exit = new QPushButton(Sensor_SEN0104);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(320, 249, 271, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton_Exit->setFont(font);
        pushButton_Exit->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_ChartZoom = new QPushButton(Sensor_SEN0104);
        pushButton_ChartZoom->setObjectName(QString::fromUtf8("pushButton_ChartZoom"));
        pushButton_ChartZoom->setGeometry(QRect(11, 250, 281, 41));
        pushButton_ChartZoom->setFont(font);
        pushButton_ChartZoom->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget = new QTabWidget(Sensor_SEN0104);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-2, 0, 607, 238));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        tabWidget->setElideMode(Qt::ElideNone);
        tab_Infor_3 = new QWidget();
        tab_Infor_3->setObjectName(QString::fromUtf8("tab_Infor_3"));
        lcdNumber_Value = new QLCDNumber(tab_Infor_3);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(10, 10, 281, 71));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 70, 102);\n"
"color: rgb(0, 243, 178);\n"
""));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(10);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        pushButton_2 = new QPushButton(tab_Infor_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 120, 32, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(32, 32));
        spinBox_setSample = new QSpinBox(tab_Infor_3);
        spinBox_setSample->setObjectName(QString::fromUtf8("spinBox_setSample"));
        spinBox_setSample->setGeometry(QRect(340, 130, 128, 51));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        spinBox_setSample->setFont(font1);
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
        pushButton_getSamples = new QPushButton(tab_Infor_3);
        pushButton_getSamples->setObjectName(QString::fromUtf8("pushButton_getSamples"));
        pushButton_getSamples->setGeometry(QRect(480, 130, 101, 51));
        pushButton_getSamples->setFont(font);
        pushButton_getSamples->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_sampleInfo = new QLabel(tab_Infor_3);
        label_sampleInfo->setObjectName(QString::fromUtf8("label_sampleInfo"));
        label_sampleInfo->setGeometry(QRect(320, 0, 261, 26));
        label_sampleInfo->setFont(font1);
        label_sampleInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalLayoutWidget_11 = new QWidget(tab_Infor_3);
        verticalLayoutWidget_11->setObjectName(QString::fromUtf8("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(340, 30, 128, 92));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_11);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_11->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_11);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_11->addWidget(label_12);

        label_15 = new QLabel(verticalLayoutWidget_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_11->addWidget(label_15);

        verticalLayoutWidget_12 = new QWidget(tab_Infor_3);
        verticalLayoutWidget_12->setObjectName(QString::fromUtf8("verticalLayoutWidget_12"));
        verticalLayoutWidget_12->setGeometry(QRect(480, 30, 101, 92));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget_12);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_12);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_ValueMax->setFont(font2);
        label_ValueMax->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_12->addWidget(label_ValueMax);

        label_ValueAvg = new QLabel(verticalLayoutWidget_12);
        label_ValueAvg->setObjectName(QString::fromUtf8("label_ValueAvg"));
        label_ValueAvg->setFont(font2);
        label_ValueAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_12->addWidget(label_ValueAvg);

        label_ValueMin = new QLabel(verticalLayoutWidget_12);
        label_ValueMin->setObjectName(QString::fromUtf8("label_ValueMin"));
        label_ValueMin->setFont(font2);
        label_ValueMin->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        verticalLayout_12->addWidget(label_ValueMin);

        comboBox_Value_Unit = new QComboBox(tab_Infor_3);
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->addItem(QString());
        comboBox_Value_Unit->setObjectName(QString::fromUtf8("comboBox_Value_Unit"));
        comboBox_Value_Unit->setGeometry(QRect(43, 120, 248, 32));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        comboBox_Value_Unit->setFont(font3);
        comboBox_Value_Unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_Value_Unit->setAutoFillBackground(false);
        comboBox_Value_Unit->setStyleSheet(QString::fromUtf8(""));
        comboBox_Value_Unit->setEditable(false);
        checkBox_setMathAvg = new QCheckBox(tab_Infor_3);
        checkBox_setMathAvg->setObjectName(QString::fromUtf8("checkBox_setMathAvg"));
        checkBox_setMathAvg->setGeometry(QRect(10, 86, 281, 27));
        checkBox_setMathAvg->setFont(font3);
        checkBox_setMathAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetZero = new QPushButton(tab_Infor_3);
        pushButton_SetZero->setObjectName(QString::fromUtf8("pushButton_SetZero"));
        pushButton_SetZero->setGeometry(QRect(10, 160, 281, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(false);
        pushButton_SetZero->setFont(font4);
        pushButton_SetZero->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tab_Infor_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayoutWidget_13 = new QWidget(tab_5);
        verticalLayoutWidget_13->setObjectName(QString::fromUtf8("verticalLayoutWidget_13"));
        verticalLayoutWidget_13->setGeometry(QRect(150, 10, 291, 101));
        verticalLayout_13 = new QVBoxLayout(verticalLayoutWidget_13);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_13);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        QFont font5;
        font5.setPointSize(10);
        label_Name->setFont(font5);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_13->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_13);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setFont(font5);
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_13->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_13);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setFont(font5);
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_13->addWidget(label_SerialNumber);

        verticalLayoutWidget_14 = new QWidget(tab_5);
        verticalLayoutWidget_14->setObjectName(QString::fromUtf8("verticalLayoutWidget_14"));
        verticalLayoutWidget_14->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_14 = new QVBoxLayout(verticalLayoutWidget_14);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(verticalLayoutWidget_14);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_14->addWidget(label_16);

        label_17 = new QLabel(verticalLayoutWidget_14);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_14->addWidget(label_17);

        label_20 = new QLabel(verticalLayoutWidget_14);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_14->addWidget(label_20);

        label_21 = new QLabel(verticalLayoutWidget_14);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_14->addWidget(label_21);

        verticalLayoutWidget_15 = new QWidget(tab_5);
        verticalLayoutWidget_15->setObjectName(QString::fromUtf8("verticalLayoutWidget_15"));
        verticalLayoutWidget_15->setGeometry(QRect(150, 110, 291, 61));
        verticalLayout_15 = new QVBoxLayout(verticalLayoutWidget_15);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_15);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setFont(font5);
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_15->addWidget(label_Description);

        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        label_26 = new QLabel(tab_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(277, 40, 41, 22));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_27 = new QLabel(tab_7);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 40, 141, 22));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime = new QPushButton(tab_7);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(320, 20, 161, 61));
        pushButton_SetSampleTime->setFont(font);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_SampleTime = new QSpinBox(tab_7);
        spinBox_SampleTime->setObjectName(QString::fromUtf8("spinBox_SampleTime"));
        spinBox_SampleTime->setGeometry(QRect(160, 10, 111, 81));
        spinBox_SampleTime->setFont(font1);
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
        line_3 = new QFrame(tab_7);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 100, 541, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_Calib = new QPushButton(tab_7);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(320, 120, 161, 61));
        pushButton_Calib->setFont(font);
        pushButton_Calib->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_28 = new QLabel(tab_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 139, 231, 22));
        label_28->setFont(font1);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_calibInfo = new QLabel(tab_7);
        label_calibInfo->setObjectName(QString::fromUtf8("label_calibInfo"));
        label_calibInfo->setGeometry(QRect(30, 160, 271, 22));
        label_calibInfo->setFont(font3);
        label_calibInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        tabWidget->addTab(tab_7, QString());
        line = new QFrame(Sensor_SEN0104);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-2, 233, 605, 5));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 187, 154);"));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);

        retranslateUi(Sensor_SEN0104);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0104);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0104)
    {
        Sensor_SEN0104->setWindowTitle(QCoreApplication::translate("Sensor_SEN0104", "Form", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0104", "Tho\303\241t", nullptr));
        pushButton_ChartZoom->setText(QCoreApplication::translate("Sensor_SEN0104", "\304\220\341\273\223 th\341\273\213", nullptr));
        pushButton_2->setText(QString());
        pushButton_getSamples->setText(QCoreApplication::translate("Sensor_SEN0104", "B\341\272\257t \304\221\341\272\247u", nullptr));
        label_sampleInfo->setText(QCoreApplication::translate("Sensor_SEN0104", "C\303\241c tham s\341\273\221 c\306\241 b\341\272\243n", nullptr));
        label_11->setText(QCoreApplication::translate("Sensor_SEN0104", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t", nullptr));
        label_12->setText(QCoreApplication::translate("Sensor_SEN0104", "Gi\303\241 tr\341\273\213 trung b\303\254nh", nullptr));
        label_15->setText(QCoreApplication::translate("Sensor_SEN0104", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Sensor_SEN0104", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Sensor_SEN0104", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Sensor_SEN0104", "0", nullptr));
        comboBox_Value_Unit->setItemText(0, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Pa (1 Pa = N/m2)", nullptr));
        comboBox_Value_Unit->setItemText(1, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo hPa (1 hPa = 100 Pa)", nullptr));
        comboBox_Value_Unit->setItemText(2, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo KPa (1 KPa = 1000 Pa)", nullptr));
        comboBox_Value_Unit->setItemText(3, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Atm (1 Atm = 101325 Pa)", nullptr));
        comboBox_Value_Unit->setItemText(4, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Bar (1 Bar = 100000 Pa)", nullptr));
        comboBox_Value_Unit->setItemText(5, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Baria (1 Baria = 0.1 Pa)", nullptr));
        comboBox_Value_Unit->setItemText(6, QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Torr (1 Torr = 133.322Pa)", nullptr));

        comboBox_Value_Unit->setCurrentText(QCoreApplication::translate("Sensor_SEN0104", "\304\220o theo Pa (1 Pa = N/m2)", nullptr));
        checkBox_setMathAvg->setText(QCoreApplication::translate("Sensor_SEN0104", "S\341\273\255 d\341\273\245ng gi\303\241 tr\341\273\213 trung b\303\254nh c\341\273\231ng", nullptr));
        pushButton_SetZero->setText(QCoreApplication::translate("Sensor_SEN0104", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m 0 (Zero)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor_3), QCoreApplication::translate("Sensor_SEN0104", "            Hi\341\273\203n th\341\273\213            ", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_16->setText(QCoreApplication::translate("Sensor_SEN0104", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_17->setText(QCoreApplication::translate("Sensor_SEN0104", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_20->setText(QCoreApplication::translate("Sensor_SEN0104", "M\303\243 s\303\252-ri:", nullptr));
        label_21->setText(QCoreApplication::translate("Sensor_SEN0104", "M\303\264 t\341\272\243:", nullptr));
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Sensor_SEN0104", "            Thi\341\272\277t b\341\273\213            ", nullptr));
        label_26->setText(QCoreApplication::translate("Sensor_SEN0104", "(ms)", nullptr));
        label_27->setText(QCoreApplication::translate("Sensor_SEN0104", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Sensor_SEN0104", "C\303\240i \304\221\341\272\267t", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Sensor_SEN0104", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_28->setText(QCoreApplication::translate("Sensor_SEN0104", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213 :", nullptr));
        label_calibInfo->setText(QCoreApplication::translate("Sensor_SEN0104", "(ch\306\260a hi\341\273\207u chu\341\272\251n)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Sensor_SEN0104", "           C\303\240i \304\221\341\272\267t            ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0104: public Ui_Sensor_SEN0104 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0104_H
