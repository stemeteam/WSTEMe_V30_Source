#include "edev_sen0107.h"

EDev_Sen0107::EDev_Sen0107(){}
EDev_Sen0107::~EDev_Sen0107(){}

QString EDev_Sen0107::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(mg/l)";
        break;
    case SSU_mg:_res="(mg/l)";
        break;
    }
    return _res;
}

double EDev_Sen0107::temperature()
{
    return m_temperature;
}

double EDev_Sen0107::temperatureTable()
{
return QVariant(DO_TABLE[QVariant(m_temperature).toUInt()]).toDouble()/1000.0;
}


void EDev_Sen0107::writeZero(QVector<quint16> values)
{
writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0107::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_mg:_res = value;
        break;
    }
    return _res;
}

void EDev_Sen0107::calculatorValue()
{
    quint32 _DO_RAW = 0;
    double V_saturation = 0;
    double mV_Sensor = QVariant(this->REG_sen01_VALUE()).toDouble();
    //Encode VALUE
    if(m_temperature>40)m_temperature=40;
    V_saturation = DO_CAL1_V + (35.0 * m_temperature) - (DO_CAL1_T * 35.0);
    _DO_RAW = QVariant((mV_Sensor * QVariant(DO_TABLE[QVariant(m_temperature).toUInt()]).toDouble()) / V_saturation).toUInt();
    //Units convert
    this->setResolution(2);
    this->setValue(this->sensorConvertUnits(QVariant(_DO_RAW).toDouble()/1000.0));//Convert to mg/l
}

void EDev_Sen0107::calculatorValueCalib()
{
    quint32 _DO_RAW = 0;
    double V_saturation = 0;
    double mV_Sensor = QVariant(this->REG_sen01_VALUE()).toDouble();
    double _CAL1_V = VDevice::decryption(this->REG_sen01_CALX1())*1000.0;//convert Volt to mVolt
    double _CAL2_V = VDevice::decryption(this->REG_sen01_CALX2())*1000.0;//convert Volt to mVolt
    double _CAL1_T = VDevice::decryption(this->REG_sen01_CALY1());
    double _CAL2_T = VDevice::decryption(this->REG_sen01_CALY2());
    double _DO_VALUE=this->value();
    //Encode VALUE
    if(m_temperature>40)m_temperature=40;
    switch(this->pointCalib()){
    case 1:
        V_saturation = _CAL1_V + (35 * m_temperature) - (_CAL1_T * 35.0);
        _DO_RAW = QVariant((mV_Sensor * QVariant(DO_TABLE[QVariant(m_temperature).toUInt()]).toDouble()) / V_saturation).toUInt();
        _DO_VALUE = this->sensorConvertUnits(QVariant(_DO_RAW).toDouble()/1000.0);
        break;
    case 2:
        double _T0 = m_temperature- _CAL2_T; // _T0 = T - T2, T = current temperature
        double _T1 = _CAL1_T - _CAL2_T;//_T1 = T1-T2
        double _V0 = _CAL1_V - _CAL2_V;//_V0 = V1-V2;
        //V_saturation = (int16_t)((int8_t)temperature_c - CAL2_T) * ((uint16_t)CAL1_V - CAL2_V) / ((uint8_t)CAL1_T - CAL2_T) + CAL2_V;
        V_saturation =  ((_T0*_V0)/_T1)+_CAL2_V;
        _DO_RAW = QVariant((mV_Sensor*QVariant(DO_TABLE[QVariant(m_temperature).toUInt()]).toDouble()/V_saturation)).toUInt();
        _DO_VALUE = this->sensorConvertUnits(QVariant(_DO_RAW).toDouble()/1000.0);
        break;
    }
    this->setResolution(2);
    this->setValueCalib(_DO_VALUE);
}
