#include "sensor_sen0120.h"
#include "ui_sensor_sen0120.h"

QT_CHARTS_USE_NAMESPACE


/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Sensor_SEN0120::Sensor_SEN0120(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0120)
{
    ui->setupUi(this);


}
Sensor_SEN0120::~Sensor_SEN0120()
{
    delete ui;
}

void Sensor_SEN0120::setDeviceWidget(VDevice dev)
{
    m_deviceInformation = dev;

}
