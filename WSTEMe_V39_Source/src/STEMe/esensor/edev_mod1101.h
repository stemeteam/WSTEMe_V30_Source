#ifndef EDEV_MOD1101_H
#define EDEV_MOD1101_H
//#include<QObject>
#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>


class EDev_Mod1101 : public ESensor_Base
{
//////////////////////////////////////////////////////////////////////////Basics///////////////////////////
public:
    EDev_Mod1101();
    virtual ~EDev_Mod1101();
    enum SensorUnits{
        SSU_default,
        SSU_scaleWeight,             //For WHL0103
        SSU_scaleGram,
        SSU_scaleKiloGram,
        SSU_scaleForce,
    };
    //properties=================================
    //Units
    inline SensorUnits sensorUnit(){return m_sensorUnit;}
    inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
    QString sensorUnitText();
    //Functions========================================
    void writeMotor(quint16 value);
    void writeZero(QVector<quint16>  values);
private:
    SensorUnits m_sensorUnit=SSU_default;
    quint32 m_REG_MOTOR_CONTROL = 0;
    //Private Function
    double sensorConvertUnits(double value);
    void calculatorValue();
    void calculatorValueCalib();


//////////////////////////////////////////////////////////////////////////Charts///////////////////////////
public:
    QPointF getChartPositionMouse(){return m_echartParameter->getPositionMouse();}
    //Chart for Parameter
    void chartInit(QWidget *widget);
    void graph(double val);
    void chartClear();
    void setTrackLine(EChartGesture::ETrackLine track);
private:
    ECharts *m_echartParameter = nullptr;
    QWidget *m_chartWidget=nullptr;
    int m_axisX_TickCount = 11;
    qreal m_axisX_Range = 100;
    int m_axisY_TickCount = 11;
    qreal m_axisY_Range_Max = 2;
    qreal m_axisY_Range_Min = 0;
    int m_chartTimerInterval = 100;
    int m_chartTimerScan = 100;



};



#endif // EDEV_MOD1101_H
