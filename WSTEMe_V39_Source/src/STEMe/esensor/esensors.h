#ifndef ESENSORS_H
#define ESENSORS_H
#include <QObject>
#include <QTimer>
#include <QtMath>

//users
#include "vcommunication/vcommunicationmodbus.h"
#include "vdevice/vdevice.h"

class ESensors : public QObject
{
    Q_OBJECT
        ////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................
public slots:
    void modbusRtuReply(VNetworkDataUnit unit);
private slots:
Q_SIGNALS:
    void modbusRtuRequest(VNetworkDataUnit unit);
    void modbusRtuRequests(VNetworkDataUnit unit,bool *ok);
   void on_sensorReply(VNetworkDataUnit unit);
public:
    enum ConnectStatus{
        deviceDisconnected,
        deviceWaitRequest,
        deviceCheckConnect,
        deviceConnected
    };

    static uint32_t m_modbusBaudRate;
    static int m_modbusTimeOut;
    static int m_modbusRetries;
    static QString m_modbusNamePort;
    //static function
    static bool modbusConnect();
    static bool modbusDisconnect();
    static bool modbusIsConnect(){
        return m_modbusIsConnect;
    }

    static void setModbusBaudRate(quint32 value);
    static void setModbusTimeOut(int value);
    static void setModbusRetries(int value);
    static void setModbusPort(QString port);
private:
       static VCommunicationModbus m_modbusDevice;
       static bool m_modbusIsConnect;
       VNetworkDataUnit m_sensorDataUnit;
       ConnectStatus m_sensorConnect = ESensors::deviceDisconnected;

       QTimer  *m_timerPoll=nullptr;
       VDevice m_sensorDevice;

       int m_sampleTime = 100;
       int m_sampleTime_Last = 100;
       QVector<int> m_avgTimeCommand;
       int m_timeQueryCommand=0;
       int testTime=0;
       int holdTestTime = 0;

       int m_intervalPoll=10;
       int m_timerRequest =0;
       int m_sensorRetries = 3;
       int m_sensorTimeOut = 0;
       quint16 m_maxREG = 0x28;

       void checkSampleTime();  //check sampletime < time query then set time query + 1
       void modbusSetAddress();
       void modbusRequestInputRegisters();
       void modbusRequestInputRegisters(bool *ok);
       void modbusReadResult(VNetworkDataUnit unit);
       void modbusWriteResult(VNetworkDataUnit unit);

////////////////////////////////////////////////////////////////////////////Read data and Calculator for SENSORS....................

public:
        enum SensorPollStatus{
            sensorIdle,
            sensorWriteCommand,
            sensorReadCommand,
            sensorWriteReply,
            sensorReadReply,
            sensorWriteError,
            sensorReadError
        };
        //properties
        inline int sensorTimeCommand(){return m_sensorDataUnit.timeQueryCommand();}
        inline int sensorHoldTestTime(){return holdTestTime;}
        inline void setSampleTime(int time){
            m_sampleTime = time;
            m_sampleTime_Last = m_sampleTime;
        }
        inline int sampleTime(){return m_sampleTime;}
        inline bool sensorIsConnect(){
            if(m_sensorConnect==ESensors::deviceConnected)return true;
            else return false;
        }
        inline VNetworkDataUnit sensorDataUnit(){return m_sensorDataUnit;}
        inline void setSensorDataUnit (VNetworkDataUnit unit){m_sensorDataUnit = unit;}
        inline void setPollStatus(SensorPollStatus status){m_sensorPollStatus = status;}
        inline SensorPollStatus pollStatus(){return m_sensorPollStatus;}
        inline void setMaxREG(quint16 regs){m_maxREG = regs;}

    //Public Function
    void sensorWriteMultipleREG(quint16 address,QVector<quint16> values,int timeout,int retries);
    void sensorWriteSingleREG(quint16 reg, quint16 value,int timeout,int retries);
    void sensorWriteMultipleREG(quint16 address,QVector<quint16> values,int timeout);
    void sensorWriteSingleREG(quint16 reg, quint16 value,int timeout);
    void sensorWriteMultipleREG(quint16 address,QVector<quint16> values);
    void sensorWriteSingleREG(quint16 reg, quint16 value);
    bool sensorStart(VDevice dev);
    void sensorStop();
    void setSensorRequest(VNetworkDataUnit unit);
    void close();
    void sensorClearListCommand();

    //Sensor calibration
    //Search and get data from list reply command
    QList<VNetworkDataUnit> sensorReplyCommand();

    explicit ESensors(QObject *parent = nullptr);
    ESensors(VNetworkDataUnit *unit);
    ESensors(quint16 regs);

signals:
        void on_sensorWriteReport(bool status);
private slots:
    void on_timerPoll();

private:
    SensorPollStatus m_sensorPollStatus=SensorPollStatus::sensorIdle;
    QList<VNetworkDataUnit> m_listReplyCommand;

    int MAX_QUERY_COMMAN = 100;

    void sensorInit();
    double sensorConvertUnits(double value);
    void checkListReplyCommand(VNetworkDataUnit unit);



};

#endif // ESENSORS_H
