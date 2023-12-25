#ifndef MODULE_MOD1102_H
#define MODULE_MOD1102_H

//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>
#include <QFile>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/edev_mod1101.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <esensor/echarts.h>
#include <vroot/vdevicecalibration.h>
#include <vfile/vfile.h>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Module_MOD1102;
}

class Module_MOD1102 : public QWidget
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
        EDev_Mod1101 *m_edev_mod1101=nullptr;

        VDevice m_deviceInformation;
        QMessageBox *m_QMessageBox = nullptr;
        VDeviceCalibration *m_deviceCalibration = nullptr;

        void sensorWriteReport(bool status);

        void calculateParametes(double value, int resolution);
    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
    private slots:
        void on_displayTimer();


    private:
        QTimer  *m_displayTimer=nullptr;
        bool    m_displayToggle=false;
        int     m_displayInterval = 10;

        void displayPoll();

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
    private:
        ECharts *m_echart = nullptr;


        int m_axisX_TickCount = 11;
        int m_axisX_Range = 100;
        int m_axisY_TickCount = 11;
        int m_axisY_Range_Max = 2;
        int m_axisY_Range_Min = 0;

        int m_chartTimerInterval = 100;
        int m_chartTimerScan = 100;

        qreal m_axtX_Index = 0;

        void chartInit();
        void chartGraph(double val);
        void chartClear();
        void setTrackLine(EChartGesture::ETrackLine track);


   /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

public:
    explicit Module_MOD1102(QWidget *parent = nullptr);
    ~Module_MOD1102();

private slots:
    void on_pushButton_Calib_clicked();

    void on_pushButton_SetSampleTime_clicked();

    void on_pushButton_Next_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Stop_clicked();

    void on_comboBox_SelectSample_currentIndexChanged(int index);

    void on_pushButton_ClearChart_clicked();

    void on_pushButton_SetConfigChart_clicked();

    void on_spinBox_SampleTime_valueChanged(int arg1);

    void on_radioButton_Accumulation_toggled(bool checked);

    void on_pushButton_SaveData_clicked();

    void on_pushButton_OpenData_clicked();

    void on_pushButton_setZero_clicked();

    void on_comboBox_Unit_currentIndexChanged(int index);

    void on_pushButton_TrackLine_Default_clicked();

    void on_pushButton_TrackLine_Tooltip_clicked();

    void on_pushButton_TrackLine_Yax_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Module_MOD1102 *ui;

    //Example for units of physical
    enum SampleType{
        sampleAuto,
        sampleWhenNext,
        sampleThreeStep
    };
    enum MotorStatus{
        motorBack,
        motorStop,
        motorNext
    };
    SampleType m_sampleType = sampleAuto;
    MotorStatus m_motorStatus = motorStop;

    QModbusDataUnit     m_deviceUnit;
    QVector<quint16>    m_ADC_Offset;
    QVector<quint16>    m_MotorControl;
    quint16             m_Weight_Value_Calib=0;

    quint8 scripChartLine=1;
    quint32 m_system_count=0;
    bool    m_deviceModbusConnect=false;
    bool    m_isOpenFile = false;
    VUser m_user;
    //File
    void setOpenFile(bool status);
    void motorGetStatus();
};


#endif // MODULE_MOD1101_H
