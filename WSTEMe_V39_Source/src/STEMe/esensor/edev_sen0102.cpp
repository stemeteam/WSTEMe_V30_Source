#include "edev_sen0102.h"

EDev_Sen0102::EDev_Sen0102(){}
EDev_Sen0102::~EDev_Sen0102(){}

QString EDev_Sen0102::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(%RH)";
        break;
    case SSU_humidityRelative:_res="(%RH)";
        break;
    case SSU_humidityAbsolute:_res="(g/m3)";
        break;
    }
    return _res;
}

double EDev_Sen0102::temperatureValue()
{
    return VDevice::decryption(REG_Read(dREG_TEMP_VALUE));
}


double EDev_Sen0102::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_humidityRelative:_res = value;
        break;
    case SSU_humidityAbsolute:_res = (6.112*qExp((17.67*this->sensorTemperatureCalib())/(this->sensorTemperatureCalib()+243.5))*value*2.1674)/(273.15+this->sensorTemperatureCalib());
        break;
    }
    return _res;
}

void EDev_Sen0102::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0102::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
