#include "efrequency.h"

EFrequency::EFrequency()
{

}

EFrequency::EWaveParameter EFrequency::getWaveParameter(QVector<QPointF> wave, double threshold, int delta)
{
    EWaveParameter _para;
    for(int i=0;i<wave.count();i++){
        _para = this->getWaveParameter(wave.at(i),threshold,delta);
        if(_para.status==true){
            qDebug()<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
            qDebug()<<"Freq:"<<_para.frequency<<"   Period:"<<_para.period<<"   Ton:"<<_para.timeON<<"   Toff:"<<_para.timeOFF;
        }
    }
    return _para;
}

double EFrequency::getElapsed(double time)
{
    double _elp = time-m_waveTimeLast;
    m_waveTimeLast = time;
    return _elp;
}

bool EFrequency::getWaveDir(double vol_new, double vol_zero, int delta)
{
    bool _dir=false;
    if(vol_new>vol_zero){
        if(m_waveDelta++>delta){
            m_waveDelta=0;
            _dir=true;
            }
        }
    else {
        if(m_waveDelta++>delta){
            m_waveDelta=0;
            _dir=false;
            }
        }
    return _dir;
}

void EFrequency::getWaveTime(QPointF p, double t_on, double t_off)
{

}

EFrequency::EWaveParameter EFrequency::getWaveParameter(QPointF voltage, double threshold, int delta)
{
    switch(m_ewaveFormStatus){
    case WFS_head:
        if(voltage.y()>=threshold){
            m_ewaveParameter.status=false;
            m_waveTimeON += this->getElapsed(voltage.x());
            m_ewaveParameter.delta++;
            if(m_ewaveParameter.delta>delta){
                m_ewaveParameter.delta=0;
                m_ewaveFormStatus=WFS_middle;
                }
            }
        else {
            m_waveTimeON=0;
            m_waveTimeOFF=0;
            m_ewaveParameter.frequency=0;
            m_ewaveParameter.period=0;
            m_ewaveParameter.delta=0;
            this->getElapsed(voltage.x());
        }
        break;
    case WFS_middle:
        if(voltage.y()>threshold)m_waveTimeON += this->getElapsed(voltage.x());
        else {
            m_waveTimeOFF += this->getElapsed(voltage.x());
            m_ewaveParameter.delta++;
            if(m_ewaveParameter.delta>delta){
                m_ewaveParameter.delta=0;
                m_ewaveFormStatus=WFS_foot;
                }
            }
        break;
    case WFS_foot:
        if(voltage.y()<threshold)m_waveTimeOFF += this->getElapsed(voltage.x());
        else {
            m_ewaveParameter.period = m_waveTimeON+m_waveTimeOFF;
            m_ewaveParameter.frequency = 1/m_ewaveParameter.period;
            m_ewaveParameter.timeON = m_waveTimeON;
            m_ewaveParameter.timeOFF = m_waveTimeOFF;
            m_waveTimeON=0;
            m_waveTimeOFF=0;
            m_ewaveParameter.status=true;
            m_waveTimeON += this->getElapsed(voltage.x());
            m_ewaveParameter.delta++;
            if(m_ewaveParameter.delta>delta){
                m_ewaveParameter.delta=0;
                m_ewaveFormStatus=WFS_middle;
                }
                else m_ewaveFormStatus=WFS_head;
            }
        break;
    }
    qDebug()<<"x:"<<voltage.x()<<"- y:"<<voltage.y()<<"- z:"<<threshold<<"- d:"<<delta<<"- s:"<<m_ewaveFormStatus;
    return m_ewaveParameter;
}
