#include "sensor_sen0121.h"
#include "ui_sensor_sen0121.h"

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Sensor_SEN0121::setDeviceWidget(VDevice dev,VUser user)
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
   m_edev_sen0121 = new EDev_Sen0121();
   m_edev_sen0121->setSensorUnit(EDev_Sen0121::SSU_milliMeter);
   m_edev_sen0121->setResolution(0);
   m_edev_sen0121->setSampleTime(m_modbusSampleTime);
   m_edev_sen0121->Start(dev);

   //Chart
   m_axisX_Range = QVariant(ui->spinBox_graphTime->value()).toDouble();
   this->chartInit();
   if(m_chartTimer) delete m_chartTimer;
   m_chartTimer = new QTimer();
   connect(m_chartTimer,&QTimer::timeout,this,&Sensor_SEN0121::on_chartUpdate);
   m_chartTimer->start(m_chartInterval);
   m_echart->setScanType(ECharts::scanCompact);

    if(m_displayTimer)delete m_displayTimer;
    m_displayTimer = new QTimer();
    connect(m_displayTimer,&QTimer::timeout,this,&Sensor_SEN0121::on_displayTimer);
    m_displayTimer->start(m_displayInterval);
    ui->spinBox_SampleTime->setValue(m_modbusSampleTime);
}


void Sensor_SEN0121::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_sen0121->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_sen0121->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_sen0121->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_sen0121->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_sen0121->resolution()));
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
m_deviceCalibration->setConnectStatus(m_edev_sen0121->isConnect());

}

void Sensor_SEN0121::setInfoCalib()
{
    if(m_user.accountType()==VUser::root){
        int _p = m_edev_sen0121->pointCalib();
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


void Sensor_SEN0121::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Sensor_SEN0121::SWS_SetZero:
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
        ui->pushButton_SetZero->setEnabled(true);
        m_SWS_Status = Sensor_SEN0121::SWS_default;
        break;
    case Sensor_SEN0121::SWS_SetMode:
        if(!status){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Chế độ đo chưa được cài đặt. \n\r    - Kiểm tra lại kết nối và thử lại.");
            m_QMessageBox->setWindowTitle("Cài đặt chế độ đo");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
        else {
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đẵ cài đặt chế độ đo thành công.");
            m_QMessageBox->setWindowTitle("Cài đặt chế độ đo");
            m_QMessageBox->show();
        }
        ui->pushButton_SetMode->setEnabled(true);
        m_SWS_Status = Sensor_SEN0121::SWS_default;
        break;
    case Sensor_SEN0121::SWS_Calib:
        if(status)m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Finished);
        else m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Error_Connect);
        break;
    case Sensor_SEN0121::SWS_default:
        return;
    }
    m_SWS_Status = Sensor_SEN0121::SWS_default;
}

void Sensor_SEN0121::calculateParametes(double value, int resolution)
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
void Sensor_SEN0121::on_displayTimer()
{
    if(m_edev_sen0121->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_sen0121->setSampleTime(m_modbusSampleTime);
        m_edev_sen0121->update();
        switch (m_edev_sen0121->pollStatus()) {
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
            m_edev_sen0121->setPollStatus(ESensors::sensorIdle);
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        m_displayTimer->setInterval(500);
        m_edev_sen0121->setSampleTime(500);
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
    if(m_deviceCalibration)this->sensorCalibration(m_edev_sen0121->valueCalib(),m_edev_sen0121->value());
}
void Sensor_SEN0121::displayPoll()
{
    m_sensor_Value=m_edev_sen0121->valueCalib();
    //get average of value
    if(ui->checkBox_setMathAvg->isChecked())m_sensor_Value = VDevice::mathAvg(m_sensor_Value,&m_VALUE_AVG,ui->spinBox_setSample->value());
    ui->lcdNumber_Value->display(QString::number(m_sensor_Value,'f',m_edev_sen0121->resolution()));
    //calculate basic parameters
    this->calculateParametes(m_sensor_Value,m_edev_sen0121->resolution());
    //Chart graph
    if(!m_stop_start)return;
    switch(ui->comboBox_Sensor_Mode->currentIndex())
    {
    case 0:
        if(m_time_Line+m_edev_sen0121->elapsed()>m_echart->axisX_Max()){
            if(ui->radioButton_Continuously->isChecked())break;
            m_echart->setAxisX_Max(m_time_Line+1);
        }
        m_time_Line += m_edev_sen0121->elapsed();
        this->chartGraph(QPointF(m_time_Line,m_sensor_Value));
        break;
    case 1:
        if(m_time_Line+m_edev_sen0121->elapsed()>m_echart->axisX_Max()){
            if(ui->radioButton_Continuously->isChecked())break;
            m_echart->setAxisX_Max(m_time_Line+1);
        }
        m_time_Line += m_edev_sen0121->elapsed();
        this->chartGraph(QPointF(m_time_Line,m_sensor_Value));
        break;
    case 2:
        break;
    }
}

void Sensor_SEN0121::on_chartUpdate()
{
    EDev_Sen0121::EData data;
    QVector<QPointF> val;
    FreqData _freq;
    bool ok=false;
    data = m_edev_sen0121->getDataPoll(&ok);
    if(!m_stop_start)return;
    if(ui->comboBox_Sensor_Mode->currentIndex()!=2)return;
    if(!ok)return;
    if(m_time_Line+data.time>ui->spinBox_graphTime->value()){
        if(ui->radioButton_Continuously->isChecked()){
            m_stop_start=false;
            ui->frame_graphTime->setEnabled(true);
            ui->pushButton_SetMode->setEnabled(true);
            ui->pushButton_SetMode->setText("BẮT ĐẦU");
            ui->pushButton_SetMode->setStyleSheet("QPushButton{\
                                                  background-color: rgb(225, 225, 225);\
                                                      color: rgb(0, 85, 255);\
                                                  }");
            return;
        }
        m_echart->setAxisX_Max(m_time_Line+1);
    }
    m_chartTimer->stop();
    m_time_Line += data.time;
    this->chartGraph(QPointF(m_time_Line,data.value));
    val = m_echart->lines(1);
    _freq = this->getPulseCounter(val,30);
    ui->label_Calculate_Pulse->setText(QString::number(_freq.pulse,'f',0));
    ui->label_Calculate_Freq->setText(QString::number(_freq.freq,'f',3));
    ui->label_Calculate_Time->setText(QString::number(_freq.time,'f',3));
    m_chartTimer->start(m_chartInterval);
}

void Sensor_SEN0121::on_setChartParameter(int sampleTime)
{
    m_modbusSampleTime = QString::number(sampleTime).toUShort();
    ui->spinBox_SampleTime->setValue(sampleTime);
    m_edev_sen0121->setSampleTime(m_modbusSampleTime);
}

void Sensor_SEN0121::closeEvent(QCloseEvent *event)
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
         m_echart->deleteLater();
         m_edev_sen0121->Stop();
         m_edev_sen0121->close();
         event->accept();
     }
}

void Sensor_SEN0121::setOpenFile(bool status)
{
    if(status)m_isOpenFile=true;
    else{
        this->setDeviceWidget(m_deviceInformation,m_user);
        //ui->comboBox_SelectSample->setCurrentIndex(0);
        m_isOpenFile=false;
        this->chartClear();
    }
}

Sensor_SEN0121::FreqData Sensor_SEN0121::getPulseCounter(QVector<QPointF> val, double threshold)
{
    FreqData data;
    bool head = true;
    double _VAL_LAST=0,_VAL_MIN=0,_time_first=0,_time_last=0,_max=0,_error=0;
    int count=0,i=0;
    //Check head
    for(i=0;i<val.count();i++){
        if(head)//head
        {
            if(val.at(i).y()<=_VAL_LAST){
                if(_VAL_LAST - _VAL_MIN>threshold){
                    if(count==0)_time_first = val.at(i).x();
                    count++;
                    _time_last = val.at(i).x();
                }
            head=false;
            }
        }
        else{//foot
            if(val.at(i).y()>_VAL_LAST){
                _VAL_MIN = _VAL_LAST;
                head=true;
            }
        }
        _error = _time_last-_time_first;
        if(_error<0)_error*=(-1);
        if(_max<_error)_max=_error;
        if(threshold < _max)threshold = _max;
        _VAL_LAST = val.at(i).y();
    }
    if(count>0)count-=1;
    data.pulse = count;
    if(QVariant(_time_last-_time_first).toInt()!=0&&count!=0){
        data.freq = QVariant(count).toDouble()/(_time_last-_time_first);
        data.time = 1/data.freq;
        }
return data;
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
void Sensor_SEN0121::chartInit()
{
    if(m_echart)delete m_echart;
    m_echart = new ECharts();
    ECharts::Parameter parameter;
    parameter.timerScan = m_chartTimerInterval;
    parameter.axisX_Range_Max = m_axisX_Range;
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(2);
    m_echart->setAxisYFormat(m_edev_sen0121->resolution());
    m_echart->setAxisXName("Thời gian");
    m_echart->setAxisYName(ui->comboBox_Sensor_Unit->currentText());
    m_echart->init(parameter,3,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_edev_sen0121->sampleTime()).toDouble()))).toInt());//Scan in 1 hour
}

void Sensor_SEN0121::chartGraph(double val)
{
    m_echart->graph(QPointF(m_axtX_Index,val));
}

void Sensor_SEN0121::chartGraph(QPointF val)
{
m_echart->graph(val);
}


void Sensor_SEN0121::chartClear()
{
    m_echart->clear();
    m_echart->setLinesIndex(1);
    m_axtX_Index=0;
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
    m_time_Line=0;
    this->chartGraph(QPointF(0,0));
    m_stop_start=false;
    ui->frame_graphTime->setEnabled(true);
    ui->pushButton_SetMode->setEnabled(true);
    ui->pushButton_SetMode->setText("BẮT ĐẦU");
    ui->pushButton_SetMode->setStyleSheet("QPushButton{\
                                          background-color: rgb(225, 225, 225);\
                                              color: rgb(0, 85, 255);\
                                          }");
}

void Sensor_SEN0121::setTrackLine(EChartGesture::ETrackLine track)
{
    ui->pushButton_TrackLine_Default->setEnabled(true);
    ui->pushButton_TrackLine_Tooltip->setEnabled(true);
    ui->pushButton_TrackLine_Yax->setEnabled(true);
    switch(track){
    case EChartGesture::ETrackLine::ETL_default:
        ui->pushButton_TrackLine_Default->setEnabled(false);
        break;
    case EChartGesture::ETrackLine::ETL_tooltip:
        ui->pushButton_TrackLine_Tooltip->setEnabled(false);
        break;
    case EChartGesture::ETrackLine::ETL_y_ax:
        ui->pushButton_TrackLine_Yax->setEnabled(false);
        break;
    }
    if(m_echart)m_echart->setTrackLine(track);
}

/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Sensor_SEN0121::Sensor_SEN0121(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0121)
{
    ui->setupUi(this);
    VDevice::deviceWidgetInstances.push_back(this);

}

Sensor_SEN0121::~Sensor_SEN0121()
{
    delete ui;
    VDevice::deviceWidgetInstances.removeOne(this);
}


void Sensor_SEN0121::on_spinBox_SampleTime_valueChanged(int arg1)
{
    if(arg1>ui->spinBox_SampleTime->minimum())ui->pushButton_SetSampleTime->setEnabled(true);
}

void Sensor_SEN0121::on_pushButton_SetSampleTime_clicked()
{
    ui->pushButton_SetSampleTime->setEnabled(false);
    m_modbusSampleTime = QString::number(ui->spinBox_SampleTime->value()).toUShort();
    m_edev_sen0121->setSampleTime(m_modbusSampleTime);
}

void Sensor_SEN0121::on_pushButton_Calib_clicked()
{
    if(m_deviceCalibration)delete m_deviceCalibration;
    m_deviceCalibration = new VDeviceCalibration();
    int _local_X = this->geometry().x()+(this->width()-m_deviceCalibration->width())/2;
    int _local_Y = this->geometry().y()+(this->height()-m_deviceCalibration->height())/2;
    m_deviceCalibration->setGeometry(_local_X,_local_Y,m_deviceCalibration->width(),m_deviceCalibration->height());
    m_deviceCalibration->setResolution(m_edev_sen0121->resolution());
    m_deviceCalibration->setTolerance(1);
    m_deviceCalibration->setCalibTime(20);
    m_deviceCalibration->setSampleNumber(200);
    m_deviceCalibration->setValueCalib_Y1(100);
    m_deviceCalibration->setUnit(m_edev_sen0121->sensorUnitText());
    m_deviceCalibration->show();
}

void Sensor_SEN0121::on_pushButton_Exit_clicked()
{
    this->close();
}

void Sensor_SEN0121::on_pushButton_getSamples_clicked()
{
    if(ui->pushButton_getSamples->text()=="Lấy mẫu"){
        m_GET_SAMPLE_STATUS=true;
        m_GET_SAMPLE_SUM = 0;
        m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        m_GET_SAMPLE_COUNT = 0;
        ui->pushButton_getSamples->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(170, 0, 0);");
        ui->pushButton_getSamples->setText("Dừng");
    }
    else{
        m_GET_SAMPLE_STATUS=false;
        ui->label_sampleInfo->setText("Các tham số cơ bản");
        ui->pushButton_getSamples->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 0);");
        ui->pushButton_getSamples->setText("Lấy mẫu");
    }
}

void Sensor_SEN0121::on_tabWidget_tabBarClicked(int index)
{
    if(index==2)this->setInfoCalib();
}

void Sensor_SEN0121::on_pushButton_SetZero_clicked()
{
    ui->pushButton_SetZero->setEnabled(false);
    QVector<quint16> values(2);
    values[0] = (m_edev_sen0121->REG_sen01_ADC()>>16)&0xFFFF;
    values[1] = (m_edev_sen0121->REG_sen01_ADC()&0xFFFF);
    m_SWS_Status = SWS_SetZero;
    m_edev_sen0121->setZero(values);
  //  ui->pushButton_SetZero->setEnabled(true);
}

void Sensor_SEN0121::on_comboBox_Sensor_Unit_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        m_edev_sen0121->setSensorUnit(EDev_Sen0121::SSU_milliMeter);
        break;
    case 1:m_edev_sen0121->setSensorUnit(EDev_Sen0121::SSU_centiMeter);
        break;
    case 2:m_edev_sen0121->setSensorUnit(EDev_Sen0121::SSU_deciMeter);
        break;
    case 3:m_edev_sen0121->setSensorUnit(EDev_Sen0121::SSU_Meter);
        break;
    }
    m_edev_sen0121->setResolution(index);
    this->chartInit();
}

void Sensor_SEN0121::on_pushButton_SetMode_clicked()
{
this->m_edev_sen0121->clearDataPoll();
if(m_stop_start){
    m_stop_start=false;
    ui->pushButton_SetMode->setText("TIẾP TỤC");
    ui->pushButton_SetMode->setStyleSheet("QPushButton{\
                                          background-color: rgb(225, 225, 225);\
                                              color: rgb(0, 170, 0);\
                                          }");
}
else{
    m_stop_start=true;
    if(ui->radioButton_Accumulation->isChecked())ui->frame_graphTime->setEnabled(false);
    if(ui->pushButton_SetMode->text()=="BẮT ĐẦU") this->chartClear();
    ui->pushButton_SetMode->setText("DỪNG");
    ui->pushButton_SetMode->setStyleSheet("QPushButton{\
                                          background-color: rgb(225, 225, 225);\
                                          color: rgb(170, 0, 0);\
                                          }");
    }
}

void Sensor_SEN0121::on_radioButton_Accumulation_toggled(bool checked)
{
    this->chartClear();
}


void Sensor_SEN0121::on_pushButton_ClearChart_clicked()
{
    ECharts::Parameter parameter = m_echart->parameter();
    if(m_isOpenFile)setOpenFile(false);
    else this->chartClear();
    parameter.axisX_Range_Max = m_axisX_Range;
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setParameter(parameter);
}


void Sensor_SEN0121::on_pushButton_TrackLine_Default_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}


void Sensor_SEN0121::on_pushButton_TrackLine_Tooltip_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_tooltip);
}


void Sensor_SEN0121::on_pushButton_TrackLine_Yax_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_y_ax);
}


void Sensor_SEN0121::on_comboBox_Sensor_Mode_currentIndexChanged(int index)
{
    quint16 mode=0;
    ui->pushButton_SetMode->setEnabled(false);
    m_SWS_Status = SWS_SetMode;
    switch(index)
    {
    case 0:mode=3;
        ui->spinBox_graphTime->setValue(10);
        ui->radioButton_Continuously->setChecked(false);
        break;
    case 1:mode=2;
        ui->spinBox_graphTime->setValue(10);
        ui->radioButton_Continuously->setChecked(false);
        break;
    case 2:mode=1;
        ui->spinBox_graphTime->setValue(30);
        ui->radioButton_Continuously->setChecked(true);
        break;
    }
    m_edev_sen0121->setMode(mode);
    this->chartClear();
}



void Sensor_SEN0121::on_spinBox_graphTime_valueChanged(int arg1)
{
    m_axisX_Range = QVariant(arg1).toDouble();
    m_echart->setAxisX_Max(m_axisX_Range);
}

