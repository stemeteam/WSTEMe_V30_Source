#include "vdevicecalibration.h"
#include "ui_vdevicecalibration.h"

//system
#include <QtMath>
#include "QMessageBox"
#include <QTimer>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

//for use
#include <vdevice/vdevice.h>


QT_CHARTS_USE_NAMESPACE



/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...

void VDeviceCalibration::chartClear(bool)
{
}

void VDeviceCalibration::chartInit()
{
    QPen _pen(Qt::green);
    this->chartInit(_pen);
}

void VDeviceCalibration::chartInit(QPen _pen)
{
    if(m_chart)delete m_chart;
    m_chart = new QChart();

    //Graph line for Value_X
    if(m_chartSplineValue)delete m_chartSplineValue;
    m_chartSplineValue = new QSplineSeries(this);
    _pen.setWidth(6);
    m_chartSplineValue->setPen(_pen);
    m_chartSplineValue->append(0,0);

    //Graph line for Value_Y (calib)
    if(m_chartSplineCalib)delete m_chartSplineCalib;
    m_chartSplineCalib = new QSplineSeries(this);
    QPen _pen_Calib(Qt::blue);
    _pen_Calib.setWidth(3);
    m_chartSplineCalib->setPen(_pen_Calib);
    m_chartSplineCalib->append(0,0);

    //Graph line for Tolerance Max
    if(m_chartSplineToleranceMax)delete m_chartSplineToleranceMax;
    m_chartSplineToleranceMax = new QSplineSeries(this);
    QPen _pen_Max(Qt::red);
    _pen_Max.setWidth(1);
    m_chartSplineToleranceMax->setPen(_pen_Max);
    m_chartSplineToleranceMax->append(0,0);

    //Graph line for Tolerance Min
    if(m_chartSplineToleranceMin)delete m_chartSplineToleranceMin;
    m_chartSplineToleranceMin = new QSplineSeries(this);
    QPen _pen_Min(Qt::red);
    _pen_Min.setWidth(1);
    m_chartSplineToleranceMin->setPen(_pen_Min);
    m_chartSplineToleranceMin->append(0,0);

    if(m_chartAxisX)delete m_chartAxisX;
    m_chartAxisX = new QValueAxis();
    if(m_chartAxisY)delete m_chartAxisY;
    m_chartAxisY = new QValueAxis();
    m_chartStep=0;

    m_chart->addSeries(m_chartSplineCalib);
    m_chart->addSeries(m_chartSplineValue);
    m_chart->addSeries(m_chartSplineToleranceMax);
    m_chart->addSeries(m_chartSplineToleranceMin);

    m_chart->addAxis(m_chartAxisX,Qt::AlignBottom);
    m_chart->addAxis(m_chartAxisY,Qt::AlignLeft);

    m_chartSplineCalib->attachAxis(m_chartAxisX);
    m_chartSplineCalib->attachAxis(m_chartAxisY);

    m_chartSplineValue->attachAxis(m_chartAxisX);
    m_chartSplineValue->attachAxis(m_chartAxisY);

    m_chartSplineToleranceMax->attachAxis(m_chartAxisX);
    m_chartSplineToleranceMax->attachAxis(m_chartAxisY);

    m_chartSplineToleranceMin->attachAxis(m_chartAxisX);
    m_chartSplineToleranceMin->attachAxis(m_chartAxisY);


    m_chartAxisX->setTickCount(m_axisX_TickCount);
    m_chartAxisX->setRange(0, m_axisX_Range);
    m_chartAxisX->setLabelsBrush(QColor("#000000"));
    m_chartAxisX->setLabelFormat("%u");
    //m_axisX->setTitleText("giây");
   // m_axisX->setTitleFont(QFont("Arial", 8));

    m_chartAxisY->setTickCount(m_axisY_TickCount);
    m_chartAxisY->setRange(m_axisY_Range_Min, m_axisY_Range_Max);
    m_chartAxisY->setLabelFormat("%.1f");
    m_chartAxisY->setLabelsBrush(QColor("#000000"));
   //m_axisY->setTitleText("(*C)");
   // m_splineChart->setTitle(m_device.name());
   // m_splineChart->setTitleFont(QFont("Arial", 10, QFont::Bold));
    m_chart->legend()->hide();
    //m_chart->setAnimationOptions(QChart::AllAnimations);
    m_chart->setBackgroundBrush(QColor("#ffffff"));
    m_chart->setBackgroundPen(QColor(Qt::cyan));
    if(m_chartView)delete m_chartView;
    m_chartView = new QChartView(m_chart);
    //m_chartView->setRenderHint(QPainter::Antialiasing);
    if(m_chartGridLayout)delete m_chartGridLayout;
    m_chartGridLayout = new QGridLayout(ui->frame_Chart);
    m_chartGridLayout->addWidget(m_chartView,0,0);
}



/////////////////////////////////////////////////////////////////////////////////////////////////Function for Clib...
void VDeviceCalibration::setValueCalib(PointCalib calib, double x, double y)
{
    switch (calib) {
    case ZeroPointCalib:
        m_valueCalib_X1 = 0;
        m_valueCalib_Y1 = 0;
        m_valueCalib_X2 = 0;
        m_valueCalib_Y2 = 0;
        m_valueCalib_X3 = 0;
        m_valueCalib_Y3 = 0;
        break;
    case OnePointCalib:
        m_valueCalib_X1 = x;
        m_valueCalib_Y1 = y;
        break;
    case TwoPointCalib:
        m_valueCalib_X2 = x;
        m_valueCalib_Y2 = y;
        break;
    case ThreePointCalib:
        m_valueCalib_X3 = x;
        m_valueCalib_Y3 = y;
        break;

    }
}
QVector<quint16> VDeviceCalibration::valueCalib(int res)
{
    QVector<quint16> values;
    switch (m_pointCalib) {
    case ZeroPointCalib:
        values.fill(0,12);
        break;
    case OnePointCalib:
        values.resize(4);
        values[0] = (VDevice::encode(m_valueCalib_X1,res)>>16)&0xFFFF;
        values[1] = VDevice::encode(m_valueCalib_X1,res)&0xFFFF;
        values[2] = (VDevice::encode(m_valueCalib_Y1,res)>>16)&0xFFFF;
        values[3] = VDevice::encode(m_valueCalib_Y1,res)&0xFFFF;
            break;
    case TwoPointCalib:
        values.resize(4);
        values[0] = (VDevice::encode(m_valueCalib_X2,res)>>16)&0xFFFF;
        values[1] = VDevice::encode(m_valueCalib_X2,res)&0xFFFF;
        values[2] = (VDevice::encode(m_valueCalib_Y2,res)>>16)&0xFFFF;
        values[3] = VDevice::encode(m_valueCalib_Y2,res)&0xFFFF;
            break;
    case ThreePointCalib:
        values.resize(4);
        values[0] = (VDevice::encode(m_valueCalib_X3,res)>>16)&0xFFFF;
        values[1] = VDevice::encode(m_valueCalib_X3,res)&0xFFFF;
        values[2] = (VDevice::encode(m_valueCalib_Y3,res)>>16)&0xFFFF;
        values[3] = VDevice::encode(m_valueCalib_Y3,res)&0xFFFF;
            break;

    }
    return  values;
}

void VDeviceCalibration::setResolution(int res)
{
    m_resolution = res;
    switch(m_resolution){
    case 0:m_chartAxisY->setLabelFormat("%.0f");
        break;
    case 1:m_chartAxisY->setLabelFormat("%.1f");
        break;
    case 2:m_chartAxisY->setLabelFormat("%.2f");
        break;
    case 3:m_chartAxisY->setLabelFormat("%.3f");
        break;
    case 4:m_chartAxisY->setLabelFormat("%.4f");
        break;
    case 5:m_chartAxisY->setLabelFormat("%.5f");
        break;
    }
}

void VDeviceCalibration::setConnectStatus(bool status)
{
    if(status){
        m_sensorStatus = true;
        m_sensorConnectCheck=0;
    }
    else{
        //m_sensorConnectRetries = 1000/m_sampleTime;
        //if(m_sensorConnectRetries<1)m_sensorConnectRetries=1;
        if(m_sensorConnectCheck++>m_sensorConnectRetries){
            if(m_calibStatus!=CalibrationStatus::Calib_default){
              m_calibStatus = CalibrationStatus::Calib_Error_Connect;
            }
        }
        if(m_calibStatus==CalibrationStatus::Calib_Writing||m_calibStatus==CalibrationStatus::Calib_WriteData){
          m_calibStatus = CalibrationStatus::Calib_Error_Connect;
        }
    }
}

void VDeviceCalibration::setCalibTime(int time)
{
    ui->spinBox_TimeCalib->setValue(time);
}

void VDeviceCalibration::setSampleNumber(int num)
{
    ui->spinBox_SampleNumber->setValue(num);
}

void VDeviceCalibration::setTolerance(double tolerance)
{
    ui->lineEdit_ToleranceCalib->setText(QString::number(tolerance));
}

void VDeviceCalibration::setValueCalib_X1(double value)
{
    m_valueCalib_X1 = value;
}

void VDeviceCalibration::setValueCalib_Y1(double value)
{
    m_valueCalib_Y1 = value;
    ui->lineEdit_Value_Y1->setText(QString::number(m_valueCalib_Y1));
}

void VDeviceCalibration::setValueCalib_X2(double value)
{
    m_valueCalib_X2 = value;
}

void VDeviceCalibration::setValueCalib_Y2(double value)
{
    m_valueCalib_Y2 = value;
}

void VDeviceCalibration::setValueCalib_X3(double value)
{
    m_valueCalib_X3 = value;
}

void VDeviceCalibration::setValueCalib_Y3(double value)
{
    m_valueCalib_Y3 = value;
}

void VDeviceCalibration::setUnit(QString unit)
{
 m_unit = unit;
 ui->label_Value_Unit->setText(m_unit);
}




void VDeviceCalibration::setCalibrating(double valueCalib, double valueRaw)
{
    //Check calib
    m_valueCalib = valueCalib;
    m_valueRaw = valueRaw;
}

void VDeviceCalibration::calibSampling(double val)
{
        if(!m_chartSplineValue)return;
        double _valueCalib_Y;
        //calculate SUM
        m_Value_Sum += val;
        m_Value_Count++;

        switch (m_calibrating) {
        case ZeroPointCalib:
            _valueCalib_Y = m_Value_Sum/m_Value_Count;
            ui->label_delta->setText(QString::number(1));
            break;
        case OnePointCalib:
            //calculate Avg
            m_valueCalib_X1 = m_Value_Sum/m_Value_Count;
            //calculator calib raw accoding x and y
            m_valueCalib_Raw = (val* m_valueCalib_Y1)/m_valueCalib_X1;
            _valueCalib_Y = m_valueCalib_Y1;
            ui->label_delta->setText(QString::number(m_valueCalib_Y1/m_valueCalib_X1));
            break;
        case TwoPointCalib:
            //calculate Avg
            m_valueCalib_X2 = m_Value_Sum/m_Value_Count;
            //calculator calib raw accoding x and y
            m_valueCalib_Raw = (val* m_valueCalib_Y2)/m_valueCalib_X2;
            _valueCalib_Y = m_valueCalib_Y2;
            ui->label_delta->setText(QString::number(m_valueCalib_Y2/m_valueCalib_X2));
            break;
        case ThreePointCalib:
            //calculate Avg
            m_valueCalib_X3 = m_Value_Sum/m_Value_Count;
            //calculator calib raw accoding x and y
            m_valueCalib_Raw = (val* m_valueCalib_Y3)/m_valueCalib_X3;
            _valueCalib_Y = m_valueCalib_Y3;
            ui->label_delta->setText(QString::number(m_valueCalib_Y3/m_valueCalib_X3));
            break;
        }

        //calculate Max
        if(m_Value_Max<m_valueCalib_Raw)m_Value_Max=m_valueCalib_Raw;
        //calculate Min
        if(m_Value_Min>m_valueCalib_Raw)m_Value_Min=m_valueCalib_Raw;


        //Check Tolerance
        double _toleranceError = _valueCalib_Y*(m_toleranceMeasure/100);
        if((m_valueCalib_Raw>_valueCalib_Y+_toleranceError)||(m_valueCalib_Raw<_valueCalib_Y-_toleranceError)){
                //calib is error tolerance
                m_calibStatus=CalibrationStatus::Calib_Error_Tolerance;
        }
        //Display parameters
        ui->lcdNumber_Value->display(m_valueCalib_Raw);
        ui->label_ValueMax->setNum(m_Value_Max);
        ui->label_ValueMin->setNum(m_Value_Min);
        ui->label_ValueAvg->setText(QString::number(m_valueCalib_Raw));
        ui->label_sampleCounter->setNum(m_chartSplineValue->count());
        //graph
        m_chartSplineValue->append(m_chartSplineValue->count(),m_valueCalib_Raw);
        if(m_valueCalib_Raw > m_chartAxisY->max()+ m_toleranceMeasure)m_chartAxisY->setMax(m_chartAxisY->max()+(m_toleranceMeasure*2));
        if(m_valueCalib_Raw < m_chartAxisY->min()- m_toleranceMeasure)m_chartAxisY->setMin(m_chartAxisY->max()-(m_toleranceMeasure*2));
        if(m_chartSplineValue->count()>=m_chartAxisX->max()){
            m_calibStatus = Calib_WriteData;
            m_chartSplineValue->clear();
           // this->chartInit();
            m_Value_Min = 99999999;
            m_Value_Max = -99999999;
            m_Value_Sum = 0;
            m_Value_Count = 0;
            this->calibCanculateRefresh();
        }
}

void VDeviceCalibration::calibCanculateRefresh()
{
    double _valueCalib_Y=0;
    switch(m_pointCalib){
    case ZeroPointCalib:
        break;
    case OnePointCalib:_valueCalib_Y=m_valueCalib_Y1;
        break;
    case TwoPointCalib:_valueCalib_Y=m_valueCalib_Y2;
        break;
    case ThreePointCalib:_valueCalib_Y=m_valueCalib_Y3;
        break;
    }
//cal sampleTime
m_sampleTime = (m_calibTime*1000)/m_sampleNumber;
m_pollTimer->setInterval(m_sampleTime);
//Refress chart
double _toleranceError = _valueCalib_Y*(m_toleranceMeasure/100);
m_chartAxisX->setMax(m_sampleNumber);
m_chartAxisY->setRange(_valueCalib_Y-(_toleranceError*2),_valueCalib_Y+(_toleranceError*2));
//Set line Calib
if(m_chartSplineCalib){
    m_chartSplineCalib->clear();
    m_chartSplineCalib->append(0,_valueCalib_Y);
    m_chartSplineCalib->append(m_sampleNumber,_valueCalib_Y);
    }
//Set line Tolerance
if(m_chartSplineToleranceMax){
    m_chartSplineToleranceMax->clear();
    m_chartSplineToleranceMax->append(0,_valueCalib_Y+_toleranceError);
    m_chartSplineToleranceMax->append(m_sampleNumber,_valueCalib_Y+_toleranceError);
    }
if(m_chartSplineToleranceMin){
    m_chartSplineToleranceMin->clear();
    m_chartSplineToleranceMin->append(0,_valueCalib_Y-_toleranceError);
    m_chartSplineToleranceMin->append(m_sampleNumber,_valueCalib_Y-_toleranceError);
}
}

void VDeviceCalibration::on_pollTimer()
{
    m_pollTimer->stop();
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowIcon(this->windowIcon());
    switch(m_calibStatus){
    case Calib_default:
        m_chartSplineValue->clear();
        m_Value_Min = 99999999;
        m_Value_Max = -99999999;
        m_Value_Sum = 0;
        m_Value_Count = 0;
        m_writeDataTimeOut=0;
        ui->lcdNumber_Value->display(m_valueCalib);
        if(m_pointCalib==OnePointCalib) ui->label_calibStatus->setText("Hiệu chuân điểm 1.");
        if(m_pointCalib==TwoPointCalib) ui->label_calibStatus->setText("Hiệu chuân điểm 2.");
        if(m_pointCalib==ThreePointCalib) ui->label_calibStatus->setText("Hiệu chuân điểm 3.");
        ui->pushButton_Stop->setEnabled(false);
        break;
    case Calib_Sampling_OnePoint:
        this->calibSampling(m_valueRaw);
        ui->label_calibStatus->setText("Đang lấy mẫu dữ liệu (X1,Y1)...");
        break;
    case Calib_Sampling_TwoPoint:
        this->calibSampling(m_valueRaw);
        ui->label_calibStatus->setText("Đang lấy mẫu dữ liệu (X2,Y2)...");
        break;
    case Calib_Sampling_ThreePoint:
        this->calibSampling(m_valueRaw);
        ui->label_calibStatus->setText("Đang lấy mẫu dữ liệu (X2,Y2)...");
        break;
    case Calib_WriteData:
        ui->pushButton_Stop->setEnabled(false);
        ui->label_calibStatus->setText("Đang ghi dữ liệu ...");
        m_writeDataTimeOut=0;
        break;
    case Calib_Writing:
        m_writeDataTimeOut++;
        break;
    case Calib_Cancel:
        m_calibStatus = CalibrationStatus::Calib_default;
        ui->label_calibStatus->setText("Đã hủy bỏ quá trình hiệu chuẩn.");
        break;
    case Calib_Finished:
        if(this->calibrating()!=ZeroPointCalib){
            ui->label_calibStatus->setText("Đã hoàn thành quá trình hiệu chuẩn.");
            msg.setText("Quá trình hiệu chuẩn thiết bị đã hoàn thành!");
        }
        else{
            ui->label_calibStatus->setText("Đã xóa dữ liệu hiệu chuẩn trên thiết bị.");
            msg.setText("Quá trình xóa dữ liệu hiệu chuẩn đã hoàn thành!");
        }
        msg.exec();
        ui->pushButton_Calibration->setEnabled(true);
        ui->pushButton_CalibrationRemove->setEnabled(true);
        ui->groupBox_Parameters->setEnabled(true);
        ui->pushButton_Exit->setEnabled(true);
        ui->pushButton_Stop->setEnabled(false);
        m_calibStatus = CalibrationStatus::Calib_default;
        this->on_comboBox_SelectPointCalib_currentIndexChanged(ui->comboBox_SelectPointCalib->currentIndex());
        break;
    case Calib_Error_Tolerance:
        ui->label_calibStatus->setText("Lỗi sai số phép đo!");
        msg.setText("Đã xảy ra lỗi!\n Giá trị đo vượt khỏi khoảng chính xác cho phép!");
        msg.exec();
        ui->pushButton_Calibration->setEnabled(true);
        ui->groupBox_Parameters->setEnabled(true);
        ui->pushButton_Exit->setEnabled(true);
        ui->pushButton_Stop->setEnabled(false);
        m_calibStatus = CalibrationStatus::Calib_default;
        break;
    case Calib_Error_Connect:
        ui->label_calibStatus->setText("Lỗi kết nối!");
        msg.setText("Đã xảy ra lỗi!\n Không thể kết nối được đến thiết bị!");
        msg.exec();
        ui->pushButton_Calibration->setEnabled(true);
        ui->pushButton_CalibrationRemove->setEnabled(true);
        ui->groupBox_Parameters->setEnabled(true);
        ui->pushButton_Exit->setEnabled(true);
        ui->pushButton_Stop->setEnabled(false);
        m_valueCalib = 0;
        m_calibStatus = CalibrationStatus::Calib_default;
        this->setCalibrating(OnePointCalib);
        break;
    }
    if(m_writeDataTimeOut>QVariant(3000/m_sampleTime).toInt()){
        m_calibStatus=Calib_Error_Connect;
        m_writeDataTimeOut=0;
    }
    m_pollTimer->start();
}


VDeviceCalibration::VDeviceCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VDeviceCalibration)
{
    ui->setupUi(this);
    this->chartInit();
    if(m_pollTimer)delete m_pollTimer;
    m_pollTimer = new QTimer();
    connect(m_pollTimer,&QTimer::timeout,this,&VDeviceCalibration::on_pollTimer);
    m_pollTimer->start(m_sampleTime);
    m_pointCalib = OnePointCalib;
}

VDeviceCalibration::~VDeviceCalibration()
{
    delete ui;
}

void VDeviceCalibration::on_spinBox_SampleNumber_valueChanged(int arg1)
{
    m_sampleNumber = arg1;
    if((m_calibTime*1000)/m_sampleNumber < 10)ui->spinBox_SampleNumber->setValue(m_calibTime*100);
    this->calibCanculateRefresh();
}

void VDeviceCalibration::on_spinBox_TimeCalib_valueChanged(int arg1)
{
    m_calibTime = arg1;
    if((m_calibTime*1000)/m_sampleNumber < 10)ui->spinBox_SampleNumber->setValue(m_calibTime*100);
    this->calibCanculateRefresh();
}



void VDeviceCalibration::on_lineEdit_ToleranceCalib_textChanged(const QString &arg1)
{
    bool ok;
    double val;
    val = QString(arg1).toDouble(&ok);
    if(ok){
        if(val<0){
            val*=(-1);
         ui->lineEdit_ToleranceCalib->setText(QString::number(val));
        }
        if(val>0){
            m_toleranceMeasure = val;
            double _info1 =0;
            switch(ui->comboBox_SelectPointCalib->currentIndex())
            {
            case 0:_info1 = (m_valueCalib_Y1*m_toleranceMeasure)/100.0;
                break;
            case 1:_info1 = (m_valueCalib_Y2*m_toleranceMeasure)/100.0;
                break;
            case 2:_info1 = (m_valueCalib_Y3*m_toleranceMeasure)/100.0;
                break;
            }
            if(_info1<0)_info1 *= (-1);
            ui->label_ToleranceInfo1->setText("Sai số = " + QString::number(_info1));
            }
    }
    this->calibCanculateRefresh();
}



void VDeviceCalibration::on_lineEdit_ToleranceCalib_editingFinished()
{
    bool ok;
    double val;
    val = QString(ui->lineEdit_ToleranceCalib->text()).toDouble(&ok);
    if(!ok||val<=0){
    ui->lineEdit_ToleranceCalib->setText(QString::number(m_toleranceMeasure));
    }
    this->calibCanculateRefresh();
}

void VDeviceCalibration::on_pushButton_Exit_clicked()
{
    this->close();
}

void VDeviceCalibration::on_pushButton_Calibration_clicked()
{
    bool ok;
    QMessageBox  error;
    error.setStandardButtons(QMessageBox::Ok);
    error.setWindowTitle(this->windowTitle());
    error.setParent(nullptr);
    error.setIcon(QMessageBox::Warning);
    error.setWindowIcon(this->windowIcon());

    QString(ui->lineEdit_Value_Y1->text()).toDouble(&ok);
    if(!ok){
        error.setText("Lỗi! Giá trị chuẩn Y nhập vào không đúng.");
        error.exec();
        return;
    }
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Khi hiệu chuẩn hoàn thành, giá trị đã lưu trước đó\n "
                "sẽ bị ghi đè giá trị hiệu chuẩn mới.\n "
                "Quá trình hiệu chuẩn sẽ diễn ra liên tục trong thời \n "
                "gian " + QString::number(m_calibTime) +" (giây) và chỉ dừng lại \n "
                "khi: \n"
                "     - Người dùng nhấn \"Hủy bỏ\".\n"
                "     - Giá trị hiệu chuẩn không đáp ứng được  độ chính xác."
                "     - Lỗi kết nối tới thiết bị.\n\n"
                " Bạn có muốn tiếp tục không?");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes) {
         ui->pushButton_Calibration->setEnabled(false);
         ui->groupBox_Parameters->setEnabled(false);
         ui->pushButton_Exit->setEnabled(false);
         ui->pushButton_Stop->setEnabled(true);
         switch(ui->comboBox_SelectPointCalib->currentIndex())
         {
         case 0:
             m_calibrating = OnePointCalib;
             m_calibStatus = CalibrationStatus::Calib_Sampling_OnePoint;
             break;
         case 1:
             m_calibrating = TwoPointCalib;
             m_calibStatus = CalibrationStatus::Calib_Sampling_TwoPoint;
             break;
         case 2:
             m_calibrating = ThreePointCalib;
             m_calibStatus = CalibrationStatus::Calib_Sampling_ThreePoint;
             break;
         }
         this->calibCanculateRefresh();
     }
}

void VDeviceCalibration::on_pushButton_Stop_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( nullptr,"Hiệu chuẩn thiết bị",
                                                                "Chấp nhận hủy bỏ sẽ dừng toàn bộ quá trình hiệu chuẩn! \n"
                                                                 "Bạn có muốn thực hiện việc hủy bỏ không?",
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                 QMessageBox::Yes);
     if (resBtn == QMessageBox::Yes) {
         ui->pushButton_Calibration->setEnabled(true);
         ui->groupBox_Parameters->setEnabled(true);
         ui->pushButton_Exit->setEnabled(true);
         ui->pushButton_Stop->setEnabled(false);
         m_pointCalib = OnePointCalib;
         this->calibCanculateRefresh();
         m_calibStatus = CalibrationStatus::Calib_Cancel;
     }
}

void VDeviceCalibration::on_comboBox_SelectPointCalib_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        m_pointCalib = OnePointCalib;
        ui->lineEdit_Value_Y1->setText(QString::number(m_valueCalib_Y1));
        break;
    case 1:
        m_pointCalib = TwoPointCalib;
        ui->lineEdit_Value_Y1->setText(QString::number(m_valueCalib_Y2));
        break;
    case 2:
        m_pointCalib = ThreePointCalib;
        ui->lineEdit_Value_Y1->setText(QString::number(m_valueCalib_Y3));
        break;
    }
    this->calibCanculateRefresh();
}

void VDeviceCalibration::on_lineEdit_Value_Y1_textChanged(const QString &arg1)
{
    bool ok;
    double val;
    val = QString(arg1).toDouble(&ok);
    if(ok){
        double _info = (val*m_toleranceMeasure)/100.0;
        switch(ui->comboBox_SelectPointCalib->currentIndex())
        {
        case 0:m_valueCalib_Y1=val;
            break;
        case 1:m_valueCalib_Y2=val;
            break;
        case 2:m_valueCalib_Y3=val;
            break;
        }
        if(_info<0)_info *= (-1);
        if(m_toleranceMeasure>0)ui->label_ToleranceInfo1->setText("Sai số = " + QString::number(_info));
        ui->label_calib_info1->setStyleSheet("color: rgb(56, 170, 170);");
        ui->lineEdit_Value_Y1->setStyleSheet("color: rgb(56, 170, 170);");
        ui->label_Value_Unit->setStyleSheet("color: rgb(56, 170, 170);");
    }
    else {
        ui->label_calib_info1->setStyleSheet("color: rgb(255, 0, 0);");
        ui->lineEdit_Value_Y1->setStyleSheet("color: rgb(255, 0, 0);");
        ui->label_Value_Unit->setStyleSheet("color: rgb(255, 0, 0);");
    }
    this->calibCanculateRefresh();
}

void VDeviceCalibration::on_pushButton_CalibrationRemove_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Nếu nhấn \"Yes\" toàn bộ dữ liệu về hiệu chuẩn\n "
                "sẽ bị xóa khỏi bộ nhớ. Cảm biến sẽ phải được hiệu \n "
                "chuẩn lại trước khi sử dụng. \n "
                "Hãy nhấn \"No\" hoặc liên hệ với nhà cung cấp nếu\n "
                "bạn không chắc chắn có thể tự làm toàn bộ quy trình \n"
                "hiệu chuẩn cảm biến.\n\n"
                " Bạn có muốn tiếp tục không?");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
     if (msg.result() == QMessageBox::Yes) {
         ui->pushButton_Calibration->setEnabled(false);
         ui->groupBox_Parameters->setEnabled(false);
         ui->pushButton_Exit->setEnabled(false);
         ui->pushButton_Stop->setEnabled(true);
         m_pointCalib = ZeroPointCalib;
         m_calibStatus = CalibrationStatus::Calib_WriteData;
     }
}
