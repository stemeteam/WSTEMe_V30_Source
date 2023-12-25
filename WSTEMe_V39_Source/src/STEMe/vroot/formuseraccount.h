#ifndef FORMUSERACCOUNT_H
#define FORMUSERACCOUNT_H

#include <QWidget>
#include <vlogin/vuser.h>

namespace Ui {
class FormUserAccount;
}

class FormUserAccount : public QWidget
{
    Q_OBJECT

public:
    explicit FormUserAccount(QWidget *parent = nullptr);
    ~FormUserAccount();
    void setUserAccount(VUser user);

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_ChangePassword_NewCreat_clicked();

    void on_pushButton_ChangePassword_clicked();

    void on_pushButton_Remove_clicked();

private:
    Ui::FormUserAccount *ui;
    VUser m_user;
};

#endif // FORMUSERACCOUNT_H
