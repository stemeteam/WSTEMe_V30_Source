#ifndef MODULE_MOD1103_H
#define MODULE_MOD1103_H

#include <QMainWindow>
//system
#include <QtMath>
#include "QMessageBox"
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>
#include <QWidget>
#include <QModbusDataUnit>
#include <QBuffer>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <esensor/edev_mod1103.h>
#include <vmodule/module_mod1103_condition.h>
#include <esensor/esensors.h>
#include <vlogin/vuser.h>
#include <vchart/vchart_zoom.h>
#include <esensor/echarts.h>
#include <vroot/vdevicecalibration.h>
#include <vfile/vfile.h>
#include <efilter/elowpassfilter.h>
#include <esensor/echartgesture.h>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

namespace Ui {
class Module_MOD1103;
}

class Module_MOD1103 : public QMainWindow
{
    Q_OBJECT

        /////////////////////////////////////////////////////////////////////////////////////////////////Function for Sensor...
public:
        void setDeviceWidget(VDevice dev,VUser user);
        void sensorCalibration(double valueCalib,double valueRaw);
        void setInfoCalib();

private:
        enum SensorWriteStatus {
            SWS_default=0,
            SWS_SetZero,
            SWS_Calib,
            SWS_SetCommand,
        }m_SWS_Status = SWS_default;

        enum CarMeasureMode{
            CMM_default,
            CMM_continuous,
            CMM_condition
        }m_CMM_carMeasureMode=CMM_default;

        enum ProcessStatus{
            PRS_play,
            PRS_pause,
            PRS_stop
        }m_PRS_processStatus=PRS_stop;



        int m_modbusSampleTime = 180;
     //   ESensors *m_esensor=nullptr;
        EDev_Mod1103 *m_edev_mod1103=nullptr;

        VDevice m_deviceInformation;
        QMessageBox *m_QMessageBox = nullptr;
        VDeviceCalibration *m_deviceCalibration = nullptr;

        void sensorWriteReport(bool status);
        void sensorWriteMultipleREG(quint16 address,QVector<quint16> values);
        void sensorWriteSingleREG(quint16 reg, quint16 value);

/////////////////////////////////////////////////////////////////////////////////////////////////Function for Display....
private slots:
        void on_displayTimer();
        void on_setCondition(Module_MOD1103_Condition::ConditionUnit unit, bool status);
        void on_setSetting(Module_MOD1103_Condition::ECarSave car01,Module_MOD1103_Condition::ECarSave car02);

        void on_pushButton_SetCommandCAR1_clicked();

        void on_pushButton_SetCommandCAR2_clicked();

        void on_pushButton_SetConfigChart_clicked();

        void on_pushButton_ClearChart_clicked();

        void on_radioButton_Accumulation_toggled(bool checked);

        void on_pushButton_ChartStart_clicked();

        void on_pushButton_SetSampleTime_clicked();

        void on_pushButton_SetCalib_S_clicked();

        void on_pushButton_SetCalib_F_clicked();

        void on_pushButton_SetADD_clicked();

        void on_pushButton_SetTS_clicked();

        void on_tabWidget_currentChanged(int index);

        void on_radioButton_CAR01_Calib_toggled(bool checked);

        void on_comboBox_Display_Car_Unit_S1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_V1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_A1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_T1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_F1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_PIN1_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_S2_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_V2_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_A2_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_T2_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_F2_currentIndexChanged(int index);

        void on_comboBox_Display_Car_Unit_PIN2_currentIndexChanged(int index);

        void on_comboBox_SelectExample_currentIndexChanged(int index);

        void on_pushButton_SetZero_Car1_clicked();

        void on_pushButton_Shutdown_Car1_clicked();

        void on_pushButton_SetZero_Car2_clicked();

        void on_pushButton_Shutdown_Car2_clicked();

        void on_checkBox_Display_Car_Vector2_toggled(bool checked);

        void on_checkBox_Display_Car_Vector1_toggled(bool checked);

        void on_pushButton_Cancel_clicked();

        void on_pushButton_SaveData_clicked();

        void on_pushButton_OpenData_clicked();

        void on_spinBox_Display_Car_Pre_S1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_V1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_A1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_T1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_F1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_PIN1_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_S2_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_V2_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_A2_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_T2_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_F2_valueChanged(int arg1);

        void on_spinBox_Display_Car_Pre_PIN2_valueChanged(int arg1);

        void on_checkBox_Car01_S_toggled(bool checked);

        void on_checkBox_Car01_V_toggled(bool checked);

        void on_checkBox_Car01_A_toggled(bool checked);

        void on_checkBox_Car01_F_toggled(bool checked);

        void on_checkBox_Car02_S_toggled(bool checked);

        void on_checkBox_Car02_V_toggled(bool checked);

        void on_checkBox_Car02_A_toggled(bool checked);

        void on_checkBox_Car02_F_toggled(bool checked);

        void on_checkBox_Filter_toggled(bool checked);

        void on_pushButton_Filter_Setup_clicked();

        void on_radioButton_Filter_LPF_toggled(bool checked);

        void on_pushButton_TrackLine_Default_clicked();

        void on_pushButton_TrackLine_Tooltip_clicked();

        void on_pushButton_TrackLine_Yax_clicked();

        void on_comboBox_SelectMode_currentIndexChanged(int index);

        void on_pushButton_SampleFreq_clicked();

        void on_tabWidget_4_currentChanged(int index);

        void on_checkBox_Display_Car_reSign1_toggled(bool checked);

        void on_checkBox_Display_Car_reSign2_toggled(bool checked);

        void on_radioButton_Graph_SPline_toggled(bool checked);

private:
        QTimer  *m_displayTimer=nullptr;
        bool    m_displayToggle=false;
        int     m_displayInterval = 10;

        void displayPoll();


/////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
private:
        struct EGraphIndex{
            int index_s=0;
            int index_v=0;
            int index_a=0;
            int index_f=0;
            int index_t=0;
            }m_graphIndex_01,m_graphIndex_02;
            EGraphIndex m_graphIndex_01_start,m_graphIndex_01_stop;
            EGraphIndex m_graphIndex_02_start,m_graphIndex_02_stop;
            qreal m_forceValue =0;
            EDev_Mod1103::ECarLines m_car01_lines,m_car02_lines;
            EDev_Mod1103::ECarSPlines m_car01_splines,m_car02_splines;
            EDev_Mod1103::TypeLine m_typeLine = EDev_Mod1103::TypeLine::typeSpline;

            void chartInit();
            void chartGraph(QPointF vals,int lines);
            void chartGraph(EDev_Mod1103::ECarLines line01,EDev_Mod1103::ECarLines line02);
            void chartGraph(EDev_Mod1103::ECarSPlines line01,EDev_Mod1103::ECarSPlines line02);
            void chartGraphContinous(EDev_Mod1103::ECarLines line01,EDev_Mod1103::ECarLines line02);
            void chartGraphContinous(EDev_Mod1103::ECarSPlines line01,EDev_Mod1103::ECarSPlines line02);
            void setSpline(QSplineSeries *series,int line);
            void setSpline(QLineSeries *series,int line);
            void chartRefresh(bool clear);
            void chartClear(bool data);

            void setTrackLine(EChartGesture::ETrackLine track);


protected:
        void closeEvent(QCloseEvent *event);

public:
    explicit Module_MOD1103(QWidget *parent = nullptr);
    ~Module_MOD1103();

private:
    Ui::Module_MOD1103 *ui;
    Module_MOD1103_Condition *m_mod1103_Condition = nullptr;

    quint32 m_system_count=0;
    bool    m_deviceModbusConnect=false;
    VUser m_user;
    QString m_msgInfo = "";

    //Car
    EDev_Mod1103::ECar m_eCar_01,m_eCar_02;
    bool m_eCar_01_connecting=false,m_eCar_02_connecting=false;
    EDev_Mod1103::CarMode m_CMD_carMode = EDev_Mod1103::CMD_condition;

    //condition
    Module_MOD1103_Condition::ConditionUnit m_conditionUnit;
    EDev_Mod1103::ConditionProcess m_CDP_conditionProcess=EDev_Mod1103::CDP_default;

    void setOpenFile(bool status);
    bool    m_isOpenFile = false;

    //getLocalForWidget
    int getLocal_X(QRect rect,int width){
        return ((rect.x() + (rect.width()/2)) - (width/2));
    }
    int getLocal_Y(QRect rect,int height){
        int offset = 44;
    return ((rect.y() + (rect.height()/2)) - (height/2))+offset;
    }
    double m_Car01_Zero_s=0;
    double m_Car01_Zero_f=0;
    double m_Car02_Zero_s=0;
    double m_Car02_Zero_f=0;
    EDev_Mod1103::ECar m_Car01_Condition,m_Car02_Condition;

    //Command Check
    bool m_commandCheckStatus=false;
    int m_commandCheckCount = 0;
    EDev_Mod1103::ESlave m_commandCheckCar = EDev_Mod1103::ESlave::CAR_01;

    //Save setting
    Module_MOD1103_Condition::ECarSave m_ecar01_Save,m_ecar02_Save;
    void getCarSave();
    void setCarSave();
    //set Command
    void commandCheck();


    //Function...............................
    void carConnectStatus(EDev_Mod1103::ESlave car,bool status);
    void updateTabParameter();
    void updateTabSetup();
    void updateTabDisplay();
    void measurePoll();
    bool checkCarStart();
    bool checkCarStop();
    void measureByCondition();
    bool checkConditionStart();
    bool checkConditionStop();
    bool checkHigher(double x1,double x2,double y,EDev_Mod1103::ESlave car);
    bool checkLower(double x1,double x2,double y,EDev_Mod1103::ESlave car);
    bool updateSPlineDataCAR01();
    bool updateSPlineDataCAR02();
    bool updateLineDataCAR01();
    bool updateLineDataCAR02();
    bool updateConditionData(EDev_Mod1103::ESlave car);
    int  syncSPlines(double time,int place);
    int  syncLines(double time,int place);
    void updateSPlines();
    void updateLines();
    void zeroConditionParameter();
    void setProcess(ProcessStatus status);

    double timeTestLast01=0,timeTestLast02=0;
};

#endif // MODULE_MOD1103_H
