#include "edev_sen0108.h"


EDev_Sen0108::EDev_Sen0108(){}
EDev_Sen0108::~EDev_Sen0108(){}

QString EDev_Sen0108::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(%VOL)";
        break;
    case SSU_percentVolt:_res="(%VOL)";
        break;
    case SSU_mg:_res="(mg/l)";
        break;
    }
    return _res;
}

double EDev_Sen0108::temperature()
{
    m_temperature = VDevice::decryption(REG_temp_VALUE());
    return m_temperature;
}


void EDev_Sen0108::writeZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}

void EDev_Sen0108::writeFastCalib(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0108::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_percentVolt:_res = value;
        break;
    case SSU_mg:_res = value;
        break;
    }
    return _res;
}

void EDev_Sen0108::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0108::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}

