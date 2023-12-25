#include "sensor_sen0108.h"
#include "ui_sensor_sen0108.h"


/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Sensor_SEN0108::setDeviceWidget(VDevice dev,VUser user)
{
   m_deviceInformation = dev;
    this->setWindowTitle(m_deviceInformation.name());
   ui->label_Name->setText(m_deviceInformation.name());
   ui->label_Address->setText(QString::number(m_deviceInformation.address()));
   ui->label_SerialNumber->setText(m_deviceInformation.serialNumber());
   ui->label_Description->setText(m_deviceInformation.description());
   //Check user
   m_user = user;
   if(user.accountType()!=VUser::root)ui->pushButton_Calib->setEnabled(false);
   //Create Sensor
   m_edev_sen0108 = new EDev_Sen0108();
   m_edev_sen0108->setSensorUnit(EDev_Sen0108::SSU_percentVolt);
   m_edev_sen0108->setSampleTime(m_modbusSampleTime);
   m_edev_sen0108->Start(dev);

   if(m_displayTimer)delete m_displayTimer;
   m_displayTimer = new QTimer();
   connect(m_displayTimer,&QTimer::timeout,this,&Sensor_SEN0108::on_displayTimer);
   m_displayTimer->start(m_displayInterval);
   ui->spinBox_SampleTime->setValue(m_modbusSampleTime);

}


void Sensor_SEN0108::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_sen0108->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_sen0108->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_sen0108->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_sen0108->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_sen0108->resolution()));
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
m_deviceCalibration->setConnectStatus(m_edev_sen0108->isConnect());

}

void Sensor_SEN0108::setInfoCalib()
{
    if(m_user.accountType()==VUser::root){
        int _p = m_edev_sen0108->pointCalib();
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



void Sensor_SEN0108::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Sensor_SEN0108::SWS_SetZero:
        if(!status){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Chưa thực hiện xong quá trình hiệu chuẩn nhanh. \n\r    - Kiểm tra lại kết nối và thử lại.");
            m_QMessageBox->setWindowTitle("Hiệu chuẩn nhanh");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
        else {
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã hiệu chuẩn nhanh thành công.");
            m_QMessageBox->setWindowTitle("Hiệu chuẩn nhanh");
            m_QMessageBox->show();
        }
        ui->pushButton_Calib->setEnabled(true);
        break;
    case Sensor_SEN0108::SWS_Calib:
        if(status)m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Finished);
        else m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Error_Connect);
        break;
    case Sensor_SEN0108::SWS_default:
        return;
    }
    m_SWS_Status = Sensor_SEN0108::SWS_default;
}

void Sensor_SEN0108::calculateParametes(double value, int resolution)
{
        //Calculate
        if(m_GET_SAMPLE_STATUS){
        m_GET_SAMPLE_COUNT++;
        m_GET_SAMPLE_SUM+=value;
        if(m_GET_SAMPLE_MAX<value)m_GET_SAMPLE_MAX=value;
        if(m_GET_SAMPLE_MIN>value)m_GET_SAMPLE_MIN=value;

        //Display
        ui->label_sampleInfo->setText("Đang lấy mẫu số    " + QString::number(m_GET_SAMPLE_COUNT));
        ui->label_ValueMax->setText(QString::number(m_GET_SAMPLE_MAX,'f',resolution));
        ui->label_ValueMin->setText(QString::number(m_GET_SAMPLE_MIN,'f',resolution));
        ui->label_ValueAvg->setText(QString::number((m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT),'f',resolution));
        if(m_GET_SAMPLE_COUNT>ui->spinBox_setSample->value()){
            m_GET_SAMPLE_STATUS=false;
            ui->label_sampleInfo->setText("Các tham số cơ bản");
            ui->pushButton_getSamples->setStyleSheet("color: rgb(0, 0, 0);");
            ui->pushButton_getSamples->setText("Bắt đầu");
            }
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Sensor_SEN0108::on_displayTimer()
{
    if(m_edev_sen0108->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_sen0108->setSampleTime(m_modbusSampleTime);
        m_edev_sen0108->update();
        switch (m_edev_sen0108->pollStatus()) {
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
            m_edev_sen0108->setPollStatus(ESensors::sensorIdle);
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        m_displayTimer->setInterval(500);
        m_edev_sen0108->setSampleTime(500);
        if(m_displayToggle){
            ui->lcdNumber_Value->display(-1);
            m_displayToggle=false;
        }
        else {
            ui->lcdNumber_Value->display(0);
            m_displayToggle=true;
        }
    }
    //Chart Calib
    if(m_deviceCalibration)this->sensorCalibration(m_edev_sen0108->valueCalib(),m_edev_sen0108->value());
}
void Sensor_SEN0108::displayPoll()
{
    double _oxy = m_edev_sen0108->valueCalib();
    //get average of value
    if(ui->checkBox_setMathAvg->isChecked()){
        _oxy = VDevice::mathAvg(_oxy,&m_VALUE_AVG,ui->spinBox_setSample->value());
        }
    ui->lcdNumber_Value->display(QString::number(_oxy,'f',m_edev_sen0108->resolution()));
    //calculate basic parameters
    this->calculateParametes(_oxy,m_edev_sen0108->resolution());
    //Chart graph
    if(m_vchartZoom){
        m_vchartZoom->vchartGraph(_oxy,ui->comboBox_Unit->currentText());
        if(m_vchartZoom->isHidden()){
            m_vchartZoom=nullptr;
            }
        }
}

void Sensor_SEN0108::on_setChartParameter(int sampleTime)
{
    m_modbusSampleTime = QString::number(sampleTime).toUShort();
    ui->spinBox_SampleTime->setValue(sampleTime);
    m_edev_sen0108->setSampleTime(m_modbusSampleTime);
}


/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Sensor_SEN0108::Sensor_SEN0108(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0108)
{
    ui->setupUi(this);


}
Sensor_SEN0108::~Sensor_SEN0108()
{
    delete ui;
}

void Sensor_SEN0108::closeEvent(QCloseEvent *event)
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
         m_vchartZoom->deleteLater();
         m_edev_sen0108->close();
         event->accept();
     }
}

void Sensor_SEN0108::on_pushButton_Exit_clicked()
{
    this->close();
}

void Sensor_SEN0108::on_pushButton_ChartZoom_clicked()
{
    if(m_vchartZoom) delete m_vchartZoom;
        m_vchartZoom = new Vchart_Zoom();
        m_vchartZoom->setDevice(m_deviceInformation);
        m_vchartZoom->vchartInit(0,1,60,m_modbusSampleTime);
        connect(m_vchartZoom,&Vchart_Zoom::setChartParameter,this,&Sensor_SEN0108::on_setChartParameter);
        m_vchartZoom->show();
}

void Sensor_SEN0108::on_pushButton_getSamples_clicked()
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


void Sensor_SEN0108::on_spinBox_SampleTime_valueChanged(int arg1)
{
    if(arg1>ui->spinBox_SampleTime->minimum())ui->pushButton_SetSampleTime->setEnabled(true);
}

void Sensor_SEN0108::on_pushButton_SetSampleTime_clicked()
{
    ui->pushButton_SetSampleTime->setEnabled(false);
    m_modbusSampleTime = QString::number(ui->spinBox_SampleTime->value()).toUShort();
    m_edev_sen0108->setSampleTime(m_modbusSampleTime);
}

void Sensor_SEN0108::on_pushButton_Calib_clicked()
{
    ui->pushButton_Calib->setEnabled(false);
    if(ui->checkBox_CalibFast->isChecked()){
        double val;
        bool ok;
        val = QString(ui->lineEdit_CalibFast->text()).toDouble(&ok);
        if(ok){
            quint32 _calib = VDevice::encode(val,2);
            QVector<quint16> values;
            values.append((_calib>>16)&0xFFFF);
            values.append(_calib&0xFFFF);
            m_SWS_Status = SWS_SetZero;
            m_edev_sen0108->writeFastCalib(values);
        }
        else {
            QMessageBox  msg;
            msg.setStandardButtons(QMessageBox::Ok);
            msg.setText("Giá trị hiệu chuẩn nhanh không đúng!");
            msg.setWindowTitle(this->windowTitle());
            msg.setParent(nullptr);
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowIcon(this->windowIcon());
            msg.exec();
        }
    }
    else {
        if(m_deviceCalibration)delete m_deviceCalibration;
        m_deviceCalibration = new VDeviceCalibration();
        int _local_X = this->geometry().x()+(this->width()-m_deviceCalibration->width())/2;
        int _local_Y = this->geometry().y()+(this->height()-m_deviceCalibration->height())/2;
        m_deviceCalibration->setGeometry(_local_X,_local_Y,m_deviceCalibration->width(),m_deviceCalibration->height());
        m_deviceCalibration->setResolution(m_edev_sen0108->resolution());
        m_deviceCalibration->setTolerance(0.5);
        m_deviceCalibration->setCalibTime(30);
        m_deviceCalibration->setSampleNumber(300);
        m_deviceCalibration->setValueCalib_Y1(100);
        m_deviceCalibration->setUnit(m_edev_sen0108->sensorUnitText());
        m_deviceCalibration->show();
        ui->pushButton_Calib->setEnabled(true);
    }
}

void Sensor_SEN0108::on_tabWidget_tabBarClicked(int index)
{
    if(index==2)this->setInfoCalib();
}

void Sensor_SEN0108::on_comboBox_Unit_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_edev_sen0108->setSensorUnit(EDev_Sen0108::SSU_percentVolt);
        break;
    case 1:m_edev_sen0108->setSensorUnit(EDev_Sen0108::SSU_mg);
        break;
    }
}

void Sensor_SEN0108::on_pushButton_SetZero_clicked()
{

}
