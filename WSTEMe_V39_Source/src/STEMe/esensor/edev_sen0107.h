#ifndef EDEV_SEN0107_H
#define EDEV_SEN0107_H
#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0107 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0107();
        virtual ~EDev_Sen0107();
        enum SensorUnits{
            SSU_default,
            SSU_mg,
        };
        //properties=================================
        //Units
        inline SensorUnits sensorUnit(){return m_sensorUnit;}
        inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
        inline void setTemperature(double temp){m_temperature = temp;}
        QString sensorUnitText();
        //Functions========================================
        double temperature();
        double temperatureTable();
        void writeZero(QVector<quint16>  values);
    private:
        SensorUnits m_sensorUnit=SSU_default;
        double m_temperature=25;
        //Private Function
        //Single point calibration needs to be filled CAL1_V and CAL1_T
            #define DO_CAL1_V 1600 //mv
            #define DO_CAL1_T 25   //?
            //Two-point calibration needs to be filled CAL2_V and CAL2_T
            //CAL1 High temperature point, CAL2 Low temperature point
            #define DO_CAL2_V 1300 //mv
            #define DO_CAL2_T 15   //?
            const uint16_t DO_TABLE[41] = {
                14460, 14220, 13820, 13440, 13090, 12740, 12420, 12110, 11810, 11530,
                11260, 11010, 10770, 10530, 10300, 10080, 9860, 9660, 9460, 9270,
                9080, 8900, 8730, 8570, 8410, 8250, 8110, 7960, 7820, 7690,
                7560, 7430, 7300, 7180, 7070, 6950, 6840, 6730, 6630, 6530, 6410
                };

        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
};

#endif // EDEV_SEN0107_H
