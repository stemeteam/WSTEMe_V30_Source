#ifndef EDEV_SEN0103_H
#define EDEV_SEN0103_H
#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>


class EDev_Sen0103 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0103();
        virtual ~EDev_Sen0103();
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
        double temperatureValue();
        void writeZero(QVector<quint16>  values);
    private:
        SensorUnits m_sensorUnit=SSU_default;
        //Private Function
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
};

#endif // EDEV_SEN0103_H
