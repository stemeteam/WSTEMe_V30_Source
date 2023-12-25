#ifndef VNETWORKDATAUNIT_H
#define VNETWORKDATAUNIT_H
#include <qmodbusdataunit.h>

class VNetworkDataUnit
{
public:
    VNetworkDataUnit();
    enum RequestType{
        Read,
        Write,
        ReadWrite
    };

    //getter
    inline int address() const{
        return m_address;
    }
    inline QModbusDataUnit modbusDataUnit() const{
        return m_modbusDataUnit;
    }
    inline bool status() const{
        return m_status;
    }
    inline RequestType requestType() const{
        return m_requestType;
    }
    inline QString error() const{
        return m_errorString;
    }
    inline QString serialNumber(){
        return m_serialNumber;
    }
    inline int timeQueryCommand() const{
        return m_timeQueryCommand;
    }
    inline int timeOut() const{
        return m_timeOut;
    }
    inline int numberOfRetries() const{
        return m_numberOfRetries;
    }

    //setter
    inline void setAddress(int newAdd){
        m_address = newAdd;
    }
    inline void setModbusDataUnit(QModbusDataUnit newUnit){
        m_modbusDataUnit = newUnit;
    }
    inline void setStatus(bool newStatus){
        m_status = newStatus;
    }
    inline void setRequestType(RequestType newRequest){
        m_requestType = newRequest;
    }
    inline void setError(QString newError){
        m_errorString = newError;
    }
    inline void setSerialNumber(QString sn){
        m_serialNumber = sn;
    }
    inline void setTimeQueryCommand(int time){
        m_timeQueryCommand = time;
    }
    inline void setTimeOut(int time){
        m_timeOut = time;
    }
    inline void setNumberOfRetries(int ret){
        m_numberOfRetries = ret;
    }

private:
    int m_address=-1;
    QModbusDataUnit m_modbusDataUnit;
    bool m_status=false;
    QString m_errorString="";
    RequestType m_requestType = RequestType::Read;
    QString m_serialNumber="";
    int m_timeQueryCommand=0;
    int m_timeOut=100;
    int m_numberOfRetries=0;
};

#endif // VNETWORKDATAUNIT_H
