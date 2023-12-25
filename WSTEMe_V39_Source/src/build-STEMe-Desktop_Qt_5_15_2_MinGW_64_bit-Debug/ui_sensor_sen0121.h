/********************************************************************************
** Form generated from reading UI file 'sensor_sen0121.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0121_H
#define UI_SENSOR_SEN0121_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor_SEN0121
{
public:
    QPushButton *pushButton_Exit;
    QFrame *frame_setChart;
    QRadioButton *radioButton_Continuously;
    QRadioButton *radioButton_Accumulation;
    QPushButton *pushButton_ClearChart;
    QFrame *frame_trackLine;
    QPushButton *pushButton_TrackLine_Yax;
    QPushButton *pushButton_TrackLine_Default;
    QPushButton *pushButton_TrackLine_Tooltip;
    QFrame *frame_Chart;
    QTabWidget *tabWidget_2;
    QWidget *tab_Infor_3;
    QLCDNumber *lcdNumber_Value;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_sampleInfo;
    QPushButton *pushButton_getSamples;
    QCheckBox *checkBox_setMathAvg;
    QPushButton *pushButton_SetZero;
    QSpinBox *spinBox_setSample;
    QFrame *frame_2;
    QPushButton *pushButton_2;
    QComboBox *comboBox_Sensor_Unit;
    QLabel *label_ValueMin;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMax;
    QWidget *tab_5;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_Description;
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
    QWidget *tab;
    QPushButton *pushButton_SetSampleTime;
    QSpinBox *spinBox_SampleTime;
    QLabel *label_24;
    QLabel *label_23;
    QLabel *label_calibInfo;
    QLabel *label_25;
    QPushButton *pushButton_Calib;
    QFrame *line_2;
    QFrame *frame;
    QPushButton *pushButton_SetMode;
    QComboBox *comboBox_Sensor_Mode;
    QFrame *frame_Calculate;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_Calculate_Freq;
    QLabel *label_Calculate_Time;
    QLabel *label_16;
    QLabel *label_Calculate_Pulse;
    QFrame *frame_graphTime;
    QSpinBox *spinBox_graphTime;
    QLabel *label_15;
    QLabel *label_26;

    void setupUi(QWidget *Sensor_SEN0121)
    {
        if (Sensor_SEN0121->objectName().isEmpty())
            Sensor_SEN0121->setObjectName(QString::fromUtf8("Sensor_SEN0121"));
        Sensor_SEN0121->resize(1280, 710);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/DIS0121_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0121->setWindowIcon(icon);
        Sensor_SEN0121->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        pushButton_Exit = new QPushButton(Sensor_SEN0121);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(1120, 660, 151, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton_Exit->setFont(font);
        pushButton_Exit->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_setChart = new QFrame(Sensor_SEN0121);
        frame_setChart->setObjectName(QString::fromUtf8("frame_setChart"));
        frame_setChart->setGeometry(QRect(860, 430, 411, 31));
        frame_setChart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_setChart->setFrameShape(QFrame::StyledPanel);
        frame_setChart->setFrameShadow(QFrame::Raised);
        radioButton_Continuously = new QRadioButton(frame_setChart);
        radioButton_Continuously->setObjectName(QString::fromUtf8("radioButton_Continuously"));
        radioButton_Continuously->setGeometry(QRect(12, 2, 151, 27));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        radioButton_Continuously->setFont(font1);
        radioButton_Continuously->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Continuously->setChecked(false);
        radioButton_Accumulation = new QRadioButton(frame_setChart);
        radioButton_Accumulation->setObjectName(QString::fromUtf8("radioButton_Accumulation"));
        radioButton_Accumulation->setGeometry(QRect(170, 2, 111, 27));
        radioButton_Accumulation->setFont(font1);
        radioButton_Accumulation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Accumulation->setChecked(true);
        pushButton_ClearChart = new QPushButton(frame_setChart);
        pushButton_ClearChart->setObjectName(QString::fromUtf8("pushButton_ClearChart"));
        pushButton_ClearChart->setGeometry(QRect(298, 2, 111, 27));
        pushButton_ClearChart->setFont(font);
        pushButton_ClearChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_trackLine = new QFrame(Sensor_SEN0121);
        frame_trackLine->setObjectName(QString::fromUtf8("frame_trackLine"));
        frame_trackLine->setGeometry(QRect(10, 430, 411, 31));
        frame_trackLine->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_trackLine->setFrameShape(QFrame::StyledPanel);
        frame_trackLine->setFrameShadow(QFrame::Raised);
        pushButton_TrackLine_Yax = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Yax->setObjectName(QString::fromUtf8("pushButton_TrackLine_Yax"));
        pushButton_TrackLine_Yax->setGeometry(QRect(382, 2, 27, 27));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        pushButton_TrackLine_Yax->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/MFS0103_Track_yax.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Yax->setIcon(icon1);
        pushButton_TrackLine_Yax->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Default = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Default->setObjectName(QString::fromUtf8("pushButton_TrackLine_Default"));
        pushButton_TrackLine_Default->setGeometry(QRect(2, 2, 27, 27));
        pushButton_TrackLine_Default->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/MFS0103_Track_D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Default->setIcon(icon2);
        pushButton_TrackLine_Default->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Tooltip = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Tooltip->setObjectName(QString::fromUtf8("pushButton_TrackLine_Tooltip"));
        pushButton_TrackLine_Tooltip->setGeometry(QRect(30, 2, 27, 27));
        pushButton_TrackLine_Tooltip->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/MFS0103_Track_T.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Tooltip->setIcon(icon3);
        pushButton_TrackLine_Tooltip->setIconSize(QSize(25, 25));
        frame_Chart = new QFrame(Sensor_SEN0121);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(10, 10, 1260, 421));
        frame_Chart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        tabWidget_2 = new QTabWidget(Sensor_SEN0121);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 470, 551, 231));
        tabWidget_2->setFont(font1);
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        tabWidget_2->setElideMode(Qt::ElideNone);
        tab_Infor_3 = new QWidget();
        tab_Infor_3->setObjectName(QString::fromUtf8("tab_Infor_3"));
        lcdNumber_Value = new QLCDNumber(tab_Infor_3);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(10, 10, 271, 71));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 70, 102);\n"
"color:rgb(5, 209, 255)"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        verticalLayoutWidget_6 = new QWidget(tab_Infor_3);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(310, 30, 121, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_10);

        label_sampleInfo = new QLabel(tab_Infor_3);
        label_sampleInfo->setObjectName(QString::fromUtf8("label_sampleInfo"));
        label_sampleInfo->setGeometry(QRect(300, 0, 241, 26));
        label_sampleInfo->setFont(font1);
        label_sampleInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_getSamples = new QPushButton(tab_Infor_3);
        pushButton_getSamples->setObjectName(QString::fromUtf8("pushButton_getSamples"));
        pushButton_getSamples->setGeometry(QRect(430, 120, 111, 51));
        pushButton_getSamples->setFont(font);
        pushButton_getSamples->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        checkBox_setMathAvg = new QCheckBox(tab_Infor_3);
        checkBox_setMathAvg->setObjectName(QString::fromUtf8("checkBox_setMathAvg"));
        checkBox_setMathAvg->setGeometry(QRect(10, 86, 281, 27));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        checkBox_setMathAvg->setFont(font3);
        checkBox_setMathAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetZero = new QPushButton(tab_Infor_3);
        pushButton_SetZero->setObjectName(QString::fromUtf8("pushButton_SetZero"));
        pushButton_SetZero->setGeometry(QRect(9, 158, 271, 41));
        pushButton_SetZero->setFont(font);
        pushButton_SetZero->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_setSample = new QSpinBox(tab_Infor_3);
        spinBox_setSample->setObjectName(QString::fromUtf8("spinBox_setSample"));
        spinBox_setSample->setGeometry(QRect(310, 120, 111, 51));
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
        frame_2 = new QFrame(tab_Infor_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 110, 271, 41));
        frame_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 8, 32, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(32, 32));
        comboBox_Sensor_Unit = new QComboBox(frame_2);
        comboBox_Sensor_Unit->addItem(QString());
        comboBox_Sensor_Unit->addItem(QString());
        comboBox_Sensor_Unit->addItem(QString());
        comboBox_Sensor_Unit->addItem(QString());
        comboBox_Sensor_Unit->setObjectName(QString::fromUtf8("comboBox_Sensor_Unit"));
        comboBox_Sensor_Unit->setGeometry(QRect(33, 8, 237, 32));
        comboBox_Sensor_Unit->setFont(font3);
        comboBox_Sensor_Unit->setLayoutDirection(Qt::LeftToRight);
        comboBox_Sensor_Unit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        comboBox_Sensor_Unit->setEditable(false);
        label_ValueMin = new QLabel(tab_Infor_3);
        label_ValueMin->setObjectName(QString::fromUtf8("label_ValueMin"));
        label_ValueMin->setGeometry(QRect(440, 89, 99, 21));
        label_ValueMin->setFont(font2);
        label_ValueMin->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        label_ValueAvg = new QLabel(tab_Infor_3);
        label_ValueAvg->setObjectName(QString::fromUtf8("label_ValueAvg"));
        label_ValueAvg->setGeometry(QRect(440, 61, 99, 21));
        label_ValueAvg->setFont(font2);
        label_ValueAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_ValueAvg->setFrameShape(QFrame::NoFrame);
        label_ValueMax = new QLabel(tab_Infor_3);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        label_ValueMax->setGeometry(QRect(440, 29, 99, 26));
        label_ValueMax->setFont(font2);
        label_ValueMax->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        tabWidget_2->addTab(tab_Infor_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayoutWidget_10 = new QWidget(tab_5);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(150, 110, 271, 61));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_10);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        QFont font4;
        font4.setPointSize(10);
        label_Description->setFont(font4);
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_10->addWidget(label_Description);

        verticalLayoutWidget_8 = new QWidget(tab_5);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(150, 10, 271, 101));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_8);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
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

        verticalLayoutWidget_9 = new QWidget(tab_5);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_14);

        label_18 = new QLabel(verticalLayoutWidget_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_19);

        tabWidget_2->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_SetSampleTime = new QPushButton(tab);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(300, 20, 121, 61));
        pushButton_SetSampleTime->setFont(font);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_SampleTime = new QSpinBox(tab);
        spinBox_SampleTime->setObjectName(QString::fromUtf8("spinBox_SampleTime"));
        spinBox_SampleTime->setGeometry(QRect(150, 10, 101, 81));
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
        spinBox_SampleTime->setValue(200);
        label_24 = new QLabel(tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 40, 131, 22));
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 40, 31, 22));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_calibInfo = new QLabel(tab);
        label_calibInfo->setObjectName(QString::fromUtf8("label_calibInfo"));
        label_calibInfo->setGeometry(QRect(30, 160, 121, 22));
        label_calibInfo->setFont(font3);
        label_calibInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        label_25 = new QLabel(tab);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 139, 141, 22));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Calib = new QPushButton(tab);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(190, 130, 121, 61));
        pushButton_Calib->setFont(font);
        pushButton_Calib->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 100, 531, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        tabWidget_2->addTab(tab, QString());
        frame = new QFrame(Sensor_SEN0121);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(570, 470, 541, 231));
        frame->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_SetMode = new QPushButton(frame);
        pushButton_SetMode->setObjectName(QString::fromUtf8("pushButton_SetMode"));
        pushButton_SetMode->setGeometry(QRect(30, 160, 481, 51));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        pushButton_SetMode->setFont(font5);
        pushButton_SetMode->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 85, 255);\n"
"}"));
        comboBox_Sensor_Mode = new QComboBox(frame);
        comboBox_Sensor_Mode->addItem(QString());
        comboBox_Sensor_Mode->addItem(QString());
        comboBox_Sensor_Mode->addItem(QString());
        comboBox_Sensor_Mode->setObjectName(QString::fromUtf8("comboBox_Sensor_Mode"));
        comboBox_Sensor_Mode->setGeometry(QRect(30, 20, 481, 41));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(true);
        comboBox_Sensor_Mode->setFont(font6);
        comboBox_Sensor_Mode->setLayoutDirection(Qt::LeftToRight);
        comboBox_Sensor_Mode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        comboBox_Sensor_Mode->setEditable(false);
        frame_Calculate = new QFrame(frame);
        frame_Calculate->setObjectName(QString::fromUtf8("frame_Calculate"));
        frame_Calculate->setGeometry(QRect(30, 70, 241, 80));
        frame_Calculate->setStyleSheet(QString::fromUtf8("QFrame#frame_Calculate{\n"
"    border: 1px solid gray;\n"
"}"));
        frame_Calculate->setFrameShape(QFrame::NoFrame);
        frame_Calculate->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(frame_Calculate);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 29, 61, 22));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(frame_Calculate);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 49, 61, 23));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Calculate_Freq = new QLabel(frame_Calculate);
        label_Calculate_Freq->setObjectName(QString::fromUtf8("label_Calculate_Freq"));
        label_Calculate_Freq->setGeometry(QRect(90, 27, 99, 26));
        label_Calculate_Freq->setFont(font2);
        label_Calculate_Freq->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_Calculate_Time = new QLabel(frame_Calculate);
        label_Calculate_Time->setObjectName(QString::fromUtf8("label_Calculate_Time"));
        label_Calculate_Time->setGeometry(QRect(90, 50, 99, 21));
        label_Calculate_Time->setFont(font2);
        label_Calculate_Time->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        label_16 = new QLabel(frame_Calculate);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 9, 61, 22));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Calculate_Pulse = new QLabel(frame_Calculate);
        label_Calculate_Pulse->setObjectName(QString::fromUtf8("label_Calculate_Pulse"));
        label_Calculate_Pulse->setGeometry(QRect(90, 10, 99, 21));
        label_Calculate_Pulse->setFont(font2);
        label_Calculate_Pulse->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Calculate_Pulse->setFrameShape(QFrame::NoFrame);
        frame_graphTime = new QFrame(frame);
        frame_graphTime->setObjectName(QString::fromUtf8("frame_graphTime"));
        frame_graphTime->setGeometry(QRect(270, 70, 241, 80));
        frame_graphTime->setStyleSheet(QString::fromUtf8("QFrame#frame_graphTime{\n"
"    border: 1px solid gray;\n"
"}"));
        frame_graphTime->setFrameShape(QFrame::NoFrame);
        frame_graphTime->setFrameShadow(QFrame::Raised);
        spinBox_graphTime = new QSpinBox(frame_graphTime);
        spinBox_graphTime->setObjectName(QString::fromUtf8("spinBox_graphTime"));
        spinBox_graphTime->setGeometry(QRect(110, 10, 91, 61));
        spinBox_graphTime->setFont(font2);
        spinBox_graphTime->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_graphTime->setMinimum(1);
        spinBox_graphTime->setMaximum(999);
        spinBox_graphTime->setSingleStep(1);
        spinBox_graphTime->setValue(10);
        label_15 = new QLabel(frame_graphTime);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(9, 29, 91, 23));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_26 = new QLabel(frame_graphTime);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(210, 30, 21, 22));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(Sensor_SEN0121);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0121);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0121)
    {
        Sensor_SEN0121->setWindowTitle(QCoreApplication::translate("Sensor_SEN0121", "Form", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0121", "Tho\303\241t", nullptr));
        radioButton_Continuously->setText(QCoreApplication::translate("Sensor_SEN0121", "Th\341\273\235i gian \304\221o", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Sensor_SEN0121", "\304\220\341\273\223 th\341\273\213 t\303\255ch l\305\251y", nullptr));
        pushButton_ClearChart->setText(QCoreApplication::translate("Sensor_SEN0121", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setToolTip(QCoreApplication::translate("Sensor_SEN0121", "t\303\255nh h\341\273\207 s\341\273\221 g\303\263c y=ax", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setToolTip(QCoreApplication::translate("Sensor_SEN0121", "tr\341\273\245c t\341\273\215a \304\221\341\273\231 \341\272\243o", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setToolTip(QCoreApplication::translate("Sensor_SEN0121", "b\341\272\257t \304\221i\341\273\203m", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setText(QString());
        label_8->setText(QCoreApplication::translate("Sensor_SEN0121", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t", nullptr));
        label_9->setText(QCoreApplication::translate("Sensor_SEN0121", "Gi\303\241 tr\341\273\213 trung b\303\254nh", nullptr));
        label_10->setText(QCoreApplication::translate("Sensor_SEN0121", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t", nullptr));
        label_sampleInfo->setText(QCoreApplication::translate("Sensor_SEN0121", "C\303\241c tham s\341\273\221 c\306\241 b\341\272\243n", nullptr));
        pushButton_getSamples->setText(QCoreApplication::translate("Sensor_SEN0121", "L\341\272\245y m\341\272\253u", nullptr));
        checkBox_setMathAvg->setText(QCoreApplication::translate("Sensor_SEN0121", "S\341\273\255 d\341\273\245ng gi\303\241 tr\341\273\213 trung b\303\254nh c\341\273\231ng", nullptr));
        pushButton_SetZero->setText(QCoreApplication::translate("Sensor_SEN0121", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m 0 (Zero)", nullptr));
        pushButton_2->setText(QString());
        comboBox_Sensor_Unit->setItemText(0, QCoreApplication::translate("Sensor_SEN0121", "\304\220o theo millimeter  (mm)", nullptr));
        comboBox_Sensor_Unit->setItemText(1, QCoreApplication::translate("Sensor_SEN0121", "\304\220o theo centimeter (cm)", nullptr));
        comboBox_Sensor_Unit->setItemText(2, QCoreApplication::translate("Sensor_SEN0121", "\304\220o theo decimeter  (dm)", nullptr));
        comboBox_Sensor_Unit->setItemText(3, QCoreApplication::translate("Sensor_SEN0121", "\304\220o theo meter (m)", nullptr));

        label_ValueMin->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_Infor_3), QCoreApplication::translate("Sensor_SEN0121", "          Hi\341\273\203n th\341\273\213          ", nullptr));
        label_Description->setText(QString());
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_13->setText(QCoreApplication::translate("Sensor_SEN0121", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_14->setText(QCoreApplication::translate("Sensor_SEN0121", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_18->setText(QCoreApplication::translate("Sensor_SEN0121", "M\303\243 s\303\252-ri:", nullptr));
        label_19->setText(QCoreApplication::translate("Sensor_SEN0121", "M\303\264 t\341\272\243:", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("Sensor_SEN0121", "            Thi\341\272\277t b\341\273\213            ", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Sensor_SEN0121", "C\303\240i \304\221\341\272\267t", nullptr));
        label_24->setText(QCoreApplication::translate("Sensor_SEN0121", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        label_23->setText(QCoreApplication::translate("Sensor_SEN0121", "(ms)", nullptr));
        label_calibInfo->setText(QCoreApplication::translate("Sensor_SEN0121", "(ch\306\260a hi\341\273\207u chu\341\272\251n)", nullptr));
        label_25->setText(QCoreApplication::translate("Sensor_SEN0121", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213 :", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Sensor_SEN0121", "Hi\341\273\207u chu\341\272\251n", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("Sensor_SEN0121", "             C\303\240i \304\221\341\272\267t             ", nullptr));
        pushButton_SetMode->setText(QCoreApplication::translate("Sensor_SEN0121", "B\341\272\256T \304\220\341\272\246U", nullptr));
        comboBox_Sensor_Mode->setItemText(0, QCoreApplication::translate("Sensor_SEN0121", "Ch\341\272\277 \304\221\341\273\231 m\341\272\267c \304\221\341\273\213nh", nullptr));
        comboBox_Sensor_Mode->setItemText(1, QCoreApplication::translate("Sensor_SEN0121", "Ch\341\272\277 \304\221\341\273\231 \304\221o ch\303\255nh x\303\241c", nullptr));
        comboBox_Sensor_Mode->setItemText(2, QCoreApplication::translate("Sensor_SEN0121", "\304\220o dao \304\221\341\273\231ng", nullptr));

        label_11->setText(QCoreApplication::translate("Sensor_SEN0121", "T\341\272\247n s\341\273\221:", nullptr));
        label_12->setText(QCoreApplication::translate("Sensor_SEN0121", "Chu k\341\273\263:", nullptr));
        label_Calculate_Freq->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        label_Calculate_Time->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        label_16->setText(QCoreApplication::translate("Sensor_SEN0121", "S\341\273\221 xung:", nullptr));
        label_Calculate_Pulse->setText(QCoreApplication::translate("Sensor_SEN0121", "0", nullptr));
        label_15->setText(QCoreApplication::translate("Sensor_SEN0121", "Th\341\273\235i gian \304\221o:", nullptr));
        label_26->setText(QCoreApplication::translate("Sensor_SEN0121", "(S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0121: public Ui_Sensor_SEN0121 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0121_H
