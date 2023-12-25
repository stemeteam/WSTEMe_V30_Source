#include "sensor_sen0111.h"
#include "ui_sensor_sen0111.h"

QT_CHARTS_USE_NAMESPACE

void Sensor_SEN0111::setDeviceWidget(VDevice dev)
{
   m_deviceInformation = dev;
}



Sensor_SEN0111::Sensor_SEN0111(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0111)
{
    ui->setupUi(this);
}

Sensor_SEN0111::~Sensor_SEN0111()
{
    delete ui;
}
