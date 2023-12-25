#ifndef EDEV_SEN0151_H
#define EDEV_SEN0151_H


#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0151 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0151();
        virtual ~EDev_Sen0151();
        enum SensorUnits{
            SSU_default,
            SSU_amp,
            SSU_milliAmp
        };
        //properties=================================
        //Units
        inline SensorUnits sensorUnit(){return m_sensorUnit;}
        inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
        QString sensorUnitText();
        //Functions========================================
        void writeZero(QVector<quint16>  values);
    private:
        SensorUnits m_sensorUnit=SSU_default;
        //Private Function
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
};


#endif // EDEV_SEN0151_H
