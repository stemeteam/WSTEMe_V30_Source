#include "edev_sen0110.h"

EDev_Sen0110::EDev_Sen0110(){}
EDev_Sen0110::~EDev_Sen0110(){}

QString EDev_Sen0110::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(ppm)";
        break;
    case SSU_ppm:_res="(ppm)";
        break;
    case SSU_mg:_res="(mg/l)";
        break;
    }
    return _res;
}

double EDev_Sen0110::temperatureValue()
{
    return VDevice::decryption(REG_Read(dREG_TEMP_VALUE));
}


double EDev_Sen0110::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_ppm:_res = value;
        break;
    case SSU_mg:_res=value*0.9988590004;
        break;
    }
    return _res;
}

void EDev_Sen0110::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0110::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
