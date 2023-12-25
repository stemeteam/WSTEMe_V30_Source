#ifndef EDEV_SEN0110_H
#define EDEV_SEN0110_H
#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0110 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0110();
        virtual ~EDev_Sen0110();
        enum SensorUnits{
            SSU_default,
            SSU_ppm,
            SSU_mg
        };
        //properties=================================
        //Units
        inline SensorUnits sensorUnit(){return m_sensorUnit;}
        inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
        QString sensorUnitText();
        //Functions========================================
        double temperatureValue();
    private:
        SensorUnits m_sensorUnit=SSU_default;
        //Private Function
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
};

#endif // EDEV_SEN0110_H
