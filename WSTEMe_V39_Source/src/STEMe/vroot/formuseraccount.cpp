#include "formuseraccount.h"
#include "ui_formuseraccount.h"
#include <QMessageBox>
#include "vlogin/vlistuser.h"
#include <QDateTime>

FormUserAccount::FormUserAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUserAccount)
{
    ui->setupUi(this);
}

FormUserAccount::~FormUserAccount()
{
    delete ui;
}

void FormUserAccount::setUserAccount(VUser user)
{
    VListUser _listUser;
     m_user = user;
     ui->label_Info_Account->setText(user.account());
     ui->label_Info_Type->setText(user.accountTypeText());
     ui->label_Info_Date->setText(user.dateCreate());
     ui->comboBox_RemoveAccount->clear();
     for(int i=0;i<_listUser.count();i++){
         ui->comboBox_RemoveAccount->addItem(_listUser.user(i).account());
     }

}

void FormUserAccount::on_pushButton_Cancel_clicked()
{
    this->close();
}

void FormUserAccount::on_pushButton_ChangePassword_NewCreat_clicked()
{
    VListUser _listUser;
    VUser _user;

    if(ui->lineEdit_NewAccount->text().count()<3) {
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Tên tài khoản cần phải lớn hơn 2 kí tự.",QMessageBox::Ok);
        return;
        }
    //Kiem tra do dai password
//    if(ui->lineEdit_NewPassword->text().count()<8) {
//        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Mật khẩu của tài khoản không đúng, mật khẩu có phân biệt chữ hoa và chữ thường và phải từ 8 ki tự trở lên.",QMessageBox::Ok);
//        return;
//        }
    //Kiem tra password va repassword
    if(QString::compare(ui->lineEdit_NewPassword->text(),ui->lineEdit_NewRePassword->text(),Qt::CaseSensitive)!=0) {
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Mật khẩu của tài khoản không trùng khớp, mật khẩu có phân biệt chữ hoa và chữ thường!",QMessageBox::Ok);
        return;
        }
    if(m_user.accountType()==VUser::student)
    {
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Tài khoản \'Student\' không được phép tạo tài khoản!",QMessageBox::Ok);
        return;
    }
    if(m_user.accountType()==VUser::teacher && ui->comboBox_NewType->currentIndex()<2)
    {
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Tài khoản \'Teacher\' chỉ được phep tạo tai khoản student!",QMessageBox::Ok);
        return;
    }

    _user.setAccount(ui->lineEdit_NewAccount->text());
    _user.setPassword(ui->lineEdit_NewPassword->text());
    switch(ui->comboBox_NewType->currentIndex())
    {
    case 0:_user.setUserType(VUser::root);
        break;
    case 1:_user.setUserType(VUser::teacher);
        break;
    case 2:_user.setUserType(VUser::student);
        break;
    }
    _user.setDateCreate(QDateTime::currentDateTime().toString());
    if(_listUser.append(_user)){
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Tài khoản \'" + _user.account() + "\' đã được tạo mới.",QMessageBox::Ok);

        ui->comboBox_RemoveAccount->clear();
        for(int i=0;i<_listUser.count();i++){
            ui->comboBox_RemoveAccount->addItem(_listUser.user(i).account());
        }
        ui->lineEdit_NewAccount->clear();
        ui->lineEdit_NewPassword->clear();
        ui->lineEdit_NewRePassword->clear();
    }
    else {
        QMessageBox::warning(nullptr,"STEMe - Tạo tài khoản","Tài khoản \'" + _user.account() + "\' đã tồn tại. Thay đổi tên tai khoản và tạo lại.",QMessageBox::Ok);
        return;
    }
}

void FormUserAccount::on_pushButton_ChangePassword_clicked()
{
    VListUser _listUser;
    //Kiem tra password cu
    if(QString::compare(ui->lineEdit_ChangePassword->text(),m_user.password(),Qt::CaseSensitive)!=0) {
        QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Mật khẩu của tài khoản cũ không đúng, mật khẩu có phân biệt chữ hoa và chữ thường!",QMessageBox::Ok);
        return;
        }
    //Kiem tra do dai password
    if(ui->lineEdit_ChangeNewPassword->text().count()<8) {
        QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Mật khẩu của tài khoản không đúng, mật khẩu có phân biệt chữ hoa và chữ thường và phải từ 8 ki tự trở lên.",QMessageBox::Ok);
        return;
        }
    //Kiem tra password va repassword
    if(QString::compare(ui->lineEdit_ChangeNewPassword->text(),ui->lineEdit_ChangeRePassword->text(),Qt::CaseSensitive)!=0) {
        QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Mật khẩu của tài khoản không trùng khớp, mật khẩu có phân biệt chữ hoa và chữ thường!",QMessageBox::Ok);
        return;
        }
    m_user.setPassword(ui->lineEdit_ChangeNewPassword->text());
    if(_listUser.update(m_user)){
        QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Đã đổi mật khẩu tài khoản thành công",QMessageBox::Ok);
        ui->lineEdit_ChangePassword->clear();
        ui->lineEdit_ChangeNewPassword->clear();
        ui->lineEdit_ChangeRePassword->clear();
    }
    else QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Lỗi cập nhật mật khẩu! Kiểm tra và thử lại!",QMessageBox::Ok);
}

void FormUserAccount::on_pushButton_Remove_clicked()
{
    VListUser _listUser;
    VUser _user;
    _user = _listUser.user(ui->comboBox_RemoveAccount->currentText());
    if(_user.account()==""){
        QMessageBox::warning(nullptr,"STEMe - Xóa tài khoản","Lỗi! Không tồn tại tài khoản cần xóa.",QMessageBox::Ok);
        return;
    }
    //Kiem tra password cu
    if(QString::compare(ui->lineEdit_RemovePassword->text(),_user.password(),Qt::CaseSensitive)!=0) {
        QMessageBox::warning(nullptr,"STEMe - Xóa tài khoản","Mật khẩu của tài khoản cũ không đúng, mật khẩu có phân biệt chữ hoa và chữ thường!",QMessageBox::Ok);
        return;
        }
    //Kiem tra password va repassword
    if(QString::compare(ui->lineEdit_RemovePassword->text(),ui->lineEdit_RemoveRePassword->text(),Qt::CaseSensitive)!=0) {
        QMessageBox::warning(nullptr,"STEMe - Xóa tài khoản","Mật khẩu của tài khoản không trùng khớp, mật khẩu có phân biệt chữ hoa và chữ thường!",QMessageBox::Ok);
        return;
        }
    if(_listUser.remove(_user)){
        QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Đã xóa tài khoản \'" + _user.account() + "\'..",QMessageBox::Ok);
        ui->comboBox_RemoveAccount->clear();
        for(int i=0;i<_listUser.count();i++){
            ui->comboBox_RemoveAccount->addItem(_listUser.user(i).account());
        }
        ui->lineEdit_RemovePassword->clear();
        ui->lineEdit_RemoveRePassword->clear();
    }
    else QMessageBox::warning(nullptr,"STEMe - Đổi mật khẩu","Lỗi! Tài khoản không tồn tại hoặc sai mật khẩu. Kiểm tra và thử lại!",QMessageBox::Ok);

}
