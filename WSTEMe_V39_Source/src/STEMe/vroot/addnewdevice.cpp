#include "addnewdevice.h"
#include "ui_addnewdevice.h"
#include <QSettings>
#include <QDebug>
#include "QMessageBox"
#include "QStandardItemModel"
#include "dialogshowicon.h"
#include "vdevice/vlistdevice.h"
#include "vfile/vfile.h"



////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................

void AddNewDevice::modbusRequestInputRegisters()
{
    QModbusDataUnit frameRead(QModbusDataUnit::InputRegisters,0,3);
    VNetworkDataUnit _netUnit;
    _netUnit.setModbusDataUnit(frameRead);
    _netUnit.setAddress(127);
    _netUnit.setRequestType(VNetworkDataUnit::Read);
    m_esensor->setSensorRequest(_netUnit);
}

void AddNewDevice::modbusReadResult(VNetworkDataUnit unit)
{
    if(unit.status()){
        VDevice _dev;
        VListDevice _ldev;
        QList<VDevice> _listDevice = _ldev.devices();
        QString _serial = VDevice::serialNumber(unit.modbusDataUnit().values());
     ui->comboBox_Search->setCurrentText(_serial);
     //Find device in listDevice
     for(int row=0;row<_listDevice.count();row++){
         if(_dev.serialNumber(_listDevice[row].serialNumber(),VDevice::GroupID)==_dev.serialNumber(_serial,VDevice::GroupID)){
             VDevice _dev = _listDevice[row];
              ui->lineEdit_Info_Name->setText(_dev.name());
              switch(_dev.typeDevice()){
              case VDevice::Sensor:ui->comboBox_typeDevice->setCurrentIndex(0);
                  break;
              case VDevice::Module:ui->comboBox_typeDevice->setCurrentIndex(1);
                  break;
              case VDevice::System:ui->comboBox_typeDevice->setCurrentIndex(2);
                  break;
              case VDevice::Setting:ui->comboBox_typeDevice->setCurrentIndex(3);
                  break;
              case VDevice::Root:ui->comboBox_typeDevice->setCurrentIndex(4);
                  break;
              }
              ui->lineEdit_Info_SerialNumber->setText(ui->comboBox_Search->currentText());
              m_SerialNumberForUpdate = ui->comboBox_Search->currentText();
              ui->textEdit_Infor_Description->setText(_dev.description());
              ui->pushButton_Infor_Icon->setIcon(QIcon(_dev.iconPath()));
              m_setIconPath = _dev.iconPath();
              ui->pushButton_Remove->setEnabled(true);
              return;
         }
     }
    }
        else{
            QMessageBox::information(this,"Thiết bị","Lỗi! Không tìm thấy thiết bị. Rút thiết bị ra cắm lại và nhấn vào tìm kiếm.",QMessageBox::Ok);
            }
}


void AddNewDevice::modbusRtuReply(VNetworkDataUnit unit)
{
        if(unit.address()==127)  //check address of device
            {
            if(unit.requestType()==VNetworkDataUnit::Read)this->modbusReadResult(unit);
            }
        ui->pushButton_Search->setEnabled(true);
}


AddNewDevice::AddNewDevice(QWidget *parent) :QWidget(parent),ui(new Ui::AddNewDevice)
    {
    ui->setupUi(this);
    ui->pushButton_Remove->setEnabled(false);
    ui->pushButton_Update->setEnabled(false);
    ui->pushButton_AddDevice->setEnabled(false);
    m_esensor = new ESensors();
    connect(m_esensor,&ESensors::on_sensorReply,this,&AddNewDevice::modbusRtuReply);
    //this->refreshTableView();
    }

AddNewDevice::~AddNewDevice()
{
    delete ui;
}

void AddNewDevice::setUserAccount(VUser user)
{
    m_user = user;
     this->refreshTableView();
}

void AddNewDevice::on_SelectIcon(QIcon icon,QString iconPath)
{
    ui->pushButton_Infor_Icon->setIcon(icon);
   // ui->pushButton_Infor_Icon->setIconSize(QSize(ui->pushButton_Infor_Icon->width(),ui->pushButton_Infor_Icon->height()));
    m_setIconPath = iconPath;


}

void AddNewDevice::refreshTableView(){
    VListDevice _ldev;
    QList<VDevice> _listDevice = _ldev.devices();
    QStandardItemModel *tableViewModel = new QStandardItemModel(ui->tableView_Device);
    QStringList list = {"Thiết bị","Sê-ri"};
    QStandardItem *item;

    for(int i=0;i<list.count();i++){
        item = new QStandardItem(list[i]);
        item->setFont(QFont("Arial",12,QFont::Bold));
        item->setTextAlignment(Qt::AlignCenter);
        tableViewModel->setHorizontalHeaderItem(i,item);
       // tableViewModel->setHeaderData(i,Qt::Horizontal,QVariant(Qt::AlignCenter));


    }
    for(int row=0;row<_listDevice.count();row++){
        item = new QStandardItem(_listDevice[row].name());
        item->setTextAlignment(Qt::AlignCenter);
        tableViewModel->setItem(row,0,item);
        if(m_user.accountType()!=VUser::root&&_listDevice[row].typeDevice()==VDevice::Root){
            item = new QStandardItem("************");
            item->setTextAlignment(Qt::AlignCenter);
        }
        else {
            item = new QStandardItem(_listDevice[row].serialNumber());
            item->setTextAlignment(Qt::AlignCenter);
        }
        tableViewModel->setItem(row,1,item);
    }
    ui->tableView_Device->setModel(tableViewModel);
    ui->tableView_Device->setColumnWidth(0,300);
    ui->tableView_Device->setColumnWidth(1,160);
}

void AddNewDevice::on_pushButton_Cancel_clicked()
{
    this->close();
}

void AddNewDevice::on_pushButton_AddDevice_clicked()
{
    VDevice _dev;   
    if(m_user.accountType()!=VUser::root&&ui->comboBox_typeDevice->currentIndex()==4){
        QMessageBox::information(this,"Thiết bị","Lỗi. Chỉ có tài khoản \"Root\" mới được chỉnh sửa loại thiết bị \"Quản lý\".",QMessageBox::Ok);
        return;
    }

    //Check user

    _dev.setName(ui->lineEdit_Info_Name->text());
    switch(ui->comboBox_typeDevice->currentIndex()){
    case 0:_dev.setType("Sensor");
        break;
    case 1:_dev.setType("Module");
        break;
    case 2:_dev.setType("System");
        break;
    case 3:_dev.setType("Setting");
        break;
    case 4:_dev.setType("Root");
        break;
    }
    _dev.setObjectName("vdevice" + ui->comboBox_Search->currentText());
    _dev.setIconPath(m_setIconPath);
    _dev.setDescription(ui->textEdit_Infor_Description->toPlainText());
    _dev.setAddress(127);
    _dev.setSerialNumber(ui->comboBox_Search->currentText());
    QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr, "Thiết bị",
                                                             tr("Bạn có chắc chắn muốn thêm thiết bị mới không?\n"),QMessageBox::No | QMessageBox::Yes,
                                                             QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
     VListDevice _listDevice;
     if(_listDevice.append(_dev)){
         QMessageBox::information(this,"Thiết bị","Thiết bị với sê-ri " + _dev.serialNumber() + "đã được thêm vào thành công.",QMessageBox::Ok);
         this->refreshTableView();
         ui->pushButton_AddDevice->setEnabled(false);
         emit this->signalAddNewDevice();
     }
     else QMessageBox::information(this,"Thiết bị","Đã có lỗi xảy ra! Thiết bị với sê-ri " + _dev.serialNumber() + "đã có trong cơ sở dữ liệu.",QMessageBox::Ok);

 }

}

void AddNewDevice::on_tableView_Device_entered(const QModelIndex &)
{
   // QMessageBox::information(this,"infor",QString::number(index.column()),QMessageBox::Ok);
}

void AddNewDevice::on_tableView_Device_pressed(const QModelIndex &index)
{
      VListDevice _listDevice;
      VDevice _dev = _listDevice.device(index.row());
       ui->lineEdit_Info_Name->setText(_dev.name());
       switch(_dev.typeDevice()){
       case VDevice::Sensor:ui->comboBox_typeDevice->setCurrentIndex(0);
           break;
       case VDevice::Module:ui->comboBox_typeDevice->setCurrentIndex(1);
           break;
       case VDevice::System:ui->comboBox_typeDevice->setCurrentIndex(2);
           break;
       case VDevice::Setting:ui->comboBox_typeDevice->setCurrentIndex(3);
           break;
       case VDevice::Root:ui->comboBox_typeDevice->setCurrentIndex(4);
           break;
       }
       if(m_user.accountType()!=VUser::root&&_dev.typeDevice()==VDevice::Root){
            ui->lineEdit_Info_SerialNumber->setText("************");
       }
       else{
           ui->lineEdit_Info_SerialNumber->setText(_dev.serialNumber());
       }
       m_SerialNumberForUpdate = _dev.serialNumber();
       ui->textEdit_Infor_Description->setText(_dev.description());
       ui->pushButton_Infor_Icon->setIcon(QIcon(_dev.iconPath()));
       //ui->pushButton_Infor_Icon->setIconSize(QSize(ui->pushButton_Infor_Icon->width(),ui->pushButton_Infor_Icon->height()));
       m_setIconPath = _dev.iconPath();
       ui->pushButton_Remove->setEnabled(true);
}







void AddNewDevice::on_comboBox_Search_editTextChanged(const QString &arg1)
{
    if(arg1.count()==12){
        VDevice _dev;
        _dev.setSerialNumber(arg1);
        quint32 _groupID = _dev.serialNumber(VDevice::GroupID);
        quint32 _deviceID = _dev.serialNumber(VDevice::DeviceID);
        QMessageBox::information(this,"Tìm kiếm thiết bị","Số sê-ri hợp lệ. Nhấn \"Thêm mới\" để thêm thiết bị vào phần mềm.",QMessageBox::Ok);
        if(_groupID>0&&_deviceID>0){
            ui->label_search->setText("Số Sê-ri hợp lệ. Nhấn \"Search\" để tìm thiết bị.");
            ui->pushButton_Search->setEnabled(true);
            ui->pushButton_getSerialFromSearch->setEnabled(true);
            //searching device is here!
            ui->pushButton_AddDevice->setEnabled(true);
            //add new device
            }
    }
    else{
        if(arg1.count()==0){
            ui->label_search->setText("Nhập số sê-ri của thiết bị");
        }
        else ui->label_search->setText("Số Sê-ri không hợp lệ!");
        ui->pushButton_Search->setEnabled(false);
        ui->pushButton_getSerialFromSearch->setEnabled(false);
        ui->pushButton_AddDevice->setEnabled(false);
    }
}

void AddNewDevice::on_pushButton_Remove_clicked()
{
    VDevice _dev;
    VListDevice _listDevice;
    _dev = _listDevice.device(ui->lineEdit_Info_SerialNumber->text());
    if(m_user.accountType()!=VUser::root&&_dev.typeDevice()==VDevice::Root){
        QMessageBox::information(this,"Thiết bị","Lỗi. Chỉ có tài khoản \"Root\" mới được chỉnh sửa loại thiết bị \"Quản lý\".",QMessageBox::Ok);
        return;
    }
    _dev.setSerialNumber(ui->lineEdit_Info_SerialNumber->text());
QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr, "Thiết bị",
                                                             tr("Bạn có chắc chắn muốn xóa thiết bị không?\n"),QMessageBox::No | QMessageBox::Yes,
                                                             QMessageBox::Yes);
 if (resBtn == QMessageBox::Yes) {
     if(_listDevice.remove(_dev)){
         QMessageBox::information(this,"Xóa thiết bị.","Thiết bị với sê-ri " + _dev.serialNumber() + "đã được xóa thành công.",QMessageBox::Ok);
         this->refreshTableView();
         emit this->signalAddNewDevice();
     }
     else QMessageBox::information(this,"Xóa thiết bị.","Đã có lỗi xảy ra! Thiết bị với sê-ri " + _dev.serialNumber()  + "không có trong cơ sở dữ liệu.",QMessageBox::Ok);
 }
}

void AddNewDevice::on_pushButton_Infor_Icon_clicked()
{
    DialogShowIcon *dialogIcon = new DialogShowIcon(this);
    connect(dialogIcon,&DialogShowIcon::signal_SelectIcon,this,&AddNewDevice::on_SelectIcon);
    dialogIcon->show();

}

void AddNewDevice::on_pushButton_Update_clicked()
{
    VDevice _dev;
    VListDevice _listDevice;
    _dev = _listDevice.device(ui->lineEdit_Info_SerialNumber->text());
    if(m_user.accountType()!=VUser::root&&_dev.typeDevice()==VDevice::Root){
        QMessageBox::information(this,"Thiết bị","Lỗi. Chỉ có tài khoản \"Root\" mới được chỉnh sửa loại thiết bị \"Quản lý\".",QMessageBox::Ok);
        return;
    }
    _dev.setName(ui->lineEdit_Info_Name->text());
    switch(ui->comboBox_typeDevice->currentIndex()){
    case 0:_dev.setType("Sensor");
        break;
    case 1:_dev.setType("Module");
        break;
    case 2:_dev.setType("System");
        break;
    case 3:_dev.setType("Setting");
        break;
    case 4:_dev.setType("Root");
        break;
    }
    _dev.setObjectName("vdevice" + ui->lineEdit_Info_SerialNumber->text());
    _dev.setIconPath(m_setIconPath);
    _dev.setDescription(ui->textEdit_Infor_Description->toPlainText());
    _dev.setAddress(127);
    _dev.setSerialNumber(m_SerialNumberForUpdate);
    QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr, "Sửa thiết bị",
                                                             tr("Bạn có chắc chắn muốn sửa thông tin thiết bị không?\n"),QMessageBox::No | QMessageBox::Yes,
                                                             QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
     if(_listDevice.update(_dev,ui->lineEdit_Info_SerialNumber->text())){
         QMessageBox::information(this,"Sửa thiết bị.","Thiết bị với sê-ri " + ui->lineEdit_Info_SerialNumber->text() + " đã được cập nhật thành công.",QMessageBox::Ok);
         this->refreshTableView();
         ui->pushButton_Update->setEnabled(false);
         emit this->signalAddNewDevice();
     }
     else QMessageBox::information(this,"Sửa thiết bị.","Đã có lỗi xảy ra! Thiết bị với sê-ri " + _dev.serialNumber() + "không có trong cơ sở dữ liệu.",QMessageBox::Ok);

 }
}

void AddNewDevice::on_lineEdit_Info_SerialNumber_textChanged(const QString &arg1)
{
    if(arg1.count()==12){
        VDevice _dev;
        _dev.setSerialNumber(arg1);
        quint32 _groupID = _dev.serialNumber(VDevice::GroupID);
        quint32 _deviceID = _dev.serialNumber(VDevice::DeviceID);
        if(_groupID>0&&_deviceID>0){
            ui->pushButton_Update->setEnabled(true);
            }
        else {
            QMessageBox::information(this,"Thêm thiết bị.","Đã có lỗi xảy ra! Thiết bị với sê-ri " + _dev.serialNumber()  + "không tồn tại.",QMessageBox::Ok);
        }
    }
    else{
        ui->pushButton_Update->setEnabled(false);
    }
}

void AddNewDevice::on_pushButton_Search_clicked()
{
ui->pushButton_Search->setEnabled(false);
this->modbusRequestInputRegisters();
}

void AddNewDevice::on_pushButton_getSerialFromSearch_clicked()
{
    ui->lineEdit_Info_SerialNumber->setText(ui->comboBox_Search->currentText());
}

void AddNewDevice::on_pushButton_ListDevice_Save_clicked()
{
    VFile file;
    VListDevice listDev;
    QList<VDevice> list = listDev.devices();
    file.saveDevices(list);
}

void AddNewDevice::on_pushButton_ListDevice_Replace_clicked()
{
    VFile file;
    VListDevice listDev;
    QList<VDevice> list = file.loadDevices();
    if(file.fileName()=="")return;
    if(list.isEmpty()){
        QMessageBox::information(this,"Tải danh sách mới","Đã có lỗi. Không có thiết bị trong danh sách hoặc tệp danh sách không đúng định dạng!",QMessageBox::Ok);
        return;
    }
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Tải danh sách mới",
                                                             tr("Tải danh sách mới sẽ xóa đi toàn bộ danh sách cũ, bạn có chắc chắn muốn tải danh sách mới khồng?\n"),QMessageBox::No | QMessageBox::Yes,
                                                             QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        listDev.setDevices(list);
        this->refreshTableView();
        emit this->signalAddNewDevice();
    }
}

void AddNewDevice::on_pushButton_ListDevice_Update_clicked()
{
    VFile file;
    VListDevice listDev;
    QList<VDevice> list = file.loadDevices();
    if(file.fileName()=="")return;
    if(list.isEmpty()){
        QMessageBox::information(this,"Cập nhật danh sách","Đã có lỗi. Không có thiết bị trong danh sách hoặc tệp danh sách không đúng định dạng!",QMessageBox::Ok);
        return;
    }
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Cập nhật danh sách",
                                                             tr("Cập nhật danh sách sẽ thêm vào danh sách cũ những thiết bị từ danh sách mới, bạn có chắc chắn muốn cập nhật khồng?\n"),QMessageBox::No | QMessageBox::Yes,
                                                             QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        foreach(auto element,list){
            if(!listDev.contains(element))listDev.append(element);
        }
        this->refreshTableView();
        emit this->signalAddNewDevice();
    }
}

void AddNewDevice::closeEvent(QCloseEvent *event)
{
    m_esensor->deleteLater();
    event->accept();
}
