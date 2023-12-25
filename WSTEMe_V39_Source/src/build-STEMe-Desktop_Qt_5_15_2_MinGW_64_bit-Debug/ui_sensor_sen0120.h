/********************************************************************************
** Form generated from reading UI file 'sensor_sen0120.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0120_H
#define UI_SENSOR_SEN0120_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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

class Ui_Sensor_SEN0120
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Name;
    QLabel *label_Address;
    QLabel *label_SerialNumber;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Description;
    QWidget *tab_2;
    QRadioButton *radioButton_Temperature;
    QRadioButton *radioButton_Temperature_2;
    QFrame *frame_Chart;
    QWidget *tab_3;
    QLineEdit *lineEdit_Calib1;
    QLabel *label_3;
    QPushButton *pushButton_Calib_Temp;
    QLabel *label_8;
    QLineEdit *lineEdit_Calib1_Humi;
    QLabel *label_9;
    QPushButton *pushButton_Calib_Humi;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QLabel *label_13;
    QSpinBox *spinBox_SampleTimer;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLCDNumber *lcdNumber_HEART;
    QLabel *label_Unit_Heart;
    QLCDNumber *lcdNumber_SPO2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_ChartZoom;
    QLabel *label_Finger_Status;

    void setupUi(QWidget *Sensor_SEN0120)
    {
        if (Sensor_SEN0120->objectName().isEmpty())
            Sensor_SEN0120->setObjectName(QString::fromUtf8("Sensor_SEN0120"));
        Sensor_SEN0120->resize(700, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/HRS0120_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0120->setWindowIcon(icon);
        frame = new QFrame(Sensor_SEN0120);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 511));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 35, 13);\n"
"background-color: rgb(170, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 180, 640, 270));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayoutWidget = new QWidget(tab_1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 111, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_7);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(tab_1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 451, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_2);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_2);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_2);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_SerialNumber);

        verticalLayoutWidget_3 = new QWidget(tab_1);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(160, 110, 451, 151));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_3);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(label_Description);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        radioButton_Temperature = new QRadioButton(tab_2);
        radioButton_Temperature->setObjectName(QString::fromUtf8("radioButton_Temperature"));
        radioButton_Temperature->setGeometry(QRect(50, 211, 92, 18));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        radioButton_Temperature->setFont(font1);
        radioButton_Temperature->setStyleSheet(QString::fromUtf8("color: rgb(255,255, 255);"));
        radioButton_Temperature->setChecked(true);
        radioButton_Temperature_2 = new QRadioButton(tab_2);
        radioButton_Temperature_2->setObjectName(QString::fromUtf8("radioButton_Temperature_2"));
        radioButton_Temperature_2->setGeometry(QRect(200, 211, 111, 18));
        radioButton_Temperature_2->setFont(font1);
        radioButton_Temperature_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));
        frame_Chart = new QFrame(tab_2);
        frame_Chart->setObjectName(QString::fromUtf8("frame_Chart"));
        frame_Chart->setGeometry(QRect(0, 0, 633, 211));
        frame_Chart->setFrameShape(QFrame::StyledPanel);
        frame_Chart->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lineEdit_Calib1 = new QLineEdit(tab_3);
        lineEdit_Calib1->setObjectName(QString::fromUtf8("lineEdit_Calib1"));
        lineEdit_Calib1->setGeometry(QRect(200, 46, 161, 30));
        lineEdit_Calib1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 16, 251, 22));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Calib_Temp = new QPushButton(tab_3);
        pushButton_Calib_Temp->setObjectName(QString::fromUtf8("pushButton_Calib_Temp"));
        pushButton_Calib_Temp->setGeometry(QRect(431, 46, 181, 30));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 50, 161, 22));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_Calib1_Humi = new QLineEdit(tab_3);
        lineEdit_Calib1_Humi->setObjectName(QString::fromUtf8("lineEdit_Calib1_Humi"));
        lineEdit_Calib1_Humi->setGeometry(QRect(199, 90, 161, 30));
        lineEdit_Calib1_Humi->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 90, 151, 22));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Calib_Humi = new QPushButton(tab_3);
        pushButton_Calib_Humi->setObjectName(QString::fromUtf8("pushButton_Calib_Humi"));
        pushButton_Calib_Humi->setGeometry(QRect(430, 90, 181, 30));
        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 130, 591, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 140, 321, 71));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 30, 131, 22));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_SampleTimer = new QSpinBox(groupBox_2);
        spinBox_SampleTimer->setObjectName(QString::fromUtf8("spinBox_SampleTimer"));
        spinBox_SampleTimer->setGeometry(QRect(180, 11, 101, 61));
        spinBox_SampleTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_SampleTimer->setMinimum(100);
        spinBox_SampleTimer->setMaximum(99999);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 34, 31, 22));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(370, 50, 51, 22));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(370, 90, 61, 22));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_3, QString());
        lcdNumber_HEART = new QLCDNumber(frame);
        lcdNumber_HEART->setObjectName(QString::fromUtf8("lcdNumber_HEART"));
        lcdNumber_HEART->setGeometry(QRect(30, 25, 300, 90));
        lcdNumber_HEART->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 255, 255);"));
        lcdNumber_HEART->setFrameShadow(QFrame::Sunken);
        lcdNumber_HEART->setSmallDecimalPoint(false);
        lcdNumber_HEART->setDigitCount(6);
        lcdNumber_HEART->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_HEART->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_HEART->setProperty("intValue", QVariant(0));
        label_Unit_Heart = new QLabel(frame);
        label_Unit_Heart->setObjectName(QString::fromUtf8("label_Unit_Heart"));
        label_Unit_Heart->setGeometry(QRect(21, 120, 321, 22));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_Unit_Heart->setFont(font2);
        label_Unit_Heart->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Unit_Heart->setAlignment(Qt::AlignCenter);
        lcdNumber_SPO2 = new QLCDNumber(frame);
        lcdNumber_SPO2->setObjectName(QString::fromUtf8("lcdNumber_SPO2"));
        lcdNumber_SPO2->setEnabled(true);
        lcdNumber_SPO2->setGeometry(QRect(371, 25, 300, 90));
        lcdNumber_SPO2->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(0, 255, 255);"));
        lcdNumber_SPO2->setFrameShadow(QFrame::Sunken);
        lcdNumber_SPO2->setLineWidth(1);
        lcdNumber_SPO2->setSmallDecimalPoint(false);
        lcdNumber_SPO2->setDigitCount(6);
        lcdNumber_SPO2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_SPO2->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_SPO2->setProperty("intValue", QVariant(0));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(362, 120, 321, 22));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(350, 459, 321, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Apply = new QPushButton(horizontalLayoutWidget);
        pushButton_Apply->setObjectName(QString::fromUtf8("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(horizontalLayoutWidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_ChartZoom = new QPushButton(frame);
        pushButton_ChartZoom->setObjectName(QString::fromUtf8("pushButton_ChartZoom"));
        pushButton_ChartZoom->setGeometry(QRect(31, 459, 121, 30));
        label_Finger_Status = new QLabel(frame);
        label_Finger_Status->setObjectName(QString::fromUtf8("label_Finger_Status"));
        label_Finger_Status->setGeometry(QRect(30, 150, 641, 22));
        label_Finger_Status->setFont(font2);
        label_Finger_Status->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 127);"));
        label_Finger_Status->setAlignment(Qt::AlignCenter);

        retranslateUi(Sensor_SEN0120);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Sensor_SEN0120);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0120)
    {
        Sensor_SEN0120->setWindowTitle(QCoreApplication::translate("Sensor_SEN0120", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Sensor_SEN0120", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_6->setText(QCoreApplication::translate("Sensor_SEN0120", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_7->setText(QCoreApplication::translate("Sensor_SEN0120", "M\303\243 s\303\252-ri:", nullptr));
        label_5->setText(QCoreApplication::translate("Sensor_SEN0120", "M\303\264 t\341\272\243:", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("Sensor_SEN0120", "          Thi\341\272\277t b\341\273\213          ", nullptr));
        radioButton_Temperature->setText(QCoreApplication::translate("Sensor_SEN0120", "Nh\341\273\213p tim", nullptr));
        radioButton_Temperature_2->setText(QCoreApplication::translate("Sensor_SEN0120", "SPO2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Sensor_SEN0120", "          \304\220\341\273\223 th\341\273\213          ", nullptr));
        label_3->setText(QCoreApplication::translate("Sensor_SEN0120", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213.", nullptr));
        pushButton_Calib_Temp->setText(QCoreApplication::translate("Sensor_SEN0120", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_8->setText(QCoreApplication::translate("Sensor_SEN0120", "Gi\303\241 tr\341\273\213 nh\341\273\213p tim chu\341\272\251n:", nullptr));
        label_9->setText(QCoreApplication::translate("Sensor_SEN0120", "Gi\303\241 tr\341\273\213 SPO2 chu\341\272\251n:", nullptr));
        pushButton_Calib_Humi->setText(QCoreApplication::translate("Sensor_SEN0120", "Hi\341\273\207u chu\341\272\251n", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Sensor_SEN0120", "C\303\240i \304\221\341\272\267t chung", nullptr));
        label_13->setText(QCoreApplication::translate("Sensor_SEN0120", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        label_14->setText(QCoreApplication::translate("Sensor_SEN0120", "(ms)", nullptr));
        label_15->setText(QCoreApplication::translate("Sensor_SEN0120", "( BPM )", nullptr));
        label_16->setText(QCoreApplication::translate("Sensor_SEN0120", "( % )", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Sensor_SEN0120", "          C\303\240i \304\221\341\272\267t          ", nullptr));
        label_Unit_Heart->setText(QCoreApplication::translate("Sensor_SEN0120", "\304\220o nh\341\273\213p tim (Beats per minute - BPM)", nullptr));
        label_2->setText(QCoreApplication::translate("Sensor_SEN0120", "\304\220o \304\221\341\273\231 b\303\243o h\303\262a Oxy trong m\303\241u (SPO2)", nullptr));
        pushButton_Apply->setText(QCoreApplication::translate("Sensor_SEN0120", "\303\201p d\341\273\245ng", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Sensor_SEN0120", "Tho\303\241t", nullptr));
        pushButton_ChartZoom->setText(QCoreApplication::translate("Sensor_SEN0120", "Ph\303\242n t\303\255ch", nullptr));
        label_Finger_Status->setText(QCoreApplication::translate("Sensor_SEN0120", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0120: public Ui_Sensor_SEN0120 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0120_H
