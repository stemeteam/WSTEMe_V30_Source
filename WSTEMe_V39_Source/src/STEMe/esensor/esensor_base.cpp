#include "esensor_base.h"

ESensor_Base::ESensor_Base()
{
    m_esensor = new ESensors(dREG_MAX);
    this->clearListCommand();
}

ESensor_Base::~ESensor_Base()
{

}

double ESensor_Base::getPrecision(double val, int pre)
{
return QString::number(val,'f',pre).toDouble();
}


double ESensor_Base::dataCar_T(uint t1, uint t2)
{
    double _val=0;
    if(t2>=t1)_val = QVariant(t2-t1).toDouble();
        else _val = QVariant(65536-t1+t2).toDouble();
    return _val;
}


double ESensor_Base::dataCar_T(double t1, double t2)
{
    double _val=0;
    if(t2>=t1)_val = t2-t1;
        else _val = (65536-t1)+t2;
    return _val;
}

double ESensor_Base::dataCar_T(double t, ESensor_Base::TimeUnits unit)
{
    double _val=t;
    switch(unit){
    case TMU_default:
        break;
    case TMU_uSecond:_val *=1000;
        break;
    case TMU_mSecond:
        break;
    case TMU_Second:_val /= 1000;
        break;
    }
    return _val;
}

double ESensor_Base::dataCar_T(double t, ESensor_Base::TimeUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_T(t,unit),pre);
}


int ESensor_Base::pointCalib()
{
    return VDevice::calibPoints(REG_sen01_CALX1(),REG_sen01_CALY1(),REG_sen01_CALX2(),\
                                REG_sen01_CALY2(),REG_sen01_CALX3(),REG_sen01_CALY3());
}

void ESensor_Base::writeCalib(VDeviceCalibration::PointCalib point, QVector<quint16> values)
{
    switch (point) {
    case VDeviceCalibration::ZeroPointCalib:
        m_esensor->sensorWriteMultipleREG(ESensor_Base::dREG_SEN01_CALX1,values);
        break;
    case VDeviceCalibration::OnePointCalib:
        m_esensor->sensorWriteMultipleREG(ESensor_Base::dREG_SEN01_CALX1,values);
        break;
    case VDeviceCalibration::TwoPointCalib:
        m_esensor->sensorWriteMultipleREG(ESensor_Base::dREG_SEN01_CALX2,values);
        break;
    case VDeviceCalibration::ThreePointCalib:
        m_esensor->sensorWriteMultipleREG(ESensor_Base::dREG_SEN01_CALX3,values);
        break;
    }
}

void ESensor_Base::writeMultipleREG(quint16 address, QVector<quint16> values)
{
    m_esensor->sensorWriteMultipleREG(address,values);
   // m_esensor->sensorWriteMultipleREG(address,values,300,1);
}

void ESensor_Base::writeSingleREG(quint16 reg, quint16 value)
{
    m_esensor->sensorWriteSingleREG(reg, value);
    //m_esensor->sensorWriteSingleREG(reg, value,300,1);
}

void ESensor_Base::clearListCommand()
{
m_esensor->sensorClearListCommand();
}

void ESensor_Base::update()
{
    m_sensorDataUnit = m_esensor->sensorDataUnit();
}

void ESensor_Base::calculatorValue()
{

}

void ESensor_Base::calculatorValueCalib()
{

}

void ESensor_Base::close()
{
    if(m_esensor){
        m_esensor->sensorStop();
        m_esensor->close();
        m_esensor->deleteLater();
    }
}




