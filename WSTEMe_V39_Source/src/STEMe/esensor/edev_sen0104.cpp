#include "edev_sen0104.h"

EDev_Sen0104::EDev_Sen0104(){}
EDev_Sen0104::~EDev_Sen0104(){}

QString EDev_Sen0104::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(Pa)";
        break;
    case SSU_pressurePa:_res="(Pa)";
        break;
    case SSU_pressureHPa:_res="(hPa)";
        break;
    case SSU_pressureKPa:_res="(kPa)";
        break;
    case SSU_pressureAtm:_res="(Atm)";
        break;
    case SSU_pressureBar:_res="(Bar)";
        break;
    case SSU_pressureBaria:_res="(Baria)";
        break;
    case SSU_pressureTorr:_res="(Torr)";
        break;
    }
    return _res;
}

double EDev_Sen0104::temperatureValue()
{
    return VDevice::decryption(REG_temp_VALUE());
}

void EDev_Sen0104::writeZero(QVector<quint16> values)
{
writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}

double EDev_Sen0104::calculatorPresure(quint32 value)
{
    double _presure=0;
    double ADC_OUT_Volts = (QVariant(value).toDouble()-QVariant(this->REG_sen01_ZERO()).toDouble())/1000.0;
    //Sensor MPX4250DP has range 0.2 -> 4.91 V with 0-250kPa
    _presure = (ADC_OUT_Volts*250000)/(4.91-0.2);
    this->setResolution(1);
    return _presure;
}


double EDev_Sen0104::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;this->setResolution(0);
        break;
    case SSU_pressurePa:_res = value;this->setResolution(0);
        break;
    case SSU_pressureHPa:_res = value/100.0;this->setResolution(2);
        break;
    case SSU_pressureKPa:_res = value/1000.0;this->setResolution(3);
        break;
    case SSU_pressureAtm:_res = value/101325.0;this->setResolution(5);
        break;
    case SSU_pressureBar:_res = value/100000.0;this->setResolution(5);
        break;
    case SSU_pressureBaria:_res = value/0.1;this->setResolution(1);
        break;
    case SSU_pressureTorr:_res = value/133.322;this->setResolution(1);
        break;
    }
    return _res;
}

void EDev_Sen0104::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(this->calculatorPresure(this->REG_sen01_VALUE())));
}

void EDev_Sen0104::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
