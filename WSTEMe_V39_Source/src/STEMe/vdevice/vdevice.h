#ifndef VDEVICE_H
#define VDEVICE_H

#include <QString>
#include <QVector>
#include <QWidget>
#include <QDebug>

class VDevice
{
 //public static
public:

    static QVector<QWidget*> deviceWidgetInstances;
    static QString serialNumber(QVector<quint16> values);
    //encode and decryption from Data to REG and opposite(Double to REG 16 or 32 bit)
    static quint16 encode(double data,quint16 resolution);
    static quint32 encode(double data,quint32 resolution);
    static quint32 encode(double data,int resolution);
    static double decryption(quint16 reg);
    static double decryption(quint32 reg);

    //get resolution of data from REG 16 or 32 (bit D12-D14 or D28-D30)
    static quint32 resolution(quint32 reg);
    static quint16 resolution(quint16 reg);

    //get value was calibrated from (x1,y1)-first point,(x2,y2)-second point,(x3,y3)-third point
    static double calibOnePoint(double val,double x1,double y1);
    static double calibTwoPoint(double val,double x1,double y1,double x2,double y2);
    static double calibThreePoint(bool *ok,double val,double x1,double y1,double x2,double y2,double x3,double y3);
    static double calibThreePoint(bool *ok,double val,double x1,double y1,double x2,double y2,double x3,double y3,double *coefficient);
    static bool solveEquations(double *b,double x1,double y1,double x2,double y2,double x3,double y3);

    static int calibPoints(quint32 x1,quint32 y1,quint32 x2,quint32 y2,quint32 x3,quint32 y3);
    static double calib(double value,quint32 x1,quint32 y1,quint32 x2,quint32 y2,quint32 x3,quint32 y3);
    static double calib(double value,quint32 x1,quint32 y1,quint32 x2,quint32 y2);
    static double calib(double value,quint32 x1,quint32 y1);
    static double calib(double value,quint16 x1,quint16 y1,quint16 x2,quint16 y2,quint16 x3,quint16 y3);
    static double calib(double value,quint16 x1,quint16 y1,quint16 x2,quint16 y2,quint16 x3,quint16 y3,double *coefficient);
    static double calib(double value,quint16 x1,quint16 y1,quint16 x2,quint16 y2);
    static double calib(double value,quint16 x1,quint16 y1);
    static double calibThreePointCheck(double *b,double x1,double y1,double x2,double y2,double x3,double y3);


    //Functions about math
    static double mathAvg(double value,QVector<double> *list,int max_len);
    static int mathAvg(int value,QVector<int> *list,int max_len);

public:
    VDevice();
    enum DeviceGroup{
        GroupNone               = 0,
        GSoftwareAddDevice      = 0x0001,
        GSoftwareAccount        = 0x0002,
        GSoftwareSetting        = 0x0003,
 //for Sensor
        GSensorSEN0101          = 0x0101,
        GSensorSEN0102          = 0x0102,
        GSensorSEN0103          = 0x0103,
        GSensorSEN0104          = 0x0104,
        GSensorSEN0105          = 0x0105,
        GSensorSEN0106          = 0x0106,
        GSensorSEN0107          = 0x0107,
        GSensorSEN0108          = 0x0108,
        GSensorSEN0109          = 0x0109,
        GSensorSEN0110          = 0x0110,
        GSensorSEN0111          = 0x0111,
        GSensorSEN0112          = 0x0112,
        GSensorSEN0113          = 0x0113,
        GSensorSEN0114          = 0x0114,
        GSensorSEN0115          = 0x0115,
        GSensorSEN0116          = 0x0116,
        GSensorSEN0120          = 0x0120,
        GSensorSEN0121          = 0x0121,
        GSensorSEN0150          = 0x0150,
        GSensorSEN0151          = 0x0151,
        GSensorSEN0132          = 0x0132,
//for Module
        GModuleMOD0020          = 0x0020,
        GModuleMOD1101          = 0x1101,
        GModuleMOD1102          = 0x1102,
        GModuleMOD1103          = 0x1103

    };


    enum TypeID{
        GroupID,
        DeviceID
    };
    enum TypeDevice{
        Root,
        Sensor,
        Module,
        System,
        Setting
    };

    //getter......
    inline QString name() const{
        return m_nameDevice;
    }
    inline QString type() const{
        return m_typeDevice;
    }

    inline int address() const{
        return m_addressDevice;
    }
    inline QString objectName() const{
        return m_objectName;
    }
    inline QString serialNumber() const{
        return m_serialNumberDevice;
    }
    inline QString serialNumberGroup(QString serial){
        return this->serialNumberText(serial,TypeID::GroupID);
    }
    inline QString serialNumberDevice(QString serial){
        return this->serialNumberText(serial,TypeID::DeviceID);
    }
    inline quint32 serialNumber(TypeID type){
        if(type==TypeID::GroupID)return snGroup(serialNumber());
        if(type==TypeID::DeviceID)return snDevice(serialNumber());
        return 0;
    }
    inline quint32 serialNumber(QString sn,TypeID type){
        if(type==TypeID::GroupID)return snGroup(sn);
        if(type==TypeID::DeviceID)return snDevice(sn);
        return 0;
    }
    inline QVector<quint16> serialVector();
    QVector<quint16> serialVector(int address);
    inline QString iconPath() const{
        return m_iconPath;
    }
    inline QString description() const{
        return m_description;
    }
    inline QString dateCreated() const{
        return m_dateCreated;
    }
    inline QString dateModified() const{
        return m_dateModified;
    }


    //setter......
    inline void setName(QString name){
        m_nameDevice = name;
    }
    inline void setType(QString type){
        m_typeDevice = type;
    }
    inline void setAddress(int newAddress){
        m_addressDevice = newAddress;
    }
    inline void setObjectName(QString newName){
        m_objectName = newName;
    }
    inline void setSerialNumber(QString newNum){
        m_serialNumberDevice = newNum;
    }
    inline void setIconPath(QString newPath){
        m_iconPath = newPath;
    }
    inline void setDescription(QString newDes){
        m_description= newDes;
    }
    inline void setDateCreated(QString newDateC){
        m_dateCreated= newDateC;
    }
    inline void setDateModified(QString newDateM){
        m_dateModified = newDateM;
    }
    //funcrion.....
    DeviceGroup group();
    TypeDevice typeDevice();
    QString serialNumberIncrease(QString serial);


private:

    DeviceGroup m_deviceGroup;
    int m_addressDevice = 127;
    QString m_nameDevice = "";
    QString m_typeDevice = "";
    QString m_objectName = "";
    QString m_serialNumberDevice="000000000000";
    QString m_iconPath = "";
    QString m_description ="";
    QString m_dateCreated="";
    QString m_dateModified="";

    int m_calibPoints=0;


    quint32 snGroup(QString serial);
    quint32 snDevice(QString serial);
    QString serialNumberText(QString serial,TypeID type);


};

#endif // VDEVICE_H
