#include "vdevice.h"
#include "qvariant.h"
#include <QVector>
#include <QString>
#include <QtMath>

QVector<QWidget*> VDevice::deviceWidgetInstances;

QString VDevice::serialNumber(QVector<quint16> values)
{
    QString _s1 = QString::number(values[0],16);
    QString _s2 = QString::number(values[1],16);
    QString _s3 = QString::number(values[2],16);

    //_s1 = ADCD = 0101 => 4 charactor in serialnumber
    if(_s1.count()<4){
        for(int i=0;i<4;i++){
            _s1 = "0" + _s1;
            if(_s1.count()>=4)break;
        }
    }
    //_s2 = ADCD => 4 charactor in serialnumber
    if(_s2.count()<4){
        for(int i=0;i<4;i++){
            _s2 = "0" + _s2;
            if(_s2.count()>=4)break;
        }
    }
    //_s3 = ADCD => 4 charactor in serialnumber
    if(_s3.count()<4){
        for(int i=0;i<4;i++){
            _s3 = "0" + _s3;
            if(_s3.count()>=4)break;
        }
    }
    return _s1+_s2+_s3;
}

quint16 VDevice::encode(double data, quint16 resolution)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x         |-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D12 = exp
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    quint16 value=0;
    quint16 sign=0,exp=0;
    exp = resolution & 0x07;
    if(data<0)
        {
        sign = 1;
        data = data*(-1);
        }
    data = data*pow(10.0,exp);
    value = QString::number(data).toUShort();
    value = value&0xFFF;
    value |= (sign<<15)|(exp<<12);
    return value;
}

quint32 VDevice::encode(double data, quint32 resolution)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x         |-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D12 = exp
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    quint32 value=0;
    quint32 sign=0,exp=0;
    exp = resolution & 0x07;
    if(data<0)
        {
        sign = 1;
        data = data*(-1);
        }
    data = data*pow(10.0,exp);
    value = QVariant(data).toUInt();
    value = value&0xFFFFFFF;
    value |= (sign<<31)|(exp<<28);
    return value;
}

quint32 VDevice::encode(double data, int resolution)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x         |-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D12 = exp
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    quint32 value=0;
    quint32 sign=0,exp=0;
    exp = resolution & 0x07;
    if(data<0)
        {
        sign = 1;
        data = data*(-1);
        }
    data = data*pow(10.0,exp);
    value = QVariant(data).toUInt();
    value = value&0xFFFFFFF;
    value |= (sign<<31)|(exp<<28);
    return value;
}

quint32 VDevice::resolution(quint32 reg)
{
    return (reg>>28)&0x07;
}

quint16 VDevice::resolution(quint16 reg)
{
    return (reg>>12)&0x07;
}



double VDevice::decryption(quint16 reg)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x         |-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D12 = exp
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    double value=0;
    quint16 exp=0;
    exp = (reg>>12) & 0x07;
    value = QVariant(reg&0xFFF).toDouble();
    value /=pow(10.0,exp);
    if(reg&0x8000)value *= (-1);
    return value;
}

double VDevice::decryption(quint32 reg)
{
    double value=0;
    quint32 exp=0;
    exp = (reg>>28) & 0x07;
    value = QVariant(reg&0xFFFFFFF).toDouble();
    value /=pow(10.0,exp);
    if(reg&0x80000000)value *= (-1);
    return value;
}
int VDevice::calibPoints(quint32 x1, quint32 y1, quint32 x2, quint32 y2, quint32 x3, quint32 y3)
{
    int poins = 0;
    //Calib is one point
    if(x1!=0&&y1!=0)poins = 1;
    if(x2!=0&&y2!=0)poins = 2;
    if(x3!=0&&y3!=0)poins = 3;
    return poins;
}
double VDevice::calib(double value, quint32 x1, quint32 y1, quint32 x2, quint32 y2, quint32 x3, quint32 y3)
{
    QVector<double> _calib_X,_calib_Y;
    double res=value;
    bool ok=false;
    int _point=0;
    //Calib is one point
    if(x1!=0&&y1!=0)_point=1;
    //Calib is two point
    if(x2!=y2&&y2!=0)_point=2;
    //Calib is three point
    if(x3!=y3&&y3!=0)_point=3;

    //Calculator Calib
    switch(_point){
    case 1:
        _calib_X.resize(1);
        _calib_Y.resize(1);
        _calib_X[0] = VDevice::decryption(x1);
        _calib_Y[0] = VDevice::decryption(y1);
        res = VDevice::calibOnePoint(value,_calib_X[0],_calib_Y[0]);
        break;
    case 2:
        _calib_X.resize(2);
        _calib_Y.resize(2);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        _calib_X[1] = VDevice::decryption(x2);
        _calib_Y[1] = VDevice::decryption(y2);
        res = VDevice::calibTwoPoint(value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1]);
        break;
    case 3:
        _calib_X.resize(3);
        _calib_Y.resize(3);
        _calib_X[2] = VDevice::decryption(x3);
        _calib_Y[2] = VDevice::decryption(y3);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        if(x2!=0&&y2!=0){
            _calib_X[1] = VDevice::decryption(x2);
            _calib_Y[1] = VDevice::decryption(y2);
            }
            else{
                _calib_X[1] = (_calib_X[2]-_calib_X[0])/2;
                _calib_Y[1] = (_calib_Y[2]-_calib_Y[0])/2;
                }
        res = VDevice::calibThreePoint(&ok,value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1],_calib_X[2],_calib_Y[2]);
        if(!ok)res=value;
        break;
    }
    return res;
}

double VDevice::calib(double value, quint32 x1, quint32 y1, quint32 x2, quint32 y2)
{
    return VDevice::calib(value,x1,y1,x2,y2,0,0);
}


double VDevice::calib(double value, quint32 x1, quint32 y1)
{
return VDevice::calib(value,x1,y1,0,0);
}

double VDevice::calib(double value, quint16 x1, quint16 y1, quint16 x2, quint16 y2, quint16 x3, quint16 y3)
{
    QVector<double> _calib_X,_calib_Y;
    double res=value;
    bool ok=false;
    int _point=0;
    //Calib is one point
    if(x1!=0&&y1!=0)_point=1;
    //Calib is two point
    if(x2!=y2&&y2!=0)_point=2;
    //Calib is three point
    if(x3!=y3&&y3!=0)_point=3;

    //Calculator Calib
    switch(_point){
    case 1:
        _calib_X.resize(1);
        _calib_Y.resize(1);
        _calib_X[0] = VDevice::decryption(x1);
        _calib_Y[0] = VDevice::decryption(y1);
        res = VDevice::calibOnePoint(value,_calib_X[0],_calib_Y[0]);
        break;
    case 2:
        _calib_X.resize(2);
        _calib_Y.resize(2);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        _calib_X[1] = VDevice::decryption(x2);
        _calib_Y[1] = VDevice::decryption(y2);
        res = VDevice::calibTwoPoint(value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1]);
        break;
    case 3:
        _calib_X.resize(3);
        _calib_Y.resize(3);
        _calib_X[2] = VDevice::decryption(x3);
        _calib_Y[2] = VDevice::decryption(y3);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        if(x2!=0&&y2!=0){
            _calib_X[1] = VDevice::decryption(x2);
            _calib_Y[1] = VDevice::decryption(y2);
            }
            else{
                _calib_X[1] = (_calib_X[2]-_calib_X[0])/2;
                _calib_Y[1] = (_calib_Y[2]-_calib_Y[0])/2;
                }
        res = VDevice::calibThreePoint(&ok,value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1],_calib_X[2],_calib_Y[2]);
        if(!ok)res=value;
        break;
    }
    return res;
}

double VDevice::calib(double value, quint16 x1, quint16 y1, quint16 x2, quint16 y2, quint16 x3, quint16 y3, double *coefficient)
{
    QVector<double> _calib_X,_calib_Y;
    double res=value;
    bool ok=false;
    int _point=0;
    //Calib is one point
    if(x1!=0&&y1!=0)_point=1;
    //Calib is two point
    if(x2!=y2&&y2!=0)_point=2;
    //Calib is three point
    if(x3!=y3&&y3!=0)_point=3;

    //Calculator Calib
    switch(_point){
    case 1:
        _calib_X.resize(1);
        _calib_Y.resize(1);
        _calib_X[0] = VDevice::decryption(x1);
        _calib_Y[0] = VDevice::decryption(y1);
        res = VDevice::calibOnePoint(value,_calib_X[0],_calib_Y[0]);
        break;
    case 2:
        _calib_X.resize(2);
        _calib_Y.resize(2);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        _calib_X[1] = VDevice::decryption(x2);
        _calib_Y[1] = VDevice::decryption(y2);
        res = VDevice::calibTwoPoint(value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1]);
        break;
    case 3:
        _calib_X.resize(3);
        _calib_Y.resize(3);
        _calib_X[2] = VDevice::decryption(x3);
        _calib_Y[2] = VDevice::decryption(y3);
        if(x1!=0&&y1!=0){
            _calib_X[0] = VDevice::decryption(x1);
            _calib_Y[0] = VDevice::decryption(y1);
            }
            else{
                _calib_X[0] = 0;
                _calib_Y[0] = 0;
                }
        if(x2!=0&&y2!=0){
            _calib_X[1] = VDevice::decryption(x2);
            _calib_Y[1] = VDevice::decryption(y2);
            }
            else{
                _calib_X[1] = (_calib_X[2]-_calib_X[0])/2;
                _calib_Y[1] = (_calib_Y[2]-_calib_Y[0])/2;
                }
        res = VDevice::calibThreePoint(&ok,value,_calib_X[0],_calib_Y[0],_calib_X[1],_calib_Y[1],_calib_X[2],_calib_Y[2],coefficient);
        if(!ok)res=value;
        break;
    }
    return res;
}

double VDevice::calib(double value, quint16 x1, quint16 y1, quint16 x2, quint16 y2)
{
return VDevice::calib(value,x1,y1,x2,y2,0,0);
}

double VDevice::calib(double value, quint16 x1, quint16 y1)
{
    return VDevice::calib(value,x1,y1,0,0);
}

double VDevice::calibThreePointCheck(double *b, double x1, double y1, double x2, double y2, double x3, double y3)
{
return VDevice::solveEquations(b,x1,y1,x2,y2,x3,y3);
}

double VDevice::mathAvg(double value, QVector<double> *list, int max_len)
{
    if(list->count()>max_len)list->resize(max_len);
    else {
        if(list->count()==max_len)list->pop_front();//shift list
    }
    list->append(value);
    double sum=0;
    for(int i = 0; i < list->count(); i++){
       sum += list->value(i);
    }
    return sum/(QVariant(list->count()).toDouble());
}

int VDevice::mathAvg(int value, QVector<int> *list, int max_len)
{
    if(list->count()>max_len)list->resize(max_len);
    else {
        if(list->count()==max_len)list->pop_front();//shift list
    }
    list->append(value);
    double sum=0;
    for(int i = 0; i < list->count(); i++){
       sum += QVariant(list->value(i)).toDouble();
    }
    return QVariant(sum/(QVariant(list->count()).toDouble())).toInt();
}




VDevice::VDevice()
{

}

VDevice::TypeDevice VDevice::typeDevice()
{
    TypeDevice td = TypeDevice::Root;
    if(QString::compare(m_typeDevice,"Root",Qt::CaseSensitive)==0)td = TypeDevice::Root;
    if(QString::compare(m_typeDevice,"Sensor",Qt::CaseSensitive)==0)td = TypeDevice::Sensor;
    if(QString::compare(m_typeDevice,"Module",Qt::CaseSensitive)==0)td = TypeDevice::Module;
    if(QString::compare(m_typeDevice,"System",Qt::CaseSensitive)==0)td = TypeDevice::System;
    if(QString::compare(m_typeDevice,"Setting",Qt::CaseSensitive)==0)td = TypeDevice::Setting;
    return td;
}

QString VDevice::serialNumberIncrease(QString serial)
{
    QString _sn="";
    _sn = QString::number(this->snDevice(serial)+1,16);
    if(_sn.count()<8){
        for(int i=0;i<8;i++){
            _sn = "0" + _sn;
            if(_sn.count()>=8)break;
        }
    }
    _sn = serial.left(4) + _sn;
    return _sn;
}

QVector<quint16> VDevice::serialVector()
{
    QVector<quint16> _vector(3);
    quint32 make;
    make = this->serialNumber(GroupID);
    _vector[0] = QString::number(make&0xFFFF).toUShort();
    make = this->serialNumber(DeviceID);
    _vector[1] = QString::number((make>>16)&0xFFFF).toUShort();
    _vector[2] = QString::number(make&0xFFFF).toUShort();
    return _vector;
}

QVector<quint16> VDevice::serialVector(int address)
{
    QVector<quint16> _vector(4);
    quint32 make;
    make = this->serialNumber(GroupID);
    _vector[0] = QString::number(make&0xFFFF).toUShort();
    make = this->serialNumber(DeviceID);
    _vector[1] = QString::number((make>>16)&0xFFFF).toUShort();
    _vector[2] = QString::number(make&0xFFFF).toUShort();
    if(address<0)address=0;
    _vector[3] = QString::number(address).toUShort();
    return _vector;
}

VDevice::DeviceGroup VDevice::group()
{
    VDevice::DeviceGroup devGroup = VDevice::GroupNone;
    switch (this->snGroup(this->serialNumber())) {
    case 0x0001: devGroup = VDevice::GSoftwareAddDevice;
        break;
    case 0x0002: devGroup = VDevice::GSoftwareAccount;
        break;
    case 0x0003: devGroup = VDevice::GSoftwareSetting;
        break;
    case 0x0101: devGroup = VDevice::GSensorSEN0101;
        break;
    case 0x0102: devGroup = VDevice::GSensorSEN0102;
        break;
    case 0x0103: devGroup = VDevice::GSensorSEN0103;
        break;
    case 0x0104: devGroup = VDevice::GSensorSEN0104;
        break;
    case 0x0105: devGroup = VDevice::GSensorSEN0105;
        break;
    case 0x0106: devGroup = VDevice::GSensorSEN0106;
        break;
    case 0x0107: devGroup = VDevice::GSensorSEN0107;
        break;
    case 0x0108: devGroup = VDevice::GSensorSEN0108;
        break;
    case 0x0109: devGroup = VDevice::GSensorSEN0109;
        break;
    case 0x0110: devGroup = VDevice::GSensorSEN0110;
        break;
    case 0x0111: devGroup = VDevice::GSensorSEN0111;
        break;
    case 0x0112: devGroup = VDevice::GSensorSEN0112;
        break;
    case 0x0113: devGroup = VDevice::GSensorSEN0113;
        break;
    case 0x0114: devGroup = VDevice::GSensorSEN0114;
        break;
    case 0x0115: devGroup = VDevice::GSensorSEN0115;
        break;
    case 0x0116: devGroup = VDevice::GSensorSEN0116;
        break;
    case 0x0120: devGroup = VDevice::GSensorSEN0120;
        break;
    case 0x0121: devGroup = VDevice::GSensorSEN0121;
        break;
    case 0x0150: devGroup = VDevice::GSensorSEN0150;
        break;
    case 0x0151: devGroup = VDevice::GSensorSEN0151;
        break;
    case 0x0132: devGroup = VDevice::GSensorSEN0132;
        break;

        //Module==========================================
    case 0x1101: devGroup = VDevice::GModuleMOD1101;
        break;
    case 0x1102: devGroup = VDevice::GModuleMOD1102;
        break;
    case 0x1103: devGroup = VDevice::GModuleMOD1103;
        break;
    case 0x0020: devGroup = VDevice::GModuleMOD0020;
        break;

    }
return devGroup;
}
quint32 VDevice::snGroup(QString serial)
{
    bool ok;
    quint32 val = serial.left(4).toUInt(&ok,16);
    if(ok)return val;
    else return 0;
}
quint32 VDevice::snDevice(QString serial)
{
    bool ok;
    quint32 val = serial.right(8).toUInt(&ok,16);
    if(ok)return val;
    else return 0;
}

QString VDevice::serialNumberText(QString serial, VDevice::TypeID type)
{
    switch(type){
    case TypeID::GroupID:
        return serial.left(4);
    case TypeID::DeviceID:
        return serial.right(8);
    }
    return "";
}

//....................................................................................................................
/////////////////////////////////////////////////////////////////////////////Functions for Calibration////////////////
double VDevice::calibOnePoint(double val, double x1, double y1)
{
    /*
    Formula for calib one point is y = x + b
    b = y1-x1
    => y = x +(y1-x1)
    */
    double _y = val*(y1/x1);
    return _y;
}

double VDevice::calibTwoPoint(double val, double x1, double y1, double x2, double y2)
{
/*
Formula for calib one point is y = ax + b
a = (y1-y2)/(x1-x2)
b = y2 - a*x2
*/
    double _a=0,_b=0,_y=0;
    if(x1==x2)return 0;
    _a = (y1-y2)/(x1-x2);
    _b = y2 - (_a*x2);
    _y = (_a*val) + _b;
    return _y;
}

double VDevice::calibThreePoint(bool *ok,double val, double x1, double y1,double x2,double y2, double x3, double y3)
{
    double _b[3],_y=val;
    *ok = false;
    if(VDevice::solveEquations(_b,x1,y1,x2,y2,x3,y3)){
        _y = (_b[0]*val*val) + (_b[1]*val) + _b[2];
        *ok = true;
      // qDebug()<<"a: "<<_b[0]<<"    b: "<<_b[1]<<"    c: "<<_b[2];
    }
    return _y;
}

double VDevice::calibThreePoint(bool *ok, double val, double x1, double y1, double x2, double y2, double x3, double y3,double *coefficient)
{
    double _y=val;
    *ok = false;
    if(VDevice::solveEquations(coefficient,x1,y1,x2,y2,x3,y3)){
        _y = (coefficient[0]*val*val) + (coefficient[1]*val) + coefficient[2];
        *ok = true;
    }
    return _y;
}

bool VDevice::solveEquations(double *b, double x1, double y1, double x2, double y2, double x3, double y3)
{
    int i,j,n=3,m,k;
    double x,tam,a[3][4];
    //ptrinh 1
    a[0][0] = x1*x1;
    a[0][1] = x1;
    a[0][2] = 1;
    b[0] = y1;
    //ptrinh 2
    a[1][0] = x2*x2;
    a[1][1] = x2;
    a[1][2] = 1;
    b[1] = y2;
    //ptrinh 3
    a[2][0] = x3*x3;
    a[2][1] = x3;
    a[2][2] = 1;
    b[2] = y3;

    //Tao ma tran lien ket--------
     for(i=0;i<n;i++)
         {
        a[i][n]=b[i];
       }
     //Bat dau thuat toan Gauss-Jordan de giai he phuong trinh.------------
     //Dung phep BDSC dua Aij ve ma tran cheo.
      for(j=0;j<n;j++)
         {
         for(i=n-1;i>=j;i--)
             {
             if(a[i][j]==0.0) continue;//Neu phan tu a bang 0 thi tang i.
             if((i>j)&&(a[i][j]!=0.0))
                 {
                 k=i-1;
                 while((k>=j)&&(a[k][j]==0.0)) k--;//Xet cac phan tu a khac 0 tren cung cot j
                 if(k<j)
                     {
                     //Doi cho dong thu i va j cho ca ma tran mo rong.
                     for(m=0;m<=n;m++)
                         {
                         tam=a[i][m];
                         a[i][m]=a[j][m];
                         a[j][m]=tam;
                         }
                     }
                 if((k>=j)&&(k>=0))
                     {
                     x=-a[i][j]/a[k][j];
                     //Nhan dong thu k cho x roi cong vao dong thu i.
                     for(m=0;m<=n;m++)
                         a[i][m]+=a[k][m]*x;
                     }
                 }
             }
         }
      for(j=n-1;j>=0;j--)
         {
         for(i=0;i<=j;i++)
             {
             if(a[i][j]==0.0) continue;
             if((i<j)&&(a[i][j]!=0.0))
                 {
                 k=i+1;
                 while((k<=j)&&(a[k][j]==0.0)) k++;
                 if((k<=j)&&(k<=n))
                     {
                     x=-a[i][j]/a[k][j];
                     //Nhan dong thu k voi x roi cong vao dong thu i.
                     for(m=0;m<=n;m++)
                         a[i][m]+=a[k][m]*x;
                     }
                 }
             }
         }
     //Ket thuc qua trinh Gauss.
      for(i=0;i<n;i++)
         if(a[i][j]==0.0)
             {
          //    printf("\nHe phuong trinh VSN");
              //dem++;
              return false;
             }
      for(i=0;i<n;i++)
         {
          b[i]=a[i][n]/a[i][i];
         }
      return true;
}
