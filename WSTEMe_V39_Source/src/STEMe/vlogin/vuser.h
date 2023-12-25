#ifndef VUSERLOGIN_H
#define VUSERLOGIN_H

#include <QObject>
#include <QList>

class VUser
{

public:
    VUser();

    enum UserType{
        root,
        teacher,
        student
    };

    inline QString account() const {
        return m_account;
    }
    inline QString password() const {
        return m_password;
    }
    inline QString dateCreate() const {
        return m_datecreate;
    }
    inline UserType accountType() const {
        return m_usertype;
    }
    QString accountTypeText();
    inline QList<QString> listDevices() const {
        return m_listDevices;
    }

    VUser* User(QString Account);

    //set Properties
    inline void setAccount(QString newAccount){
        m_account= newAccount;
    }
    inline void setPassword(QString newPassword){
        m_password = newPassword;
    }
    inline void setDateCreate(QString dateCreate){
        m_datecreate = dateCreate;
    }
    inline void setUserType(UserType newType){
        m_usertype = newType;
    }

    inline void setListDevices(QList<QString> newList){
        m_listDevices = newList;
    }

signals:

public slots:

private:

    QString m_account ="";
    QString m_password="";
    UserType  m_usertype = UserType::student;
    QList<QString> m_listDevices; //list of devices that user is used.
    QString m_datecreate="";
};

#endif // VUSERLOGIN_H
