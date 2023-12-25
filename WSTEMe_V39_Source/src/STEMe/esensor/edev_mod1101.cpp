#include "edev_mod1101.h"

EDev_Mod1101::EDev_Mod1101()
{
//this->setMaxREG(0x28);
}

EDev_Mod1101::~EDev_Mod1101()
{

}
QString EDev_Mod1101::sensorUnitText()
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


void EDev_Mod1101::writeMotor(quint16 value)
{
    writeSingleREG(ESensor_Base::dREG_MOTOR_CONTROL,value);
}

void EDev_Mod1101::writeZero(QVector<quint16> values)
{
    writeMultipleREG(ESensor_Base::dREG_SEN01_ZERO,values);
}


double EDev_Mod1101::sensorConvertUnits(double value)
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

void EDev_Mod1101::calculatorValue()
{
    //Units convert
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValue(this->sensorConvertUnits(VDevice::decryption(this->REG_sen01_VALUE())));
}

void EDev_Mod1101::calculatorValueCalib()
{
    double val = this->value();
   // if(val<0)val*=-1;
    this->setResolution(QVariant(VDevice::resolution(this->REG_sen01_VALUE())).toInt());
    this->setValueCalib(VDevice::calib(val,this->REG_sen01_CALX1(),this->REG_sen01_CALY1(),\
                                       this->REG_sen01_CALX2(),this->REG_sen01_CALY2(),this->REG_sen01_CALX3(),this->REG_sen01_CALY3()));
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////CHARTS//////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EDev_Mod1101::chartInit(QWidget *widget)
{
    if(m_echartParameter)delete m_echartParameter;
    m_echartParameter = new ECharts();
    ECharts::Parameter parameter;
    parameter.timerScan = m_chartTimerScan;
    parameter.axisX_Range_Max = m_axisX_Range;
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echartParameter->init(parameter,3,widget);
    m_echartParameter->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_chartTimerScan).toDouble()))).toInt());//Scan in 1 hour

}

void EDev_Mod1101::graph(double val)
{
    m_echartParameter->graph(val);
}

void EDev_Mod1101::chartClear()
{
    m_echartParameter->clear();
    m_echartParameter->setLinesIndex(1);
}

void EDev_Mod1101::setTrackLine(EChartGesture::ETrackLine track)
{
if(m_echartParameter)m_echartParameter->setTrackLine(track);
}










