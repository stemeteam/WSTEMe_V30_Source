#ifndef VDEVICECALIBRATION_H
#define VDEVICECALIBRATION_H
//for system
#include <QWidget>
#include "QMessageBox"
#include <QTimer>

//for char
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
//for use
#include <vdevice/vdevice.h>


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class VDeviceCalibration;
}

class VDeviceCalibration : public QWidget
{
    Q_OBJECT
    /////////////////////////////////////////////////////////////////////////////////////////////////Function for sensor...
public:
    enum OnePointCalibrationSteps{
        OnePC_default,
        OnePC_Steps
    }m_onePoint_Steps = OnePC_default;
    enum TwoPointCalibrationSteps{
        TwoPC_default,
        TwoPC_Steps
    }m_twoPoint_Steps = TwoPC_default;
    enum ThreePointCalibrationSteps{
        ThreePC_default,
        ThreePC_Steps
    }m_threePoint_Steps = ThreePC_default;

    enum PointCalib{
        ZeroPointCalib,
        OnePointCalib,
        TwoPointCalib,
        ThreePointCalib
    }m_pointCalib = OnePointCalib;

    enum CalibrationStatus{
        Calib_default,
        Calib_Sampling_OnePoint,
        Calib_Sampling_TwoPoint,
        Calib_Sampling_ThreePoint,
        Calib_WriteData,
        Calib_Writing,
        Calib_Finished,
        Calib_Error_Tolerance,
        Calib_Cancel,
        Calib_Error_Connect
    }m_calibStatus = Calib_default;


    //Properties get........
    inline QString unit(){
        return m_unit;
    }
    inline int calibTime(){
        return m_calibTime;
    }
    inline int sampleTime(){
        return m_sampleTime;
    }
    inline int sampleNumber(){
        return m_sampleNumber;
    }
    inline int resolution(){
        return m_resolution;
    }
    inline double tolerance(){
        return m_toleranceMeasure;
    }
    inline double valueCalib_X1(){
        return m_valueCalib_X1;
    }
    inline double valueCalib_Y1(){
        return m_valueCalib_Y1;
    }
    inline double valueCalib_X2(){
        return m_valueCalib_X2;
    }
    inline double valueCalib_Y2(){
        return m_valueCalib_Y2;
    }
    inline double valueCalib_X3(){
        return m_valueCalib_X3;
    }
    inline double valueCalib_Y3(){
        return m_valueCalib_Y3;
    }
    inline CalibrationStatus calibStatus(){
        return m_calibStatus;
    }
    inline void setCalibStatus(CalibrationStatus status){
        m_calibStatus = status;
    }
    inline PointCalib pointCalib(){
        return m_pointCalib;
    }
    inline void setPointCalib(PointCalib point){
        m_pointCalib = point;
    }
    inline PointCalib calibrating(){
        return m_calibrating;
    }
    inline void setCalibrating(PointCalib point){
        m_calibrating = point;
    }
    void setResolution(int res);

    bool connectStatus(){
        return m_sensorStatus;
    }




    //Properties set........
    void setConnectStatus(bool status);

    void setCalibTime(int time);
    void setSampleNumber(int num);
    void setTolerance(double tolerance);
    void setValueCalib_X1(double value);
    void setValueCalib_Y1(double value);
    void setValueCalib_X2(double value);
    void setValueCalib_Y2(double value);
    void setValueCalib_X3(double value);
    void setValueCalib_Y3(double value);
    void setUnit(QString unit);

    //public function
    void setValueCalib(PointCalib calib,double x,double y);
    QVector<quint16> valueCalib(int res);
    void setCalibrating(double valueCalib,double valueRaw);

private:

    double m_Value_Min = 99999999;
    double m_Value_Max = -99999999;
    double m_Value_Sum = 0;
    int m_Value_Count = 0;
    PointCalib m_calibrating = OnePointCalib;

    QString m_unit = "";
    int m_calibTime = 10;   //second
    int m_sampleTime = 100; //miniSecond
    int m_sampleNumber = 10;

    int m_sensorConnectRetries = 2;
    int m_sensorConnectCheck = 0;
    bool m_sensorStatus = false;


    double m_toleranceMeasure = 0.1;
    double m_valueCalib_X1 = 0;
    double m_valueCalib_Y1 = 0;
    double m_valueCalib_X2 = 0;
    double m_valueCalib_Y2 = 0;
    double m_valueCalib_X3 = 0;
    double m_valueCalib_Y3 = 0;
    double m_valueCalib_Raw = 0;
    int m_resolution = 3;

    void calibSampling(double val);
    void calibCanculateRefresh();
    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
   private slots:
        void on_pollTimer();
        void on_spinBox_SampleNumber_valueChanged(int arg1);

        void on_spinBox_TimeCalib_valueChanged(int arg1);

        void on_lineEdit_ToleranceCalib_textChanged(const QString &arg1);

        void on_lineEdit_ToleranceCalib_editingFinished();

        void on_pushButton_Exit_clicked();

        void on_pushButton_Calibration_clicked();

        void on_pushButton_Stop_clicked();

        void on_comboBox_SelectPointCalib_currentIndexChanged(int index);

        void on_lineEdit_Value_Y1_textChanged(const QString &arg1);

        void on_pushButton_CalibrationRemove_clicked();

private:
        QTimer  *m_pollTimer=nullptr;

        VDevice m_device;


        QGridLayout     *m_chartGridLayout=nullptr;
        QChartView      *m_chartView=nullptr;
        QChart          *m_chart=nullptr;
        QValueAxis      *m_chartAxisX=nullptr;
        QValueAxis      *m_chartAxisY=nullptr;
        quint16         m_chartStep;
        QVector<qreal>  m_chartValueArray;

        QSplineSeries   *m_chartSplineValue=nullptr;
        QSplineSeries   *m_chartSplineCalib=nullptr;
        QSplineSeries   *m_chartSplineToleranceMax=nullptr;
        QSplineSeries   *m_chartSplineToleranceMin=nullptr;

        int             m_chartListValue_Fill=0;
        int             m_chartListValue_Max = 200;
        int             m_chartListValue_Count=0;

        int m_axisX_TickCount = 10;
        int m_axisX_Range = 10;
        int m_axisY_TickCount = 5;
        qreal m_axisY_Range_Max = 1;
        qreal m_axisY_Range_Min = 0;

        int m_chartTimerInterval = 50;
        int m_chartTimerScan = 50;



        void chartInit();
        void chartInit(QPen _pen);
        void chartClear(bool init);




public:
    explicit VDeviceCalibration(QWidget *parent = nullptr);
    ~VDeviceCalibration();

private:
    Ui::VDeviceCalibration *ui;

    double m_valueCalib=0;
    double m_valueRaw = 0;
    int m_writeDataTimeOut = 0;
};

#endif // VDEVICECALIBRATION_H
