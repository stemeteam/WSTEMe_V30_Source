#ifndef VLISTDEVICE_H
#define VLISTDEVICE_H
#include <QList>
#include <vdevice/vdevice.h>


class VListDevice
{
public:
    VListDevice();

    VDevice device(QString serial)const;
    VDevice device(int index)const;
    bool contains(VDevice dev) const;
    int  indexOfDevice(VDevice dev) const{
        return checkDevice(dev,loadDevices());
    }
    int count() const{
        return loadDevices().count();
    }

    bool append(VDevice dev);
    bool update(VDevice dev);
    bool update(VDevice dev,QString serial);
    bool remove(VDevice dev);
    bool pushFront(VDevice dev);

    QList<VDevice> devices() const{
        return loadDevices();
    }
    void setDevices(QList<VDevice> listDevice){
        this->saveDevices(listDevice);
    }

private:
    QList<VDevice> loadDevices() const;
    void saveDevices(QList<VDevice> listDevice);
    int checkDevice(VDevice dev,QList<VDevice> listDevice) const;
};

#endif // VLISTDEVICE_H
