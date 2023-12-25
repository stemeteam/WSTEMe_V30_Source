#include "vformlogin.h"
#include "ui_vformlogin.h"
#include "QMessageBox"
#include "QDateTime"
#include "vuser.h"
#include "mainwindow.h"
#include "vlogin/vlistuser.h"
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/qserialportinfo.h>


VFormLogin::VFormLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VFormLogin)
{
    ui->setupUi(this);
    lineEdit = new QLineEdit(this);
    this->setGeometry(0,60,this->width(),this->height());
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  rec = screen->geometry();
    this->setGeometry((rec.width()-this->width())/2,(rec.height()-this->height())/2,this->width(),this->height());

    lineEdit->setFont(QFont("Segoe UI", 10, QFont::Bold));
    ui->comboBox_Account->setLineEdit(lineEdit);
    ui->pushButton_Login->setAutoFillBackground(true);
    ui->pushButton_Login->setFocusPolicy(Qt::StrongFocus);

    QList<QString> _accList;
    VListUser _listUser;
    if(_listUser.count()<2){
        VUser _user;
        _user.setAccount("student");
        _user.setPassword("");
        _user.setUserType(VUser::student);
        _user.setDateCreate(QDateTime::currentDateTimeUtc().toString());
        _listUser.append(_user);
        _user.setDateCreate(QDateTime::currentDateTimeUtc().toString());
        _user.setAccount("teacher");
        _user.setPassword("12345678");
        _user.setUserType(VUser::teacher);
        _listUser.append(_user);
        _user.setAccount("root");
        _user.setPassword("12345678");
        _user.setUserType(VUser::root);
        _listUser.append(_user);


    }

    for(int i=0;i<_listUser.count();i++)_accList.append(_listUser.user(i).account());
    for(int i=0;i<_accList.count();i++){
        ui->comboBox_Account->addItem(_accList.at(i));
        if(i>5)break;
    }

    //Com port
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
        QList<QSerialPortInfo>::iterator p;
        for (p = list.begin(); p != list.end(); ++p)
        {
            if(p->portName()!="COM1")ui->comboBox_Port->addItem(p->portName());
        }
    ui->comboBox_Port->addItem("COM1");
}

VFormLogin::~VFormLogin()
{
    delete ui;
}

void VFormLogin::on_loggout()
{
    this->show();
    this->ui->lineEdit_Password->setText("");
}

void VFormLogin::on_pushButton_Login_clicked()
{
    VListUser _luser;
    VUser _user = _luser.user(lineEdit->text());
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowIcon(this->windowIcon());

    if(lineEdit->text()==""){
        msg.setText("Tên đăng nhập không được để trống!");
        msg.exec();
        return;
    }
    if(_user.account()=="") {
        msg.setText("Tên đăng nhập không tồn tại!");
        msg.exec();
        return;
    }

    if(QString::compare(ui->lineEdit_Password->text(),_user.password(),Qt::CaseSensitive)!=0) {
        msg.setText("Mật khẩu của tài khoản không đúng!\n"
                    "    - Mật khẩu có phân biệt chữ hoa và chữ thường.");
        msg.exec();
        return;
    }

    w.setNamePort(ui->comboBox_Port->currentText());
    if(!w.connectModbus())return;
    w.setUserLogin(_user);
    w.Refresh();
    connect(&w,&MainWindow::set_loggout,this,&VFormLogin::on_loggout);
    w.show();
    this->hide();
}

void VFormLogin::on_lineEdit_Password_textChanged(const QString &)
{

}

void VFormLogin::on_comboBox_Account_currentTextChanged(const QString &arg1)
{
    VListUser _luser;
    VUser _user = _luser.user(arg1);
    if(_user.account()!=""){
        switch(_user.accountType()){
        case VUser::root:ui->label_accountType->setText("Root (Quản lý)");
            break;
        case VUser::teacher:ui->label_accountType->setText("Teacher (Giáo viên)");
            break;
        case VUser::student:ui->label_accountType->setText("Student (Học sinh)");
            break;
        }
    }
}



