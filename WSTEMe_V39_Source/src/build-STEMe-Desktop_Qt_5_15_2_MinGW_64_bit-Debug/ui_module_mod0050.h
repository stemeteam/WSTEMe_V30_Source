/********************************************************************************
** Form generated from reading UI file 'module_mod0050.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_MOD0050_H
#define UI_MODULE_MOD0050_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Module_MOD0050
{
public:
    QRadioButton *radioButton_Continuously;
    QRadioButton *radioButton_Accumulation;
    QPushButton *pushButton;

    void setupUi(QWidget *Module_MOD0050)
    {
        if (Module_MOD0050->objectName().isEmpty())
            Module_MOD0050->setObjectName(QString::fromUtf8("Module_MOD0050"));
        Module_MOD0050->resize(331, 135);
        Module_MOD0050->setStyleSheet(QString::fromUtf8("background-color: #132630;"));
        radioButton_Continuously = new QRadioButton(Module_MOD0050);
        radioButton_Continuously->setObjectName(QString::fromUtf8("radioButton_Continuously"));
        radioButton_Continuously->setGeometry(QRect(60, 30, 141, 27));
        radioButton_Continuously->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Continuously->setChecked(true);
        radioButton_Accumulation = new QRadioButton(Module_MOD0050);
        radioButton_Accumulation->setObjectName(QString::fromUtf8("radioButton_Accumulation"));
        radioButton_Accumulation->setGeometry(QRect(60, 60, 211, 27));
        radioButton_Accumulation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        radioButton_Accumulation->setChecked(false);
        pushButton = new QPushButton(Module_MOD0050);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 100, 99, 30));

        retranslateUi(Module_MOD0050);

        QMetaObject::connectSlotsByName(Module_MOD0050);
    } // setupUi

    void retranslateUi(QWidget *Module_MOD0050)
    {
        Module_MOD0050->setWindowTitle(QCoreApplication::translate("Module_MOD0050", "Form", nullptr));
        radioButton_Continuously->setText(QCoreApplication::translate("Module_MOD0050", "H\341\273\207 con l\341\272\257c l\303\262 xo", nullptr));
        radioButton_Accumulation->setText(QCoreApplication::translate("Module_MOD0050", "H\341\273\207 \304\221o l\341\273\261c c\341\272\243n c\341\273\247a n\306\260\341\273\233c", nullptr));
        pushButton->setText(QCoreApplication::translate("Module_MOD0050", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Module_MOD0050: public Ui_Module_MOD0050 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_MOD0050_H
