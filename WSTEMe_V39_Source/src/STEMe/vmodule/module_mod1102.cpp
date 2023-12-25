#include "module_mod1102.h"
#include "ui_module_mod1102.h"

QT_CHARTS_USE_NAMESPACE

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Module_MOD1102::setDeviceWidget(VDevice dev,VUser user)
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
  m_edev_mod1101 = new EDev_Mod1101();
  m_edev_mod1101->setSensorUnit(EDev_Mod1101::SSU_scaleForce);
  m_edev_mod1101->setSampleTime(m_modbusSampleTime);
  m_edev_mod1101->Start(dev);

  //Chart
  this->chartInit();
  //Timer
   if(m_displayTimer)delete m_displayTimer;
   m_displayTimer = new QTimer();
   connect(m_displayTimer,&QTimer::timeout,this,&Module_MOD1102::on_displayTimer);
   m_displayTimer->start(m_displayInterval);
   ui->spinBox_SampleTime->setValue(m_modbusSampleTime);

   this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}


void Module_MOD1102::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_mod1101->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_mod1101->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_mod1101->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_mod1101->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_mod1101->resolution()));
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
    m_deviceCalibration->setConnectStatus(m_edev_mod1101->isConnect());
}

void Module_MOD1102::setInfoCalib()
{
    if(m_user.accountType()==VUser::root){
        int _p = m_edev_mod1101->pointCalib();
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

void Module_MOD1102::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Module_MOD1102::SWS_SetZero:
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
        ui->pushButton_setZero->setEnabled(true);
        break;
    case Module_MOD1102::SWS_Calib:
        if(status)m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Finished);
        else m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Error_Connect);
        break;
    case Module_MOD1102::SWS_default:
        return;
    }
    m_SWS_Status = Module_MOD1102::SWS_default;

}

void Module_MOD1102::calculateParametes(double value, int resolution)
{
    if(m_motorStatus==Module_MOD1102::motorNext&&m_sampleType!=Module_MOD1102::sampleAuto)
    {
        //Calculate
        m_GET_SAMPLE_COUNT++;
        m_GET_SAMPLE_SUM+=value;
        if(m_GET_SAMPLE_MAX<value)m_GET_SAMPLE_MAX=value;
        if(m_GET_SAMPLE_MIN>value)m_GET_SAMPLE_MIN=value;

        //Display
       // ui->label_sampleInfo->setText("Đang lấy mẫu số    " + QString::number(m_GET_SAMPLE_COUNT));
        ui->label_ValueMax->setText(QString::number(m_GET_SAMPLE_MAX,'f',resolution));
        ui->label_ValueMin->setText(QString::number(m_GET_SAMPLE_MIN,'f',resolution));
        ui->label_ValueAvg->setText(QString::number((m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT),'f',resolution));
    }
    else {
        m_GET_SAMPLE_SUM = 0;
        m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
        m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
        m_GET_SAMPLE_COUNT = 0;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Module_MOD1102::on_displayTimer()
{
    if(m_edev_mod1101->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_mod1101->setSampleTime(m_modbusSampleTime);
        m_edev_mod1101->update();
        switch (m_edev_mod1101->pollStatus()) {
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
            m_edev_mod1101->setPollStatus(ESensors::sensorIdle);
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        m_displayTimer->setInterval(500);
        m_edev_mod1101->setSampleTime(500);
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
    if(m_deviceCalibration)this->sensorCalibration(m_edev_mod1101->valueCalib(),m_edev_mod1101->value());
}
void Module_MOD1102::displayPoll()
{
    double _weight_gam = m_edev_mod1101->valueCalib();
    ui->lcdNumber_Value->display(QString::number(_weight_gam,'f',m_edev_mod1101->resolution()));
    //calculate basic parameters
    this->calculateParametes(_weight_gam,m_edev_mod1101->resolution());
    //Chart graph
    this->chartGraph(_weight_gam);
    //Status of motor
    this->motorGetStatus();
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...

void Module_MOD1102::chartInit()
{
    if(m_echart)delete m_echart;
    m_echart = new ECharts();
    ECharts::Parameter parameter;
    parameter.timerScan = m_chartTimerInterval;
    parameter.axisX_Range_Max = m_axisX_Range*(QVariant(m_edev_mod1101->sampleTime()).toDouble()/1000);
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(1);
    m_echart->setAxisXName("Thời gian");
    m_echart->setAxisYName(ui->comboBox_Unit->currentText());
    m_echart->init(parameter,3,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_edev_mod1101->sampleTime()).toDouble()))).toInt());//Scan in 1 hour

}

void Module_MOD1102::chartGraph(double val)
{
    if(m_isOpenFile)return;
    if(m_motorStatus==Module_MOD1102::motorStop&&m_sampleType!=Module_MOD1102::sampleAuto)return;
    //Check graphType
    m_axtX_Index += QVariant(m_edev_mod1101->sampleTime()).toDouble()/1000;
    m_echart->graph(QPointF(m_axtX_Index,val));
    //m_echart->graph(val);
}

void Module_MOD1102::chartClear()
{
    m_echart->clear();
    m_echart->setLinesIndex(1);
    m_axtX_Index=0;
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Module_MOD1102::setTrackLine(EChartGesture::ETrackLine track)
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


void Module_MOD1102::setOpenFile(bool status)
{
    if(status)m_isOpenFile=true;
    else{
        this->setDeviceWidget(m_deviceInformation,m_user);
        ui->comboBox_SelectSample->setCurrentIndex(0);
        m_isOpenFile=false;
        this->chartClear();
    }
}





/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Module_MOD1102::Module_MOD1102(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Module_MOD1102)
{
    ui->setupUi(this);
    m_ADC_Offset.resize(2);
}

Module_MOD1102::~Module_MOD1102()
{
    delete ui;
}

void Module_MOD1102::closeEvent(QCloseEvent *event)
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
         if(m_echart)delete m_echart;
         m_displayTimer->deleteLater();
         if(m_edev_mod1101){
             m_edev_mod1101->close();
             delete m_edev_mod1101;
         }
         event->accept();
     }
}

void Module_MOD1102::motorGetStatus()
{
    //Contrl text of button Next and Pause
    //........button Next
    if(m_motorStatus==Module_MOD1102::motorNext&&m_sampleType!=Module_MOD1102::sampleAuto){
        if(ui->pushButton_Next->text()!=">>..")ui->pushButton_Next->setText(">>..");
        else ui->pushButton_Next->setText("..>>");
        }
    else {
        ui->pushButton_Next->setText("Bắt đầu");
    }
    //....button Pause
    if(m_motorStatus==Module_MOD1102::motorStop&&m_sampleType!=Module_MOD1102::sampleAuto){
        if(ui->pushButton_Stop->text()!="....")ui->pushButton_Stop->setText("....");
        else ui->pushButton_Stop->setText("..");
        }
    else {
        ui->pushButton_Stop->setText("Dừng");
    }
}


void Module_MOD1102::on_pushButton_Calib_clicked()
{
    if(m_deviceCalibration)delete m_deviceCalibration;
    m_deviceCalibration = new VDeviceCalibration();
    int _local_X = this->geometry().x()+(this->width()-m_deviceCalibration->width())/2;
    int _local_Y = this->geometry().y()+(this->height()-m_deviceCalibration->height())/2;
    m_deviceCalibration->setGeometry(_local_X,_local_Y,m_deviceCalibration->width(),m_deviceCalibration->height());
    m_deviceCalibration->setResolution(m_edev_mod1101->resolution());
    m_deviceCalibration->setTolerance(0.1);
    m_deviceCalibration->setCalibTime(30);
    m_deviceCalibration->setSampleNumber(300);
    m_deviceCalibration->setValueCalib_Y1(5);
    m_deviceCalibration->setUnit("(N)");
    m_deviceCalibration->setUnit(m_edev_mod1101->sensorUnitText());
    m_deviceCalibration->show();
}


void Module_MOD1102::on_pushButton_SetSampleTime_clicked()
{
    ui->pushButton_SetSampleTime->setEnabled(false);
        m_modbusSampleTime = ui->spinBox_SampleTime->value();
        m_edev_mod1101->setSampleTime(m_modbusSampleTime);
        ECharts::Parameter p;
        p = m_echart->parameter();
        p.axisX_Range_Max = ui->spinBox_AxitX_Range_Max->value()*(QVariant(m_edev_mod1101->sampleTime()).toDouble()/1000);
        m_echart->setParameter(p);
        this->chartClear();
}


void Module_MOD1102::on_pushButton_Next_clicked()
{
    if(m_isOpenFile)setOpenFile(false);
    m_motorStatus = Module_MOD1102::motorNext;
    if(m_sampleType==Module_MOD1102::sampleThreeStep){
        m_axtX_Index = 0;
        m_echart->setLinesIndexNext();
        if(m_echart->scanType()==ECharts::scanScroll)m_echart->chartAxisX->setRange(0,m_echart->chartAxisX->max());
    }
    ui->pushButton_Next->setEnabled(false);
    ui->pushButton_Stop->setEnabled(true);
}


void Module_MOD1102::on_pushButton_Cancel_clicked()
{
    this->close();
}

void Module_MOD1102::on_pushButton_Stop_clicked()
{
    m_motorStatus = Module_MOD1102::motorStop;
    ui->pushButton_Next->setEnabled(true);
    ui->pushButton_Stop->setEnabled(false);
}

void Module_MOD1102::on_comboBox_SelectSample_currentIndexChanged(int index)
{
    this->chartClear();
    m_motorStatus = Module_MOD1102::motorStop;
    switch (index) {
    case 0:m_sampleType = Module_MOD1102::sampleAuto;
        break;
    case 1:m_sampleType = Module_MOD1102::sampleWhenNext;
        break;
    case 2:m_sampleType = Module_MOD1102::sampleThreeStep;
        m_echart->setLinesIndexMax(3);
        break;
    }
    ui->pushButton_Next->setEnabled(true);
    ui->pushButton_Stop->setEnabled(false);
}

void Module_MOD1102::on_pushButton_ClearChart_clicked()
{
    if(m_isOpenFile)setOpenFile(false);
    else this->chartClear();
}

void Module_MOD1102::on_pushButton_SetConfigChart_clicked()
{
    if(ui->spinBox_AxisY_Range_Min->value()>=ui->spinBox_AxisY_Range_Max->value()){
        QMessageBox::information(this,"Cài đặt đồ thị","Dải đo \"Thấp\" phải nhỏ hơn dải đo \"Cao\"!",QMessageBox::Ok);
        return;
    }

    ECharts::Parameter p;
    p = m_echart->parameter();
    p.axisX_Range_Max = ui->spinBox_AxitX_Range_Max->value()*(QVariant(m_edev_mod1101->sampleTime()).toDouble()/1000);
    p.axisY_Range_Max= ui->spinBox_AxisY_Range_Max->value();
    p.axisY_Range_Min = ui->spinBox_AxisY_Range_Min->value();
    m_echart->setParameter(p);
    this->chartClear();
}

void Module_MOD1102::on_spinBox_SampleTime_valueChanged(int arg1)
{
        if(arg1>ui->spinBox_SampleTime->minimum())ui->pushButton_SetSampleTime->setEnabled(true);
}

void Module_MOD1102::on_radioButton_Accumulation_toggled(bool s)
{
    this->chartClear();
    if(s)m_echart->setScanType(ECharts::scanCompact);
    else m_echart->setScanType(ECharts::scanScroll);
}

void Module_MOD1102::on_pushButton_SaveData_clicked()
{
    VFile _file;
    VFile::VFileDataUnit _unit;
    for(int i=1;i<=m_echart->lines();i++){
        _unit.data.append(m_echart->vector(i));
    }
    _unit.device = m_deviceInformation;
    _unit.infoSample.interval = m_modbusSampleTime;
    _unit.infoSample.axisX_Max = m_echart->chartAxisX->max();
    _unit.infoSample.axisX_Min = m_echart->chartAxisX->min();
    _unit.infoSample.axisY_Max = m_echart->chartAxisY->max();
    _unit.infoSample.axisY_Min = m_echart->chartAxisY->min();

    switch(m_sampleType){
    case Module_MOD1102::sampleAuto:
        _unit.infoSample.count = 1;
        _unit.infoSample.typeSample = "Lấy mẫu tự động";
        _file.saveDatas(_unit);
        break;
    case Module_MOD1102::sampleWhenNext:
        _unit.infoSample.count = 1;
        _unit.infoSample.typeSample = "Lấy mẫu khi động cơ chạy \"Tiến\"";
        _file.saveDatas(_unit);
        break;
    case Module_MOD1102::sampleThreeStep:
        _unit.infoSample.count = _unit.data.count();
        _unit.infoSample.typeSample = "Lấy mẫu so sánh (3 đường đồ thị)";
        _file.saveDatas(_unit);
        break;
    }
    QPixmap p = this->grab();// m_chartView->grab();
    QFile filePNG(_file.fileName().left(_file.fileName().count()-4)+".png");
    filePNG.open(QIODevice::WriteOnly);
    p.save(&filePNG, "PNG");
}


void Module_MOD1102::on_pushButton_OpenData_clicked()
{
    VFile file;
    VFile::VFileDataUnit unit;
    unit = file.loadDatas();
    if(file.fileName()=="")return;
    if(unit.data.count()<1){
        QMessageBox::warning(nullptr,"Mở bản ghi","Đã xảy ra lỗi! Bản ghi không đúng định dạng dữ liệu hoặc không có dữ liệu được lưu. Error:\"" + file.error() + "\"",QMessageBox::Ok);
        return;
    }

    //Stop sampling
    m_isOpenFile = true;

    //update info for device
    this->setWindowTitle(unit.device.name());
    ui->label_Name->setText(unit.device.name());
    ui->label_Address->setText(QString::number(unit.device.address()));
    ui->label_SerialNumber->setText(unit.device.serialNumber());
    ui->label_Description->setText(unit.device.description());
    ui->spinBox_SampleTime->setValue(unit.infoSample.interval);
    ui->comboBox_SelectSample->setCurrentText(unit.infoSample.typeSample);

    //Update graphic
    m_echart->chartAxisX->setRange(unit.infoSample.axisX_Min,unit.infoSample.axisX_Max);
    m_echart->chartAxisY->setRange(unit.infoSample.axisY_Min,unit.infoSample.axisY_Max);
     //   m_echart->init();
    QSplineSeries* line;
    for(int i=0;i<unit.infoSample.count;i++){
        line = new QSplineSeries();
        double _y=0;
        int j=0;
        for(j=0;j<unit.data[i].count();j++){
            _y += QVariant(unit.infoSample.interval).toDouble()/1000;
            line->append(_y,unit.data[i][j]);
        }
        m_echart->setSplines(line,i+1);
    }
}

void Module_MOD1102::on_pushButton_setZero_clicked()
{
    ui->pushButton_setZero->setEnabled(false);
    QVector<quint16> values(2);
    values[0] = (m_edev_mod1101->REG_sen01_ADC()>>16)&0xFFFF;
    values[1] = (m_edev_mod1101->REG_sen01_ADC()&0xFFFF);
    m_SWS_Status = SWS_SetZero;
    m_edev_mod1101->writeZero(values);
    ui->pushButton_setZero->setEnabled(true);
}

void Module_MOD1102::on_comboBox_Unit_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_edev_mod1101->setSensorUnit(EDev_Mod1101::SSU_scaleForce);
        break;
    case 1:m_edev_mod1101->setSensorUnit(EDev_Mod1101::SSU_scaleGram);
        break;
    case 2:m_edev_mod1101->setSensorUnit(EDev_Mod1101::SSU_scaleKiloGram);
        break;
    case 3:m_edev_mod1101->setSensorUnit(EDev_Mod1101::SSU_scaleWeight);
        break;
    }
    this->chartInit();
    this->chartClear();
}

void Module_MOD1102::on_pushButton_TrackLine_Default_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}


void Module_MOD1102::on_pushButton_TrackLine_Tooltip_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_tooltip);
}


void Module_MOD1102::on_pushButton_TrackLine_Yax_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_y_ax);
}

