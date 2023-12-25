#ifndef EDEV_SEN0104_H
#define EDEV_SEN0104_H

#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0104 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0104();
        virtual ~EDev_Sen0104();
        enum SensorUnits{
            SSU_default,
            SSU_pressurePa,   //For ATH0102
            SSU_pressureHPa,
            SSU_pressureKPa,
            SSU_pressureAtm,
            SSU_pressureBar,
            SSU_pressureBaria,
            SSU_pressureTorr
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
        double calculatorPresure(quint32 value);
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
};
#endif // EDEV_SEN0104_H
