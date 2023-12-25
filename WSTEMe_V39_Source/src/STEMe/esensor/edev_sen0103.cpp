#include "edev_sen0103.h"

EDev_Sen0103::EDev_Sen0103()
{
}
EDev_Sen0103::~EDev_Sen0103(){}

QString EDev_Sen0103::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "";
        break;
    case SSU_scaleGram:_res="(g)";
        break;
    case SSU_scaleKiloGram:_res="(Kg)";
        break;
    case SSU_scaleForce:_res="(N)";
        break;
    case SSU_scaleWeight:_res="(N)";
        break;
    }
    return _res;
}

double EDev_Sen0103::temperatureValue()
{
    return VDevice::decryption(REG_Read(dREG_TEMP_VALUE));
}

void EDev_Sen0103::writeZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0103::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_scaleForce:_res = value/100.0;this->setResolution(3);
        break;
    case SSU_scaleGram:_res = value;this->setResolution(1);
        break;
    case SSU_scaleKiloGram:_res = value/1000;this->setResolution(3);
        break;
    case SSU_scaleWeight:_res = value*0.0098;this->setResolution(3);
        break;

    }
    return _res;
}

void EDev_Sen0103::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Sen0103::calculatorValueCalib()
{
    double val = this->value();
    if(val<0)val*=-1;
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(val,this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}

