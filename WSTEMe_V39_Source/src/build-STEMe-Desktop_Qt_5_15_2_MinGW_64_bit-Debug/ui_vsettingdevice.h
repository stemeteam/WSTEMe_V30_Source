/********************************************************************************
** Form generated from reading UI file 'vsettingdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSETTINGDEVICE_H
#define UI_VSETTINGDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VSettingDevice
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QFrame *line;
    QPushButton *pushButton_SearchDevice;
    QLineEdit *lineEdit_SerialNumber;
    QLabel *label_SN_Info;
    QPushButton *pushButton_SetupSN;
    QCheckBox *checkBox_SN_Increase;
    QLabel *label_SN_Info_2;
    QLabel *label_SN_Info_3;
    QLabel *label_SN_Info_4;
    QLabel *label_SN_Info_5;
    QLabel *label_SN_Info_6;
    QLabel *label_SN_Info_7;
    QLabel *label_SN_Info_8;
    QLabel *label_SN_Info_9;
    QLabel *label_SN_Info_10;
    QLabel *label_SN_Info_11;
    QLabel *label_SN_setG;
    QLabel *label_SN_setD;
    QWidget *tab_2;
    QPushButton *pushButton_SN_Exit;

    void setupUi(QMainWindow *VSettingDevice)
    {
        if (VSettingDevice->objectName().isEmpty())
            VSettingDevice->setObjectName(QString::fromUtf8("VSettingDevice"));
        VSettingDevice->resize(620, 449);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/settingdevice.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VSettingDevice->setWindowIcon(icon);
        VSettingDevice->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(VSettingDevice);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 600, 400));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 541, 341));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(270, 10, 271, 20));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_SearchDevice = new QPushButton(groupBox);
        pushButton_SearchDevice->setObjectName(QString::fromUtf8("pushButton_SearchDevice"));
        pushButton_SearchDevice->setGeometry(QRect(350, 70, 151, 40));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        pushButton_SearchDevice->setFont(font2);
        lineEdit_SerialNumber = new QLineEdit(groupBox);
        lineEdit_SerialNumber->setObjectName(QString::fromUtf8("lineEdit_SerialNumber"));
        lineEdit_SerialNumber->setGeometry(QRect(40, 70, 301, 40));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        lineEdit_SerialNumber->setFont(font3);
        lineEdit_SerialNumber->setMaxLength(12);
        lineEdit_SerialNumber->setAlignment(Qt::AlignCenter);
        label_SN_Info = new QLabel(groupBox);
        label_SN_Info->setObjectName(QString::fromUtf8("label_SN_Info"));
        label_SN_Info->setGeometry(QRect(40, 40, 461, 22));
        QFont font4;
        font4.setPointSize(10);
        label_SN_Info->setFont(font4);
        label_SN_Info->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pushButton_SetupSN = new QPushButton(groupBox);
        pushButton_SetupSN->setObjectName(QString::fromUtf8("pushButton_SetupSN"));
        pushButton_SetupSN->setGeometry(QRect(40, 160, 301, 41));
        pushButton_SetupSN->setFont(font2);
        checkBox_SN_Increase = new QCheckBox(groupBox);
        checkBox_SN_Increase->setObjectName(QString::fromUtf8("checkBox_SN_Increase"));
        checkBox_SN_Increase->setGeometry(QRect(40, 120, 311, 27));
        label_SN_Info_2 = new QLabel(groupBox);
        label_SN_Info_2->setObjectName(QString::fromUtf8("label_SN_Info_2"));
        label_SN_Info_2->setGeometry(QRect(40, 210, 461, 22));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setItalic(true);
        label_SN_Info_2->setFont(font5);
        label_SN_Info_3 = new QLabel(groupBox);
        label_SN_Info_3->setObjectName(QString::fromUtf8("label_SN_Info_3"));
        label_SN_Info_3->setGeometry(QRect(40, 240, 181, 22));
        label_SN_Info_4 = new QLabel(groupBox);
        label_SN_Info_4->setObjectName(QString::fromUtf8("label_SN_Info_4"));
        label_SN_Info_4->setGeometry(QRect(160, 260, 341, 22));
        label_SN_Info_5 = new QLabel(groupBox);
        label_SN_Info_5->setObjectName(QString::fromUtf8("label_SN_Info_5"));
        label_SN_Info_5->setGeometry(QRect(40, 300, 461, 22));
        label_SN_Info_6 = new QLabel(groupBox);
        label_SN_Info_6->setObjectName(QString::fromUtf8("label_SN_Info_6"));
        label_SN_Info_6->setGeometry(QRect(342, 240, 71, 22));
        label_SN_Info_7 = new QLabel(groupBox);
        label_SN_Info_7->setObjectName(QString::fromUtf8("label_SN_Info_7"));
        label_SN_Info_7->setGeometry(QRect(222, 240, 41, 22));
        QFont font6;
        font6.setBold(true);
        label_SN_Info_7->setFont(font6);
        label_SN_Info_7->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_SN_Info_8 = new QLabel(groupBox);
        label_SN_Info_8->setObjectName(QString::fromUtf8("label_SN_Info_8"));
        label_SN_Info_8->setGeometry(QRect(262, 240, 74, 22));
        label_SN_Info_8->setFont(font6);
        label_SN_Info_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        label_SN_Info_9 = new QLabel(groupBox);
        label_SN_Info_9->setObjectName(QString::fromUtf8("label_SN_Info_9"));
        label_SN_Info_9->setGeometry(QRect(50, 280, 101, 22));
        label_SN_Info_9->setFont(font6);
        label_SN_Info_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        label_SN_Info_10 = new QLabel(groupBox);
        label_SN_Info_10->setObjectName(QString::fromUtf8("label_SN_Info_10"));
        label_SN_Info_10->setGeometry(QRect(82, 260, 71, 22));
        label_SN_Info_10->setFont(font6);
        label_SN_Info_10->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_SN_Info_11 = new QLabel(groupBox);
        label_SN_Info_11->setObjectName(QString::fromUtf8("label_SN_Info_11"));
        label_SN_Info_11->setGeometry(QRect(160, 280, 341, 22));
        label_SN_setG = new QLabel(groupBox);
        label_SN_setG->setObjectName(QString::fromUtf8("label_SN_setG"));
        label_SN_setG->setGeometry(QRect(46, 69, 41, 22));
        label_SN_setG->setFont(font4);
        label_SN_setG->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_SN_setD = new QLabel(groupBox);
        label_SN_setD->setObjectName(QString::fromUtf8("label_SN_setD"));
        label_SN_setD->setGeometry(QRect(47, 87, 41, 22));
        label_SN_setD->setFont(font4);
        label_SN_setD->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        pushButton_SN_Exit = new QPushButton(centralwidget);
        pushButton_SN_Exit->setObjectName(QString::fromUtf8("pushButton_SN_Exit"));
        pushButton_SN_Exit->setGeometry(QRect(470, 414, 141, 30));
        pushButton_SN_Exit->setFont(font2);
        VSettingDevice->setCentralWidget(centralwidget);

        retranslateUi(VSettingDevice);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VSettingDevice);
    } // setupUi

    void retranslateUi(QMainWindow *VSettingDevice)
    {
        VSettingDevice->setWindowTitle(QCoreApplication::translate("VSettingDevice", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VSettingDevice", "C\303\240i \304\221\341\272\267t m\303\243 qu\341\272\243n l\303\275 (S/N) cho thi\341\272\277t b\341\273\213. ", nullptr));
        pushButton_SearchDevice->setText(QCoreApplication::translate("VSettingDevice", "T\303\254m thi\341\272\277t b\341\273\213", nullptr));
        lineEdit_SerialNumber->setPlaceholderText(QCoreApplication::translate("VSettingDevice", "1102 123456789", nullptr));
        label_SN_Info->setText(QCoreApplication::translate("VSettingDevice", "Nh\341\272\255p m\303\243 (12 k\303\255 t\341\273\261) ho\341\272\267c nh\341\272\245n \"T\303\254m thi\341\272\277t b\341\273\213\".", nullptr));
        pushButton_SetupSN->setText(QCoreApplication::translate("VSettingDevice", "C\303\240i \304\221\341\272\267t S/N", nullptr));
        checkBox_SN_Increase->setText(QCoreApplication::translate("VSettingDevice", "T\304\203ng S/N l\303\252n m\341\273\231t \304\221\306\241n v\341\273\213 m\341\273\227i khi c\303\240i \304\221\341\272\267t.", nullptr));
        label_SN_Info_2->setText(QCoreApplication::translate("VSettingDevice", "Ch\303\272 \303\275:", nullptr));
        label_SN_Info_3->setText(QCoreApplication::translate("VSettingDevice", "- M\303\243 qu\341\272\243n l\303\275 g\341\273\223m 12 k\303\255 t\341\273\261 ", nullptr));
        label_SN_Info_4->setText(QCoreApplication::translate("VSettingDevice", "M\303\243 ph\303\242n nh\303\263m (ph\303\242n lo\341\272\241i thi\341\272\277t b\341\273\213, lu\303\264n c\341\273\221 \304\221\341\273\213nh)", nullptr));
        label_SN_Info_5->setText(QCoreApplication::translate("VSettingDevice", "- N\341\272\277u c\303\263 l\341\273\227i khi c\303\240i \304\221\341\272\267t th\303\254 c\341\272\247n r\303\272t c\303\241p k\341\272\277t n\341\273\221i v\303\240 c\341\272\257m l\341\272\241i.", nullptr));
        label_SN_Info_6->setText(QCoreApplication::translate("VSettingDevice", "bao g\341\273\223m:", nullptr));
        label_SN_Info_7->setText(QCoreApplication::translate("VSettingDevice", "1102", nullptr));
        label_SN_Info_8->setText(QCoreApplication::translate("VSettingDevice", "12345678", nullptr));
        label_SN_Info_9->setText(QCoreApplication::translate("VSettingDevice", "D - 12345678:", nullptr));
        label_SN_Info_10->setText(QCoreApplication::translate("VSettingDevice", "G - 1102 :", nullptr));
        label_SN_Info_11->setText(QCoreApplication::translate("VSettingDevice", "M\303\243 \304\221\341\273\213nh danh thi\341\272\277t b\341\273\213, thay \304\221\341\273\225i theo t\341\273\253ng thi\341\272\277t b\341\273\213", nullptr));
        label_SN_setG->setText(QCoreApplication::translate("VSettingDevice", "G (0)", nullptr));
        label_SN_setD->setText(QCoreApplication::translate("VSettingDevice", "D (0)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("VSettingDevice", "     Thi\341\272\277t b\341\273\213     ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("VSettingDevice", "     Ph\341\272\247n m\341\273\201m     ", nullptr));
        pushButton_SN_Exit->setText(QCoreApplication::translate("VSettingDevice", "Tho\303\241t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VSettingDevice: public Ui_VSettingDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSETTINGDEVICE_H
