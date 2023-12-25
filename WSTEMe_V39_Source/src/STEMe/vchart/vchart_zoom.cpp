#include "vchart_zoom.h"
#include "ui_vchart_zoom.h"


//system
#include "QMessageBox"
#include <QTimer>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
#include <vfile/vfile.h>
#include <QFile>


Vchart_Zoom::Vchart_Zoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vchart_Zoom)
{
    ui->setupUi(this);

    if(m_chartTimer)delete m_chartTimer;
    m_chartTimer = new QTimer();
    connect(m_chartTimer,&QTimer::timeout,this,&Vchart_Zoom::on_chartTimer);
    m_chartTimer->start(m_chartTimerInterval);

    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

Vchart_Zoom::~Vchart_Zoom()
{
    delete ui;
}

void Vchart_Zoom::setDevice(VDevice dev)
{
    m_device = dev;
    ui->label_Device_Name->setText(m_device.name());
    switch(m_device.typeDevice()){
    case VDevice::Sensor:ui->label_Device_Type->setText("Cảm biến");
        break;
    case VDevice::Module:ui->label_Device_Type->setText("Mô-đun thực hành");
        break;
    case VDevice::System:ui->label_Device_Type->setText("Mô hình thí nghiệm");
        break;
    case VDevice::Setting:ui->label_Device_Type->setText("Cài đặt và tiện ích");
        break;
    case VDevice::Root:ui->label_Device_Type->setText("Quản lý");
        break;
    }
    ui->label_Device_SN->setText(m_device.serialNumber());
}

void Vchart_Zoom::vchartInit(double y_min, double y_max, double x_max, int interval)
{
    m_axisY_Range_Min = y_min;
    m_axisY_Range_Max = y_max;
    m_axisX_Range = x_max;
    ui->spinBox_AxisY_Range_Max->setValue(QVariant(m_axisY_Range_Max).toInt());
    ui->spinBox_AxisY_Range_Max->setValue(QVariant(m_axisY_Range_Min).toInt());
    ui->spinBox_AxitX_Range_Max->setValue(QVariant(m_axisX_Range).toInt());
    ui->spinBox_SampleTime->setValue(interval);
    if(m_echart)delete m_echart;
    m_echart = new ECharts();
    ECharts::Parameter parameter;
    parameter.timerScan = m_chartTimerInterval;
    parameter.axisX_Range_Max = m_axisX_Range*(QVariant(ui->spinBox_SampleTime->value()).toDouble()/1000);
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(1);
    m_echart->setAxisXName("Thời gian");
    m_echart->setAxisYName(ui->label_deviceUnit->text());
    m_echart->init(parameter,3,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(ui->spinBox_SampleTime->value()).toDouble()))).toInt());//Scan in 1 hour

}

void Vchart_Zoom::vchartGraph(double val, QString units)
{
this->chartGraph(val);
ui->label_deviceUnit->setText(units);
}



/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
void Vchart_Zoom::on_chartTimer()
{
    m_chartTimer->stop();
    /*if(m_chartListValue.count()>0){
        if(m_chartListValue_Count>=m_chartListValue.count())m_chartListValue_Count=m_chartListValue.count()-1;
        this->chartGraph(m_chartListValue[m_chartListValue_Count++]);
    }*/
    m_chartTimer->start();
}
/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
void Vchart_Zoom::chartInit()
{
    if(m_echart)delete m_echart;
    m_echart = new ECharts();
    ECharts::Parameter parameter;
    parameter.timerScan = m_chartTimerInterval;
    parameter.axisX_Range_Max = m_axisX_Range*(QVariant(ui->spinBox_SampleTime->value()).toDouble()/1000);
    parameter.axisX_Range_Min = 0;
    parameter.axisX_TickCount = m_axisX_TickCount;
    parameter.axisY_TickCount = m_axisY_TickCount;
    parameter.axisY_Range_Min = m_axisY_Range_Min;
    parameter.axisY_Range_Max = m_axisY_Range_Max;
    m_echart->setAxisXFormat(1);
    m_echart->setAxisXName("Thời gian");
    m_echart->setAxisYName(ui->label_deviceUnit->text());
    m_echart->init(parameter,3,ui->frame_Chart);
    m_echart->setSampleMax(QVariant(3600.0*(1000.0/(QVariant(ui->spinBox_SampleTime->value()).toDouble()))).toInt());//Scan in 1 hour

}

void Vchart_Zoom::chartGraph(double val)
{
    if(m_isOpenFile)return;
    //Check graphType
    m_axtX_Index += QVariant(ui->spinBox_SampleTime->value()).toDouble()/1000;
    m_echart->graph(QPointF(m_axtX_Index,val));
  //  m_echart->graph(val);
    if(m_GET_SAMPLE_MAX<val)m_GET_SAMPLE_MAX=val;
    if(m_GET_SAMPLE_MIN>val)m_GET_SAMPLE_MIN=val;
    m_GET_SAMPLE_COUNT++;
    m_GET_SAMPLE_SUM+=val;
    QString tilte = "Đánh giá phép đo trên " + QString::number(ui->spinBox_AxitX_Range_Max->value()) + " mẫu đo:";
    ui->groupBox_Analysis->setTitle(tilte);
    ui->label_ValueMax->setText(QString::number(m_GET_SAMPLE_MAX,'f',3));
    ui->label_ValueMin->setText(QString::number(m_GET_SAMPLE_MIN,'f',3));
    ui->label_ValueAvg->setText(QString::number(m_GET_SAMPLE_SUM/m_GET_SAMPLE_COUNT,'f',3));
    ui->lcdNumber_Value->display(QString::number(val,'f',3));
}


void Vchart_Zoom::chartClear()
{
    m_echart->clear();
    m_echart->setLinesIndex(1);
    m_axtX_Index=0;
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}

void Vchart_Zoom::setTrackLine(EChartGesture::ETrackLine track)
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

void Vchart_Zoom::on_pushButton_Cancel_clicked()
{
    this->close();
}


void Vchart_Zoom::closeEvent(QCloseEvent *event)
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
         if(m_chartTimer)m_chartTimer->deleteLater();
         event->accept();
     }
}

void Vchart_Zoom::on_pushButton_SaveData_clicked()
{
    VFile _file;
    VFile::VFileDataUnit _unit;
    for(int i=1;i<=m_echart->lines();i++){
        _unit.data.append(m_echart->vector(i));
    }
    _unit.device = m_device;
    _unit.infoSample.interval = ui->spinBox_SampleTime->value();
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
}

void Vchart_Zoom::on_pushButton_OpenData_clicked()
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
    ui->label_Device_Name->setText(unit.device.name());
    ui->label_Device_Type->setText(unit.device.type());
    ui->label_Device_SN->setText(unit.device.serialNumber());
    ui->spinBox_SampleTime->setValue(unit.infoSample.interval);

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

void Vchart_Zoom::setOpenFile(bool status)
{
    if(status)m_isOpenFile=true;
    else{
        //this->setDeviceWidget(m_deviceInformation);
        ui->spinBox_SampleTime->setValue(m_chartTimerScan);
        m_isOpenFile=false;
        this->chartClear();
    }
}

void Vchart_Zoom::on_pushButton_Stop_clicked()
{
    if(ui->pushButton_Stop->text()=="Dừng"){
        m_isOpenFile = true;
        ui->pushButton_Stop->setText("Tiếp tục");
        ui->pushButton_Stop->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(0, 0, 255);");
    }
    else{
        m_isOpenFile = false;
        ui->pushButton_Stop->setText("Dừng");
        ui->pushButton_Stop->setStyleSheet("background-color: rgb(225, 225, 225);color: rgb(170, 0, 0);");
    }

}


void Vchart_Zoom::on_pushButton_SetSampleTime_clicked()
{
    m_chartTimerInterval = ui->spinBox_SampleTime->value();
    emit setChartParameter(m_chartTimerInterval);
    this->chartClear();
}

void Vchart_Zoom::on_pushButton_SetConfigChart_clicked()
{
    if(ui->spinBox_AxisY_Range_Min->value()>=ui->spinBox_AxisY_Range_Max->value()){
        QMessageBox::information(this,"Cài đặt đồ thị","Dải đo \"Thấp\" phải nhỏ hơn dải đo \"Cao\"!",QMessageBox::Ok);
        return;
    }

    ECharts::Parameter p;
    p = m_echart->parameter();
    p.axisX_Range_Max = ui->spinBox_AxitX_Range_Max->value()*(QVariant(ui->spinBox_SampleTime->value()).toDouble()/1000);
    p.axisY_Range_Max= ui->spinBox_AxisY_Range_Max->value();
    p.axisY_Range_Min = ui->spinBox_AxisY_Range_Min->value();
    m_echart->setParameter(p);
    this->chartClear();
}

void Vchart_Zoom::on_pushButton_ClearChart_clicked()
{
    if(m_isOpenFile)setOpenFile(false);
    ui->spinBox_SampleTime->setValue(m_chartTimerScan);
    m_isOpenFile=true;
    ui->pushButton_Stop->setText("Tiếp tục");
    ui->pushButton_Stop->setStyleSheet("color: rgb(0, 0, 255);");
    this->chartClear();
}

void Vchart_Zoom::on_radioButton_Accumulation_toggled(bool checked)
{
    this->chartClear();
    if(checked)m_echart->setScanType(ECharts::scanCompact);
    else m_echart->setScanType(ECharts::scanScroll);
}

void Vchart_Zoom::on_pushButton_TrackLine_Default_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_default);
}


void Vchart_Zoom::on_pushButton_TrackLine_Tooltip_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_tooltip);
}


void Vchart_Zoom::on_pushButton_TrackLine_Yax_clicked()
{
    this->setTrackLine(EChartGesture::ETrackLine::ETL_y_ax);
}

