#include "vsettingdevice.h"
#include "ui_vsettingdevice.h"

#include <QSettings>
#include <QDebug>
#include "QMessageBox"
#include "QStandardItemModel"
#include "dialogshowicon.h"
#include "vdevice/vlistdevice.h"
////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................

void VSettingDevice::modbusRequestInputRegisters()
{
    QModbusDataUnit frameRead(QModbusDataUnit::InputRegisters,0,3);
    VNetworkDataUnit _netUnit;
    _netUnit.setModbusDataUnit(frameRead);
    _netUnit.setAddress(127);
    _netUnit.setRequestType(VNetworkDataUnit::Read);
    m_esensor->setSensorRequest(_netUnit);
}

void VSettingDevice::modbusReadResult(VNetworkDataUnit unit)
{
    if(unit.status()){
        QString _serial = VDevice::serialNumber(unit.modbusDataUnit().values());
        if(this->deviceCheckSN(_serial))ui->lineEdit_SerialNumber->setText(_serial);
    }
        else{
            QMessageBox::information(this,"Thiết bị","Lỗi! Không tìm thấy thiết bị. Rút thiết bị ra cắm lại và nhấn vào tìm kiếm.",QMessageBox::Ok);
    }
}

void VSettingDevice::modbusSetSerialNumber(QString serial)
{
  QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,0xFF00,4);
  VNetworkDataUnit _netUnit;
  QVector<quint16> sn = {0,0,0,0xFFFF};
  VDevice _device;
  _device.setSerialNumber(serial);
  sn[0] = QString::number(_device.serialNumber(VDevice::GroupID)).toUShort();
  sn[1] = QString::number((_device.serialNumber(VDevice::DeviceID)>>16)&0xFFFF).toUShort();
  sn[2] = QString::number(_device.serialNumber(VDevice::DeviceID)&0xFFFF).toUShort();

  unit.setValues(sn);
  _netUnit.setModbusDataUnit(unit);
  _netUnit.setAddress(127);
 _netUnit.setRequestType(VNetworkDataUnit::Write);
 m_esensor->setSensorRequest(_netUnit);
}


void VSettingDevice::modbusRtuReply(VNetworkDataUnit unit)
{
        if(unit.address()==127)  //check address of device
            {
            if(unit.requestType()==VNetworkDataUnit::Read)this->modbusReadResult(unit);
            else{
                if(unit.status()){
                    QMessageBox::information(this,"Cài đặt S/N.","Mã quản lý thiết bị với S/N = " + m_serinumber_new  + "\n đã được cài đặt.",QMessageBox::Ok);

                    if(ui->checkBox_SN_Increase->isChecked()){
                        VDevice _dev;
                        ui->lineEdit_SerialNumber->setText(_dev.serialNumberIncrease(m_serinumber_new));
                    }
                }
                else{
                    QMessageBox::warning(this,"Cài đặt S/N.","Lỗi kết nối! Không thể cài đặt S/N = " + m_serinumber_new  + "\n xuống thiết bị. \n   - Kiểm tra kết nối hoặc rút thiết bị ra kết nối lại!",QMessageBox::Ok);
                }
            }
            }
        ui->pushButton_SearchDevice->setEnabled(true);
}




VSettingDevice::VSettingDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VSettingDevice)
{
    ui->setupUi(this);
    ui->pushButton_SetupSN->setEnabled(false);
    m_esensor = new ESensors();
    connect(m_esensor,&ESensors::on_sensorReply,this,&VSettingDevice::modbusRtuReply);
}

VSettingDevice::~VSettingDevice()
{
    delete ui;
}

void VSettingDevice::on_pushButton_SearchDevice_clicked()
{
    ui->pushButton_SearchDevice->setEnabled(false);
    this->modbusRequestInputRegisters();
}

void VSettingDevice::on_pushButton_SetupSN_clicked()
{
    if(m_serinumber_new==""){
        QMessageBox::information(this,"Cài đặt S/N.","Đã có lỗi xảy ra! Thiết bị với sê-ri \"" + m_serinumber_new  + "\"không tồn tại.",QMessageBox::Ok);
    }
    else{
        QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr, "Cài đặt S/N.",
                                                                     tr("Cài đặt S/N là thay đổi mã định danh của thiết bị. \n\r Bạn có chắc chắn muốn tiếp tục cài đặt không ?"),QMessageBox::No | QMessageBox::Yes,
                                                                     QMessageBox::Yes);
         if (resBtn == QMessageBox::Yes) {
             this->modbusSetSerialNumber(m_serinumber_new);
             ui->pushButton_SetupSN->setEnabled(false);
         }
    }
}

void VSettingDevice::on_lineEdit_SerialNumber_textChanged(const QString &arg1)
{
    if(arg1.count()<4)ui->label_SN_setG->setText("G ("+QString::number(arg1.count())+")");
    else{
       ui->label_SN_setG->setText("G (4)");
       ui->label_SN_setD->setText("D ("+QString::number(arg1.count()-4)+")");
    }
    if(arg1.count()==12){
        ui->label_SN_setG->setStyleSheet("color: rgb(0, 85, 255);");
        ui->label_SN_setG->setStyleSheet("color: rgb(0, 85, 255);");
         this->deviceCheckSN(arg1);
    }
    else{
        ui->label_SN_setG->setStyleSheet("color: rgb(0, 85, 0);");
        ui->label_SN_setG->setStyleSheet("color: rgb(170, 0, 0);");
        ui->label_SN_Info->setText("Nhập mã (12 kí tự) hoặc nhấn \"Tìm thiết bị\".");
        ui->label_SN_Info->setStyleSheet("color: rgb(255, 0, 0);");
        m_serinumber_new = "";
        ui->pushButton_SetupSN->setEnabled(false);
    }
}

void VSettingDevice::on_pushButton_SN_Exit_clicked()
{
    this->close();
}

void VSettingDevice::closeEvent(QCloseEvent *event)
{
    m_esensor->deleteLater();
    event->accept();
}

bool VSettingDevice::deviceCheckSN(QString sn)
{
    VDevice _dev;
    VListDevice _ldev;
    QList<VDevice> _listDevice = _ldev.devices();
    _dev.setSerialNumber(sn);
    quint32 _groupID = _dev.serialNumber(VDevice::GroupID);
    quint32 _deviceID = _dev.serialNumber(VDevice::DeviceID);
    if(_groupID>0&&_deviceID>0){
         //Find device in listDevice
         for(int row=0;row<_listDevice.count();row++){
             if(_dev.serialNumber(_listDevice[row].serialNumber(),VDevice::GroupID)==_dev.serialNumber(sn,VDevice::GroupID)){
                 VDevice _dev = _listDevice[row];
                  ui->label_SN_Info->setText("G - " + _dev.serialNumberGroup(sn) + ": " + _dev.name());
                  ui->label_SN_Info->setStyleSheet("color: rgb(0, 85, 255);");
                break;
             }
             else{
                 ui->label_SN_Info->setText("Tìm thấy một thiết bị mới chưa có trong danh sách.");
                 ui->label_SN_Info->setStyleSheet("color: rgb(0, 170, 0);");
             }
         }
         m_serinumber_new = sn;
         ui->pushButton_SetupSN->setEnabled(true);
         return true;
        }
    else {
        QMessageBox::information(this,"Thêm thiết bị.","Đã có lỗi xảy ra! Thiết bị với sê-ri " + sn  + "không đúng. \n\r    - Xem phần chú ý bên dưới!",QMessageBox::Ok);
    }
    return false;
}
