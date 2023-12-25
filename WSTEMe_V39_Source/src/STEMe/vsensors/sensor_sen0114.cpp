#include "sensor_sen0114.h"
#include "ui_sensor_sen0114.h"

QT_CHARTS_USE_NAMESPACE

void Sensor_SEN0114::setDeviceWidget(VDevice dev)
{
   m_deviceInformation = dev;

}


Sensor_SEN0114::Sensor_SEN0114(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0114)
{
    ui->setupUi(this);
}

Sensor_SEN0114::~Sensor_SEN0114()
{
    delete ui;
}
