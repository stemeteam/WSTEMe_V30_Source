/********************************************************************************
** Form generated from reading UI file 'aboutsteme.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSTEME_H
#define UI_ABOUTSTEME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutSteme
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Loggout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton_Cancel;

    void setupUi(QMainWindow *AboutSteme)
    {
        if (AboutSteme->objectName().isEmpty())
            AboutSteme->setObjectName(QString::fromUtf8("AboutSteme"));
        AboutSteme->resize(470, 558);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        AboutSteme->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/STEMe_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutSteme->setWindowIcon(icon);
        centralwidget = new QWidget(AboutSteme);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Loggout_2 = new QPushButton(centralwidget);
        pushButton_Loggout_2->setObjectName(QString::fromUtf8("pushButton_Loggout_2"));
        pushButton_Loggout_2->setGeometry(QRect(2, 10, 141, 20));
        QFont font1;
        font1.setBold(true);
        pushButton_Loggout_2->setFont(font1);
        pushButton_Loggout_2->setAutoFillBackground(false);
        pushButton_Loggout_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: rgb(255, 255, 255);"));
        pushButton_Loggout_2->setIcon(icon);
        pushButton_Loggout_2->setIconSize(QSize(150, 25));
        pushButton_Loggout_2->setAutoDefault(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 301, 22));
        label->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 451, 471));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        textEdit->setReadOnly(true);
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(140, 520, 191, 31));
        AboutSteme->setCentralWidget(centralwidget);
        QWidget::setTabOrder(pushButton_Cancel, textEdit);
        QWidget::setTabOrder(textEdit, pushButton_Loggout_2);

        retranslateUi(AboutSteme);

        pushButton_Loggout_2->setDefault(false);


        QMetaObject::connectSlotsByName(AboutSteme);
    } // setupUi

    void retranslateUi(QMainWindow *AboutSteme)
    {
        AboutSteme->setWindowTitle(QCoreApplication::translate("AboutSteme", "About", nullptr));
        pushButton_Loggout_2->setText(QString());
        label->setText(QCoreApplication::translate("AboutSteme", "STEMe V3.0 - Ph\341\272\247n m\341\273\201m gi\303\241o d\341\273\245c", nullptr));
        textEdit->setHtml(QCoreApplication::translate("AboutSteme", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-weight:600;\">Ph\341\272\247n m\341\273\201m</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	H\341\273\207 \304\221i\341\273\201u h\303\240nh:  </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">Debian</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Ng\303\264n ng\341\273\257 :       </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">C++</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Gi\341\272\245y ph\303\251p: 	      </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">m\303\243 ngu\341\273\223n m\341\273\237</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-weight:600;\">Ph\341\272\247n c\341\273\251ng</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-"
                        "size:12pt;\">\357\202\247	Vi x\341\273\255 l\303\275: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">BCM2711, Cortex-A72 (ARM v8) </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">		     64-bit SoC 1.5GHz</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	RAM: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">4GB LPDDR4-2400 SDRAM</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Wifi: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:it"
                        "alic;\">2.4GHz, 5.0GHz IEEE802.11ac</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Bluetooth:</span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-weight:600;\"> 	</span><span style=\" font-family:'PibotoLt'; font-size:12pt;\">     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">5.0 BLE</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	USB: 	     2-</span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">USB2.0, 2-USB3.0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\""
                        ">	</span><span style=\" font-family:'PibotoLt'; font-size:12pt;\">C\341\273\225ng m\341\272\241ng:      </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">Gigabit Ethernet</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	HDMI: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">\304\221\341\273\231 ph\303\242n gi\341\272\243i 4K</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	VPS: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">2 (c\341\273\225ng giao ti\341\272\277p c\341\272\243m bi\341\272\277n)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">	</span><span style=\" font-family:'PibotoLt'; font-size:12pt;\">Th\341\272\273 nh\341\273\233</span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">: 	</span><span style=\" font-family:'PibotoLt'; font-size:12pt;\">     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">128G (cho H\341\273\207 \304\221i\341\273\201u h\303\240nh v\303\240 d\341\273\257 li\341\273\207u</span><span style=\" font-family:'PibotoLt'; font-size:12pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Ngu\341\273\223n c\341\272\245p:     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">12V/5A</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt; font-weight:600;\">M\303\240n h\303\254nh</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	K\303\255ch th\306\260\341\273\233c:      </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">10.1 inch</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	\304\220\341\273\231 ph\303\242n gi\341\272\243i:   </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">1280x800</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-s"
                        "ize:12pt;\">\357\202\247	C\341\272\243m \341\273\251ng: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">C\341\272\243m \341\273\251ng \304\221i\341\273\207n dung</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'PibotoLt'; font-size:12pt;\">\357\202\247	Giao ti\341\272\277p: 	     </span><span style=\" font-family:'PibotoLt'; font-size:12pt; font-style:italic;\">HDMI</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'PibotoLt'; font-size:12pt;\"><br /></p></body></html>", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("AboutSteme", "Tho\303\241t", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Cancel->setShortcut(QCoreApplication::translate("AboutSteme", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class AboutSteme: public Ui_AboutSteme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSTEME_H
