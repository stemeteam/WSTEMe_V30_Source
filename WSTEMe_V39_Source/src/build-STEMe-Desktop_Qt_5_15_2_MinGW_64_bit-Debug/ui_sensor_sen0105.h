/********************************************************************************
** Form generated from reading UI file 'sensor_sen0105.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0105_H
#define UI_SENSOR_SEN0105_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_Sensor_SEN0105
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_Infor_2;
    QFrame *frame_2;
    QLCDNumber *lcdNumber_Value;
    QComboBox *comboBox_Unit;
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
    QPushButton *pushButton;
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
    QWidget *tab;
    QSpinBox *spinBox_SoundSensitivity;
    QSpinBox *spinBox_SoundRepeat;
    QLabel *label_30;
    QLabel *label_32;
    QLabel *label_61;
    QSpinBox *spinBox_Display_Unit_Pre;
    QFrame *line;
    QPushButton *pushButton_Exit;
    QFrame *frame_Chart;
    QPushButton *pushButton_OpenData;
    QFrame *frame;
    QPushButton *pushButton_Start;
    QComboBox *comboBox_SelectSample;
    QPushButton *pushButton_SaveData;
    QFrame *frame_trackLine;
    QPushButton *pushButton_TrackLine_Yax;
    QPushButton *pushButton_TrackLine_Default;
    QPushButton *pushButton_TrackLine_Tooltip;
    QFrame *frame_setChart;
    QRadioButton *radioButton_Continuously;
    QRadioButton *radioButton_Accumulation;
    QPushButton *pushButton_ClearChart;

    void setupUi(QWidget *Sensor_SEN0105)
    {
        if (Sensor_SEN0105->objectName().isEmpty())
            Sensor_SEN0105->setObjectName(QString::fromUtf8("Sensor_SEN0105"));
        Sensor_SEN0105->resize(1280, 710);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/SOU0105_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0105->setWindowIcon(icon);
        Sensor_SEN0105->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        tabWidget = new QTabWidget(Sensor_SEN0105);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 460, 431, 241));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        tabWidget->setElideMode(Qt::ElideNone);
        tab_Infor_2 = new QWidget();
        tab_Infor_2->setObjectName(QString::fromUtf8("tab_Infor_2"));
        frame_2 = new QFrame(tab_Infor_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 431, 211));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        lcdNumber_Value = new QLCDNumber(frame_2);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(8, 9, 411, 51));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(0, 255, 187);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        comboBox_Unit = new QComboBox(frame_2);
        comboBox_Unit->addItem(QString());
        comboBox_Unit->addItem(QString());
        comboBox_Unit->addItem(QString());
        comboBox_Unit->setObjectName(QString::fromUtf8("comboBox_Unit"));
        comboBox_Unit->setGeometry(QRect(41, 69, 377, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        comboBox_Unit->setFont(font1);
        comboBox_Unit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        verticalLayoutWidget_6 = new QWidget(frame_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(8, 110, 128, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
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

        verticalLayoutWidget_7 = new QWidget(frame_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(150, 110, 261, 81));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_7);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font3;
        font3.setPointSize(12);
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

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(8, 69, 32, 32));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));
        tabWidget->addTab(tab_Infor_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayoutWidget_8 = new QWidget(tab_4);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(110, 10, 231, 101));
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
        verticalLayoutWidget_9->setGeometry(QRect(10, 10, 91, 131));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font4);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_14);

        label_18 = new QLabel(verticalLayoutWidget_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font4);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_19);

        verticalLayoutWidget_10 = new QWidget(tab_4);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(110, 110, 231, 61));
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
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        spinBox_SoundSensitivity = new QSpinBox(tab);
        spinBox_SoundSensitivity->setObjectName(QString::fromUtf8("spinBox_SoundSensitivity"));
        spinBox_SoundSensitivity->setGeometry(QRect(190, 110, 101, 41));
        spinBox_SoundSensitivity->setFont(font);
        spinBox_SoundSensitivity->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_SoundSensitivity->setMinimum(0);
        spinBox_SoundSensitivity->setMaximum(4096);
        spinBox_SoundSensitivity->setValue(500);
        spinBox_SoundRepeat = new QSpinBox(tab);
        spinBox_SoundRepeat->setObjectName(QString::fromUtf8("spinBox_SoundRepeat"));
        spinBox_SoundRepeat->setGeometry(QRect(190, 160, 101, 41));
        spinBox_SoundRepeat->setFont(font);
        spinBox_SoundRepeat->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_SoundRepeat->setMinimum(0);
        spinBox_SoundRepeat->setMaximum(255);
        spinBox_SoundRepeat->setValue(10);
        label_30 = new QLabel(tab);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(70, 120, 111, 22));
        label_30->setFont(font4);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_32 = new QLabel(tab);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(114, 170, 71, 22));
        label_32->setFont(font4);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_61 = new QLabel(tab);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(94, 30, 81, 20));
        label_61->setFont(font2);
        label_61->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_Display_Unit_Pre = new QSpinBox(tab);
        spinBox_Display_Unit_Pre->setObjectName(QString::fromUtf8("spinBox_Display_Unit_Pre"));
        spinBox_Display_Unit_Pre->setGeometry(QRect(190, 20, 101, 40));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        spinBox_Display_Unit_Pre->setFont(font5);
        spinBox_Display_Unit_Pre->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_Display_Unit_Pre->setAlignment(Qt::AlignCenter);
        spinBox_Display_Unit_Pre->setMinimum(0);
        spinBox_Display_Unit_Pre->setMaximum(3);
        spinBox_Display_Unit_Pre->setValue(3);
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 80, 411, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab, QString());
        pushButton_Exit = new QPushButton(Sensor_SEN0105);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(1120, 650, 151, 41));
        pushButton_Exit->setFont(font3);
        pushButton_Exit->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_Chart = new QFrame(Sensor_SEN0105);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(10, 0, 1260, 421));
        frame_Chart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        pushButton_OpenData = new QPushButton(Sensor_SEN0105);
        pushButton_OpenData->setObjectName(QString::fromUtf8("pushButton_OpenData"));
        pushButton_OpenData->setGeometry(QRect(1120, 500, 151, 41));
        pushButton_OpenData->setFont(font3);
        pushButton_OpenData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame = new QFrame(Sensor_SEN0105);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(450, 470, 501, 231));
        frame->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_Start = new QPushButton(frame);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(20, 90, 461, 61));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        pushButton_Start->setFont(font6);
        pushButton_Start->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(225, 225, 225);\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        comboBox_SelectSample = new QComboBox(frame);
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->setObjectName(QString::fromUtf8("comboBox_SelectSample"));
        comboBox_SelectSample->setGeometry(QRect(20, 20, 461, 41));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setItalic(true);
        comboBox_SelectSample->setFont(font7);
        comboBox_SelectSample->setLayoutDirection(Qt::LeftToRight);
        comboBox_SelectSample->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        comboBox_SelectSample->setEditable(false);
        pushButton_SaveData = new QPushButton(Sensor_SEN0105);
        pushButton_SaveData->setObjectName(QString::fromUtf8("pushButton_SaveData"));
        pushButton_SaveData->setGeometry(QRect(1120, 550, 151, 41));
        pushButton_SaveData->setFont(font3);
        pushButton_SaveData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_trackLine = new QFrame(Sensor_SEN0105);
        frame_trackLine->setObjectName(QString::fromUtf8("frame_trackLine"));
        frame_trackLine->setGeometry(QRect(10, 420, 411, 31));
        frame_trackLine->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_trackLine->setFrameShape(QFrame::StyledPanel);
        frame_trackLine->setFrameShadow(QFrame::Raised);
        pushButton_TrackLine_Yax = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Yax->setObjectName(QString::fromUtf8("pushButton_TrackLine_Yax"));
        pushButton_TrackLine_Yax->setGeometry(QRect(382, 2, 27, 27));
        pushButton_TrackLine_Yax->setFont(font6);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/MFS0103_Track_yax.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Yax->setIcon(icon1);
        pushButton_TrackLine_Yax->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Default = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Default->setObjectName(QString::fromUtf8("pushButton_TrackLine_Default"));
        pushButton_TrackLine_Default->setGeometry(QRect(2, 2, 27, 27));
        pushButton_TrackLine_Default->setFont(font6);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/MFS0103_Track_D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Default->setIcon(icon2);
        pushButton_TrackLine_Default->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Tooltip = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Tooltip->setObjectName(QString::fromUtf8("pushButton_TrackLine_Tooltip"));
        pushButton_TrackLine_Tooltip->setGeometry(QRect(30, 2, 27, 27));
        pushButton_TrackLine_Tooltip->setFont(font6);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/MFS0103_Track_T.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Tooltip->setIcon(icon3);
        pushButton_TrackLine_Tooltip->setIconSize(QSize(25, 25));
        frame_setChart = new QFrame(Sensor_SEN0105);
        frame_setChart->setObjectName(QString::fromUtf8("frame_setChart"));
        frame_setChart->setGeometry(QRect(860, 420, 411, 31));
        frame_setChart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_setChart->setFrameShape(QFrame::StyledPanel);
        frame_setChart->setFrameShadow(QFrame::Raised);
        radioButton_Continuously = new QRadioButton(frame_setChart);
        radioButton_Continuously->setObjectName(QString::fromUtf8("radioButton_Continuously"));
        radioButton_Continuously->setGeometry(QRect(12, 2, 141, 27));
        radioButton_Continuously->setFont(font);
        radioButton_Continuously->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Continuously->setChecked(false);
        radioButton_Accumulation = new QRadioButton(frame_setChart);
        radioButton_Accumulation->setObjectName(QString::fromUtf8("radioButton_Accumulation"));
        radioButton_Accumulation->setGeometry(QRect(152, 2, 131, 27));
        radioButton_Accumulation->setFont(font);
        radioButton_Accumulation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Accumulation->setChecked(true);
        pushButton_ClearChart = new QPushButton(frame_setChart);
        pushButton_ClearChart->setObjectName(QString::fromUtf8("pushButton_ClearChart"));
        pushButton_ClearChart->setGeometry(QRect(298, 2, 111, 27));
        pushButton_ClearChart->setFont(font3);
        pushButton_ClearChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        retranslateUi(Sensor_SEN0105);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0105);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0105)
    {
        Sensor_SEN0105->setWindowTitle(QCoreApplication::translate("Sensor_SEN0105", "Form", nullptr));
        comboBox_Unit->setItemText(0, QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\231 \341\273\223n (dB)", nullptr));
        comboBox_Unit->setItemText(1, QCoreApplication::translate("Sensor_SEN0105", "T\341\272\247n s\341\273\221 (Hz)", nullptr));
        comboBox_Unit->setItemText(2, QCoreApplication::translate("Sensor_SEN0105", "\304\220i\341\273\207n \303\241p (V - Voltage)", nullptr));

        label_8->setText(QCoreApplication::translate("Sensor_SEN0105", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t", nullptr));
        label_9->setText(QCoreApplication::translate("Sensor_SEN0105", "Gi\303\241 tr\341\273\213 trung b\303\254nh", nullptr));
        label_10->setText(QCoreApplication::translate("Sensor_SEN0105", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Sensor_SEN0105", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Sensor_SEN0105", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Sensor_SEN0105", "0", nullptr));
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor_2), QCoreApplication::translate("Sensor_SEN0105", "     Hi\341\273\203n th\341\273\213     ", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_13->setText(QCoreApplication::translate("Sensor_SEN0105", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_14->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_18->setText(QCoreApplication::translate("Sensor_SEN0105", "M\303\243 s\303\252-ri:", nullptr));
        label_19->setText(QCoreApplication::translate("Sensor_SEN0105", "M\303\264 t\341\272\243:", nullptr));
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Sensor_SEN0105", "       Thi\341\272\277t b\341\273\213       ", nullptr));
        label_30->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\231 nh\341\272\241y \303\242m thoa:", nullptr));
        label_32->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\231 l\341\272\267p l\341\272\241i:", nullptr));
        label_61->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\231 ph\303\242n gi\341\272\243i:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Sensor_SEN0105", "        C\303\240i \304\221\341\272\267t        ", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0105", "Tho\303\241t", nullptr));
        pushButton_OpenData->setText(QCoreApplication::translate("Sensor_SEN0105", "M\341\273\237 b\341\272\243n ghi", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("Sensor_SEN0105", "B\341\272\257t \304\221\341\272\247u", nullptr));
        comboBox_SelectSample->setItemText(0, QCoreApplication::translate("Sensor_SEN0105", "\304\220o m\341\273\251c \303\242m thanh", nullptr));
        comboBox_SelectSample->setItemText(1, QCoreApplication::translate("Sensor_SEN0105", "\304\220o s\303\263ng t\341\273\233i v\303\240 s\303\263ng ph\341\272\243n x\341\272\241", nullptr));
        comboBox_SelectSample->setItemText(2, QCoreApplication::translate("Sensor_SEN0105", "\304\220o t\341\272\247n s\341\273\221 \303\242m thoa", nullptr));
        comboBox_SelectSample->setItemText(3, QCoreApplication::translate("Sensor_SEN0105", "\304\220o \304\221i\341\273\207n \303\241p (Vrms)", nullptr));

        pushButton_SaveData->setText(QCoreApplication::translate("Sensor_SEN0105", "Ghi d\341\273\257 li\341\273\207u", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setToolTip(QCoreApplication::translate("Sensor_SEN0105", "t\303\255nh h\341\273\207 s\341\273\221 g\303\263c y=ax", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setToolTip(QCoreApplication::translate("Sensor_SEN0105", "tr\341\273\245c t\341\273\215a \304\221\341\273\231 \341\272\243o", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setToolTip(QCoreApplication::translate("Sensor_SEN0105", "b\341\272\257t \304\221i\341\273\203m", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setText(QString());
        radioButton_Continuously->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\223 th\341\273\213 li\303\252n t\341\273\245c", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Sensor_SEN0105", "\304\220\341\273\223 th\341\273\213 t\303\255ch l\305\251y", nullptr));
        pushButton_ClearChart->setText(QCoreApplication::translate("Sensor_SEN0105", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0105: public Ui_Sensor_SEN0105 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0105_H
