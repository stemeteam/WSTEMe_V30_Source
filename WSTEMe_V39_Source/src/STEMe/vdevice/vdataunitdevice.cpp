#include "vdataunitdevice.h"
#include <QSettings>

VDataUnitDevice::VDataUnitDevice()
{

}

QList<VDataUnitDevice::DataUnit> VDataUnitDevice::loadFrameWidget()
{
    QList<DataUnit> frameDevice;
     QSettings settings("ELEVOI","VDAT");
     int size = settings.beginReadArray("VFrameDeviceWidget");
     for (int i = 0; i < size; ++i) {
         DataUnit vframe;
         settings.setArrayIndex(i);
         vframe.addressDevice = i+1;
         vframe.nameDevice = settings.value("nameDevice","").toString();
         vframe.objectName = settings.value("objectName","object").toString();
         vframe.serialNumberDevice = settings.value("serialNumberDevice","ffffffff").toString();
         vframe.iconPath = settings.value("iconPath","").toString();
         vframe.styleSheet = settings.value("styleSheet","").toString();
         vframe.description = settings.value("description","").toString();
         frameDevice.append(vframe);
     }
     settings.endArray();
     return  frameDevice;

}

void VDataUnitDevice::writeFrameWidget(QList<DataUnit> frameDevice)
{
    if(frameDevice.count()>0){
        QSettings settings("ELEVOI","VDAT");
        settings.beginWriteArray("VFrameDeviceWidget");
        settings.remove("");
        for (int i = 0; i < frameDevice.count(); ++i) {
            settings.setArrayIndex(i);
            settings.setValue("nameDevice", frameDevice.at(i).nameDevice);
            settings.setValue("objectName",frameDevice.at(i).objectName);
            settings.setValue("serialNumberDevice",frameDevice.at(i).serialNumberDevice);
            settings.setValue("iconPath",frameDevice.at(i).iconPath);
            settings.setValue("styleSheet",frameDevice.at(i).styleSheet);
            settings.setValue("description",frameDevice.at(i).description);
        }
        settings.endArray();
    }
}

bool VDataUnitDevice::insertFrameWidget(DataUnit frameDevice)
{
            QList<DataUnit> list = loadFrameWidget();
            for(int i=0;i<list.count();i++){
                if(QString::compare(list[i].serialNumberDevice,frameDevice.serialNumberDevice,Qt::CaseSensitive)==0){
                    return false;
                }
            }
            frameDevice.addressDevice = list.count()+1;
            list.append(frameDevice);
            writeFrameWidget(list);
            return true;
}

bool VDataUnitDevice::removeFrameWidget(VDataUnitDevice::DataUnit frameDevice)
{
    QList<DataUnit> list = loadFrameWidget();
    for(int i=0;i<list.count();i++){
        if(QString::compare(list[i].serialNumberDevice,frameDevice.serialNumberDevice,Qt::CaseSensitive)==0){
            list.removeAt(i);
            writeFrameWidget(list);
            return  true;
        }
    }
return false;
}

bool VDataUnitDevice::updateFrameWidget(VDataUnitDevice::DataUnit frameDevice)
{
    QList<DataUnit> list = loadFrameWidget();
    for(int i=0;i<list.count();i++){
        if(QString::compare(list[i].serialNumberDevice,frameDevice.serialNumberDevice,Qt::CaseSensitive)==0){
            int add = list[i].addressDevice;
            list[i] = frameDevice;
            list[i].addressDevice = add;
            writeFrameWidget(list);
            return true;
        }
    }
return false;
}

void VDataUnitDevice::clearFrameWidget()
{
        QSettings settings("ELEVOI","VDAT");
        settings.beginWriteArray("VFrameDeviceWidget");
        settings.remove("");
        settings.endArray();
}



VDataUnitDevice::VDeviceTypeInGroup VDataUnitDevice::SerialNumberGroup(QString serial)
{
    bool ok=false;
    VDeviceTypeInGroup type = VDeviceTypeInGroup::groupNone;
    uint group = serial.left(4).toUInt(&ok,16);
    if(!ok)return VDeviceTypeInGroup::groupNone;
    switch(group){
    case 0x0001: type = VDeviceTypeInGroup::groupSoftware_AddNewDevice;break;
    case 0x0002: type = VDeviceTypeInGroup::groupSoftware_Setup;break;
    case 0x0101: type = VDeviceTypeInGroup::groupSensor_PT100;break;
    case 0x0102: type = VDeviceTypeInGroup::groupSensor_Humidity;break;

    }
    return type;
}
uint VDataUnitDevice::SerialNumberGroup(bool *ok,QString serial)
{
    ok=nullptr;
    return serial.left(4).toUInt(ok,16);
}
uint VDataUnitDevice::SerialNumberDevice(bool *ok, QString serial)
{
    ok=nullptr;
    return serial.right(8).toUInt(ok,16);
}


