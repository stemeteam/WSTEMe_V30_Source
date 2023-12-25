/********************************************************************************
** Form generated from reading UI file 'formuseraccount.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUSERACCOUNT_H
#define UI_FORMUSERACCOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormUserAccount
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Cancel;
    QFrame *frame;
    QGroupBox *groupBox_AccountInfo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Info_Account;
    QLabel *label_Info_Type;
    QLabel *label_Info_Date;
    QFrame *frame_2;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_ChangePassword;
    QLineEdit *lineEdit_ChangeNewPassword;
    QLineEdit *lineEdit_ChangeRePassword;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_ChangePassword;
    QFrame *frame_3;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QComboBox *comboBox_RemoveAccount;
    QLineEdit *lineEdit_RemovePassword;
    QLineEdit *lineEdit_RemoveRePassword;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_Remove;
    QFrame *frame_4;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_NewAccount;
    QComboBox *comboBox_NewType;
    QLineEdit *lineEdit_NewPassword;
    QLineEdit *lineEdit_NewRePassword;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_ChangePassword_NewCreat;

    void setupUi(QWidget *FormUserAccount)
    {
        if (FormUserAccount->objectName().isEmpty())
            FormUserAccount->setObjectName(QString::fromUtf8("FormUserAccount"));
        FormUserAccount->resize(900, 533);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Setup_icon_1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormUserAccount->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(FormUserAccount);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 480, 321, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Cancel = new QPushButton(horizontalLayoutWidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        QFont font;
        font.setBold(true);
        pushButton_Cancel->setFont(font);

        horizontalLayout->addWidget(pushButton_Cancel);

        frame = new QFrame(FormUserAccount);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 431, 241));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox_AccountInfo = new QGroupBox(frame);
        groupBox_AccountInfo->setObjectName(QString::fromUtf8("groupBox_AccountInfo"));
        groupBox_AccountInfo->setGeometry(QRect(10, 10, 411, 151));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        groupBox_AccountInfo->setFont(font1);
        groupBox_AccountInfo->setStyleSheet(QString::fromUtf8("border:5px"));
        groupBox_AccountInfo->setFlat(false);
        verticalLayoutWidget = new QWidget(groupBox_AccountInfo);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 121, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        verticalLayoutWidget_2 = new QWidget(groupBox_AccountInfo);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 40, 231, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Info_Account = new QLabel(verticalLayoutWidget_2);
        label_Info_Account->setObjectName(QString::fromUtf8("label_Info_Account"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        label_Info_Account->setFont(font2);

        verticalLayout_2->addWidget(label_Info_Account);

        label_Info_Type = new QLabel(verticalLayoutWidget_2);
        label_Info_Type->setObjectName(QString::fromUtf8("label_Info_Type"));
        label_Info_Type->setFont(font2);

        verticalLayout_2->addWidget(label_Info_Type);

        label_Info_Date = new QLabel(verticalLayoutWidget_2);
        label_Info_Date->setObjectName(QString::fromUtf8("label_Info_Date"));
        label_Info_Date->setFont(font2);

        verticalLayout_2->addWidget(label_Info_Date);

        frame_2 = new QFrame(FormUserAccount);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 260, 431, 201));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 191));
        groupBox->setFont(font1);
        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 30, 134, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        verticalLayout_3->addWidget(label_6);

        verticalLayoutWidget_4 = new QWidget(groupBox);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(180, 30, 211, 110));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_ChangePassword = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_ChangePassword->setObjectName(QString::fromUtf8("lineEdit_ChangePassword"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        lineEdit_ChangePassword->setFont(font3);
        lineEdit_ChangePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_4->addWidget(lineEdit_ChangePassword);

        lineEdit_ChangeNewPassword = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_ChangeNewPassword->setObjectName(QString::fromUtf8("lineEdit_ChangeNewPassword"));
        lineEdit_ChangeNewPassword->setFont(font3);
        lineEdit_ChangeNewPassword->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(lineEdit_ChangeNewPassword);

        lineEdit_ChangeRePassword = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_ChangeRePassword->setObjectName(QString::fromUtf8("lineEdit_ChangeRePassword"));
        lineEdit_ChangeRePassword->setFont(font3);
        lineEdit_ChangeRePassword->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(lineEdit_ChangeRePassword);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(180, 150, 211, 32));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_ChangePassword = new QPushButton(horizontalLayoutWidget_2);
        pushButton_ChangePassword->setObjectName(QString::fromUtf8("pushButton_ChangePassword"));
        pushButton_ChangePassword->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_ChangePassword);

        frame_3 = new QFrame(FormUserAccount);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(450, 260, 441, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 421, 191));
        groupBox_2->setFont(font1);
        verticalLayoutWidget_7 = new QWidget(groupBox_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(20, 30, 134, 101));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        verticalLayout_7->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        verticalLayout_7->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        verticalLayout_7->addWidget(label_13);

        verticalLayoutWidget_8 = new QWidget(groupBox_2);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(170, 30, 231, 110));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        comboBox_RemoveAccount = new QComboBox(verticalLayoutWidget_8);
        comboBox_RemoveAccount->setObjectName(QString::fromUtf8("comboBox_RemoveAccount"));
        comboBox_RemoveAccount->setFont(font3);
        comboBox_RemoveAccount->setEditable(false);

        verticalLayout_8->addWidget(comboBox_RemoveAccount);

        lineEdit_RemovePassword = new QLineEdit(verticalLayoutWidget_8);
        lineEdit_RemovePassword->setObjectName(QString::fromUtf8("lineEdit_RemovePassword"));
        lineEdit_RemovePassword->setFont(font3);
        lineEdit_RemovePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_8->addWidget(lineEdit_RemovePassword);

        lineEdit_RemoveRePassword = new QLineEdit(verticalLayoutWidget_8);
        lineEdit_RemoveRePassword->setObjectName(QString::fromUtf8("lineEdit_RemoveRePassword"));
        lineEdit_RemoveRePassword->setFont(font3);
        lineEdit_RemoveRePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_8->addWidget(lineEdit_RemoveRePassword);

        horizontalLayoutWidget_4 = new QWidget(groupBox_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(170, 150, 231, 32));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_Remove = new QPushButton(horizontalLayoutWidget_4);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setFont(font1);

        horizontalLayout_6->addWidget(pushButton_Remove);

        frame_4 = new QFrame(FormUserAccount);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(450, 10, 441, 241));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        groupBox_3 = new QGroupBox(frame_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 421, 231));
        groupBox_3->setFont(font1);
        verticalLayoutWidget_5 = new QWidget(groupBox_3);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 30, 134, 141));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        verticalLayout_5->addWidget(label_10);

        verticalLayoutWidget_6 = new QWidget(groupBox_3);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(160, 30, 241, 148));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_NewAccount = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_NewAccount->setObjectName(QString::fromUtf8("lineEdit_NewAccount"));
        lineEdit_NewAccount->setFont(font3);

        verticalLayout_6->addWidget(lineEdit_NewAccount);

        comboBox_NewType = new QComboBox(verticalLayoutWidget_6);
        comboBox_NewType->addItem(QString());
        comboBox_NewType->addItem(QString());
        comboBox_NewType->addItem(QString());
        comboBox_NewType->setObjectName(QString::fromUtf8("comboBox_NewType"));
        comboBox_NewType->setFont(font3);
        comboBox_NewType->setEditable(false);

        verticalLayout_6->addWidget(comboBox_NewType);

        lineEdit_NewPassword = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_NewPassword->setObjectName(QString::fromUtf8("lineEdit_NewPassword"));
        lineEdit_NewPassword->setFont(font3);
        lineEdit_NewPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_6->addWidget(lineEdit_NewPassword);

        lineEdit_NewRePassword = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_NewRePassword->setObjectName(QString::fromUtf8("lineEdit_NewRePassword"));
        lineEdit_NewRePassword->setFont(font3);
        lineEdit_NewRePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_6->addWidget(lineEdit_NewRePassword);

        horizontalLayoutWidget_3 = new QWidget(groupBox_3);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(160, 190, 241, 32));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_ChangePassword_NewCreat = new QPushButton(horizontalLayoutWidget_3);
        pushButton_ChangePassword_NewCreat->setObjectName(QString::fromUtf8("pushButton_ChangePassword_NewCreat"));
        pushButton_ChangePassword_NewCreat->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_ChangePassword_NewCreat);


        retranslateUi(FormUserAccount);

        QMetaObject::connectSlotsByName(FormUserAccount);
    } // setupUi

    void retranslateUi(QWidget *FormUserAccount)
    {
        FormUserAccount->setWindowTitle(QCoreApplication::translate("FormUserAccount", "STEMe - T\341\272\241o t\303\240i kho\341\272\243n", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("FormUserAccount", "Tho\303\241t", nullptr));
        groupBox_AccountInfo->setTitle(QCoreApplication::translate("FormUserAccount", "Th\303\264ng tin t\303\240i kho\341\272\243n", nullptr));
        label_2->setText(QCoreApplication::translate("FormUserAccount", "T\303\252n t\303\240i kho\341\272\243n:", nullptr));
        label->setText(QCoreApplication::translate("FormUserAccount", "Ki\341\273\203u t\303\240i kho\341\272\243n:", nullptr));
        label_4->setText(QCoreApplication::translate("FormUserAccount", "Ng\303\240y l\341\272\255p:", nullptr));
        label_Info_Account->setText(QString());
        label_Info_Type->setText(QString());
        label_Info_Date->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("FormUserAccount", "Thay \304\221\341\273\225i m\341\272\255t kh\341\272\251u", nullptr));
        label_3->setText(QCoreApplication::translate("FormUserAccount", "M\341\272\255t kh\341\272\251u c\305\251:", nullptr));
        label_5->setText(QCoreApplication::translate("FormUserAccount", "M\341\272\255t kh\341\272\251u m\341\273\233i:", nullptr));
        label_6->setText(QCoreApplication::translate("FormUserAccount", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        lineEdit_ChangePassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "> 7 k\303\255 t\341\273\261, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_ChangeNewPassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "> 7 k\303\255 t\341\273\261, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_ChangeRePassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "> 7 k\303\255 t\341\273\261, kh\303\264ng d\341\272\245u", nullptr));
        pushButton_ChangePassword->setText(QCoreApplication::translate("FormUserAccount", "\304\220\341\273\225i m\341\272\255t kh\341\272\251u", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FormUserAccount", "X\303\263a t\303\240i kho\341\272\243n", nullptr));
        label_11->setText(QCoreApplication::translate("FormUserAccount", "Ch\341\273\215n t\303\240i kho\341\272\243n:", nullptr));
        label_12->setText(QCoreApplication::translate("FormUserAccount", "M\341\272\255t kh\341\272\251u:", nullptr));
        label_13->setText(QCoreApplication::translate("FormUserAccount", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        comboBox_RemoveAccount->setCurrentText(QString());
        lineEdit_RemovePassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_RemoveRePassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        pushButton_Remove->setText(QCoreApplication::translate("FormUserAccount", "X\303\263a t\303\240i kho\341\272\243n", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FormUserAccount", "T\341\272\241o t\303\240i kho\341\272\243n m\341\273\233i", nullptr));
        label_7->setText(QCoreApplication::translate("FormUserAccount", "T\303\252n t\303\240i kho\341\272\243n:", nullptr));
        label_8->setText(QCoreApplication::translate("FormUserAccount", "Lo\341\272\241i t\303\240i kho\341\272\243n:", nullptr));
        label_9->setText(QCoreApplication::translate("FormUserAccount", "M\341\272\255t kh\341\272\251u:", nullptr));
        label_10->setText(QCoreApplication::translate("FormUserAccount", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u:", nullptr));
        lineEdit_NewAccount->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        comboBox_NewType->setItemText(0, QCoreApplication::translate("FormUserAccount", "Root (Qu\341\272\243n l\303\275)", nullptr));
        comboBox_NewType->setItemText(1, QCoreApplication::translate("FormUserAccount", "Teacher (Gi\303\241o vi\303\252n)", nullptr));
        comboBox_NewType->setItemText(2, QCoreApplication::translate("FormUserAccount", "Student (H\341\273\215c sinh)", nullptr));

        comboBox_NewType->setCurrentText(QCoreApplication::translate("FormUserAccount", "Root (Qu\341\272\243n l\303\275)", nullptr));
        lineEdit_NewPassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        lineEdit_NewRePassword->setPlaceholderText(QCoreApplication::translate("FormUserAccount", "Vi\341\272\277t li\341\273\201n, kh\303\264ng d\341\272\245u", nullptr));
        pushButton_ChangePassword_NewCreat->setText(QCoreApplication::translate("FormUserAccount", "T\341\272\241o t\303\240i kho\341\272\243n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormUserAccount: public Ui_FormUserAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUSERACCOUNT_H
