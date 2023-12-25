#include "edev_sen0151.h"


EDev_Sen0151::EDev_Sen0151(){}
EDev_Sen0151::~EDev_Sen0151(){}

QString EDev_Sen0151::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "(A)";
        break;
    case SSU_amp:_res="(A)";
        break;
    case SSU_milliAmp:_res="(mA)";
        break;
    }
    return _res;
}

void EDev_Sen0151::writeZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0151::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;this->setResolution(3);
        break;
    case SSU_amp:_res = value;this->setResolution(3);
        break;
    case SSU_milliAmp:_res = value*1000;this->setResolution(0);
        break;
    }
    return _res;
}

void EDev_Sen0151::calculatorValue()
{
    //Units convert
    double _value;
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    _value = VDevice::decryption(this->REG_sen01_VALUE());
    if(_value>=-0.001&&_value<=0.001)_value=0;
    this->setValue(this->sensorConvertUnits(_value));
}

void EDev_Sen0151::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
