/********************************************************************************
** Form generated from reading UI file 'module_mod1103_condition.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_MOD1103_CONDITION_H
#define UI_MODULE_MOD1103_CONDITION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Module_MOD1103_Condition
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget_CAR01;
    QWidget *tab;
    QLabel *label_Blink_Stop;
    QLabel *label_Blink_Process;
    QLabel *label_runBlink;
    QFrame *line_2;
    QFrame *frame_Condition;
    QFrame *frame_3;
    QLineEdit *lineEdit_Condition_Stop;
    QComboBox *comboBox_Condition_Stop_Car;
    QLabel *label_5;
    QComboBox *comboBox_Condition_Stop;
    QLabel *label_Condition_Stop_Unit;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_New;
    QFrame *frame_2;
    QComboBox *comboBox_Condition_Start_Car;
    QLabel *label_4;
    QLineEdit *lineEdit_Condition_Start;
    QLabel *label_Condition_Start_Unit;
    QComboBox *comboBox_Condition_Start;
    QGroupBox *groupBox;
    QFrame *line;
    QFrame *frame;
    QComboBox *comboBox_Unit;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_Run;
    QLabel *label_arrowBlink;
    QLabel *label_Blink_Start;
    QLabel *label_Run_Comment;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_Cancel;
    QWidget *tab_2;

    void setupUi(QMainWindow *Module_MOD1103_Condition)
    {
        if (Module_MOD1103_Condition->objectName().isEmpty())
            Module_MOD1103_Condition->setObjectName(QString::fromUtf8("Module_MOD1103_Condition"));
        Module_MOD1103_Condition->resize(1030, 519);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/MFS0103_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Module_MOD1103_Condition->setWindowIcon(icon);
        Module_MOD1103_Condition->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 58, 70);"));
        centralwidget = new QWidget(Module_MOD1103_Condition);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget_CAR01 = new QTabWidget(centralwidget);
        tabWidget_CAR01->setObjectName(QString::fromUtf8("tabWidget_CAR01"));
        tabWidget_CAR01->setGeometry(QRect(0, 0, 1031, 521));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        tabWidget_CAR01->setFont(font);
        tabWidget_CAR01->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"border: 1px solid #C0C0C0;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_Blink_Stop = new QLabel(tab);
        label_Blink_Stop->setObjectName(QString::fromUtf8("label_Blink_Stop"));
        label_Blink_Stop->setGeometry(QRect(710, 10, 211, 22));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        label_Blink_Stop->setFont(font1);
        label_Blink_Stop->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);"));
        label_Blink_Process = new QLabel(tab);
        label_Blink_Process->setObjectName(QString::fromUtf8("label_Blink_Process"));
        label_Blink_Process->setGeometry(QRect(330, 10, 371, 21));
        label_Blink_Process->setFont(font1);
        label_Blink_Process->setAutoFillBackground(false);
        label_Blink_Process->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Blink_Process->setAlignment(Qt::AlignCenter);
        label_runBlink = new QLabel(tab);
        label_runBlink->setObjectName(QString::fromUtf8("label_runBlink"));
        label_runBlink->setGeometry(QRect(480, 58, 71, 22));
        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(70, 410, 900, 1));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame_Condition = new QFrame(tab);
        frame_Condition->setObjectName(QString::fromUtf8("frame_Condition"));
        frame_Condition->setGeometry(QRect(10, 160, 1011, 231));
        frame_Condition->setFrameShape(QFrame::NoFrame);
        frame_Condition->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_Condition);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(580, 10, 381, 91));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px solid gray;\n"
"background-color: rgb(44, 58, 70);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        lineEdit_Condition_Stop = new QLineEdit(frame_3);
        lineEdit_Condition_Stop->setObjectName(QString::fromUtf8("lineEdit_Condition_Stop"));
        lineEdit_Condition_Stop->setGeometry(QRect(210, 50, 91, 32));
        lineEdit_Condition_Stop->setFont(font);
        lineEdit_Condition_Stop->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Condition_Stop->setMaxLength(4);
        lineEdit_Condition_Stop->setAlignment(Qt::AlignCenter);
        comboBox_Condition_Stop_Car = new QComboBox(frame_3);
        comboBox_Condition_Stop_Car->addItem(QString());
        comboBox_Condition_Stop_Car->addItem(QString());
        comboBox_Condition_Stop_Car->addItem(QString());
        comboBox_Condition_Stop_Car->setObjectName(QString::fromUtf8("comboBox_Condition_Stop_Car"));
        comboBox_Condition_Stop_Car->setGeometry(QRect(210, 10, 91, 32));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        comboBox_Condition_Stop_Car->setFont(font2);
        comboBox_Condition_Stop_Car->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 14, 191, 22));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(true);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);"));
        comboBox_Condition_Stop = new QComboBox(frame_3);
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->addItem(QString());
        comboBox_Condition_Stop->setObjectName(QString::fromUtf8("comboBox_Condition_Stop"));
        comboBox_Condition_Stop->setGeometry(QRect(10, 50, 191, 32));
        comboBox_Condition_Stop->setFont(font2);
        comboBox_Condition_Stop->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        label_Condition_Stop_Unit = new QLabel(frame_3);
        label_Condition_Stop_Unit->setObjectName(QString::fromUtf8("label_Condition_Stop_Unit"));
        label_Condition_Stop_Unit->setGeometry(QRect(304, 56, 71, 20));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        label_Condition_Stop_Unit->setFont(font4);
        label_Condition_Stop_Unit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Condition_Stop_Unit->setAlignment(Qt::AlignCenter);
        pushButton_Save = new QPushButton(frame_Condition);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(80, 200, 181, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        pushButton_Save->setFont(font5);
        pushButton_Save->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_New = new QPushButton(frame_Condition);
        pushButton_New->setObjectName(QString::fromUtf8("pushButton_New"));
        pushButton_New->setGeometry(QRect(790, 200, 151, 31));
        pushButton_New->setFont(font5);
        pushButton_New->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        frame_2 = new QFrame(frame_Condition);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(60, 10, 381, 91));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px solid gray;\n"
"background-color: rgb(44, 58, 70);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        comboBox_Condition_Start_Car = new QComboBox(frame_2);
        comboBox_Condition_Start_Car->addItem(QString());
        comboBox_Condition_Start_Car->addItem(QString());
        comboBox_Condition_Start_Car->addItem(QString());
        comboBox_Condition_Start_Car->setObjectName(QString::fromUtf8("comboBox_Condition_Start_Car"));
        comboBox_Condition_Start_Car->setGeometry(QRect(210, 10, 91, 32));
        comboBox_Condition_Start_Car->setFont(font2);
        comboBox_Condition_Start_Car->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 14, 191, 22));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));
        lineEdit_Condition_Start = new QLineEdit(frame_2);
        lineEdit_Condition_Start->setObjectName(QString::fromUtf8("lineEdit_Condition_Start"));
        lineEdit_Condition_Start->setGeometry(QRect(210, 50, 91, 32));
        lineEdit_Condition_Start->setFont(font);
        lineEdit_Condition_Start->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Condition_Start->setMaxLength(4);
        lineEdit_Condition_Start->setAlignment(Qt::AlignCenter);
        label_Condition_Start_Unit = new QLabel(frame_2);
        label_Condition_Start_Unit->setObjectName(QString::fromUtf8("label_Condition_Start_Unit"));
        label_Condition_Start_Unit->setGeometry(QRect(304, 56, 71, 20));
        label_Condition_Start_Unit->setFont(font4);
        label_Condition_Start_Unit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Condition_Start_Unit->setAlignment(Qt::AlignCenter);
        comboBox_Condition_Start = new QComboBox(frame_2);
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->addItem(QString());
        comboBox_Condition_Start->setObjectName(QString::fromUtf8("comboBox_Condition_Start"));
        comboBox_Condition_Start->setGeometry(QRect(10, 50, 191, 32));
        comboBox_Condition_Start->setFont(font2);
        comboBox_Condition_Start->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        groupBox = new QGroupBox(frame_Condition);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 110, 911, 91));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(false);
        groupBox->setFont(font6);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:0px;\n"
"color: rgb(0, 255, 255);\n"
"}\n"
""));
        groupBox->setFlat(false);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 8, 661, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 20, 921, 61));
        frame->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        comboBox_Unit = new QComboBox(frame);
        comboBox_Unit->setObjectName(QString::fromUtf8("comboBox_Unit"));
        comboBox_Unit->setGeometry(QRect(10, 10, 861, 32));
        comboBox_Unit->setFont(font2);
        comboBox_Unit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width:35px;\n"
"}"));
        comboBox_Unit->setEditable(true);
        pushButton_Delete = new QPushButton(frame_Condition);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(630, 200, 151, 31));
        pushButton_Delete->setFont(font5);
        pushButton_Delete->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_Run = new QPushButton(tab);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(359, 420, 321, 61));
        QFont font7;
        font7.setPointSize(20);
        font7.setBold(true);
        pushButton_Run->setFont(font7);
        pushButton_Run->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 85, 127);\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"	border-color: rgb(0, 50, 74);\n"
"}\n"
""));
        label_arrowBlink = new QLabel(tab);
        label_arrowBlink->setObjectName(QString::fromUtf8("label_arrowBlink"));
        label_arrowBlink->setGeometry(QRect(120, 50, 41, 22));
        label_Blink_Start = new QLabel(tab);
        label_Blink_Start->setObjectName(QString::fromUtf8("label_Blink_Start"));
        label_Blink_Start->setGeometry(QRect(170, 10, 151, 21));
        label_Blink_Start->setFont(font1);
        label_Blink_Start->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));
        label_Run_Comment = new QLabel(tab);
        label_Run_Comment->setObjectName(QString::fromUtf8("label_Run_Comment"));
        label_Run_Comment->setGeometry(QRect(10, 130, 1021, 31));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setItalic(true);
        label_Run_Comment->setFont(font8);
        label_Run_Comment->setAutoFillBackground(false);
        label_Run_Comment->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_Run_Comment->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 40, 1001, 91));
        graphicsView->setStyleSheet(QString::fromUtf8("background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-image: url(:/image/MFS0103_Unit01.jpg);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        pushButton_Cancel = new QPushButton(tab);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(890, 440, 131, 41));
        pushButton_Cancel->setFont(font5);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        tabWidget_CAR01->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_CAR01->addTab(tab_2, QString());
        Module_MOD1103_Condition->setCentralWidget(centralwidget);

        retranslateUi(Module_MOD1103_Condition);

        tabWidget_CAR01->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Module_MOD1103_Condition);
    } // setupUi

    void retranslateUi(QMainWindow *Module_MOD1103_Condition)
    {
        Module_MOD1103_Condition->setWindowTitle(QCoreApplication::translate("Module_MOD1103_Condition", "MFS1103-Th\341\273\261c h\303\240nh", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget_CAR01->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_Blink_Stop->setText(QCoreApplication::translate("Module_MOD1103_Condition", "\304\220i\341\273\201u ki\341\273\207n k\341\272\277t th\303\272c", nullptr));
        label_Blink_Process->setText(QCoreApplication::translate("Module_MOD1103_Condition", "Qu\303\241 tr\303\254nh", nullptr));
        label_runBlink->setText(QString());
        lineEdit_Condition_Stop->setText(QCoreApplication::translate("Module_MOD1103_Condition", "0", nullptr));
        comboBox_Condition_Stop_Car->setItemText(0, QCoreApplication::translate("Module_MOD1103_Condition", "XE-01", nullptr));
        comboBox_Condition_Stop_Car->setItemText(1, QCoreApplication::translate("Module_MOD1103_Condition", "XE-02", nullptr));
        comboBox_Condition_Stop_Car->setItemText(2, QCoreApplication::translate("Module_MOD1103_Condition", "T\341\272\244T C\341\272\242", nullptr));

        label_5->setText(QCoreApplication::translate("Module_MOD1103_Condition", "\304\220i\341\273\201u ki\341\273\207n k\341\272\277t th\303\272c cho", nullptr));
        comboBox_Condition_Stop->setItemText(0, QCoreApplication::translate("Module_MOD1103_Condition", "Kh\303\264ng c\303\263 \304\221i\341\273\201u ki\341\273\207n", nullptr));
        comboBox_Condition_Stop->setItemText(1, QCoreApplication::translate("Module_MOD1103_Condition", "Qu\303\243ng \304\221\306\260\341\273\235ng (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(2, QCoreApplication::translate("Module_MOD1103_Condition", "Qu\303\243ng \304\221\306\260\341\273\235ng (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(3, QCoreApplication::translate("Module_MOD1103_Condition", "V\341\272\255n t\341\273\221c (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(4, QCoreApplication::translate("Module_MOD1103_Condition", "V\341\272\255n t\341\273\221c (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(5, QCoreApplication::translate("Module_MOD1103_Condition", "Gia t\341\273\221c (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(6, QCoreApplication::translate("Module_MOD1103_Condition", "Gia t\341\273\221c (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(7, QCoreApplication::translate("Module_MOD1103_Condition", "L\341\273\261c t\303\241c \304\221\341\273\231ng (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(8, QCoreApplication::translate("Module_MOD1103_Condition", "L\341\273\261c t\303\241c \304\221\341\273\231ng (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Stop->setItemText(9, QCoreApplication::translate("Module_MOD1103_Condition", "Th\341\273\235i gian (l\341\273\233n h\306\241n)", nullptr));

        label_Condition_Stop_Unit->setText(QCoreApplication::translate("Module_MOD1103_Condition", "(mm/s2)", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("Module_MOD1103_Condition", "L\306\260u", nullptr));
        pushButton_New->setText(QCoreApplication::translate("Module_MOD1103_Condition", "T\341\272\241o m\341\273\233i", nullptr));
        comboBox_Condition_Start_Car->setItemText(0, QCoreApplication::translate("Module_MOD1103_Condition", "XE-01", nullptr));
        comboBox_Condition_Start_Car->setItemText(1, QCoreApplication::translate("Module_MOD1103_Condition", "XE-02", nullptr));
        comboBox_Condition_Start_Car->setItemText(2, QCoreApplication::translate("Module_MOD1103_Condition", "T\341\272\244T C\341\272\242", nullptr));

        label_4->setText(QCoreApplication::translate("Module_MOD1103_Condition", "\304\220i\341\273\201u ki\341\273\207n b\341\272\257t \304\221\341\272\247u cho", nullptr));
        lineEdit_Condition_Start->setText(QCoreApplication::translate("Module_MOD1103_Condition", "0", nullptr));
        label_Condition_Start_Unit->setText(QCoreApplication::translate("Module_MOD1103_Condition", "(mm/s2)", nullptr));
        comboBox_Condition_Start->setItemText(0, QCoreApplication::translate("Module_MOD1103_Condition", "Kh\303\264ng c\303\263 \304\221i\341\273\201u ki\341\273\207n", nullptr));
        comboBox_Condition_Start->setItemText(1, QCoreApplication::translate("Module_MOD1103_Condition", "Qu\303\243ng \304\221\306\260\341\273\235ng (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(2, QCoreApplication::translate("Module_MOD1103_Condition", "Qu\303\243ng \304\221\306\260\341\273\235ng (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(3, QCoreApplication::translate("Module_MOD1103_Condition", "V\341\272\255n t\341\273\221c (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(4, QCoreApplication::translate("Module_MOD1103_Condition", "V\341\272\255n t\341\273\221c (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(5, QCoreApplication::translate("Module_MOD1103_Condition", "Gia t\341\273\221c (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(6, QCoreApplication::translate("Module_MOD1103_Condition", "Gia t\341\273\221c (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(7, QCoreApplication::translate("Module_MOD1103_Condition", "L\341\273\261c t\303\241c \304\221\341\273\231ng (l\341\273\233n h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(8, QCoreApplication::translate("Module_MOD1103_Condition", "L\341\273\261c t\303\241c \304\221\341\273\231ng (nh\341\273\217 h\306\241n)", nullptr));
        comboBox_Condition_Start->setItemText(9, QCoreApplication::translate("Module_MOD1103_Condition", "Th\341\273\235i gian (l\341\273\233n h\306\241n)", nullptr));

        groupBox->setTitle(QCoreApplication::translate("Module_MOD1103_Condition", "C\303\241c b\303\240i th\341\273\261c h\303\240nh c\306\241 b\341\272\243n", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("Module_MOD1103_Condition", "X\303\263a", nullptr));
        pushButton_Run->setText(QCoreApplication::translate("Module_MOD1103_Condition", "Th\341\273\261c hi\341\273\207n", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Run->setShortcut(QCoreApplication::translate("Module_MOD1103_Condition", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        label_arrowBlink->setText(QString());
        label_Blink_Start->setText(QCoreApplication::translate("Module_MOD1103_Condition", "\304\220i\341\273\201u ki\341\273\207n b\341\272\257t \304\221\341\272\247u", nullptr));
        label_Run_Comment->setText(QCoreApplication::translate("Module_MOD1103_Condition", "H\306\260\341\273\233ng d\341\272\253n", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Module_MOD1103_Condition", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("Module_MOD1103_Condition", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget_CAR01->setTabText(tabWidget_CAR01->indexOf(tab), QCoreApplication::translate("Module_MOD1103_Condition", "       Th\341\273\261c h\303\240nh       ", nullptr));
        tabWidget_CAR01->setTabText(tabWidget_CAR01->indexOf(tab_2), QCoreApplication::translate("Module_MOD1103_Condition", "          C\303\240i \304\221\341\272\267t          ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Module_MOD1103_Condition: public Ui_Module_MOD1103_Condition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_MOD1103_CONDITION_H
