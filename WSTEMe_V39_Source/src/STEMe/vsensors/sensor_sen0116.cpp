#include "sensor_sen0116.h"
#include "ui_sensor_sen0116.h"

QT_CHARTS_USE_NAMESPACE




/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
void Sensor_SEN0116::setDeviceWidget(VDevice dev)
{
    m_deviceInformation = dev;

}

Sensor_SEN0116::Sensor_SEN0116(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0116)
{
    ui->setupUi(this);
}

Sensor_SEN0116::~Sensor_SEN0116()
{
    delete ui;
}
