//system
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QList>
#include <QStringList>
#include <QFrame>
#include <QRadioButton>
#include <QLayout>
#include <QDebug>

//User's class
#include "vcommunication/vcommunicationmodbus.h"
#include "vroot/vbuttonsingle.h"
#include "esensor/esensors.h"
//#include "addnewdevice.h"


int MainWindow::mainWindow_Width=1280;
int MainWindow::mainWindow_Height=800;
int MainWindow::mainWindow_LocalX=0;
int MainWindow::mainWindow_LocalY=60;


QColor MainWindow::VBackgroud_Color = QColor("#132635");
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vcomModbus = new VCommunicationModbus(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  rec = screen->geometry();
    this->setGeometry((rec.width()-this->width())/2,(rec.height()-this->height())/2,this->width(),this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Refresh()
{
    this->refreshFrameWidget();
}

void MainWindow::setUserLogin(VUser user)
{
            m_userLogin = user;
            ui->label_User_Account->setText("Tài khoản: " + m_userLogin.account());
            switch (m_userLogin.accountType()) {
            case VUser::UserType::root:ui->label_User_Type->setText("Người dùng: Root");
                break;
            case VUser::UserType::teacher:ui->label_User_Type->setText("Người dùng: Teacher");
                break;
            case VUser::UserType::student:ui->label_User_Type->setText("Người dùng: Student");
                break;
            }


}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có muốn thoát khỏi phần mềm \'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() != QMessageBox::Yes) {
         event->ignore();
     } else {
         if(m_frmSEN0101)m_frmSEN0101->deleteLater();
         if(m_frmSEN0102)m_frmSEN0102->deleteLater();
         if(m_frmSEN0103)m_frmSEN0103->deleteLater();
         if(m_frmSEN0104)m_frmSEN0104->deleteLater();
         if(m_frmSEN0105)m_frmSEN0105->deleteLater();
         if(m_frmSEN0106)m_frmSEN0106->deleteLater();
         if(m_frmSEN0107)m_frmSEN0107->deleteLater();
         if(m_frmSEN0108)m_frmSEN0108->deleteLater();
         if(m_frmSEN0109)m_frmSEN0109->deleteLater();
         if(m_frmSEN0110)m_frmSEN0110->deleteLater();
         if(m_frmSEN0111)m_frmSEN0111->deleteLater();
         if(m_frmSEN0112)m_frmSEN0112->deleteLater();
         if(m_frmSEN0113)m_frmSEN0113->deleteLater();
         if(m_frmSEN0114)m_frmSEN0114->deleteLater();
         if(m_frmSEN0115)m_frmSEN0115->deleteLater();
         if(m_frmSEN0116)m_frmSEN0116->deleteLater();
         if(m_frmSEN0120)m_frmSEN0120->deleteLater();
         if(m_frmSEN0121)m_frmSEN0121->deleteLater();
         if(m_frmSEN0150)m_frmSEN0150->deleteLater();
         if(m_frmSEN0151)m_frmSEN0151->deleteLater();
         if(m_frmSEN0132)m_frmSEN0132->deleteLater();
         if(m_frmMOD1101)m_frmMOD1101->deleteLater();
         if(m_frmMOD1103)m_frmMOD1103->deleteLater();
         event->accept();
        this->close();
     }
}

bool MainWindow::reConnectModbus()
{
    ESensors::modbusDisconnect();
    ESensors::setModbusPort(m_namePort);
    if(!ESensors::modbusConnect()){
        QMessageBox::warning(nullptr,"VDAT: Lỗi kết nối!","Phần mềm đang chạy hoặc các kết nối chưa đúng. Kiểm tra và chạy lại chương trình!",QMessageBox::Ok);
        return false;
    }
    return true;
}

void MainWindow::on_AddNewDevice()
{
    this->refreshFrameWidget();
}

void MainWindow::deleteWidgetAvailable(VDevice dev)
{
//if(widget)delete widget;
  VDevice check;

foreach (auto element,VDevice::deviceWidgetInstances){
    if(QString::compare(element->objectName(),dev.serialNumber(),Qt::CaseSensitive)==0)delete element;
    else{
       if(dev.serialNumber(element->objectName(),VDevice::GroupID)==dev.serialNumber(dev.serialNumber(),VDevice::GroupID))element->activateWindow();
    }
}
}

void MainWindow::on_vbuttonSigle_Clicked(VDevice dev)
{
    // serialNumber =  0x      f              ff             fffff
    // comment              Groups       type of device       No.

    //==============================================================
    //.........................Groups...............................
    //  0x00:           Connectors, networks, switch...
    //  0x01:            Sensors
    //.........................type of device.......................
    //  0x01            Temperature sensors
    //
    //..........................No..................................
    //  0xfffff = 1.048.575 devices is maximum
   // QMessageBox::information(this,"info",dev.serialNumber(),QMessageBox::Ok);
    m_vdev = dev;
    VDevice::DeviceGroup serialNumberGroup = dev.group();//get "groups" and "type of device"
    this->deleteWidgetAvailable (dev);
    switch (serialNumberGroup) {
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////    SOFTWARE   /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case VDevice::GSoftwareAccount:
            if(m_frmUserAccount) delete m_frmUserAccount;
            m_frmUserAccount = new FormUserAccount();
            m_frmUserAccount->setUserAccount(m_userLogin);
            m_frmUserAccount->setGeometry(this->getLocal_X(m_frmUserAccount->width()),\
                                  this->getLocal_Y(m_frmUserAccount->height()),m_frmUserAccount->width(),m_frmUserAccount->height());
            m_frmUserAccount->show();
            break;
        case VDevice::GSoftwareAddDevice:
            if(m_frmAddNewDevice)delete m_frmAddNewDevice;
            m_frmAddNewDevice = new AddNewDevice();
            m_frmAddNewDevice->setUserAccount(m_userLogin);
            connect(m_frmAddNewDevice,&AddNewDevice::signalAddNewDevice,this,&MainWindow::on_AddNewDevice);
            connect(vcomModbus,&VCommunicationModbus::modbusRtuReply,m_frmAddNewDevice,&AddNewDevice::modbusRtuReply);
            connect(m_frmAddNewDevice,&AddNewDevice::modbusRtuRequest,vcomModbus,&VCommunicationModbus::modbusRtuRequest);
            m_frmAddNewDevice->setGeometry(this->getLocal_X(m_frmAddNewDevice->width()),\
                                      this->getLocal_Y(m_frmAddNewDevice->height()),m_frmAddNewDevice->width(),m_frmAddNewDevice->height());
            m_frmAddNewDevice->show();
            break;
        case VDevice::GSoftwareSetting:
            if(m_frmsettingDevice)delete m_frmsettingDevice;
            m_frmsettingDevice = new VSettingDevice();
            connect(m_frmsettingDevice,&VSettingDevice::signalAddNewDevice,this,&MainWindow::on_AddNewDevice);
            connect(vcomModbus,&VCommunicationModbus::modbusRtuReply,m_frmsettingDevice,&VSettingDevice::modbusRtuReply);
            connect(m_frmsettingDevice,&VSettingDevice::modbusRtuRequest,vcomModbus,&VCommunicationModbus::modbusRtuRequest);
            m_frmsettingDevice->setGeometry(this->getLocal_X(m_frmsettingDevice->width()),\
                                      this->getLocal_Y(m_frmsettingDevice->height()),m_frmsettingDevice->width(),m_frmsettingDevice->height());
            m_frmsettingDevice->show();
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////    SENSORS   /////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case VDevice::GSensorSEN0101:
        if(m_frmSEN0101)delete m_frmSEN0101;
        m_frmSEN0101 = new Sensor_SEN0101();
        m_frmSEN0101->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0101->setGeometry(this->getLocal_X(m_frmSEN0101->width()),\
                                      this->getLocal_Y(m_frmSEN0101->height()),m_frmSEN0101->width(),m_frmSEN0101->height());
        m_frmSEN0101->show();
        break;
    case VDevice::GSensorSEN0102:
        if(m_frmSEN0102)delete m_frmSEN0102;
        m_frmSEN0102 = new Sensor_SEN0102();
        m_frmSEN0102->setDeviceWidget(dev,m_userLogin);

        m_frmSEN0102->setGeometry(this->getLocal_X(m_frmSEN0102->width()),\
                                      this->getLocal_Y(m_frmSEN0102->height()),m_frmSEN0102->width(),m_frmSEN0102->height());
        m_frmSEN0102->show();
        break;
    case VDevice::GSensorSEN0103:
        if(m_frmMSG1101)delete m_frmMSG1101;
        m_frmMSG1101 = new Module_Msg1101();
        m_frmMSG1101->setRadioButton(Module_Msg1101::MSG_SYSTEM_SENSOR);
        connect(m_frmMSG1101,&Module_Msg1101::set_selectModule1101,this,&MainWindow::on_selectModule1101);
        m_frmMSG1101->setGeometry(this->getLocal_X(m_frmMSG1101->width()),\
                                      this->getLocal_Y(m_frmMSG1101->height()),m_frmMSG1101->width(),m_frmMSG1101->height());
        m_frmMSG1101->show();
        break;
    case VDevice::GSensorSEN0104:
        if(m_frmSEN0104)delete m_frmSEN0104;
        m_frmSEN0104 = new Sensor_SEN0104();
        m_frmSEN0104->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0104->setGeometry(this->getLocal_X(m_frmSEN0104->width()),\
                                      this->getLocal_Y(m_frmSEN0104->height()),m_frmSEN0104->width(),m_frmSEN0104->height());
        m_frmSEN0104->show();
        break;
    case VDevice::GSensorSEN0105:
        if(m_frmSEN0105)delete m_frmSEN0105;
        m_frmSEN0105 = new Sensor_SEN0105();
        m_frmSEN0105->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0105->setGeometry(this->getLocal_X(m_frmSEN0105->width()),\
                                      this->getLocal_Y(m_frmSEN0105->height()),m_frmSEN0105->width(),m_frmSEN0105->height());
        m_frmSEN0105->show();
        break;
    case VDevice::GSensorSEN0106:
        if(m_frmSEN0106)delete m_frmSEN0106;
        m_frmSEN0106 = new Sensor_SEN0106();
        m_frmSEN0106->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0106->setGeometry(this->getLocal_X(m_frmSEN0106->width()),\
                                      this->getLocal_Y(m_frmSEN0106->height()),m_frmSEN0106->width(),m_frmSEN0106->height());
        m_frmSEN0106->show();
        break;
    case VDevice::GSensorSEN0107:
        if(m_frmSEN0107)delete m_frmSEN0107;
        m_frmSEN0107 = new Sensor_SEN0107();
        m_frmSEN0107->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0107->setGeometry(this->getLocal_X(m_frmSEN0107->width()),\
                                      this->getLocal_Y(m_frmSEN0107->height()),m_frmSEN0107->width(),m_frmSEN0107->height());
        m_frmSEN0107->show();
        break;
    case VDevice::GSensorSEN0108:
        if(m_frmSEN0108)delete m_frmSEN0108;
        m_frmSEN0108 = new Sensor_SEN0108();
        m_frmSEN0108->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0108->setGeometry(this->getLocal_X(m_frmSEN0108->width()),\
                                      this->getLocal_Y(m_frmSEN0108->height()),m_frmSEN0108->width(),m_frmSEN0108->height());

        m_frmSEN0108->show();
        break;
    case VDevice::GSensorSEN0109:
        if(m_frmSEN0109)delete m_frmSEN0109;
        m_frmSEN0109 = new Sensor_SEN0109();
        m_frmSEN0109->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0109->setGeometry(this->getLocal_X(m_frmSEN0109->width()),\
                                      this->getLocal_Y(m_frmSEN0109->height()),m_frmSEN0109->width(),m_frmSEN0109->height());
        m_frmSEN0109->show();
        break;
    case VDevice::GSensorSEN0110:
        if(m_frmSEN0110)delete m_frmSEN0110;
        m_frmSEN0110 = new Sensor_SEN0110();
        m_frmSEN0110->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0110->setGeometry(this->getLocal_X(m_frmSEN0110->width()),\
                                  this->getLocal_Y(m_frmSEN0110->height()),m_frmSEN0110->width(),m_frmSEN0110->height());
        m_frmSEN0110->show();
        break;
    case VDevice::GSensorSEN0111:
        if(m_frmSEN0111)delete m_frmSEN0111;
        m_frmSEN0111 = new Sensor_SEN0111();
        m_frmSEN0111->setDeviceWidget(dev);
        m_frmSEN0111->setGeometry(this->getLocal_X(m_frmSEN0111->width()),\
                                  this->getLocal_Y(m_frmSEN0111->height()),m_frmSEN0111->width(),m_frmSEN0111->height());
        m_frmSEN0111->show();
        break;
    case VDevice::GSensorSEN0112:
        if(m_frmSEN0112)delete m_frmSEN0112;
        m_frmSEN0112 = new Sensor_SEN0112();
        m_frmSEN0112->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0112->setGeometry(this->getLocal_X(m_frmSEN0112->width()),\
                                  this->getLocal_Y(m_frmSEN0112->height()),m_frmSEN0112->width(),m_frmSEN0112->height());
        m_frmSEN0112->show();
        break;
    case VDevice::GSensorSEN0113:
        if(m_frmSEN0113)delete m_frmSEN0113;
        m_frmSEN0113 = new Sensor_SEN0113();
        m_frmSEN0113->setDeviceWidget(dev);
        m_frmSEN0113->setGeometry(this->getLocal_X(m_frmSEN0113->width()),\
                                  this->getLocal_Y(m_frmSEN0113->height()),m_frmSEN0113->width(),m_frmSEN0113->height());
        m_frmSEN0113->show();
        break;
    case VDevice::GSensorSEN0114:
        if(m_frmSEN0114)delete m_frmSEN0114;
        m_frmSEN0114 = new Sensor_SEN0114();
        m_frmSEN0114->setDeviceWidget(dev);
        m_frmSEN0114->setGeometry(this->getLocal_X(m_frmSEN0114->width()),\
                                      this->getLocal_Y(m_frmSEN0114->height()),m_frmSEN0114->width(),m_frmSEN0114->height());
        m_frmSEN0114->show();
        break;
    case VDevice::GSensorSEN0115:
        if(m_frmSEN0115)delete m_frmSEN0115;
        m_frmSEN0115 = new Sensor_SEN0115();
        m_frmSEN0115->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0115->setGeometry(this->getLocal_X(m_frmSEN0115->width()),\
                                      this->getLocal_Y(m_frmSEN0115->height()),m_frmSEN0115->width(),m_frmSEN0115->height());
        m_frmSEN0115->show();
        break;
    case VDevice::GSensorSEN0116:
        if(m_frmSEN0116)delete m_frmSEN0116;
        m_frmSEN0116 = new Sensor_SEN0116();
        m_frmSEN0116->setDeviceWidget(dev);
        m_frmSEN0116->setGeometry(this->getLocal_X(m_frmSEN0116->width()),\
                                  this->getLocal_Y(m_frmSEN0116->height()),m_frmSEN0116->width(),m_frmSEN0116->height());
        m_frmSEN0116->show();
        break;
    case VDevice::GSensorSEN0120:
        if(m_frmSEN0120)delete m_frmSEN0120;
        m_frmSEN0120 = new Sensor_SEN0120();
        m_frmSEN0120->setDeviceWidget(dev);
        m_frmSEN0120->setGeometry(this->getLocal_X(m_frmSEN0120->width()),\
                                  this->getLocal_Y(m_frmSEN0120->height()),m_frmSEN0120->width(),m_frmSEN0120->height());
        m_frmSEN0120->show();
        break;
    case VDevice::GSensorSEN0121:
        if(m_frmSEN0121)delete m_frmSEN0121;
        m_frmSEN0121 = new Sensor_SEN0121();
        m_frmSEN0121->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0121->setGeometry(this->getLocal_X(m_frmSEN0121->width()),\
                                  this->getLocal_Y(m_frmSEN0121->height()),m_frmSEN0121->width(),m_frmSEN0121->height());
        m_frmSEN0121->show();
        break;
    case VDevice::GSensorSEN0150:
        if(m_frmSEN0150)delete m_frmSEN0150;
        m_frmSEN0150 = new Sensor_SEN0150();
        m_frmSEN0150->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0150->setGeometry(this->getLocal_X(m_frmSEN0150->width()),\
                                      this->getLocal_Y(m_frmSEN0150->height()),m_frmSEN0150->width(),m_frmSEN0150->height());
        m_frmSEN0150->show();
        break;
    case VDevice::GSensorSEN0151:
        if(m_frmSEN0151)delete m_frmSEN0151;
        m_frmSEN0151 = new Sensor_SEN0151();
        m_frmSEN0151->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0151->setGeometry(this->getLocal_X(m_frmSEN0151->width()),\
                                      this->getLocal_Y(m_frmSEN0151->height()),m_frmSEN0151->width(),m_frmSEN0151->height());
        m_frmSEN0151->show();
        break;
    case VDevice::GSensorSEN0132:
        if(m_frmSEN0132)delete m_frmSEN0132;
        m_frmSEN0132 = new Sensor_SEN0132();
        m_frmSEN0132->setDeviceWidget(dev,m_userLogin);
        m_frmSEN0132->setGeometry(this->getLocal_X(m_frmSEN0132->width()),\
                                      this->getLocal_Y(m_frmSEN0132->height()),m_frmSEN0132->width(),m_frmSEN0132->height());
        m_frmSEN0132->show();
        break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////    MODULE   /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case VDevice::GModuleMOD1101:
        if(m_frmMSG1101)delete m_frmMSG1101;
        m_frmMSG1101 = new Module_Msg1101();
        connect(m_frmMSG1101,&Module_Msg1101::set_selectModule1101,this,&MainWindow::on_selectModule1101);
        m_frmMSG1101->setGeometry(this->getLocal_X(m_frmMSG1101->width()),\
                                      this->getLocal_Y(m_frmMSG1101->height()),m_frmMSG1101->width(),m_frmMSG1101->height());
        m_frmMSG1101->show();
            break;
        case VDevice::GModuleMOD1102:
        if(m_frmMSG1101)delete m_frmMSG1101;
        m_frmMSG1101 = new Module_Msg1101();
        m_frmMSG1101->setRadioButton(Module_Msg1101::MSG_SYSTEM_SPRINGS);
        connect(m_frmMSG1101,&Module_Msg1101::set_selectModule1101,this,&MainWindow::on_selectModule1101);
        m_frmMSG1101->setGeometry(this->getLocal_X(m_frmMSG1101->width()),\
                                      this->getLocal_Y(m_frmMSG1101->height()),m_frmMSG1101->width(),m_frmMSG1101->height());
        m_frmMSG1101->show();
            break;   
    case VDevice::GModuleMOD1103:
        if(m_frmMOD1103)delete m_frmMOD1103;
        m_frmMOD1103 = new Module_MOD1103();
        m_frmMOD1103->setDeviceWidget(dev,m_userLogin);
        m_frmMOD1103->setGeometry(this->getLocal_X(m_frmMOD1103->width()),\
                                  this->getLocal_Y(m_frmMOD1103->height()),m_frmMOD1103->width(),m_frmMOD1103->height());
        m_frmMOD1103->show();
        break;
        case VDevice::GModuleMOD0020:
            if(m_frmMOD0020)delete m_frmMOD0020;
            m_frmMOD0020 = new Module_MOD0020();
            m_frmMOD0020->setDeviceWidget(dev);
            connect(vcomModbus,&VCommunicationModbus::modbusRtuReply,m_frmMOD0020,&Module_MOD0020::modbusRtuReply);
            connect(m_frmMOD0020,&Module_MOD0020::modbusRtuRequest,vcomModbus,&VCommunicationModbus::modbusRtuRequest);
            m_frmMOD0020->setGeometry(this->getLocal_X(m_frmMOD0020->width()),\
                                      this->getLocal_Y(m_frmMOD0020->height()),m_frmMOD0020->width(),m_frmMOD0020->height());
            m_frmMOD0020->show();
            break;
            default:break;
    }
}

void MainWindow::close()
{
    if(vcomModbus)delete this->vcomModbus;
    delete ui;
}

void MainWindow::refreshFrameWidget()
{
    this->setFrameDevice();
}

void MainWindow::setFrameDevice()
{
    VListDevice _listDevice;
    QList<VDevice> _frameDevice = _listDevice.devices();
    VDevice _dev;
    int rowWidget = 0,colunmWidget= 0;
    int uiFrame_Widget = ui->tabWidget->width();
    int uiFrame_Height = ui->tabWidget->height();
    const int iconWidth = 160;
    const int iconHeight = 160;

    //For Sensor frame
    if(vbuttonSingle)delete vbuttonSingle;
    m_frameButtonSensors = new QFrame(ui->tab_Sensors);
    m_frameButtonSensors->setGeometry(2,2,ui->tabWidget->width()-4,ui->tabWidget->height()-4);
    m_frameButtonSensors->show();
    //For Module frame
    m_frameButtonModules = new QFrame(ui->tab_Modules);
    m_frameButtonModules->setGeometry(2,2,ui->tabWidget->width()-4,ui->tabWidget->height()-4);
    m_frameButtonModules->show();
    //For System frame
    m_frameButtonSystems = new QFrame(ui->tab_Systems);
    m_frameButtonSystems->setGeometry(2,2,ui->tabWidget->width()-4,ui->tabWidget->height()-4);
    m_frameButtonSystems->show();
    //For Setting frame
    m_frameButtonSettings = new QFrame(ui->tab_Settings);
    m_frameButtonSettings->setGeometry(2,2,ui->tabWidget->width()-4,ui->tabWidget->height()-4);
    m_frameButtonSettings->show();

    ////////////////////////////////////////////////////////////////////Add more for root and teacher user

    if(this->m_userLogin.accountType()!=VUser::UserType::student)
    {
    //Set widget add newdevice for frame.
    _dev.setName("Cài đặt thiết bị");
    _dev.setType("Root");
    _dev.setObjectName("vdevice000100000000");
    _dev.setIconPath(":/image/DeviceIcon.jpg");
    _dev.setSerialNumber("000100000000");
    _frameDevice.push_front(_dev);
    }

    //Set all devices is in setting files
    if(!_frameDevice.isEmpty()){
        //update for Sensors.................................................................................................
        foreach(auto element,_frameDevice){
            if(element.typeDevice()==VDevice::Sensor){
                if(uiFrame_Widget-rowWidget<iconWidth ){
                    colunmWidget += iconHeight;
                    if(colunmWidget>uiFrame_Height-iconHeight)return;
                    rowWidget = 0;
                    }
                if(uiFrame_Widget-rowWidget>=iconWidth){
                    vbuttonSingle = new VButtonSingle(m_frameButtonSensors);
                    connect(vbuttonSingle,&VButtonSingle::signal_vbuttonSigle_Clicked,this,&MainWindow::on_vbuttonSigle_Clicked);
                    vbuttonSingle->setLocal_ax(rowWidget);
                    vbuttonSingle->setLocal_ay(colunmWidget);
                    vbuttonSingle->setDeviceWidget(element);
                    vbuttonSingle->show();
                    rowWidget += iconWidth ;
                    }
               }
            }

        //update for Modules.................................................................................................
        rowWidget = 0;
        colunmWidget= 0;
        uiFrame_Widget = ui->tabWidget->width();
        uiFrame_Height = ui->tabWidget->height();
        foreach(auto element,_frameDevice){
            if(element.typeDevice()==VDevice::Module){
                if(uiFrame_Widget-rowWidget<iconWidth ){
                    colunmWidget += iconHeight;
                    if(colunmWidget>uiFrame_Height-iconHeight)return;
                    rowWidget = 0;
                    }
                if(uiFrame_Widget-rowWidget>=iconWidth){
                    vbuttonSingle = new VButtonSingle(m_frameButtonModules);
                    connect(vbuttonSingle,&VButtonSingle::signal_vbuttonSigle_Clicked,this,&MainWindow::on_vbuttonSigle_Clicked);
                    vbuttonSingle->setLocal_ax(rowWidget);
                    vbuttonSingle->setLocal_ay(colunmWidget);
                    vbuttonSingle->setDeviceWidget(element);
                    vbuttonSingle->show();
                    rowWidget += iconWidth ;
                    }
               }
            }
        //update for Systems.................................................................................................
        rowWidget = 0;
        colunmWidget= 0;
        uiFrame_Widget = ui->tabWidget->width();
        uiFrame_Height = ui->tabWidget->height();
        foreach(auto element,_frameDevice){
            if(element.typeDevice()==VDevice::System){
                if(uiFrame_Widget-rowWidget<iconWidth ){
                    colunmWidget += iconHeight;
                    if(colunmWidget>uiFrame_Height-iconHeight)return;
                    rowWidget = 0;
                    }
                if(uiFrame_Widget-rowWidget>=iconWidth){
                    vbuttonSingle = new VButtonSingle(m_frameButtonSystems);
                    connect(vbuttonSingle,&VButtonSingle::signal_vbuttonSigle_Clicked,this,&MainWindow::on_vbuttonSigle_Clicked);
                    vbuttonSingle->setLocal_ax(rowWidget);
                    vbuttonSingle->setLocal_ay(colunmWidget);
                    vbuttonSingle->setDeviceWidget(element);
                    vbuttonSingle->show();
                    rowWidget += iconWidth ;
                    }
               }
            }
        //update for Settings.................................................................................................
        rowWidget = 0;
        colunmWidget= 0;
        uiFrame_Widget = ui->tabWidget->width();
        uiFrame_Height = ui->tabWidget->height();
        foreach(auto element,_frameDevice){
            if(m_userLogin.accountType()==VUser::root){
                if(element.typeDevice()==VDevice::Setting||element.typeDevice()==VDevice::Root){
                    if(uiFrame_Widget-rowWidget<iconWidth ){
                        colunmWidget += iconHeight;
                        if(colunmWidget>uiFrame_Height-iconHeight)return;
                        rowWidget = 0;
                        }
                    if(uiFrame_Widget-rowWidget>=iconWidth){
                        vbuttonSingle = new VButtonSingle(m_frameButtonSettings);
                        connect(vbuttonSingle,&VButtonSingle::signal_vbuttonSigle_Clicked,this,&MainWindow::on_vbuttonSigle_Clicked);
                        vbuttonSingle->setLocal_ax(rowWidget);
                        vbuttonSingle->setLocal_ay(colunmWidget);
                        vbuttonSingle->setDeviceWidget(element);
                        vbuttonSingle->show();
                        rowWidget += iconWidth ;
                        }
                   }
                }
            if(m_userLogin.accountType()==VUser::teacher){
                if(element.typeDevice()==VDevice::Setting){
                    if(uiFrame_Widget-rowWidget<iconWidth ){
                        colunmWidget += iconHeight;
                        if(colunmWidget>uiFrame_Height-iconHeight)return;
                        rowWidget = 0;
                        }
                    if(uiFrame_Widget-rowWidget>=iconWidth){
                        vbuttonSingle = new VButtonSingle(m_frameButtonSettings);
                        connect(vbuttonSingle,&VButtonSingle::signal_vbuttonSigle_Clicked,this,&MainWindow::on_vbuttonSigle_Clicked);
                        vbuttonSingle->setLocal_ax(rowWidget);
                        vbuttonSingle->setLocal_ay(colunmWidget);
                        vbuttonSingle->setDeviceWidget(element);
                        vbuttonSingle->show();
                        rowWidget += iconWidth ;
                        }
                   }
                }


           }

    }
}

void MainWindow::on_pushButton_Loggout_clicked()
{
    emit this->set_loggout();
    this->hide();
}

void MainWindow::on_selectModule1101(Module_Msg1101::MsgSystem n)
{
    switch(n){
    case Module_Msg1101::MSG_SYSTEM_WATER:
        if(m_frmMOD1101)delete m_frmMOD1101;
        m_frmMOD1101 = new Module_MOD1101();
        m_frmMOD1101->setDeviceWidget(m_vdev,m_userLogin);
        m_frmMOD1101->setGeometry(this->getLocal_X(m_frmMOD1101->width()),\
                                  this->getLocal_Y(m_frmMOD1101->height()),m_frmMOD1101->width(),m_frmMOD1101->height());
        m_frmMOD1101->show();
        break;
    case Module_Msg1101::MSG_SYSTEM_SPRINGS:
        if(m_frmMOD1102)delete m_frmMOD1102;
        m_frmMOD1102 = new Module_MOD1102();
        m_frmMOD1102->setDeviceWidget(m_vdev,m_userLogin);
        m_frmMOD1102->setGeometry(this->getLocal_X(m_frmMOD1102->width()),\
                                  this->getLocal_Y(m_frmMOD1102->height()),m_frmMOD1102->width(),m_frmMOD1102->height());
        m_frmMOD1102->show();
        break;
    case Module_Msg1101::MSG_SYSTEM_SENSOR:
        if(m_frmSEN0103)delete m_frmSEN0103;
        m_frmSEN0103 = new Sensor_SEN0103();
        m_frmSEN0103->setDeviceWidget(m_vdev,m_userLogin);
        m_frmSEN0103->setGeometry(this->getLocal_X(m_frmSEN0103->width()),\
                                      this->getLocal_Y(m_frmSEN0103->height()),m_frmSEN0103->width(),m_frmSEN0103->height());
        m_frmSEN0103->show();
        break;
    }
}

void MainWindow::on_pushButton_Loggout_2_clicked()
{
    m_aboutSteme = new AboutSteme();
    m_aboutSteme->show();
}
