#ifndef ADDNEWDEVICE_H
#define ADDNEWDEVICE_H

#include <QWidget>
#include "QStandardItemModel"
#include <QCloseEvent>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/esensors.h>
#include <vlogin/vuser.h>

namespace Ui {
class AddNewDevice;
}

class AddNewDevice : public QWidget
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

public:
    explicit AddNewDevice(QWidget *parent = nullptr);
    ~AddNewDevice();
        void setUserAccount(VUser user);


public: signals:
    void signalAddNewDevice();

private slots:
    void on_SelectIcon(QIcon icon,QString iconPath);
    void on_pushButton_Cancel_clicked();

    void on_pushButton_AddDevice_clicked();

    void on_tableView_Device_entered(const QModelIndex &index);

    void on_tableView_Device_pressed(const QModelIndex &index);

    void on_comboBox_Search_editTextChanged(const QString &arg1);

    void on_pushButton_Remove_clicked();

    void on_pushButton_Infor_Icon_clicked();

    void on_pushButton_Update_clicked();

    void on_lineEdit_Info_SerialNumber_textChanged(const QString &arg1);

    void on_pushButton_Search_clicked();

    void on_pushButton_getSerialFromSearch_clicked();

    void on_pushButton_ListDevice_Save_clicked();

    void on_pushButton_ListDevice_Replace_clicked();

    void on_pushButton_ListDevice_Update_clicked();
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::AddNewDevice *ui;
    VUser m_user;
    void refreshTableView();
    QString m_setIconPath="";

    QString m_SerialNumberForUpdate="";
    ESensors *m_esensor = nullptr;
};

#endif // ADDNEWDEVICE_H
