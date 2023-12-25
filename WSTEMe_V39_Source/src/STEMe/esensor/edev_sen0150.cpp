#include "edev_sen0150.h"

EDev_Sen0150::EDev_Sen0150(){}
EDev_Sen0150::~EDev_Sen0150(){}

QString EDev_Sen0150::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "(V)";
        break;
    case SSU_volt:_res="(V)";
        break;
    case SSU_milliVolt:_res="(mV)";
        break;
    }
    return _res;
}

void EDev_Sen0150::writeZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0150::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;this->setResolution(3);
        break;
    case SSU_volt:_res = value;this->setResolution(3);
        break;
    case SSU_milliVolt:_res = value*1000;this->setResolution(0);
        break;
    }
    return _res;
}

void EDev_Sen0150::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0150::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
