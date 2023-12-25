#ifndef SENSOR_SEN0102_H
#define SENSOR_SEN0102_H

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
#include <esensor/edev_sen0102.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <vroot/vdevicecalibration.h>


namespace Ui {
class Sensor_SEN0102;
}

class Sensor_SEN0102 : public QWidget
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
    QVector<double> m_VALUE_AVG_TEMP;

    int m_modbusSampleTime = 100;
    EDev_Sen0102 *m_edev_sen0102=nullptr;

    VDevice m_deviceInformation;
    QMessageBox *m_QMessageBox = nullptr;
    VDeviceCalibration *m_deviceCalibration = nullptr;

    void sensorWriteReport(bool status);
    void sensorWriteMultipleREG(quint16 address,QVector<quint16> values);
    void sensorWriteSingleREG(quint16 reg, quint16 value);

    void calculateParametes(double value,int resolution);
/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
private slots:
    void on_displayTimer();
    void on_setChartParameter(int sampleTime);

private:
    QTimer  *m_displayTimer=nullptr;
    bool    m_displayToggle=false;
    int     m_displayInterval = 10;

    void displayPoll();

/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
public:
    explicit Sensor_SEN0102(QWidget *parent = nullptr);
    ~Sensor_SEN0102();

private slots:


    void on_pushButton_Exit_clicked();

    void on_pushButton_ChartZoom_clicked();

    void on_pushButton_getSamples_clicked();

    void on_comboBox_Temp_Unit_currentIndexChanged(int index);

    void on_spinBox_SampleTime_valueChanged(int arg1);

    void on_pushButton_SetSampleTime_clicked();

    void on_pushButton_Calib_clicked();

    void on_tabWidget_tabBarClicked(int index);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Sensor_SEN0102 *ui;
    bool    m_deviceModbusConnect=false;
    Vchart_Zoom *m_vchartZoom = nullptr;
    VUser m_user;
};

#endif // FORMATH0102_H
