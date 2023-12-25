#ifndef VCOMMUNICATIONMODBUS_H
#define VCOMMUNICATIONMODBUS_H

#include <QObject>
#include <QList>
#include <QModbusDataUnit>
#include <QTimer>
#include <QDebug>
#include <vcommunication/vnetworkdataunit.h>

class QModbusClient;
class QModbusReply;



class VCommunicationModbus : public QObject
{
    Q_OBJECT
public:
    explicit VCommunicationModbus(QObject *parent = nullptr);

    enum typeCommunication{
        modbusRTU,
        modbusASCII,
        modbusTCPIP,
        MQTT,
        Bluetooth
    };

    //Properties
    inline QString NamePort(){
        return _namePort;
    }
    inline void setNamePort(QString port){
        _namePort = port;
    }
    inline quint32 BaudRate(){
        return _baudRate;
    }
    inline void setBaudRate(uint32_t value){
        _baudRate = value;
    }
    inline int TimeOut(){
        return _timerOut;
    }
    inline void setTimeOut(int value){
        _timerOut = value;
    }
    inline void setRetries(int value){
        _numberOfRetries = value;
    }
    ////////////////////////////////////////////////
    inline bool connectDevice(){return _connectStatus;}
    bool connectDevice(QString namePort,uint32_t baudRate, int timeout,int retries);
    bool connectDevice(QString namePort,uint32_t baudRate){
        return connectDevice(namePort,baudRate,_timerOut,_numberOfRetries);
    }
    bool connectDevice(QString namePort){
        return connectDevice(namePort,_baudRate,_timerOut,_numberOfRetries);
    }
    void disconnectDevice();

    bool isConnectDevice(){
        return _connectStatus;}

    void setParameter(QString namePort,uint32_t baudRate, int timeout,int retries)
        {_namePort = namePort;_baudRate = baudRate;_timerOut = timeout;_numberOfRetries = retries;}
    void setParameter(QString namePort,uint32_t baudRate){
        setParameter(namePort,baudRate,_timerOut,_numberOfRetries);
    }

    void setPollTime(int interval){
        _pollRequestTime = interval;
    }

    QString errorString(){
        return _errorString;
    }

    //Clear command list to write command
    void clearListNetworkDataUnit(){
        m_listNetworkDataUnit.clear();
    }


    void setReadRequest(int serverAddress,QModbusDataUnit unit){
        _serverAddress = serverAddress;
        readRequest(unit);
    }
    void setWriteRequest(int serverAddress,QModbusDataUnit unit){
        _serverAddress = serverAddress;
        writeRequest(unit);
    }



public slots:
    void modbusRtuRequest(VNetworkDataUnit unit);
    void modbusRtuRequests(VNetworkDataUnit unit,bool *ok);



Q_SIGNALS:
    void modbusRtuReply(VNetworkDataUnit unit);




private slots:
    void on_modbusPollEventTime();
    void on_queryCommandEventTime();
    void on_ReadReady();
    void on_WriteReady();

private:
    void setError(QString err){
        _errorString = err;
    }
    bool writeRequest(QModbusDataUnit unit);
    bool readRequest(QModbusDataUnit unit);

    bool getRequestQueue(int &serverAddress,QModbusDataUnit &unit,VNetworkDataUnit::RequestType &request){
        if(requestQueue.size()>0 && serverAddressQueue.size()>0 && typeRequestQueue.size()>0){
        request = typeRequestQueue.first();
        typeRequestQueue.pop_front();
        unit = requestQueue.first();
        requestQueue.pop_front();
        serverAddress = serverAddressQueue.first();
        serverAddressQueue.pop_front();
        return true;
        }
        return false;
    }
    QVector<VNetworkDataUnit::RequestType>    typeRequestQueue;
    QVector<int>      serverAddressQueue;
    QVector<QModbusDataUnit> requestQueue;

    QList<VNetworkDataUnit> m_listNetworkDataUnit;
    VNetworkDataUnit m_networkDataUnit;

    /////////////////////////////////////////////////////////   
    QModbusClient *modbusDevice = nullptr;
    //QModbusReply *lastRequest = nullptr;
    QTimer *timeRequestModbus=nullptr;
    QTimer *timeQueryCommand = nullptr;

    bool _connectStatus = false;
    bool _requestStatus = false;
    int _serverAddress = 127;
    QString _errorString = "";
    QString _namePort="ttyS0";
    //uint32_t _baudRate = 19200;
    uint32_t _baudRate = 115200;
    int _pollRequestTime = 5;
    int _timerOut = 100;
    int _numberOfRetries = 1;
    int count_test = 1;
    int _timeQueryCommand = 0;
    int MAX_QUERY_COMMAN = 10;


};

#endif // VCOMMUNICATIONMODBUS_H
