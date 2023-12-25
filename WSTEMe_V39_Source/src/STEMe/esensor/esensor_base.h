#ifndef ESENSOR_BASE_H
#define ESENSOR_BASE_H
#include <QObject>
#include <QVariant>
//users
#include "vcommunication/vnetworkdataunit.h"
#include "vdevice/vdevice.h"
#include "vroot/vdevicecalibration.h"
#include "esensor/esensors.h"

class ESensor_Base
{
public:
    ESensor_Base();
    virtual ~ESensor_Base();


    enum TimeUnits{
        TMU_default,
        TMU_uSecond,
        TMU_mSecond,
        TMU_Second
    };

    enum DeviceREG{
            dREG_MAX            = 0x28,
            dREG_ID				= 0x00,//ID = 0x00,0x01,0x02 of 16-bit reg
            dREG_ADDRESS 		= 0x03,
            dREG_BAUDRATE 		= 0x04,

            /*Temperature compensation for module
            use regs 16 bit with:
            |D15|D14|D13|D12|D11...D0|
            + D15: sign of data, 1 is '-', 0 is '+'
            + D14-D12: resolution, B = pow(10,D14-D12)
            + D11...D0: Data
            Temp = (D15)*(D11...D0)/(B)
            */
            dREG_TEMP_ADC		= 0x05,
            dREG_TEMP_VALUE		= 0x06,//0x07
            dREG_TEMP_CALX1		= 0x08,
            dREG_TEMP_CALY1		= 0x09,

            //REG from 0x0A to 0x0F use for each sensor
            dREG_MOTOR_CONTROL		= 0x0A,	//REG status of motor and control motor
                                            //LSB: Speed for Motor (%dirty)
                                            //4 bit MSB_HI: control motor (1: back, 2: stop, 3: next)
                                            //4 bit MSB_LO: Status motor (1: back, 2: stop, 3: next)


            dREG_SEN01_ZERO 		= 0x0B,//0x0C

            //...............................................
            /*Data of measurement............................
            use regs 32 bit with:
            |D31|D30|D29|D28|D27...D0|
            + D31: sign of data, 1 is '-', 0 is '+'
            + D30-D28: resolution, B = pow(10,D30-D28)
            + D27...D0: Data = (D15)*(D11...D0)/(B)
            Value = D31*(D27...D0)/(B)*/

            dREG_SEN01_ADC			= 0x10,//0x11
            dREG_SEN01_VALUE		= 0x12,//0x13
            dREG_SEN01_CALX1		= 0x14,//0x15
            dREG_SEN01_CALY1		= 0x16,//0x17
            dREG_SEN01_CALX2		= 0x18,//0x19
            dREG_SEN01_CALY2		= 0x1A,//0x1B
            dREG_SEN01_CALX3		= 0x1C,//0x1D
            dREG_SEN01_CALY3		= 0x1E,//0x1F

            dREG_SEN02_ADC			= 0x20,//0x21
            dREG_SEN02_VALUE		= 0x22,//0x23
            dREG_SEN02_CALX1		= 0x24,//0x25
            dREG_SEN02_CALY1		= 0x26,//0x27
            dREG_SEN02_CALX2		= 0x28,//0x29
            dREG_SEN02_CALY2		= 0x2A,//0x2B
            dREG_SEN02_CALX3		= 0x2C,//0x2D
            dREG_SEN02_CALY3		= 0x2E,//0x2F
    };

    //properties

    inline double sensorTemperature(){
        return m_temperature;
    }
    inline void setSensorTemperature(double value){
        m_temperature = value;
    }
    inline double sensorTemperatureCalib(){
        return m_temperatureCalib;
    }
    inline void setSensorTemperatureCalib(double value){
        m_temperatureCalib = value;
    }
    inline double sensorVoltage(){
        return m_voltage;
    }
    inline void setSensorVoltage(double value){
        m_voltage = value;
    }
    //SampleTime
    void setSampleTime(int time){m_esensor->setSampleTime(time);}
    int sampleTime(){return m_esensor->sampleTime();}
    //Sensors
    inline void setMaxREG(quint16 regs){m_esensor->setMaxREG(regs);}
    inline bool isConnect(){return m_esensor->sensorIsConnect();}
    int timeQueryCommand(){return m_sensorDataUnit.timeQueryCommand();}
    inline int resolution(){return m_resolution;}
    inline void setResolution(int value){m_resolution = value;m_precision_value = value;}
    ESensors::SensorPollStatus pollStatus(){return m_esensor->pollStatus();}
    void setPollStatus(ESensors::SensorPollStatus status){m_esensor->setPollStatus(status);}
    inline double value(){this->calculatorValue(); return m_value;}
    inline void setValue(double val){m_value = val;}
    inline double elapsed(){return m_elapsed;}
    inline void setElapsed(double elap){m_elapsed = elap;}
    inline double valueCalib(){this->calculatorValueCalib(); return m_valueCalib;}
    inline void setValueCalib(double val){m_valueCalib = val;}


    //public functions
    quint16 REG_Read(int num){
        return m_sensorDataUnit.modbusDataUnit().value(num);
    }
    double REG_ReadToDouble(int num){
        return QVariant(m_sensorDataUnit.modbusDataUnit().value(num)).toDouble();
    }
    quint32 REG_temp_VALUE(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_TEMP_VALUE)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_TEMP_VALUE+1)).toUInt();
    }
    quint16 REG_temp_CALX1(){
        return m_sensorDataUnit.modbusDataUnit().value(dREG_TEMP_CALX1);
    }
    quint16 REG_temp_CALY1(){
        return m_sensorDataUnit.modbusDataUnit().value(dREG_TEMP_CALY1);
    }
    quint16 REG_motor_CONTROL(){
        return m_sensorDataUnit.modbusDataUnit().value(dREG_MOTOR_CONTROL);
    }
    quint32 REG_sen01_ZERO(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_ZERO)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_ZERO+1)).toUInt();
    }
    quint32 REG_sen01_ADC(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_ADC)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_ADC+1)).toUInt();
    }
    quint32 REG_sen01_VALUE(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_VALUE)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_VALUE+1)).toUInt();
    }
    quint32 REG_sen01_CALX1(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX1)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX1+1)).toUInt();
    }
    quint32 REG_sen01_CALY1(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY1)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY1+1)).toUInt();
    }
    quint32 REG_sen01_CALX2(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX2)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX2+1)).toUInt();
    }
    quint32 REG_sen01_CALY2(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY2)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY2+1)).toUInt();
    }
    quint32 REG_sen01_CALX3(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX3)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALX3+1)).toUInt();
    }
    quint32 REG_sen01_CALY3(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY3)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN01_CALY3+1)).toUInt();
    }
    quint32 REG_sen02_ADC(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_ADC)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_ADC+1)).toUInt();
    }
    quint32 REG_sen02_VALUE(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_VALUE)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_VALUE+1)).toUInt();
    }
    quint32 REG_sen02_CALX1(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX1)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX1+1)).toUInt();
    }
    quint32 REG_sen02_CALY1(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY1)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY1+1)).toUInt();
    }
    quint32 REG_sen02_CALX2(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX2)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX2+1)).toUInt();
    }
    quint32 REG_sen02_CALY2(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY2)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY2+1)).toUInt();
    }
    quint32 REG_sen02_CALX3(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX3)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALX3+1)).toUInt();
    }
    quint32 REG_sen02_CALY3(){
        return (QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY3)).toUInt()<<16)|QVariant(m_sensorDataUnit.modbusDataUnit().value(dREG_SEN02_CALY3+1)).toUInt();
    }

    //Function Precision
    void setPrecision(int pre){m_precision_value = pre;}
    double getPrecision(double val){return this->getPrecision(val,m_precision_value);}
    double getPrecision(double val,int pre);
    //Function Time
    double dataCar_T(uint t1,uint t2);
    double dataCar_T(double t1,double t2);
    double dataCar_T(double t,TimeUnits unit);
    double dataCar_T(double t,TimeUnits unit,int pre);

    //Function
    virtual int pointCalib();
    virtual void writeCalib(VDeviceCalibration::PointCalib point, QVector<quint16> values);
    virtual void Start(VDevice dev){m_esensor->sensorStart(dev);}
    virtual void Stop(){m_esensor->sensorStop();}

    void writeMultipleREG(quint16 address,QVector<quint16> values);
    void writeSingleREG(quint16 reg, quint16 value);
    void clearListCommand();

    //Calculator and update
    void update();
    virtual void calculatorValue();
    virtual void calculatorValueCalib();

    void close();

    int sensorAddress(){return m_esensor->sensorDataUnit().address();}
private:
    ESensors *m_esensor=nullptr;
    VNetworkDataUnit m_sensorDataUnit;
    int m_precision_value = 0;
   // QModbusDataUnit m_deviceUnit;

    double m_value = 0;
    double m_valueCalib = 0;
    double m_elapsed = 0;
    double m_temperature = 0;
    double m_temperatureCalib = 0;
    double m_voltage = 0;
    int m_resolution = 3;

};

#endif // ESENSOR_BASE_H
