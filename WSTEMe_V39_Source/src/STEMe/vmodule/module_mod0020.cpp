
//system
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QModbusDataUnit>

//user
#include "module_mod0020.h"
#include "ui_module_mod0020.h"
#include "vcommunication/vcommunicationmodbus.h"

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

////////////////////////////////////////////////////////////////////////////Modbus RTU communication Function for All Module....................

void Module_MOD0020::modbusSetAddress()
{
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,0xFF00,4);
    VNetworkDataUnit _netUnit;
    m_modbusAddress = 0;
    unit.setValues(m_deviceInformation.serialVector(m_deviceInformation.address()));
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_modbusAddress);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    emit modbusRtuRequest(_netUnit);
}
void Module_MOD0020::modbusRequestInputRegisters()
{
    QModbusDataUnit frameRead(QModbusDataUnit::InputRegisters,dREG_START,dREG_NUMBER);
    VNetworkDataUnit _netUnit;
    m_modbusAddress = m_deviceInformation.address();
    _netUnit.setModbusDataUnit(frameRead);
    _netUnit.setAddress(m_modbusAddress);
    _netUnit.setRequestType(VNetworkDataUnit::Read);
    emit modbusRtuRequest(_netUnit);
//    qDebug()<<"res";
}

void Module_MOD0020::modbusReadResult(VNetworkDataUnit unit)
{
    if(unit.status()){
        m_modbusConnectStatus = Module_MOD0020::deviceConnected;
        m_modbusNumberOfRetries = 0;
        m_networkDataUnit = unit;
        }
        else{
            if(m_modbusNumberOfRetries >= m_modbusNumberOfRetriesMax)
                m_modbusConnectStatus = Module_MOD0020::deviceDisconnected;
            else
                m_modbusConnectStatus = Module_MOD0020::deviceReConnect;
            }
}

void Module_MOD0020::modbusWriteResult(VNetworkDataUnit unit)
{
    if(unit.address()==0){ //set New Address
        m_modbusConnectStatus = Module_MOD0020::deviceTestConnect;
    }
}

void Module_MOD0020::modbusRtuReply(VNetworkDataUnit unit)
{
        if(unit.address()==m_modbusAddress)  //check address of device
            {
            if(unit.requestType()==VNetworkDataUnit::Read)this->modbusReadResult(unit);
            else this->modbusWriteResult(unit);
            }
}


void Module_MOD0020::on_modbusTimer()
{
    m_modbusTimer->stop();
    switch(m_modbusConnectStatus){
        case Module_MOD0020::deviceDisconnected:   //Send command connet with serialNumber  of device and new address
                modbusSetAddress();
                m_modbusConnectStatus = Module_MOD0020::deviceTimeout;
                m_modbusPollCount=0;
                m_deviceModbusConnect=false;
                break;
        case Module_MOD0020::deviceTestConnect:
                modbusRequestInputRegisters();
                m_modbusNumberOfRetries=m_modbusNumberOfRetriesMax;
                m_modbusConnectStatus = Module_MOD0020::deviceTimeout;
            break;
        case Module_MOD0020::deviceConnected:
                if(m_modbusSampleTimeCount++>=(m_modbusSampleTime/100)){
                    modbusRequestInputRegisters();
                    m_modbusConnectStatus = Module_MOD0020::deviceTimeout;
                    m_modbusSampleTimeCount=0;
                    m_deviceModbusConnect = true;
                }
                break;
        case Module_MOD0020::deviceReConnect:
                if(m_modbusSampleTimeCount++>=(m_modbusSampleTime/100)){
                    modbusRequestInputRegisters();
                    m_modbusConnectStatus = Module_MOD0020::deviceTimeout;
                    m_modbusSampleTimeCount=0;
                    m_modbusNumberOfRetries++;
                }
                break;
        case Module_MOD0020::deviceTimeout:
                if(m_modbusPollCount++>=(m_modbusPollTimeout/100)){
                 m_modbusConnectStatus = Module_MOD0020::deviceDisconnected;
                 m_modbusPollCount=0;
                }
                break;
    }
    m_modbusTimer->start();
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
void Module_MOD0020::on_displayTimer()
{
    if(m_chartTimerScan<100){
        m_displayTimer->stop();
    this->displayPoll();
    m_displayTimer->start();
    }
    else this->displayPoll();

}
void Module_MOD0020::displayPoll()
{
    if(m_deviceModbusConnect){
        if(m_networkDataUnit.requestType()==m_networkDataUnit.Read){
            if(m_networkDataUnit.status()){
                QModbusDataUnit m_deviceUnit = m_networkDataUnit.modbusDataUnit();

                double _adc = 0;
                _adc = QVariant(m_deviceUnit.value(0)).toDouble();
                bool ok;
                double _ratio = QString(ui->lineEdit_RatioValue->text()).toDouble(&ok);
                if(!ok){
                    ui->lineEdit_RatioValue->setText("1");
                }
                else{
                    _adc = _adc*_ratio;
                }
                ui->lcdNumber_Test->display(QString::number(_adc));
                //Chart graph
                this->chartGraph(_adc);

            }
        }
    }
    else {
        if(m_displayToggle){
            ui->lcdNumber_Test->display(QString::number(-1));
            m_displayToggle=false;
        }
        else {
            ui->lcdNumber_Test->display(QString::number(0));
            m_displayToggle=true;
        }

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
void Module_MOD0020::chartInit()
{
    QPen _pen(Qt::red);
    this->chartInit(_pen);
}

void Module_MOD0020::chartInit(QPen _pen)
{
    if(m_chart)delete m_chart;
    m_chart = new QChart();

    if(m_force_Sample)delete m_force_Sample;
    m_force_Sample = new Force_Sample();
    m_force_Sample->fs_device = m_deviceInformation;
    m_force_Sample->fs_Control_Index=0;
    m_force_Sample->fs_sampleTime = m_chartTimerScan;
    m_force_Sample->fs_Control[0].fc_chart = new QSplineSeries();
    m_force_Sample->fs_Control[1].fc_chart = new QSplineSeries();
    m_force_Sample->fs_Control[2].fc_chart = new QSplineSeries();

    switch(ui->comboBox_SelectSample_2->currentIndex()){
    case 0:m_force_Sample->fs_sampleType = Sample_Type::sampleAuto;
        break;
    case 1:m_force_Sample->fs_sampleType = Sample_Type::sampleWhenNext;
        break;
    case 2:m_force_Sample->fs_sampleType = Sample_Type::sampleThreeStep;
        break;
    default:m_force_Sample->fs_sampleType = Sample_Type::sampleAuto;
        break;
    }

    if(m_chartAxisX)delete m_chartAxisX;
    m_chartAxisX = new QValueAxis(m_chart);
    if(m_chartAxisY)delete m_chartAxisY;
    m_chartAxisY = new QValueAxis(m_chart);

    _pen = QPen(Qt::red);
    _pen.setWidth(3);
    m_force_Sample->fs_Control[0].fc_chart->setPen(_pen);
    _pen = QPen(Qt::white);
    _pen.setWidth(3);
    m_force_Sample->fs_Control[1].fc_chart->setPen(_pen);
    _pen = QPen(Qt::green);
    _pen.setWidth(3);
    m_force_Sample->fs_Control[2].fc_chart->setPen(_pen);


    m_chart->addSeries(m_force_Sample->fs_Control[0].fc_chart);
    m_chart->addSeries(m_force_Sample->fs_Control[1].fc_chart);
    m_chart->addSeries(m_force_Sample->fs_Control[2].fc_chart);


    m_chart->addAxis(m_chartAxisX,Qt::AlignBottom);
    m_chart->addAxis(m_chartAxisY,Qt::AlignLeft);


    m_force_Sample->fs_Control[0].fc_chart->attachAxis(m_chartAxisX);
    m_force_Sample->fs_Control[0].fc_chart->attachAxis(m_chartAxisY);
    m_force_Sample->fs_Control[1].fc_chart->attachAxis(m_chartAxisX);
    m_force_Sample->fs_Control[1].fc_chart->attachAxis(m_chartAxisY);
    m_force_Sample->fs_Control[2].fc_chart->attachAxis(m_chartAxisX);
    m_force_Sample->fs_Control[2].fc_chart->attachAxis(m_chartAxisY);


    m_chartAxisX->setTickCount(m_axisX_TickCount);
    m_chartAxisX->setRange(0, m_axisX_Range);
    m_chartAxisX->setLabelsBrush(QColor("#b6b7b8"));
    m_chartAxisX->setLabelFormat("%u");
    //m_axisX->setTitleText("giây");
   // m_axisX->setTitleFont(QFont("Arial", 8));

    m_chartAxisY->setTickCount(m_axisY_TickCount);
    m_chartAxisY->setRange(m_axisY_Range_Min, m_axisY_Range_Max);
    m_chartAxisY->setLabelFormat("%.1f");
    m_chartAxisY->setLabelsBrush(QColor("#b6b7b8"));
   //m_axisY->setTitleText("(*C)");
   // m_splineChart->setTitle(m_device.name());
   // m_splineChart->setTitleFont(QFont("Arial", 10, QFont::Bold));
    m_chart->legend()->hide();
    //m_chart->setAnimationOptions(QChart::AllAnimations);
    m_chart->setBackgroundBrush(QColor("#0f1c23"));
    m_chart->setBackgroundPen(QColor(Qt::cyan));

    if(m_chartView)delete m_chartView;
    m_chartView = new QChartView(m_chart);
    //m_chartView->setRenderHint(QPainter::Antialiasing);
    if(m_chartGridLayout)delete m_chartGridLayout;
    m_chartGridLayout = new QGridLayout(ui->frame_Chart);
    m_chartGridLayout->addWidget(m_chartView,0,0);
}

void Module_MOD0020::chartGraph(double val)
{
    if(!m_force_Sample)return;
    int _index = m_force_Sample->fs_Control_Index;
    int sampleNumberLimit = 86400000/m_chartTimerScan;  //86400 = 1 day = 24h = 86400 second
    m_force_Sample->fs_Control[_index].fc_chartStep +=1;
    if(m_force_Sample->fs_Control[_index].fc_chartStep >= sampleNumberLimit)this->chartClear(true);
    m_force_Sample->fs_chartArray[_index].append(val);
    //Calculator information
    if(val>m_force_Sample->fs_Control[_index].fc_Max)m_force_Sample->fs_Control[_index].fc_Max=val;
    if(val<m_force_Sample->fs_Control[_index].fc_Min)m_force_Sample->fs_Control[_index].fc_Min=val;
    m_force_Sample->fs_Control[_index].fc_Sum +=val;
    m_force_Sample->fs_Control[_index].fc_Mean = m_force_Sample->fs_Control[_index].fc_Sum/m_force_Sample->fs_Control[_index].fc_chartStep;
    //Resize_Chart AxisY
    if(val>m_chartAxisY->max())m_chartAxisY->setMax(val+1);
    if(val<m_chartAxisY->min())m_chartAxisY->setMin(val-1);

    //Select chart with continuously or accumulation
    if((m_force_Sample->fs_chartArray[_index].count()>=m_axisX_Range)&&(ui->radioButton_Continuously->isChecked())){
        for(int i=0;i<m_axisX_Range;i++){
            m_force_Sample->fs_Control[_index].fc_chart->replace(i,i,m_force_Sample->fs_chartArray[_index][i]);
        }
      m_force_Sample->fs_chartArray[_index].pop_front();
    }
    else    {
        m_force_Sample->fs_Control[_index].fc_chart->append(m_force_Sample->fs_Control[_index].fc_chartStep,val);
        int axisX_Max = m_axisX_Range;
        if(m_force_Sample->fs_sampleType==Sample_Type::sampleThreeStep){
            for(int i=0;i<3;i++){
                if(m_force_Sample->fs_Control[i].fc_chart->count()>axisX_Max)axisX_Max=m_force_Sample->fs_Control[i].fc_chart->count();
            }
        }
        if(ui->radioButton_Accumulation->isChecked()&&(m_force_Sample->fs_chartArray[_index].count()>=axisX_Max)){
         m_chartAxisX->setMax(m_force_Sample->fs_Control[_index].fc_chart->count());
        }
    }





    ui->label_ValueMax_2->setNum(m_force_Sample->fs_Control[_index].fc_Max);
    ui->label_ValueMin_2->setNum(m_force_Sample->fs_Control[_index].fc_Min);
    ui->label_ValueAvg_2->setNum(m_force_Sample->fs_Control[_index].fc_Mean);
    ui->lcdNumber_Test->display(val);

}

void Module_MOD0020::chartClear(bool init)
{
 if(init)this->chartInit();
 else{
     m_force_Sample->fs_device = m_deviceInformation;
     m_force_Sample->fs_sampleTime = m_chartTimerScan;
     for(int i=0;i<3;i++){
          m_force_Sample->fs_chartArray[i].clear();
          m_force_Sample->fs_Control[i].fc_chart->clear();
          m_force_Sample->fs_Control[i].fc_chartStep=0;
          m_force_Sample->fs_Control[i].fc_Max=-0xFFFFFFFF;
          m_force_Sample->fs_Control[i].fc_Min=0xFFFFFFFF;
          m_force_Sample->fs_Control[i].fc_Sum=-0;
     }
 }
}



/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Module_MOD0020::Module_MOD0020(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Module_MOD0020)
{
    ui->setupUi(this);
    m_ADC_Offset.resize(2);




}

Module_MOD0020::~Module_MOD0020()
{
    delete ui;
}


void Module_MOD0020::setDeviceWidget(VDevice dev)
{
   m_deviceInformation = dev;
    this->setWindowTitle(m_deviceInformation.name());
   ui->label_Name_2->setText(m_deviceInformation.name());
   ui->label_Address_2->setText(QString::number(m_deviceInformation.address()));
   ui->label_SerialNumber_2->setText(m_deviceInformation.serialNumber());
   ui->label_Description_2->setText(m_deviceInformation.description());


   if(m_modbusTimer)delete m_modbusTimer;
   m_modbusTimer = new QTimer();
   connect(m_modbusTimer,&QTimer::timeout,this,&Module_MOD0020::on_modbusTimer);
   m_modbusTimer->start(100); //100msecond per ticked

   if(m_displayTimer)delete m_displayTimer;
   m_displayTimer = new QTimer();
   connect(m_displayTimer,&QTimer::timeout,this,&Module_MOD0020::on_displayTimer);
   m_displayTimer->start(m_displayTimePoll);
   this->chartInit();
   ui->spinBox_SampleTime_2->setValue(m_chartTimerScan);

}



void Module_MOD0020::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr, "ATH0101",
                                                                 tr("Bạn có muốn thoát khỏi màn hình không?\n"),QMessageBox::No | QMessageBox::Yes,
                                                                 QMessageBox::Yes);
     if (resBtn != QMessageBox::Yes) {
         event->ignore();
     } else {

         m_chartGridLayout->deleteLater();
         m_chartView->deleteLater();
         m_chart->deleteLater();
         m_chartAxisX->deleteLater();
         m_chartAxisY->deleteLater();
         m_displayTimer->deleteLater();
         m_modbusTimer->deleteLater();
         event->accept();
     }
}


void Module_MOD0020::on_pushButton_2_clicked()
{
    ui->pushButton_Zero->setEnabled(false);
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,dREG_ADC_ZERO_HI,2);
    VNetworkDataUnit _netUnit;
    m_modbusAddress = m_deviceInformation.address();
    unit.setValues(m_ADC_Offset);
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_modbusAddress);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    emit modbusRtuRequest(_netUnit);
    ui->pushButton_Zero->setEnabled(true);
}

quint16 Module_MOD0020::macroEncodeREG(double reg,bool *ok)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x    | Sign2|-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D13 = x
    // D15 D14 D13 = 10^-4 to 10^4
    // D12 is sign of data, D12 = 1: sign = "-", D12 = 0: sign = "+"
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    quint16 Sign1=0,Sign2=0;
    quint16 x=6,data=0;
    quint16 i=0;
    //get sign of reg
    if(reg<0){
        reg *= (-1);
    Sign2 = 0x1000;
    }
    reg *= 1000;
    for(i=0;i<6;i++){
        if(reg>4096){
            reg = reg/10;
            x--;
        }
        else break;
    }
    //Check data
    if(reg>4096)*ok=false;
    else *ok = true;
    //Check sign
    if(x>3){
        x=(x-3);
        Sign1 = 0x8000;
    }
    else x = 3-x;
    x = QString::number(x<<13).toUShort();
    data = QString::number(static_cast<int>(reg)).toUShort();
    data = Sign1|x|Sign2|data;
    return data;
}

double Module_MOD0020::macroDecriptionREG(quint16 reg)
{
    //REG = 16-bit = | D15 | D14 | D13 | D12 | D11 | D10 | D9 | D8 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
    //				 | Sign1|   10^x    | Sign2|-------------------------------12 bit Data-------------------|
    // D15 i sign of x, D15 = 1: sign = "-", D15 = 0: sign = "+"
    // D14-D13 = x
    // D15 D14 D13 = 10^-4 to 10^4
    // D12 is sign of data, D12 = 1: sign = "-", D12 = 0: sign = "+"
    // D11-D0 = 12 bit data
    // value = (sign2)Data * 10^(sign1)x
    double value=0;
    quint16 sign1=0,sign2=0,x=0,i=0;
    sign1 	= (reg>>15)&0x01; //get D15
    x		= (reg>>13)&0x03;//get D14-D13
    sign2	= (reg>>12)&0x01;//get D12
    value	= QString::number(reg&0xFFF).toDouble(); //get 12 bit data
    for(i=0;i<x;i++){
    if(sign1==1)//sign = "-" => 10^(-x)
        value = value/10;
        else value =value*10;	//sign = "+" => 10^x
    }
    if(sign2)value = value*(-1);
    return value;

}



void Module_MOD0020::deviceCalibration(double slope, double offset)
{
    bool ok;
    QVector<quint16> calib(2);
    calib[0] = Module_MOD0020::macroEncodeREG(slope,&ok);
    calib[1] = Module_MOD0020::macroEncodeREG(offset,&ok);
    if(!ok)return;
    //Send data to modbus
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,dREG_TEST_SLOPE,2);
    VNetworkDataUnit _netUnit;
    m_modbusAddress = m_deviceInformation.address();
    unit.setValues(calib);
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_modbusAddress);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    emit modbusRtuRequest(_netUnit);

}


void Module_MOD0020::on_pushButton_Calib_clicked()
{
double _offset=0,_slope=0,_calib=0;
bool ok;

_calib = QString(ui->lineEdit_Calib1_2->text()).toDouble(&ok)*100;
if(!ok){
    QMessageBox::information(this,"Error!", "Giá trị hiệu chuẩn nhập vào không đúng.",QMessageBox::Ok);
    return;
}
//_weight= QString::number(m_deviceUnit.value(dREG_WEIGHT_CALIB)).toUInt();
_slope = _calib/QString::number(m_Weight_Value_Calib).toDouble();
QString str = "_calib: "+QString::number(_calib) + "_calib: "+QString::number(m_Weight_Value_Calib) + "_slope: "+QString::number(_slope);
QMessageBox::information(this,"Error!", str,QMessageBox::Ok);
this->deviceCalibration(_slope,_offset);
}


void Module_MOD0020::motorControl()
{
    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters,dREG_MOTOR_CONTROL,2);
    VNetworkDataUnit _netUnit;
    quint16 ctrl=0;
    ctrl = QString::number(VL9110_MOTOR_CTRL<<12).toUShort()|QString::number(VL9110_MOTOR_STATUS<<8).toUShort()|VL9110_MOTOR_SPEED;
    m_MotorControl.resize(2);
    m_MotorControl[0] = ctrl;
    m_MotorControl[1] = 0;
    m_modbusAddress = m_deviceInformation.address();
    unit.setValues(m_MotorControl);
    _netUnit.setModbusDataUnit(unit);
    _netUnit.setAddress(m_modbusAddress);
    _netUnit.setRequestType(VNetworkDataUnit::Write);
    emit modbusRtuRequest(_netUnit);
}

void Module_MOD0020::motorGetStatus(double val)
{
    if(VL9110_MOTOR_STATUS==1){
        ui->pushButton_Previous_2->setEnabled(false);
        if(ui->pushButton_Previous_2->text()!="<<..")ui->pushButton_Previous_2->setText("<<..");
        else ui->pushButton_Previous_2->setText("..<<");
       if(m_sample_Index==2)this->chartGraph(val);
       m_force_Sample->fs_motorStatus = Motor_Status::motorBack;
    }
       else {
        ui->pushButton_Previous_2->setText("Lùi");
        ui->pushButton_Previous_2->setEnabled(true);
    }
    if(VL9110_MOTOR_STATUS==2)
    {
        ui->pushButton_Stop_2->setEnabled(false);
        if(ui->pushButton_Stop_2->text()!="֎")ui->pushButton_Stop_2->setText("֎");
        else ui->pushButton_Stop_2->setText("֍");
        m_force_Sample->fs_motorStatus = Motor_Status::motorStop;
    }
       else
        {
            ui->pushButton_Stop_2->setText("Dừng");
            ui->pushButton_Stop_2->setEnabled(true);
        }
    if(VL9110_MOTOR_STATUS==3)
    {
        ui->pushButton_Next_2->setEnabled(false);
        if(ui->pushButton_Next_2->text()!=".>>..")ui->pushButton_Next_2->setText(".>>..");
        else ui->pushButton_Next_2->setText("..>>.");
        if((m_force_Sample->fs_sampleType == Sample_Type::sampleWhenNext)||(m_force_Sample->fs_sampleType == Sample_Type::sampleThreeStep))this->chartGraph(val);
        m_force_Sample->fs_motorStatus = Motor_Status::motorNext;
    }
       else {
        ui->pushButton_Next_2->setText("Tiến");
        ui->pushButton_Next_2->setEnabled(true);
    }
}

void Module_MOD0020::on_pushButton_Next_clicked()
{
    VL9110_MOTOR_SPEED=100;
    VL9110_MOTOR_CTRL=3;
    this->motorControl();
    if(m_force_Sample->fs_sampleType==Sample_Type::sampleThreeStep){
        m_force_Sample->fs_Control_Index++;
        if(m_force_Sample->fs_Control_Index>2)m_force_Sample->fs_Control_Index=0;
        m_force_Sample->fs_chartArray[m_force_Sample->fs_Control_Index].clear();
        m_force_Sample->fs_Control[m_force_Sample->fs_Control_Index].fc_chartStep=0;
        m_force_Sample->fs_Control[m_force_Sample->fs_Control_Index].fc_chart->clear();
        m_force_Sample->fs_Control[m_force_Sample->fs_Control_Index].fc_Max=-0xFFFFFFFF;
        m_force_Sample->fs_Control[m_force_Sample->fs_Control_Index].fc_Min=0xFFFFFFFF;
        m_force_Sample->fs_Control[m_force_Sample->fs_Control_Index].fc_Sum=0;
    }
}

void Module_MOD0020::on_pushButton_Previous_clicked()
{
    VL9110_MOTOR_SPEED=100;
    VL9110_MOTOR_CTRL=1;
    this->motorControl();
}


void Module_MOD0020::on_pushButton_Cancel_clicked()
{
    this->close();
}

void Module_MOD0020::on_pushButton_Stop_clicked()
{
    VL9110_MOTOR_SPEED=100;
    VL9110_MOTOR_CTRL=2;
    this->motorControl();
}

void Module_MOD0020::on_comboBox_SelectSample_currentIndexChanged(int index)
{
    this->chartClear(true);
    if(index==2)m_force_Sample->fs_Control_Index=2;
}

void Module_MOD0020::on_pushButton_ClearChart_clicked()
{
    this->chartClear(true);
}

void Module_MOD0020::on_pushButton_SetConfigChart_clicked()
{
    if(ui->spinBox_AxisY_Range_Min_2->value()>=ui->spinBox_AxisY_Range_Max_2->value()){
        QMessageBox::information(this,"Cài đặt đồ thị","Dải đo \"Thấp\" phải nhỏ hơn dải đo \"Cao\"!",QMessageBox::Ok);
        return;
    }
    m_axisX_Range = ui->spinBox_AxitX_Range_Max_2->value();
    m_axisY_Range_Max = ui->spinBox_AxisY_Range_Max_2->value();
    m_axisY_Range_Min = ui->spinBox_AxisY_Range_Min_2->value();
    this->chartClear(true);
}



void Module_MOD0020::on_radioButton_Accumulation_toggled(bool)
{
    this->chartClear(true);
}

void Module_MOD0020::on_pushButton_SetSampleTime_2_clicked()
{
    ui->pushButton_SetSampleTime_2->setEnabled(false);
        m_modbusSampleTime = QString::number(ui->spinBox_SampleTime_2->value()).toUShort();
        m_displayTimePoll = ui->spinBox_SampleTime_2->value();
        m_displayTimer->setInterval(m_displayTimePoll);
}

void Module_MOD0020::on_spinBox_SampleTime_2_valueChanged(int arg1)
{
            if(arg1>ui->spinBox_SampleTime_2->minimum())ui->pushButton_SetSampleTime_2->setEnabled(true);
}
