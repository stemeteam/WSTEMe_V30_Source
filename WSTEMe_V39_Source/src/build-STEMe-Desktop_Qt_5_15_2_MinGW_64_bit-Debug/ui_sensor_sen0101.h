/********************************************************************************
** Form generated from reading UI file 'sensor_sen0101.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0101_H
#define UI_SENSOR_SEN0101_H

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

class Ui_Sensor_SEN0101
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_Infor_2;
    QLCDNumber *lcdNumber_Value;
    QPushButton *pushButton;
    QComboBox *comboBox_Temp_Unit;
    QSpinBox *spinBox_setSample;
    QPushButton *pushButton_getSamples;
    QLabel *label_sampleInfo;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_ValueMax;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMin;
    QCheckBox *checkBox_setMathAvg;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_Name;
    QLabel *label_Address;
    QLabel *label_SerialNumber;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_19;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_Description;
    QWidget *tab_6;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *pushButton_SetSampleTime;
    QSpinBox *spinBox_SampleTime;
    QFrame *line_2;
    QPushButton *pushButton_Calib;
    QLabel *label_25;
    QLabel *label_calibInfo;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_ChartZoom;
    QFrame *line;

    void setupUi(QWidget *Sensor_SEN0101)
    {
        if (Sensor_SEN0101->objectName().isEmpty())
            Sensor_SEN0101->setObjectName(QString::fromUtf8("Sensor_SEN0101"));
        Sensor_SEN0101->resize(600, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Temperature_icon_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0101->setWindowIcon(icon);
        Sensor_SEN0101->setAutoFillBackground(false);
        Sensor_SEN0101->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        tabWidget = new QTabWidget(Sensor_SEN0101);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-2, 0, 606, 238));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);"));
        tabWidget->setElideMode(Qt::ElideNone);
        tab_Infor_2 = new QWidget();
        tab_Infor_2->setObjectName(QString::fromUtf8("tab_Infor_2"));
        lcdNumber_Value = new QLCDNumber(tab_Infor_2);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(10, 10, 281, 71));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 0, 0);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        pushButton = new QPushButton(tab_Infor_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 32, 32));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/Temperature_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(32, 32));
        comboBox_Temp_Unit = new QComboBox(tab_Infor_2);
        comboBox_Temp_Unit->addItem(QString());
        comboBox_Temp_Unit->addItem(QString());
        comboBox_Temp_Unit->addItem(QString());
        comboBox_Temp_Unit->setObjectName(QString::fromUtf8("comboBox_Temp_Unit"));
        comboBox_Temp_Unit->setGeometry(QRect(43, 120, 248, 32));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        comboBox_Temp_Unit->setFont(font1);
        comboBox_Temp_Unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_Temp_Unit->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 97, 109);\n"
"color: rgb(255, 255, 255);"));
        comboBox_Temp_Unit->setEditable(false);
        spinBox_setSample = new QSpinBox(tab_Infor_2);
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
        pushButton_getSamples = new QPushButton(tab_Infor_2);
        pushButton_getSamples->setObjectName(QString::fromUtf8("pushButton_getSamples"));
        pushButton_getSamples->setGeometry(QRect(480, 130, 101, 51));
        pushButton_getSamples->setFont(font);
        pushButton_getSamples->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_sampleInfo = new QLabel(tab_Infor_2);
        label_sampleInfo->setObjectName(QString::fromUtf8("label_sampleInfo"));
        label_sampleInfo->setGeometry(QRect(320, 0, 261, 26));
        label_sampleInfo->setFont(font2);
        label_sampleInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalLayoutWidget_6 = new QWidget(tab_Infor_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(340, 30, 128, 92));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_10);

        verticalLayoutWidget_7 = new QWidget(tab_Infor_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(480, 30, 101, 92));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_7);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_ValueMax->setFont(font3);
        label_ValueMax->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_7->addWidget(label_ValueMax);

        label_ValueAvg = new QLabel(verticalLayoutWidget_7);
        label_ValueAvg->setObjectName(QString::fromUtf8("label_ValueAvg"));
        label_ValueAvg->setFont(font3);
        label_ValueAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_7->addWidget(label_ValueAvg);

        label_ValueMin = new QLabel(verticalLayoutWidget_7);
        label_ValueMin->setObjectName(QString::fromUtf8("label_ValueMin"));
        label_ValueMin->setFont(font3);
        label_ValueMin->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        verticalLayout_7->addWidget(label_ValueMin);

        checkBox_setMathAvg = new QCheckBox(tab_Infor_2);
        checkBox_setMathAvg->setObjectName(QString::fromUtf8("checkBox_setMathAvg"));
        checkBox_setMathAvg->setGeometry(QRect(10, 86, 281, 27));
        checkBox_setMathAvg->setFont(font2);
        checkBox_setMathAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_Infor_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayoutWidget_8 = new QWidget(tab_4);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(150, 10, 291, 101));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_8);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        QFont font4;
        font4.setPointSize(10);
        label_Name->setFont(font4);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_8);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setFont(font4);
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_8);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setFont(font4);
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_SerialNumber);

        verticalLayoutWidget_9 = new QWidget(tab_4);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_14);

        label_18 = new QLabel(verticalLayoutWidget_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_19);

        verticalLayoutWidget_10 = new QWidget(tab_4);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(150, 110, 291, 61));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_10);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setFont(font4);
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_10->addWidget(label_Description);

        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(277, 40, 41, 22));
        label_23->setFont(font2);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 40, 141, 22));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime = new QPushButton(tab_6);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(320, 20, 161, 61));
        pushButton_SetSampleTime->setFont(font);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_SampleTime = new QSpinBox(tab_6);
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
        line_2 = new QFrame(tab_6);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 100, 541, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_Calib = new QPushButton(tab_6);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(320, 120, 161, 61));
        pushButton_Calib->setFont(font);
        pushButton_Calib->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_25 = new QLabel(tab_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 139, 231, 22));
        label_25->setFont(font2);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_calibInfo = new QLabel(tab_6);
        label_calibInfo->setObjectName(QString::fromUtf8("label_calibInfo"));
        label_calibInfo->setGeometry(QRect(40, 160, 271, 22));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setItalic(true);
        label_calibInfo->setFont(font5);
        label_calibInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        tabWidget->addTab(tab_6, QString());
        pushButton_Exit = new QPushButton(Sensor_SEN0101);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(320, 250, 271, 41));
        pushButton_Exit->setFont(font);
        pushButton_ChartZoom = new QPushButton(Sensor_SEN0101);
        pushButton_ChartZoom->setObjectName(QString::fromUtf8("pushButton_ChartZoom"));
        pushButton_ChartZoom->setGeometry(QRect(11, 250, 281, 41));
        pushButton_ChartZoom->setFont(font);
        line = new QFrame(Sensor_SEN0101);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-2, 233, 605, 5));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 116, 207);"));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);

        retranslateUi(Sensor_SEN0101);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0101);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0101)
    {
        Sensor_SEN0101->setWindowTitle(QCoreApplication::translate("Sensor_SEN0101", "Temprature", nullptr));
        pushButton->setText(QString());
        comboBox_Temp_Unit->setItemText(0, QCoreApplication::translate("Sensor_SEN0101", "\304\220o theo \304\221\341\273\231 C (Celsius - C)", nullptr));
        comboBox_Temp_Unit->setItemText(1, QCoreApplication::translate("Sensor_SEN0101", "\304\220o theo \304\221\341\273\231 F (Fahrenheit - F)", nullptr));
        comboBox_Temp_Unit->setItemText(2, QCoreApplication::translate("Sensor_SEN0101", "\304\220o theo \304\221\341\273\231 K (Kelvin - K )", nullptr));

        pushButton_getSamples->setText(QCoreApplication::translate("Sensor_SEN0101", "B\341\272\257t \304\221\341\272\247u", nullptr));
        label_sampleInfo->setText(QCoreApplication::translate("Sensor_SEN0101", "C\303\241c tham s\341\273\221 c\306\241 b\341\272\243n", nullptr));
        label_8->setText(QCoreApplication::translate("Sensor_SEN0101", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t", nullptr));
        label_9->setText(QCoreApplication::translate("Sensor_SEN0101", "Gi\303\241 tr\341\273\213 trung b\303\254nh", nullptr));
        label_10->setText(QCoreApplication::translate("Sensor_SEN0101", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Sensor_SEN0101", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Sensor_SEN0101", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Sensor_SEN0101", "0", nullptr));
        checkBox_setMathAvg->setText(QCoreApplication::translate("Sensor_SEN0101", "S\341\273\255 d\341\273\245ng gi\303\241 tr\341\273\213 trung b\303\254nh c\341\273\231ng", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor_2), QCoreApplication::translate("Sensor_SEN0101", "            Hi\341\273\203n th\341\273\213            ", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_13->setText(QCoreApplication::translate("Sensor_SEN0101", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_14->setText(QCoreApplication::translate("Sensor_SEN0101", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_18->setText(QCoreApplication::translate("Sensor_SEN0101", "M\303\243 s\303\252-ri:", nullptr));
        label_19->setText(QCoreApplication::translate("Sensor_SEN0101", "M\303\264 t\341\272\243:", nullptr));
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Sensor_SEN0101", "            Thi\341\272\277t b\341\273\213            ", nullptr));
        label_23->setText(QCoreApplication::translate("Sensor_SEN0101", "(ms)", nullptr));
        label_24->setText(QCoreApplication::translate("Sensor_SEN0101", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Sensor_SEN0101", "C\303\240i \304\221\341\272\267t", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Sensor_SEN0101", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_25->setText(QCoreApplication::translate("Sensor_SEN0101", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213 :", nullptr));
        label_calibInfo->setText(QCoreApplication::translate("Sensor_SEN0101", "(ch\306\260a hi\341\273\207u chu\341\272\251n)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Sensor_SEN0101", "           C\303\240i \304\221\341\272\267t            ", nullptr));
        pushButton_Exit->setStyleSheet(QCoreApplication::translate("Sensor_SEN0101", "background-color: rgb(225, 225, 225);", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0101", "Tho\303\241t", nullptr));
        pushButton_ChartZoom->setStyleSheet(QCoreApplication::translate("Sensor_SEN0101", "background-color: rgb(225, 225, 225);", nullptr));
        pushButton_ChartZoom->setText(QCoreApplication::translate("Sensor_SEN0101", "\304\220\341\273\223 th\341\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0101: public Ui_Sensor_SEN0101 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0101_H
