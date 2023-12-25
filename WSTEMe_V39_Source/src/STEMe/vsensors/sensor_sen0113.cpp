#include "sensor_sen0113.h"
#include "ui_sensor_sen0113.h"

QT_CHARTS_USE_NAMESPACE

void Sensor_SEN0113::setDeviceWidget(VDevice dev)
{
   m_deviceInformation = dev;

}

Sensor_SEN0113::Sensor_SEN0113(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0113)
{
    ui->setupUi(this);
}

Sensor_SEN0113::~Sensor_SEN0113()
{
    delete ui;
}
