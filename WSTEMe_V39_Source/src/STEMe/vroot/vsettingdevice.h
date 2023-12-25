#ifndef VSETTINGDEVICE_H
#define VSETTINGDEVICE_H

//system
#include <QCloseEvent>

#include <QMainWindow>
#include "QStandardItemModel"

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/esensors.h>

namespace Ui {
class VSettingDevice;
}

class VSettingDevice : public QMainWindow
{
    Q_OBJECT
    ////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................

    public slots:
        void modbusRtuReply(VNetworkDataUnit unit);
    Q_SIGNALS:
        void modbusRtuRequest(VNetworkDataUnit unit);
    private:
        void modbusRequestInputRegisters();
        void modbusReadResult(VNetworkDataUnit unit);
        void modbusSetSerialNumber(QString serial);


public: signals:
    void signalAddNewDevice();

public:
    explicit VSettingDevice(QWidget *parent = nullptr);
    ~VSettingDevice();

private slots:
    void on_pushButton_SearchDevice_clicked();

    void on_pushButton_SetupSN_clicked();

    void on_lineEdit_SerialNumber_textChanged(const QString &arg1);

    void on_pushButton_SN_Exit_clicked();

protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::VSettingDevice *ui;

    QString m_serinumber_new="";

    bool deviceCheckSN(QString sn);
    ESensors *m_esensor = nullptr;

};

#endif // VSETTINGDEVICE_H
