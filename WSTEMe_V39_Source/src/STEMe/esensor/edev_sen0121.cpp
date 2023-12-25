#include "edev_sen0121.h"

EDev_Sen0121::EDev_Sen0121()
{
    this->setMaxREG(0x4B);
    m_dataRaw.resize(DATA_RAW_MAXSIZE);
}
EDev_Sen0121::~EDev_Sen0121()
{
}

QString EDev_Sen0121::sensorUnitText()
{
    QString _res="";
    switch(m_sensorUnit){
    case SSU_default:_res = "(mm)";
        break;
    case SSU_milliMeter:_res="(mm)";
        break;
    case SSU_centiMeter:_res="(cm)";
        break;
    case SSU_deciMeter:_res="(dm)";
        break;
    case SSU_Meter:_res="(m)";
        break;
    }
    return _res;
}


void EDev_Sen0121::setMode(quint16 value)
{
    writeSingleREG(ESensor_Base::dREG_MOTOR_CONTROL,value);
}

void EDev_Sen0121::setZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Sen0121::sensorConvertUnits(double value)
{
    double _res;
    switch(m_sensorUnit){
    case SSU_default:_res = value;this->setResolution(0);
        break;
    case SSU_milliMeter:_res = value;this->setResolution(0);
        break;
    case SSU_centiMeter:_res = value/10;this->setResolution(1);
        break;
    case SSU_deciMeter:_res = value/100;this->setResolution(2);
        break;
    case SSU_Meter:_res = value/1000;this->setResolution(3);
        break;
    }
    return _res;
}

void EDev_Sen0121::calculatorValue()
{
    //Units convert
    updateDataPoll();
   // this->setValue(this->REG_sen01_VALUE());
}

void EDev_Sen0121::calculatorValueCalib()
{
    this->setValueCalib(VDevice::calib(this->value(),this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}


EDev_Sen0121::EData EDev_Sen0121::getDataRaw(bool *ok)
{
    EData data;
    int head,tail;
    head = m_DATA_RAW_HEAD;
    tail = m_DATA_RAW_TAIL;
    *(ok)=false;
    if(head != tail){
        data = m_dataRaw.at(tail);
        if(++tail>=DATA_RAW_MAXSIZE)tail = 0;
        m_DATA_RAW_TAIL = tail;
        *(ok)=true;
        }
    return data;
}

void EDev_Sen0121::setDataRaw(EData data)
{
    m_dataRaw.replace(m_DATA_RAW_HEAD,data);
    m_DATA_RAW_HEAD++;
    if(m_DATA_RAW_HEAD>=m_dataRaw.size())m_DATA_RAW_HEAD = 0;
    if(m_DATA_RAW_HEAD==m_DATA_RAW_TAIL){
        if(m_DATA_RAW_HEAD>0)m_DATA_RAW_HEAD--;
            else m_DATA_RAW_HEAD = m_dataRaw.size()-1;
    }
}

void EDev_Sen0121::clearDataRaw()
{
m_DATA_RAW_HEAD = m_DATA_RAW_TAIL;
}

void EDev_Sen0121::updateDataPoll()
{
    double _val=0,_sum=0,_time=0,_lineTime=0;
    EData data;
    int _index = QVariant(this->REG_Read(dREG_SEN01_INDEX)).toInt();
     if(_index>0&&_index<19){
         for(int i=0;i<_index;i++){
             _time = QVariant(this->REG_Read(dREG_SEN01_TIME+i)).toDouble();//convert to miniSecond
             data.time = this->dataCar_T(m_time_last,_time);
             m_time_last = _time;
             if(data.time<5||data.time>1000)return;
             _lineTime += data.time;
             data.time = this->dataCar_T(data.time,TimeUnits::TMU_Second);//convert mS -> Second
             _val = QVariant(this->REG_Read(dREG_SEN01_BUFF+i)).toDouble();
             //get Offset
             _val -= QVariant(this->REG_Read(dREG_SEN01_ZERO+1)).toDouble();
             //get Units
             _val = this->sensorConvertUnits(_val);
             _sum+=_val;
             //get Calib
             _val = VDevice::calib(_val,this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3());
             //get pricision
             data.value = this->getPrecision(_val);
            this->setDataRaw(data);
         }
         this->setValue(getPrecision(_sum/QVariant(_index).toDouble()));
         this->setElapsed(this->dataCar_T(_lineTime,TimeUnits::TMU_Second));
         }
}

void EDev_Sen0121::getValueBuff()
{
    double _val=0,_sum=0,_time=0,_lineTime=0;
    int _index = QVariant(this->REG_Read(dREG_SEN01_INDEX)).toInt();
     if(_index>0&&_index<19){
         m_lineBuff->clear();
         for(int i=0;i<_index;i++){
             _time = QVariant(this->REG_Read(dREG_SEN01_TIME+i)).toDouble();//convert to miniSecond
             if(_time<10||_time>500)return;
             _val = QVariant(this->REG_Read(dREG_SEN01_BUFF+i)).toDouble();
             _lineTime += _time;
             _sum += _val;
             m_lineBuff->append(QPointF(this->dataCar_T(_time,TimeUnits::TMU_Second),this->sensorConvertUnits(VDevice::calib(_val,this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                                                                                    this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()))));
             }
         this->setValue(this->sensorConvertUnits(getPrecision(_sum/QVariant(_index).toDouble(),0)));
         this->setElapsed(this->dataCar_T(_lineTime,TimeUnits::TMU_Second));
         }
}
