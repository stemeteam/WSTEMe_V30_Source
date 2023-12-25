#ifndef VFRAMEDEVICEWIDGET_H
#define VFRAMEDEVICEWIDGET_H
#include <QList>


class VDataUnitDevice
{
public:
    VDataUnitDevice();

    enum VDeviceTypeInGroup{
        groupNone                   = 0,
        groupSoftware_AddNewDevice  = 0x0001,
        groupSoftware_Setup         = 0x0002,
        groupSensor_PT100           = 0x0101,
        groupSensor_Humidity        = 0x0102
    }m_deviceTypeInGroup;




    struct DataUnit{
        int addressDevice = 127;
        QString nameDevice = "name";
        QString objectName = "object";
        QString serialNumberDevice="000000000000";
        QString iconPath = "";
        QString styleSheet ="";
        QString description ="";
    };

    QList<DataUnit> loadFrameWidget();
    void writeFrameWidget(QList<DataUnit> frameDevice);
    bool insertFrameWidget(DataUnit frameDevice);
    bool removeFrameWidget(DataUnit frameDevice);
    bool updateFrameWidget(DataUnit frameDevice);
    void clearFrameWidget();

    uint SerialNumberGroup(bool *ok,QString serial);
    VDeviceTypeInGroup SerialNumberGroup(QString serial);
    uint SerialNumberDevice(bool *ok,QString serial);

};

#endif // VFRAMEDEVICEWIDGET_H
