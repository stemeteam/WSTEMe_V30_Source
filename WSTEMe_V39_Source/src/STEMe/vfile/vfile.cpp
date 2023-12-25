#include "vfile.h"
#include <QFile>
#include <QFileDialog>
#include <QObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>


VFile::VFile()
{

}





QJsonDocument VFile::getJsonDocumentDeviceList(QList<VDevice> list)
{
    QJsonDocument jsonDoc;
    QJsonObject jsonList;
    foreach(auto element,list){
    if(element.typeDevice()!=VDevice::Setting)
        {
        QJsonObject jsonDevice;
        jsonDevice.insert("nameDevice",element.name());
        jsonDevice.insert("typeDevice",element.type());
        jsonDevice.insert("objectName",element.objectName());
        jsonDevice.insert("serialNumberDevice",element.serialNumber());
        jsonDevice.insert("iconPath",element.iconPath());
        jsonDevice.insert("description",element.description());
        jsonDevice.insert("dateCreated",element.dateCreated());
        jsonDevice.insert("dateModified",element.dateModified());
        jsonList.insert(element.serialNumber(),jsonDevice);
        }
    }

    jsonDoc.setObject(jsonList);
    return jsonDoc;
}

QJsonDocument VFile::getJsonDocumentDevice(VDevice dev)
{
    QJsonDocument jsonDoc;
    QJsonObject jsonDevice;
    jsonDevice.insert("nameDevice",dev.name());
    jsonDevice.insert("typeDevice",dev.type());
    jsonDevice.insert("objectName",dev.objectName());
    jsonDevice.insert("serialNumberDevice",dev.serialNumber());
    jsonDevice.insert("iconPath",dev.iconPath());
    jsonDevice.insert("description",dev.description());
    jsonDevice.insert("dateCreated",dev.dateCreated());
    jsonDevice.insert("dateModified",dev.dateModified());
    jsonDoc.setObject(jsonDevice);
    return jsonDoc;
}

VDevice VFile::getDeviceFromJsonObject(QJsonObject obj)
{
    VDevice dev;
    dev.setName(obj.value("nameDevice").toString());
    dev.setType(obj.value("typeDevice").toString());
    dev.setObjectName(obj.value("objectName").toString());
    dev.setSerialNumber(obj.value("serialNumberDevice").toString());
    dev.setIconPath(obj.value("iconPath").toString());
    dev.setDescription(obj.value("description").toString());
    dev.setDateCreated(obj.value("dateCreated").toString());
    dev.setDateModified(obj.value("dateModified").toString());
    return dev;
}

QList<VDevice> VFile::getDeviceListFromJsonDocument(QJsonDocument doc)
{
    QList<VDevice> lstDev;
    QJsonObject jsonList = doc.object();
    QStringList list = jsonList.keys();
    if(list.isEmpty())return lstDev;

    foreach(QString key, list){
        lstDev.append(this->getDeviceFromJsonObject(jsonList.value(key).toObject()));
    }
    return lstDev;
}




bool VFile::saveDevice(VDevice dev)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    m_fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/dev"+_time,QObject::tr("STEMe files (*.dev);;Text files (*.txt)"));
    if(m_fileName.isEmpty())return false;
    //Open file
    if(!m_fileName.contains(".dev",Qt::CaseSensitive))m_fileName += ".dev";
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Save jsonDocument to file
    fileDev.write(this->getJsonDocumentDevice(dev).toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDevice(QWidget *parrent, VDevice dev)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    m_fileName = QFileDialog::getSaveFileName(parrent,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/dev"+_time,QObject::tr("STEMe files (*.dev);;Text files (*.txt)"));
    if(m_fileName.isEmpty())return false;
    //Open file
    if(!m_fileName.contains(".dev",Qt::CaseSensitive))m_fileName += ".dev";
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(parrent,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Save jsonDocument to file
    fileDev.write(this->getJsonDocumentDevice(dev).toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDevices(QList<VDevice> list)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    m_fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/dev"+_time,QObject::tr("STEMe files (*.dev);;Text files (*.txt)"));
    if(m_fileName.isEmpty())return false;

    //Open file
    if(!m_fileName.contains(".dev",Qt::CaseSensitive))m_fileName += ".dev";
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Save jsonDocument to file
    fileDev.write(this->getJsonDocumentDeviceList(list).toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDevices(QWidget *parrent, QList<VDevice> list)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    m_fileName = QFileDialog::getSaveFileName(parrent,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/device/dev"+_time,QObject::tr("STEMe files (*.dev);;Text files (*.txt)"));
    if(m_fileName.isEmpty())return false;

    //Open file
    if(!m_fileName.contains(".dev",Qt::CaseSensitive))m_fileName += ".dev";
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(parrent,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Save jsonDocument to file
    fileDev.write(this->getJsonDocumentDeviceList(list).toJson());
    fileDev.close();
    return true;
}


QList<VDevice> VFile::loadDevices()
{
    QList<VDevice> listDev;
    //Show dialog file, get path of file
    m_fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/device",QObject::tr("STEMe files (*.dev);;Text files (*.txt)"));
    if(m_fileName.isEmpty())return listDev;

    //Open file
    QFile fileDev(m_fileName);
    if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return listDev;
    }
    //get jsonDocument from file
    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileDev.readAll(),&jsonParseError);
    fileDev.close();
    if(jsonParseError.error != QJsonParseError::NoError)return listDev;
    //get All device from JsonDocument
    listDev = this->getDeviceListFromJsonDocument(jsonDoc);
    return listDev;
}


QJsonObject VFile::getSampleInfo(int num, int interval)
{
    QJsonObject obj;
    obj.insert("DateTime",QDateTime::currentDateTime().toString());
    obj.insert("Interval",interval);
    obj.insert("Count",num);
    return obj;
}

QJsonObject VFile::getSampleInfo(int num, int interval, QString typeSample)
{
    QJsonObject obj;
    obj.insert("Type",typeSample);
    obj.insert("DateTime",QDateTime::currentDateTime().toString());
    obj.insert("Interval",interval);
    obj.insert("Count",num);
    return obj;
}

QJsonObject VFile::getSampleInfo(VFile::VFileInfoSample info)
{
    QJsonObject obj;
    obj.insert("Type",info.typeSample);
    obj.insert("DateTime",QDateTime::currentDateTime().toString());
    obj.insert("Interval",info.interval);
    obj.insert("Count",info.count);
    obj.insert("AxisX_Max",info.axisX_Max);
    obj.insert("AxisX_Min",info.axisX_Min);
    obj.insert("AxisY_Max",info.axisY_Max);
    obj.insert("AxisY_Min",info.axisY_Min);
    return obj;
}

QJsonObject VFile::getData(QVector<double> data)
{
    QJsonArray array;
    QJsonObject obj;
    for(int i=0;i<data.count();i++)array.append(data[i]);
    obj.insert("Data1",array);
    return obj;
}

QJsonObject VFile::getDatas(QList<QVector<double>> data)
{
    QJsonObject obj;
    for(int i=0;i<data.count();i++){
           QJsonArray array;
           for(int j=0;j<data[i].count();j++)array.append(data[i][j]);
           obj.insert("Data"+QString::number(i+1),array);
    }
    return obj;
}

QJsonObject VFile::getDatas(QList<QVector<double> > data, int number)
{
    QJsonObject obj;
    for(int i=0;i<data.count()&&i<number;i++){
           QJsonArray array;
           for(int j=0;j<data[i].count();j++)array.append(data[i][j]);
           obj.insert("Data"+QString::number(i+1),array);
    }
    return obj;
}

QJsonObject VFile::getDataF(QList<QVector<QPointF> > data, int number)
{
    QJsonObject obj;
    for(int i=0;i<data.count()&&i<number;i++){
           QJsonArray _x,_y;
           for(int j=0;j<data[i].count();j++){
               _x.append(data[i][j].x());
               _y.append(data[i][j].y());
           }
           obj.insert("X"+QString::number(i),_x);
           obj.insert("Y"+QString::number(i),_y);
    }
    return obj;
}

QJsonObject VFile::getDataF(QList<QVector<QPointF> > data, QList<QString> text, int number)
{
    QJsonObject obj;
    if(text.count()<data.count())return obj;
    for(int i=0;i<data.count()&&i<number;i++){
           QJsonArray _x,_y;
           for(int j=0;j<data[i].count();j++){
               _x.append(data[i][j].x());
               _y.append(data[i][j].y());
           }
           obj.insert(text.at(i)+"x",_x);
           obj.insert(text.at(i)+"y",_y);
    }
    return obj;
}




//Map..............................................
/*
 {
 "Device":{...},
 "Data":{
        "DateTime":"12/01/2021 12:15:36",
        "Interval":100,
        "Data":[1,2,3,4...]
        }
 }

 */

bool VFile::saveData(VDevice dev, QVector<double> data,int interval)
{
    //Show dialog file, get path of file
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());

    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+ _time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dev).object());
    obj.insert("Info",getSampleInfo(1,interval));
    obj.insert("Sample",getData(data));
    QJsonDocument doc;
    doc.setObject(obj);
    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}

bool VFile::saveData(VDevice dev, QVector<double> data, int interval, QString typeSample)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+_time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dev).object());
    obj.insert("Info",getSampleInfo(1,interval,typeSample));
    obj.insert("Sample",getData(data));
    QJsonDocument doc;
    doc.setObject(obj);
    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}


bool VFile::saveDatas(VDevice dev, QList<QVector<double>> data, int interval)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+_time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dev).object());
    obj.insert("Info",getSampleInfo(data.count(),interval));
    obj.insert("Sample",getDatas(data));
    QJsonDocument doc;
    doc.setObject(obj);

    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDatas(VDevice dev, QList<QVector<double>> data, int interval, QString typeSample)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+_time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dev).object());
    obj.insert("Info",getSampleInfo(data.count(),interval,typeSample));
    obj.insert("Sample",getDatas(data));
    QJsonDocument doc;
    doc.setObject(obj);

    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDatas(VFile::VFileDataUnit dataUnit)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+_time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dataUnit.device).object());
    obj.insert("Info",getSampleInfo(dataUnit.infoSample));
    obj.insert("Sample",getDatas(dataUnit.data,dataUnit.infoSample.count));
    QJsonDocument doc;
    doc.setObject(obj);
    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}

bool VFile::saveDataF(VFile::VFileDataUnit dataUnit)
{
    QString _time = QString::number(QDateTime::currentDateTime().date().year()) + \
                    QString::number(QDateTime::currentDateTime().date().month()) + \
                    QString::number(QDateTime::currentDateTime().date().day()) + \
                    QString::number(QDateTime::currentDateTime().time().hour()) + \
                    QString::number(QDateTime::currentDateTime().time().minute()) + \
                    QString::number(QDateTime::currentDateTime().time().second());
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getSaveFileName(nullptr,QObject::tr("Save File"),QCoreApplication::applicationDirPath()+"/data/stm"+_time,QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return false;
    m_fileName = fileName;
    //Open file
    if(!fileName.contains(".stm",Qt::CaseSensitive))fileName += ".stm";
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::WriteOnly)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return false;
    }

    //Add info to jsonDocument
    QJsonObject obj;
    obj.insert("Device",getJsonDocumentDevice(dataUnit.device).object());
    obj.insert("Info",getSampleInfo(dataUnit.infoSample));
    obj.insert("Sample",getDataF(dataUnit.lines,dataUnit.texts,dataUnit.infoSample.count));
    QJsonDocument doc;
    doc.setObject(obj);

    //Save jsonDocument to file
    fileDev.write(doc.toJson());
    fileDev.close();
    return true;
}

VFile::VFileDataUnit VFile::loadDatas()
{
        VFile::VFileDataUnit fileData;
        this->setError("");
        //Show dialog file, get path of file
        QString fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/data",QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
        if(fileName.isEmpty())return fileData;
        m_fileName = fileName;
        //Open file
        QFile fileDev(fileName);
        if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
            return fileData;
        }
        //get jsonDocument from file
        QJsonParseError jsonParseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(fileDev.readAll(),&jsonParseError);
        fileDev.close();
        if(jsonParseError.error != QJsonParseError::NoError){
            this->setError("Can't to convert JsonDocument");
            return fileData;
        }
        //get All JsonObject from JsonDocument
        QJsonObject obj;
        obj = jsonDoc.object();
        QJsonObject objInfo;
        objInfo = obj.value("Info").toObject();
        int count = objInfo.value("Count").toInt();
        //Read data with 1 sample
        if(count<1){
            this->setError("Can't to read data");
            return fileData;
        }
        QJsonObject objSample;
        objSample = obj.value("Sample").toObject();
        for(int i=1;i<=count;i++){
            QJsonArray array = objSample.value("Data"+QString::number(i)).toArray();
            QVariantList lst = array.toVariantList();
            QVector<double> data;
            for(int j=0;j<lst.count();j++)data.append(lst[j].toDouble());
            fileData.data.append(data);
        }
        //Read Info
        fileData.infoSample.interval = objInfo.value("Interval").toInt();
        fileData.infoSample.typeSample = objInfo.value("Type").toString();
        fileData.infoSample.count = objInfo.value("Count").toInt();
        fileData.infoSample.axisX_Max = objInfo.value("AxisX_Max").toDouble();
        fileData.infoSample.axisX_Min = objInfo.value("AxisX_Min").toDouble();
        fileData.infoSample.axisY_Max = objInfo.value("AxisY_Max").toDouble();
        fileData.infoSample.axisY_Min = objInfo.value("AxisY_Min").toDouble();
        //Read Device
        fileData.device = getDeviceFromJsonObject(obj.value("Device").toObject());
        return fileData;
}

VFile::VFileDataUnit VFile::loadDataF()
{
    VFile::VFileDataUnit fileData;
    this->setError("");
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/data",QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return fileData;
    m_fileName = fileName;
    //Open file
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return fileData;
    }
    //get jsonDocument from file
    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileDev.readAll(),&jsonParseError);
    fileDev.close();
    if(jsonParseError.error != QJsonParseError::NoError){
        this->setError("Can't to convert JsonDocument");
        return fileData;
    }
    //get All JsonObject from JsonDocument
    QJsonObject obj;
    obj = jsonDoc.object();
    QJsonObject objInfo;
    objInfo = obj.value("Info").toObject();
    int count = objInfo.value("Count").toInt();
    //Read data with 1 sample
    if(count<1){
        this->setError("Can't to read data");
        return fileData;
    }
    QJsonObject objSample;
    objSample = obj.value("Sample").toObject();
    for(int i=0;i<count;i++){
        QJsonArray _x = objSample.value("X"+QString::number(i)).toArray();
        QJsonArray _y = objSample.value("Y"+QString::number(i)).toArray();
        QVariantList lst_x = _x.toVariantList();
        QVariantList lst_y = _y.toVariantList();
        QVector<QPointF> data;
        for(int j=0;j<lst_x.count();j++){
            data.append(QPointF(lst_x[j].toDouble(),lst_y[j].toDouble()));
        }
        fileData.lines.append(data);
    }
    //Read Info
    fileData.infoSample.interval = objInfo.value("Interval").toInt();
    fileData.infoSample.typeSample = objInfo.value("Type").toString();
    fileData.infoSample.count = objInfo.value("Count").toInt();
    fileData.infoSample.axisX_Max = objInfo.value("AxisX_Max").toDouble();
    fileData.infoSample.axisX_Min = objInfo.value("AxisX_Min").toDouble();
    fileData.infoSample.axisY_Max = objInfo.value("AxisY_Max").toDouble();
    fileData.infoSample.axisY_Min = objInfo.value("AxisY_Min").toDouble();
    //Read Device
    fileData.device = getDeviceFromJsonObject(obj.value("Device").toObject());
    return fileData;
}

VFile::VFileDataUnit VFile::loadDataF(VFileDataUnit unit)
{
    VFile::VFileDataUnit fileData;
    this->setError("");
    //Show dialog file, get path of file
    QString fileName = QFileDialog::getOpenFileName(nullptr,QObject::tr("Open File"),QCoreApplication::applicationDirPath()+"/data",QObject::tr("STEMe files (*.stm);;Text files (*.txt)"));
    if(fileName.isEmpty())return fileData;
    m_fileName = fileName;
    //Open file
    QFile fileDev(fileName);
    if(!fileDev.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr,QObject::tr("Can't to open file!"),fileDev.errorString());
        return fileData;
    }
    //get jsonDocument from file
    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileDev.readAll(),&jsonParseError);
    fileDev.close();
    if(jsonParseError.error != QJsonParseError::NoError){
        this->setError("Can't to convert JsonDocument");
        return fileData;
    }
    //get All JsonObject from JsonDocument
    QJsonObject obj;
    obj = jsonDoc.object();
    QJsonObject objInfo;
    objInfo = obj.value("Info").toObject();
    int count = objInfo.value("Count").toInt();
    //Read data with 1 sample
    if(count<1){
        this->setError("Can't to read data");
        return fileData;
    }
    QJsonObject objSample;
    objSample = obj.value("Sample").toObject();
    for(int i=0;i<count;i++){
        QJsonArray _x = objSample.value(unit.texts.at(i)+"x").toArray();
        QJsonArray _y = objSample.value(unit.texts.at(i)+"y").toArray();
        QVariantList lst_x = _x.toVariantList();
        QVariantList lst_y = _y.toVariantList();
        QVector<QPointF> data;
        for(int j=0;j<lst_x.count();j++){
            data.append(QPointF(lst_x[j].toDouble(),lst_y[j].toDouble()));
        }
        fileData.lines.append(data);
    }
    //Read Info
    fileData.infoSample.interval = objInfo.value("Interval").toInt();
    fileData.infoSample.typeSample = objInfo.value("Type").toString();
    fileData.infoSample.count = objInfo.value("Count").toInt();
    fileData.infoSample.axisX_Max = objInfo.value("AxisX_Max").toDouble();
    fileData.infoSample.axisX_Min = objInfo.value("AxisX_Min").toDouble();
    fileData.infoSample.axisY_Max = objInfo.value("AxisY_Max").toDouble();
    fileData.infoSample.axisY_Min = objInfo.value("AxisY_Min").toDouble();
    //Read Device
    fileData.device = getDeviceFromJsonObject(obj.value("Device").toObject());
    return fileData;
}
















