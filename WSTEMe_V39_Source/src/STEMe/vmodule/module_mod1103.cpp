#include "module_mod1103.h"
#include "ui_module_mod1103.h"

QT_CHARTS_USE_NAMESPACE


/////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...

void Module_MOD1103::setDeviceWidget(VDevice dev,VUser user)
{
   m_deviceInformation = dev;
   this->setWindowTitle(m_deviceInformation.name());
   ui->label_Name->setText(m_deviceInformation.name());
   ui->label_Address->setText(QString::number(m_deviceInformation.address()));
   ui->label_SerialNumber->setText(m_deviceInformation.serialNumber());
   ui->label_Description->setText(m_deviceInformation.description());
    //Check user
   m_user = user;
   if(user.accountType()!=VUser::root)ui->groupBox_Car_Setup->setEnabled(false);
   //Create Sensor
   m_edev_mod1103 = new EDev_Mod1103();
   //Update units for car-01
   m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::DistanceUnits::DSU_millimetre);
   m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SSU_scaleForce);
   m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::TMU_Second);
   m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SPU_mm_per_second);
   m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::ACU_mm_per_s2);
   m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::VTU_Volt);
   m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_01,true);
   //Update units for car-02
   m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::DistanceUnits::DSU_millimetre);
   m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SSU_scaleForce);
   m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::TMU_Second);
   m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SPU_mm_per_second);
   m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::ACU_mm_per_s2);
   m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::VTU_Volt);
   m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_02,true);
   //for Car
   m_edev_mod1103->setSampleTime(m_modbusSampleTime);
   m_edev_mod1103->Start(dev);

   //Chart
   m_typeLine = EDev_Mod1103::TypeLine::typeSpline;
   m_edev_mod1103->setTypeLine(m_typeLine);
   this->chartInit();
   //Display Timer
    if(m_displayTimer)delete m_displayTimer;
    m_displayTimer = new QTimer();
    connect(m_displayTimer,&QTimer::timeout,this,&Module_MOD1103::on_displayTimer);
    m_displayTimer->start(m_displayInterval);

    ui->spinBox_SampleTime->setValue(m_modbusSampleTime);
    if(m_mod1103_Condition)delete m_mod1103_Condition;
    m_mod1103_Condition = new Module_MOD1103_Condition(this);
    connect(m_mod1103_Condition,&Module_MOD1103_Condition::setCondition,this,&Module_MOD1103::on_setCondition);
    connect(m_mod1103_Condition,&Module_MOD1103_Condition::setSetting,this,&Module_MOD1103::on_setSetting);
    m_mod1103_Condition->setGeometry(this->getLocal_X(ui->tabWidget->geometry(),m_mod1103_Condition->width()),\
                                  this->getLocal_Y(ui->tabWidget->geometry(),m_mod1103_Condition->height()),m_mod1103_Condition->width(),m_mod1103_Condition->height());


    //Tab setup
    ui->frame_Filter->setEnabled(ui->checkBox_Filter->isChecked());
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Module_MOD1103::sensorCalibration(double valueCalib,double valueRaw)
{
    if(m_edev_mod1103->isConnect()){
        m_deviceCalibration->setCalibrating(valueCalib,valueRaw);
        switch(m_deviceCalibration->calibStatus()){
        case VDeviceCalibration::Calib_default:
            m_edev_mod1103->setSampleTime(m_modbusSampleTime);
            break;
        case VDeviceCalibration::Calib_Sampling_OnePoint:
            m_edev_mod1103->setSampleTime(m_deviceCalibration->sampleTime());
            break;
        case VDeviceCalibration::Calib_Sampling_TwoPoint:
            break;
        case VDeviceCalibration::Calib_Sampling_ThreePoint:
            break;
        case VDeviceCalibration::Calib_WriteData:
            m_edev_mod1103->writeCalib(m_deviceCalibration->pointCalib(),m_deviceCalibration->valueCalib(m_edev_mod1103->resolution()));
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
    m_deviceCalibration->setConnectStatus(m_edev_mod1103->isConnect());
}

void Module_MOD1103::setInfoCalib()
{
    if(m_user.accountType()==VUser::root){
    }
}

void Module_MOD1103::sensorWriteReport(bool status)
{
    switch(m_SWS_Status){
    case Module_MOD1103::SWS_SetZero:
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
        break;
    case Module_MOD1103::SWS_Calib:
        m_QMessageBox = new QMessageBox();
        m_QMessageBox->setText(m_msgInfo);
        m_QMessageBox->setWindowTitle("Lệnh cài đặt");
        m_QMessageBox->show();
        break;
    case Module_MOD1103::SWS_SetCommand:
        m_commandCheckStatus = true;
        break;
    case Module_MOD1103::SWS_default:
        return;
    }
            m_SWS_Status = Module_MOD1103::SWS_default;

}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Module_MOD1103::on_displayTimer()
{
    if(m_edev_mod1103->isConnect()){
        m_displayTimer->setInterval(m_displayInterval);
        m_edev_mod1103->setSampleTime(m_modbusSampleTime);
        m_edev_mod1103->update();
        switch (m_edev_mod1103->pollStatus()) {
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
            m_edev_mod1103->setPollStatus(ESensors::sensorIdle);
            this->commandCheck();
            break;
        case ESensors::sensorWriteReply:
            sensorWriteReport(true);
            break;
        }
    }
    else {
        m_displayTimer->setInterval(500);
        m_edev_mod1103->setSampleTime(500);
        if(m_displayToggle){
            ui->lcdNumber_Value_1->display(-1);
            ui->lcdNumber_Value_2->display(-1);
            m_displayToggle=false;
        }
        else {
            ui->lcdNumber_Value_1->display(0);
            ui->lcdNumber_Value_2->display(-1);
            m_displayToggle=true;
        }
    }
    //Chart Calib
    if(m_deviceCalibration)this->sensorCalibration(m_edev_mod1103->valueCalib(),m_edev_mod1103->value());
    //
    //Chart Graph
    this->measurePoll();
}


void Module_MOD1103::displayPoll()
{
    //get Car
    m_edev_mod1103->sensorUpdate();
    m_eCar_01 = m_edev_mod1103->sensorCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_02 = m_edev_mod1103->sensorCar(EDev_Mod1103::ESlave::CAR_02);
    //Check tabWidget
    if(ui->tabWidget->currentWidget()->objectName()=="tabParameter"){
        this->updateTabParameter();
    }
    if(ui->tabWidget->currentWidget()->objectName()=="tabDisplay"){
        if(m_CDP_conditionProcess == EDev_Mod1103::CDP_default)this->updateTabDisplay();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
void Module_MOD1103::chartInit()
{
    m_edev_mod1103->setChartTimeScan(ui->spinBox_SampleTime->value());
    //Set color for lines XE - 01
    m_edev_mod1103->replaceListLineColor(0,ui->checkBox_Car01_S->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(1,ui->checkBox_Car01_V->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(2,ui->checkBox_Car01_A->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(3,ui->checkBox_Car01_F->palette().color(QPalette::Text));
    //Set color for lines XE - 02
    m_edev_mod1103->replaceListLineColor(4,ui->checkBox_Car02_S->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(5,ui->checkBox_Car02_V->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(6,ui->checkBox_Car02_A->palette().color(QPalette::Text));
    m_edev_mod1103->replaceListLineColor(7,ui->checkBox_Car02_F->palette().color(QPalette::Text));
    m_edev_mod1103->chartInit(ui->frame_Chart_Display,m_typeLine);
    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        if(ui->radioButton_Accumulation->isChecked())m_edev_mod1103->setScanType(ECharts::scanCompact);
            else m_edev_mod1103->setScanType(ECharts::scanScroll);
        }
        else{
        if(ui->radioButton_Accumulation->isChecked())m_edev_mod1103->setScanType(EChartLines::scanCompact);
            else m_edev_mod1103->setScanType(EChartLines::scanScroll);
        }
}

void Module_MOD1103::chartGraph(QPointF vals,int lines)
{
    if(m_isOpenFile)return;
    //Check graphType
    m_edev_mod1103->graph(vals,lines);
}

void Module_MOD1103::chartGraph(EDev_Mod1103::ECarLines line01,EDev_Mod1103::ECarLines line02)
{
    int _precision=0;
    if(line01.line_index>0){
        //For CAR_01
            if(ui->checkBox_Car01_S->isChecked()){
                this->setSpline(line01.line_s,1);
                if(m_eCar_01.s.pre>_precision)_precision=m_eCar_01.s.pre;
            }
            if(ui->checkBox_Car01_V->isChecked()){
                this->setSpline(line01.line_v,2);
                if(m_eCar_01.v.pre>_precision)_precision=m_eCar_01.v.pre;
            }
            if(ui->checkBox_Car01_A->isChecked()){
                this->setSpline(line01.line_a,3);
                if(m_eCar_01.a.pre>_precision)_precision=m_eCar_01.a.pre;
            }
            if(ui->checkBox_Car01_F->isChecked()){
                this->setSpline(line01.line_f,4);
                if(m_eCar_01.f.pre>_precision)_precision=m_eCar_01.f.pre;
            }
    }
    if(line02.line_index>0){
        //For CAR_02
            if(ui->checkBox_Car02_S->isChecked()){
                this->setSpline(line02.line_s,5);
                if(m_eCar_02.s.pre>_precision)_precision=m_eCar_02.s.pre;
            }
            if(ui->checkBox_Car02_V->isChecked()){
                this->setSpline(line02.line_v,6);
                if(m_eCar_02.v.pre>_precision)_precision=m_eCar_02.v.pre;
            }
            if(ui->checkBox_Car02_A->isChecked()){
                this->setSpline(line02.line_a,7);
                if(m_eCar_02.a.pre>_precision)_precision=m_eCar_02.a.pre;
            }
            if(ui->checkBox_Car02_F->isChecked()){
                this->setSpline(line02.line_f,8);
                if(m_eCar_02.f.pre>_precision)_precision=m_eCar_02.f.pre;
            }
            m_edev_mod1103->setPrecisionXY(m_eCar_01.t.pre,_precision);
    }
}

void Module_MOD1103::chartGraph(EDev_Mod1103::ECarSPlines line01, EDev_Mod1103::ECarSPlines line02)
{
    int _precision=0;
    if(line01.line_index>0){
        //For CAR_01
            if(ui->checkBox_Car01_S->isChecked()){
                this->setSpline(line01.line_s,1);
                if(m_eCar_01.s.pre>_precision)_precision=m_eCar_01.s.pre;
            }
            if(ui->checkBox_Car01_V->isChecked()){
                this->setSpline(line01.line_v,2);
                if(m_eCar_01.v.pre>_precision)_precision=m_eCar_01.v.pre;
            }
            if(ui->checkBox_Car01_A->isChecked()){
                this->setSpline(line01.line_a,3);
                if(m_eCar_01.a.pre>_precision)_precision=m_eCar_01.a.pre;
            }
            if(ui->checkBox_Car01_F->isChecked()){
                this->setSpline(line01.line_f,4);
                if(m_eCar_01.f.pre>_precision)_precision=m_eCar_01.f.pre;
            }
    }
    if(line02.line_index>0){
        //For CAR_02
            if(ui->checkBox_Car02_S->isChecked()){
                this->setSpline(line02.line_s,5);
                if(m_eCar_02.s.pre>_precision)_precision=m_eCar_02.s.pre;
            }
            if(ui->checkBox_Car02_V->isChecked()){
                this->setSpline(line02.line_v,6);
                if(m_eCar_02.v.pre>_precision)_precision=m_eCar_02.v.pre;
            }
            if(ui->checkBox_Car02_A->isChecked()){
                this->setSpline(line02.line_a,7);
                if(m_eCar_02.a.pre>_precision)_precision=m_eCar_02.a.pre;
            }
            if(ui->checkBox_Car02_F->isChecked()){
                this->setSpline(line02.line_f,8);
                if(m_eCar_02.f.pre>_precision)_precision=m_eCar_02.f.pre;
            }
            m_edev_mod1103->setPrecisionXY(m_eCar_01.t.pre,_precision);
    }
}
void Module_MOD1103::chartGraphContinous(EDev_Mod1103::ECarLines line01,EDev_Mod1103::ECarLines line02)
{
    if(line01.line_index>0){
        //For CAR_01
        if(m_graphIndex_01.index_s<line01.line_s->count()){
            if(ui->checkBox_Car01_S->isChecked())this->chartGraph(line01.line_s->at(m_graphIndex_01.index_s),1);
            m_graphIndex_01.index_s++;
            }
        if(m_graphIndex_01.index_v<line01.line_v->count()){
            if(ui->checkBox_Car01_V->isChecked())this->chartGraph(line01.line_v->at(m_graphIndex_01.index_v),2);
            m_graphIndex_01.index_v++;
            }
        if(m_graphIndex_01.index_a<line01.line_a->count()){
            if(ui->checkBox_Car01_A->isChecked())this->chartGraph(line01.line_a->at(m_graphIndex_01.index_a),3);
            m_graphIndex_01.index_a++;
            }
        if(m_graphIndex_01.index_f<line01.line_f->count()){
            if(ui->checkBox_Car01_F->isChecked())this->chartGraph(line01.line_f->at(m_graphIndex_01.index_f),4);
            m_graphIndex_01.index_f++;
            }
    }
    if(line02.line_index>0){
        //For CAR_02
        if(m_graphIndex_02.index_s<line02.line_s->count()){
            if(ui->checkBox_Car02_S->isChecked())this->chartGraph(line02.line_s->at(m_graphIndex_02.index_s),5);
            m_graphIndex_02.index_s++;
            }
        if(m_graphIndex_02.index_v<line02.line_v->count()){
            if(ui->checkBox_Car02_V->isChecked())this->chartGraph(line02.line_v->at(m_graphIndex_02.index_v),6);
            m_graphIndex_02.index_v++;
            }
        if(m_graphIndex_02.index_a<line02.line_a->count()){
            if(ui->checkBox_Car02_A->isChecked())this->chartGraph(line02.line_a->at(m_graphIndex_02.index_a),7);
            m_graphIndex_02.index_a++;
            }
        if(m_graphIndex_02.index_f<line02.line_f->count()){
            if(ui->checkBox_Car02_F->isChecked())this->chartGraph(line02.line_f->at(m_graphIndex_02.index_f),8);
            m_graphIndex_02.index_f++;
        }
    }
}

void Module_MOD1103::chartGraphContinous(EDev_Mod1103::ECarSPlines line01, EDev_Mod1103::ECarSPlines line02)
{
    if(line01.line_index>0){
        //For CAR_01
        if(m_graphIndex_01.index_s<line01.line_s->count()){
            if(ui->checkBox_Car01_S->isChecked())this->chartGraph(line01.line_s->at(m_graphIndex_01.index_s),1);
            m_graphIndex_01.index_s++;
            }
        if(m_graphIndex_01.index_v<line01.line_v->count()){
            if(ui->checkBox_Car01_V->isChecked())this->chartGraph(line01.line_v->at(m_graphIndex_01.index_v),2);
            m_graphIndex_01.index_v++;
            }
        if(m_graphIndex_01.index_a<line01.line_a->count()){
            if(ui->checkBox_Car01_A->isChecked())this->chartGraph(line01.line_a->at(m_graphIndex_01.index_a),3);
            m_graphIndex_01.index_a++;
            }
        if(m_graphIndex_01.index_f<line01.line_f->count()){
            if(ui->checkBox_Car01_F->isChecked())this->chartGraph(line01.line_f->at(m_graphIndex_01.index_f),4);
            m_graphIndex_01.index_f++;
            }
    }
    if(line02.line_index>0){
        //For CAR_02
        if(m_graphIndex_02.index_s<line02.line_s->count()){
            if(ui->checkBox_Car02_S->isChecked())this->chartGraph(line02.line_s->at(m_graphIndex_02.index_s),5);
            m_graphIndex_02.index_s++;
            }
        if(m_graphIndex_02.index_v<line02.line_v->count()){
            if(ui->checkBox_Car02_V->isChecked())this->chartGraph(line02.line_v->at(m_graphIndex_02.index_v),6);
            m_graphIndex_02.index_v++;
            }
        if(m_graphIndex_02.index_a<line02.line_a->count()){
            if(ui->checkBox_Car02_A->isChecked())this->chartGraph(line02.line_a->at(m_graphIndex_02.index_a),7);
            m_graphIndex_02.index_a++;
            }
        if(m_graphIndex_02.index_f<line02.line_f->count()){
            if(ui->checkBox_Car02_F->isChecked())this->chartGraph(line02.line_f->at(m_graphIndex_02.index_f),8);
            m_graphIndex_02.index_f++;
        }
    }
}
void Module_MOD1103::setSpline(QSplineSeries *series, int line)
{
    if(series->count()<1)return;
    //Fillter
    double _max_x,_max_y,_min_x,_min_y,_val,_gain_y=0;
    double _deltaTime=0,_freq=1;
    bool ok;
    QSplineSeries *spline = new QSplineSeries();
    _val = ui->lineEdit_Filter_Freq->text().toDouble(&ok);
    if(ok)_freq = _val;
    _deltaTime = series->at(series->count()-1).x()/QVariant(series->count()).toDouble();
    ELowPassFilter *lpf = new ELowPassFilter(_freq,_deltaTime);
    lpf->setFilterType(ELowPassFilter::FilterType::filter_lpf);

    _max_x = _max_y = _gain_y = QVariant(std::numeric_limits<double>::min()).toDouble();
    _min_x = _min_y = QVariant(std::numeric_limits<double>::max()).toDouble();
    for(int i=0;i<series->count();i++){
        //Check min,max for x
        _val = series->at(i).x();
        if(_val>_max_x)_max_x=_val;
        if(_val<_min_x)_min_x=_val;
        //Check min,max for y
        _val = series->at(i).y();
        if(_val>_max_y)_max_y=_val;
        if(_val<_min_y)_min_y=_val;
        //Clear
        if(i==0){
            _val = series->at(i).y();
            lpf->setOutput(_val);
            }
            else _val = lpf->update(series->at(i).y());
        if(_val>_gain_y)_gain_y=_val;
        if(ui->checkBox_Filter->isChecked())spline->append(series->at(i).x(),_val);
        else spline->append(series->at(i));
    }
    //recovery the signal amplitude
    if(ui->checkBox_Filter->isChecked()){
        //_gain_y = _max_y/_gain_y;
        _gain_y = 1;
        for(int i=0;i<spline->count();i++)spline->replace(i,QPointF(spline->at(i).x(),spline->at(i).y()*_gain_y));
    }

    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        ECharts::Parameter p;
        p = m_edev_mod1103->chartParameter();
        if(_max_x>p.axisX_Range_Max)p.axisX_Range_Max = _max_x;
        if(_min_x<p.axisX_Range_Min)p.axisX_Range_Min = _min_x;
        if(_max_y>p.axisY_Range_Max)p.axisY_Range_Max= _max_y+(_max_y*0.1);
        if(_min_y<p.axisY_Range_Min)p.axisY_Range_Min = _min_y;
        m_edev_mod1103->setChartParameter(p);
    }
    else{
        EChartLines::Parameter p;
        p = m_edev_mod1103->chartLineParameter();
        if(_max_x>p.axisX_Range_Max)p.axisX_Range_Max = _max_x;
        if(_min_x<p.axisX_Range_Min)p.axisX_Range_Min = _min_x;
        if(_max_y>p.axisY_Range_Max)p.axisY_Range_Max= _max_y+(_max_y*0.1);
        if(_min_y<p.axisY_Range_Min)p.axisY_Range_Min = _min_y;
        m_edev_mod1103->setChartParameter(p);
    }
    m_edev_mod1103->setSpline(spline,line);
}


void Module_MOD1103::setSpline(QLineSeries *series, int line)
{
    if(series->count()<1)return;
    //Fillter
    double _max_x,_max_y,_min_x,_min_y,_val,_gain_y=0;
    double _deltaTime=0.01,_freq=1;
    bool ok;
    QLineSeries *spline = new QLineSeries();
    _val = ui->lineEdit_Filter_Freq->text().toDouble(&ok);
    if(ok)_freq = _val;
    _deltaTime = series->at(series->count()-1).x()/QVariant(series->count()).toDouble();
    if(_deltaTime<0.01)_deltaTime=0.01;
    ELowPassFilter *lpf = new ELowPassFilter(_freq,_deltaTime);
    lpf->setFilterType(ELowPassFilter::FilterType::filter_lpf);

    _max_x = _max_y = _gain_y = QVariant(std::numeric_limits<double>::min()).toDouble();
    _min_x = _min_y = QVariant(std::numeric_limits<double>::max()).toDouble();
    for(int i=0;i<series->count();i++){
        //Check min,max for x
        _val = series->at(i).x();
        if(_val>_max_x)_max_x=_val;
        if(_val<_min_x)_min_x=_val;
        //Check min,max for y
        _val = series->at(i).y();
        if(_val>_max_y)_max_y=_val;
        if(_val<_min_y)_min_y=_val;
        //Clear
        if(i==0){
            _val = series->at(i).y();
            lpf->setOutput(_val);
            }
            else _val = lpf->update(series->at(i).y());
        if(_val>_gain_y)_gain_y=_val;
        if(ui->checkBox_Filter->isChecked())spline->append(series->at(i).x(),_val);
        else spline->append(series->at(i));
    }
    //recovery the signal amplitude
    if(ui->checkBox_Filter->isChecked()){
        //_gain_y = _max_y/_gain_y;
        _gain_y = 1;
        for(int i=0;i<spline->count();i++)spline->replace(i,QPointF(spline->at(i).x(),spline->at(i).y()*_gain_y));
    }

    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        ECharts::Parameter p;
        p = m_edev_mod1103->chartParameter();
        if(_max_x>p.axisX_Range_Max)p.axisX_Range_Max = _max_x;
        if(_min_x<p.axisX_Range_Min)p.axisX_Range_Min = _min_x;
        if(_max_y>p.axisY_Range_Max)p.axisY_Range_Max= _max_y+(_max_y*0.1);
        if(_min_y<p.axisY_Range_Min)p.axisY_Range_Min = _min_y;
        m_edev_mod1103->setChartParameter(p);
    }
    else{
        EChartLines::Parameter p;
        p = m_edev_mod1103->chartLineParameter();
        if(_max_x>p.axisX_Range_Max)p.axisX_Range_Max = _max_x;
        if(_min_x<p.axisX_Range_Min)p.axisX_Range_Min = _min_x;
        if(_max_y>p.axisY_Range_Max)p.axisY_Range_Max= _max_y+(_max_y*0.1);
        if(_min_y<p.axisY_Range_Min)p.axisY_Range_Min = _min_y;
        m_edev_mod1103->setChartParameter(p);
    }
    m_edev_mod1103->setSpline(spline,line);
}

void Module_MOD1103::chartRefresh(bool clear)
{
    if(clear){
        this->chartClear(false);
        if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
            ECharts::Parameter p;
            p = m_edev_mod1103->chartParameter();
            p.axisX_Range_Max = 0.1;
            p.axisY_Range_Max= 0.1;
            p.axisY_Range_Min = 0;
            m_edev_mod1103->setChartParameter(p);
        }
        else
        {
            EChartLines::Parameter p;
            p = m_edev_mod1103->chartLineParameter();
            p.axisX_Range_Max = 0.1;
            p.axisY_Range_Max= 0.1;
            p.axisY_Range_Min = 0;
            m_edev_mod1103->setChartParameter(p);
        }
    }
    if(m_typeLine==EDev_Mod1103::TypeLine::typeLine)this->chartGraph(m_car01_lines,m_car02_lines);
        else this->chartGraph(m_car01_splines,m_car02_splines);
}

void Module_MOD1103::chartClear(bool data)
{
    m_edev_mod1103->chartClear();
    if(data){
        m_graphIndex_01.index_s=0;
        m_graphIndex_01.index_a=0;
        m_graphIndex_01.index_v=0;
        m_graphIndex_01.index_f=0;
        m_graphIndex_01.index_t=0;
        m_graphIndex_02.index_s=0;
        m_graphIndex_02.index_a=0;
        m_graphIndex_02.index_v=0;
        m_graphIndex_02.index_f=0;
        m_graphIndex_02.index_t=0;
    }
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Module_MOD1103::setTrackLine(EChartGesture::ETrackLine track)
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
    if(m_edev_mod1103)m_edev_mod1103->setTrackLine(track);
}

/////////////////////////////////////////////////////////////////////////////////////////////////DEV
Module_MOD1103::Module_MOD1103(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Module_MOD1103)
{
    ui->setupUi(this);
}

Module_MOD1103::~Module_MOD1103()
{
    delete ui;
}

void Module_MOD1103::setCarSave()
{
    ////////////////////////////////////////For CAR01//////////////////////////////
    //unit-01
    ui->comboBox_Display_Car_Unit_S1->setCurrentIndex(m_ecar01_Save.unit_s);
    ui->comboBox_Display_Car_Unit_V1->setCurrentIndex(m_ecar01_Save.unit_v);
    ui->comboBox_Display_Car_Unit_A1->setCurrentIndex(m_ecar01_Save.unit_a);
    ui->comboBox_Display_Car_Unit_T1->setCurrentIndex(m_ecar01_Save.unit_t);
    ui->comboBox_Display_Car_Unit_F1->setCurrentIndex(m_ecar01_Save.unit_f);
    ui->comboBox_Display_Car_Unit_PIN1->setCurrentIndex(m_ecar01_Save.unit_pin);
    //pre-01
    ui->spinBox_Display_Car_Pre_S1->setValue(m_ecar01_Save.pre_s);
    ui->spinBox_Display_Car_Pre_V1->setValue(m_ecar01_Save.pre_v);
    ui->spinBox_Display_Car_Pre_A1->setValue(m_ecar01_Save.pre_a);
    ui->spinBox_Display_Car_Pre_T1->setValue(m_ecar01_Save.pre_t);
    ui->spinBox_Display_Car_Pre_F1->setValue(m_ecar01_Save.pre_f);
    ui->spinBox_Display_Car_Pre_PIN1->setValue(m_ecar01_Save.pre_pin);
    //graph
    ui->checkBox_Car01_S->setChecked(m_ecar01_Save.graph_s);
    ui->checkBox_Car01_V->setChecked(m_ecar01_Save.graph_v);
    ui->checkBox_Car01_A->setChecked(m_ecar01_Save.graph_a);
    ui->checkBox_Car01_F->setChecked(m_ecar01_Save.graph_f);
    //Vector
    ui->checkBox_Display_Car_Vector1->setChecked(m_ecar01_Save.vector);
    m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_01,m_ecar01_Save.vector);
    //reSign
    ui->checkBox_Display_Car_reSign1->setChecked(m_ecar01_Save.reSign);
    m_edev_mod1103->setReverseSign(EDev_Mod1103::ESlave::CAR_01,m_ecar01_Save.reSign);
    //Filter
    ui->checkBox_Filter->setChecked(m_ecar01_Save.filter_set);
    ui->lineEdit_Filter_Freq->setText(QString::number(m_ecar01_Save.filter_freq));

    ////////////////////////////////////////For CAR02//////////////////////////////
    //unit-02
    ui->comboBox_Display_Car_Unit_S2->setCurrentIndex(m_ecar02_Save.unit_s);
    ui->comboBox_Display_Car_Unit_V2->setCurrentIndex(m_ecar02_Save.unit_v);
    ui->comboBox_Display_Car_Unit_A2->setCurrentIndex(m_ecar02_Save.unit_a);
    ui->comboBox_Display_Car_Unit_T2->setCurrentIndex(m_ecar02_Save.unit_t);
    ui->comboBox_Display_Car_Unit_F2->setCurrentIndex(m_ecar02_Save.unit_f);
    ui->comboBox_Display_Car_Unit_PIN2->setCurrentIndex(m_ecar02_Save.unit_pin);
    //pre-02
    ui->spinBox_Display_Car_Pre_S2->setValue(m_ecar02_Save.pre_s);
    ui->spinBox_Display_Car_Pre_V2->setValue(m_ecar02_Save.pre_v);
    ui->spinBox_Display_Car_Pre_A2->setValue(m_ecar02_Save.pre_a);
    ui->spinBox_Display_Car_Pre_T2->setValue(m_ecar02_Save.pre_t);
    ui->spinBox_Display_Car_Pre_F2->setValue(m_ecar02_Save.pre_f);
    ui->spinBox_Display_Car_Pre_PIN2->setValue(m_ecar02_Save.pre_pin);
    //graph
    ui->checkBox_Car02_S->setChecked(m_ecar02_Save.graph_s);
    ui->checkBox_Car02_V->setChecked(m_ecar02_Save.graph_v);
    ui->checkBox_Car02_A->setChecked(m_ecar02_Save.graph_a);
    ui->checkBox_Car02_F->setChecked(m_ecar02_Save.graph_f);
    //Vector
    ui->checkBox_Display_Car_Vector2->setChecked(m_ecar02_Save.vector);
    m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_02,m_ecar02_Save.vector);
    //reSign
    ui->checkBox_Display_Car_reSign2->setChecked(m_ecar02_Save.reSign);
    m_edev_mod1103->setReverseSign(EDev_Mod1103::ESlave::CAR_02,m_ecar02_Save.reSign);

}

void Module_MOD1103::commandCheck()
{
    bool flag=false;
    if(!m_commandCheckStatus){
        m_commandCheckCount=0;
        return;
    }

    //check
    switch(m_commandCheckCar)
    {
    case EDev_Mod1103::ESlave::CAR_01:
        if(ui->radioButton_Display_Car_S1->isChecked()&&m_eCar_01.s.value<m_edev_mod1103->dataCar_S(0.3,m_eCar_01.s.unit)&&m_eCar_01.s.value>m_edev_mod1103->dataCar_S(-0.3,m_eCar_01.s.unit))
            flag=true;
        if(ui->radioButton_Display_Car_F1->isChecked()&&m_eCar_01.f.value<m_edev_mod1103->dataCar_F(0.1,m_eCar_01.f.unit)&&m_eCar_01.f.value>m_edev_mod1103->dataCar_F(-0.1,m_eCar_01.f.unit))
            flag=true;
        break;
    case EDev_Mod1103::ESlave::CAR_02:
        if(ui->radioButton_Display_Car_S2->isChecked()&&m_eCar_02.s.value<m_edev_mod1103->dataCar_S(0.3,m_eCar_02.s.unit)&&m_eCar_02.s.value>m_edev_mod1103->dataCar_S(-0.3,m_eCar_02.s.unit))
            flag=true;
        if(ui->radioButton_Display_Car_F2->isChecked()&&m_eCar_02.f.value<m_edev_mod1103->dataCar_F(0.1,m_eCar_02.f.unit)&&m_eCar_02.f.value>m_edev_mod1103->dataCar_F(-0.1,m_eCar_02.f.unit))
            flag=true;
        break;
    case EDev_Mod1103::ESlave::CAR_ALL:
        break;
    }


    if(flag){
        m_commandCheckCount=0;
        m_commandCheckStatus=false;
        m_QMessageBox = new QMessageBox();
        m_QMessageBox->setText(m_msgInfo);
        m_QMessageBox->setWindowTitle("Thiết lập điểm 0");
        m_QMessageBox->show();
    }
    else{
        m_commandCheckCount++;
        if(m_commandCheckCount>3){
            m_commandCheckStatus=false;
            m_commandCheckCount=0;
        }
    }

}

void Module_MOD1103::getCarSave()
{
    bool ok;
    double _val=1;
    ////////////////////////////////////////For CAR01//////////////////////////////
    _val = ui->lineEdit_Filter_Freq->text().toDouble(&ok);
    //unit-01
    m_ecar01_Save.unit_s = ui->comboBox_Display_Car_Unit_S1->currentIndex();
    m_ecar01_Save.unit_v = ui->comboBox_Display_Car_Unit_V1->currentIndex();
    m_ecar01_Save.unit_a = ui->comboBox_Display_Car_Unit_A1->currentIndex();
    m_ecar01_Save.unit_t = ui->comboBox_Display_Car_Unit_T1->currentIndex();
    m_ecar01_Save.unit_f = ui->comboBox_Display_Car_Unit_F1->currentIndex();
    m_ecar01_Save.unit_pin = ui->comboBox_Display_Car_Unit_PIN1->currentIndex();
    //pre-01
    m_ecar01_Save.pre_s = ui->spinBox_Display_Car_Pre_S1->value();
    m_ecar01_Save.pre_v = ui->spinBox_Display_Car_Pre_V1->value();
    m_ecar01_Save.pre_a = ui->spinBox_Display_Car_Pre_A1->value();
    m_ecar01_Save.pre_t = ui->spinBox_Display_Car_Pre_T1->value();
    m_ecar01_Save.pre_f = ui->spinBox_Display_Car_Pre_F1->value();
    m_ecar01_Save.pre_pin = ui->spinBox_Display_Car_Pre_PIN1->value();
    //graph
    m_ecar01_Save.graph_s = ui->checkBox_Car01_S->isChecked();
    m_ecar01_Save.graph_v = ui->checkBox_Car01_V->isChecked();
    m_ecar01_Save.graph_a = ui->checkBox_Car01_A->isChecked();
    m_ecar01_Save.graph_f = ui->checkBox_Car01_F->isChecked();
    //Vector
    m_ecar01_Save.vector = ui->checkBox_Display_Car_Vector1->isChecked();
    m_ecar01_Save.reSign = ui->checkBox_Display_Car_reSign1->isChecked();
    //Filter
    m_ecar01_Save.filter_set = ui->checkBox_Filter->isChecked();;
    if(ok)m_ecar01_Save.filter_freq = _val;

    ////////////////////////////////////////For CAR02//////////////////////////////
    //unit-02
    m_ecar02_Save.unit_s = ui->comboBox_Display_Car_Unit_S2->currentIndex();
    m_ecar02_Save.unit_v = ui->comboBox_Display_Car_Unit_V2->currentIndex();
    m_ecar02_Save.unit_a = ui->comboBox_Display_Car_Unit_A2->currentIndex();
    m_ecar02_Save.unit_t = ui->comboBox_Display_Car_Unit_T2->currentIndex();
    m_ecar02_Save.unit_f = ui->comboBox_Display_Car_Unit_F2->currentIndex();
    m_ecar02_Save.unit_pin = ui->comboBox_Display_Car_Unit_PIN2->currentIndex();
    //pre-02
    m_ecar02_Save.pre_s = ui->spinBox_Display_Car_Pre_S2->value();
    m_ecar02_Save.pre_v = ui->spinBox_Display_Car_Pre_V2->value();
    m_ecar02_Save.pre_a = ui->spinBox_Display_Car_Pre_A2->value();
    m_ecar02_Save.pre_t = ui->spinBox_Display_Car_Pre_T2->value();
    m_ecar02_Save.pre_f = ui->spinBox_Display_Car_Pre_F2->value();
    m_ecar02_Save.pre_pin = ui->spinBox_Display_Car_Pre_PIN2->value();
    //graph
    m_ecar02_Save.graph_s = ui->checkBox_Car02_S->isChecked();
    m_ecar02_Save.graph_v = ui->checkBox_Car02_V->isChecked();
    m_ecar02_Save.graph_a = ui->checkBox_Car02_A->isChecked();
    m_ecar02_Save.graph_f = ui->checkBox_Car02_F->isChecked();
    //Vector
    m_ecar02_Save.vector = ui->checkBox_Display_Car_Vector2->isChecked();
    m_ecar02_Save.reSign = ui->checkBox_Display_Car_reSign2->isChecked();
}

void Module_MOD1103::carConnectStatus(EDev_Mod1103::ESlave car, bool status)
{
    switch(car)
    {
    case EDev_Mod1103::CAR_01:
        if(status){
            if(QVariant(m_eCar_01.ts-m_eCar_01.cs).toInt()<15){
                QString str = "XE-01 sẽ tắt trong ";
                str += "("+ QString::number(m_eCar_01.ts-m_eCar_01.cs) +") giây";
               ui->label_CAR01_Connect->setText(str);
               ui->label_CAR01_Connect->setStyleSheet("color: rgb(255, 255, 0);");
            }
            else{
                ui->label_CAR01_Connect->setText("XE-01 đang kết nối!");
                ui->label_CAR01_Connect->setStyleSheet("color: rgb(0, 255, 255);");
            }
        }
        else{
            ui->label_CAR01_Connect->setText("XE-01 đã ngắt kết nối!");
            ui->label_CAR01_Connect->setStyleSheet("color: rgb(255, 0, 0);");
        }
        break;
    case EDev_Mod1103::CAR_02:
        if(status){
            if(QVariant(m_eCar_02.ts-m_eCar_02.cs).toInt()<15){
                QString str = "XE-02 sẽ tắt trong ";
                str += "("+ QString::number(m_eCar_02.ts-m_eCar_02.cs) +") giây";
               ui->label_CAR02_Connect->setText(str);
               ui->label_CAR02_Connect->setStyleSheet("color: rgb(255, 255, 0);");
            }
            else{
            ui->label_CAR02_Connect->setText("XE-02 đang kết nối!");
            ui->label_CAR02_Connect->setStyleSheet("color: rgb(0, 255, 255);");
            }
        }
        else{
            ui->label_CAR02_Connect->setText("XE-02 đã ngắt kết nối!");
            ui->label_CAR02_Connect->setStyleSheet("color: rgb(255, 0, 0);");
        }
        break;
    case EDev_Mod1103::CAR_ALL:
        if(status){
            ui->label_CAR01_Connect->setText("XE-01 đang kết nối!");
            ui->label_CAR01_Connect->setStyleSheet("color: rgb(0, 255, 255);");
            ui->label_CAR02_Connect->setText("XE-02 đang kết nối!");
            ui->label_CAR02_Connect->setStyleSheet("color: rgb(0, 255, 255);");
        }
        else{
            ui->label_CAR01_Connect->setText("XE-01 đã ngắt kết nối!");
            ui->label_CAR01_Connect->setStyleSheet("color: rgb(255, 0, 0);");
            ui->label_CAR02_Connect->setText("XE-02 đã ngắt kết nối!");
            ui->label_CAR02_Connect->setStyleSheet("color: rgb(255, 0, 0);");
        }
        break;
    }
}

void Module_MOD1103::updateTabParameter()
{
    double _val=0;
    //For CAR-01
   ui->label_Car01_ADD->setText(m_eCar_01.add);
   _val = m_eCar_01.s.value;
   ui->label_Car01_S->setText(QString::number(_val));
   ui->label_Car01_V->setText(QString::number(m_eCar_01.v.value));
   ui->label_Car01_A->setText(QString::number(m_eCar_01.a.value));
   ui->label_Car01_F->setText(QString::number(m_eCar_01.f.value));
   ui->label_Car01_TIME->setText(QString::number(m_eCar_01.t.value));
   ui->label_Car01_PIN->setText(QString::number(m_eCar_01.pin.value));
   ui->label_Car01_Index->setNum(QVariant(m_eCar_01.index).toInt());
   //Calib S
   ui->label_Car01_CALIB_S->setNum(m_eCar_01.sc);
   //Calib F
   ui->label_Car01_CALIB_F->setNum(m_eCar_01.fc);
   //Time Shutdown
   ui->label_Car01_CS->setNum(QVariant(m_eCar_01.ts-m_eCar_01.cs).toInt());

   //////////////////////////////////////////////////////////////////////////////////////////
   //For CAR-02
   ui->label_Car02_ADD->setText(m_eCar_02.add);
   _val = m_eCar_02.s.value;
   ui->label_Car02_S->setText(QString::number(_val));
   ui->label_Car02_V->setText(QString::number(m_eCar_02.v.value));
   ui->label_Car02_A->setText(QString::number(m_eCar_02.a.value));
   ui->label_Car02_F->setText(QString::number(m_eCar_02.f.value));
   ui->label_Car02_TIME->setText(QString::number(m_eCar_02.t.value));
   ui->label_Car02_PIN->setText(QString::number(m_eCar_02.pin.value));
   ui->label_Car02_Index->setNum(QVariant(m_eCar_02.index).toInt());
   //Calib S
   ui->label_Car02_CALIB_S->setNum(m_eCar_02.sc);
   //Calib F
   ui->label_Car02_CALIB_F->setNum(m_eCar_02.fc);
   //Time Shutdown
   ui->label_Car02_CS->setNum(QVariant(m_eCar_02.ts-m_eCar_02.cs).toInt());

}

void Module_MOD1103::updateTabSetup()
{
    if(ui->radioButton_CAR01_Calib->isChecked()) {
        ui->lineEdit_CAR_SetADD->setText(m_eCar_01.add.left(4));
        ui->spinBox_CAR_TS->setValue(QVariant(m_eCar_01.ts).toInt());
    }
        else {
        ui->lineEdit_CAR_SetADD->setText(m_eCar_02.add.left(4));
        ui->spinBox_CAR_TS->setValue(QVariant(m_eCar_02.ts).toInt());
    }
}

void Module_MOD1103::updateTabDisplay()
{
    double _val=0;
    //For CAR-01
    _val = m_eCar_01.s.value;
   ui->label_Display_Car_S1->setText(QString::number(_val));
   ui->label_Display_Car_V1->setText(QString::number(m_eCar_01.v.value));
   ui->label_Display_Car_A1->setText(QString::number(m_eCar_01.a.value));
   ui->label_Display_Car_F1->setText(QString::number(m_eCar_01.f.value));
   //LCD Display
  if(ui->radioButton_Display_Car_S1->isChecked())ui->lcdNumber_Value_1->display(QString::number(_val));
  if(ui->radioButton_Display_Car_V1->isChecked())ui->lcdNumber_Value_1->display(QString::number(m_eCar_01.v.value));
  if(ui->radioButton_Display_Car_A1->isChecked())ui->lcdNumber_Value_1->display(QString::number(m_eCar_01.a.value));
  if(ui->radioButton_Display_Car_F1->isChecked())ui->lcdNumber_Value_1->display(QString::number(m_eCar_01.f.value));
   //////////////////////////////////////////////////////////////////////////////////////////
   //For CAR-02
  _val = m_eCar_02.s.value;
  ui->label_Display_Car_S2->setText(QString::number(_val));
  ui->label_Display_Car_V2->setText(QString::number(m_eCar_02.v.value));
  ui->label_Display_Car_A2->setText(QString::number(m_eCar_02.a.value));
  ui->label_Display_Car_F2->setText(QString::number(m_eCar_02.f.value));
  //LCD Display
 if(ui->radioButton_Display_Car_S2->isChecked())ui->lcdNumber_Value_2->display(QString::number(_val));
 if(ui->radioButton_Display_Car_V2->isChecked())ui->lcdNumber_Value_2->display(QString::number(m_eCar_02.v.value));
 if(ui->radioButton_Display_Car_A2->isChecked())ui->lcdNumber_Value_2->display(QString::number(m_eCar_02.a.value));
 if(ui->radioButton_Display_Car_F2->isChecked())ui->lcdNumber_Value_2->display(QString::number(m_eCar_02.f.value));

 //Check condition for CAR
 if(!m_eCar_01.connect){
     ui->tabWidget_CAR01->setEnabled(false);
     ui->frame_ChartSelect_01->setEnabled(false);
    }
    else {
     ui->tabWidget_CAR01->setEnabled(true);
     if(m_CMM_carMeasureMode==CMM_default)ui->frame_ChartSelect_01->setEnabled(true);
    }
 if(!m_eCar_02.connect){
     ui->tabWidget_CAR02->setEnabled(false);
     ui->frame_ChartSelect_02->setEnabled(false);
    }
    else {
     ui->tabWidget_CAR02->setEnabled(true);
     if(m_CMM_carMeasureMode==CMM_default)ui->frame_ChartSelect_02->setEnabled(true);
    }

 this->carConnectStatus(EDev_Mod1103::CAR_01,m_eCar_01.connect);
 this->carConnectStatus(EDev_Mod1103::CAR_02,m_eCar_02.connect);
}




void Module_MOD1103::on_setCondition(Module_MOD1103_Condition::ConditionUnit unit, bool status)
{
    if(status)
    {
        m_conditionUnit = unit;
        ui->pushButton_ChartStart->setText("Dừng");
        ui->pushButton_ChartStart->setStyleSheet("color: rgb(255, 0, 0);");
        m_CDP_conditionProcess = EDev_Mod1103::CDP_init;
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
    }
    else this->setProcess(ProcessStatus::PRS_stop);
}

void Module_MOD1103::on_setSetting(Module_MOD1103_Condition::ECarSave car01, Module_MOD1103_Condition::ECarSave car02)
    {
        m_ecar01_Save = car01;
        m_ecar02_Save = car02;
        this->setCarSave();
    }


void Module_MOD1103::measurePoll()
{
    switch(m_CMM_carMeasureMode){
        case CMM_default:
            m_edev_mod1103->setUpdateLine(false,m_CMD_carMode);
            m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
            break;
        case CMM_continuous:
            if(m_eCar_01_connecting&&!m_eCar_01.connect){
                if(m_QMessageBox)delete m_QMessageBox;
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("XE-01 đã dừng kết nối!");
                m_QMessageBox->setWindowTitle("Trạng thái xe");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                this->setProcess(ProcessStatus::PRS_pause);
            }
            if(m_eCar_02_connecting&&!m_eCar_02.connect){
                if(m_QMessageBox)delete m_QMessageBox;
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("XE-02 đã dừng kết nối!");
                m_QMessageBox->setWindowTitle("Trạng thái xe");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                this->setProcess(ProcessStatus::PRS_pause);
            }
            m_edev_mod1103->setUpdateLine(true,m_CMD_carMode);
            if(m_typeLine==EDev_Mod1103::TypeLine::typeLine)this->chartGraphContinous(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01),m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02));
                else this->chartGraphContinous(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01),m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02));
            break;
        case CMM_condition:
            if(m_eCar_01_connecting&&!m_eCar_01.connect){
                if(m_QMessageBox)delete m_QMessageBox;
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("XE-01 đã dừng kết nối!");
                m_QMessageBox->setWindowTitle("Trạng thái xe");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                m_eCar_01_connecting = false;
                break;
            }
            if(m_eCar_02_connecting&&!m_eCar_02.connect){
                if(m_QMessageBox)delete m_QMessageBox;
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("XE-02 đã dừng kết nối!");
                m_QMessageBox->setWindowTitle("Trạng thái xe");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                m_eCar_02_connecting = false;
                break;
            }
            this->measureByCondition();
            break;
    }
}





void Module_MOD1103::zeroConditionParameter()
{

    m_Car01_Condition.s.value=0;
    m_Car01_Condition.v.value=0;
    m_Car01_Condition.a.value=0;
    m_Car01_Condition.f.value=0;
    m_Car01_Condition.t.value=0;
    m_Car01_Condition = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);//update unit and precision

    m_Car02_Condition.s.value=0;
    m_Car02_Condition.v.value=0;
    m_Car02_Condition.a.value=0;
    m_Car02_Condition.f.value=0;
    m_Car02_Condition.t.value=0;
    m_Car02_Condition = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);//update unit and precision
}


bool Module_MOD1103::checkCarStart()
{
    if((m_conditionUnit.start_car==EDev_Mod1103::ESlave::CAR_01&&!m_eCar_01.connect)||(m_conditionUnit.start_car==EDev_Mod1103::ESlave::CAR_02&&!m_eCar_02.connect)){
        m_CDP_conditionProcess=EDev_Mod1103::CDP_end;
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
        this->setProcess(ProcessStatus::PRS_stop);
    }
    if(!this->updateConditionData(m_conditionUnit.start_car))return false;
    return true;
}

bool Module_MOD1103::checkCarStop()
{
    if((m_conditionUnit.stop_car==EDev_Mod1103::ESlave::CAR_01&&!m_eCar_01.connect)||(m_conditionUnit.stop_car==EDev_Mod1103::ESlave::CAR_02&&!m_eCar_02.connect)){
        m_CDP_conditionProcess=EDev_Mod1103::CDP_end;
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
        this->setProcess(ProcessStatus::PRS_stop);
    }
    if(!this->updateConditionData(m_conditionUnit.stop_car))return false;
    return true;
}

void Module_MOD1103::measureByCondition()
{
    switch(m_CDP_conditionProcess){
    case EDev_Mod1103::CDP_default:
        m_mod1103_Condition->setCar(m_eCar_01,m_eCar_02,m_CDP_conditionProcess);
        break;
    case EDev_Mod1103::CDP_init:
        this->chartClear(true);
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01),true);
            m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02),true);
            }
            else{
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01),true);
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02),true);
                }
        m_edev_mod1103->clearListCommand();
        m_edev_mod1103->writeSingleREG(EDev_Mod1103::dREG_TIME_SYSTEM,0);
        this->zeroConditionParameter();
        m_Car01_Zero_s=m_eCar_01.s.value;
        m_Car01_Zero_f=m_eCar_01.f.value;
        m_Car02_Zero_s=m_eCar_02.s.value;
        m_Car02_Zero_f=m_eCar_02.f.value;
        m_CDP_conditionProcess = EDev_Mod1103::CDP_startCheck;
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        m_edev_mod1103->setUpdateLine(true,m_CMD_carMode);
        break;
    case EDev_Mod1103::CDP_startCheck:
        if(!checkCarStart())break;
        if(this->checkConditionStart()){
            m_CDP_conditionProcess = EDev_Mod1103::CDP_start;
            m_graphIndex_01_start = m_graphIndex_01;
            m_graphIndex_02_start = m_graphIndex_02;
        }
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        break;
    case EDev_Mod1103::CDP_start:
        this->zeroConditionParameter();
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            m_Car01_Zero_s=m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(m_graphIndex_01_start.index_s-1).y();
            m_Car01_Zero_f=m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(m_graphIndex_01_start.index_f-1).y();
            m_Car02_Zero_s=m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(m_graphIndex_02_start.index_s-1).y();
            m_Car02_Zero_f=m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(m_graphIndex_02_start.index_f-1).y();
            }
            else{
                m_Car01_Zero_s=m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(m_graphIndex_01_start.index_s-1).y();
                m_Car01_Zero_f=m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(m_graphIndex_01_start.index_f-1).y();
                m_Car02_Zero_s=m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(m_graphIndex_02_start.index_s-1).y();
                m_Car02_Zero_f=m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(m_graphIndex_02_start.index_f-1).y();
                }
        m_CDP_conditionProcess = EDev_Mod1103::CDP_stopCheck;
        break;
    case EDev_Mod1103::CDP_stopCheck:
        if(!checkCarStop())break;
        if(this->checkConditionStop()){
            m_CDP_conditionProcess = EDev_Mod1103::CDP_stop;
            m_graphIndex_01_stop = m_graphIndex_01;
            m_graphIndex_02_stop = m_graphIndex_02;
        }
        else m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        break;
    case EDev_Mod1103::CDP_stop:
        if(!checkCarStop())break;
        if(((m_graphIndex_01.index_s-m_graphIndex_01_stop.index_s)<10)&&((m_graphIndex_02.index_s-m_graphIndex_02_stop.index_s)<10))break;
        m_edev_mod1103->setUpdateLine(false,m_CMD_carMode);
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            this->updateLines();
            this->chartClear(true);
            this->chartGraph(m_car01_lines,m_car02_lines);
            }
            else {
            this->updateSPlines();
            this->chartClear(true);
            this->chartGraph(m_car01_splines,m_car02_splines);
        }
        m_CDP_conditionProcess = EDev_Mod1103::CDP_end;
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        break;
    case EDev_Mod1103::CDP_end:
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
        m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
        this->setProcess(ProcessStatus::PRS_pause);
        break;
    }

}

bool Module_MOD1103::checkConditionStart()
{
 switch(m_conditionUnit.start_condition)
    {
    case EDev_Mod1103::CCD_default:return true;
    case EDev_Mod1103::CCD_S_Higher:
        return this->checkHigher(m_Car01_Condition.s.value,m_Car02_Condition.s.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_S_Lower:
        return this->checkLower(m_Car01_Condition.s.value,m_Car02_Condition.s.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_V_Higher:
        return this->checkHigher(m_Car01_Condition.v.value,m_Car02_Condition.v.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_V_Lower:
        return this->checkLower(m_Car01_Condition.v.value,m_Car02_Condition.v.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_A_Higher:
        return this->checkHigher(m_Car01_Condition.a.value,m_Car02_Condition.a.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_A_Lower:
        return this->checkLower(m_Car01_Condition.a.value,m_Car02_Condition.a.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_F_Higher:
        return this->checkHigher(m_Car01_Condition.f.value,m_Car02_Condition.f.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_F_Lower:
        return this->checkLower(m_Car01_Condition.f.value,m_Car02_Condition.f.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    case EDev_Mod1103::CCD_T_Higher:
        return this->checkHigher(m_Car01_Condition.t.value,m_Car02_Condition.t.value,m_conditionUnit.start_value,m_conditionUnit.start_car);
    }
 return false;
}

bool Module_MOD1103::checkConditionStop()
{
    switch(m_conditionUnit.stop_condition)
       {
    case EDev_Mod1103::CCD_default:return true;
    case EDev_Mod1103::CCD_S_Higher:
        return this->checkHigher(m_Car01_Condition.s.value,m_Car02_Condition.s.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_S_Lower:
        return this->checkLower(m_Car01_Condition.s.value,m_Car02_Condition.s.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_V_Higher:
        return this->checkHigher(m_Car01_Condition.v.value,m_Car02_Condition.v.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_V_Lower:
        return this->checkLower(m_Car01_Condition.v.value,m_Car02_Condition.v.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_A_Higher:
        return this->checkHigher(m_Car01_Condition.a.value,m_Car02_Condition.a.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_A_Lower:
        return this->checkLower(m_Car01_Condition.a.value,m_Car02_Condition.a.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_F_Higher:
        return this->checkHigher(m_Car01_Condition.f.value,m_Car02_Condition.f.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_F_Lower:
        return this->checkLower(m_Car01_Condition.f.value,m_Car02_Condition.f.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
    case EDev_Mod1103::CCD_T_Higher:
        return this->checkHigher(m_Car01_Condition.t.value,m_Car02_Condition.t.value,m_conditionUnit.stop_value,m_conditionUnit.stop_car);
       }
    return false;
}

bool Module_MOD1103::checkHigher(double x1,double x2, double y,EDev_Mod1103::ESlave car)
{
    switch(car){
    case EDev_Mod1103::CAR_01:
        if(x1>y)return true;
        break;
    case EDev_Mod1103::CAR_02:
        if(x2>y)return true;
        break;
    case EDev_Mod1103::CAR_ALL:
        if(x1>y||x2>y)return true;
        break;
    }
    return false;
}

bool Module_MOD1103::checkLower(double x1, double x2, double y, EDev_Mod1103::ESlave car)
{
    switch(car){
    case EDev_Mod1103::CAR_01:
        if(x1<y)return true;
        break;
    case EDev_Mod1103::CAR_02:
        if(x2<y)return true;
        break;
    case EDev_Mod1103::CAR_ALL:
        if(x1<y||x2<y)return true;
        break;
    }
    return false;
}

bool Module_MOD1103::updateSPlineDataCAR01()
{
    bool status = false;
    if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_index>0){
        //For CAR_02
        if(m_graphIndex_02.index_s<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_s->count()){
            m_Car02_Condition.s.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(m_graphIndex_02.index_s).y();
            m_Car02_Condition.s.value -= m_Car02_Zero_s;
            m_graphIndex_02.index_s++;
            status=true;
            }
        if(m_graphIndex_02.index_v<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_v->count()){
            m_Car02_Condition.v.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_v->at(m_graphIndex_02.index_v).y();
            m_graphIndex_02.index_v++;
            }
        if(m_graphIndex_02.index_a<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_a->count()){
            m_Car02_Condition.a.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_a->at(m_graphIndex_02.index_a).y();
            m_graphIndex_02.index_a++;
            }
        if(m_graphIndex_02.index_f<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_f->count()){
            m_Car02_Condition.f.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(m_graphIndex_02.index_f).y();
            m_Car02_Condition.f.value -= m_Car02_Zero_f;
            m_graphIndex_02.index_f++;
            }
        if(m_graphIndex_02.index_t<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->count()){
            m_Car02_Condition.t.value += m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(m_graphIndex_02.index_t).y();
            m_graphIndex_02.index_t++;
            }
        }
    return status;
}

bool Module_MOD1103::updateSPlineDataCAR02()
{
    bool status = false;
    if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_index>0){
        //For CAR_01
        if(m_graphIndex_01.index_s<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_s->count()){
            m_Car01_Condition.s.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(m_graphIndex_01.index_s).y();
            m_Car01_Condition.s.value -= m_Car01_Zero_s;
            m_graphIndex_01.index_s++;
            status=true;
            }
        if(m_graphIndex_01.index_v<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_v->count()){
            m_Car01_Condition.v.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_v->at(m_graphIndex_01.index_v).y();
            m_graphIndex_01.index_v++;
            }
        if(m_graphIndex_01.index_a<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_a->count()){
            m_Car01_Condition.a.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_a->at(m_graphIndex_01.index_a).y();
            m_graphIndex_01.index_a++;
            }
        if(m_graphIndex_01.index_f<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_f->count()){
            m_Car01_Condition.f.value = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(m_graphIndex_01.index_f).y();
            m_Car01_Condition.f.value -= m_Car01_Zero_f;
            m_graphIndex_01.index_f++;
            }
        if(m_graphIndex_01.index_t<m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->count()){
            m_Car01_Condition.t.value += m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01.index_t).y();
            m_graphIndex_01.index_t++;
            }
        }
    return status;
}

bool Module_MOD1103::updateLineDataCAR01()
{
    bool status = false;
    if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_index>0){
        //For CAR_01
        if(m_graphIndex_01.index_s<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_s->count()){
            m_Car01_Condition.s.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(m_graphIndex_01.index_s).y();
            m_Car01_Condition.s.value -= m_Car01_Zero_s;
            m_graphIndex_01.index_s++;
            status=true;
            }
        if(m_graphIndex_01.index_v<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_v->count()){
            m_Car01_Condition.v.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_v->at(m_graphIndex_01.index_v).y();
            m_graphIndex_01.index_v++;
            }
        if(m_graphIndex_01.index_a<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_a->count()){
            m_Car01_Condition.a.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_a->at(m_graphIndex_01.index_a).y();
            m_graphIndex_01.index_a++;
            }
        if(m_graphIndex_01.index_f<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_f->count()){
            m_Car01_Condition.f.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(m_graphIndex_01.index_f).y();
            m_Car01_Condition.f.value -= m_Car01_Zero_f;
            m_graphIndex_01.index_f++;
            }
        if(m_graphIndex_01.index_t<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->count()){
            m_Car01_Condition.t.value += m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01.index_t).y();
            m_graphIndex_01.index_t++;
            }
        }
    return status;
}

bool Module_MOD1103::updateLineDataCAR02()
{
    bool status = false;
    if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_index>0){
        //For CAR_02
        if(m_graphIndex_02.index_s<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_s->count()){
            m_Car02_Condition.s.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(m_graphIndex_02.index_s).y();
            m_Car02_Condition.s.value -= m_Car02_Zero_s;
            m_graphIndex_02.index_s++;
            status=true;
            }
        if(m_graphIndex_02.index_v<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_v->count()){
            m_Car02_Condition.v.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_v->at(m_graphIndex_02.index_v).y();
            m_graphIndex_02.index_v++;
            }
        if(m_graphIndex_02.index_a<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_a->count()){
            m_Car02_Condition.a.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_a->at(m_graphIndex_02.index_a).y();
            m_graphIndex_02.index_a++;
            }
        if(m_graphIndex_02.index_f<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_f->count()){
            m_Car02_Condition.f.value = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(m_graphIndex_02.index_f).y();
            m_Car02_Condition.f.value -= m_Car02_Zero_f;
            m_graphIndex_02.index_f++;
            }
        if(m_graphIndex_02.index_t<m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->count()){
            m_Car02_Condition.t.value += m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(m_graphIndex_02.index_t).y();
            m_graphIndex_02.index_t++;
            }
        }
    return status;
}



bool Module_MOD1103::updateConditionData(EDev_Mod1103::ESlave car)
{
    switch(car){
    case EDev_Mod1103::CAR_01:
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            if(this->updateLineDataCAR01()){
                this->updateLineDataCAR02();
                return true;
                }
            }
            else{
                if(this->updateSPlineDataCAR01()){
                    this->updateSPlineDataCAR02();
                    return true;
                    }
                }
        break;
    case EDev_Mod1103::CAR_02:
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
        if(this->updateLineDataCAR02()){
            this->updateLineDataCAR01();
            return true;
            }
        }
        else{
            if(this->updateSPlineDataCAR02()){
                this->updateSPlineDataCAR01();
                return true;
                }
            }
        break;
    case EDev_Mod1103::CAR_ALL:
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            if(this->updateLineDataCAR01()&&this->updateLineDataCAR01())return true;
            }
            else{
                if(this->updateSPlineDataCAR01()&&this->updateSPlineDataCAR01())return true;
                }
        break;
    }
    return false;
}

int Module_MOD1103::syncSPlines(double time, int place)
{
    int _delta_min = 20,_delta_min_max=20,_index=0;
    double _val=0,_min=1000;
    //find forward
    if(place<1)return 0;
    if(place<_delta_min)_delta_min = place-1;
    if((m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_index-place)<_delta_min_max)_delta_min_max = (m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_index-place)-1;
    for(int i=-_delta_min;i<_delta_min_max;i++){
    _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+place).x()-time;
    if(_val<0)_val*=(-1);
    //find min
    if(_min>_val){
        _min=_val;
        _index = i;
        }
    }
    return _index;
}

int Module_MOD1103::syncLines(double time,int place)
{
    int _delta_min = 20,_delta_min_max=20,_index=0;
    double _val=0,_min=1000;
    //find forward
    if(place<1)return 0;
    if(place<_delta_min)_delta_min = place-1;
    if((m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_index-place)<_delta_min_max)_delta_min_max = (m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_index-place)-1;
    for(int i=-_delta_min;i<_delta_min_max;i++){
    _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+place).x()-time;
    if(_val<0)_val*=(-1);
    //find min
    if(_min>_val){
        _min=_val;
        _index = i;
        }
    }
    return _index;
}

void Module_MOD1103::updateSPlines()
{
    EDev_Mod1103::ECarSPlines _car01,_car02;
    double _val=0,_timeDelta1=0,_timeDelta2=0;
    int _index_sync_start=0,_index_sync_stop=0;

    //sync start
    _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01_start.index_s-1).x();
    _index_sync_start = this->syncSPlines(_val,m_graphIndex_02_start.index_s);
    _timeDelta1 = _val;
    _timeDelta2 = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(_index_sync_start+m_graphIndex_02_start.index_s).x();
    //sync stop
    _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01_stop.index_s).x();
    _index_sync_stop = this->syncSPlines(_val,m_graphIndex_02_stop.index_s);
    for(int i=-1;i<m_graphIndex_01_stop.index_s-m_graphIndex_01_start.index_s;i++){
         _car01.line_time = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(i+m_graphIndex_01_start.index_s).x()-_timeDelta1;
         _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(i+m_graphIndex_01_start.index_s).y()-m_Car01_Zero_s;
         if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
         if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_s->count()>i+m_graphIndex_01_start.index_s)_car01.line_s->append(_car01.line_time,_val);
         if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->count()>i+m_graphIndex_01_start.index_s)_car01.line_t->append(_car01.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(i+m_graphIndex_01_start.index_s).y());
         if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_v->count()>i+m_graphIndex_01_start.index_v)_car01.line_v->append(_car01.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_v->at(i+m_graphIndex_01_start.index_v).y());
         if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_a->count()>i+m_graphIndex_01_start.index_a)_car01.line_a->append(_car01.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_a->at(i+m_graphIndex_01_start.index_a).y());
         _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(i+m_graphIndex_01_start.index_f).y()-m_Car01_Zero_f;
         if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
         if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01).line_f->count()>i+m_graphIndex_01_start.index_f)_car01.line_f->append(_car01.line_time,_val);
         _car01.line_index++;
        }
    m_car01_splines = _car01;
    for(int i=_index_sync_start;i<(m_graphIndex_02_stop.index_s-m_graphIndex_02_start.index_s)+_index_sync_stop;i++){
        _car02.line_time = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+m_graphIndex_02_start.index_s).x() - _timeDelta2;
        _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(i+m_graphIndex_02_start.index_s).y()-m_Car02_Zero_s;
        if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
        if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_s->count()>i+m_graphIndex_02_start.index_s)_car02.line_s->append(_car02.line_time,_val);
        if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->count()>i+m_graphIndex_02_start.index_s)_car02.line_t->append(_car02.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+m_graphIndex_02_start.index_s).y());
        if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_v->count()>i+m_graphIndex_02_start.index_v)_car02.line_v->append(_car02.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_v->at(i+m_graphIndex_02_start.index_v).y());
        if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_a->count()>i+m_graphIndex_02_start.index_a)_car02.line_a->append(_car02.line_time,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_a->at(i+m_graphIndex_02_start.index_a).y());
        _val = m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(i+m_graphIndex_02_start.index_f).y()-m_Car02_Zero_f;
        if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
        if(m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02).line_f->count()>i+m_graphIndex_02_start.index_f)_car02.line_f->append(_car02.line_time,_val);
        _car02.line_index++;
       }

     m_car02_splines = _car02;
}


void Module_MOD1103::updateLines()
{
    EDev_Mod1103::ECarLines _car01,_car02;
    double _val=0,_timeDelta1=0,_timeDelta2=0;
    int _index_sync_start=0,_index_sync_stop=0;

    //sync start
    _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01_start.index_s-1).x();
    _index_sync_start = this->syncLines(_val,m_graphIndex_02_start.index_s);
    _timeDelta1 = _val;
    _timeDelta2 = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(_index_sync_start+m_graphIndex_02_start.index_s).x();
    //sync stop
    _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(m_graphIndex_01_stop.index_s).x();
    _index_sync_stop = this->syncLines(_val,m_graphIndex_02_stop.index_s);
    for(int i=-1;i<m_graphIndex_01_stop.index_s-m_graphIndex_01_start.index_s;i++){
         _car01.line_time = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(i+m_graphIndex_01_start.index_s).x()-_timeDelta1;
         _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_s->at(i+m_graphIndex_01_start.index_s).y()-m_Car01_Zero_s;
         if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
         if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_s->count()>i+m_graphIndex_01_start.index_s)_car01.line_s->append(_car01.line_time,_val);
         if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->count()>i+m_graphIndex_01_start.index_s)_car01.line_t->append(_car01.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_t->at(i+m_graphIndex_01_start.index_s).y());
         if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_v->count()>i+m_graphIndex_01_start.index_v)_car01.line_v->append(_car01.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_v->at(i+m_graphIndex_01_start.index_v).y());
         if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_a->count()>i+m_graphIndex_01_start.index_a)_car01.line_a->append(_car01.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_a->at(i+m_graphIndex_01_start.index_a).y());
         _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_f->at(i+m_graphIndex_01_start.index_f).y()-m_Car01_Zero_f;
         if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
         if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01).line_f->count()>i+m_graphIndex_01_start.index_f)_car01.line_f->append(_car01.line_time,_val);
         _car01.line_index++;
        }
    m_car01_lines = _car01;
    for(int i=_index_sync_start;i<(m_graphIndex_02_stop.index_s-m_graphIndex_02_start.index_s)+_index_sync_stop;i++){
        _car02.line_time = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+m_graphIndex_02_start.index_s).x() - _timeDelta2;
        _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_s->at(i+m_graphIndex_02_start.index_s).y()-m_Car02_Zero_s;
        if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
        if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_s->count()>i+m_graphIndex_02_start.index_s)_car02.line_s->append(_car02.line_time,_val);
        if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->count()>i+m_graphIndex_02_start.index_s)_car02.line_t->append(_car02.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_t->at(i+m_graphIndex_02_start.index_s).y());
        if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_v->count()>i+m_graphIndex_02_start.index_v)_car02.line_v->append(_car02.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_v->at(i+m_graphIndex_02_start.index_v).y());
        if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_a->count()>i+m_graphIndex_02_start.index_a)_car02.line_a->append(_car02.line_time,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_a->at(i+m_graphIndex_02_start.index_a).y());
        _val = m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_f->at(i+m_graphIndex_02_start.index_f).y()-m_Car02_Zero_f;
        if(!ui->checkBox_Display_Car_Vector1->isChecked()&&_val<0)_val*=(-1);
        if(m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02).line_f->count()>i+m_graphIndex_02_start.index_f)_car02.line_f->append(_car02.line_time,_val);
        _car02.line_index++;
       }

     m_car02_lines = _car02;
}


void Module_MOD1103::closeEvent(QCloseEvent *event)
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
        // if(m_echart)m_echart->deleteLater();
         if(m_mod1103_Condition)delete m_mod1103_Condition;
         //m_mod1103_Condition->deleteLater();
         m_displayTimer->deleteLater();
         m_edev_mod1103->close();
         delete m_edev_mod1103;
         event->accept();
     }
}



void Module_MOD1103::on_pushButton_SetCommandCAR1_clicked()
{
    ui->pushButton_SetCommandCAR1->setEnabled(false);
    switch (ui->comboBox_CAR_Command->currentIndex()) {
    case 0:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_ZeroCAR);
        m_edev_mod1103->setDistanceCheck(0);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Quãng đường\"";
        break;
    case 1:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_ZeroForce);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Lực tác động\"";
        break;
    case 2:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_Shutdown);
        m_msgInfo = "Đã tắt XE - 01.                         ";
        break;
    }
    m_SWS_Status = SWS_SetCommand;
    ui->pushButton_SetCommandCAR1->setEnabled(true);
}

void Module_MOD1103::on_pushButton_SetCommandCAR2_clicked()
{
    ui->pushButton_SetCommandCAR2->setEnabled(false);
    switch (ui->comboBox_CAR_Command->currentIndex()) {
    case 0:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_ZeroCAR);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Quãng đường\"";
        break;
    case 1:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_ZeroForce);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Lực tác động\"";
        break;
    case 2:m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_Shutdown);
        m_msgInfo = "Đã tắt XE - 01.                         ";
        break;
    }
    m_SWS_Status = SWS_SetCommand;
    ui->pushButton_SetCommandCAR2->setEnabled(true);
}

void Module_MOD1103::on_pushButton_SetConfigChart_clicked()
{
    if(ui->spinBox_AxisY_Range_Min->value()>=ui->spinBox_AxisY_Range_Max->value()){
        QMessageBox::information(this,"Cài đặt đồ thị","Dải đo \"Thấp\" phải nhỏ hơn dải đo \"Cao\"!",QMessageBox::Ok);
        return;
    }

    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        ECharts::Parameter p;
        p = m_edev_mod1103->chartParameter();
        p.axisX_Range_Max = ui->spinBox_AxitX_Range_Max->value();
        p.axisY_Range_Max= ui->spinBox_AxisY_Range_Max->value();
        p.axisY_Range_Min = ui->spinBox_AxisY_Range_Min->value();
        m_edev_mod1103->setChartParameter(p);
    }
    else
    {
        EChartLines::Parameter p;
        p = m_edev_mod1103->chartLineParameter();
        p.axisX_Range_Max = ui->spinBox_AxitX_Range_Max->value();
        p.axisY_Range_Max= ui->spinBox_AxisY_Range_Max->value();
        p.axisY_Range_Min = ui->spinBox_AxisY_Range_Min->value();
        m_edev_mod1103->setChartParameter(p);
    }

    this->chartClear(true);
}

void Module_MOD1103::on_pushButton_ClearChart_clicked()
{
    this->chartClear(true);
}

void Module_MOD1103::on_radioButton_Accumulation_toggled(bool checked)
{
    this->chartClear(true);
    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        if(checked)m_edev_mod1103->setScanType(ECharts::scanCompact);
            else m_edev_mod1103->setScanType(ECharts::scanScroll);
        }
        else{
        if(checked)m_edev_mod1103->setScanType(EChartLines::scanCompact);
            else m_edev_mod1103->setScanType(EChartLines::scanScroll);
        }
}


void Module_MOD1103::setProcess(Module_MOD1103::ProcessStatus status)
{
    m_PRS_processStatus = status;
    switch(m_PRS_processStatus){
    case ProcessStatus::PRS_play:
        if(m_CMD_carMode==EDev_Mod1103::CMD_continous){
            ui->frame_ChartSelect_01->setEnabled(false);
            ui->frame_ChartSelect_02->setEnabled(false);
            ui->frame_setChart->setEnabled(false);
            ui->frame_Mode->setEnabled(false);
            ui->pushButton_ChartStart->setText("Dừng");
            ui->pushButton_ChartStart->setStyleSheet("QPushButton {\
                                                     color: rgb(255, 255, 0);\
                                                     background-color: rgb(0, 85, 127);\
                                                     border-style: outset;\
                                                     border-width: 0px;\
                                                     }");
            if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
                ECharts::Parameter p;
                p = m_edev_mod1103->chartParameter();
                p.axisX_Range_Min = 0;
                p.axisX_Range_Max = 1;
                p.axisY_Range_Max= 0.1;
                p.axisY_Range_Min = 0;
                m_edev_mod1103->setChartParameter(p);
            }
            else
            {
                EChartLines::Parameter p;
                p = m_edev_mod1103->chartLineParameter();
                p.axisX_Range_Min = 0;
                p.axisX_Range_Max = 1;
                p.axisY_Range_Max= 0.1;
                p.axisY_Range_Min = 0;
                m_edev_mod1103->setChartParameter(p);
            }
            if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01),true);
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02),true);
                }
                else{
                    m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01),true);
                    m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02),true);
                    }
            m_CMM_carMeasureMode=CarMeasureMode::CMM_continuous;
            }
        if(m_CMD_carMode==EDev_Mod1103::CMD_condition){
            if(m_mod1103_Condition){
                if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
                    ECharts::Parameter p;
                    p = m_edev_mod1103->chartParameter();
                    p.axisX_Range_Max = 0.1;
                    p.axisY_Range_Max= 0.1;
                    p.axisY_Range_Min = 0;
                    m_edev_mod1103->setChartParameter(p);
                }
                else
                {
                    EChartLines::Parameter p;
                    p = m_edev_mod1103->chartLineParameter();
                    p.axisX_Range_Max = 0.1;
                    p.axisY_Range_Max= 0.1;
                    p.axisY_Range_Min = 0;
                    m_edev_mod1103->setChartParameter(p);
                }

                m_mod1103_Condition->setCar(m_eCar_01,m_eCar_02,false);
                this->getCarSave();
                m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
                m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,m_CDP_conditionProcess);
                m_mod1103_Condition->setCar(m_ecar01_Save,m_ecar02_Save);
                m_mod1103_Condition->setWindowTitle(this->windowTitle());
                int _local_X = this->geometry().x()+(this->width()-m_mod1103_Condition->width())/2;
                int _local_Y = this->geometry().y()+(this->height()-m_mod1103_Condition->height())/2;
                m_mod1103_Condition->setGeometry(_local_X,_local_Y,m_mod1103_Condition->width(),m_mod1103_Condition->height());
                m_mod1103_Condition->show();
                ui->frame_ChartSelect_01->setEnabled(false);
                ui->frame_ChartSelect_02->setEnabled(false);
                ui->frame_setChart->setEnabled(false);
                ui->frame_trackLine->setEnabled(false);
                ui->frame_Mode->setEnabled(false);
                m_CMM_carMeasureMode=CarMeasureMode::CMM_condition;
                }
            }
        m_eCar_01_connecting = m_eCar_01.connect;
        m_eCar_02_connecting = m_eCar_02.connect;
        break;
    case ProcessStatus::PRS_pause:
        m_CMM_carMeasureMode=CarMeasureMode::CMM_default;
        ui->frame_trackLine->setEnabled(true);
        ui->pushButton_ChartStart->setText("Kết thúc");
        ui->pushButton_ChartStart->setStyleSheet("QPushButton {\
                                                 color: rgb(255,0, 0);\
                                                 background-color: rgb(0, 85, 127);\
                                                 border-style: outset;\
                                                 border-width: 0px;\
                                                 }");
        break;
    case ProcessStatus::PRS_stop:
        m_CMM_carMeasureMode=CarMeasureMode::CMM_default;
        ui->pushButton_ChartStart->setText("Thực hiện");
        ui->pushButton_ChartStart->setStyleSheet("QPushButton {\
                                                 color: rgb(255,255,255);\
                                                 background-color: rgb(0, 85, 127);\
                                                 border-style: outset;\
                                                 border-width: 0px;\
                                                 }");
        ui->frame_ChartSelect_01->setEnabled(true);
        ui->frame_ChartSelect_02->setEnabled(true);
        ui->frame_setChart->setEnabled(true);
        ui->frame_trackLine->setEnabled(true);
        ui->frame_Mode->setEnabled(true);
        m_edev_mod1103->setUpdateLine(false,m_CMD_carMode);
        if(m_typeLine==EDev_Mod1103::TypeLine::typeLine){
            m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_01),true);
            m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->lineCar(EDev_Mod1103::ESlave::CAR_02),true);
            }
            else{
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_01,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_01),true);
                m_edev_mod1103->setLineCar(EDev_Mod1103::ESlave::CAR_02,m_edev_mod1103->splineCar(EDev_Mod1103::ESlave::CAR_02),true);
                }
        m_mod1103_Condition->setCar(m_Car01_Condition,m_Car02_Condition,EDev_Mod1103::CDP_default);
        if(!m_mod1103_Condition->isHidden())m_mod1103_Condition->hide();
        this->chartClear(true);
        break;
    }
}


void Module_MOD1103::on_pushButton_ChartStart_clicked()
{
    if(!m_eCar_01.connect&&!m_eCar_02.connect)   {
        m_QMessageBox = new QMessageBox();
        m_QMessageBox->setText("Không có XE nào đang kết nối");
        m_QMessageBox->setWindowTitle("Trạng thái xe");
        m_QMessageBox->setIcon(QMessageBox::Warning);
        m_QMessageBox->show();
        return;
    }
    if(ui->pushButton_ChartStart->text()=="Thực hiện")this->setProcess(ProcessStatus::PRS_play);
        else
            if(ui->pushButton_ChartStart->text()=="Dừng")this->setProcess(ProcessStatus::PRS_pause);
                else
                    if(ui->pushButton_ChartStart->text()=="Kết thúc")this->setProcess(ProcessStatus::PRS_stop);
    m_edev_mod1103->writeSingleREG(EDev_Mod1103::dREG_TIME_SYSTEM,0);
}

void Module_MOD1103::on_pushButton_SetSampleTime_clicked()
{
    m_modbusSampleTime = ui->spinBox_SampleTime->value();
    m_edev_mod1103->setSampleTime(m_modbusSampleTime);
}


void Module_MOD1103::on_pushButton_SetCalib_S_clicked()
{
    double c=0,d=0;
    bool ok;
    if(!m_eCar_01.connect&&ui->radioButton_CAR01_Calib->isChecked()){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! XE-01 đã ngắt kết nối!");
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
        if(!m_eCar_02.connect&&ui->radioButton_CAR02_Calib->isChecked()){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! XE-02 đã ngắt kết nối!");
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
    d = ui->lineEdit_CAR_CalibS->text().toDouble(&ok);
    if(ok){
        QVector<quint16> val(2);
        quint32 res=0;
        if(ui->comboBox_CAR_Calib_Sc->currentIndex()==0){
            c = d*M_PI;
            c = c/318.0;
            }
            else c = d;
        if(c<0.00001||c>0xFFFFFFF){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Không thể hiệu chuẩn, lỗi hệ số sai số chuẩn!");
            m_QMessageBox->setWindowTitle("Lỗi hiệu chuẩn");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
            }
        res = VDevice::encode(c,5);
        val[0]=(res>>16)&0xFFFF;
        val[1]=res&0xFFFF;
        if(ui->radioButton_CAR01_Calib->isChecked()){
            m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR01_CALS_X,val);
            m_msgInfo = "Đã cài đặt thành công giá trị hiệu chuẩn cho "
                        "phép đo \"Quãng đường\" trên XE - 01";
            }
            else {
            m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR02_CALS_X,val);
            m_msgInfo = "Đã cài đặt thành công giá trị hiệu chuẩn cho "
                        "phép đo \"Quãng đường\" trên XE - 02";
        }
        m_SWS_Status = SWS_Calib;
    }
    else{
        m_QMessageBox = new QMessageBox();
        m_QMessageBox->setText("Đã có lỗi xảy ra! Giá trị nhập vào không đúng!");
        m_QMessageBox->setWindowTitle("Lỗi hiệu chuẩn");
        m_QMessageBox->setIcon(QMessageBox::Warning);
        m_QMessageBox->show();
    }
}

void Module_MOD1103::on_pushButton_SetCalib_F_clicked()
{
    double c=0,d=0,_f=0;
        bool ok;
        uint8_t slave;
        if(!m_eCar_01.connect&&ui->radioButton_CAR01_Calib->isChecked()){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! XE-01 đã ngắt kết nối!");
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
        if(!m_eCar_02.connect&&ui->radioButton_CAR02_Calib->isChecked()){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! XE-02 đã ngắt kết nối!");
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
        d = ui->lineEdit_CAR_CalibF->text().toDouble(&ok);
        if(ui->radioButton_CAR01_Calib->isChecked()) slave=1;
            else slave=2;
        if(ok){
            QVector<quint16> val(2);
            quint32 res=0;
            if(ui->comboBox_CAR_Calib_Fc->currentIndex()==0){
                if(slave==1){
                    c = d*m_eCar_01.fc;
                    _f = m_edev_mod1103->dataCar_F(m_eCar_01.f.value,EDev_Mod1103::ForceUnits::SSU_default);
                    if(_f!=0)c = c/_f;
                    }
                    else{
                        c = d*m_eCar_02.fc;
                        _f = m_edev_mod1103->dataCar_F(m_eCar_02.f.value,EDev_Mod1103::ForceUnits::SSU_default);
                        if(_f!=0)c = c/_f;
                        }
                }
                else c = d;
            if(c<0.00001||c>0xFFFFFFF){
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("Không thể hiệu chuẩn, lỗi hệ số sai số chuẩn!");
                m_QMessageBox->setWindowTitle("Lỗi hiệu chuẩn");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                return;
                }
            res = VDevice::encode(c,5);
            val[0]=(res>>16)&0xFFFF;
            val[1]=res&0xFFFF;
            if(slave==1) m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR01_CALF_X,val);
                else m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR02_CALF_X,val);
            m_msgInfo = "Đã cài đặt thành công giá trị hiệu chuẩn cho "
                        "phép đo \"Lực tác động\" trên XE - 0"+ QString::number(slave)+".";
            m_SWS_Status = SWS_Calib;
        }
        else{
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Giá trị nhập vào không đúng!");
            m_QMessageBox->setWindowTitle("Lỗi hiệu chuẩn");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
}

void Module_MOD1103::on_pushButton_SetADD_clicked()
{
    if(!m_eCar_01.connect||!m_eCar_02.connect){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Cả hai xe đều phải đang kết nối khi cài đặt địa chỉ!");
            m_QMessageBox->setWindowTitle("Lỗi cài đặt");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
    if(ui->lineEdit_CAR_SetADD->text().count()!=4){
        m_QMessageBox = new QMessageBox();
        m_QMessageBox->setText("Đã có lỗi xảy ra! Địa chỉ phải có đúng 4 kí tự!");
        m_QMessageBox->setWindowTitle("Lỗi cài đặt");
        m_QMessageBox->setIcon(QMessageBox::Warning);
        m_QMessageBox->show();
    }
    else {
        QVector<quint16> val(2);
        QByteArray a = ui->lineEdit_CAR_SetADD->text().toUtf8();
        val[0] = QString::number(a[0]).toUShort()<<8|QString::number((a[1])).toUShort();
        val[1] = QString::number(a[2]).toUShort()<<8|QString::number((a[3])).toUShort();
        if(ui->radioButton_CAR01_Calib->isChecked()){
            m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR01_ADD,val);
            m_msgInfo = "Đã cài đặt thành công địa chỉ cho XE - 01";
            }
            else {
            m_edev_mod1103->writeMultipleREG(EDev_Mod1103::dREG_CAR02_ADD,val);
            m_msgInfo = "Đã cài đặt thành công địa chỉ cho XE - 02";
            }
        m_SWS_Status = SWS_Calib;
    }
}

void Module_MOD1103::on_pushButton_SetTS_clicked()
{
        quint16 val = QString::number(ui->spinBox_CAR_TS->value()).toUShort();
        if(!m_eCar_01.connect&&ui->radioButton_CAR01_Calib->isChecked()){
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("Đã có lỗi xảy ra! XE-01 đã ngắt kết nối!");
                m_QMessageBox->setWindowTitle("Lỗi kết nối");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                return;
            }
            if(!m_eCar_02.connect&&ui->radioButton_CAR02_Calib->isChecked()){
                m_QMessageBox = new QMessageBox();
                m_QMessageBox->setText("Đã có lỗi xảy ra! XE-02 đã ngắt kết nối!");
                m_QMessageBox->setWindowTitle("Lỗi kết nối");
                m_QMessageBox->setIcon(QMessageBox::Warning);
                m_QMessageBox->show();
                return;
            }
        if(ui->radioButton_CAR01_Calib->isChecked()){
            m_edev_mod1103->writeSingleREG(EDev_Mod1103::dREG_CAR01_TS,val);
            m_msgInfo = "Đã cài đặt thời gian tắt cho XE - 01.";
            }
            else {
            m_edev_mod1103->writeSingleREG(EDev_Mod1103::dREG_CAR02_TS,val);
            m_msgInfo = "Đã cài đặt thời gian tắt cho XE - 02.";
            }
        m_SWS_Status = SWS_Calib;
}

void Module_MOD1103::on_tabWidget_currentChanged(int )
{
    if(ui->tabWidget->currentWidget()->objectName()=="tabSetup"){
        this->updateTabSetup();
    }
}

void Module_MOD1103::on_radioButton_CAR01_Calib_toggled(bool )
{
    updateTabSetup();
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_S1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::DSU_millimetre);
        break;
    case 1:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::DSU_metre);
        break;
    case 2:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::DSU_kilometre);
        break;
    }
    ui->label_Display_Car_Unit_S1->setText(ui->comboBox_Display_Car_Unit_S1->currentText());
    ui->label_Display_Car_Unit_S3->setText(ui->comboBox_Display_Car_Unit_S1->currentText());
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_V1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SPU_mm_per_second);
        break;
    case 1:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SPU_m_per_second);
        break;
    case 2:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SPU_km_per_hour);
        break;
    }
    ui->label_Display_Car_Unit_V1->setText(ui->comboBox_Display_Car_Unit_V1->currentText());
    ui->label_Display_Car_Unit_V3->setText(ui->comboBox_Display_Car_Unit_V1->currentText());
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_A1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::ACU_mm_per_s2);
        break;
    case 1:m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::ACU_m_per_s2);
        break;
    }
    ui->label_Display_Car_Unit_A1->setText(ui->comboBox_Display_Car_Unit_A1->currentText());
    ui->label_Display_Car_Unit_A3->setText(ui->comboBox_Display_Car_Unit_A1->currentText());
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_T1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::TMU_Second);
        break;
    case 1:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::TMU_mSecond);
        break;
    case 2:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::TMU_uSecond);
        break;
    }
    ui->label_Display_Car_Unit_T3->setText(ui->comboBox_Display_Car_Unit_T1->currentText());
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_F1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SSU_scaleForce);
        break;
    case 1:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SSU_scaleGram);
        break;
    case 2:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SSU_scaleKiloGram);
        break;
    case 3:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::SSU_scaleWeight);
        break;
    }
    ui->label_Display_Car_Unit_F1->setText(ui->comboBox_Display_Car_Unit_F1->currentText());
    ui->label_Display_Car_Unit_F3->setText(ui->comboBox_Display_Car_Unit_F1->currentText());
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_PIN1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::VTU_Volt);
        break;
    case 1:m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::VTU_mVolt);
        break;
    }
ui->label_Display_Car_Unit_V3->setText(ui->comboBox_Display_Car_Unit_PIN1->currentText());
m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_S2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::DSU_millimetre);
        break;
    case 1:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::DSU_metre);
        break;
    case 2:m_edev_mod1103->setDistanceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::DSU_kilometre);
        break;
    }
    ui->label_Display_Car_Unit_S2->setText(ui->comboBox_Display_Car_Unit_S2->currentText());
    ui->label_Display_Car_Unit_S4->setText(ui->comboBox_Display_Car_Unit_S2->currentText());
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_V2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SPU_mm_per_second);
        break;
    case 1:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SPU_m_per_second);
        break;
    case 2:m_edev_mod1103->setSpeedUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SPU_km_per_hour);
        break;
    }
    ui->label_Display_Car_Unit_V2->setText(ui->comboBox_Display_Car_Unit_V2->currentText());
    ui->label_Display_Car_Unit_V4->setText(ui->comboBox_Display_Car_Unit_V2->currentText());
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_A2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::ACU_mm_per_s2);
        break;
    case 1:m_edev_mod1103->setAccelerationUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::ACU_m_per_s2);
        break;
    }
    ui->label_Display_Car_Unit_A2->setText(ui->comboBox_Display_Car_Unit_A2->currentText());
    ui->label_Display_Car_Unit_A4->setText(ui->comboBox_Display_Car_Unit_A2->currentText());
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_T2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::TMU_Second);
        break;
    case 1:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::TMU_mSecond);
        break;
    case 2:m_edev_mod1103->setTimeUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::TMU_uSecond);
        break;
    }
    ui->label_Display_Car_Unit_T4->setText(ui->comboBox_Display_Car_Unit_T2->currentText());
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_F2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SSU_scaleForce);
        break;
    case 1:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SSU_scaleGram);
        break;
    case 2:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SSU_scaleKiloGram);
        break;
    case 3:m_edev_mod1103->setForceUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::SSU_scaleWeight);
        break;
    }
    ui->label_Display_Car_Unit_F2->setText(ui->comboBox_Display_Car_Unit_F2->currentText());
    ui->label_Display_Car_Unit_F4->setText(ui->comboBox_Display_Car_Unit_F2->currentText());
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_Display_Car_Unit_PIN2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::VTU_Volt);
        break;
    case 1:m_edev_mod1103->setVoltageUnit(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::VTU_mVolt);
        break;
    }
ui->label_Display_Car_Unit_V4->setText(ui->comboBox_Display_Car_Unit_PIN2->currentText());
m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
}

void Module_MOD1103::on_comboBox_SelectExample_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_CMD_carMode = EDev_Mod1103::CMD_condition;
        break;
    case 1:m_CMD_carMode = EDev_Mod1103::CMD_continous;
        break;
    }
}

void Module_MOD1103::on_pushButton_SetZero_Car1_clicked()
{
    ui->pushButton_SetZero_Car1->setEnabled(false);
    if(ui->radioButton_Display_Car_S1->isChecked()){
        m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_ZeroCAR);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Quãng đường\"";
        m_SWS_Status = SWS_SetCommand;
        m_edev_mod1103->setDistanceCheck();
    }
    else {
        if(ui->radioButton_Display_Car_F1->isChecked()){
            m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_ZeroForce);
            m_msgInfo = "Đã thiết lập điểm 0 cho \"Lực tác động\"";
            m_SWS_Status = SWS_SetCommand;
        }
        else{
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Chỉ có thể thiết lập điểm 0 cho \n\r"
                                   "\"Quãng đường\" và \"Lực tác động\".");
            m_QMessageBox->setWindowTitle("Lỗi cài đặt");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
    }
    ui->pushButton_SetZero_Car1->setEnabled(true);
    m_commandCheckCar = EDev_Mod1103::ESlave::CAR_01;
}

void Module_MOD1103::on_pushButton_Shutdown_Car1_clicked()
{
    ui->pushButton_Shutdown_Car1->setEnabled(false);
    m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_01,EDev_Mod1103::CCMD_Shutdown);
    m_msgInfo = "Đã tắt XE - 01.                         ";
    m_SWS_Status = SWS_SetCommand;
    ui->pushButton_Shutdown_Car1->setEnabled(true);
}

void Module_MOD1103::on_pushButton_SetZero_Car2_clicked()
{
    ui->pushButton_SetZero_Car2->setEnabled(false);
    if(ui->radioButton_Display_Car_S2->isChecked()){
        m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_ZeroCAR);
        m_msgInfo = "Đã thiết lập điểm 0 cho \"Quãng đường\"";
        m_SWS_Status = SWS_SetCommand;
    }
    else {
        if(ui->radioButton_Display_Car_F2->isChecked()){
            m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_ZeroForce);
            m_msgInfo = "Đã thiết lập điểm 0 cho \"Lực tác động\"";
            m_SWS_Status = SWS_SetCommand;
        }
        else{
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Đã có lỗi xảy ra! Chỉ có thể thiết lập điểm 0 cho \n\r"
                                   "\"Quãng đường\" và \"Lực tác động\".");
            m_QMessageBox->setWindowTitle("Lỗi cài đặt");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
        }
    }
    ui->pushButton_SetZero_Car2->setEnabled(true);
    m_commandCheckCar = EDev_Mod1103::ESlave::CAR_02;
}

void Module_MOD1103::on_pushButton_Shutdown_Car2_clicked()
{
    ui->pushButton_Shutdown_Car2->setEnabled(false);
    m_edev_mod1103->writeSensorCommand(EDev_Mod1103::ESlave::CAR_02,EDev_Mod1103::CCMD_Shutdown);
    m_msgInfo = "Đã tắt XE - 02.                         ";
    m_SWS_Status = SWS_SetCommand;
    ui->pushButton_Shutdown_Car2->setEnabled(true);
}


void Module_MOD1103::on_checkBox_Display_Car_Vector2_toggled(bool checked)
{
    m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_02,checked);
}

void Module_MOD1103::on_checkBox_Display_Car_Vector1_toggled(bool checked)
{
    m_edev_mod1103->setMeasureVector(EDev_Mod1103::ESlave::CAR_01,checked);
}

void Module_MOD1103::on_pushButton_Cancel_clicked()
{
    this->close();
}

void Module_MOD1103::on_pushButton_SaveData_clicked()
{
    VFile _file;
       VFile::VFileDataUnit _unit;
       if(m_typeLine == EDev_Mod1103::TypeLine::typeSpline){
           for(int i=1;i<=m_edev_mod1103->chart()->lines();i++){
               _unit.lines.append(m_edev_mod1103->chart()->lines(i));
           }
           _unit.device = m_deviceInformation;
           _unit.infoSample.interval = m_modbusSampleTime;
           _unit.infoSample.axisX_Max = m_edev_mod1103->chart()->chartAxisX->max();
           _unit.infoSample.axisX_Min = m_edev_mod1103->chart()->chartAxisX->min();
           _unit.infoSample.axisY_Max = m_edev_mod1103->chart()->chartAxisY->max();
           _unit.infoSample.axisY_Min = m_edev_mod1103->chart()->chartAxisY->min();
       }
       else{
           for(int i=1;i<=m_edev_mod1103->chartLines()->lines();i++){
               _unit.lines.append(m_edev_mod1103->chartLines()->lines(i));
           }
           _unit.device = m_deviceInformation;
           _unit.infoSample.interval = m_modbusSampleTime;
           _unit.infoSample.axisX_Max = m_edev_mod1103->chartLines()->chartAxisX->max();
           _unit.infoSample.axisX_Min = m_edev_mod1103->chartLines()->chartAxisX->min();
           _unit.infoSample.axisY_Max = m_edev_mod1103->chartLines()->chartAxisY->max();
           _unit.infoSample.axisY_Min = m_edev_mod1103->chartLines()->chartAxisY->min();
       }


       _unit.texts.append("XE01_S");
       _unit.texts.append("XE01_V");
       _unit.texts.append("XE01_A");
       _unit.texts.append("XE01_F");
       _unit.texts.append("XE02_S");
       _unit.texts.append("XE02_V");
       _unit.texts.append("XE02_A");
       _unit.texts.append("XE02_F");

       switch(ui->comboBox_SelectMode->currentIndex()){
       case 0:
           _unit.infoSample.count = _unit.lines.count();
           _unit.infoSample.typeSample = ui->comboBox_SelectMode->currentText();
           _file.saveDataF(_unit);
           break;
       case 1:
           _unit.infoSample.count = _unit.lines.count();
           _unit.infoSample.typeSample = ui->comboBox_SelectMode->currentText();
           _file.saveDataF(_unit);
           break;
       }
       QPixmap p = this->grab();// m_chartView->grab();
       QFile filePNG(_file.fileName().left(_file.fileName().count()-4)+".png");
       filePNG.open(QIODevice::WriteOnly);
       p.save(&filePNG, "PNG");
}

void Module_MOD1103::on_pushButton_OpenData_clicked()
{
    VFile file;
    VFile::VFileDataUnit unit;
    unit.texts.append("XE01_S");
    unit.texts.append("XE01_V");
    unit.texts.append("XE01_A");
    unit.texts.append("XE01_F");
    unit.texts.append("XE02_S");
    unit.texts.append("XE02_V");
    unit.texts.append("XE02_A");
    unit.texts.append("XE02_F");
    unit = file.loadDataF(unit);
    if(file.fileName()=="")return;
    if(unit.lines.count()<1){
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

    //Update graphic
    if(m_typeLine==EDev_Mod1103::TypeLine::typeSpline){
        ECharts::Parameter _parameter = m_edev_mod1103->chartParameter();
        _parameter.axisX_Range_Min = unit.infoSample.axisX_Min;
        _parameter.axisX_Range_Max = unit.infoSample.axisX_Max;
        _parameter.axisY_Range_Min = unit.infoSample.axisY_Min;
        _parameter.axisY_Range_Max = unit.infoSample.axisY_Max;
        m_edev_mod1103->setChartParameter(_parameter);
    }
    else{
        EChartLines::Parameter _parameter = m_edev_mod1103->chartLineParameter();
        _parameter.axisX_Range_Min = unit.infoSample.axisX_Min;
        _parameter.axisX_Range_Max = unit.infoSample.axisX_Max;
        _parameter.axisY_Range_Min = unit.infoSample.axisY_Min;
        _parameter.axisY_Range_Max = unit.infoSample.axisY_Max;
        m_edev_mod1103->setChartParameter(_parameter);
    }

     //   m_echart->init();
    QSplineSeries* line;
    for(int i=0;i<unit.infoSample.count;i++){
        line = new QSplineSeries();
        int j=0;
        for(j=0;j<unit.lines[i].count();j++){
            line->append(unit.lines[i][j].x(),unit.lines[i][j].y());
        }
        m_edev_mod1103->setSpline(line,i+1);
    }
}


void Module_MOD1103::on_spinBox_Display_Car_Pre_S1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.s.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_V1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.v.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_A1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.a.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_T1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.t.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_F1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.f.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_PIN1_valueChanged(int arg1)
{
    m_eCar_01 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_01);
    m_eCar_01.pin.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_01,m_eCar_01);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_S2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.s.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_V2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.v.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_A2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.a.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_T2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.t.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_F2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.f.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_spinBox_Display_Car_Pre_PIN2_valueChanged(int arg1)
{
    m_eCar_02 = m_edev_mod1103->getCar(EDev_Mod1103::ESlave::CAR_02);
    m_eCar_02.pin.pre = arg1;
    m_edev_mod1103->setCar(EDev_Mod1103::ESlave::CAR_02,m_eCar_02);
}

void Module_MOD1103::on_checkBox_Car01_S_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car01_V_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car01_A_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car01_F_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car02_S_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car02_V_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car02_A_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}

void Module_MOD1103::on_checkBox_Car02_F_toggled(bool checked)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(!checked);
}


void Module_MOD1103::on_checkBox_Filter_toggled(bool checked)
{
    ui->frame_Filter->setEnabled(checked);
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(false);
}

void Module_MOD1103::on_pushButton_Filter_Setup_clicked()
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(false);
}


void Module_MOD1103::on_radioButton_Filter_LPF_toggled(bool)
{
    if(m_PRS_processStatus==PRS_pause)this->chartRefresh(false);
}

void Module_MOD1103::on_pushButton_TrackLine_Default_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Module_MOD1103::on_pushButton_TrackLine_Tooltip_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_tooltip);
}

void Module_MOD1103::on_pushButton_TrackLine_Yax_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_y_ax);
}

void Module_MOD1103::on_comboBox_SelectMode_currentIndexChanged(int index)
{
    switch(index){
    case 0:m_CMD_carMode=EDev_Mod1103::CMD_condition;
        break;
    case 1:m_CMD_carMode=EDev_Mod1103::CMD_continous;
        break;
    }
}

void Module_MOD1103::on_pushButton_SampleFreq_clicked()
{
    uint val=0;
    val = ui->spinBox_SampleFreq->value();
    if(val!=0)val = 1000/val;
    m_edev_mod1103->writeSingleREG(EDev_Mod1103::dREG_CAR01_SPT,val);
    m_msgInfo = "Đã cài đặt tần số lấy mẫu!";
    m_SWS_Status = SWS_Calib;
}

void Module_MOD1103::on_tabWidget_4_currentChanged(int index)
{
    if(index==1){
        if(m_eCar_01.SPT!=0)ui->spinBox_SampleFreq->setValue(QVariant(1000/m_eCar_01.SPT).toInt());
        if(m_eCar_02.SPT!=0)ui->spinBox_SampleFreq->setValue(QVariant(1000/m_eCar_02.SPT).toInt());
    }
}



void Module_MOD1103::on_checkBox_Display_Car_reSign1_toggled(bool checked)
{
    m_edev_mod1103->setReverseSign(EDev_Mod1103::ESlave::CAR_01,checked);
    m_Car01_Zero_s *= (-1);
    m_Car01_Zero_f *= (-1);
}


void Module_MOD1103::on_checkBox_Display_Car_reSign2_toggled(bool checked)
{
    m_edev_mod1103->setReverseSign(EDev_Mod1103::ESlave::CAR_02,checked);
    m_Car02_Zero_s *= (-1);
    m_Car02_Zero_f *= (-1);
}


void Module_MOD1103::on_radioButton_Graph_SPline_toggled(bool checked)
{
    if(checked)m_typeLine=EDev_Mod1103::TypeLine::typeSpline;
        else m_typeLine=EDev_Mod1103::TypeLine::typeLine;
    m_edev_mod1103->setTypeLine(m_typeLine);
    this->chartInit();
    this->chartClear(true);
}

