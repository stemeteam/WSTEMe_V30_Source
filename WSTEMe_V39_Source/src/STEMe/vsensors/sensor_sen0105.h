#ifndef SENSOR_SEN0105_H
#define SENSOR_SEN0105_H

//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>
#include <QSettings>

//user
#include <vdevice/vdevice.h>
#include <esensor/edev_sen0105.h>
#include <vlogin/vuser.h>
#include <vroot/vdevicecalibration.h>
#include <vfile/vfile.h>
#include <efilter/elowpassfilter.h>
#include <efilter/efrequency.h>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <echart/echartlines.h>
#include <QGridLayout>
#include <QValueAxis>
namespace Ui {
class Sensor_SEN0105;
}

class Sensor_SEN0105 : public QWidget
{
    Q_OBJECT

        /////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...
public:
        void setDeviceWidget(VDevice dev,VUser user);
        void sensorCalibration(double valueCalib,double valueRaw);

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
        EDev_Sen0105 *m_edev_sen0105=nullptr;

        VDevice m_deviceInformation;
        QMessageBox *m_QMessageBox = nullptr;
        VDeviceCalibration *m_deviceCalibration = nullptr;

        void sensorWriteReport(bool status);
        void calculateParametes(QVector<QPointF> value,int resolution);

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
            EChartLines *m_echart = nullptr;
            QTimer  *m_chartTimer=nullptr;
            QSplineSeries *m_soundLine=nullptr;
            QSplineSeries *m_soundLine1=nullptr;
            QSplineSeries *m_soundLine2=nullptr;
            int     m_chartInterval = 1;

            int m_axisX_TickCount = 11;
            int m_axisX_Range = 10;
            int m_axisY_TickCount = 11;
            int m_axisY_Range_Max = 5;
            int m_axisY_Range_Min = 0;

            //int m_chartTimerScan = 100;

            qreal m_axtX_Index = 0;
            double m_chartTime_AxisX=0;

            void chartInit();
            void chartInit(QSplineSeries *Line);
            void chartGraph(double val);
            void chartGraph(QPointF val);
            void chartGraph(QVector<QPointF> val);
            void chartClear();

            void setTrackLine(EChartGesture::ETrackLine track);
    /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
public:
    explicit Sensor_SEN0105(QWidget *parent = nullptr);
    ~Sensor_SEN0105();

private slots:
    void on_pushButton_Calib_clicked();

    void on_pushButton_Exit_clicked();

    void on_comboBox_Unit_currentIndexChanged(int index);

    void on_pushButton_OpenData_clicked();

    void on_pushButton_SaveData_clicked();

    void on_pushButton_Start_clicked();

    void on_comboBox_SelectSample_currentIndexChanged(int index);

    void on_pushButton_ClearChart_clicked();

    void on_radioButton_Accumulation_toggled(bool checked);

    void on_pushButton_TrackLine_Default_clicked();

    void on_pushButton_TrackLine_Tooltip_clicked();

    void on_pushButton_TrackLine_Yax_clicked();

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::Sensor_SEN0105 *ui;
    quint32 m_system_count=0;
 //   QVector<QPointF> m_soundValue;
    bool    m_deviceModbusConnect=false;
    QModbusDataUnit   m_deviceUnit;
    VUser m_user;

    struct ConfigSave{
        int voltageThreshold=0;
        int voltageRepeat=0;
    }m_configSave;

    enum SoundType{
        typeSoundLevel,
        typeSoundReflection,
        typeSoundFrequency,
        typeSoundVoltage
    };
    enum SoundStatus{
        soundStart,
        soundWait,
        soundSampling,
        soundFilter,
        soundChart,
        soundStop,
        soundError
    };
    enum FrequencyStatus{
        freqIdle,
        freqRead
    };

    SoundType m_soundType = typeSoundLevel;
    SoundStatus m_soundStatus = soundStop;
    FrequencyStatus m_frequencyStatus = freqIdle;

    bool m_frequencyToggle=false;
    bool m_VoltageToggle=false;
    bool m_LevelToggle=false;
    //for Sound
    double m_soundFrequency = 100;//100Hz
    int m_soundTimeQueryData = 0;
    int m_soundTimeSample = 0;

    double m_Time_Line = 0;


    bool    m_isOpenFile = false;
    //File
    void loadConfig();
    void saveConfig();
    void setOpenFile(bool status);
    void soundPoll();
    void soundLevel();
    void soundVoltage();
    void soundReflection();
    void soundReflectionChart();
    void soundFrequency();
    void soundFrequencyRead();
    QVector<quint16> soundGetFrequency();
};

#endif // SENSOR_SEN0105_H
