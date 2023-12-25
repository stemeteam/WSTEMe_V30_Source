#ifndef EFREQUENCY_H
#define EFREQUENCY_H
#include <QPointF>
#include <QDebug>

class EFrequency
{
public:
    EFrequency();
    EFrequency(double vol){m_waveZeroVoltage = vol;}

    struct EWaveParameter{
        double frequency=0;
        double timeON=0;
        double timeOFF=0;
        double period=0;
        int delta=0;
        bool status=false;
    }m_ewaveParameter;

    inline void setZeroVoltage(double vol){m_waveZeroVoltage = vol;}
    inline void setDelta(double del){m_waveDelta = del;}


    EWaveParameter getWaveParameter(QVector<QPointF> wave,double threshold,int delta);
private:
    enum EWaveFormStatus{
        WFS_head,
        WFS_middle,
        WFS_foot
    }m_ewaveFormStatus = WFS_head;



    bool m_waveDir = false;
    double m_waveDelta = 0;
    double m_waveZeroVoltage = 0;
    double m_waveTimeON = 0;
    double m_waveTimeOFF = 0;
    double m_waveTimeLast = 0;

    double getElapsed(double time);
    bool getWaveDir(double vol_new,double vol_zero,int delta);
    void getWaveTime(QPointF p, double t_on,double t_off);
    EWaveParameter getWaveParameter(QPointF voltage,double threshold,int delta);
};

#endif // EFREQUENCY_H
