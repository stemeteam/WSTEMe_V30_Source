/********************************************************************************
** Form generated from reading UI file 'module_mod1101.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_MOD1101_H
#define UI_MODULE_MOD1101_H

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

class Ui_Module_MOD1101
{
public:
    QFrame *frame_Chart;
    QTabWidget *tabWidget;
    QWidget *tab_Infor;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ValueMax;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMin;
    QSpinBox *spinBox_setSample;
    QPushButton *pushButton_getSamples;
    QLabel *label_sampleInfo;
    QFrame *frame_2;
    QPushButton *pushButton_SetZero;
    QLCDNumber *lcdNumber_Value;
    QCheckBox *checkBox_setMathAvg;
    QComboBox *comboBox_Unit;
    QPushButton *pushButton;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Name;
    QLabel *label_Address;
    QLabel *label_SerialNumber;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Description;
    QWidget *tab;
    QLabel *label_15;
    QLabel *label_16;
    QSpinBox *spinBox_AxisY_Range_Min;
    QSpinBox *spinBox_AxisY_Range_Max;
    QLabel *label_17;
    QSpinBox *spinBox_AxitX_Range_Max;
    QPushButton *pushButton_SetConfigChart;
    QWidget *tab_3;
    QLabel *label_12;
    QLabel *label_11;
    QPushButton *pushButton_SetSampleTime;
    QSpinBox *spinBox_SampleTime;
    QFrame *line;
    QRadioButton *radioButton_typeCalib;
    QPushButton *pushButton_Calib;
    QLabel *label_calibInfo;
    QLabel *label_60;
    QSpinBox *spinBox_Display_Car_Pre_F1;
    QPushButton *pushButton_Cancel;
    QFrame *frame;
    QPushButton *pushButton_Previous;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Next;
    QComboBox *comboBox_SelectSample;
    QLabel *label_MotorStatus;
    QPushButton *pushButton_SaveData;
    QPushButton *pushButton_OpenData;
    QFrame *frame_trackLine;
    QPushButton *pushButton_TrackLine_Yax;
    QPushButton *pushButton_TrackLine_Default;
    QPushButton *pushButton_TrackLine_Tooltip;
    QFrame *frame_setChart;
    QRadioButton *radioButton_Continuously;
    QRadioButton *radioButton_Accumulation;
    QPushButton *pushButton_ClearChart;

    void setupUi(QWidget *Module_MOD1101)
    {
        if (Module_MOD1101->objectName().isEmpty())
            Module_MOD1101->setObjectName(QString::fromUtf8("Module_MOD1101"));
        Module_MOD1101->resize(1280, 710);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/MFS1101_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Module_MOD1101->setWindowIcon(icon);
        Module_MOD1101->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame_Chart = new QFrame(Module_MOD1101);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(10, 10, 1261, 421));
        frame_Chart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(Module_MOD1101);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 470, 581, 231));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"border: 1px solid #C0C0C0;\n"
"}\n"
""));
        tab_Infor = new QWidget();
        tab_Infor->setObjectName(QString::fromUtf8("tab_Infor"));
        verticalLayoutWidget = new QWidget(tab_Infor);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(320, 30, 128, 92));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2);

        verticalLayoutWidget_2 = new QWidget(tab_Infor);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(460, 30, 101, 92));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_2);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_ValueMax->setFont(font1);
        label_ValueMax->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_2->addWidget(label_ValueMax);

        label_ValueAvg = new QLabel(verticalLayoutWidget_2);
        label_ValueAvg->setObjectName(QString::fromUtf8("label_ValueAvg"));
        label_ValueAvg->setFont(font1);
        label_ValueAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_ValueAvg);

        label_ValueMin = new QLabel(verticalLayoutWidget_2);
        label_ValueMin->setObjectName(QString::fromUtf8("label_ValueMin"));
        label_ValueMin->setFont(font1);
        label_ValueMin->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        verticalLayout_2->addWidget(label_ValueMin);

        spinBox_setSample = new QSpinBox(tab_Infor);
        spinBox_setSample->setObjectName(QString::fromUtf8("spinBox_setSample"));
        spinBox_setSample->setGeometry(QRect(320, 130, 128, 51));
        spinBox_setSample->setFont(font);
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
        spinBox_setSample->setAlignment(Qt::AlignCenter);
        spinBox_setSample->setMinimum(1);
        spinBox_setSample->setMaximum(9999999);
        spinBox_setSample->setValue(10);
        pushButton_getSamples = new QPushButton(tab_Infor);
        pushButton_getSamples->setObjectName(QString::fromUtf8("pushButton_getSamples"));
        pushButton_getSamples->setGeometry(QRect(460, 130, 101, 51));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        pushButton_getSamples->setFont(font2);
        pushButton_getSamples->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_sampleInfo = new QLabel(tab_Infor);
        label_sampleInfo->setObjectName(QString::fromUtf8("label_sampleInfo"));
        label_sampleInfo->setGeometry(QRect(310, 2, 261, 26));
        label_sampleInfo->setFont(font);
        label_sampleInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_2 = new QFrame(tab_Infor);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 311, 191));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_SetZero = new QPushButton(frame_2);
        pushButton_SetZero->setObjectName(QString::fromUtf8("pushButton_SetZero"));
        pushButton_SetZero->setGeometry(QRect(18, 130, 281, 51));
        pushButton_SetZero->setFont(font2);
        pushButton_SetZero->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        lcdNumber_Value = new QLCDNumber(frame_2);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(18, 10, 281, 51));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 0, 0);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        checkBox_setMathAvg = new QCheckBox(frame_2);
        checkBox_setMathAvg->setObjectName(QString::fromUtf8("checkBox_setMathAvg"));
        checkBox_setMathAvg->setGeometry(QRect(18, 61, 281, 27));
        checkBox_setMathAvg->setFont(font);
        checkBox_setMathAvg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_Unit = new QComboBox(frame_2);
        comboBox_Unit->addItem(QString());
        comboBox_Unit->addItem(QString());
        comboBox_Unit->addItem(QString());
        comboBox_Unit->addItem(QString());
        comboBox_Unit->setObjectName(QString::fromUtf8("comboBox_Unit"));
        comboBox_Unit->setGeometry(QRect(50, 90, 249, 32));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        comboBox_Unit->setFont(font3);
        comboBox_Unit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 90, 32, 32));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));
        tabWidget->addTab(tab_Infor, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_4 = new QWidget(tab_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(150, 10, 291, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_4);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        QFont font4;
        font4.setPointSize(10);
        label_Name->setFont(font4);
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_4);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setFont(font4);
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_4);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setFont(font4);
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_SerialNumber);

        verticalLayoutWidget_5 = new QWidget(tab_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(label_7);

        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(label_5);

        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(150, 110, 291, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_3);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setFont(font4);
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(label_Description);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 10, 101, 22));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(230, 10, 91, 22));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_AxisY_Range_Min = new QSpinBox(tab);
        spinBox_AxisY_Range_Min->setObjectName(QString::fromUtf8("spinBox_AxisY_Range_Min"));
        spinBox_AxisY_Range_Min->setGeometry(QRect(30, 35, 111, 81));
        spinBox_AxisY_Range_Min->setFont(font);
        spinBox_AxisY_Range_Min->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
"}"));
        spinBox_AxisY_Range_Min->setMinimum(-9999999);
        spinBox_AxisY_Range_Min->setMaximum(9999999);
        spinBox_AxisY_Range_Min->setValue(0);
        spinBox_AxisY_Range_Max = new QSpinBox(tab);
        spinBox_AxisY_Range_Max->setObjectName(QString::fromUtf8("spinBox_AxisY_Range_Max"));
        spinBox_AxisY_Range_Max->setGeometry(QRect(220, 35, 111, 81));
        spinBox_AxisY_Range_Max->setFont(font);
        spinBox_AxisY_Range_Max->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
"}"));
        spinBox_AxisY_Range_Max->setMinimum(-9999999);
        spinBox_AxisY_Range_Max->setMaximum(9999999);
        spinBox_AxisY_Range_Max->setValue(1);
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(390, 10, 161, 22));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_AxitX_Range_Max = new QSpinBox(tab);
        spinBox_AxitX_Range_Max->setObjectName(QString::fromUtf8("spinBox_AxitX_Range_Max"));
        spinBox_AxitX_Range_Max->setGeometry(QRect(410, 35, 111, 81));
        spinBox_AxitX_Range_Max->setFont(font);
        spinBox_AxitX_Range_Max->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
"}"));
        spinBox_AxitX_Range_Max->setMinimum(10);
        spinBox_AxitX_Range_Max->setMaximum(1000);
        spinBox_AxitX_Range_Max->setValue(100);
        pushButton_SetConfigChart = new QPushButton(tab);
        pushButton_SetConfigChart->setObjectName(QString::fromUtf8("pushButton_SetConfigChart"));
        pushButton_SetConfigChart->setGeometry(QRect(90, 130, 371, 41));
        pushButton_SetConfigChart->setFont(font);
        pushButton_SetConfigChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(380, 40, 41, 22));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(123, 40, 141, 22));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime = new QPushButton(tab_3);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(430, 20, 121, 61));
        pushButton_SetSampleTime->setFont(font2);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        spinBox_SampleTime = new QSpinBox(tab_3);
        spinBox_SampleTime->setObjectName(QString::fromUtf8("spinBox_SampleTime"));
        spinBox_SampleTime->setGeometry(QRect(263, 10, 111, 81));
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
        spinBox_SampleTime->setMinimum(1);
        spinBox_SampleTime->setMaximum(9999999);
        spinBox_SampleTime->setValue(100);
        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 100, 541, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        radioButton_typeCalib = new QRadioButton(tab_3);
        radioButton_typeCalib->setObjectName(QString::fromUtf8("radioButton_typeCalib"));
        radioButton_typeCalib->setGeometry(QRect(256, 133, 171, 27));
        radioButton_typeCalib->setFont(font);
        radioButton_typeCalib->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_typeCalib->setChecked(false);
        pushButton_Calib = new QPushButton(tab_3);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(430, 125, 121, 61));
        pushButton_Calib->setFont(font2);
        pushButton_Calib->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_calibInfo = new QLabel(tab_3);
        label_calibInfo->setObjectName(QString::fromUtf8("label_calibInfo"));
        label_calibInfo->setGeometry(QRect(256, 156, 171, 22));
        label_calibInfo->setFont(font3);
        label_calibInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        label_60 = new QLabel(tab_3);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(30, 145, 95, 20));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        label_60->setFont(font5);
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_Display_Car_Pre_F1 = new QSpinBox(tab_3);
        spinBox_Display_Car_Pre_F1->setObjectName(QString::fromUtf8("spinBox_Display_Car_Pre_F1"));
        spinBox_Display_Car_Pre_F1->setGeometry(QRect(130, 120, 71, 71));
        spinBox_Display_Car_Pre_F1->setFont(font5);
        spinBox_Display_Car_Pre_F1->setStyleSheet(QString::fromUtf8("QSpinBox\n"
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
        spinBox_Display_Car_Pre_F1->setAlignment(Qt::AlignCenter);
        spinBox_Display_Car_Pre_F1->setMinimum(0);
        spinBox_Display_Car_Pre_F1->setMaximum(4);
        spinBox_Display_Car_Pre_F1->setValue(3);
        tabWidget->addTab(tab_3, QString());
        pushButton_Cancel = new QPushButton(Module_MOD1101);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(1120, 660, 151, 41));
        pushButton_Cancel->setFont(font2);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame = new QFrame(Module_MOD1101);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(610, 480, 491, 221));
        frame->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_Previous = new QPushButton(frame);
        pushButton_Previous->setObjectName(QString::fromUtf8("pushButton_Previous"));
        pushButton_Previous->setGeometry(QRect(20, 110, 140, 80));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        pushButton_Previous->setFont(font6);
        pushButton_Previous->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(255, 255, 127);"));
        pushButton_Stop = new QPushButton(frame);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(175, 110, 140, 80));
        pushButton_Stop->setFont(font6);
        pushButton_Stop->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(170, 0, 0);"));
        pushButton_Next = new QPushButton(frame);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(330, 110, 140, 80));
        pushButton_Next->setFont(font6);
        pushButton_Next->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 170, 0);"));
        comboBox_SelectSample = new QComboBox(frame);
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->addItem(QString());
        comboBox_SelectSample->setObjectName(QString::fromUtf8("comboBox_SelectSample"));
        comboBox_SelectSample->setGeometry(QRect(20, 20, 451, 41));
        QFont font7;
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setItalic(true);
        comboBox_SelectSample->setFont(font7);
        comboBox_SelectSample->setLayoutDirection(Qt::LeftToRight);
        comboBox_SelectSample->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_SelectSample->setEditable(false);
        label_MotorStatus = new QLabel(frame);
        label_MotorStatus->setObjectName(QString::fromUtf8("label_MotorStatus"));
        label_MotorStatus->setGeometry(QRect(20, 80, 451, 22));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setItalic(true);
        label_MotorStatus->setFont(font8);
        label_MotorStatus->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"color: rgb(255, 0, 0);"));
        pushButton_SaveData = new QPushButton(Module_MOD1101);
        pushButton_SaveData->setObjectName(QString::fromUtf8("pushButton_SaveData"));
        pushButton_SaveData->setGeometry(QRect(1120, 550, 151, 41));
        pushButton_SaveData->setFont(font2);
        pushButton_SaveData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_OpenData = new QPushButton(Module_MOD1101);
        pushButton_OpenData->setObjectName(QString::fromUtf8("pushButton_OpenData"));
        pushButton_OpenData->setGeometry(QRect(1120, 500, 151, 41));
        pushButton_OpenData->setFont(font2);
        pushButton_OpenData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_trackLine = new QFrame(Module_MOD1101);
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
        pushButton_TrackLine_Yax->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/MFS0103_Track_yax.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Yax->setIcon(icon1);
        pushButton_TrackLine_Yax->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Default = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Default->setObjectName(QString::fromUtf8("pushButton_TrackLine_Default"));
        pushButton_TrackLine_Default->setGeometry(QRect(2, 2, 27, 27));
        pushButton_TrackLine_Default->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/MFS0103_Track_D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Default->setIcon(icon2);
        pushButton_TrackLine_Default->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Tooltip = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Tooltip->setObjectName(QString::fromUtf8("pushButton_TrackLine_Tooltip"));
        pushButton_TrackLine_Tooltip->setGeometry(QRect(30, 2, 27, 27));
        pushButton_TrackLine_Tooltip->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/MFS0103_Track_T.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Tooltip->setIcon(icon3);
        pushButton_TrackLine_Tooltip->setIconSize(QSize(25, 25));
        frame_setChart = new QFrame(Module_MOD1101);
        frame_setChart->setObjectName(QString::fromUtf8("frame_setChart"));
        frame_setChart->setGeometry(QRect(860, 430, 411, 31));
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
        pushButton_ClearChart->setFont(font2);
        pushButton_ClearChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        retranslateUi(Module_MOD1101);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Module_MOD1101);
    } // setupUi

    void retranslateUi(QWidget *Module_MOD1101)
    {
        Module_MOD1101->setWindowTitle(QCoreApplication::translate("Module_MOD1101", "Form", nullptr));
        label->setText(QCoreApplication::translate("Module_MOD1101", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t:", nullptr));
        label_3->setText(QCoreApplication::translate("Module_MOD1101", "Gi\303\241 tr\341\273\213 trung b\303\254nh:", nullptr));
        label_2->setText(QCoreApplication::translate("Module_MOD1101", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t:", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Module_MOD1101", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Module_MOD1101", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Module_MOD1101", "0", nullptr));
        pushButton_getSamples->setText(QCoreApplication::translate("Module_MOD1101", "B\341\272\257t \304\221\341\272\247u", nullptr));
        label_sampleInfo->setText(QCoreApplication::translate("Module_MOD1101", "C\303\241c tham s\341\273\221 c\306\241 b\341\272\243n", nullptr));
        pushButton_SetZero->setText(QCoreApplication::translate("Module_MOD1101", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m 0 (Zero)", nullptr));
        checkBox_setMathAvg->setText(QCoreApplication::translate("Module_MOD1101", "S\341\273\255 d\341\273\245ng gi\303\241 tr\341\273\213 trung b\303\254nh c\341\273\231ng", nullptr));
        comboBox_Unit->setItemText(0, QCoreApplication::translate("Module_MOD1101", "\304\220o l\341\273\261c (N - Newton)", nullptr));
        comboBox_Unit->setItemText(1, QCoreApplication::translate("Module_MOD1101", "\304\220o kh\341\273\221i l\306\260\341\273\243ng (G - Gram)", nullptr));
        comboBox_Unit->setItemText(2, QCoreApplication::translate("Module_MOD1101", "\304\220o kh\341\273\221i l\306\260\341\273\243ng (Kg - Kilogram)", nullptr));
        comboBox_Unit->setItemText(3, QCoreApplication::translate("Module_MOD1101", "\304\220o tr\341\273\215ng l\306\260\341\273\243ng (N - Newton)", nullptr));

        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor), QCoreApplication::translate("Module_MOD1101", "     \304\220i\341\273\201u khi\341\273\203n     ", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_4->setText(QCoreApplication::translate("Module_MOD1101", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_6->setText(QCoreApplication::translate("Module_MOD1101", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_7->setText(QCoreApplication::translate("Module_MOD1101", "M\303\243 s\303\252-ri:", nullptr));
        label_5->setText(QCoreApplication::translate("Module_MOD1101", "M\303\264 t\341\272\243:", nullptr));
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Module_MOD1101", "       Thi\341\272\277t b\341\273\213       ", nullptr));
        label_15->setText(QCoreApplication::translate("Module_MOD1101", "Tr\341\273\245c Y - Th\341\272\245p", nullptr));
        label_16->setText(QCoreApplication::translate("Module_MOD1101", "Tr\341\273\245c Y - Cao", nullptr));
        label_17->setText(QCoreApplication::translate("Module_MOD1101", "S\341\273\221 l\306\260\341\273\243ng m\341\272\253u (tr\341\273\245c X):", nullptr));
        pushButton_SetConfigChart->setText(QCoreApplication::translate("Module_MOD1101", "C\303\240i \304\221\341\272\267t \304\221\341\273\223 th\341\273\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Module_MOD1101", "       \304\220\341\273\223 th\341\273\213       ", nullptr));
        label_12->setText(QCoreApplication::translate("Module_MOD1101", "(ms)", nullptr));
        label_11->setText(QCoreApplication::translate("Module_MOD1101", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Module_MOD1101", "C\303\240i \304\221\341\272\267t", nullptr));
        radioButton_typeCalib->setText(QCoreApplication::translate("Module_MOD1101", "Hi\341\273\207u chu\341\272\251n 1 \304\221i\341\273\203m", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Module_MOD1101", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_calibInfo->setText(QCoreApplication::translate("Module_MOD1101", "(ch\306\260a hi\341\273\207u chu\341\272\251n)", nullptr));
        label_60->setText(QCoreApplication::translate("Module_MOD1101", "\304\220\341\273\231 ph\303\242n gi\341\272\243i:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Module_MOD1101", "       C\303\240i \304\221\341\272\267t       ", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Module_MOD1101", "Tho\303\241t", nullptr));
        pushButton_Previous->setText(QCoreApplication::translate("Module_MOD1101", "L\303\271i", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("Module_MOD1101", "D\341\273\253ng", nullptr));
        pushButton_Next->setText(QCoreApplication::translate("Module_MOD1101", "Ti\341\272\277n", nullptr));
        comboBox_SelectSample->setItemText(0, QCoreApplication::translate("Module_MOD1101", "L\341\272\245y m\341\272\253u t\341\273\261 \304\221\341\273\231ng", nullptr));
        comboBox_SelectSample->setItemText(1, QCoreApplication::translate("Module_MOD1101", "L\341\272\245y m\341\272\253u khi \304\221\341\273\231ng c\306\241 ch\341\272\241y \"ti\341\272\277n\"", nullptr));
        comboBox_SelectSample->setItemText(2, QCoreApplication::translate("Module_MOD1101", "L\341\272\245y m\341\272\253u so s\303\241nh (3 \304\221\306\260\341\273\235ng \304\221\341\273\223 th\341\273\213)", nullptr));

        label_MotorStatus->setText(QCoreApplication::translate("Module_MOD1101", "L\341\273\227i k\341\272\277t n\341\273\221i \304\221\341\272\277n b\341\273\231 \304\221i\341\273\201u khi\341\273\203n \304\221\341\273\231ng c\306\241 !", nullptr));
        pushButton_SaveData->setText(QCoreApplication::translate("Module_MOD1101", "Ghi d\341\273\257 li\341\273\207u", nullptr));
        pushButton_OpenData->setText(QCoreApplication::translate("Module_MOD1101", "M\341\273\237 b\341\272\243n ghi", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setToolTip(QCoreApplication::translate("Module_MOD1101", "t\303\255nh h\341\273\207 s\341\273\221 g\303\263c y=ax", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setToolTip(QCoreApplication::translate("Module_MOD1101", "tr\341\273\245c t\341\273\215a \304\221\341\273\231 \341\272\243o", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setToolTip(QCoreApplication::translate("Module_MOD1101", "b\341\272\257t \304\221i\341\273\203m", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setText(QString());
        radioButton_Continuously->setText(QCoreApplication::translate("Module_MOD1101", "\304\220\341\273\223 th\341\273\213 li\303\252n t\341\273\245c", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Module_MOD1101", "\304\220\341\273\223 th\341\273\213 t\303\255ch l\305\251y", nullptr));
        pushButton_ClearChart->setText(QCoreApplication::translate("Module_MOD1101", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Module_MOD1101: public Ui_Module_MOD1101 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_MOD1101_H
