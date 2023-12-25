/********************************************************************************
** Form generated from reading UI file 'sensor_sen0113.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_SEN0113_H
#define UI_SENSOR_SEN0113_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor_SEN0113
{
public:
    QFrame *frame;
    QLabel *label;
    QLCDNumber *lcdNumber_DISTANCE;
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
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *tab_3;
    QLabel *label_3;
    QLineEdit *lineEdit_Calib1;
    QLabel *label_8;
    QPushButton *pushButton_Calib;
    QLabel *label_9;
    QPushButton *pushButton_Calib_2;
    QLabel *label_10;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QLabel *label_13;
    QSpinBox *spinBox_SampleTimer;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_ChartZoom;
    QLCDNumber *lcdNumber_VELOCITY;
    QLabel *label_2;

    void setupUi(QWidget *Sensor_SEN0113)
    {
        if (Sensor_SEN0113->objectName().isEmpty())
            Sensor_SEN0113->setObjectName(QString::fromUtf8("Sensor_SEN0113"));
        Sensor_SEN0113->resize(570, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/MOVE0113_Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Sensor_SEN0113->setWindowIcon(icon);
        frame = new QFrame(Sensor_SEN0113);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 570, 500));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 179, 76);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 130, 221, 22));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);"));
        label->setAlignment(Qt::AlignCenter);
        lcdNumber_DISTANCE = new QLCDNumber(frame);
        lcdNumber_DISTANCE->setObjectName(QString::fromUtf8("lcdNumber_DISTANCE"));
        lcdNumber_DISTANCE->setGeometry(QRect(35, 35, 241, 90));
        lcdNumber_DISTANCE->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 255,255);"));
        lcdNumber_DISTANCE->setFrameShape(QFrame::WinPanel);
        lcdNumber_DISTANCE->setLineWidth(1);
        lcdNumber_DISTANCE->setSmallDecimalPoint(false);
        lcdNumber_DISTANCE->setDigitCount(7);
        lcdNumber_DISTANCE->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_DISTANCE->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_DISTANCE->setProperty("intValue", QVariant(0));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(35, 180, 500, 270));
        QFont font1;
        font1.setBold(false);
        tabWidget->setFont(font1);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 179, 76);"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        tab_1->setStyleSheet(QString::fromUtf8("background-color: #132635;"));
        verticalLayoutWidget = new QWidget(tab_1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 111, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: #132635;"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-color: #132635;\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: #132635;\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_7);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: #132635;\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(tab_1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 451, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(verticalLayoutWidget_2);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: #132635;"));

        verticalLayout_3->addWidget(label_Name);

        label_Address = new QLabel(verticalLayoutWidget_2);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: #132635;"));

        verticalLayout_3->addWidget(label_Address);

        label_SerialNumber = new QLabel(verticalLayoutWidget_2);
        label_SerialNumber->setObjectName(QString::fromUtf8("label_SerialNumber"));
        label_SerialNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: #132635;"));

        verticalLayout_3->addWidget(label_SerialNumber);

        verticalLayoutWidget_3 = new QWidget(tab_1);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(160, 110, 451, 151));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(verticalLayoutWidget_3);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: #132635;"));
        label_Description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(label_Description);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("background-color: #132635;"));
        verticalLayoutWidget_4 = new QWidget(tab_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 501, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("background-color: #132635;"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 61, 141, 22));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_Calib1 = new QLineEdit(tab_3);
        lineEdit_Calib1->setObjectName(QString::fromUtf8("lineEdit_Calib1"));
        lineEdit_Calib1->setGeometry(QRect(180, 91, 101, 30));
        lineEdit_Calib1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 95, 141, 22));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Calib = new QPushButton(tab_3);
        pushButton_Calib->setObjectName(QString::fromUtf8("pushButton_Calib"));
        pushButton_Calib->setGeometry(QRect(350, 91, 131, 30));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(290, 96, 51, 22));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Calib_2 = new QPushButton(tab_3);
        pushButton_Calib_2->setObjectName(QString::fromUtf8("pushButton_Calib_2"));
        pushButton_Calib_2->setGeometry(QRect(180, 21, 301, 30));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 25, 151, 22));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 130, 461, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 140, 321, 71));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 30, 131, 22));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        spinBox_SampleTimer = new QSpinBox(groupBox_2);
        spinBox_SampleTimer->setObjectName(QString::fromUtf8("spinBox_SampleTimer"));
        spinBox_SampleTimer->setGeometry(QRect(160, 11, 101, 61));
        spinBox_SampleTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox_SampleTimer->setMinimum(1);
        spinBox_SampleTimer->setMaximum(99999);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(270, 34, 31, 22));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_3, QString());
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(274, 458, 261, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Apply = new QPushButton(horizontalLayoutWidget);
        pushButton_Apply->setObjectName(QString::fromUtf8("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        pushButton_Exit = new QPushButton(horizontalLayoutWidget);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));

        horizontalLayout->addWidget(pushButton_Exit);

        pushButton_ChartZoom = new QPushButton(frame);
        pushButton_ChartZoom->setObjectName(QString::fromUtf8("pushButton_ChartZoom"));
        pushButton_ChartZoom->setGeometry(QRect(37, 459, 121, 30));
        lcdNumber_VELOCITY = new QLCDNumber(frame);
        lcdNumber_VELOCITY->setObjectName(QString::fromUtf8("lcdNumber_VELOCITY"));
        lcdNumber_VELOCITY->setGeometry(QRect(290, 35, 251, 90));
        lcdNumber_VELOCITY->setStyleSheet(QString::fromUtf8("background-color: #132630;\n"
"color: rgb(255, 0,0);"));
        lcdNumber_VELOCITY->setFrameShape(QFrame::WinPanel);
        lcdNumber_VELOCITY->setLineWidth(1);
        lcdNumber_VELOCITY->setSmallDecimalPoint(false);
        lcdNumber_VELOCITY->setDigitCount(7);
        lcdNumber_VELOCITY->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_VELOCITY->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_VELOCITY->setProperty("intValue", QVariant(0));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(296, 130, 241, 22));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(Sensor_SEN0113);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sensor_SEN0113);
    } // setupUi

    void retranslateUi(QWidget *Sensor_SEN0113)
    {
        Sensor_SEN0113->setWindowTitle(QCoreApplication::translate("Sensor_SEN0113", "Form", nullptr));
#if QT_CONFIG(accessibility)
        frame->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("Sensor_SEN0113", "\304\220o kho\341\272\243ng c\303\241ch (m - m\303\251t)", nullptr));
        label_4->setText(QCoreApplication::translate("Sensor_SEN0113", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label_6->setText(QCoreApplication::translate("Sensor_SEN0113", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_7->setText(QCoreApplication::translate("Sensor_SEN0113", "M\303\243 s\303\252-ri:", nullptr));
        label_5->setText(QCoreApplication::translate("Sensor_SEN0113", "M\303\264 t\341\272\243:", nullptr));
        label_Name->setText(QString());
        label_Address->setText(QString());
        label_SerialNumber->setText(QString());
        label_Description->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("Sensor_SEN0113", "          Thi\341\272\277t b\341\273\213          ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Sensor_SEN0113", "          \304\220\341\273\223 th\341\273\213          ", nullptr));
        label_3->setText(QCoreApplication::translate("Sensor_SEN0113", "Hi\341\273\207u chu\341\272\251n thi\341\272\277t b\341\273\213.", nullptr));
        lineEdit_Calib1->setText(QCoreApplication::translate("Sensor_SEN0113", "1", nullptr));
        label_8->setText(QCoreApplication::translate("Sensor_SEN0113", "Gi\303\241 tr\341\273\213 \304\221o chu\341\272\251n:", nullptr));
        pushButton_Calib->setText(QCoreApplication::translate("Sensor_SEN0113", "Hi\341\273\207u chu\341\272\251n", nullptr));
        label_9->setText(QCoreApplication::translate("Sensor_SEN0113", "( m )", nullptr));
        pushButton_Calib_2->setText(QCoreApplication::translate("Sensor_SEN0113", "Hi\341\273\207u ch\341\273\211nh (Zero)", nullptr));
        label_10->setText(QCoreApplication::translate("Sensor_SEN0113", "\304\220i\341\273\201u ch\341\273\211nh \304\221\341\273\231 l\341\273\207ch 0:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Sensor_SEN0113", "C\303\240i \304\221\341\272\267t chung", nullptr));
        label_13->setText(QCoreApplication::translate("Sensor_SEN0113", "Th\341\273\235i gian l\341\272\245y m\341\272\253u :", nullptr));
        label_14->setText(QCoreApplication::translate("Sensor_SEN0113", "(ms)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Sensor_SEN0113", "          C\303\240i \304\221\341\272\267t          ", nullptr));
        pushButton_Apply->setText(QCoreApplication::translate("Sensor_SEN0113", "\303\201p d\341\273\245ng", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Sensor_SEN0113", "Tho\303\241t", nullptr));
        pushButton_ChartZoom->setText(QCoreApplication::translate("Sensor_SEN0113", "Ph\303\242n t\303\255ch", nullptr));
        label_2->setText(QCoreApplication::translate("Sensor_SEN0113", "\304\220o v\341\272\255n t\341\273\221c (m/s - m\303\251t/gi\303\242y)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor_SEN0113: public Ui_Sensor_SEN0113 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_SEN0113_H
