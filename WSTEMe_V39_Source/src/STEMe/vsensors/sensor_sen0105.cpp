#include "sensor_sen0105.h"
#include "ui_sensor_sen0105.h"




/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Sensor_SEN0105::setDeviceWidget(VDevice dev,VUser user)
{
   m_deviceInformation = dev;
    this->setWindowTitle(m_deviceInformation.name());
   ui->label_Name->setText(m_deviceInformation.name());
   ui->label_Address->setText(QString::number(m_deviceInformation.address()));
   ui->label_SerialNumber->setText(m_deviceInformation.serialNumber());
   ui->label_Description->setText(m_deviceInformation.description());
   //Check user
   m_user = user;

   //Create Sensor
   m_edev_sen0105 = new EDev_Sen0105();
   m_edev_sen0105->setSensorUnit(EDev_Sen0105::SSU_soundSPL);
   m_edev_sen0105->setSampleTime(m_modbusSampleTime);
   m_edev_sen0105->Start(dev);
   //Chart
   this->chartInit();
   if(m_chartTimer) delete m_chartTimer;
   m_chartTimer = new QTimer();
   connect(m_chartTimer,&QTimer::timeout,this,&Sensor_SEN0105::on_chartUpdate);
   m_chartTimer->start(m_chartInterval);
   m_soundLine = new QSplineSeries();
   this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
   m_frequencyToggle=false;
   m_VoltageToggle=false;
   m_LevelToggle=false;
    //Timer
    if(m_displayTimer)delete m_displayTimer;
    m_displayTimer = new QTimer();
    connect(m_displayTimer,&QTimer::timeout,this,&Sensor_SEN0105::on_displayTimer);
    m_displayTimer->start(m_displayInterval);

    ui->pushButton_Start->setEnabled(true);

    //get Config
    this->loadConfig();
    ui->spinBox_SoundSensitivity->setValue(m_configSave.voltageThreshold);
    ui->spinBox_SoundRepeat->setValue(m_configSave.voltageRepeat);

    //setMode
    this->on_comboBox_SelectSample_currentIndexChanged(ui->comboBox_SelectSample->currentIndex());
    ui->radioButton_Continuously->setChecked(true);
}


void Sensor_SEN0105::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_sen0105->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_sen0105->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_sen0105->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_sen0105->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_sen0105->resolution()));
            m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Writing);
            m_SWS_Status = SWS_Calib;
            break;
        case VDeviceCalibration::Calib_Writing:
            break;
        case VDeviceCalibration::Calib_Cancel:
            break;
        case VDeviceCalibration::Calib_Finished:
            break;
        case VDeviceCalibration::Calib_Error_Tolerance:
            break;
        case VDeviceCalibration::Calib_Error_Connect:
                break;
        }
    }
m_deviceCalibration->setConnectStatus(m_edev_sen0105->isConnect());

}

void Sensor_SEN0105::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Sensor_SEN0105::SWS_SetZero:
        break;
    case Sensor_SEN0105::SWS_Calib:
        if(status)m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Finished);
        else m_deviceCalibration->setCalibStatus(VDeviceCalibration::Calib_Error_Connect);
        break;
    case Sensor_SEN0105::SWS_default:
        return;
    }
    m_SWS_Status = Sensor_SEN0105::SWS_default;
}

void Sensor_SEN0105::calculateParametes(QVector<QPointF> value, int resolution)
{
        //Calculate
    if(value.count()<3){
         m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
         m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
         m_GET_SAMPLE_SUM=0;
         m_GET_SAMPLE_COUNT=0;
        return;
    }
    for(int i=1;i<value.count();i++){
        m_GET_SAMPLE_COUNT++;
        m_GET_SAMPLE_SUM+=value.at(i).y();
        if(m_GET_SAMPLE_MAX<value.at(i).y())m_GET_SAMPLE_MAX=value.at(i).y();
        if(m_GET_SAMPLE_MIN>value.at(i).y())m_GET_SAMPLE_MIN=value.at(i).y();

        //Display
        ui->label_ValueMax->setText(QString::number(m_GET_SAMPLE_MAX,'f',resolution));
        ui->label_ValueMin->setText(QString::number(m_GET_SAMPLE_MIN,'f',resolution));
        ui->label_ValueAvg->setText(QString::number((m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT),'f',resolution));
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Sensor_SEN0105::on_displayTimer()
{
    if(m_edev_sen0105->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_sen0105->setSampleTime(m_modbusSampleTime);
        m_edev_sen0105->update();
        switch (m_edev_sen0105->pollStatus()) {
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
            m_edev_sen0105->setPollStatus(ESensors::sensorIdle);
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        if(m_frequencyToggle)return;
        m_displayTimer->setInterval(500);
        m_edev_sen0105->setSampleTime(500);
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
    if(m_deviceCalibration)this->sensorCalibration(m_edev_sen0105->valueCalib(),m_edev_sen0105->value());
}
void Sensor_SEN0105::displayPoll()
{
    this->soundPoll();
}

void Sensor_SEN0105::on_chartUpdate()
{
    switch (m_soundType) {
        case SoundType::typeSoundLevel:
            break;
        case SoundType::typeSoundReflection:this->soundReflectionChart();
             break;
        case SoundType::typeSoundFrequency:this->soundFrequencyRead();
             break;
        case SoundType::typeSoundVoltage:
         break;
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...

void Sensor_SEN0105::chartInit()
{
    if(m_echart)delete m_echart;
    m_echart = new EChartLines();
    EChartLines::Parameter parameter;
    parameter.timerScan = m_modbusSampleTime;
    parameter.axisX_Range_Max = m_axisX_Range;
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(3);
    m_echart->setAxisXName("mili giây (ms)");
    m_echart->setAxisYName(ui->comboBox_Unit->currentText());
    m_echart->init(parameter,3,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_edev_sen0105->sampleTime()).toDouble()))).toInt());//Scan in 1 hour
    if(ui->radioButton_Accumulation->isChecked())m_echart->setScanType(EChartLines::scanCompact);
        else m_echart->setScanType(EChartLines::scanScroll);
}

void Sensor_SEN0105::chartInit(QSplineSeries *Line)
{
    if(m_echart)delete m_echart;
    m_echart = new EChartLines();
    EChartLines::Parameter parameter;
    parameter.timerScan = m_modbusSampleTime;
    parameter.axisX_Range_Max = m_axisX_Range;
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(3);
    m_echart->setAxisXName("Thời gian");
    m_echart->setAxisYName(ui->comboBox_Unit->currentText());
    m_echart->init(parameter,Line,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(m_edev_sen0105->sampleTime()).toDouble()))).toInt());//Scan in 1 hour
}

void Sensor_SEN0105::chartGraph(double val)
{
    if(m_isOpenFile)return;
    //Check graphType
    m_axtX_Index += QVariant(m_edev_sen0105->sampleTime()).toDouble()/1000;
    m_echart->graph(QPointF(m_axtX_Index,val));
}

void Sensor_SEN0105::chartGraph(QPointF val)
{
    if(m_isOpenFile)return;
    //Check graphType
    m_echart->graph(val);
}

void Sensor_SEN0105::chartGraph(QVector<QPointF> val)
{
    if(m_isOpenFile)return;
    QPointF _res;
    for(int i=0;i<val.count();i++){
      m_axtX_Index += 1.0/m_soundFrequency;
      _res = val.at(i);
      _res.setX(m_axtX_Index);
      val.replace(i,_res);
    }
    if(m_axtX_Index>=m_echart->chartAxisX->max()){
        this->chartClear();
    }
    else m_echart->graph(val);
}

void Sensor_SEN0105::chartClear()
{
    m_echart->clear();
    m_echart->setLinesIndex(1);
    m_axtX_Index=0;
    m_soundLine->clear();
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
    m_Time_Line = 0;
    this->chartGraph(QPointF(m_Time_Line,0));
}

void Sensor_SEN0105::setTrackLine(EChartGesture::ETrackLine track)
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


void Sensor_SEN0105::setOpenFile(bool status)
{
    if(status)m_isOpenFile=true;
    else{
        this->setDeviceWidget(m_deviceInformation,m_user);
        ui->comboBox_SelectSample->setCurrentIndex(0);
        m_isOpenFile=false;
        this->chartClear();
    }
}

void Sensor_SEN0105::soundPoll()
{
    switch(m_soundType){
    case SoundType::typeSoundLevel:this->soundLevel();
        break;
    case SoundType::typeSoundReflection:this->soundReflection();
        break;
    case SoundType::typeSoundFrequency:this->soundFrequency();
        break;
    case SoundType::typeSoundVoltage:this->soundVoltage();
        break;
    }
}

void Sensor_SEN0105::soundLevel()
{
    double _valSound=m_edev_sen0105->value();
    switch(ui->comboBox_Unit->currentIndex()){
    case 0:
        break;
    case 1:_valSound=m_edev_sen0105->sensorVoltage();
        break;
    }
    //get average of value
    _valSound = m_edev_sen0105->getPrecision(_valSound,ui->spinBox_Display_Unit_Pre->value());
    ui->lcdNumber_Value->display(_valSound);
    if(m_LevelToggle&&m_edev_sen0105->isUpdateData()){
        m_Time_Line += m_edev_sen0105->elapsed();
        this->chartGraph(QPointF(m_Time_Line,_valSound));
        calculateParametes(m_echart->lines(1),ui->spinBox_Display_Unit_Pre->value());
        }
}

void Sensor_SEN0105::soundVoltage()
{
double _valSound=m_edev_sen0105->voltage();
//get average of value
_valSound = m_edev_sen0105->getPrecision(_valSound,ui->spinBox_Display_Unit_Pre->value());
ui->lcdNumber_Value->display(_valSound);
//Graph
if(m_VoltageToggle){
    m_Time_Line += m_edev_sen0105->elapsed();
    this->chartGraph(QPointF(m_Time_Line,_valSound));
    calculateParametes(m_echart->lines(1),ui->spinBox_Display_Unit_Pre->value());
    }
}

void Sensor_SEN0105::soundReflection()
{
    //calculate basic parameters
    if(m_soundStatus == soundSampling){
        QString str="Đang lấy mẫu (";
        if(m_soundLine->count()<100000)m_edev_sen0105->valueSoundAppend(m_soundLine,QVariant(m_soundTimeQueryData).toDouble(),true);
        m_soundTimeQueryData = 0;
        str = str+ QString::number(m_soundTimeSample)+")";
        ui->pushButton_Start->setText(QString::number(m_soundTimeSample));
    }
    if(m_soundStatus == soundWait){
        m_soundStatus = soundSampling;
        m_soundTimeQueryData=0;
        m_edev_sen0105->setFrequency(this->soundGetFrequency());
    }
}

void Sensor_SEN0105::soundReflectionChart()
{
    // double _deltaTime;
    // ELowPassFilter *lpf;
     m_soundTimeQueryData++;
    // m_chartTimer->stop();
     switch(m_soundStatus){
     case soundStart:
         m_soundTimeSample = 1000;
         m_edev_sen0105->valueSoundAppend(m_soundLine,m_soundFrequency,false);
         m_GET_SAMPLE_SUM = 0;
         m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
         m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
         m_GET_SAMPLE_COUNT = 0;
         m_soundStatus=soundWait;
         m_echart->clear();
         break;
     case soundWait:
         break;
     case soundSampling:
         m_soundTimeSample--;
         if(m_soundTimeSample<1){
             m_soundStatus=soundFilter;
             ui->pushButton_Start->setText("Bắt đầu");
             ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
             ui->pushButton_Start->setEnabled(true);
         }
         break;
     case soundFilter:
         m_soundStatus=soundChart;
         break;
     case soundChart:
         m_chartTimer->stop();
         if(m_soundLine->count()>0&&m_echart){
         m_echart->chartAxisX->setRange(0,m_edev_sen0105->samples());
         m_echart->chartAxisY->setRange(0,m_edev_sen0105->avg()*2);
         QSplineSeries *line = new QSplineSeries();
         for(int i=0;i<m_soundLine->count();i++)line->append(m_soundLine->at(i));
         m_echart->setSplines(line,1);
         }
         m_chartTimer->start(1);
         //Display
         if(m_soundLine->count()>0){
             ui->label_ValueMax->setText(QString::number(m_edev_sen0105->max(),'f',3));
             ui->label_ValueMin->setText(QString::number(m_edev_sen0105->min(),'f',3));
             ui->label_ValueAvg->setText(QString::number(m_edev_sen0105->avg(),'f',3));
         }
         m_soundStatus=soundStop;
         break;
     case soundStop:
         break;
     case soundError:
         break;
     }
}

void Sensor_SEN0105::soundFrequency()
{
    double _valSound=0;
    _valSound = m_edev_sen0105->frequency();
    //get average of value
    if(!m_frequencyToggle){
        ui->lcdNumber_Value->display(QString::number(0,'f',0));
        m_chartTime_AxisX=0;
    }
    else{
        ui->lcdNumber_Value->display(QString::number(_valSound,'f',0));
        this->chartGraph(QPointF(m_chartTime_AxisX,_valSound));
    }
}

void Sensor_SEN0105::soundFrequencyRead()
{
    if(m_frequencyToggle)m_chartTime_AxisX+=0.001;
    switch(m_frequencyStatus){
    case FrequencyStatus::freqIdle:
        if(m_frequencyToggle){
            m_soundTimeSample = 1200;
            m_edev_sen0105->setFrequency(soundGetFrequency());
            m_frequencyStatus = freqRead;
        }
        else{
            if(!ui->comboBox_SelectSample->isEnabled())ui->comboBox_SelectSample->setEnabled(true);
        }
        break;
    case FrequencyStatus::freqRead:
        if(m_soundTimeSample--<1){
           m_frequencyStatus = freqIdle;
        }
        break;
    }
}

QVector<quint16> Sensor_SEN0105::soundGetFrequency()
{
 QVector<quint16> _val;
 quint16 _pulse=0;
 quint16 _time=0;
 //
 switch (m_soundType) {
     case SoundType::typeSoundLevel:_val.append(0);
        break;
     case SoundType::typeSoundReflection:_val.append(1);
        break;
     case SoundType::typeSoundFrequency:
     _val.append(2);
     _pulse = QVariant(ui->spinBox_SoundSensitivity->value()).toUInt()&0xFFFF;
     _time = QVariant(ui->spinBox_SoundRepeat->value()).toUInt()&0xFFFF;
        break;
    case SoundType::typeSoundVoltage:_val.append(4);
        break;
     }
 _val.append(_time);
 _val.append(_pulse);
 return _val;
}


/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

Sensor_SEN0105::Sensor_SEN0105(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor_SEN0105)
{
    ui->setupUi(this);
    VDevice::deviceWidgetInstances.push_back(this);

}

Sensor_SEN0105::~Sensor_SEN0105()
{
    delete ui;
    VDevice::deviceWidgetInstances.removeOne(this);
}
void Sensor_SEN0105::closeEvent(QCloseEvent *event)
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
         m_edev_sen0105->close();
         event->accept();
     }
}

void Sensor_SEN0105::loadConfig()
{
     QSettings settings("ELEVOI","VDAT");
     m_configSave.voltageThreshold = settings.value("voltageThreshold","300").toInt();
     m_configSave.voltageRepeat = settings.value("voltageRepeat","10").toInt();
}

void Sensor_SEN0105::saveConfig()
{
    QSettings settings("ELEVOI","VDAT");
    settings.setValue("voltageThreshold",m_configSave.voltageThreshold);
    settings.setValue("voltageRepeat",m_configSave.voltageRepeat);
}

void Sensor_SEN0105::on_pushButton_Calib_clicked()
{
    if(m_deviceCalibration)delete m_deviceCalibration;
    m_deviceCalibration = new VDeviceCalibration();
    int _local_X = this->geometry().x()+(this->width()-m_deviceCalibration->width())/2;
    int _local_Y = this->geometry().y()+(this->height()-m_deviceCalibration->height())/2;
    m_deviceCalibration->setGeometry(_local_X,_local_Y,m_deviceCalibration->width(),m_deviceCalibration->height());
    m_deviceCalibration->setResolution(m_edev_sen0105->resolution());
    m_deviceCalibration->setTolerance(0.1);
    m_deviceCalibration->setCalibTime(60);
    m_deviceCalibration->setSampleNumber(600);
    m_deviceCalibration->setValueCalib_Y1(100);
    m_deviceCalibration->setUnit(m_edev_sen0105->sensorUnitText());
    m_deviceCalibration->show();
}

void Sensor_SEN0105::on_pushButton_Exit_clicked()
{
    this->close();
}

void Sensor_SEN0105::on_comboBox_Unit_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_edev_sen0105->setSensorUnit(EDev_Sen0105::SSU_soundSPL);
        break;
    case 1:m_edev_sen0105->setSensorUnit(EDev_Sen0105::SSU_soundDecibel);
        break;
    case 2:m_edev_sen0105->setSensorUnit(EDev_Sen0105::SSU_soundVolt);
        break;
    }
}

void Sensor_SEN0105::on_pushButton_OpenData_clicked()
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
    ui->comboBox_SelectSample->setCurrentText(unit.infoSample.typeSample);

    //Update graphic
    m_echart->init();
    m_echart->chartAxisX->setRange(unit.infoSample.axisX_Min,unit.infoSample.axisX_Max);
    m_echart->chartAxisY->setRange(unit.infoSample.axisY_Min,unit.infoSample.axisY_Max);
    QSplineSeries* line;
    for(int i=0;i<unit.infoSample.count;i++){
        line = new QSplineSeries();
        for(int j=0;j<unit.data[i].count();j++)line->append(j,unit.data[i][j]);
        m_echart->setSplines(line,i+1);
    }
}

void Sensor_SEN0105::on_pushButton_SaveData_clicked()
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
    _unit.infoSample.count = 1;
    _unit.infoSample.typeSample = "Lấy mẫu tự động";
    _file.saveDatas(_unit);
    QPixmap p = this->grab();// m_chartView->grab();
    QFile filePNG(_file.fileName().left(_file.fileName().count()-4)+".png");
    filePNG.open(QIODevice::WriteOnly);
    p.save(&filePNG, "PNG");
    QMessageBox::warning(nullptr,"Mở bản ghi","Đã xảy ra lỗi! Bản ghi không đúng định dạng dữ liệu hoặc không có dữ liệu được lưu. Error",QMessageBox::Ok);
}

void Sensor_SEN0105::on_pushButton_Start_clicked()
{
    if(m_isOpenFile)setOpenFile(false);
    ui->pushButton_Start->setEnabled(false);
    switch (m_soundType) {
        case SoundType::typeSoundLevel:
            if(m_LevelToggle){
                ui->pushButton_Start->setText("Tiếp tục");
                ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
                ui->pushButton_Start->setEnabled(true);
                m_LevelToggle = false;
                }
                else{
                    ui->pushButton_Start->setText("Dừng");
                    ui->pushButton_Start->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(255, 0, 0);");
                    ui->pushButton_Start->setEnabled(true);
                    m_LevelToggle = true;
                }
            break;
        case SoundType::typeSoundReflection:
            m_echart->clear();
            m_edev_sen0105->setFrequency(soundGetFrequency());
            m_soundStatus=soundStart;
            ui->pushButton_Start->setText("Đang cài đặt");
            ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(255, 0, 0);");
             break;
        case SoundType::typeSoundFrequency:
            if(m_frequencyToggle==false){
                m_edev_sen0105->setFrequency(soundGetFrequency());
                ui->pushButton_Start->setText("Đang đo âm thoa...");
                ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(255, 0, 0);");
                ui->comboBox_SelectSample->setEnabled(false);
                m_configSave.voltageThreshold = ui->spinBox_SoundSensitivity->value();
                m_configSave.voltageRepeat = ui->spinBox_SoundRepeat->value();
                this->saveConfig();
                if(m_echart){
                    m_echart->setScanType(EChartLines::ScanType::scanCompact);
                    m_echart->chartAxisX->setRange(0,1);
                    m_echart->chartAxisY->setRange(0,10);
                    m_echart->clear();
                    m_chartTime_AxisX=0;
                    this->chartGraph(QPointF(0,0));
                }
                m_frequencyToggle = true;
            }
            else{
                ui->pushButton_Start->setText("Bắt đầu");
                ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
                m_frequencyToggle = false;
            }
            ui->pushButton_Start->setEnabled(true);
            break;
        case SoundType::typeSoundVoltage:
            if(m_VoltageToggle){
                ui->pushButton_Start->setText("Tiếp tục");
                ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
                ui->pushButton_Start->setEnabled(true);
                m_VoltageToggle = false;
                }
                else{
                    ui->pushButton_Start->setText("Dừng");
                    ui->pushButton_Start->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(255, 0, 0);");
                    ui->pushButton_Start->setEnabled(true);
                    m_VoltageToggle = true;
                }
            break;
        }
}

void Sensor_SEN0105::on_comboBox_SelectSample_currentIndexChanged(int index)
{
    m_modbusSampleTime=100;
    switch(index){
    case 0:m_soundType = SoundType::typeSoundLevel;
        m_edev_sen0105->setFrequency(soundGetFrequency());
        ui->pushButton_Start->setText("Bắt đầu");
        ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
        ui->pushButton_Start->setEnabled(true);
        m_LevelToggle=false;
        ui->comboBox_Unit->setCurrentIndex(0);
        break;
    case 1:m_soundType = SoundType::typeSoundReflection;
        ui->pushButton_Start->setText("Bắt đầu");
        ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
        ui->pushButton_Start->setEnabled(true);
        ui->comboBox_Unit->setCurrentIndex(2);
        break;
    case 2:m_soundType = SoundType::typeSoundFrequency;
       // m_edev_sen0105->setFrequency(soundGetFrequency());
        ui->pushButton_Start->setText("Đo tần số");
        ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
        ui->pushButton_Start->setEnabled(true);
        ui->comboBox_SelectSample->setEnabled(false);
        ui->comboBox_Unit->setCurrentIndex(1);
        break;
    case 3:m_soundType = typeSoundVoltage;
        m_edev_sen0105->setFrequency(soundGetFrequency());
        ui->pushButton_Start->setText("Bắt đầu");
        ui->pushButton_Start->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
        ui->pushButton_Start->setEnabled(true);
        m_VoltageToggle = false;
        ui->comboBox_Unit->setCurrentIndex(2);
        m_modbusSampleTime = 300;
        break;
    }
    m_edev_sen0105->setSampleTime(m_modbusSampleTime);
    this->chartClear();
    ui->label_ValueMax->setText(QString::number(0,'f',0));
    ui->label_ValueMin->setText(QString::number(0,'f',0));
    ui->label_ValueAvg->setText(QString::number(0,'f',0));
}

void Sensor_SEN0105::on_pushButton_ClearChart_clicked()
{
    if(m_isOpenFile)setOpenFile(false);
    else this->chartClear();
}

void Sensor_SEN0105::on_radioButton_Accumulation_toggled(bool checked)
{
    this->chartClear();
    if(checked)m_echart->setScanType(EChartLines::scanCompact);
    else m_echart->setScanType(EChartLines::scanScroll);
}

void Sensor_SEN0105::on_pushButton_TrackLine_Default_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Sensor_SEN0105::on_pushButton_TrackLine_Tooltip_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_tooltip);
}

void Sensor_SEN0105::on_pushButton_TrackLine_Yax_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_y_ax);
}
