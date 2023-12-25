#ifndef VLISTUSER_H
#define VLISTUSER_H

#include <vlogin/vuser.h>


class VListUser
{

public:
    VListUser();

    VUser user(QString account)const;
    VUser user(int index)const;
    bool contains(VUser user) const;
    int  indexOfUser(VUser user) const{
        return checkUser(user,loadUsers());
    }
    int count() const{
        return loadUsers().count();
    }

    bool append(VUser user);
    bool update(VUser user);
    bool remove(VUser user);


signals:

public slots:



private:
    QList<VUser> loadUsers() const;
    void saveUsers(QList<VUser> listUser);
    int checkUser(VUser user,QList<VUser> luser) const;
};

#endif // VLISTUSER_H
