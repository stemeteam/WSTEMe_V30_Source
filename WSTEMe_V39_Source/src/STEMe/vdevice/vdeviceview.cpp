#include "vdeviceview.h"
#include "ui_vdeviceview.h"
#include "vdevice/vlistdevice.h"
#include "vdevice/vdevice.h"
#include "QMessageBox"
#include "QStandardItemModel"

VDeviceView::VDeviceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VDeviceView)
{
    ui->setupUi(this);
    ui->pushButton_RemoveDevice->setEnabled(false);
    ui->pushButton_SelectDevice->setEnabled(false);
    //ui->pushButton_Apply->setEnabled(false);
    VListDevice m_ldev;
    m_listDevice = m_ldev.devices();
    this->refreshTableView();
    this->refreshTableSelect();
}

VDeviceView::~VDeviceView()
{
    delete ui;
}

void VDeviceView::refreshTableView(){
    VListDevice m_ldev;
    QList<VDevice> lst = m_ldev.devices();
    foreach(auto dev,lst){
        if(dev.typeDevice()==VDevice::Sensor){
            m_listDevice.append(dev);
        }
    }
    QStandardItemModel *m_tableView = new QStandardItemModel(ui->tableView_Device);
    QStringList list = {"Thiết bị","Sê-ri"};
    QStandardItem *item;

    for(int i=0;i<list.count();i++){
        item = new QStandardItem(list[i]);
        item->setFont(QFont("Arial",12,QFont::Bold));
        item->setTextAlignment(Qt::AlignCenter);
        m_tableView->setHorizontalHeaderItem(i,item);
    }
    for(int row=0;row<m_listDevice.count();row++){
            item = new QStandardItem(m_listDevice[row].name());
            item->setTextAlignment(Qt::AlignCenter);
            m_tableView->setItem(row,0,item);
            item = new QStandardItem(m_listDevice[row].serialNumber());
            item->setTextAlignment(Qt::AlignCenter);
            m_tableView->setItem(row,1,item);
    }
    ui->tableView_Device->setModel(m_tableView);
    ui->tableView_Device->setColumnWidth(0,300);
    ui->tableView_Device->setColumnWidth(1,160);
}

void VDeviceView::refreshTableSelect()
{
    QStandardItemModel *m_tableViewSelect = new QStandardItemModel(ui->tableView_Select);
    QStringList list = {"Thiết bị","Sê-ri"};
    QStandardItem *item;

    for(int i=0;i<list.count();i++){
        item = new QStandardItem(list[i]);
        item->setFont(QFont("Arial",12,QFont::Bold));
        item->setTextAlignment(Qt::AlignCenter);
        m_tableViewSelect->setHorizontalHeaderItem(i,item);
    }
    for(int row=0;row<m_listDeviceSelect.count();row++){
            item = new QStandardItem(m_listDeviceSelect[row].name());
            item->setTextAlignment(Qt::AlignCenter);
            m_tableViewSelect->setItem(row,0,item);
            item = new QStandardItem(m_listDeviceSelect[row].serialNumber());
            item->setTextAlignment(Qt::AlignCenter);
            m_tableViewSelect->setItem(row,1,item);
    }
    ui->tableView_Select->setModel(m_tableViewSelect);
    ui->tableView_Select->setColumnWidth(0,300);
    ui->tableView_Select->setColumnWidth(1,160);
}

bool VDeviceView::checkDevice(VDevice dev, QList<VDevice> listDevice) const
{
    if(listDevice.isEmpty())return false;
    for(int i=0;i<listDevice.count();i++){
        if(QString::compare(listDevice[i].serialNumber(),dev.serialNumber(),Qt::CaseSensitive)==0)return true;
    }
    return false;
}

void VDeviceView::on_tableView_Device_pressed(const QModelIndex &index)
{
    m_deviceSelect = m_listDevice[index.row()];
    ui->pushButton_RemoveDevice->setEnabled(false);
    ui->pushButton_SelectDevice->setEnabled(true);
}

void VDeviceView::on_pushButton_SelectDevice_clicked()
{
    if(this->checkDevice(m_deviceSelect,m_listDeviceSelect)){
        QMessageBox::warning(this,"Chọn thiết bị","Thiết bị đã có trong danh sách được chọn.",QMessageBox::Ok);
        return;
    }
    m_listDeviceSelect.append(m_deviceSelect);
    this->refreshTableSelect();
    ui->pushButton_SelectDevice->setEnabled(false);
    ui->pushButton_Apply->setEnabled(true);
}

void VDeviceView::on_pushButton_RemoveDevice_clicked()
{
    m_listDeviceSelect.removeAt(m_indexSelect);
    this->refreshTableSelect();
    ui->pushButton_RemoveDevice->setEnabled(false);
    if(m_listDeviceSelect.count()<1)ui->pushButton_Apply->setEnabled(false);
}

void VDeviceView::on_pushButton_Cancel_clicked()
{
    this->close();
}

void VDeviceView::on_tableView_Select_pressed(const QModelIndex &index)
{
    m_indexSelect = index.row();
    ui->pushButton_RemoveDevice->setEnabled(true);
    ui->pushButton_SelectDevice->setEnabled(false);
}

void VDeviceView::on_pushButton_Apply_clicked()
{
    this->refreshTableView();
}
