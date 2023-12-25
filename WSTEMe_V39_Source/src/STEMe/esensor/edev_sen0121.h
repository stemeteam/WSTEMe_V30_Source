#ifndef EDEV_SEN0121_H
#define EDEV_SEN0121_H

#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>
#include <echart/echartlines.h>


class EDev_Sen0121 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Basics///////////////////////////
    public:
        EDev_Sen0121();
        virtual ~EDev_Sen0121();
        enum SensorUnits{
            SSU_default,
            SSU_milliMeter,             //For WHL0103
            SSU_centiMeter,
            SSU_deciMeter,
            SSU_Meter
        };

        enum DeviceREG_Tables{
            dREG_ID				= 0x00,//ID = 0x00,0x01,0x02 of 16-bit reg
            dREG_ADDRESS 		= 0x03,
            dREG_BAUDRATE 		= 0x04,

            /*Temperature compensation for module
            use regs 16 bit with:
            |D15|D14|D13|D12|D11...D0|
            + D15: sign of data, 1 is '-', 0 is '+'
            + D14-D12: resolution, B = pow(10,D14-D12)
            + D11...D0: Data
            Temp = (D15)*(D11...D0)/(B)
            */
            dREG_TEMP_VALUE		= 0x05,
            dREG_TEMP_CALX1		= 0x06,
            dREG_TEMP_CALY1		= 0x07,
            dREG_TEMP_CALX2		= 0x08,
            dREG_TEMP_CALY2		= 0x09,

            //REG from 0x0A to 0x0F use for each sensor
            dREG_MODE_CONTROL		= 0x0A,	//0x00: Set Long Measurement Mode
                                            //0x01: Set Fast Measurement Mode
                                            //0x02: Set Frecision Measurement Mode
                                            //0x03: Set General Measurement Mode


            dREG_SEN01_ZERO 		= 0x0B,//0x0C

            //...............................................
            /*Data of measurement............................
            use regs 32 bit with:
            |D31|D30|D29|D28|D27...D0|
            + D31: sign of data, 1 is '-', 0 is '+'
            + D30-D28: resolution, B = pow(10,D30-D28)
            + D27...D0: Data = (D15)*(D11...D0)/(B)
            Value = D31*(D27...D0)/(B)*/

            dREG_SEN01_ADC			= 0x10,//0x11
            dREG_SEN01_VALUE		= 0x12,//0x13
            dREG_SEN01_CALX1		= 0x14,//0x15
            dREG_SEN01_CALY1		= 0x16,//0x17
            dREG_SEN01_CALX2		= 0x18,//0x19
            dREG_SEN01_CALY2		= 0x1A,//0x1B
            dREG_SEN01_CALX3		= 0x1C,//0x1D
            dREG_SEN01_CALY3		= 0x1E,//0x1F

            dREG_SEN01_INDEX		= 0x20,
            dREG_SEN01_BUFF 		= 0x21,//,0x21->0x35
            dREG_SEN01_TIME			= 0x36//0x36->0x4B
        };
        struct EData
        {
            double value=0;
            double time=0;
        };
        //properties=================================
        inline QSplineSeries* sensorBuff(){return m_lineBuff;}
        //Units
        inline SensorUnits sensorUnit(){return m_sensorUnit;}
        inline void setSensorUnit(SensorUnits unit){m_sensorUnit = unit;}
        QString sensorUnitText();

        //////////////////////////////////////////
        void setMode(quint16 value);
        void setZero(QVector<quint16>  values);
        EData getDataPoll(bool *ok){return this->getDataRaw(ok);}
        void clearDataPoll(){this->clearDataRaw();}
    private:
        SensorUnits m_sensorUnit=SSU_default;

        QSplineSeries *m_lineBuff = new QSplineSeries();
        double m_time_last = 0;
        //for set/get DataRaw
        QVector<EData> m_dataRaw;
        int  DATA_RAW_MAXSIZE = 200;
        int m_DATA_RAW_HEAD = 0,m_DATA_RAW_TAIL = 0;

        //Private Function
        double sensorConvertUnits(double value);
        void calculatorValue();
        void calculatorValueCalib();
        EData getDataRaw(bool *ok);
        void setDataRaw(EData data);
        void clearDataRaw();
        void updateDataPoll();
        void getValueBuff();
};

#endif // EDEV_SEN0121_H
