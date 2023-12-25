#include "vcommunicationmodbus.h"
#include<QModbusRtuSerialMaster>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QVariant>


VCommunicationModbus::VCommunicationModbus(QObject *parent) : QObject(parent)
{

}

bool VCommunicationModbus::connectDevice(QString namePort,uint32_t baudRate, int timeout,int retries)
{
    if(modbusDevice){
            modbusDevice->disconnectDevice();
        }
    modbusDevice = new QModbusRtuSerialMaster(this);
    if(modbusDevice->state()!=QModbusDevice::ConnectedState){
        modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,namePort);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,baudRate);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);
        //modbus time
        modbusDevice->setTimeout(timeout);
        modbusDevice->setNumberOfRetries(retries);
        //connect to modbus
        _connectStatus = modbusDevice->connectDevice();
        if(_connectStatus){
            timeRequestModbus = new QTimer(this);
            timeRequestModbus->setInterval(_pollRequestTime);
            connect(timeRequestModbus,&QTimer::timeout,this,&VCommunicationModbus::on_modbusPollEventTime);
            timeRequestModbus->start();
            timeQueryCommand = new QTimer(this);
            timeQueryCommand->setInterval(1);
            timeQueryCommand->start();//count time query into _timeQueryCommand
            connect(timeQueryCommand,&QTimer::timeout,this,&VCommunicationModbus::on_queryCommandEventTime);
        }
        return _connectStatus;
    }
    modbusDevice->disconnectDevice();
    _connectStatus = false;
    return _connectStatus;
}

void VCommunicationModbus::disconnectDevice()
{
    if(timeRequestModbus){
        delete timeRequestModbus;
        timeRequestModbus = nullptr;
    }
    if(timeQueryCommand){
        delete timeQueryCommand;
        timeQueryCommand = nullptr;
    }
     if(modbusDevice){
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
     }
     _connectStatus = false;
}

void VCommunicationModbus::modbusRtuRequest(VNetworkDataUnit unit)
{
    if(m_listNetworkDataUnit.size()<MAX_QUERY_COMMAN)m_listNetworkDataUnit.append(unit);
}

void VCommunicationModbus::modbusRtuRequests(VNetworkDataUnit unit, bool *ok)
{
    bool _add=true;
    if(m_listNetworkDataUnit.size()<MAX_QUERY_COMMAN){
        for(int i=0;i<m_listNetworkDataUnit.size();i++){
            if(m_listNetworkDataUnit.at(i).address()==unit.address()){
                _add=false;
                break;
            }
        }
        if(_add)m_listNetworkDataUnit.append(unit);
    }
    *ok = _add;
}






void VCommunicationModbus::on_modbusPollEventTime()
{
    if(!_requestStatus){
        if(!m_listNetworkDataUnit.isEmpty()){
            m_networkDataUnit = m_listNetworkDataUnit.first();
            m_listNetworkDataUnit.pop_front();
            //qDebug() << "sendCommand:" + QString::number(unit.address()) + "," + QString::number(unit.modbusDataUnit().startAddress()) + "," + QString::number(unit.modbusDataUnit().valueCount());
            modbusDevice->setTimeout(m_networkDataUnit.timeOut());
            modbusDevice->setNumberOfRetries(m_networkDataUnit.numberOfRetries());
            if(m_networkDataUnit.requestType() == VNetworkDataUnit::Read){
                this->setReadRequest(m_networkDataUnit.address(),m_networkDataUnit.modbusDataUnit());
               // qDebug() <<"?";
            }
            if(m_networkDataUnit.requestType()  == VNetworkDataUnit::Write){
                this->setWriteRequest(m_networkDataUnit.address(),m_networkDataUnit.modbusDataUnit());
            }
            _timeQueryCommand=0;    //Reset time query
        }
    }
}

void VCommunicationModbus::on_queryCommandEventTime()
{
_timeQueryCommand++;
}

void VCommunicationModbus::on_ReadReady()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if(reply){
        const QModbusDataUnit unit = reply->result();
       // VNetworkDataUnit _resUnit;
        m_networkDataUnit.setAddress(_serverAddress);
        m_networkDataUnit.setModbusDataUnit(unit);
                    //qDebug()<<"..................................." << reply->errorString();

        if(reply->error()==QModbusDevice::NoError){
            m_networkDataUnit.setStatus(true);//qDebug() <<"OK";
        }
        else{
            m_networkDataUnit.setStatus(false);//qDebug() <<"ERR";
        }
        m_networkDataUnit.setRequestType(VNetworkDataUnit::Read);
        m_networkDataUnit.setError(reply->errorString());
        m_networkDataUnit.setTimeQueryCommand(_timeQueryCommand);
        emit modbusRtuReply(m_networkDataUnit);
    }
    delete reply;
    _requestStatus=false;
}

void VCommunicationModbus::on_WriteReady()
{
    //VNetworkDataUnit _resUnit;
    m_networkDataUnit.setStatus(false);
    auto reply = qobject_cast<QModbusReply*>(sender());
    if(reply){
        if (reply->error() == QModbusDevice::NoError)m_networkDataUnit.setStatus(true);
    } 
//    qDebug()<<"......on_writereadly............................." << reply->errorString();
    if(_serverAddress==0)m_networkDataUnit.setStatus(true);
    m_networkDataUnit.setAddress(_serverAddress);
    m_networkDataUnit.setModbusDataUnit(reply->result());
    m_networkDataUnit.setRequestType(VNetworkDataUnit::Write);
    m_networkDataUnit.setTimeQueryCommand(_timeQueryCommand);
    emit modbusRtuReply(m_networkDataUnit);
    delete reply;
    _requestStatus = false;
}

bool VCommunicationModbus::writeRequest(QModbusDataUnit unit)
{
    if (!modbusDevice){
        this->setError("not foud device!");
        return false;
        }
    if (auto *reply = modbusDevice->sendWriteRequest(unit,_serverAddress))
        {
         if (!reply->isFinished()){
                connect(reply, &QModbusReply::finished, this,&VCommunicationModbus::on_WriteReady);
                _requestStatus = true;
                this->setError("OK");
                return true;
                } else {
                reply->deleteLater();
                }
        }
    this->setError("error write request!");
    return false;
}


bool VCommunicationModbus::readRequest(QModbusDataUnit unit)
{
    if(!modbusDevice){
        this->setError("not foud device!");
        return false;}
    if(auto *reply = modbusDevice->sendReadRequest(unit,_serverAddress)){
        if(!reply->isFinished()){
            connect(reply,&QModbusReply::finished,this,&VCommunicationModbus::on_ReadReady);
            _requestStatus = true;
            this->setError("OK");
            //qDebug()<<"------------------------------ReadRequest: OK"<<QString::number(_serverAddress);
            return true;
            }
        else reply->deleteLater();
        }
    this->setError("error read request!");
    //qDebug()<<"------------------------------ReadRequest: false";
    return false;
}






