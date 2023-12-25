#ifndef EDEV_SEN0150_H
#define EDEV_SEN0150_H

#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0150 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0150();
        virtual ~EDev_Sen0150();
        enum SensorUnits{
            SSU_default,
            SSU_volt,
            SSU_milliVolt
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


#endif // EDEV_SEN0150_H
