#include "esensors.h"


////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................
 VCommunicationModbus ESensors::m_modbusDevice;
 bool ESensors::m_modbusIsConnect=false;
 //uint32_t ESensors::m_modbusBaudRate = 9600;
 uint32_t ESensors::m_modbusBaudRate = 115200;
 int ESensors::m_modbusTimeOut = 100;
 int ESensors::m_modbusRetries = 0;
 QString ESensors::m_modbusNamePort = "ttyS0";
bool ESensors::modbusConnect()
{
    bool _status;
    if(m_modbusDevice.connectDevice()){m_modbusIsConnect = true;return true;}
  //  m_modbusDevice.setNamePort(m_modbusNamePort);
    _status = m_modbusDevice.connectDevice(m_modbusDevice.NamePort(),m_modbusBaudRate,m_modbusTimeOut,m_modbusRetries);
    if(_status){
    m_modbusIsConnect = true;
    }
    else{
        m_modbusIsConnect = false;
    }
    return m_modbusIsConnect;
}
bool ESensors::modbusDisconnect()
{
    m_modbusDevice.disconnectDevice();
    return m_modbusDevice.isConnectDevice();
}

void ESensors::setModbusBaudRate(quint32 value)
{
    m_modbusBaudRate = value;
    m_modbusDevice.setBaudRate(m_modbusBaudRate);
}

void ESensors::setModbusTimeOut(int value)
{
    m_modbusDevice.setTimeOut(value);
    m_modbusTimeOut = value;
}

void ESensors::setModbusRetries(int value)
{
    m_modbusDevice.setRetries(value);
    m_modbusRetries = value;
}

void ESensors::setModbusPort(QString port)
{
m_modbusDevice.setNamePort(port);
m_modbusNamePort = port;
}

void ESensors::checkSampleTime()
{
    m_timeQueryCommand =VDevice::mathAvg(m_sensorDataUnit.timeQueryCommand(),&m_avgTimeCommand,20);
    m_intervalPoll = m_timeQueryCommand/5;
    if(m_intervalPoll<1)m_intervalPoll=1;
    m_timerPoll->setInterval(m_intervalPoll);
}
void ESensors::modbusSetAddress()
{
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,0xFF00,4);
    VNetworkDataUnit _netUnit;
    //if(m_sensorDataUnit)_netUnit=*m_sensorDataUnit;
    unit.setValues(m_sensorDevice.serialVector(m_sensorDevice.address()));
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(0);
    _netUnit.setSerialNumber(m_sensorDevice.serialNumber());
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    emit modbusRtuRequest(_netUnit);
}
void ESensors::modbusRequestInputRegisters()
{
    QModbusDataUnit frameRead(QModbusDataUnit::InputRegisters,0,m_maxREG);
    VNetworkDataUnit _netUnit;
    _netUnit.setModbusDataUnit(frameRead);
    _netUnit.setAddress(m_sensorDevice.address());
    _netUnit.setSerialNumber(m_sensorDevice.serialNumber());
    _netUnit.setTimeOut(m_modbusTimeOut);
    _netUnit.setNumberOfRetries(m_modbusRetries);
    _netUnit.setRequestType(VNetworkDataUnit::Read);
    emit modbusRtuRequest(_netUnit);

}

void ESensors::modbusRequestInputRegisters(bool *ok)
{
    QModbusDataUnit frameRead(QModbusDataUnit::InputRegisters,0,m_maxREG);
    VNetworkDataUnit _netUnit;
    _netUnit.setModbusDataUnit(frameRead);
    _netUnit.setAddress(m_sensorDevice.address());
    _netUnit.setSerialNumber(m_sensorDevice.serialNumber());
    _netUnit.setTimeOut(m_modbusTimeOut);
    _netUnit.setNumberOfRetries(m_modbusRetries);
    _netUnit.setRequestType(VNetworkDataUnit::Read);
    emit modbusRtuRequests(_netUnit,ok);
   // qDebug()<<_netUnit.address();
}
void ESensors::modbusReadResult(VNetworkDataUnit unit)
{
    if(unit.status()){
        m_sensorDataUnit = unit;
        QModbusDataUnit m_deviceUnit = unit.modbusDataUnit();
        this->checkSampleTime();
        m_sensorPollStatus=SensorPollStatus::sensorReadReply;
      //  qDebug()<<unit.address()<<">>"<< unit.timeQueryCommand();
        }
        else{
            m_sensorPollStatus=SensorPollStatus::sensorReadError;
        }
}
void ESensors::modbusWriteResult(VNetworkDataUnit unit)
{
    emit on_sensorWriteReport(unit.status());
    if(unit.status())m_sensorPollStatus=SensorPollStatus::sensorWriteReply;
    else m_sensorPollStatus=SensorPollStatus::sensorWriteError;
}

void ESensors::modbusRtuReply(VNetworkDataUnit unit)
{
    emit on_sensorReply(unit);
    checkListReplyCommand(unit);
    //set New Address
    if(unit.address()==0){
        if(QString::compare(unit.serialNumber(),m_sensorDevice.serialNumber(),Qt::CaseSensitive)==0) {
        m_sensorConnect = ESensors::deviceCheckConnect;
        }
    }
    //Request data
    if(unit.address()==m_sensorDevice.address())  //check address of device
        {
        if(unit.requestType()==VNetworkDataUnit::Read)this->modbusReadResult(unit);
            else this->modbusWriteResult(unit);
        if(unit.status()){
            m_sensorConnect = ESensors::deviceConnected;
            m_sensorTimeOut = 0;
        }
        else {
            //Check retries
            if(m_sensorTimeOut++>=m_sensorRetries){
                m_sensorConnect = ESensors::deviceDisconnected;
                m_sensorTimeOut = 0;
            }
        }
      }
}


/////////////////////////////////////////////////////////////////

void ESensors::sensorInit()
{
    m_timerPoll = new QTimer(this);
    m_timerPoll->setInterval(m_intervalPoll);
    QObject::connect(&m_modbusDevice,&VCommunicationModbus::modbusRtuReply,this,&ESensors::modbusRtuReply);
    QObject::connect(this,&ESensors::modbusRtuRequest,&m_modbusDevice,&VCommunicationModbus::modbusRtuRequest);
    QObject::connect(this,&ESensors::modbusRtuRequests,&m_modbusDevice,&VCommunicationModbus::modbusRtuRequests);
    QObject::connect(m_timerPoll,&QTimer::timeout,this,&ESensors::on_timerPoll);
}

ESensors::ESensors(QObject *parent) : QObject(parent)
{
    this->sensorInit();
}
ESensors::ESensors(VNetworkDataUnit *unit)
{
    this->sensorInit();
    this->setSensorDataUnit(*unit);
}

ESensors::ESensors(quint16 regs)
{
    this->sensorInit();
    this->setMaxREG(regs);
}
bool ESensors::sensorStart(VDevice dev)
{
    if(!m_modbusIsConnect)return false;
    m_sensorDevice = dev;
    m_timerPoll->start();
    m_sensorConnect = ESensors::deviceDisconnected;
    return true;
}

void ESensors::sensorStop()
{
    m_timerPoll->stop();
    m_sensorConnect = ESensors::deviceDisconnected;
}

void ESensors::setSensorRequest(VNetworkDataUnit unit)
{
    emit modbusRtuRequest(unit);
}


QList<VNetworkDataUnit> ESensors::sensorReplyCommand()
{
    QList<VNetworkDataUnit> _list = m_listReplyCommand;
    m_listReplyCommand.empty();
    return _list;
}


void ESensors::checkListReplyCommand(VNetworkDataUnit unit)
{
    if(m_listReplyCommand.size()<MAX_QUERY_COMMAN){
        m_listReplyCommand.append(unit);
    }
    else{
        for(int i=0;i<MAX_QUERY_COMMAN/3;i++){//Remove 1/3 list query
            m_listReplyCommand.pop_front();
        }
    }
}

void ESensors::close()
{
    m_timerPoll->stop();
    m_timerPoll->deleteLater();
}

void ESensors::sensorClearListCommand()
{
m_modbusDevice.clearListNetworkDataUnit();
}

void ESensors::on_timerPoll()
{
    testTime++;
    switch(m_sensorConnect){
        case ESensors::deviceDisconnected://Send command connet with serialNumber  of device and new address
             modbusSetAddress();
             m_sensorPollStatus=SensorPollStatus::sensorWriteCommand;
             m_sensorConnect = ESensors::deviceWaitRequest;
             m_timerRequest =0;
             break;
        case ESensors::deviceWaitRequest:
             if((m_timeQueryCommand+(m_intervalPoll*m_timerRequest++))>m_sampleTime){
             m_sensorConnect = ESensors::deviceDisconnected;
             m_timerRequest =0;
             }
             break;
        case ESensors::deviceCheckConnect:
             modbusRequestInputRegisters();
             m_sensorConnect = ESensors::deviceWaitRequest;
             m_timerRequest =0;
             break;
        case ESensors::deviceConnected:
            if((m_timeQueryCommand+(m_intervalPoll*m_timerRequest))>m_sampleTime){
             bool ok;
             holdTestTime = testTime;testTime=0;
             modbusRequestInputRegisters(&ok);
         //    qDebug()<<m_sensorDevice.address()<<">>"<< QString::number(m_timeQueryCommand+(m_intervalPoll*m_timerRequest));
             if(!ok){
                 m_timerRequest--;
             }
             else{
                 m_sensorPollStatus=SensorPollStatus::sensorReadCommand;
                 m_timerRequest = 0;
             }
             }
            m_timerRequest++;
    }
}

////////////////////////////////////////////////////////////////////////////Read data and Calculator for SENSORS....................
void ESensors::sensorWriteMultipleREG(quint16 address, QVector<quint16> values, int timeout, int retries)
{
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,address,QString::number(values.count()).toUShort());
    VNetworkDataUnit _netUnit;
    unit.setValues(values);
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_sensorDevice.address());
    _netUnit.setTimeOut(timeout);
    _netUnit.setNumberOfRetries(retries);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    m_modbusDevice.clearListNetworkDataUnit();
    emit modbusRtuRequest(_netUnit);
}

void ESensors::sensorWriteSingleREG(quint16 reg, quint16 value, int timeout, int retries)
{
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,reg,1);
    VNetworkDataUnit _netUnit;
    unit.setValue(0,value);
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_sensorDevice.address());
    _netUnit.setTimeOut(timeout);
    _netUnit.setNumberOfRetries(retries);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    m_modbusDevice.clearListNetworkDataUnit();
    emit modbusRtuRequest(_netUnit);
}
void ESensors::sensorWriteMultipleREG(quint16 address, QVector<quint16> values, int timeout)
{
this->sensorWriteMultipleREG(address,values,timeout,m_modbusRetries);
}

void ESensors::sensorWriteSingleREG(quint16 reg, quint16 value, int timeout)
{
this->sensorWriteSingleREG(reg,value,timeout,m_modbusRetries);
}
void ESensors::sensorWriteMultipleREG(quint16 address, QVector<quint16> values)
{
    this->sensorWriteMultipleREG(address,values,m_modbusTimeOut);
}

void ESensors::sensorWriteSingleREG(quint16 reg, quint16 value)
{
    this->sensorWriteSingleREG(reg,value,m_modbusTimeOut);
}
