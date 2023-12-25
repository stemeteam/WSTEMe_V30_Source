//user
#include "sensor_sen0103.h"
#include "ui_sensor_sen0103.h"
QVector<Sensor_SEN0103*> Sensor_SEN0103::instances;

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Sensor_SEN0103::setDeviceWidget(VDevice dev,VUser user)
{
   m_deviceInformation = dev;
    this->setWindowTitle(m_deviceInformation.name());
   ui->label_Name_2->setText(m_deviceInformation.name());
   ui->label_Address_2->setText(QString::number(m_deviceInformation.address()));
   ui->label_SerialNumber_2->setText(m_deviceInformation.serialNumber());
   ui->label_Description_2->setText(m_deviceInformation.description());
   //Check user
   m_user = user;
  if(user.accountType()!=VUser::root)ui->pushButton_Calib_2->setEnabled(false);
  //Create Sensor
  m_edev_sen0103 = new EDev_Sen0103();
  m_edev_sen0103->setSensorUnit(EDev_Sen0103::SSU_scaleWeight);
  m_edev_sen0103->setSampleTime(m_modbusSampleTime);
  m_edev_sen0103->Start(dev);

    //Timer
   if(m_displayTimer)delete m_displayTimer;
   m_displayTimer = new QTimer();
   connect(m_displayTimer,&QTimer::timeout,this,&Sensor_SEN0103::on_displayTimer);
   m_displayTimer->start(m_displayInterval);
   ui->spinBox_SampleTime_2->setValue(m_modbusSampleTime);
}


void Sensor_SEN0103::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_sen0103->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_sen0103->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_sen0103->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_sen0103->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_sen0103->resolution()));
            m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Writing);
            m_SWS_Status = SWS_Calib;
            break;
        case VDeviceCalibration::Calib_Writing:
            break;
        case VDeviceCalibration::Calib_Cancel:
            break;
        case VDeviceCalibration::Calib_Finished:this->setInfoCalib();
            break;
        case VDeviceCalibration::Calib_Error_Tolerance:
            break;
        case VDeviceCalibration::Calib_Error_Connect:
                break;
        }
    }
m_deviceCalibration->setConnectStatus(m_edev_sen0103->isConnect());


}

void Sensor_SEN0103::setInfoCalib()
{
    if(m_user.accountType()==VUser::root){
        int _p = m_edev_sen0103->pointCalib();
        if(_p>0){
            ui->label_calibInfo->setText("(Đã hiệu chuẩn " + QString::number(_p) + " điểm.)");
            ui->label_calibInfo->setStyleSheet("color: rgb(0, 255, 0);");
        }
        else{
            ui->label_calibInfo->setText("(Chưa hiệu chuẩn)");
            ui->label_calibInfo->setStyleSheet("color: rgb(255, 255, 127);");
        }
    }
}



void Sensor_SEN0103::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Sensor_SEN0103::SWS_SetZero:
        if(!status){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Điểm 0 chưa được thiết lập. \n\r    - Kiểm tra lại kết nối và thử lại.");
            m_QMessageBox->setWindowTitle("Thiết lập điểm 0");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
        else {
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Thiết lập điểm 0 (Zero) thành công.");
            m_QMessageBox->setWindowTitle("Thiết lập điểm 0");
            m_QMessageBox->show();
        }
        ui->pushButton_SetZero_2->setEnabled(true);
        m_SWS_Status = Sensor_SEN0103::SWS_default;
        break;
    case Sensor_SEN0103::SWS_Calib:
        if(status)m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Finished);
        else m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Error_Connect);
        m_SWS_Status = Sensor_SEN0103::SWS_default;
        break;
    case Sensor_SEN0103::SWS_default:
        return;
    }

}

void Sensor_SEN0103::calculateParametes(double value, int resolution)
{
        //Calculate
        if(m_GET_SAMPLE_STATUS){
        m_GET_SAMPLE_COUNT++;
        m_GET_SAMPLE_SUM+=value;
        if(m_GET_SAMPLE_MAX<value)m_GET_SAMPLE_MAX=value;
        if(m_GET_SAMPLE_MIN>value)m_GET_SAMPLE_MIN=value;

        //Display
        ui->label_sampleInfo->setText("Đang lấy mẫu số    " + QString::number(m_GET_SAMPLE_COUNT));
        ui->label_ValueMax_2->setText(QString::number(m_GET_SAMPLE_MAX,'f',resolution));
        ui->label_ValueMin_2->setText(QString::number(m_GET_SAMPLE_MIN,'f',resolution));
        ui->label_ValueAvg_2->setText(QString::number((m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT),'f',resolution));
        if(m_GET_SAMPLE_COUNT>ui->spinBox_setSample->value()){
            m_GET_SAMPLE_STATUS=false;
            ui->label_sampleInfo->setText("Các tham số cơ bản");
            ui->pushButton_getSamples->setStyleSheet("color: rgb(0, 0, 0);");
            ui->pushButton_getSamples->setText("Bắt đầu");
            }
        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Sensor_SEN0103::on_displayTimer()
{
    if(m_edev_sen0103->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_sen0103->setSampleTime(m_modbusSampleTime);
        m_edev_sen0103->update();
        switch (m_edev_sen0103->pollStatus()) {
        case ESensors::sensorIdle:
            break;
        case ESensors::sensorReadCommand:
            break;
        case ESensors::sensorWriteCommand:
            break;
        case ESensors::sensorReadError:
            break;
        case ESensors::sensorWriteError:
            sensorWriteReport(false);
            break;
        case ESensors::sensorReadReply:
            this->displayPoll();
            m_edev_sen0103->setPollStatus(ESensors::sensorIdle);
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        m_displayTimer->setInterval(500);
        m_edev_sen0103->setSampleTime(500);
        if(m_displayToggle){
            ui->lcdNumber_Value_2->display(-1);
            m_displayToggle=false;
        }
        else {
            ui->lcdNumber_Value_2->display(0);
            m_displayToggle=true;
        }
    }
    //Chart Calib
    if(m_deviceCalibration)this->sensorCalibration(m_edev_sen0103->valueCalib(),m_edev_sen0103->value());

}
void Sensor_SEN0103::displayPoll()
{
    double _weight_gam = m_edev_sen0103->valueCalib();
    //get average of value
    if(ui->checkBox_setMathAvg->isChecked())_weight_gam = VDevice::mathAvg(_weight_gam,&m_VALUE_AVG,ui->spinBox_setSample->value());
    ui->lcdNumber_Value_2->display(QString::number(_weight_gam,'f',m_edev_sen0103->resolution()));
    //calculate basic parameters
    this->calculateParametes(_weight_gam,m_edev_sen0103->resolution());
    //Chart graph
    if(m_vchartZoom){
        m_vchartZoom->vchartGraph(_weight_gam,ui->comboBox_Unit->currentText());
        if(m_vchartZoom->isHidden()){
            m_vchartZoom=nullptr;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Sensor_SEN0103::Sensor_SEN0103(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0103)
{
    ui->setupUi(this);
    instances.push_back(this);
    VDevice::deviceWidgetInstances.push_back(this);
//    ui->comboBox_Unit->setStyleSheet("color: rgb(255, 255, 255);"
 //       "alternate-background-color: rgb(62, 97, 109);");
}

Sensor_SEN0103::~Sensor_SEN0103()
{
    VDevice::deviceWidgetInstances.removeOne(this);
    delete ui;
}

void Sensor_SEN0103::on_setChartParameter(int sampleTime)
{
    m_modbusSampleTime = QString::number(sampleTime).toUShort();
    ui->spinBox_SampleTime_2->setValue(sampleTime);
    m_edev_sen0103->setSampleTime(m_modbusSampleTime);
}


void Sensor_SEN0103::closeEvent(QCloseEvent *event)
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có muốn thoát khỏi màn hình \'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() != QMessageBox::Yes) {
         event->ignore();
     } else {
         m_displayTimer->deleteLater();
         m_edev_sen0103->close();
         m_vchartZoom->deleteLater();
         event->accept();
     }
}



void Sensor_SEN0103::on_pushButton_Exit_clicked()
{
    this->close();
}



void Sensor_SEN0103::on_pushButton_ChartZoom_clicked()
{
    if(m_vchartZoom) delete m_vchartZoom;
        m_vchartZoom = new Vchart_Zoom();
        m_vchartZoom->setDevice(m_deviceInformation);
        m_vchartZoom->vchartInit(0,1,60,m_modbusSampleTime);
        connect(m_vchartZoom,&Vchart_Zoom::setChartParameter,this,&Sensor_SEN0103::on_setChartParameter);
        m_vchartZoom->show();
}


void Sensor_SEN0103::on_pushButton_SetZero_2_clicked()
{
    ui->pushButton_SetZero_2->setEnabled(false);
    QVector<quint16> values(2);
    values[0] = (m_edev_sen0103->REG_sen01_ADC()>>16)&0xFFFF;
    values[1] = (m_edev_sen0103->REG_sen01_ADC()&0xFFFF);
    m_SWS_Status = SWS_SetZero;
    m_edev_sen0103->writeZero(values);
    ui->pushButton_SetZero_2->setEnabled(true);
}

void Sensor_SEN0103::on_spinBox_SampleTime_2_valueChanged(int arg1)
{
    if(arg1>ui->spinBox_SampleTime_2->minimum())ui->pushButton_SetSampleTime_2->setEnabled(true);
}

void Sensor_SEN0103::on_pushButton_SetSampleTime_2_clicked()
{
    ui->pushButton_SetSampleTime_2->setEnabled(false);
    m_modbusSampleTime = QString::number(ui->spinBox_SampleTime_2->value()).toUShort();
    m_edev_sen0103->setSampleTime(m_modbusSampleTime);
    m_displayInterval = m_modbusSampleTime;
}

void Sensor_SEN0103::on_pushButton_Calib_2_clicked()
{
    if(m_deviceCalibration)delete m_deviceCalibration;
    m_deviceCalibration = new VDeviceCalibration();
    int _local_X = this->geometry().x()+(this->width()-m_deviceCalibration->width())/2;
    int _local_Y = this->geometry().y()+(this->height()-m_deviceCalibration->height())/2;
    m_deviceCalibration->setGeometry(_local_X,_local_Y,m_deviceCalibration->width(),m_deviceCalibration->height());
    m_deviceCalibration->setResolution(m_edev_sen0103->resolution());
    m_deviceCalibration->setTolerance(0.1);
    m_deviceCalibration->setCalibTime(30);
    m_deviceCalibration->setSampleNumber(300);
    m_deviceCalibration->setValueCalib_Y1(500);
    m_deviceCalibration->setUnit(m_edev_sen0103->sensorUnitText());
    m_deviceCalibration->show();
}


void Sensor_SEN0103::on_comboBox_Unit_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_edev_sen0103->setSensorUnit(EDev_Sen0103::SSU_scaleWeight);
        break;
    case 1:m_edev_sen0103->setSensorUnit(EDev_Sen0103::SSU_scaleGram);
        break;
    case 2:m_edev_sen0103->setSensorUnit(EDev_Sen0103::SSU_scaleKiloGram);
        break;
    case 3:m_edev_sen0103->setSensorUnit(EDev_Sen0103::SSU_scaleForce);
        break;
    }
}

void Sensor_SEN0103::on_pushButton_getSamples_clicked()
{
    if(ui->pushButton_getSamples->text()=="Bắt đầu"){
        m_GET_SAMPLE_STATUS=true;
        m_GET_SAMPLE_SUM = 0;
        m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        m_GET_SAMPLE_COUNT = 0;
        ui->pushButton_getSamples->setStyleSheet("color: rgb(170, 0, 0);");
        ui->pushButton_getSamples->setText("Dừng");
    }
    else{
        m_GET_SAMPLE_STATUS=false;
        ui->label_sampleInfo->setText("Các tham số cơ bản");
        ui->pushButton_getSamples->setStyleSheet("color: rgb(0, 0, 0);");
        ui->pushButton_getSamples->setText("Bắt đầu");
    }
}

void Sensor_SEN0103::on_tabWidget_tabBarClicked(int index)
{
    if(index==2)this->setInfoCalib();
}
