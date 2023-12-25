/********************************************************************************
** Form generated from reading UI file 'addnewdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWDEVICE_H
#define UI_ADDNEWDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewDevice
{
public:
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_Infor_Description;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Info_Name;
    QComboBox *comboBox_typeDevice;
    QLineEdit *lineEdit_Info_SerialNumber;
    QPushButton *pushButton_Infor_Icon;
    QLabel *label_5;
    QLabel *label_search;
    QComboBox *comboBox_Search;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Cancel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Search;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_AddDevice;
    QPushButton *pushButton_Update;
    QPushButton *pushButton_Remove;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_getSerialFromSearch;
    QGroupBox *groupBox;
    QTableView *tableView_Device;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_ListDevice_Update;
    QPushButton *pushButton_ListDevice_Replace;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_ListDevice_Save;

    void setupUi(QWidget *AddNewDevice)
    {
        if (AddNewDevice->objectName().isEmpty())
            AddNewDevice->setObjectName(QString::fromUtf8("AddNewDevice"));
        AddNewDevice->setWindowModality(Qt::ApplicationModal);
        AddNewDevice->resize(1040, 610);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/AddDevice_icon_2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        AddNewDevice->setWindowIcon(icon);
        groupBox_2 = new QGroupBox(AddNewDevice);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(560, 10, 501, 600));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox_2->setFont(font);
        groupBox_2->setFlat(false);
        textEdit_Infor_Description = new QTextEdit(groupBox_2);
        textEdit_Infor_Description->setObjectName(QString::fromUtf8("textEdit_Infor_Description"));
        textEdit_Infor_Description->setGeometry(QRect(30, 420, 281, 101));
        textEdit_Infor_Description->setReadOnly(false);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 396, 209, 23));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 120, 121, 110));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 120, 301, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_Info_Name = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_Info_Name->setObjectName(QString::fromUtf8("lineEdit_Info_Name"));
        lineEdit_Info_Name->setMaxLength(20);
        lineEdit_Info_Name->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        verticalLayout_2->addWidget(lineEdit_Info_Name);

        comboBox_typeDevice = new QComboBox(verticalLayoutWidget_2);
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->addItem(QString());
        comboBox_typeDevice->setObjectName(QString::fromUtf8("comboBox_typeDevice"));

        verticalLayout_2->addWidget(comboBox_typeDevice);

        lineEdit_Info_SerialNumber = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_Info_SerialNumber->setObjectName(QString::fromUtf8("lineEdit_Info_SerialNumber"));
        lineEdit_Info_SerialNumber->setMaxLength(20);
        lineEdit_Info_SerialNumber->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        verticalLayout_2->addWidget(lineEdit_Info_SerialNumber);

        pushButton_Infor_Icon = new QPushButton(groupBox_2);
        pushButton_Infor_Icon->setObjectName(QString::fromUtf8("pushButton_Infor_Icon"));
        pushButton_Infor_Icon->setGeometry(QRect(310, 290, 100, 100));
        pushButton_Infor_Icon->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        pushButton_Infor_Icon->setIconSize(QSize(100, 100));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 290, 131, 32));
        label_search = new QLabel(groupBox_2);
        label_search->setObjectName(QString::fromUtf8("label_search"));
        label_search->setGeometry(QRect(30, 40, 431, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        label_search->setFont(font1);
        comboBox_Search = new QComboBox(groupBox_2);
        comboBox_Search->setObjectName(QString::fromUtf8("comboBox_Search"));
        comboBox_Search->setGeometry(QRect(30, 70, 291, 32));
        comboBox_Search->setEditable(true);
        comboBox_Search->setMaxCount(12);
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 550, 431, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Cancel = new QPushButton(horizontalLayoutWidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setFont(font);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        horizontalLayout->addWidget(pushButton_Cancel);

        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(330, 70, 131, 32));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Search = new QPushButton(horizontalLayoutWidget_2);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));
        pushButton_Search->setFont(font);
        pushButton_Search->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        horizontalLayout_2->addWidget(pushButton_Search);

        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(320, 420, 151, 104));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_AddDevice = new QPushButton(verticalLayoutWidget_3);
        pushButton_AddDevice->setObjectName(QString::fromUtf8("pushButton_AddDevice"));
        pushButton_AddDevice->setFont(font);
        pushButton_AddDevice->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        verticalLayout_3->addWidget(pushButton_AddDevice);

        pushButton_Update = new QPushButton(verticalLayoutWidget_3);
        pushButton_Update->setObjectName(QString::fromUtf8("pushButton_Update"));
        pushButton_Update->setFont(font);
        pushButton_Update->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        verticalLayout_3->addWidget(pushButton_Update);

        pushButton_Remove = new QPushButton(verticalLayoutWidget_3);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setFont(font);
        pushButton_Remove->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        verticalLayout_3->addWidget(pushButton_Remove);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 330, 161, 32));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        label_6->setFont(font2);
        horizontalLayoutWidget_5 = new QWidget(groupBox_2);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(160, 230, 301, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_getSerialFromSearch = new QPushButton(horizontalLayoutWidget_5);
        pushButton_getSerialFromSearch->setObjectName(QString::fromUtf8("pushButton_getSerialFromSearch"));

        horizontalLayout_5->addWidget(pushButton_getSerialFromSearch);

        groupBox = new QGroupBox(AddNewDevice);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 521, 541));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setFlat(false);
        tableView_Device = new QTableView(groupBox);
        tableView_Device->setObjectName(QString::fromUtf8("tableView_Device"));
        tableView_Device->setGeometry(QRect(0, 30, 511, 511));
        tableView_Device->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 214, 214);"));
        horizontalLayoutWidget_3 = new QWidget(AddNewDevice);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 560, 313, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_ListDevice_Update = new QPushButton(horizontalLayoutWidget_3);
        pushButton_ListDevice_Update->setObjectName(QString::fromUtf8("pushButton_ListDevice_Update"));
        pushButton_ListDevice_Update->setFont(font);
        pushButton_ListDevice_Update->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        horizontalLayout_3->addWidget(pushButton_ListDevice_Update);

        pushButton_ListDevice_Replace = new QPushButton(horizontalLayoutWidget_3);
        pushButton_ListDevice_Replace->setObjectName(QString::fromUtf8("pushButton_ListDevice_Replace"));
        pushButton_ListDevice_Replace->setFont(font);
        pushButton_ListDevice_Replace->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        horizontalLayout_3->addWidget(pushButton_ListDevice_Replace);

        horizontalLayoutWidget_4 = new QWidget(AddNewDevice);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(380, 560, 151, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_ListDevice_Save = new QPushButton(horizontalLayoutWidget_4);
        pushButton_ListDevice_Save->setObjectName(QString::fromUtf8("pushButton_ListDevice_Save"));
        pushButton_ListDevice_Save->setFont(font);
        pushButton_ListDevice_Save->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));

        horizontalLayout_4->addWidget(pushButton_ListDevice_Save);


        retranslateUi(AddNewDevice);

        QMetaObject::connectSlotsByName(AddNewDevice);
    } // setupUi

    void retranslateUi(QWidget *AddNewDevice)
    {
        AddNewDevice->setWindowTitle(QCoreApplication::translate("AddNewDevice", "STEMe - Th\303\252m thi\341\272\277t b\341\273\213 m\341\273\233i", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AddNewDevice", "Th\303\264ng tin chi ti\341\272\277t v\341\273\201 thi\341\272\277t b\341\273\213", nullptr));
        label_4->setText(QCoreApplication::translate("AddNewDevice", "M\303\264 t\341\272\243 v\341\273\201 thi\341\272\277t b\341\273\213:", nullptr));
        label_2->setText(QCoreApplication::translate("AddNewDevice", "T\303\252n thi\341\272\277t b\341\273\213:", nullptr));
        label->setText(QCoreApplication::translate("AddNewDevice", "Lo\341\272\241i thi\341\272\277t b\341\273\213:", nullptr));
        label_3->setText(QCoreApplication::translate("AddNewDevice", "M\303\243 s\303\252-ri:", nullptr));
        lineEdit_Info_Name->setPlaceholderText(QCoreApplication::translate("AddNewDevice", "t\303\252n g\341\273\243i nh\341\273\233...", nullptr));
        comboBox_typeDevice->setItemText(0, QCoreApplication::translate("AddNewDevice", "C\341\272\243m bi\341\272\277n", nullptr));
        comboBox_typeDevice->setItemText(1, QCoreApplication::translate("AddNewDevice", "M\303\264-\304\221un th\341\273\261c h\303\240nh", nullptr));
        comboBox_typeDevice->setItemText(2, QCoreApplication::translate("AddNewDevice", "M\303\264 h\303\254nh th\303\255 nghi\341\273\207m", nullptr));
        comboBox_typeDevice->setItemText(3, QCoreApplication::translate("AddNewDevice", "C\303\240i \304\221\341\272\267t v\303\240 ti\341\273\207n \303\255ch", nullptr));
        comboBox_typeDevice->setItemText(4, QCoreApplication::translate("AddNewDevice", "Qu\341\272\243n l\303\275", nullptr));

        lineEdit_Info_SerialNumber->setPlaceholderText(QCoreApplication::translate("AddNewDevice", "SN c\303\263 12 k\303\255 t\341\273\261...", nullptr));
        pushButton_Infor_Icon->setText(QString());
        label_5->setText(QCoreApplication::translate("AddNewDevice", "Bi\341\273\203u t\306\260\341\273\243ng (Icon):", nullptr));
        label_search->setText(QCoreApplication::translate("AddNewDevice", "Nh\341\272\255p s\341\273\221 s\303\252-ri c\341\273\247a thi\341\272\277t b\341\273\213", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("AddNewDevice", "Tho\303\241t", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("AddNewDevice", "T\303\254m ki\341\272\277m", nullptr));
        pushButton_AddDevice->setText(QCoreApplication::translate("AddNewDevice", "Th\303\252m m\341\273\233i", nullptr));
        pushButton_Update->setText(QCoreApplication::translate("AddNewDevice", "S\341\273\255a", nullptr));
        pushButton_Remove->setText(QCoreApplication::translate("AddNewDevice", "X\303\263a", nullptr));
        label_6->setText(QCoreApplication::translate("AddNewDevice", "    Nh\341\272\245n \304\221\341\273\203 ch\341\273\215n h\303\254nh =>", nullptr));
        pushButton_getSerialFromSearch->setText(QCoreApplication::translate("AddNewDevice", "L\341\272\245y m\303\243 s\303\252-ri t\341\273\253 thanh \"T\303\254m ki\341\272\277m\"", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_getSerialFromSearch->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QCoreApplication::translate("AddNewDevice", "Danh s\303\241ch thi\341\272\277t b\341\273\213", nullptr));
        pushButton_ListDevice_Update->setText(QCoreApplication::translate("AddNewDevice", "C\341\272\255p nh\341\272\255t danh s\303\241ch", nullptr));
        pushButton_ListDevice_Replace->setText(QCoreApplication::translate("AddNewDevice", "T\341\272\243i danh s\303\241ch m\341\273\233i", nullptr));
        pushButton_ListDevice_Save->setText(QCoreApplication::translate("AddNewDevice", "L\306\260u danh s\303\241ch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewDevice: public Ui_AddNewDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWDEVICE_H
