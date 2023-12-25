#ifndef SENSOR_SEN0121_H
#define SENSOR_SEN0121_H

//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>

//user
#include <vdevice/vdevice.h>
#include <esensor/edev_sen0121.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <vroot/vdevicecalibration.h>
#include <echart/echartlines.h>


namespace Ui {
class Sensor_SEN0121;
}

class Sensor_SEN0121 : public QWidget
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
            SWS_SetMode,
            SWS_Calib
        }m_SWS_Status = SWS_default;


        bool    m_GET_SAMPLE_STATUS = false;
        double  m_GET_SAMPLE_SUM = 0;
        double  m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        double  m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        int     m_GET_SAMPLE_COUNT = 0;

        QVector<double> m_VALUE_AVG;

        int m_modbusSampleTime = 200;
        EDev_Sen0121 *m_edev_sen0121=nullptr;

        VDevice m_deviceInformation;
        QMessageBox *m_QMessageBox = nullptr;
        VDeviceCalibration *m_deviceCalibration = nullptr;

        void sensorWriteReport(bool status);
        void calculateParametes(double value,int resolution);

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
    private slots:
        void on_displayTimer();


    private:
        QTimer  *m_displayTimer=nullptr;
        bool    m_displayToggle=false;
        int     m_displayInterval = 10;

        void displayPoll();

    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
    private slots:
        void on_chartUpdate();
    private:
        ECharts *m_echart = nullptr;
        QTimer  *m_chartTimer=nullptr;

        int     m_chartInterval = 10;

        int m_axisX_TickCount = 11;
        qreal m_axisX_Range = 10;
        int m_axisY_TickCount = 11;
        qreal m_axisY_Range_Max = 2;
        qreal m_axisY_Range_Min = 0;

        int m_chartTimerInterval = 100;
      //  int m_chartTimerScan = 100;

        qreal m_forceValue =0;
        qreal m_axtX_Index = 0;

        void chartInit();
        void chartGraph(double val);
        void chartGraph(QPointF val);
        void chartClear();
        void setTrackLine(EChartGesture::ETrackLine track);
    /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
public:
    explicit Sensor_SEN0121(QWidget *parent = nullptr);
    ~Sensor_SEN0121();

private slots:
    void on_setChartParameter(int sampleTime);

    void on_spinBox_SampleTime_valueChanged(int arg1);

    void on_pushButton_SetSampleTime_clicked();

    void on_pushButton_Calib_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_getSamples_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_SetZero_clicked();

    void on_comboBox_Sensor_Unit_currentIndexChanged(int index);

    void on_pushButton_SetMode_clicked();

    void on_radioButton_Accumulation_toggled(bool checked);

    void on_pushButton_ClearChart_clicked();

    void on_pushButton_TrackLine_Default_clicked();

    void on_pushButton_TrackLine_Tooltip_clicked();

    void on_pushButton_TrackLine_Yax_clicked();

    void on_comboBox_Sensor_Mode_currentIndexChanged(int index);

    void on_spinBox_graphTime_valueChanged(int arg1);

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::Sensor_SEN0121 *ui;

    struct FreqData{
        int pulse=0;
        double freq=0;
        double time=0;
    };

    void setOpenFile(bool status);
    bool    m_isOpenFile = false;

    quint32 m_system_count=0;
    double m_sensor_Value=0;
    double m_time_Line=0;
    bool m_stop_start = false;
    bool    m_deviceModbusConnect=false;
    Vchart_Zoom *m_vchartZoom = nullptr;
    QModbusDataUnit   m_deviceUnit;
    VUser m_user;

    //Function
    FreqData getPulseCounter(QVector<QPointF> val,double threshold);
};

#endif // SENSOR_SEN0121_H
