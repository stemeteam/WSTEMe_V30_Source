#include "vlistdevice.h"
#include <QSettings>
#include <QList>
#include <vdevice/vdevice.h>

VListDevice::VListDevice()
{

}

VDevice VListDevice::device(QString serial) const
{
    VDevice _dev;
    QList<VDevice> _ldev= loadDevices();
    if(!_ldev.isEmpty())
    {
        for(int i=0;i<_ldev.count();i++){
            if(QString::compare(_ldev[i].serialNumber(),serial,Qt::CaseInsensitive)==0)return _ldev[i];
        }
    }
    return _dev;
}

VDevice VListDevice::device(int index) const
{
    QList<VDevice> _ldev = loadDevices();
    VDevice _dev;
    if(_ldev.count()<=index)return _dev;
    return _ldev[index];
}

bool VListDevice::contains(VDevice dev) const
{
    if(checkDevice(dev,loadDevices())==-1){
        return false;
    }
    return true;
}

bool VListDevice::append(VDevice dev)
{
    QList<VDevice> _ldev = loadDevices();
    if(checkDevice(dev,_ldev)!=-1)return false;
    _ldev.append(dev);
    this->saveDevices(_ldev);
    return true;
}

bool VListDevice::update(VDevice dev)
{
    QList<VDevice> _ldev = loadDevices();
    int _index = checkDevice(dev,_ldev);
    if(_index ==-1)return false;
    _ldev.replace(_index,dev);
    this->saveDevices(_ldev);
    return true;
}

bool VListDevice::update(VDevice dev, QString serial)
{
    QList<VDevice> _ldev = loadDevices();
    int _index = checkDevice(dev,_ldev);
    if(_index ==-1)return false;
    dev.setSerialNumber(serial);
    _ldev.replace(_index,dev);
    this->saveDevices(_ldev);
    return true;
}

bool VListDevice::remove(VDevice dev)
{
    QList<VDevice> _ldev = loadDevices();
    int _index = checkDevice(dev,_ldev);
    if(_index ==-1)return false;
    _ldev.removeAt(_index);
    this->saveDevices(_ldev);
    return true;
}

bool VListDevice::pushFront(VDevice dev)
{
    QList<VDevice> _ldev = loadDevices();
    int _index = checkDevice(dev,_ldev);
    if(_index ==-1)return false;
    _ldev.push_front(dev);
    this->saveDevices(_ldev);
    return true;
}

QList<VDevice> VListDevice::loadDevices() const
{
     QList<VDevice> listDevice;
     QSettings settings("ELEVOI","VDAT");
     int size = settings.beginReadArray("VFrameDeviceWidget");
     for (int i = 0; i < size; ++i) {
         VDevice dev;
         settings.setArrayIndex(i);
         dev.setAddress(i+1);
         dev.setName(settings.value("nameDevice","").toString());
         dev.setType(settings.value("typeDevice","Root").toString());
         dev.setObjectName(settings.value("objectName","object").toString());
         dev.setSerialNumber(settings.value("serialNumberDevice","ffffffff").toString());
         dev.setIconPath(settings.value("iconPath","").toString());
         dev.setDescription(settings.value("description","").toString());
         dev.setDateCreated(settings.value("dateCreated","").toString());
         dev.setDateModified(settings.value("dateModified","").toString());
         listDevice.append(dev);
     }
     settings.endArray();
     return  listDevice;
}

void VListDevice::saveDevices(QList<VDevice> listDevice)
{
    if(listDevice.count()>0){
        QSettings settings("ELEVOI","VDAT");
        settings.beginWriteArray("VFrameDeviceWidget");
        settings.remove("");
        for (int i = 0; i < listDevice.count(); ++i) {
            settings.setArrayIndex(i);
            settings.setValue("nameDevice", listDevice[i].name());
            settings.setValue("typeDevice",listDevice[i].type());
            settings.setValue("objectName",listDevice[i].objectName());
            settings.setValue("serialNumberDevice",listDevice[i].serialNumber());
            settings.setValue("iconPath",listDevice[i].iconPath());
            settings.setValue("description",listDevice[i].description());
            settings.setValue("dateCreated",listDevice[i].dateCreated());
            settings.setValue("dateModified",listDevice[i].dateModified());
        }
        settings.endArray();
    }
}

int VListDevice::checkDevice(VDevice dev, QList<VDevice> listDevice) const
{
    if(listDevice.isEmpty())return false;
    for(int i=0;i<listDevice.count();i++){
        if(QString::compare(listDevice[i].serialNumber(),dev.serialNumber(),Qt::CaseSensitive)==0)return i;
    }
    return -1;
}
