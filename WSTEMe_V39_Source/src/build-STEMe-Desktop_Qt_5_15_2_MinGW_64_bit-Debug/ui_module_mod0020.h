/********************************************************************************
** Form generated from reading UI file 'module_mod0020.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_MOD0020_H
#define UI_MODULE_MOD0020_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Module_MOD0020
{
public:
    QFrame *frame_Chart;
    QPushButton *pushButton_ClearChart;
    QTabWidget *tabWidget;
    QWidget *tab_Infor_2;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_18;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_ValueMax_2;
    QLabel *label_ValueAvg_2;
    QLabel *label_ValueMin_2;
    QLCDNumber *lcdNumber_Test;
    QPushButton *pushButton_Zero;
    QLineEdit *lineEdit_RatioValue;
    QLabel *label_11;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_Name_2;
    QLabel *label_Address_2;
    QLabel *label_SerialNumber_2;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_Description_2;
    QWidget *tab_5;
    QLabel *label_23;
    QLabel *label_24;
    QSpinBox *spinBox_AxisY_Range_Min_2;
    QSpinBox *spinBox_AxisY_Range_Max_2;
    QLabel *label_25;
    QSpinBox *spinBox_AxitX_Range_Max_2;
    QPushButton *pushButton_SetConfigChart_2;
    QWidget *tab_6;
    QLabel *label_26;
    QLineEdit *lineEdit_Calib1_2;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *pushButton_SetSampleTime_2;
    QPushButton *pushButton_Calib_2;
    QSpinBox *spinBox_SampleTime_2;
    QLabel *label_30;
    QFrame *line_2;
    QRadioButton *radioButton_Continuously;
    QFrame *frame;
    QPushButton *pushButton_Previous_2;
    QPushButton *pushButton_Stop_2;
    QPushButton *pushButton_Next_2;
    QComboBox *comboBox_SelectSample_2;
    QPushButton *pushButton_Cancel;
    QRadioButton *radioButton_Accumulation;

    void setupUi(QWidget *Module_MOD0020)
    {
        if (Module_MOD0020->objectName().isEmpty())
            Module_MOD0020->setObjectName(QString::fromUtf8("Module_MOD0020"));
        Module_MOD0020->resize(1280, 710);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/TST0020_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Module_MOD0020->setWindowIcon(icon);
        Module_MOD0020->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame_Chart = new QFrame(Module_MOD0020);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(10, 10, 1260, 480));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        pushButton_ClearChart = new QPushButton(Module_MOD0020);
        pushButton_ClearChart->setObjectName(QString::fromUtf8("pushButton_ClearChart"));
        pushButton_ClearChart->setGeometry(QRect(1120, 520, 151, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        pushButton_ClearChart->setFont(font);
        tabWidget = new QTabWidget(Module_MOD0020);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 490, 581, 211));
        tabWidget->setFont(font);
        tab_Infor_2 = new QWidget();
        tab_Infor_2->setObjectName(QString::fromUtf8("tab_Infor_2"));
        verticalLayoutWidget_6 = new QWidget(tab_Infor_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(320, 10, 128, 92));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font1;
        font1.setBold(true);
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_10);

        label_14 = new QLabel(verticalLayoutWidget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_14);

        label_18 = new QLabel(verticalLayoutWidget_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_6->addWidget(label_18);

        verticalLayoutWidget_7 = new QWidget(tab_Infor_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(460, 10, 101, 92));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_ValueMax_2 = new QLabel(verticalLayoutWidget_7);
        label_ValueMax_2->setObjectName(QString::fromUtf8("label_ValueMax_2"));
        label_ValueMax_2->setFont(font);
        label_ValueMax_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_7->addWidget(label_ValueMax_2);

        label_ValueAvg_2 = new QLabel(verticalLayoutWidget_7);
        label_ValueAvg_2->setObjectName(QString::fromUtf8("label_ValueAvg_2"));
        label_ValueAvg_2->setFont(font);
        label_ValueAvg_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_7->addWidget(label_ValueAvg_2);

        label_ValueMin_2 = new QLabel(verticalLayoutWidget_7);
        label_ValueMin_2->setObjectName(QString::fromUtf8("label_ValueMin_2"));
        label_ValueMin_2->setFont(font);
        label_ValueMin_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        verticalLayout_7->addWidget(label_ValueMin_2);

        lcdNumber_Test = new QLCDNumber(tab_Infor_2);
        lcdNumber_Test->setObjectName(QString::fromUtf8("lcdNumber_Test"));
        lcdNumber_Test->setGeometry(QRect(20, 10, 281, 51));
        lcdNumber_Test->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 0, 0);"));
        lcdNumber_Test->setFrameShape(QFrame::WinPanel);
        lcdNumber_Test->setLineWidth(1);
        lcdNumber_Test->setSmallDecimalPoint(false);
        lcdNumber_Test->setDigitCount(7);
        lcdNumber_Test->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_Test->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_Test->setProperty("intValue", QVariant(0));
        pushButton_Zero = new QPushButton(tab_Infor_2);
        pushButton_Zero->setObjectName(QString::fromUtf8("pushButton_Zero"));
        pushButton_Zero->setGeometry(QRect(20, 110, 281, 51));
        pushButton_Zero->setFont(font1);
        lineEdit_RatioValue = new QLineEdit(tab_Infor_2);
        lineEdit_RatioValue->setObjectName(QString::fromUtf8("lineEdit_RatioValue"));
        lineEdit_RatioValue->setGeometry(QRect(210, 70, 91, 30));
        lineEdit_RatioValue->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_Infor_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 70, 181, 26));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_Infor_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayoutWidget_8 = new QWidget(tab_4);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(150, 10, 291, 101));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_Name_2 = new QLabel(verticalLayoutWidget_8);
        label_Name_2->setObjectName(QString::fromUtf8("label_Name_2"));
        label_Name_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_Name_2);

        label_Address_2 = new QLabel(verticalLayoutWidget_8);
        label_Address_2->setObjectName(QString::fromUtf8("label_Address_2"));
        label_Address_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_Address_2);

        label_SerialNumber_2 = new QLabel(verticalLayoutWidget_8);
        label_SerialNumber_2->setObjectName(QString::fromUtf8("label_SerialNumber_2"));
        label_SerialNumber_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(label_SerialNumber_2);

        verticalLayoutWidget_9 = new QWidget(tab_4);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(10, 10, 111, 131));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(verticalLayoutWidget_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_19);

        label_20 = new QLabel(verticalLayoutWidget_9);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_20);

        label_21 = new QLabel(verticalLayoutWidget_9);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_21);

        label_22 = new QLabel(verticalLayoutWidget_9);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(label_22);

        verticalLayoutWidget_10 = new QWidget(tab_4);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(150, 110, 291, 61));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_Description_2 = new QLabel(verticalLayoutWidget_10);
        label_Description_2->setObjectName(QString::fromUtf8("label_Description_2"));
        label_Description_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_10->addWidget(label_Description_2);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 10, 101, 22));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_24 = new QLabel(tab_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(150, 10, 91, 22));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_AxisY_Range_Min_2 = new QSpinBox(tab_5);
        spinBox_AxisY_Range_Min_2->setObjectName(QString::fromUtf8("spinBox_AxisY_Range_Min_2"));
        spinBox_AxisY_Range_Min_2->setGeometry(QRect(20, 35, 91, 81));
        spinBox_AxisY_Range_Min_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_AxisY_Range_Min_2->setMinimum(-9999999);
        spinBox_AxisY_Range_Min_2->setMaximum(9999999);
        spinBox_AxisY_Range_Min_2->setValue(-10);
        spinBox_AxisY_Range_Max_2 = new QSpinBox(tab_5);
        spinBox_AxisY_Range_Max_2->setObjectName(QString::fromUtf8("spinBox_AxisY_Range_Max_2"));
        spinBox_AxisY_Range_Max_2->setGeometry(QRect(150, 35, 91, 81));
        spinBox_AxisY_Range_Max_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_AxisY_Range_Max_2->setMinimum(-9999999);
        spinBox_AxisY_Range_Max_2->setMaximum(9999999);
        spinBox_AxisY_Range_Max_2->setValue(10);
        label_25 = new QLabel(tab_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(260, 10, 161, 22));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_AxitX_Range_Max_2 = new QSpinBox(tab_5);
        spinBox_AxitX_Range_Max_2->setObjectName(QString::fromUtf8("spinBox_AxitX_Range_Max_2"));
        spinBox_AxitX_Range_Max_2->setGeometry(QRect(280, 35, 111, 81));
        spinBox_AxitX_Range_Max_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_AxitX_Range_Max_2->setMinimum(10);
        spinBox_AxitX_Range_Max_2->setMaximum(1000);
        spinBox_AxitX_Range_Max_2->setValue(100);
        pushButton_SetConfigChart_2 = new QPushButton(tab_5);
        pushButton_SetConfigChart_2->setObjectName(QString::fromUtf8("pushButton_SetConfigChart_2"));
        pushButton_SetConfigChart_2->setGeometry(QRect(20, 124, 371, 41));
        pushButton_SetConfigChart_2->setFont(font1);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_26 = new QLabel(tab_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(260, 115, 41, 22));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_Calib1_2 = new QLineEdit(tab_6);
        lineEdit_Calib1_2->setObjectName(QString::fromUtf8("lineEdit_Calib1_2"));
        lineEdit_Calib1_2->setGeometry(QRect(170, 50, 81, 30));
        lineEdit_Calib1_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_27 = new QLabel(tab_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(261, 54, 31, 22));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_28 = new QLabel(tab_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(40, 54, 121, 22));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_29 = new QLabel(tab_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(20, 115, 211, 22));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_SetSampleTime_2 = new QPushButton(tab_6);
        pushButton_SetSampleTime_2->setObjectName(QString::fromUtf8("pushButton_SetSampleTime_2"));
        pushButton_SetSampleTime_2->setGeometry(QRect(300, 110, 111, 31));
        pushButton_Calib_2 = new QPushButton(tab_6);
        pushButton_Calib_2->setObjectName(QString::fromUtf8("pushButton_Calib_2"));
        pushButton_Calib_2->setGeometry(QRect(300, 50, 111, 30));
        spinBox_SampleTime_2 = new QSpinBox(tab_6);
        spinBox_SampleTime_2->setObjectName(QString::fromUtf8("spinBox_SampleTime_2"));
        spinBox_SampleTime_2->setGeometry(QRect(170, 100, 81, 61));
        spinBox_SampleTime_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_SampleTime_2->setMinimum(10);
        spinBox_SampleTime_2->setMaximum(9999999);
        spinBox_SampleTime_2->setValue(100);
        label_30 = new QLabel(tab_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 20, 141, 22));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2 = new QFrame(tab_6);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 80, 391, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_6, QString());
        radioButton_Continuously = new QRadioButton(Module_MOD0020);
        radioButton_Continuously->setObjectName(QString::fromUtf8("radioButton_Continuously"));
        radioButton_Continuously->setGeometry(QRect(860, 490, 141, 27));
        radioButton_Continuously->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Continuously->setChecked(true);
        frame = new QFrame(Module_MOD0020);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(610, 521, 491, 180));
        frame->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_Previous_2 = new QPushButton(frame);
        pushButton_Previous_2->setObjectName(QString::fromUtf8("pushButton_Previous_2"));
        pushButton_Previous_2->setGeometry(QRect(20, 90, 140, 80));
        pushButton_Previous_2->setFont(font);
        pushButton_Previous_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        pushButton_Stop_2 = new QPushButton(frame);
        pushButton_Stop_2->setObjectName(QString::fromUtf8("pushButton_Stop_2"));
        pushButton_Stop_2->setGeometry(QRect(175, 90, 140, 80));
        pushButton_Stop_2->setFont(font);
        pushButton_Stop_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        pushButton_Next_2 = new QPushButton(frame);
        pushButton_Next_2->setObjectName(QString::fromUtf8("pushButton_Next_2"));
        pushButton_Next_2->setGeometry(QRect(330, 90, 140, 80));
        pushButton_Next_2->setFont(font);
        pushButton_Next_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        comboBox_SelectSample_2 = new QComboBox(frame);
        comboBox_SelectSample_2->addItem(QString());
        comboBox_SelectSample_2->addItem(QString());
        comboBox_SelectSample_2->addItem(QString());
        comboBox_SelectSample_2->setObjectName(QString::fromUtf8("comboBox_SelectSample_2"));
        comboBox_SelectSample_2->setGeometry(QRect(20, 12, 451, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        comboBox_SelectSample_2->setFont(font2);
        comboBox_SelectSample_2->setLayoutDirection(Qt::LeftToRight);
        comboBox_SelectSample_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox_SelectSample_2->setEditable(false);
        pushButton_Cancel = new QPushButton(Module_MOD0020);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(1120, 640, 151, 61));
        pushButton_Cancel->setFont(font);
        radioButton_Accumulation = new QRadioButton(Module_MOD0020);
        radioButton_Accumulation->setObjectName(QString::fromUtf8("radioButton_Accumulation"));
        radioButton_Accumulation->setGeometry(QRect(690, 490, 141, 27));
        radioButton_Accumulation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Accumulation->setChecked(false);

        retranslateUi(Module_MOD0020);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Module_MOD0020);
    } // setupUi

    void retranslateUi(QWidget *Module_MOD0020)
    {
        pushButton_ClearChart->setText(QCoreApplication::translate("Module_MOD0020", "X\303\263a \304\221\341\273\223 th\341\273\213", nullptr));
        label_10->setText(QCoreApplication::translate("Module_MOD0020", "Gi\303\241 tr\341\273\213 l\341\273\233n nh\341\272\245t:", nullptr));
        label_14->setText(QCoreApplication::translate("Module_MOD0020", "Gi\303\241 tr\341\273\213 trung b\303\254nh:", nullptr));
        label_18->setText(QCoreApplication::translate("Module_MOD0020", "Gi\303\241 tr\341\273\213 nh\341\273\217 nh\341\272\245t::", nullptr));
        label_ValueMax_2->setText(QCoreApplication::translate("Module_MOD0020", "0", nullptr));
        label_ValueAvg_2->setText(QCoreApplication::translate("Module_MOD0020", "0", nullptr));
        label_ValueMin_2->setText(QCoreApplication::translate("Module_MOD0020", "0", nullptr));
        pushButton_Zero->setText(QCoreApplication::translate("Module_MOD0020", "Thi\341\272\277t l\341\272\255p \304\221i\341\273\203m 0 (Zero)", nullptr));
        lineEdit_RatioValue->setText(QCoreApplication::translate("Module_MOD0020", "1", nullptr));
        label_11->setText(QCoreApplication::translate("Module_MOD0020", "H\341\273\207 s\341\273\221 t\341\273\267 l\341\273\207 (a) v\341\273\233i  y = ax", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Infor_2), QCoreApplication::translate("Module_MOD0020", "     \304\220i\341\273\201u khi\341\273\203n     ", nullptr));
        label_Name_2->setText(QString());
        label_Address_2->setText(QString());
        label_SerialNumber_2->setText(QString());
        label_19->setText(QCoreApplication::translate("Module_MOD0020", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_20->setText(QCoreApplication::translate("Module_MOD0020", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_21->setText(QCoreApplication::translate("Module_MOD0020", "M\303\243 s\303\252-ri:", nullptr));
        label_22->setText(QCoreApplication::translate("Module_MOD0020", "M\303\264 t\341\272\243:", nullptr));
        label_Description_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Module_MOD0020", "       Thi\341\272\277t b\341\273\213       ", nullptr));
        label_23->setText(QCoreApplication::translate("Module_MOD0020", "Tr\341\273\245c Y - Th\341\272\245p", nullptr));
        label_24->setText(QCoreApplication::translate("Module_MOD0020", "Tr\341\273\245c Y - Cao", nullptr));
        label_25->setText(QCoreApplication::translate("Module_MOD0020", "S\341\273\221 l\306\260\341\273\243ng m\341\272\253u (tr\341\273\245c X):", nullptr));
        pushButton_SetConfigChart_2->setText(QCoreApplication::translate("Module_MOD0020", "C\303\240i \304\221\341\272\267t \304\221\341\273\223 th\341\273\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Module_MOD0020", "       \304\220\341\273\223 th\341\273\213       ", nullptr));
        label_26->setText(QCoreApplication::translate("Module_MOD0020", "(ms)", nullptr));
        label_27->setText(QCoreApplication::translate("Module_MOD0020", "(N)", nullptr));
        label_28->setText(QCoreApplication::translate("Module_MOD0020", "Gi\303\241 tr\341\273\213 \304\221o chu\341\272\251n :", nullptr));
        label_29->setText(QCoreApplication::translate("Module_MOD0020", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        pushButton_SetSampleTime_2->setText(QCoreApplication::translate("Module_MOD0020", "C\303\240i \304\221\341\272\267t", nullptr));
        pushButton_Calib_2->setText(QCoreApplication::translate("Module_MOD0020", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_30->setText(QCoreApplication::translate("Module_MOD0020", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Module_MOD0020", "       C\303\240i \304\221\341\272\267t       ", nullptr));
        radioButton_Continuously->setText(QCoreApplication::translate("Module_MOD0020", "\304\220\341\273\223 th\341\273\213 li\303\252n t\341\273\245c", nullptr));
        pushButton_Previous_2->setText(QCoreApplication::translate("Module_MOD0020", "L\303\271i", nullptr));
        pushButton_Stop_2->setText(QCoreApplication::translate("Module_MOD0020", "D\341\273\253ng", nullptr));
        pushButton_Next_2->setText(QCoreApplication::translate("Module_MOD0020", "Ti\341\272\277n", nullptr));
        comboBox_SelectSample_2->setItemText(0, QCoreApplication::translate("Module_MOD0020", "L\341\272\245y m\341\272\253u t\341\273\261 \304\221\341\273\231ng", nullptr));
        comboBox_SelectSample_2->setItemText(1, QCoreApplication::translate("Module_MOD0020", "L\341\272\245y m\341\272\253u khi \304\221\341\273\231ng c\306\241 ch\341\272\241y \"ti\341\272\277n\"", nullptr));
        comboBox_SelectSample_2->setItemText(2, QCoreApplication::translate("Module_MOD0020", "L\341\272\245y m\341\272\253u so s\303\241nh (3 \304\221\306\260\341\273\235ng \304\221\341\273\223 th\341\273\213)", nullptr));

        pushButton_Cancel->setText(QCoreApplication::translate("Module_MOD0020", "Tho\303\241t", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Module_MOD0020", "\304\220\341\273\223 th\341\273\213 t\303\255ch l\305\251y", nullptr));
        (void)Module_MOD0020;
    } // retranslateUi

};

namespace Ui {
    class Module_MOD0020: public Ui_Module_MOD0020 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_MOD0020_H
