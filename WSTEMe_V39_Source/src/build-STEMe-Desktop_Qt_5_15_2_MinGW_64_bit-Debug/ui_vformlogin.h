/********************************************************************************
** Form generated from reading UI file 'vformlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VFORMLOGIN_H
#define UI_VFORMLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VFormLogin
{
public:
    QFrame *frame;
    QPushButton *pushButton_Login;
    QLabel *label_2;
    QLineEdit *lineEdit_Password;
    QLabel *label_3;
    QLabel *label_accountType;
    QFrame *frame_2;
    QLabel *label;
    QComboBox *comboBox_Account;
    QLabel *label_4;
    QComboBox *comboBox_Port;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *VFormLogin)
    {
        if (VFormLogin->objectName().isEmpty())
            VFormLogin->setObjectName(QString::fromUtf8("VFormLogin"));
        VFormLogin->setWindowModality(Qt::WindowModal);
        VFormLogin->resize(1280, 740);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Steme_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VFormLogin->setWindowIcon(icon);
        VFormLogin->setStyleSheet(QString::fromUtf8("background-color: #132635;\n"
"background-color: #193848;\n"
""));
        frame = new QFrame(VFormLogin);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(410, 119, 460, 491));
        frame->setStyleSheet(QString::fromUtf8("background-color: #193848;\n"
"color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_Login = new QPushButton(frame);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setGeometry(QRect(80, 400, 300, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton_Login->setFont(font);
        pushButton_Login->setAutoFillBackground(false);
        pushButton_Login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: none;\n"
"background-color: rgb(0, 222, 99);\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        pushButton_Login->setIconSize(QSize(100, 20));
        pushButton_Login->setCheckable(false);
        pushButton_Login->setChecked(false);
        pushButton_Login->setAutoDefault(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(78, 246, 111, 22));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(13, 207, 200);"));
        lineEdit_Password = new QLineEdit(frame);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(80, 270, 300, 30));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        lineEdit_Password->setFont(font2);
        lineEdit_Password->setAcceptDrops(true);
        lineEdit_Password->setAutoFillBackground(false);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        lineEdit_Password->setFrame(true);
        lineEdit_Password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 370, 111, 22));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_accountType = new QLabel(frame);
        label_accountType->setObjectName(QString::fromUtf8("label_accountType"));
        label_accountType->setGeometry(QRect(200, 370, 171, 22));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(true);
        label_accountType->setFont(font4);
        label_accountType->setStyleSheet(QString::fromUtf8("color: rgb(255,255, 255);"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(50, 170, 361, 80));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #193848;"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(29, 15, 161, 22));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(13, 207, 200);"));
        comboBox_Account = new QComboBox(frame_2);
        comboBox_Account->setObjectName(QString::fromUtf8("comboBox_Account"));
        comboBox_Account->setEnabled(true);
        comboBox_Account->setGeometry(QRect(30, 40, 300, 30));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setKerning(true);
        comboBox_Account->setFont(font5);
        comboBox_Account->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}\n"
""));
        comboBox_Account->setFrame(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(79, 305, 161, 22));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(13, 207, 200);"));
        comboBox_Port = new QComboBox(frame);
        comboBox_Port->setObjectName(QString::fromUtf8("comboBox_Port"));
        comboBox_Port->setGeometry(QRect(80, 330, 301, 32));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(true);
        comboBox_Port->setFont(font6);
        comboBox_Port->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        graphicsView = new QGraphicsView(VFormLogin);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(488, 140, 300, 150));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/image/LogginLogoBig.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        QWidget::setTabOrder(comboBox_Account, lineEdit_Password);
        QWidget::setTabOrder(lineEdit_Password, pushButton_Login);
        QWidget::setTabOrder(pushButton_Login, graphicsView);

        retranslateUi(VFormLogin);

        pushButton_Login->setDefault(false);


        QMetaObject::connectSlotsByName(VFormLogin);
    } // setupUi

    void retranslateUi(QWidget *VFormLogin)
    {
        VFormLogin->setWindowTitle(QCoreApplication::translate("VFormLogin", "STEMe-\304\220\304\203ng nh\341\272\255p", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("VFormLogin", "\304\220\304\203ng nh\341\272\255p", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Login->setShortcut(QCoreApplication::translate("VFormLogin", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("VFormLogin", "M\341\272\255t kh\341\272\251u", nullptr));
        lineEdit_Password->setText(QString());
        label_3->setText(QCoreApplication::translate("VFormLogin", "Lo\341\272\241i t\303\240i kho\341\272\243n:", nullptr));
        label_accountType->setText(QCoreApplication::translate("VFormLogin", "Student (h\341\273\215c sinh)", nullptr));
        label->setText(QCoreApplication::translate("VFormLogin", "T\303\252n \304\221\304\203ng nh\341\272\255p", nullptr));
        label_4->setText(QCoreApplication::translate("VFormLogin", "C\341\273\225ng k\341\272\277t n\341\273\221i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VFormLogin: public Ui_VFormLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFORMLOGIN_H
