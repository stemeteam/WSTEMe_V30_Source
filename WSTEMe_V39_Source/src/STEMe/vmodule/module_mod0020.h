#ifndef MODULE_MOD0020_H
#define MODULE_MOD0020_H


//system
#include <QWidget>
#include <QCloseEvent>
#include <QModbusDataUnit>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <vchart/vchart_zoom.h>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Module_MOD0020;
}

class Module_MOD0020 : public QWidget
{
    Q_OBJECT
    ////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................
        enum ConnectStatus{
            deviceDisconnected,
            deviceTestConnect,
            deviceReConnect,
            deviceTimeout,
            deviceConnected
        };
    public slots:
        void modbusRtuReply(VNetworkDataUnit unit);
    private slots:
        void on_modbusTimer();
    Q_SIGNALS:
        void modbusRtuRequest(VNetworkDataUnit unit);
    private:
        VNetworkDataUnit m_networkDataUnit;
        ConnectStatus m_modbusConnectStatus = Module_MOD0020::deviceDisconnected;

        QTimer *m_modbusTimer=nullptr; //communication ModbusRTUs
        quint16 m_modbusPollCount=0;
        quint16 m_modbusPollTimeout=5000;//minisecond

        quint16 m_modbusNumberOfRetries=0;
        quint16 m_modbusNumberOfRetriesMax=5;

        quint16 m_modbusSampleTime = 100; //time per sample
        quint16 m_modbusSampleTimeCount = 0;

        int m_modbusAddress=127;
        bool m_debug=false;

        void modbusSetAddress();
        void modbusRequestInputRegisters();
        void modbusReadResult(VNetworkDataUnit unit);
        void modbusWriteResult(VNetworkDataUnit unit);

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
    private slots:
        void on_displayTimer();


    private:
        QTimer  *m_displayTimer=nullptr;
        int     m_displayTimePoll = 100;
        bool    m_displayToggle=false;

        void displayPoll();

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
    private:
        QGridLayout     *m_chartGridLayout=nullptr;
        QChartView      *m_chartView=nullptr;
        QChart          *m_chart=nullptr;
        QValueAxis      *m_chartAxisX=nullptr;
        QValueAxis      *m_chartAxisY=nullptr;

        int m_axisX_TickCount = 11;
        int m_axisX_Range = 100;
        int m_axisY_TickCount = 11;
        int m_axisY_Range_Max = 2;
        int m_axisY_Range_Min = 0;

        int m_chartTimerInterval = 100;
        int m_chartTimerScan = 100;



        void chartInit();
        void chartInit(QPen _pen);
        void chartGraph(double val);
        void chartClear(bool init);

   /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

public:
    explicit Module_MOD0020(QWidget *parent = nullptr);
    ~Module_MOD0020();
        void setDeviceWidget(VDevice dev);

private slots:
    void deviceCalibration(double slope,double offset);
    void on_pushButton_2_clicked();
    void on_pushButton_Calib_clicked();

    void on_pushButton_Next_clicked();

    void on_pushButton_Previous_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Stop_clicked();

    void on_comboBox_SelectSample_currentIndexChanged(int index);

    void on_pushButton_ClearChart_clicked();

    void on_pushButton_SetConfigChart_clicked();


    void on_radioButton_Accumulation_toggled(bool checked);

    void on_pushButton_SetSampleTime_2_clicked();

    void on_spinBox_SampleTime_2_valueChanged(int arg1);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Module_MOD0020 *ui;
    quint32 m_system_count=0;
    bool    m_deviceModbusConnect=false;
    VDevice m_deviceInformation;
    enum DeviceREG_Tables{
        dREG_START          = 0x05,
        dREG_NUMBER         = 0x02,
        dREG_ID				= 0x00,//ID = 0x00,0x01,0x02 of 16-bit reg
        dREG_ADDRESS 		= 0x03,
        dREG_BAUDRATE 		= 0x04,

        //line y = ax + b
        //with y = PH_CALIB
        //with x = PH_VALUE
        //with a = PH_SLOPE
        //with b = PH_OFFSET
        dREG_TEST_ADC		= 0x05, //ADC 16-bit MSB
        dREG_TEST_VALUE 	= 0x06, //Weight value
        dREG_TEST_CALIB		= 0x07,	//Weight value calib
        dREG_TEST_SLOPE		= 0x08,
        dREG_TEST_OFFSET		= 0x09,
        dREG_ADC_ZERO_HI		= 0x0A,
        dREG_ADC_ZERO_LO		= 0x0B,
        dREG_MOTOR_CONTROL		= 0x0C
    };


    //Example for units of physical
    enum Sample_Type{
        sampleAuto,
        sampleWhenNext,
        sampleThreeStep
    };
    enum Motor_Status{
        motorBack,
        motorStop,
        motorNext
    };

    struct Force_Control{
        qreal   fc_Sum=0;
        qreal   fc_Max=-0xFFFFFFFF;
        qreal   fc_Min=0xFFFFFFFF;
        qreal   fc_Mean=0;
        qreal   fc_time=0;
        qreal   fc_velocity=0;
        qreal   fc_distance=0;
        QSplineSeries *fc_chart=nullptr;
        int fc_chartStep=0;
    };

    struct Force_Sample{
        VDevice fs_device;
        int          fs_Control_Index=0;
        QVector<qreal>  fs_chartArray[3];
        Force_Control   fs_Control[3];
        int     fs_sampleTime=0;
        Sample_Type fs_sampleType = Sample_Type::sampleAuto;
        Motor_Status fs_motorStatus = Motor_Status::motorStop;

    };

    QModbusDataUnit     m_deviceUnit;
    QVector<quint16>    m_ADC_Offset;
    QVector<quint16>    m_MotorControl;
    quint16             m_Weight_Value_Calib=0;

    quint8 scripChartLine=1;

    Force_Sample *m_force_Sample=nullptr;

    quint16 macroEncodeREG(double reg,bool *ok);
    double  macroDecriptionREG(quint16 reg);

    //Control motor
    int m_sample_Index=0;
    quint16 VL9110_MOTOR_SPEED=0;
    quint16 VL9110_MOTOR_CTRL=0;
    quint16 VL9110_MOTOR_STATUS=0;
    void motorControl();
    void motorGetStatus(double val);
};


#endif // MODULE_MOD0020_H
