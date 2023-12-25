#ifndef SENSOR_SEN0103_H
#define SENSOR_SEN0103_H

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
#include <esensor/edev_sen0103.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <vroot/vdevicecalibration.h>


namespace Ui {
class Sensor_SEN0103;
}

class Sensor_SEN0103 : public QWidget
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
        EDev_Sen0103 *m_edev_sen0103=nullptr;

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



   /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

public:
    explicit Sensor_SEN0103(QWidget *parent = nullptr);
    static QVector<Sensor_SEN0103*> instances;
    ~Sensor_SEN0103();
private slots:
    void on_setChartParameter(int sampleTime);
    void on_pushButton_Exit_clicked();

    void on_pushButton_ChartZoom_clicked();

    void on_pushButton_SetZero_2_clicked();

    void on_spinBox_SampleTime_2_valueChanged(int arg1);

    void on_pushButton_SetSampleTime_2_clicked();

    void on_pushButton_Calib_2_clicked();

    void on_comboBox_Unit_currentIndexChanged(int index);

    void on_pushButton_getSamples_clicked();

    void on_tabWidget_tabBarClicked(int index);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Sensor_SEN0103 *ui;
    quint32 m_system_count=0;
    bool    m_deviceModbusConnect=false;
    QModbusDataUnit   m_deviceUnit;
    Vchart_Zoom *m_vchartZoom = nullptr;
    VUser m_user;

};

#endif // SENSOR_WHL0103_H
