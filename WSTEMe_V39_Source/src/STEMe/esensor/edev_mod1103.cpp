#include "edev_mod1103.h"



EDev_Mod1103::EDev_Mod1103()
{
this->setMaxREG(0x7D);
m_emfsData.car01.resize(DATA_RAW_MAXSIZE);
m_emfsData.car02.resize(DATA_RAW_MAXSIZE);
}

EDev_Mod1103::~EDev_Mod1103()
{

}

int EDev_Mod1103::getESlave(EDev_Mod1103::ESlave slave)
{
    switch(slave){
    case ESlave::CAR_01:return 0;
     case ESlave::CAR_02:return 1;
       case ESlave::CAR_ALL:return 2;
    }
    return 0;
}

EDev_Mod1103::ESlave EDev_Mod1103::getESlave(int slave)
{
    switch(slave){
    case 0:return ESlave::CAR_01;
      case 1:return ESlave::CAR_02;
        case 2:return ESlave::CAR_ALL;
    }
    return ESlave::CAR_01;
}

int EDev_Mod1103::getCarCondition(EDev_Mod1103::CarCondition condition)
{
    switch(condition){
    case CarCondition::CCD_default:return 0;
    case CarCondition::CCD_S_Higher:return 1;
    case CarCondition::CCD_S_Lower:return 2;
    case CarCondition::CCD_V_Higher:return 3;
    case CarCondition::CCD_V_Lower:return 4;
    case CarCondition::CCD_A_Higher:return 5;
    case CarCondition::CCD_A_Lower:return 6;
    case CarCondition::CCD_F_Higher:return 7;
    case CarCondition::CCD_F_Lower:return 8;
    case CarCondition::CCD_T_Higher:return 9;
    }
    return 0;
}

EDev_Mod1103::CarCondition EDev_Mod1103::getCarCondition(int condition)
{
    switch(condition){
    case 0:return CarCondition::CCD_default;
    case 1:return CarCondition::CCD_S_Higher;
    case 2:return CarCondition::CCD_S_Lower;
    case 3:return CarCondition::CCD_V_Higher;
    case 4:return CarCondition::CCD_V_Lower;
    case 5:return CarCondition::CCD_A_Higher;
    case 6:return CarCondition::CCD_A_Lower;
    case 7:return CarCondition::CCD_F_Higher;
    case 8:return CarCondition::CCD_F_Lower;
    case 9:return CarCondition::CCD_T_Higher;
    }
    return CarCondition::CCD_default;
}

QString EDev_Mod1103::getCarConditionUnit(int condition,ECar car)
{
    switch(condition){
    case 0:return "";
    case 1:return EDev_Mod1103::distanceUnit(car.s.unit);
    case 2:return EDev_Mod1103::distanceUnit(car.s.unit);
    case 3:return EDev_Mod1103::speedUnit(car.v.unit);
    case 4:return EDev_Mod1103::speedUnit(car.v.unit);
    case 5:return EDev_Mod1103::accelerationUnit(car.a.unit);
    case 6:return EDev_Mod1103::accelerationUnit(car.a.unit);
    case 7:return EDev_Mod1103::forceUnit(car.f.unit);
    case 8:return EDev_Mod1103::forceUnit(car.f.unit);
    case 9:return EDev_Mod1103::timeUnit(car.t.unit);
    }
    return "";
}

QString EDev_Mod1103::getCarConditionUnit(EDev_Mod1103::CarCondition condition, EDev_Mod1103::ECar car)
{
    return EDev_Mod1103::getCarConditionUnit(EDev_Mod1103::getCarCondition(condition),car);
}

EDev_Mod1103::ECar EDev_Mod1103::getCar(ESlave slave,EDev_Mod1103::ECar car01, EDev_Mod1103::ECar car02)
{
    switch(slave){
    case ESlave::CAR_01:return car01;
     case ESlave::CAR_02:return car02;
       case ESlave::CAR_ALL:return car01;
    }
    return car01;
}

EDev_Mod1103::ECar EDev_Mod1103::getCar(EDev_Mod1103::ESlave slave)
{
    switch(slave){
    case ESlave::CAR_01:return m_ecar_01;
     case ESlave::CAR_02:return m_ecar_02;
       case ESlave::CAR_ALL:return m_ecar_01;
    }
    return m_ecar_01;
}

void EDev_Mod1103::setCar(EDev_Mod1103::ESlave slave, EDev_Mod1103::ECar car)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01=car;
        break;
     case ESlave::CAR_02:m_ecar_02=car;
        break;
       case ESlave::CAR_ALL:m_ecar_01=car;
        break;
    }
}

EDev_Mod1103::ForceUnits EDev_Mod1103::sensorUnit(ESlave slave)
{
    if(slave==ESlave::CAR_02)return m_ecar_02.f.unit;
    return m_ecar_01.f.unit;
}

void EDev_Mod1103::setForceUnit(ESlave slave, EDev_Mod1103::ForceUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.f.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.f.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.f.unit = unit;m_ecar_02.f.unit = unit;
        break;
    }
}

QString EDev_Mod1103::forceUnit(EDev_Mod1103::ForceUnits unit)
{
    QString _val = "(N)";
        switch(unit){
            case SSU_default:
                break;
            case SSU_scaleForce:
                break;
            case SSU_scaleGram:_val = "(G)";
                break;
            case SSU_scaleKiloGram:_val = "(Kg)";
                break;
            case SSU_scaleWeight:_val = "(Kg)";
                break;

            }
        return _val;
}

void EDev_Mod1103::setDistanceUnit(ESlave slave, EDev_Mod1103::DistanceUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.s.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.s.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.s.unit = unit;m_ecar_02.s.unit = unit;
        break;
    }
}

QString EDev_Mod1103::distanceUnit(EDev_Mod1103::DistanceUnits unit)
{
    QString _val = "(mm)";
        switch(unit)
        {
        case DistanceUnits::DSU_default:
            break;
        case DistanceUnits::DSU_millimetre:
            break;
        case DistanceUnits::DSU_metre:_val = "(m)";
            break;
        case DistanceUnits::DSU_kilometre:_val = "(Km)";
            break;
        }
        return _val;
}

void EDev_Mod1103::setSpeedUnit(ESlave slave, EDev_Mod1103::SpeedUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.v.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.v.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.v.unit = unit;m_ecar_02.v.unit = unit;
        break;
    }
}

QString EDev_Mod1103::speedUnit(EDev_Mod1103::SpeedUnits unit)
{
    QString _val = "(mm/s)";
        switch(unit)
            {
            case SpeedUnits::SPU_default:
                break;
            case SpeedUnits::SPU_mm_per_second:
                break;
            case SpeedUnits::SPU_m_per_second:_val = "(m/s)";
                break;
            case SpeedUnits::SPU_km_per_hour:_val = "(km/s)";  //1 m/s = 3.6 km/h
                break;
            }
        return _val;
}

void EDev_Mod1103::setAccelerationUnit(ESlave slave, EDev_Mod1103::AccelerationUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.a.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.a.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.a.unit = unit;m_ecar_02.a.unit = unit;
        break;
    }
}

QString EDev_Mod1103::accelerationUnit(EDev_Mod1103::AccelerationUnits unit)
{
    QString _val = "(mm/s2)";
        switch(unit)
            {
            case AccelerationUnits::ACU_default:
                break;
            case AccelerationUnits::ACU_mm_per_s2:
                break;
            case AccelerationUnits::ACU_m_per_s2:_val = "(m/s2)";
                break;
            }
        return _val;
}

void EDev_Mod1103::setVoltageUnit(ESlave slave, EDev_Mod1103::VoltageUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.pin.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.pin.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.pin.unit = unit;m_ecar_02.pin.unit = unit;
        break;
    }
}

QString EDev_Mod1103::voltageUnit(EDev_Mod1103::VoltageUnits unit)
{
    QString _val="(V)";
        switch(unit)
            {
            case VoltageUnits::VTU_default:
                break;
            case VoltageUnits::VTU_mVolt:_val="(V)";
                break;
            case VoltageUnits::VTU_Volt:
                break;
            }
        return _val;
}

void EDev_Mod1103::setTimeUnit(ESlave slave, EDev_Mod1103::TimeUnits unit)
{
    switch(slave){
    case ESlave::CAR_01:m_ecar_01.t.unit = unit;
        break;
     case ESlave::CAR_02:m_ecar_02.t.unit = unit;
        break;
       case ESlave::CAR_ALL:m_ecar_01.t.unit = unit;m_ecar_02.t.unit = unit;
        break;
    }
}

QString EDev_Mod1103::timeUnit(EDev_Mod1103::TimeUnits unit)
{
    QString _val="(S)";
        switch(unit){
        case TMU_default:
            break;
        case TMU_uSecond:_val="(uS)";
            break;
        case TMU_mSecond:_val="(mS)";
            break;
        case TMU_Second:
            break;
        }
        return _val;
}

void EDev_Mod1103::on_PollTimer()
{

}

void EDev_Mod1103::setMeasureVector(ESlave slave, bool vector)
{
    switch(slave){
    case ESlave::CAR_01:m_useMeasureVector[0] = vector;
        break;
     case ESlave::CAR_02:m_useMeasureVector[1] = vector;
        break;
       case ESlave::CAR_ALL:
        m_useMeasureVector[0] = vector;
        m_useMeasureVector[1] = vector;
        break;
    }
}

void EDev_Mod1103::setReverseSign(ESlave slave, bool sign)
{
    switch(slave){
    case ESlave::CAR_01:m_useReverseSign[0] = sign;
        break;
    case ESlave::CAR_02:m_useReverseSign[1] = sign;
        break;
    case ESlave::CAR_ALL:
        m_useReverseSign[0] = sign;
        m_useReverseSign[1] = sign;
        break;
    }
}

EDev_Mod1103::ECar EDev_Mod1103::sensorCar(ESlave slave)
{
    switch(slave){
    case ESlave::CAR_01:return m_ecar_01;
     case ESlave::CAR_02:return m_ecar_02;
       case ESlave::CAR_ALL:return m_ecar_01;
    }
    return m_ecar_01;
}

EDev_Mod1103::ECarLines EDev_Mod1103::lineCar(ESlave slave)
{
    switch(slave){
    case ESlave::CAR_01:return m_ecarLines_01;
     case ESlave::CAR_02:return m_ecarLines_02;
       case ESlave::CAR_ALL:return m_ecarLines_01;
    }
    return m_ecarLines_01;
}


EDev_Mod1103::ECarSPlines EDev_Mod1103::splineCar(ESlave slave)
{
    switch(slave){
    case ESlave::CAR_01:return m_ecarSPlines_01;
     case ESlave::CAR_02:return m_ecarSPlines_02;
       case ESlave::CAR_ALL:return m_ecarSPlines_01;
    }
    return m_ecarSPlines_01;
}

void EDev_Mod1103::setLineCar(ESlave slave,EDev_Mod1103::ECarLines lines,bool clear)
{
    switch(slave){
    case ESlave::CAR_01:
        if(clear){
            m_ecarLines_01.line_s->clear();
            m_ecarLines_01.line_d->clear();
            m_ecarLines_01.line_t->clear();
            m_ecarLines_01.line_v->clear();
            m_ecarLines_01.line_a->clear();
            m_ecarLines_01.line_f->clear();
            m_ecarLines_01.line_index = 0;
            m_ecarLines_01.line_time = 0;
        }
        else m_ecarLines_01 = lines;
        break;
     case ESlave::CAR_02:
        if(clear){
            m_ecarLines_02.line_s->clear();
            m_ecarLines_02.line_d->clear();
            m_ecarLines_02.line_t->clear();
            m_ecarLines_02.line_v->clear();
            m_ecarLines_02.line_a->clear();
            m_ecarLines_02.line_f->clear();
            m_ecarLines_02.line_index = 0;
            m_ecarLines_02.line_time = 0;
        }
        else m_ecarLines_02 = lines;
        break;
       case ESlave::CAR_ALL:
        if(clear){
            m_ecarLines_01.line_s->clear();
            m_ecarLines_01.line_d->clear();
            m_ecarLines_01.line_t->clear();
            m_ecarLines_01.line_v->clear();
            m_ecarLines_01.line_a->clear();
            m_ecarLines_01.line_f->clear();
            m_ecarLines_01.line_index = 0;
            m_ecarLines_01.line_time = 0;
            m_ecarLines_02.line_s->clear();
            m_ecarLines_02.line_d->clear();
            m_ecarLines_02.line_t->clear();
            m_ecarLines_02.line_v->clear();
            m_ecarLines_02.line_a->clear();
            m_ecarLines_02.line_f->clear();
            m_ecarLines_02.line_index = 0;
            m_ecarLines_02.line_time = 0;
        }
        else {
            m_ecarLines_01 = lines;
            m_ecarLines_02 = lines;
        }
        break;
    }
}

void EDev_Mod1103::setLineCar(ESlave slave, ECarSPlines lines, bool clear)
{
    switch(slave){
    case ESlave::CAR_01:
        if(clear){
            m_ecarSPlines_01.line_s->clear();
            m_ecarSPlines_01.line_d->clear();
            m_ecarSPlines_01.line_t->clear();
            m_ecarSPlines_01.line_v->clear();
            m_ecarSPlines_01.line_a->clear();
            m_ecarSPlines_01.line_f->clear();
            m_ecarSPlines_01.line_index = 0;
            m_ecarSPlines_01.line_time = 0;
        }
        else m_ecarSPlines_01 = lines;
        break;
     case ESlave::CAR_02:
        if(clear){
            m_ecarSPlines_02.line_s->clear();
            m_ecarSPlines_02.line_d->clear();
            m_ecarSPlines_02.line_t->clear();
            m_ecarSPlines_02.line_v->clear();
            m_ecarSPlines_02.line_a->clear();
            m_ecarSPlines_02.line_f->clear();
            m_ecarSPlines_02.line_index = 0;
            m_ecarSPlines_02.line_time = 0;
        }
        else m_ecarSPlines_02 = lines;
        break;
       case ESlave::CAR_ALL:
        if(clear){
            m_ecarSPlines_01.line_s->clear();
            m_ecarSPlines_01.line_d->clear();
            m_ecarSPlines_01.line_t->clear();
            m_ecarSPlines_01.line_v->clear();
            m_ecarSPlines_01.line_a->clear();
            m_ecarSPlines_01.line_f->clear();
            m_ecarSPlines_01.line_index = 0;
            m_ecarSPlines_01.line_time = 0;
            m_ecarSPlines_02.line_s->clear();
            m_ecarSPlines_02.line_d->clear();
            m_ecarSPlines_02.line_t->clear();
            m_ecarSPlines_02.line_v->clear();
            m_ecarSPlines_02.line_a->clear();
            m_ecarSPlines_02.line_f->clear();
            m_ecarSPlines_02.line_index = 0;
            m_ecarSPlines_02.line_time = 0;
        }
        else {
            m_ecarSPlines_01 = lines;
            m_ecarSPlines_02 = lines;
        }
        break;
    }
}


void EDev_Mod1103::setUpdateLine(bool update,CarMode mode)
{
    m_updateLine = update;
    m_CMD_carMode = mode;
}

void EDev_Mod1103::writeSensorCommand(ESlave slave, EDev_Mod1103::CAR_Command cmd)
{
    quint16 val=0;
    switch (cmd) {
    case CAR_Command::CCMD_ZeroCAR:val = uint16_t(mapZeroCAR);
        break;
    case CAR_Command::CCMD_ZeroForce:val = uint16_t(mapZeroForce);
        break;
    case CAR_Command::CCMD_Shutdown:val = uint16_t(mapShutdown);
        break;
    case CAR_Command::CCMD_Calib_S:val = uint16_t(mapShutdown);
        break;
    case CAR_Command::CCMD_Calib_F:val = uint16_t(mapShutdown);
        break;
    }
    switch(slave){
        case ESlave::CAR_01:
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t(val<<8));
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t(val<<8));
            break;
        case ESlave::CAR_02:
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t(val));
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t(val));
            break;
        case ESlave::CAR_ALL:
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t((val<<8)|val));
            this->writeSingleREG(dREG_CAR_Command,std::uint16_t((val<<8)|val));
            break;
    }
}

uint EDev_Mod1103::dataPoll_uint16(uint d1, uint d2)
{
    uint _val=0;
    if(d2>=d1)_val = QVariant(d2-d1).toUInt();
        else _val = QVariant((65536-d1)+d2).toUInt();
    return _val;
}

double EDev_Mod1103::dataPoll_uint16(double d1, double d2)
{
    double _val=0;
    if(d2>=d1)_val = d2-d1;
        else _val = (65536-d1)+d2;
    return _val;
}

uint EDev_Mod1103::getAbsMult(uint s1, uint s2)
{
if(s1>s2)return (s1-s2);
else return (s2-s1);
}

double EDev_Mod1103::getPrecision(double val, int pre)
{
return QString::number(val,'f',pre).toDouble();
}

void EDev_Mod1103::setChartParameter(ECharts::Parameter p)
{
    m_echart->setParameter(p);
}
void EDev_Mod1103::setChartParameter(EChartLines::Parameter p)
{
    m_echartLine->setParameter(p);
}

void EDev_Mod1103::setScanType(ECharts::ScanType type)
{
    if(m_echart)m_echart->setScanType(type);
}
void EDev_Mod1103::setScanType(EChartLines::ScanType type)
{
    if(m_echartLine)m_echartLine->setScanType(type);
}


QPointF EDev_Mod1103::getChartValueMouse(int line)
{
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)return m_echart->getValueMouse(line);
        else return QPointF(0,0);
        }
        else{
            if(m_echartLine)return m_echartLine->getValueMouse(line);
            else return QPointF(0,0);
        }
}

void EDev_Mod1103::setColorTextAxis_X(QColor color)
{
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)return m_echart->setColorTextAxis_X(color);
    }
    else {
        if(m_echartLine)return m_echartLine->setColorTextAxis_X(color);
    }
}

void EDev_Mod1103::setColorTextAxis_Y(QColor color)
{
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)return m_echart->setColorTextAxis_Y(color);
    }
    else {
        if(m_echartLine)return m_echartLine->setColorTextAxis_Y(color);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////CHARTS//////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EDev_Mod1103::chartInit(QWidget *widget,TypeLine type)
{
    m_typeLine = type;
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)delete m_echart;
        m_echart = new ECharts();
        ECharts::Parameter parameter;
        parameter.timerScan = m_chartTimerScan;
        parameter.axisX_Range_Max = m_axisX_Range;
        parameter.axisX_Range_Min = 0;
        parameter.axisX_TickCount = m_axisX_TickCount;
        parameter.axisY_TickCount = m_axisY_TickCount;
        parameter.axisY_Range_Min = m_axisY_Range_Min;
        parameter.axisY_Range_Max = m_axisY_Range_Max;
        for(int i=0;i<m_listColor.count();i++){
            m_echart->replaceListLineColor(i,m_listColor.at(i));
        }
        m_echart->init(parameter,8,widget);
        m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_chartTimerScan).toDouble()))).toInt());//Scan in 1 hour
    }
    else {
        if(m_echartLine)delete m_echartLine;
        m_echartLine = new EChartLines();
        EChartLines::Parameter parameter;
        parameter.timerScan = m_chartTimerScan;
        parameter.axisX_Range_Max = m_axisX_Range;
        parameter.axisX_Range_Min = 0;
        parameter.axisX_TickCount = m_axisX_TickCount;
        parameter.axisY_TickCount = m_axisY_TickCount;
        parameter.axisY_Range_Min = m_axisY_Range_Min;
        parameter.axisY_Range_Max = m_axisY_Range_Max;
        for(int i=0;i<m_listColor.count();i++){
            m_echartLine->replaceListLineColor(i,m_listColor.at(i));
        }
        m_echartLine->init(parameter,8,widget);
        m_echartLine->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_chartTimerScan).toDouble()))).toInt());//Scan in 1 hour
    }

}

void EDev_Mod1103::graph(QPointF vals, int line)
{
    if(m_typeLine==TypeLine::typeSpline)m_echart->graph(vals,line);
    else m_echartLine->graph(vals,line);
}

void EDev_Mod1103::setSpline(QSplineSeries *series, int line)
{
    m_echart->setSplines(series,line);
}

void EDev_Mod1103::setSpline(QLineSeries *series, int line)
{
    m_echartLine->setSplines(series,line);
}

void EDev_Mod1103::chartClear()
{
    if(m_typeLine==TypeLine::typeSpline){
        m_echart->clear();
        m_echart->setLinesIndex(1);
        }
        else{
            m_echartLine->clear();
            m_echartLine->setLinesIndex(1);
        }
}

void EDev_Mod1103::setTrackLine(EChartGesture::ETrackLine track)
{
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)m_echart->setTrackLine(track);
        }
        else{
            if(m_echartLine)m_echartLine->setTrackLine(track);
        }
}

void EDev_Mod1103::setPrecisionXY(int x, int y)
{
    if(m_typeLine==TypeLine::typeSpline){
        if(m_echart)m_echart->setPrecisionXY(x,y);
        }
        else {
        if(m_echartLine)m_echartLine->setPrecisionXY(x,y);
        }
}
////////////////////////////////////////////////////////////////////////////////////////Update NEW//////////////////////////
uint EDev_Mod1103::frame_Index(ESlave slave)
{
    switch(slave)
    {
    case ESlave::CAR_01:return QVariant(this->REG_Read(dREG_CAR01_INDEX)).toUInt();
    case ESlave::CAR_02:return QVariant(this->REG_Read(dREG_CAR02_INDEX)).toUInt();
    case ESlave::CAR_ALL:
        break;
    }
    return 0;
}

uint EDev_Mod1103::frame_Force_Index(ESlave slave)
{
    switch(slave)
    {
    case ESlave::CAR_01:return QVariant(this->REG_Read(dREG_CAR01_F_INDEX)).toUInt();
    case ESlave::CAR_02:return QVariant(this->REG_Read(dREG_CAR02_F_INDEX)).toUInt();
    case ESlave::CAR_ALL:
        break;
    }
    return 0;
}

double EDev_Mod1103::frame_S(EDev_Mod1103::ESlave slave,uint index)
{
    double _s = 0;
    if(slave==ESlave::CAR_01)_s = this->REG_Read(dREG_CAR01_D + QVariant(index).toInt());
    if(slave==ESlave::CAR_02)_s = this->REG_Read(dREG_CAR02_D + QVariant(index).toInt());
    if(_s>=0x8000)_s = _s-65536.0;//Convert int16_t to double
    _s = _s*this->frame_sc(slave);
    return _s;
}

uint EDev_Mod1103::frame_t(EDev_Mod1103::ESlave slave,uint index)
{
    uint _val=0;
    int i = QVariant(index).toInt();
    if(slave==ESlave::CAR_01)_val = this->REG_Read(dREG_CAR01_T +i);
    if(slave==ESlave::CAR_02)_val = this->REG_Read(dREG_CAR02_T +i);
    return _val;
}

double EDev_Mod1103::frame_f(EDev_Mod1103::ESlave slave,uint index)
{
    double _f = 0;
    if(slave==ESlave::CAR_01)_f = this->REG_Read(dREG_CAR01_F + QVariant(index).toInt());
    if(slave==ESlave::CAR_02)_f = this->REG_Read(dREG_CAR02_F + QVariant(index).toInt());
    if(_f>=0x8000)_f = _f-65536.0;//Convert int16_t to double
    _f = _f*this->frame_fc(slave);
    return _f;
}

double EDev_Mod1103::frame_pin(EDev_Mod1103::ESlave slave)
{
    double _v = 0;
    if(slave==ESlave::CAR_01)_v = this->REG_Read(dREG_CAR01_PIN);
    if(slave==ESlave::CAR_02)_v = this->REG_Read(dREG_CAR02_PIN);
    return _v;
}

QString EDev_Mod1103::frame_add(EDev_Mod1103::ESlave slave)
{
    QString _s="";
    if(slave==ESlave::CAR_01){
        _s += QVariant(this->REG_Read(dREG_CAR01_ADD)&0xFF).toChar();
        _s += QVariant((this->REG_Read(dREG_CAR01_ADD+1)>>8)&0xFF).toChar();
        _s += QVariant(this->REG_Read(dREG_CAR01_ADD+1)&0xFF).toChar();
        _s += QVariant((this->REG_Read(dREG_CAR01_ADD+2)>>8)&0xFF).toChar();
        _s += QVariant(this->REG_Read(dREG_CAR01_ADD+2)&0xFF).toChar();
    }
    if(slave==ESlave::CAR_02){
        _s += QVariant(this->REG_Read(dREG_CAR02_ADD)&0xFF).toChar();
        _s += QVariant((this->REG_Read(dREG_CAR02_ADD+1)>>8)&0xFF).toChar();
        _s += QVariant(this->REG_Read(dREG_CAR02_ADD+1)&0xFF).toChar();
        _s += QVariant((this->REG_Read(dREG_CAR02_ADD+2)>>8)&0xFF).toChar();
        _s += QVariant(this->REG_Read(dREG_CAR02_ADD+2)&0xFF).toChar();
    }
    return _s;
}

double EDev_Mod1103::frame_sc(EDev_Mod1103::ESlave slave)
{
    quint32 _val=0;
    double _s = 0;
    if(slave==ESlave::CAR_01)_val = QVariant(this->REG_Read(dREG_CAR01_CALS_X+1)).toUInt()|(QVariant(this->REG_Read(dREG_CAR01_CALS_X)).toUInt()<<16);
    if(slave==ESlave::CAR_02)_val = QVariant(this->REG_Read(dREG_CAR02_CALS_X+1)).toUInt()|(QVariant(this->REG_Read(dREG_CAR02_CALS_X)).toUInt()<<16);
    _s = VDevice::decryption(_val);
    if(_s==0)_s=0.366;
    return _s;
}

double EDev_Mod1103::frame_fc(EDev_Mod1103::ESlave slave)
{
    quint32 _val=0;
    double _f = 0;
    if(slave==ESlave::CAR_01)_val = QVariant(this->REG_Read(dREG_CAR01_CALF_X+1)).toUInt()|(QVariant(this->REG_Read(dREG_CAR01_CALF_X)).toUInt()<<16);
    if(slave==ESlave::CAR_02)_val = QVariant(this->REG_Read(dREG_CAR02_CALF_X+1)).toUInt()|(QVariant(this->REG_Read(dREG_CAR02_CALF_X)).toUInt()<<16);
    _f = VDevice::decryption(_val);
    if(_f==0)_f=1;
    return _f;
}

uint EDev_Mod1103::frame_ts(EDev_Mod1103::ESlave slave)
{
    uint _val=0;
    if(slave==ESlave::CAR_01)_val = QVariant(this->REG_Read(dREG_CAR01_TS)).toUInt();
    if(slave==ESlave::CAR_02)_val = QVariant(this->REG_Read(dREG_CAR02_TS)).toUInt();
    return _val;
}

uint EDev_Mod1103::frame_cs(EDev_Mod1103::ESlave slave)
{
    uint _val=0;
    if(slave==ESlave::CAR_01)_val = QVariant(this->REG_Read(dREG_CAR01_CS)).toUInt();
    if(slave==ESlave::CAR_02)_val = QVariant(this->REG_Read(dREG_CAR02_CS)).toUInt();
    return _val;
}

uint EDev_Mod1103::frame_SPT(ESlave slave)
{
    uint _val=0;
    if(slave==ESlave::CAR_01)_val = QVariant(this->REG_Read(dREG_CAR01_SPT)).toUInt();
    if(slave==ESlave::CAR_02)_val = QVariant(this->REG_Read(dREG_CAR02_SPT)).toUInt();
    return _val;
}

uint EDev_Mod1103::frame_timeSystem()
{
    return QVariant(this->REG_Read(dREG_TIME_SYSTEM)).toUInt();
}


double EDev_Mod1103::dataCar_S(double s,DistanceUnits unit)
{
    double _val = s;
    switch(unit)
    {
    case DistanceUnits::DSU_default:
        break;
    case DistanceUnits::DSU_millimetre:
        break;
    case DistanceUnits::DSU_metre:_val /= 1000.0;
        break;
    case DistanceUnits::DSU_kilometre:_val /= 1000000.0;
        break;
    }
    return _val;
}

double EDev_Mod1103::dataCar_S(double s, EDev_Mod1103::DistanceUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_S(s,unit),pre);
}


double EDev_Mod1103::dataCar_T(uint t1, uint t2)
{
    double _val=0;
    if(t2>=t1)_val = QVariant(t2-t1).toDouble();
        else _val = QVariant(65536-t1+t2).toDouble();
    return _val;
}


double EDev_Mod1103::dataCar_T(double t1, double t2)
{
    double _val=0;
    if(t2>=t1)_val = t2-t1;
        else _val = (65536-t1)+t2;
    return _val;
}

double EDev_Mod1103::dataCar_T(double t, EDev_Mod1103::TimeUnits unit)
{
    double _val=t;
    switch(unit){
    case TMU_default:
        break;
    case TMU_uSecond:_val *=1000;
        break;
    case TMU_mSecond:
        break;
    case TMU_Second:_val /= 1000;
        break;
    }
    return _val;
}

double EDev_Mod1103::dataCar_T(double t, EDev_Mod1103::TimeUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_T(t,unit),pre);
}

double EDev_Mod1103::dataCar_V(double s1, double s2, double t)
{
return ((s2-s1)/t);
}

double EDev_Mod1103::dataCar_V(double v, EDev_Mod1103::SpeedUnits unit)
{
    double _val = v;
    switch(unit)
        {
        case SpeedUnits::SPU_default:
            break;
        case SpeedUnits::SPU_mm_per_second:
            break;
        case SpeedUnits::SPU_m_per_second:_val /=1000;
            break;
        case SpeedUnits::SPU_km_per_hour:_val = (_val/1000)*3.6;  //1 m/s = 3.6 km/h
            break;
        }
    return _val;
}

double EDev_Mod1103::dataCar_V(double v, EDev_Mod1103::SpeedUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_V(v,unit),pre);
}

double EDev_Mod1103::dataCar_A(double v1, double v2, double t)
{
    return ((v2-v1)/t);
}

double EDev_Mod1103::dataCar_A(double a, EDev_Mod1103::AccelerationUnits unit)
{
    double _val = a;
    switch(unit)
        {
        case AccelerationUnits::ACU_default:
            break;
        case AccelerationUnits::ACU_mm_per_s2:
            break;
        case AccelerationUnits::ACU_m_per_s2:_val /=1000;
            break;
        }
    return _val;
}

double EDev_Mod1103::dataCar_A(double a, EDev_Mod1103::AccelerationUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_A(a,unit),pre);
}

double EDev_Mod1103::dataCar_PIN(double v, EDev_Mod1103::VoltageUnits unit)
{
    double _val=v;
    switch(unit)
        {
        case VoltageUnits::VTU_default:
            break;
        case VoltageUnits::VTU_mVolt:
            break;
        case VoltageUnits::VTU_Volt:_val /= 1000;
            break;
        }
    return _val;
}

double EDev_Mod1103::dataCar_PIN(double v, EDev_Mod1103::VoltageUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_PIN(v,unit),pre);
}

double EDev_Mod1103::dataCar_F(double f, EDev_Mod1103::ForceUnits unit)
{
    double _val = f;
    switch(unit){
        case SSU_default:
            break;
        case SSU_scaleForce:_val /= 100;
            break;
        case SSU_scaleGram:
            break;
        case SSU_scaleKiloGram:_val /= 1000;
            break;
        case SSU_scaleWeight:_val *= 0.0098;
            break;

        }
    return _val;
}

double EDev_Mod1103::dataCar_F(double f, EDev_Mod1103::ForceUnits unit, int pre)
{
    return this->getPrecision(this->dataCar_F(f,unit),pre);
}


QString EDev_Mod1103::getConditionText(CarCondition condition)
{
    switch(condition)
       {
       case CarCondition::CCD_default:
        return "Không có điều kiện";;
       case CarCondition::CCD_S_Higher:
           return "Quãng đường (lớn hơn)";
       case CarCondition::CCD_S_Lower:
           return "Quãng đường (nhỏ hơn)";
       case CarCondition::CCD_V_Higher:
           return "Vận tốc (lớn hơn)";
       case CarCondition::CCD_V_Lower:
           return "Vận tốc (nhỏ hơn)";
       case CarCondition::CCD_A_Higher:
           return "Gia tốc (lớn hơn)";
       case CarCondition::CCD_A_Lower:
           return "Gia tốc (nhỏ hơn)";
       case CarCondition::CCD_F_Higher:
           return "Lực tác động (lớn hơn)";
       case CarCondition::CCD_F_Lower:
           return "Lực tác động (nhỏ hơn)";
       case CarCondition::CCD_T_Higher:
           return "Thời gian (lớn hơn)";
       }
    return "";
}

double EDev_Mod1103::checkVector(double val,EDev_Mod1103::ESlave slave)
{
    switch (slave) {
    case ESlave::CAR_01:
        if(!m_useMeasureVector[0]&&val<0)val*=(-1);
        if(m_useReverseSign[0])val*=(-1);
        break;
    case ESlave::CAR_02:
        if(!m_useMeasureVector[1]&&val<0)val*=(-1);
        if(m_useReverseSign[1])val*=(-1);
        break;
    case ESlave::CAR_ALL:
        break;
    }
    return val;
}

EDev_Mod1103::ECar EDev_Mod1103::getDataRawBefore(ESlave slave)
{
    ECar data;
    switch(slave){
        case ESlave::CAR_01:
            if(m_CAR01_DATA_RAW_HEAD==0)data = m_emfsData.car01.at(m_emfsData.car01.count()-2);
                else data = m_emfsData.car01.at(m_CAR01_DATA_RAW_HEAD-2);
            break;
        case ESlave::CAR_02:
            if(m_CAR02_DATA_RAW_HEAD==0)data = m_emfsData.car02.at(m_emfsData.car02.count()-2);
                else data = m_emfsData.car02.at(m_CAR02_DATA_RAW_HEAD-2);
            break;
        case ESlave::CAR_ALL:
        break;
    }
    return data;
}

EDev_Mod1103::ECar EDev_Mod1103::getDataRawLast(ESlave slave, bool clear)
{
    ECar data;
    switch(slave){
        case ESlave::CAR_01:
            if(m_CAR01_DATA_RAW_HEAD==0)data = m_emfsData.car01.last();
                else data = m_emfsData.car01.at(m_CAR01_DATA_RAW_HEAD-1);
            if(clear)m_CAR01_DATA_RAW_TAIL = m_CAR01_DATA_RAW_HEAD;
            break;
        case ESlave::CAR_02:
            if(m_CAR02_DATA_RAW_HEAD==0)data = m_emfsData.car02.last();
                else data = m_emfsData.car02.at(m_CAR02_DATA_RAW_HEAD-1);
            if(clear)m_CAR02_DATA_RAW_TAIL = m_CAR02_DATA_RAW_HEAD;
            break;
        case ESlave::CAR_ALL:
        break;
    }
    return data;
}


EDev_Mod1103::ECar EDev_Mod1103::getDataRaw(ESlave slave, bool *ok)
{
    ECar data;
    //return -1 is status error frame rs232
    int head, tail;
    *(ok)=false;
    switch(slave){
        case ESlave::CAR_01:
            head = m_CAR01_DATA_RAW_HEAD;
            tail = m_CAR01_DATA_RAW_TAIL;
            if(head != tail){
                data = m_emfsData.car01.at(tail);
                if(++tail>=DATA_RAW_MAXSIZE)tail = 0;
                m_CAR01_DATA_RAW_TAIL = tail;
                *(ok)=true;
                }
            break;
        case ESlave::CAR_02:
            head = m_CAR02_DATA_RAW_HEAD;
            tail = m_CAR02_DATA_RAW_TAIL;
            if(head != tail){
                data = m_emfsData.car02.at(tail);
                if(++tail>=DATA_RAW_MAXSIZE)tail = 0;
                m_CAR02_DATA_RAW_TAIL = tail;
                *(ok)=true;
                }
        break;
        case ESlave::CAR_ALL:
        break;
    }
    return data;
}

void EDev_Mod1103::setDataRaw(ESlave slave, ECar data)
{
    switch(slave){
        case ESlave::CAR_01:
            m_emfsData.car01.replace(m_CAR01_DATA_RAW_HEAD,data);
            m_CAR01_DATA_RAW_HEAD++;
            if(m_CAR01_DATA_RAW_HEAD>=m_emfsData.car01.size())m_CAR01_DATA_RAW_HEAD = 0;
            if(m_CAR01_DATA_RAW_HEAD==m_CAR01_DATA_RAW_TAIL){
                if(m_CAR01_DATA_RAW_HEAD>0)m_CAR01_DATA_RAW_HEAD--;
                    else m_CAR01_DATA_RAW_HEAD = m_emfsData.car01.size()-1;
                    }
        break;
        case ESlave::CAR_02:
            m_emfsData.car02.replace(m_CAR02_DATA_RAW_HEAD,data);
            m_CAR02_DATA_RAW_HEAD++;
            if(m_CAR02_DATA_RAW_HEAD>=m_emfsData.car02.size())m_CAR02_DATA_RAW_HEAD = 0;
            if(m_CAR02_DATA_RAW_HEAD==m_CAR02_DATA_RAW_TAIL){
                if(m_CAR02_DATA_RAW_HEAD>0)m_CAR02_DATA_RAW_HEAD--;
                    else m_CAR02_DATA_RAW_HEAD = m_emfsData.car02.size()-1;
                    }
        break;
        case ESlave::CAR_ALL:
        break;
    }
}

void EDev_Mod1103::frameUpdate(EDev_Mod1103::ESlave slave)
{
    uint _index_force=0;
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        for(uint i=0;i<this->frame_Index(ESlave::CAR_01);i++){
            ECar data;
            data.index      = this->frame_Index(ESlave::CAR_01);
            data.s.value    = this->frame_S(ESlave::CAR_01,i);
            data.t.value    = this->frame_t(ESlave::CAR_01,i);
            if((i%3==0)&&_index_force<this->frame_Force_Index(ESlave::CAR_01)){
                m_car01_Force = this->frame_f(ESlave::CAR_01,_index_force++);
                }
            data.f.value    = m_car01_Force;
            data.pin.value  = this->frame_pin(ESlave::CAR_01);
            data.add = this->frame_add(ESlave::CAR_01);
            data.sc = this->frame_sc(ESlave::CAR_01);
            data.fc = this->frame_fc(ESlave::CAR_01);
            data.ts = this->frame_ts(ESlave::CAR_01);
            data.cs = this->frame_cs(ESlave::CAR_01);
            data.SPT = this->frame_SPT(ESlave::CAR_01);
            this->setDataRaw(ESlave::CAR_01,data);
        }
        break;
    case ESlave::CAR_02:
        //For CAR-02
        for(uint i=0;i<this->frame_Index(ESlave::CAR_02);i++){
            ECar data;
            data.index      = this->frame_Index(ESlave::CAR_02);
            data.s.value    = this->frame_S(ESlave::CAR_02,i);
            data.t.value    = this->frame_t(ESlave::CAR_02,i);
            if((i%3==0)&&_index_force<this->frame_Force_Index(ESlave::CAR_02)){
                m_car02_Force = this->frame_f(ESlave::CAR_02,_index_force++);
                }
            data.f.value    = m_car02_Force;
            data.pin.value  = this->frame_pin(ESlave::CAR_02);
            data.add = this->frame_add(ESlave::CAR_02);
            data.sc = this->frame_sc(ESlave::CAR_02);
            data.fc = this->frame_fc(ESlave::CAR_02);
            data.ts = this->frame_ts(ESlave::CAR_02);
            data.cs = this->frame_cs(ESlave::CAR_02);
            data.SPT = this->frame_SPT(ESlave::CAR_02);
            this->setDataRaw(ESlave::CAR_02,data);
        }
        break;
    case ESlave::CAR_ALL:
        break;
    }
}

void EDev_Mod1103::carDataUpdate(EDev_Mod1103::ESlave slave)
{
    double v=0,a=0,t=0;
    ECar data;
    data = getDataRawLast(slave,!m_updateLine);
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        t = this->dataCar_T(m_ecar01_Last.t.value,data.t.value);//convert to miniSecond
        m_car01_timeConnect = t;
        if(t<5)break;
        m_ecar01_Last.t.value = data.t.value;
        m_ecar_01.add = data.add;
        m_ecar_01.s.value = this->dataCar_S(this->checkVector(data.s.value,ESlave::CAR_01),m_ecar_01.s.unit,m_ecar_01.s.pre);
        m_ecar_01.t.value = this->dataCar_T(t,m_ecar_01.t.unit,m_ecar_01.t.pre);
        //calculate v
        v = this->dataCar_V(m_ecar01_Last.s.value,data.s.value,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Last.s.value = data.s.value;
        m_ecar_01.v.value = this->dataCar_V(this->checkVector(v,ESlave::CAR_01),m_ecar_01.v.unit,m_ecar_01.v.pre);
        //calculate a
        a = this->dataCar_A(m_ecar01_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Last.v.value = v;
        m_ecar_01.a.value = this->dataCar_A(this->checkVector(a,ESlave::CAR_01),m_ecar_01.a.unit,m_ecar_01.a.pre);
        m_ecar_01.f.value = this->dataCar_F(data.f.value,m_ecar_01.f.unit,m_ecar_01.f.pre);
        m_ecar_01.f.value = this->checkVector(m_ecar_01.f.value,ESlave::CAR_01);
        m_ecar_01.pin.value = this->dataCar_PIN(data.pin.value,m_ecar_01.pin.unit,m_ecar_01.pin.pre);
        m_ecar_01.ts = data.ts;
        m_ecar_01.cs = data.cs;
        m_ecar_01.sc = data.sc;
        m_ecar_01.fc = data.fc;
        m_ecar_01.SPT = data.SPT;
        m_ecar_01.index = data.index;
        break;
    case ESlave::CAR_02:
        t = this->dataCar_T(m_ecar02_Last.t.value,data.t.value);//convert to miniSecond
        m_car02_timeConnect = t;
        if(t<5)break;
        m_ecar02_Last.t.value = data.t.value;
        m_ecar_02.add = data.add;
        m_ecar_02.s.value = this->dataCar_S(this->checkVector(data.s.value,ESlave::CAR_02),m_ecar_02.s.unit,m_ecar_02.s.pre);
        m_ecar_02.t.value = this->dataCar_T(t,m_ecar_02.t.unit,m_ecar_02.t.pre);
        //calculate v
        v = this->dataCar_V(m_ecar02_Last.s.value,data.s.value,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Last.s.value = data.s.value;
        m_ecar_02.v.value = this->dataCar_V(this->checkVector(v,ESlave::CAR_02),m_ecar_02.v.unit,m_ecar_02.v.pre);
        //calculate a
        a = this->dataCar_A(m_ecar02_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Last.v.value = v;
        m_ecar_02.a.value = this->dataCar_A(this->checkVector(a,ESlave::CAR_02),m_ecar_02.a.unit,m_ecar_02.a.pre);
        m_ecar_02.f.value = this->dataCar_F(data.f.value,m_ecar_02.f.unit,m_ecar_02.f.pre);
        m_ecar_02.f.value = this->checkVector(m_ecar_02.f.value,ESlave::CAR_02);
        m_ecar_02.pin.value = this->dataCar_PIN(data.pin.value,m_ecar_02.pin.unit,m_ecar_02.pin.pre);
        m_ecar_02.ts = data.ts;
        m_ecar_02.cs = data.cs;
        m_ecar_02.sc = data.sc;
        m_ecar_02.fc = data.fc;
        m_ecar_02.SPT = data.SPT;
        m_ecar_02.index = data.index;
        break;
    case ESlave::CAR_ALL:
        break;
    }
}

void EDev_Mod1103::carLineUpdateContinous(EDev_Mod1103::ESlave slave)
{
    double v=0,a=0,t=0,s=0,s1=0,f=0;
    double  t1=0;
    ECar data = getDataRawLast(slave,true);
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        t1 = data.t.value;
        t = this->dataCar_T(m_ecar01_Line_Last.t.value,t1);
        m_ecar01_Line_Last.t.value = t1;
        if(t<5||t>1000)break;
        m_ecarLines_01.line_time += t;
        s = this->dataCar_S(data.s.value,m_ecar_01.s.unit,m_ecar_01.s.pre);
        m_ecarLines_01.line_s->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(s,ESlave::CAR_01));
        m_ecarLines_01.line_t->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_T(t,m_ecar_01.t.unit,m_ecar_01.t.pre));
        //calculate v
        s1 = data.s.value;
        v = this->dataCar_V(m_ecar01_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Line_Last.s.value = s1;
        m_ecarLines_01.line_v->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_01),m_ecar_01.v.unit,m_ecar_01.v.pre));
        //calculate a
        a = this->dataCar_A(m_ecar01_Line_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Line_Last.v.value = v;
        if(m_ecarLines_01.line_v->count()>1)m_ecarLines_01.line_a->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_A(this->checkVector(a,ESlave::CAR_01),m_ecar_01.a.unit,m_ecar_01.a.pre));
        //calculate f
        f = this->dataCar_F(data.f.value,m_ecar_01.f.unit,m_ecar_01.f.pre);
        m_ecarLines_01.line_f->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(f,ESlave::CAR_01));
        m_ecarLines_01.line_index++;
        break;
    case ESlave::CAR_02:
        //For CAR-02
        t1 = data.t.value;
        t = this->dataCar_T(m_ecar02_Line_Last.t.value,t1);
        m_ecar02_Line_Last.t.value = t1;
        if(t<5||t>1000)break;
        m_ecarLines_02.line_time += t;
        s = this->dataCar_S(data.s.value,m_ecar_02.s.unit,m_ecar_02.s.pre);
        m_ecarLines_02.line_s->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(s,ESlave::CAR_02));
        m_ecarLines_02.line_t->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_T(t,m_ecar_02.t.unit,m_ecar_02.t.pre));
        //calculate v
        s1 = data.s.value;
        v = this->dataCar_V(m_ecar02_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Line_Last.s.value = s1;
        m_ecarLines_02.line_v->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_02),m_ecar_02.v.unit,m_ecar_02.v.pre));
        //calculate a
        a = this->dataCar_A(m_ecar02_Line_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Line_Last.v.value = v;
        if(m_ecarLines_02.line_v->count()>1)m_ecarLines_02.line_a->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_A(this->checkVector(a,ESlave::CAR_02),m_ecar_02.a.unit,m_ecar_02.a.pre));
        //calculate f
        f = this->dataCar_F(data.f.value,m_ecar_02.f.unit,m_ecar_02.f.pre);
        m_ecarLines_02.line_f->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(f,ESlave::CAR_02));
        m_ecarLines_02.line_index++;
        break;
    case ESlave::CAR_ALL:
        break;
    }
}

void EDev_Mod1103::carSPlineUpdateContinous(ESlave slave)
{
    double v=0,a=0,t=0,s=0,s1=0,f=0;
    double  t1=0;
    ECar data = getDataRawLast(slave,true);
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        t1 = data.t.value;
        t = this->dataCar_T(m_ecar01_Line_Last.t.value,t1);
        m_ecar01_Line_Last.t.value = t1;
        if(t<5||t>1000)break;
        m_ecarSPlines_01.line_time += t;
        s = this->dataCar_S(data.s.value,m_ecar_01.s.unit,m_ecar_01.s.pre);
        m_ecarSPlines_01.line_s->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(s,ESlave::CAR_01));
        m_ecarSPlines_01.line_t->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_T(t,m_ecar_01.t.unit,m_ecar_01.t.pre));
        //calculate v
        s1 = data.s.value;
        v = this->dataCar_V(m_ecar01_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Line_Last.s.value = s1;
        m_ecarSPlines_01.line_v->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_01),m_ecar_01.v.unit,m_ecar_01.v.pre));
        //calculate a
        a = this->dataCar_A(m_ecar01_Line_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
        m_ecar01_Line_Last.v.value = v;
        if(m_ecarSPlines_01.line_v->count()>1)m_ecarSPlines_01.line_a->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_A(this->checkVector(a,ESlave::CAR_01),m_ecar_01.a.unit,m_ecar_01.a.pre));
        //calculate f
        f = this->dataCar_F(data.f.value,m_ecar_01.f.unit,m_ecar_01.f.pre);
        m_ecarSPlines_01.line_f->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(f,ESlave::CAR_01));
        m_ecarSPlines_01.line_index++;
        break;
    case ESlave::CAR_02:
        //For CAR-02
        t1 = data.t.value;
        t = this->dataCar_T(m_ecar02_Line_Last.t.value,t1);
        m_ecar02_Line_Last.t.value = t1;
        if(t<5||t>1000)break;
        m_ecarSPlines_02.line_time += t;
        s = this->dataCar_S(data.s.value,m_ecar_02.s.unit,m_ecar_02.s.pre);
        m_ecarSPlines_02.line_s->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(s,ESlave::CAR_02));
        m_ecarSPlines_02.line_t->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_T(t,m_ecar_02.t.unit,m_ecar_02.t.pre));
        //calculate v
        s1 = data.s.value;
        v = this->dataCar_V(m_ecar02_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Line_Last.s.value = s1;
        m_ecarSPlines_02.line_v->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_02),m_ecar_02.v.unit,m_ecar_02.v.pre));
        //calculate a
        a = this->dataCar_A(m_ecar02_Line_Last.v.value,v,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
        m_ecar02_Line_Last.v.value = v;
        if(m_ecarSPlines_02.line_v->count()>1)m_ecarSPlines_02.line_a->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_A(this->checkVector(a,ESlave::CAR_02),m_ecar_02.a.unit,m_ecar_02.a.pre));
        //calculate f
        f = this->dataCar_F(data.f.value,m_ecar_02.f.unit,m_ecar_02.f.pre);
        m_ecarSPlines_02.line_f->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(f,ESlave::CAR_02));
        m_ecarSPlines_02.line_index++;
        break;
    case ESlave::CAR_ALL:
        break;
    }
}





void EDev_Mod1103::carLineUpdateCondition(EDev_Mod1103::ESlave slave)
{
    double v=0,t=0,s=0,s1=0,f=0;
    double  t1=0;
    bool ok = false;
    ECar data;
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        for(int i=0;i<200;i++){
            data = this->getDataRaw(slave,&ok);
            if(!ok)return;
            t1 = data.t.value;
            t = this->dataCar_T(m_ecar01_Line_Last.t.value,t1);
            if(t<5)continue;
            m_ecar01_Line_Last.t.value = t1;
            if(t>100)continue;
            m_ecarLines_01.line_time = t1;
            //update s
            s = this->dataCar_S(data.s.value,m_ecar_01.s.unit,m_ecar_01.s.pre);
            m_ecarLines_01.line_s->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(s,ESlave::CAR_01));
            //update t
            m_ecarLines_01.line_t->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_T(t,m_ecar_01.t.unit,m_ecar_01.t.pre));
            //calculate v
            s1 = data.s.value;
            v = this->dataCar_V(m_ecar01_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
            m_ecarLines_01.line_v->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_01),m_ecar_01.v.unit,m_ecar_01.v.pre));
            m_ecar01_Line_Last.s.value=s1;
            //calculate a
            m_car01_AccelerationTime +=t;
            m_car01_SpeedSUM += v;
            m_car01_SpeedCNT++;
            if(m_car01_AccelerationTime>200)//100miliSecond
                {
                v = m_car01_SpeedSUM/QVariant(m_car01_SpeedCNT).toDouble();
                m_car01_Acceleration = this->dataCar_A(m_ecar01_Line_Last.v.value,v,this->dataCar_T(m_car01_AccelerationTime,TimeUnits::TMU_Second,m_ecar_01.t.pre));
                m_ecar01_Line_Last.v.value=v;
                m_car01_AccelerationTime=0;
                m_car01_SpeedSUM = 0;
                m_car01_SpeedCNT = 0;
                }
            if(m_ecarLines_01.line_v->count()>1)m_ecarLines_01.line_a->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_A(this->checkVector(m_car01_Acceleration,ESlave::CAR_01),m_ecar_01.a.unit,m_ecar_01.a.pre));
            //calculate f
            f = this->dataCar_F(data.f.value,m_ecar_01.f.unit,m_ecar_01.f.pre);
            m_ecarLines_01.line_f->append(this->dataCar_T(m_ecarLines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(f,ESlave::CAR_01));
            //update Index
            m_ecarLines_01.line_index++;
        }
        break;
    case ESlave::CAR_02:
        //For CAR-02
        for(int i=0;i<200;i++){
            data = this->getDataRaw(slave,&ok);
            if(!ok)return;
            t1 = data.t.value;
            t = this->dataCar_T(m_ecar02_Line_Last.t.value,t1);
            if(t<5)continue;
            m_ecar02_Line_Last.t.value = t1;
            if(t>100)continue;
            m_ecarLines_02.line_time = t1;
            //update s
            s = this->dataCar_S(data.s.value,m_ecar_02.s.unit,m_ecar_02.s.pre);
            m_ecarLines_02.line_s->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(s,ESlave::CAR_02));
            //update t
            m_ecarLines_02.line_t->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_T(t,m_ecar_02.t.unit,m_ecar_02.t.pre));
            //calculate v
            s1 = data.s.value;
            v = this->dataCar_V(m_ecar02_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
            m_ecarLines_02.line_v->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_02),m_ecar_02.v.unit,m_ecar_02.v.pre));
            m_ecar02_Line_Last.s.value=s1;
            //calculate a
            m_car02_AccelerationTime +=t;
            m_car02_SpeedSUM += v;
            m_car02_SpeedCNT++;
            if(m_car02_AccelerationTime>200)//100miliSecond
                {
                v = m_car02_SpeedSUM/QVariant(m_car02_SpeedCNT).toDouble();
                m_car02_Acceleration = this->dataCar_A(m_ecar02_Line_Last.v.value,v,this->dataCar_T(m_car02_AccelerationTime,TimeUnits::TMU_Second,m_ecar_02.t.pre));
                m_ecar02_Line_Last.v.value=v;
                m_car02_AccelerationTime=0;
                m_car02_SpeedSUM = 0;
                m_car02_SpeedCNT = 0;
                }
            if(m_ecarLines_02.line_v->count()>1)m_ecarLines_02.line_a->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_A(this->checkVector(m_car02_Acceleration,ESlave::CAR_02),m_ecar_02.a.unit,m_ecar_02.a.pre));
            //calculate f
            f = this->dataCar_F(data.f.value,m_ecar_02.f.unit,m_ecar_02.f.pre);
            m_ecarLines_02.line_f->append(this->dataCar_T(m_ecarLines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(f,ESlave::CAR_02));
            //update Index
            m_ecarLines_02.line_index++;
        }
        break;
    case ESlave::CAR_ALL:
        break;
    }
}

void EDev_Mod1103::carSPlineUpdateCondition(ESlave slave)
{
    double v=0,t=0,s=0,s1=0,f=0;
    double  t1=0;
    bool ok = false;
    ECar data;
    switch(slave){
    case ESlave::CAR_01:
        //For CAR-01
        for(int i=0;i<200;i++){
            data = this->getDataRaw(slave,&ok);
            if(!ok)return;
            t1 = data.t.value;
            t = this->dataCar_T(m_ecar01_Line_Last.t.value,t1);
            if(t<5)continue;
            m_ecar01_Line_Last.t.value = t1;
            if(t>100)continue;
            m_ecarSPlines_01.line_time = t1;
            //update s
            s = this->dataCar_S(data.s.value,m_ecar_01.s.unit,m_ecar_01.s.pre);
            m_ecarSPlines_01.line_s->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(s,ESlave::CAR_01));
            //update t
            m_ecarSPlines_01.line_t->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_T(t,m_ecar_01.t.unit,m_ecar_01.t.pre));
            //calculate v
            s1 = data.s.value;
            v = this->dataCar_V(m_ecar01_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_01.t.pre));
            m_ecarSPlines_01.line_v->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_01),m_ecar_01.v.unit,m_ecar_01.v.pre));
            m_ecar01_Line_Last.s.value=s1;
            //calculate a
            m_car01_AccelerationTime +=t;
            m_car01_SpeedSUM += v;
            m_car01_SpeedCNT++;
            if(m_car01_AccelerationTime>200)//100miliSecond
                {
                v = m_car01_SpeedSUM/QVariant(m_car01_SpeedCNT).toDouble();
                m_car01_Acceleration = this->dataCar_A(m_ecar01_Line_Last.v.value,v,this->dataCar_T(m_car01_AccelerationTime,TimeUnits::TMU_Second,m_ecar_01.t.pre));
                m_ecar01_Line_Last.v.value=v;
                m_car01_AccelerationTime=0;
                m_car01_SpeedSUM = 0;
                m_car01_SpeedCNT = 0;
                }
            if(m_ecarSPlines_01.line_v->count()>1)m_ecarSPlines_01.line_a->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->dataCar_A(this->checkVector(m_car01_Acceleration,ESlave::CAR_01),m_ecar_01.a.unit,m_ecar_01.a.pre));
            //calculate f
            f = this->dataCar_F(data.f.value,m_ecar_01.f.unit,m_ecar_01.f.pre);
            m_ecarSPlines_01.line_f->append(this->dataCar_T(m_ecarSPlines_01.line_time,TimeUnits::TMU_Second,m_ecar_01.t.pre),this->checkVector(f,ESlave::CAR_01));
            //update Index
            m_ecarSPlines_01.line_index++;
        }
        break;
    case ESlave::CAR_02:
        //For CAR-02
        for(int i=0;i<200;i++){
            data = this->getDataRaw(slave,&ok);
            if(!ok)return;
            t1 = data.t.value;
            t = this->dataCar_T(m_ecar02_Line_Last.t.value,t1);
            if(t<5)continue;
            m_ecar02_Line_Last.t.value = t1;
            if(t>100)continue;
            m_ecarSPlines_02.line_time = t1;
            //update s
            s = this->dataCar_S(data.s.value,m_ecar_02.s.unit,m_ecar_02.s.pre);
            m_ecarSPlines_02.line_s->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(s,ESlave::CAR_02));
            //update t
            m_ecarSPlines_02.line_t->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_T(t,m_ecar_02.t.unit,m_ecar_02.t.pre));
            //calculate v
            s1 = data.s.value;
            v = this->dataCar_V(m_ecar02_Line_Last.s.value,s1,this->dataCar_T(t,TimeUnits::TMU_Second,m_ecar_02.t.pre));
            m_ecarSPlines_02.line_v->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_V(this->checkVector(v,ESlave::CAR_02),m_ecar_02.v.unit,m_ecar_02.v.pre));
            m_ecar02_Line_Last.s.value=s1;
            //calculate a
            m_car02_AccelerationTime +=t;
            m_car02_SpeedSUM += v;
            m_car02_SpeedCNT++;
            if(m_car02_AccelerationTime>200)//100miliSecond
                {
                v = m_car02_SpeedSUM/QVariant(m_car02_SpeedCNT).toDouble();
                m_car02_Acceleration = this->dataCar_A(m_ecar02_Line_Last.v.value,v,this->dataCar_T(m_car02_AccelerationTime,TimeUnits::TMU_Second,m_ecar_02.t.pre));
                m_ecar02_Line_Last.v.value=v;
                m_car02_AccelerationTime=0;
                m_car02_SpeedSUM = 0;
                m_car02_SpeedCNT = 0;
                }
            if(m_ecarSPlines_02.line_v->count()>1)m_ecarSPlines_02.line_a->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->dataCar_A(this->checkVector(m_car02_Acceleration,ESlave::CAR_02),m_ecar_02.a.unit,m_ecar_02.a.pre));
            //calculate f
            f = this->dataCar_F(data.f.value,m_ecar_02.f.unit,m_ecar_02.f.pre);
            m_ecarSPlines_02.line_f->append(this->dataCar_T(m_ecarSPlines_02.line_time,TimeUnits::TMU_Second,m_ecar_02.t.pre),this->checkVector(f,ESlave::CAR_02));
            //update Index
            m_ecarSPlines_02.line_index++;
        }
        break;
    case ESlave::CAR_ALL:
        break;
    }
}







void EDev_Mod1103::carCheckConnect()
{
    if(this->frame_ts(ESlave::CAR_01)==0){m_ecar_01.connect=false;}
        else m_ecar_01.connect=true;
    if(this->frame_ts(ESlave::CAR_02)==0)m_ecar_02.connect=false;
        else m_ecar_02.connect=true;
}

void EDev_Mod1103::sensorUpdate()
{
//Update frame Car
    this->frameUpdate(ESlave::CAR_01);
    this->frameUpdate(ESlave::CAR_02);

//Update Display value
    this->carDataUpdate(ESlave::CAR_01);
    this->carDataUpdate(ESlave::CAR_02);


//Check CAR ON/OFF
    this->carCheckConnect();
    if(!m_updateLine){
        //Car01

        m_ecar01_Line_Last.t.value = m_ecar01_Last.t.value;
        m_ecar01_Line_Last.s.value = m_ecar01_Last.s.value;
        m_ecar01_Line_Last.v.value = m_ecar01_Last.v.value;
        m_ecarLines_01.line_time = 80;
        m_ecarSPlines_01.line_time = 80;
        m_car01_AccelerationTime=0;
        m_car01_SpeedSUM = 0;
        m_car01_SpeedCNT = 0;
        //Car02
        m_ecar02_Line_Last.t.value = m_ecar02_Last.t.value;
        m_ecar02_Line_Last.s.value = m_ecar02_Last.s.value;
        m_ecar02_Line_Last.v.value = m_ecar02_Last.v.value;
        m_ecarLines_02.line_time = 0;
        m_ecarSPlines_02.line_time = 0;
        m_car02_AccelerationTime=0;
        m_car02_SpeedSUM = 0;
        m_car02_SpeedCNT = 0;
        return;
    }
    //update Line
    if(m_CMD_carMode==CarMode::CMD_condition){
        if(m_typeLine==TypeLine::typeLine){
            if(m_ecar_01.connect)this->carLineUpdateCondition(ESlave::CAR_01);
            if(m_ecar_02.connect)this->carLineUpdateCondition(ESlave::CAR_02);
            }
            else{
                if(m_ecar_01.connect)this->carSPlineUpdateCondition(ESlave::CAR_01);
                if(m_ecar_02.connect)this->carSPlineUpdateCondition(ESlave::CAR_02);
                }
    }
    else{
        if(m_typeLine==TypeLine::typeLine){
             if(m_ecar_01.connect)this->carLineUpdateContinous(ESlave::CAR_01);
             if(m_ecar_02.connect)this->carLineUpdateContinous(ESlave::CAR_02);
            }
            else{
                if(m_ecar_01.connect)this->carSPlineUpdateContinous(ESlave::CAR_01);
                if(m_ecar_02.connect)this->carSPlineUpdateContinous(ESlave::CAR_02);
                }
         }

}


