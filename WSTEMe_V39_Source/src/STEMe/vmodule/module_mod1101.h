#ifndef MODULE_MOD1101_H
#define MODULE_MOD1101_H


//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>
#include <QBuffer>

//user
//#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/edev_mod1101.h>
#include <vlogin/vuser.h>
#include <vroot/vdevicecalibration.h>
#include <vfile/vfile.h>

//chart
#include <esensor/echarts.h>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>


namespace Ui {
class Module_MOD1101;
}

class Module_MOD1101 : public QWidget
{
    Q_OBJECT

        /////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...
public:
        void setDeviceWidget(VDevice dev,VUser user);
        void sensorCalibration(double valueCalib,double valueRaw);
        void setInfoCalib();

private:
        enum SensorWriteStatus {
            SWS_default=0,
            SWS_SetZero,
            SWS_Calib
        }m_SWS_Status = SWS_default;

        bool    m_GET_SAMPLE_STATUS = false;
        double  m_GET_SAMPLE_SUM = 0;
        double  m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        double  m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        int     m_GET_SAMPLE_COUNT = 0;
        QVector<double> m_VALUE_AVG;


        int m_modbusSampleTime = 100;
     //   ESensors *m_esensor=nullptr;
        EDev_Mod1101 *m_edev_mod1101=nullptr;

        VDevice m_deviceInformation;
        QMessageBox *m_QMessageBox = nullptr;
        VDeviceCalibration *m_deviceCalibration = nullptr;

        void sensorWriteReport(bool status);
        void sensorWriteMultipleREG(quint16 address,QVector<quint16> values);
        void sensorWriteSingleREG(quint16 reg, quint16 value);

        void calculateParametes(double value, int resolution);
    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
    private slots:
        void on_displayTimer();

    private:
        QTimer  *m_displayTimer=nullptr;
        bool    m_displayToggle=false;
        int     m_displayInterval = 1;


        void displayPoll();

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
    private:
        ECharts *m_echart = nullptr;
        int m_axisX_TickCount = 11;
        qreal m_axisX_Range = 100;
        int m_axisY_TickCount = 11;
        qreal m_axisY_Range_Max = 2;
        qreal m_axisY_Range_Min = 0;

        int m_chartTimerInterval = 100;
      //  int m_chartTimerScan = 100;

        qreal m_forceValue =0;
        qreal m_axtX_Index = 0;

        void chartInit();
        void chartGraph(double val);
        void chartClear();
        void setTrackLine(EChartGesture::ETrackLine track);


   /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

public:
    explicit Module_MOD1101(QWidget *parent = nullptr);
    ~Module_MOD1101();


private slots:


    void on_pushButton_SetSampleTime_clicked();

    void on_pushButton_Next_clicked();

    void on_pushButton_Previous_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Stop_clicked();

    void on_comboBox_SelectSample_currentIndexChanged(int index);

    void on_pushButton_ClearChart_clicked();

    void on_pushButton_SetConfigChart_clicked();

    void on_spinBox_SampleTime_valueChanged(int arg1);

    void on_radioButton_Accumulation_toggled(bool checked);

    void on_pushButton_SaveData_clicked();

    void on_pushButton_OpenData_clicked();

    void on_pushButton_SetZero_clicked();

    void on_pushButton_Calib_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBox_Unit_currentIndexChanged(int index);


    void on_pushButton_getSamples_clicked();

    void on_spinBox_Display_Car_Pre_F1_valueChanged(int arg1);

    void on_pushButton_TrackLine_Default_clicked();

    void on_pushButton_TrackLine_Tooltip_clicked();

    void on_pushButton_TrackLine_Yax_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Module_MOD1101 *ui;
    quint32 m_system_count=0;
    bool    m_deviceModbusConnect=false;
    VUser m_user;

    void setOpenFile(bool status);
    bool    m_isOpenFile = false;


    //Example for units of physical
    enum Sample_Type{
        sampleAuto,
        sampleWhenNext,
        sampleThreeStep
    };
    enum Motor_Status{
        motorDisconnect,
        motorBack,
        motorStop,
        motorNext
    };
    Sample_Type m_sampleType = Sample_Type::sampleAuto;
    Motor_Status m_motorStatus = Motor_Status::motorDisconnect;

    //Control motor
    quint16 VL9110_MOTOR_SPEED=100;
    quint16 VL9110_MOTOR_CTRL=0;
    quint16 VL9110_MOTOR_STATUS=0;
    void motorControl();
    void motorGetStatus();
};


#endif // MODULE_MOD1101_H
