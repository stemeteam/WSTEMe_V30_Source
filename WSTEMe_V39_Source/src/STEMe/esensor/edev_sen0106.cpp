#include "edev_sen0106.h"


EDev_Sen0106::EDev_Sen0106(){}
EDev_Sen0106::~EDev_Sen0106(){}

QString EDev_Sen0106::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(pH)";
        break;
    case SSU_phPH:_res="(pH)";
        break;
    }
    return _res;
}

double EDev_Sen0106::temperature()
{
    m_temperature = VDevice::decryption(REG_temp_VALUE());
    return m_temperature;
}

double EDev_Sen0106::calculatorPH(quint32 adc,double temp)
{
    /*ADC_Vref = 4.096V
     *ADC_Resolution = 4096
     *=> ADC_Vin = adc/1000 (V)
     * GAIN = (22k/12k)+1 = 2.83333333
     * Vsensor = ADC_Vin/2.83333333
     * E = VpH = Vsensor-1V (1V is voltage common)
 ======================================================
 Nernst Equation:
 E = E0 + ((R*T)/n*F)*2.303pH
 R = 8.3145 J/mol.K
 n = 1
 F = 96485.309
 T = celsius + 273.15
 E0 = 0.41412 (V)

 => E = 0.41412 - 1.9846*T*pH
 => pH = (0.41412 - E)/(1.9846*T)
     * */
    double _Vph = 0,_pH=0,_ADC_Vin=0;
    _ADC_Vin = QVariant(adc).toDouble()/1000.0;
    _Vph = (_ADC_Vin/2.833333333)-1.0;
    _pH = (0.41412-_Vph)/(0.00019846*(temp+273.15));
  //  if(_pH>14)_pH=14;
//    if(_pH<0)_pH=0;
    return _pH;
}


double EDev_Sen0106::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_phPH:_res = value;
        break;
    }
    return _res;
}

void EDev_Sen0106::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
   // this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
    this->setValue(this->sensorConvertUnits(this->calculatorPH(this->REG_sen01_ADC(),m_temperature)));
}

void EDev_Sen0106::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
