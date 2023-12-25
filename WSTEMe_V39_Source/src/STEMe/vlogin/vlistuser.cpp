#include "vlistuser.h"
#include <QSettings>

VListUser::VListUser()
{

}


VUser VListUser::user(int index) const
{
    QList<VUser> _luser = loadUsers();
    VUser _u;
    if(_luser.count()<=index)return _u;
    return _luser[index];
}

VUser VListUser::user(QString account) const
{
    VUser _u;
    QList<VUser> _luser = loadUsers();
    if(!_luser.isEmpty())
    {
        for(int i=0;i<_luser.count();i++){
            if(QString::compare(_luser[i].account(),account,Qt::CaseInsensitive)==0)return _luser[i];
        }
    }
    return _u;
}

bool VListUser::contains(VUser user) const
{
    if(checkUser(user,loadUsers())==-1){
        return false;
    }
    return true;
}

bool VListUser::append(VUser user)
{
    QList<VUser> _luser = loadUsers();
    if(checkUser(user,_luser)!=-1)return false;
    _luser.append(user);
    this->saveUsers(_luser);
    return true;
}

bool VListUser::update(VUser user)
{
   QList<VUser> _luser = loadUsers();
   int _index = checkUser(user,_luser);
   if(_index ==-1)return false;
   _luser.replace(_index,user);
   this->saveUsers(_luser);
   return true;
}

bool VListUser::remove(VUser user)
{
    QList<VUser> _luser = loadUsers();
    int _index = checkUser(user,_luser);
    if(_index ==-1)return false;
    _luser.removeAt(_index);
    this->saveUsers(_luser);
    return true;
}

QList<VUser> VListUser::loadUsers() const
{
    QList<VUser> _listUser;
    VUser _user;
    QSettings settings("ELEVOI","VDAT");
    int size = settings.beginReadArray("VUserLoggin");
    if(size<1)return _listUser;
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        _user.setAccount(settings.value("account","euwdjfisjf329428282428jejfsjj").toString());
        _user.setPassword(settings.value("password","jdsajfwjfwjfoj273482342").toString());
        switch(settings.value("usertype","root").toInt()){
        case 0:_user.setUserType(VUser::root);
            break;
         case 1:_user.setUserType(VUser::teacher);
            break;
        case 2:_user.setUserType(VUser::student);
            break;
        }
       _user.setListDevices(settings.value("listDevices","jdsajfwjfwjfoj273482342").toStringList());
        _listUser.append(_user);
    }
    settings.endArray();
    return _listUser;
}

void VListUser::saveUsers(QList<VUser> listUser)
{
        QSettings settings("ELEVOI","VDAT");
        settings.beginWriteArray("VUserLoggin");
        settings.remove("");
        for (int i = 0; i < listUser.count(); ++i) {
            settings.setArrayIndex(i);
            settings.setValue("account", listUser[i].account());
            settings.setValue("password", listUser[i].password());
            switch(listUser[i].accountType()){
            case VUser::root:settings.setValue("usertype",0);
                break;
            case VUser::teacher:settings.setValue("usertype",1);
                break;
            case VUser::student:settings.setValue("usertype",2);
                break;
            }
            settings.setValue("listDevices",QVariant(listUser[i].listDevices()));
        }
        settings.endArray();
}

int VListUser::checkUser(VUser user,QList<VUser> luser) const
{
    //if(luser.isEmpty())return -1;
    for(int i=0;i<luser.count();i++){
        if(QString::compare(luser[i].account(),user.account(),Qt::CaseInsensitive)==0)return i;
    }
    return -1;
}
