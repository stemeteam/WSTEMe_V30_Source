#include "vuser.h"
#include <QSettings>

VUser::VUser()
{

}

QString VUser::accountTypeText()
{
    QString type="student";
    switch(m_usertype)
    {
    case VUser::root:
        type="root";
        break;
    case VUser::teacher:
        type="teacher";
        break;
    case VUser::student:
        type="student";
        break;
    }
   return type;
}

