#include "edev_sen0105.h"

EDev_Sen0105::EDev_Sen0105(){
    this->setMaxREG(dREG_MAX);
}
EDev_Sen0105::~EDev_Sen0105(){}

QVector<QPointF> EDev_Sen0105::valueSound()
{
int _index = QVariant(this->REG_Read(dREG_SOUND_INDEX)).toInt();
QVector<QPointF> _val;
for(int i=0;i<_index;i++){
_val.append(QPointF(0,this->getVoltage(this->REG_Read(dREG_SOUND_VALUE + i))));
}
return _val;
}

int EDev_Sen0105::valueSoundAppend(QSplineSeries* lines,double freq,bool flag)
{
    if(!flag){
        m_dataIndex=0;
        lines->clear();
        m_convertData=false;
        m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        m_GET_SAMPLE_COUNT=0;
        m_GET_SAMPLE_SUM=0;
        return -1;
    }

    int _index = QVariant(this->REG_Read(dREG_SOUND_INDEX)).toInt();
   // qDebug()<<_index<<"-"<<QVariant((this->REG_Read(dREG_SOUND_VALUE)>>8)&0xFF).toInt()<<"-"<<QVariant(this->REG_Read(dREG_SOUND_VALUE)&0xFF).toInt();
    if(_index>QVariant(dREG_MAX).toInt()||_index==0)return _index;
    //Check x
    for(int i=0;i<_index*2;i++){
        double _vol;
        if(!m_convertData){
            _vol = this->getVoltage((this->REG_Read(dREG_SOUND_VALUE + i/2)>>8)&0xFF);
            m_convertData = true;
        }
        else {
            _vol = this->getVoltage(this->REG_Read(dREG_SOUND_VALUE + i/2)&0xFF);
            m_convertData = false;
        }
       // if(lines->count()>0)m_dataIndex += (freq/1000)/QVariant(_index).toDouble();
        if(_vol<0.2)break;
        if(lines->count()>0)m_dataIndex += this->getTime(this->REG_Read(dREG_SOUND_TIME));
        lines->append(m_dataIndex,_vol);
        if(_vol<5){
            if(m_GET_SAMPLE_MAX<_vol)m_GET_SAMPLE_MAX=_vol;
            if(m_GET_SAMPLE_MIN>_vol)m_GET_SAMPLE_MIN=_vol;
            m_GET_SAMPLE_COUNT++;
            m_GET_SAMPLE_SUM+=_vol;
        }
    }
    return _index*2;
}

void EDev_Sen0105::setFrequency(QVector<quint16> values)
{
    this->writeMultipleREG(dREG_SOUND_CONTROL,values);
}

double EDev_Sen0105::frequency()
{
    return QVariant(this->REG_Read(dREG_SOUND_VALUE)).toDouble();
}

double EDev_Sen0105::voltage()
{
    double _time = QVariant(this->REG_Read(dREG_SOUND_TIME)).toDouble();
    this->setElapsed(this->dataCar_T(_time,TimeUnits::TMU_Second));
    return QVariant(this->REG_Read(dREG_SOUND_VALUE)).toDouble()/1000;
}

QString EDev_Sen0105::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "(dB-SPL)";
        break;
    case SSU_soundSPL:_res = "(dB-SPL)";
        break;
    case SSU_soundDecibel:_res = "(dB)";//52 is MICRO_SENSITIVITY, 94.0 is SPL at 1Pa
        break;
    case SSU_soundVolt:_res = "(V)";
        break;
    }
    return _res;
}


double EDev_Sen0105::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;
        break;
    case SSU_soundSPL:_res = value;
        break;
    case SSU_soundDecibel:_res = value - 94.0 + 52.0;//52 is MICRO_SENSITIVITY, 94.0 is SPL at 1Pa
        break;
    case SSU_soundVolt:_res = this->sensorVoltage();
        break;
    }
    return _res;
}

void EDev_Sen0105::calculatorValue()
{
    //float volts = (((float)SENSOR_ADC * adc_Vin_max) / 4096.0)/10.0;      // convert to volts,gain 20db  = 10V
    // https://electronics.stackexchange.com/questions/96205/how-to-convert-volts-in-db-spl
    // The microphone sensitivity is -58db, so V RMS / PA is 0.001259
    // conversion using : http://www.sengpielaudio.com/calculator-gainloss.htm
    // Convert db to V0 of microphone sensitivity, -52db = 0.002512 volts
    //SOU0105_SOUND_VALUE = 20.0*log10(volts/0.002512);
    //  94 is a 1 Pa expressed as dB SPL
    // https://support.biamp.com/General/Audio/Microphone_sensitivity
    // https://forums.adafruit.com/download/file.php?id=38278&sid=3f8400ec828f5b22ed3be3ef64eb4e86
    //SOU0105_SOUND_SPL_VALUE = SOU0105_SOUND_VALUE + 94.0 + MICRO_SENSITIVITY - (float)MAX9812_GAIN;
/*
    Your microphone has a sensitivity of -46dBV/Pa , this gives 0.005012 V RMS/ Pa
    1 Pa (pascal) equals 94 dB sound pressure (SPL)

    The dB equation for voltage is 20×logV1Vo
    where V1 is the voltage being measured, and V0 the reference level

    If we do an example calculation for the measurement of 2.5v (assuming a unity gain for the amplifier) we get

    20×log2.50.005012=53.96dB
    so the SPL will be (-46) + 53.96 = 7.95 + 94 = 101.95 Db SPL

    We assumed a unity gain for the preamplifier, if the actual gain was 20dB then the SPL becomes
    101.95 - 20 = 81.95 Db SPL

    if the actual gain was 10dB then the SPL becomes
    101.95 - 10 = 91.95 Db SPL ...
 */
double _sound_DB=0;
double _R23 = 33000,_R22=33000;//Resisters is on applify of op-amp
double AMP_GAIN = 1,VOLTS_OUT=0;
double MIC9812_OUT_MAX=0;
double ADC_RESOLUTION = 4096.0;
double ADC_VOLT_REF = 4.096;
double VOLT_LV = 0;
//double VOLT_SENTIVITY_MIC=0.002512,MICRO_SENSITIVITY = -62;
double VOLT_SENTIVITY_MIC=0.002512;
//Calculator m_REG_SEN01_VALUE and sound
m_voltageSUM += QVariant(this->REG_Read(dREG_SOUND_VALUE)).toDouble();
m_timeSUM += this->dataCar_T(QVariant(this->REG_Read(dREG_SOUND_TIME)).toDouble(),TimeUnits::TMU_Second);
m_updateData = false;
if(m_voltageCNT++<8)return;
VOLT_LV = m_voltageSUM/QVariant(m_voltageCNT).toDouble();
AMP_GAIN = (1+(_R23/_R22));
MIC9812_OUT_MAX = (ADC_VOLT_REF/AMP_GAIN);
VOLTS_OUT = ((VOLT_LV * MIC9812_OUT_MAX) / ADC_RESOLUTION);
VOLTS_OUT /= 10;      // convert to volts,gain 20db  = 10V
if(VOLTS_OUT<VOLT_SENTIVITY_MIC)VOLTS_OUT=VOLT_SENTIVITY_MIC;//Limit voltages that micro measured
_sound_DB = 20.0*log10(VOLTS_OUT/VOLT_SENTIVITY_MIC);
this->setSensorVoltage(VOLTS_OUT);
this->setValue(this->sensorConvertUnits(_sound_DB));
this->setElapsed(m_timeSUM);
m_updateData = true;
m_timeSUM = 0;
m_voltageSUM = 0;
m_voltageCNT=0;
}

void EDev_Sen0105::calculatorValueCalib()
{
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}

double EDev_Sen0105::getVoltage(int vol)
{
    double _val=0;
    _val = (QVariant(vol).toDouble()*4096)/(255*1000.0);
    if(vol==255)_val=10.0;
   // qDebug()<<vol<<"-"<<_val;
    return _val;
}

double EDev_Sen0105::getTime(int time)
{
  //  double _milliSecond = (QVariant(time).toDouble()*1.6)/1000;
    double _milliSecond = QVariant(time).toDouble();
    return _milliSecond/1000;
}
