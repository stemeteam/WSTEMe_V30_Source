#include "edev_sen0101.h"

EDev_Sen0101::EDev_Sen0101(){}
EDev_Sen0101::~EDev_Sen0101(){}

QString EDev_Sen0101::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "(C)";
        break;
    case SSU_tempDegree:_res="(C)";
        break;
    case SSU_tempKelvin:_res="(K)";
        break;
    case SSU_tempFahrenheit:_res="(F)";
        break;
    }
    return _res;
}


double EDev_Sen0101::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_tempDegree:_res = value;
        break;
    case SSU_tempKelvin:_res = value + 273.15;
        break;
    case SSU_tempFahrenheit:_res = (9.0/5.0)*value + 32.0;
        break;

    }
    return _res;
}

void EDev_Sen0101::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0101::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
