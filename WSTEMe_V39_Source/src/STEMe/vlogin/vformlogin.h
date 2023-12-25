#ifndef VFORMLOGIN_H
#define VFORMLOGIN_H

#include <QWidget>
#include <QEvent>
#include <QLineEdit>
#include <vlogin/vuser.h>
#include <mainwindow.h>

namespace Ui {
class VFormLogin;
}

class VFormLogin : public QWidget
{
    Q_OBJECT

public:
    explicit VFormLogin(QWidget *parent = nullptr);
    ~VFormLogin();

    inline QString namePort(){return m_namePort;}

private slots:
    void on_loggout();
    void on_pushButton_Login_clicked();

    void on_lineEdit_Password_textChanged(const QString &arg1);

    void on_comboBox_Account_currentTextChanged(const QString &arg1);


private:
    Ui::VFormLogin *ui;  
    MainWindow w;
    QLineEdit *lineEdit;

    QString m_namePort="COM1";
};

#endif // VFORMLOGIN_H
