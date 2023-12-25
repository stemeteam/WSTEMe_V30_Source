#ifndef SENSOR_SEN0120_H
#define SENSOR_SEN0120_H


//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/edev_sen0120.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <vroot/vdevicecalibration.h>

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Sensor_SEN0120;
}

class Sensor_SEN0120 : public QWidget
{
    Q_OBJECT

public:
    explicit Sensor_SEN0120(QWidget *parent = nullptr);
    ~Sensor_SEN0120();

    void setDeviceWidget(VDevice dev);

private:
    Ui::Sensor_SEN0120 *ui;

    VDevice m_deviceInformation;


};
#endif // SENSOR_SEN0120_H
