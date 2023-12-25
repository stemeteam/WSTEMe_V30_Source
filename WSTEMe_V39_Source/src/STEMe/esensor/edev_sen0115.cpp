#include "edev_sen0115.h"


EDev_Sen0115::EDev_Sen0115(){}
EDev_Sen0115::~EDev_Sen0115(){}

QString EDev_Sen0115::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res="(uS/cm)";
        break;
    case SSU_uScm:_res="(uS/cm)";
        break;
    case SSU_mScm:_res="(mS/cm)";
        break;
    }
    return _res;
}

double EDev_Sen0115::temperature()
{
    m_temperature = VDevice::decryption(REG_temp_VALUE());
    return m_temperature;
}


void EDev_Sen0115::writeZero(QVector<quint16> values)
{
writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0115::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_uScm:_res=(value*1000000.0)/640.0;this->setResolution(1);
        break;
    case SSU_mScm:_res = (value*1000.0)/640;//1mScm = 1000uScm
        break;
    }
    return _res;
}

void EDev_Sen0115::calculatorValue()
{
       double ADC_OUT_Volts = (QVariant(this->REG_sen01_VALUE()).toDouble()-QVariant(this->REG_sen01_ZERO()).toDouble())/1000.0;
       double sign=1;
       if(ADC_OUT_Volts<0){
           sign=-1;
           ADC_OUT_Volts*=sign;
       }
       /*...............................................................
           Calculate Voltages at SENSOR out
           AMP_R22 = 33k//in KOhms
           AMP_R23 = 22k;//in KOhms
           AMP_GAIN = (1.0 + AMP_R23/AMP_R22);
           SENSOR_OUT_Volts = ADC_OUT_Volts/AMP_GAIN = ADC_OUT_Volts/1.66666667;
       */
       double SENSOR_OUT_Volts = ADC_OUT_Volts/1.66666667;
       /*................................................................
           Temprature compensattion in measurement
           compensationTemp=25.0;
           compensationCoefficient = 1.0 + 0.02*(compensationTemp-25.0) = 1;
           compensationVoltages = SENSOR_OUT_Volts/compensationCoefficient = SENSOR_OUT_Volts;
       */
       double compensationCoefficient=1.0+0.02*(m_temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
       double compensationVoltages = SENSOR_OUT_Volts/compensationCoefficient;
       /*.................................................................
           This is formula to calculate TDS from voltages
           Calculate TDS Value = (133.42(X^3) + 255.86(X^2) + 857.39(X))/2; //in uS/cm
           here:
               X is compensationVoltages;
       */
       double _TDS = (133.42*pow(compensationVoltages,3) + 255.86*pow(compensationVoltages,2) + 857.39*compensationVoltages)*0.5;
       _TDS = (640*(_TDS/1000))/1000;//with 640 scale, 1ppm = 640*mS/cm, 1ppt = 0.001pp
    //Units convert
    this->setResolution(3);
    this->setValue(this->sensorConvertUnits(_TDS*sign));
}

void EDev_Sen0115::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}
