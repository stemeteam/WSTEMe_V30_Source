#ifndef VFILE_H
#define VFILE_H

#include <QObject>
#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QCoreApplication>
#include <QDebug>

#include "vdevice/vdevice.h"
#include "vdevice/vlistdevice.h"


class VFile
{


public:
    VFile();
    struct VFileInfoSample{
        int interval;           //Sample time
        QString typeSample;     // type sample
        qreal axisX_Max;        // axisX_max on chart
        qreal axisX_Min;        // axisX_min on chart
        qreal axisY_Max;       // axisY_max on chart
        qreal axisY_Min;              // axisY_min on chart
        int count;              // number of data (QVector<double>) to save
    };

    struct VFileDataUnit{
        VDevice device;
        QList<QVector<double>> data;
        QList<QVector<QPointF>> lines;
        QList<QString> texts;
        VFileInfoSample infoSample;
    };

    inline QString error() const{
        return m_error;
    }

    void setError(QString error){
        m_error = error;
    }
    inline QString fileName(){
        return m_fileName;
    }
    inline QString filePath(){
        return m_filePath;
    }

    bool saveDevice(VDevice dev);
    bool saveDevice(QWidget *parrent, VDevice dev);
    bool saveDevices(QList<VDevice> list);
    bool saveDevices(QWidget *parrent,QList<VDevice> list);
    bool saveData(VDevice dev,QVector<double> data,int interval);
    bool saveData(VDevice dev,QVector<double> data,int interval,QString typeSample);
    bool saveDatas(VDevice dev,QList<QVector<double>> data,int interval);
    bool saveDatas(VDevice dev,QList<QVector<double>> data,int interval,QString typeSample);
    bool saveDatas(VFileDataUnit dataUnit);
    bool saveDataF(VFileDataUnit dataUnit);

    VFileDataUnit loadDatas();
    VFileDataUnit loadDataF();
    VFileDataUnit loadDataF(VFileDataUnit unit);
    QList<VDevice> loadDevices();

private:
    QString m_error="";
    QString m_fileName="";
    QString m_filePath="/home/pi/Desktop";

    QJsonDocument getJsonDocumentDeviceList(QList<VDevice> list);
    QJsonDocument getJsonDocumentDevice(VDevice dev);
    VDevice getDeviceFromJsonObject(QJsonObject obj);
    QList<VDevice> getDeviceListFromJsonDocument(QJsonDocument doc);
    QJsonObject getSampleInfo(int num,int interval);
    QJsonObject getSampleInfo(int num,int interval,QString typeSample);
    QJsonObject getSampleInfo(VFileInfoSample info);
    QJsonObject getData(QVector<double> data);
    QJsonObject getDatas(QList<QVector<double>> data);
    QJsonObject getDatas(QList<QVector<double>> data,int number);
    QJsonObject getDataF(QList<QVector<QPointF>> data,int number);
    QJsonObject getDataF(QList<QVector<QPointF>> data,QList<QString> text,int number);


};

#endif // VFILE_H
