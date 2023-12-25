#ifndef EDEV_SE0105_H
#define EDEV_SE0105_H

#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>

class EDev_Sen0105 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0105();
        virtual ~EDev_Sen0105();

        enum DeviceREG_Tables{
           // dREG_MAX            = 0x7D,
            dREG_MAX            = 0x3B,
            dREG_ID				= 0x00,//ID = 0x00,0x01,0x02 of 16-bit reg
            dREG_ADDRESS 		= 0x03,
            dREG_BAUDRATE 		= 0x04,
            //REG from 0x0A to 0x0F use for each sensor
            dREG_SOUND_CONTROL	= 0x05,
            //LBS: 00:OFF, 01: SIN Wave, 02: SQUARE Wave, 03: TRIANGLE
            dREG_SOUND_FREQ		= 0x06,
            dREG_SOUND_TIME		= 0x07,
        //
            dREG_SOUND_INDEX	= 0x08,//0x11
            dREG_SOUND_VALUE	= 0x09
        };


        enum SensorUnits{
            SSU_default,
            SSU_soundSPL,             //For WHL0103
            SSU_soundDecibel,
            SSU_soundVolt
        };

        double  m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        double  m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        double  m_GET_SAMPLE_SUM = 0;
        int     m_GET_SAMPLE_COUNT = 0;
        //properties=================================
        //Units

        inline double max(){return m_GET_SAMPLE_MAX;}
        inline double min(){return m_GET_SAMPLE_MIN;}
        inline double avg(){return m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT;}
        inline double samples(){return m_dataIndex;}
        inline SensorUnits sensorUnit(){return m_sensorUnit;}
        inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
        inline bool isUpdateData(){return m_updateData;}
        QString sensorUnitText();
        //Functions========================================
        QVector<QPointF> valueSound();
        int valueSoundAppend(QSplineSeries* lines,double freq,bool flag);
        void setFrequency(QVector<quint16> values);
        double frequency();
        double voltage();
    private:
        SensorUnits m_sensorUnit=SSU_default;
        double m_dataIndex=0;
        bool m_convertData=false;
        double m_voltageSUM = 0;
        int m_voltageCNT = 0;
        double m_timeSUM = 0;
        bool m_updateData = false;
        //Private Function
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
        double getVoltage(int vol);
        double getTime(int time);
};
#endif // EDEV_SE0105_H
