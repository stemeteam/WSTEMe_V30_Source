/********************************************************************************
** Form generated from reading UI file 'vchart_zoom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCHART_ZOOM_H
#define UI_VCHART_ZOOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vchart_Zoom
{
public:
    QFrame *frame_Chart;
    QTabWidget *tabWidget;
    QWidget *tab_Infor;
    QLCDNumber *lcdNumber_Value;
    QGroupBox *groupBox_Analysis;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ValueMax;
    QLabel *label_ValueAvg;
    QLabel *label_ValueMin;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Device_Name;
    QLabel *label_Device_Type;
    QLabel *label_Device_SN;
    QLabel *label_deviceUnit;
    QWidget *tab;
    QSpinBox *spinBox_AxitX_Range_Max;
    QLabel *label_17;
    QLabel *label_16;
    QSpinBox *spinBox_AxisY_Range_Min;
    QSpinBox *spinBox_AxisY_Range_Max;
    QPushButton *pushButton_SetConfigChart;
    QLabel *label_15;
    QWidget *tab_2;
    QSpinBox *spinBox_SampleTime;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_SetSampleTime;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_SaveData;
    QPushButton *pushButton_OpenData;
    QFrame *frame;
    QPushButton *pushButton_Stop;
    QFrame *frame_setChart;
    QRadioButton *radioButton_Continuously;
    QRadioButton *radioButton_Accumulation;
    QPushButton *pushButton_ClearChart;
    QFrame *frame_trackLine;
    QPushButton *pushButton_TrackLine_Yax;
    QPushButton *pushButton_TrackLine_Default;
    QPushButton *pushButton_TrackLine_Tooltip;

    void setupUi(QWidget *Vchart_Zoom)
    {
        if (Vchart_Zoom->objectName().isEmpty())
            Vchart_Zoom->setObjectName(QString::fromUtf8("Vchart_Zoom"));
        Vchart_Zoom->resize(1280, 710);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/ChartZoom_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Vchart_Zoom->setWindowIcon(icon);
        Vchart_Zoom->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame_Chart = new QFrame(Vchart_Zoom);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(10, 10, 1260, 421));
        frame_Chart->setStyleSheet(QString::fromUtf8("QFrame { \n"
"border: 1px solid #C0C0C0;\n"
"}"));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(Vchart_Zoom);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 470, 701, 231));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tab_Infor = new QWidget();
        tab_Infor->setObjectName(QString::fromUtf8("tab_Infor"));
        lcdNumber_Value = new QLCDNumber(tab_Infor);
        lcdNumber_Value->setObjectName(QString::fromUtf8("lcdNumber_Value"));
        lcdNumber_Value->setGeometry(QRect(20, 10, 301, 51));
        lcdNumber_Value->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 0, 0);"));
        lcdNumber_Value->setFrameShape(QFrame::WinPanel);
        lcdNumber_Value->setLineWidth(1);
        lcdNumber_Value->setSmallDecimalPoint(false);
        lcdNumber_Value->setDigitCount(7);
        lcdNumber_Value->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Value->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Value->setProperty("intValue", QVariant(0));
        groupBox_Analysis = new QGroupBox(tab_Infor);
        groupBox_Analysis->setObjectName(QString::fromUtf8("groupBox_Analysis"));
        groupBox_Analysis->setGeometry(QRect(350, 10, 341, 151));
        groupBox_Analysis->setFont(font);
        groupBox_Analysis->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        groupBox_Analysis->setFlat(false);
        verticalLayoutWidget_2 = new QWidget(groupBox_Analysis);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(220, 40, 101, 92));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_ValueMax = new QLabel(verticalLayoutWidget_2);
        label_ValueMax->setObjectName(QString::fromUtf8("label_ValueMax"));
        QFont font1;
        font1.setPointSize(12);
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

        verticalLayoutWidget = new QWidget(groupBox_Analysis);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 40, 150, 92));
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

        verticalLayoutWidget_3 = new QWidget(tab_Infor);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 90, 70, 92));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_6);

        verticalLayoutWidget_4 = new QWidget(tab_Infor);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(99, 90, 221, 92));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Device_Name = new QLabel(verticalLayoutWidget_4);
        label_Device_Name->setObjectName(QString::fromUtf8("label_Device_Name"));
        QFont font2;
        font2.setPointSize(10);
        label_Device_Name->setFont(font2);
        label_Device_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(label_Device_Name);

        label_Device_Type = new QLabel(verticalLayoutWidget_4);
        label_Device_Type->setObjectName(QString::fromUtf8("label_Device_Type"));
        label_Device_Type->setFont(font2);
        label_Device_Type->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(label_Device_Type);

        label_Device_SN = new QLabel(verticalLayoutWidget_4);
        label_Device_SN->setObjectName(QString::fromUtf8("label_Device_SN"));
        label_Device_SN->setFont(font2);
        label_Device_SN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(label_Device_SN);

        label_deviceUnit = new QLabel(tab_Infor);
        label_deviceUnit->setObjectName(QString::fromUtf8("label_deviceUnit"));
        label_deviceUnit->setGeometry(QRect(20, 60, 301, 26));
        label_deviceUnit->setFont(font);
        label_deviceUnit->setLayoutDirection(Qt::LeftToRight);
        label_deviceUnit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 170, 127);"));
        label_deviceUnit->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_Infor, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        spinBox_AxitX_Range_Max = new QSpinBox(tab);
        spinBox_AxitX_Range_Max->setObjectName(QString::fromUtf8("spinBox_AxitX_Range_Max"));
        spinBox_AxitX_Range_Max->setGeometry(QRect(410, 30, 111, 81));
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
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(390, 5, 161, 22));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(230, 5, 91, 22));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_AxisY_Range_Min = new QSpinBox(tab);
        spinBox_AxisY_Range_Min->setObjectName(QString::fromUtf8("spinBox_AxisY_Range_Min"));
        spinBox_AxisY_Range_Min->setGeometry(QRect(30, 30, 111, 81));
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
        spinBox_AxisY_Range_Max->setGeometry(QRect(220, 30, 111, 81));
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
        pushButton_SetConfigChart = new QPushButton(tab);
        pushButton_SetConfigChart->setObjectName(QString::fromUtf8("pushButton_SetConfigChart"));
        pushButton_SetConfigChart->setGeometry(QRect(90, 125, 371, 51));
        pushButton_SetConfigChart->setFont(font1);
        pushButton_SetConfigChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 5, 101, 22));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        spinBox_SampleTime = new QSpinBox(tab_2);
        spinBox_SampleTime->setObjectName(QString::fromUtf8("spinBox_SampleTime"));
        spinBox_SampleTime->setGeometry(QRect(170, 40, 111, 81));
        spinBox_SampleTime->setFont(font);
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
"}"));
        spinBox_SampleTime->setMinimum(1);
        spinBox_SampleTime->setMaximum(9999999);
        spinBox_SampleTime->setValue(100);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 70, 141, 22));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 65, 41, 22));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime = new QPushButton(tab_2);
        pushButton_SetSampleTime->setObjectName(QString::fromUtf8("pushButton_SetSampleTime"));
        pushButton_SetSampleTime->setGeometry(QRect(330, 50, 151, 61));
        pushButton_SetSampleTime->setFont(font1);
        pushButton_SetSampleTime->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget->addTab(tab_2, QString());
        pushButton_Cancel = new QPushButton(Vchart_Zoom);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(1100, 660, 171, 41));
        pushButton_Cancel->setFont(font1);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_SaveData = new QPushButton(Vchart_Zoom);
        pushButton_SaveData->setObjectName(QString::fromUtf8("pushButton_SaveData"));
        pushButton_SaveData->setGeometry(QRect(1100, 550, 171, 41));
        pushButton_SaveData->setFont(font1);
        pushButton_SaveData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_OpenData = new QPushButton(Vchart_Zoom);
        pushButton_OpenData->setObjectName(QString::fromUtf8("pushButton_OpenData"));
        pushButton_OpenData->setGeometry(QRect(1100, 500, 171, 41));
        pushButton_OpenData->setFont(font1);
        pushButton_OpenData->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame = new QFrame(Vchart_Zoom);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(730, 500, 351, 121));
        frame->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_Stop = new QPushButton(frame);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(29, 30, 291, 61));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        pushButton_Stop->setFont(font3);
        pushButton_Stop->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(170, 0, 0);"));
        frame_setChart = new QFrame(Vchart_Zoom);
        frame_setChart->setObjectName(QString::fromUtf8("frame_setChart"));
        frame_setChart->setGeometry(QRect(859, 430, 411, 31));
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
        pushButton_ClearChart->setFont(font1);
        pushButton_ClearChart->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_trackLine = new QFrame(Vchart_Zoom);
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
        pushButton_TrackLine_Yax->setFont(font3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/MFS0103_Track_yax.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Yax->setIcon(icon1);
        pushButton_TrackLine_Yax->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Default = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Default->setObjectName(QString::fromUtf8("pushButton_TrackLine_Default"));
        pushButton_TrackLine_Default->setGeometry(QRect(2, 2, 27, 27));
        pushButton_TrackLine_Default->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/MFS0103_Track_D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Default->setIcon(icon2);
        pushButton_TrackLine_Default->setIconSize(QSize(25, 25));
        pushButton_TrackLine_Tooltip = new QPushButton(frame_trackLine);
        pushButton_TrackLine_Tooltip->setObjectName(QString::fromUtf8("pushButton_TrackLine_Tooltip"));
        pushButton_TrackLine_Tooltip->setGeometry(QRect(30, 2, 27, 27));
        pushButton_TrackLine_Tooltip->setFont(font3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/MFS0103_Track_T.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TrackLine_Tooltip->setIcon(icon3);
        pushButton_TrackLine_Tooltip->setIconSize(QSize(25, 25));

        retranslateUi(Vchart_Zoom);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Vchart_Zoom);
    } // setupUi

    void retranslateUi(QWidget *Vchart_Zoom)
    {
        Vchart_Zoom->setWindowTitle(QCoreApplication::translate("Vchart_Zoom", "Ph\303\242n t\303\255ch", nullptr));
        groupBox_Analysis->setTitle(QCoreApplication::translate("Vchart_Zoom", "\304\220\303\241nh gi\303\241 ph\303\251p \304\221o tr\303\252n 0 m\341\272\253u \304\221o:", nullptr));
        label_ValueMax->setText(QCoreApplication::translate("Vchart_Zoom", "0", nullptr));
        label_ValueAvg->setText(QCoreApplication::translate("Vchart_Zoom", "0", nullptr));
        label_ValueMin->setText(QCoreApplication::translate("Vchart_Zoom", "0", nullptr));
        label->setText(QCoreApplication::translate("Vchart_Zoom", "Gi\303\241 tr\341\273\213 \304\221o l\341\273\233n nh\341\272\245t:", nullptr));
        label_3->setText(QCoreApplication::translate("Vchart_Zoom", "Gi\303\241 tr\341\273\213 \304\221o trung b\303\254nh:", nullptr));
        label_2->setText(QCoreApplication::translate("Vchart_Zoom", "Gi\303\241 tr\341\273\213 \304\221o nh\341\273\217 nh\341\272\245t::", nullptr));
        label_4->setText(QCoreApplication::translate("Vchart_Zoom", "T\303\252n:", nullptr));
        label_5->setText(QCoreApplication::translate("Vchart_Zoom", "Ki\341\273\203u:", nullptr));
        label_6->setText(QCoreApplication::translate("Vchart_Zoom", "M\303\243 S\303\252-ri:", nullptr));
        label_Device_Name->setText(QString());
        label_Device_Type->setText(QString());
        label_Device_SN->setText(QString());
        label_deviceUnit->setText(QCoreApplication::translate("Vchart_Zoom", "\304\220\306\241n v\341\273\213 \304\221o", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor), QCoreApplication::translate("Vchart_Zoom", "               Hi\341\273\203n th\341\273\213               ", nullptr));
        label_17->setText(QCoreApplication::translate("Vchart_Zoom", "S\341\273\221 l\306\260\341\273\243ng m\341\272\253u (tr\341\273\245c X):", nullptr));
        label_16->setText(QCoreApplication::translate("Vchart_Zoom", "Tr\341\273\245c Y - Cao", nullptr));
        pushButton_SetConfigChart->setText(QCoreApplication::translate("Vchart_Zoom", "C\303\240i \304\221\341\272\267t \304\221\341\273\223 th\341\273\213", nullptr));
        label_15->setText(QCoreApplication::translate("Vchart_Zoom", "Tr\341\273\245c Y - Th\341\272\245p", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Vchart_Zoom", "              \304\220\341\273\223 th\341\273\213               ", nullptr));
        label_13->setText(QCoreApplication::translate("Vchart_Zoom", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        label_14->setText(QCoreApplication::translate("Vchart_Zoom", "(ms)", nullptr));
        pushButton_SetSampleTime->setText(QCoreApplication::translate("Vchart_Zoom", "C\303\240i \304\221\341\272\267t", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Vchart_Zoom", "               C\303\240i \304\221\341\272\267t               ", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Vchart_Zoom", "Tho\303\241t", nullptr));
        pushButton_SaveData->setText(QCoreApplication::translate("Vchart_Zoom", "Ghi d\341\273\257 li\341\273\207u", nullptr));
        pushButton_OpenData->setText(QCoreApplication::translate("Vchart_Zoom", "M\341\273\237 b\341\272\243n ghi", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("Vchart_Zoom", "D\341\273\253ng", nullptr));
        radioButton_Continuously->setText(QCoreApplication::translate("Vchart_Zoom", "\304\220\341\273\223 th\341\273\213 li\303\252n t\341\273\245c", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Vchart_Zoom", "\304\220\341\273\223 th\341\273\213 t\303\255ch l\305\251y", nullptr));
        pushButton_ClearChart->setText(QCoreApplication::translate("Vchart_Zoom", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setToolTip(QCoreApplication::translate("Vchart_Zoom", "t\303\255nh h\341\273\207 s\341\273\221 g\303\263c y=ax", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Yax->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setToolTip(QCoreApplication::translate("Vchart_Zoom", "tr\341\273\245c t\341\273\215a \304\221\341\273\231 \341\272\243o", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Default->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setToolTip(QCoreApplication::translate("Vchart_Zoom", "b\341\272\257t \304\221i\341\273\203m", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TrackLine_Tooltip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Vchart_Zoom: public Ui_Vchart_Zoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCHART_ZOOM_H
