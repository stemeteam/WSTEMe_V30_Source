#ifndef MODULE_MOD1103_CONDITION_H
#define MODULE_MOD1103_CONDITION_H

#include <QMainWindow>
#include <esensor/edev_mod1103.h>
#include <QSettings>

namespace Ui {
class Module_MOD1103_Condition;
}

class Module_MOD1103_Condition : public QMainWindow
{
    Q_OBJECT

public:
    explicit Module_MOD1103_Condition(QWidget *parent = nullptr);
    ~Module_MOD1103_Condition();

    struct ConditionUnit{
        EDev_Mod1103::ESlave start_car = EDev_Mod1103::ESlave::CAR_01;
        EDev_Mod1103::CarCondition start_condition = EDev_Mod1103::CarCondition::CCD_default;
        double start_value=0;
        EDev_Mod1103::ESlave stop_car = EDev_Mod1103::ESlave::CAR_01;
        EDev_Mod1103::CarCondition stop_condition = EDev_Mod1103::CarCondition::CCD_default;
        double stop_value=0;
    };
    struct ECarSave{
        int unit_s=0;
        int unit_v=0;
        int unit_a=0;
        int unit_t=0;
        int unit_f=0;
        int unit_pin=0;
        int pre_s=0;
        int pre_v=1;
        int pre_a=1;
        int pre_t=3;
        int pre_f=1;
        int pre_pin=2;
        bool vector=true;
        bool reSign=false;
        bool graph_s=false;
        bool graph_v=false;
        bool graph_a=false;
        bool graph_f=false;
        bool filter_set=false;
        bool filter_lpf=false;
        double filter_freq=1;
    };
    struct EUnits{
        QString name="";
        ConditionUnit unit;
        ECarSave car01;
        ECarSave car02;
    };
    //////Car Save
    ECarSave getCarSave(EDev_Mod1103::ESlave slave);

    ///////////////////////////////////////////////////////////
    void setCar(EDev_Mod1103::ESlave slave,EDev_Mod1103::ECar car);
    void setCar(EDev_Mod1103::ECar car01,EDev_Mod1103::ECar car02);
    void setCar(EDev_Mod1103::ECar car01,EDev_Mod1103::ECar car02,bool update);
    void setCar(EDev_Mod1103::ECar car01,EDev_Mod1103::ECar car02,EDev_Mod1103::ConditionProcess process);

    //Set CarSave
    void setCar(ECarSave car01,ECarSave car02);

signals:
    void setCondition(ConditionUnit unit,bool status);
    void setSetting(ECarSave car01,ECarSave car02);
private slots:
    void on_displayTimer();

    //Gui
    void on_pushButton_Cancel_clicked();

    void on_pushButton_Run_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_New_clicked();

    void on_comboBox_Unit_currentIndexChanged(int index);

    void on_comboBox_Condition_Start_currentIndexChanged(int index);

    void on_comboBox_Condition_Stop_currentIndexChanged(int index);

    void on_comboBox_Condition_Start_Car_currentIndexChanged(int index);

    void on_comboBox_Condition_Stop_Car_currentIndexChanged(int index);

    void on_pushButton_Delete_clicked();

private:
    Ui::Module_MOD1103_Condition *ui;

    QTimer  *m_displayTimer=nullptr;
    int m_displayInterval = 10;
    QMessageBox *m_QMessageBox = nullptr;
    QList<EUnits> m_unit;
    ECarSave m_ecar01_save,m_ecar02_save;
    EDev_Mod1103::ECar m_ecar01,m_ecar02;
    EDev_Mod1103::ESlave m_car_stop = EDev_Mod1103::ESlave::CAR_01,m_car_start = EDev_Mod1103::ESlave::CAR_01;
    EDev_Mod1103::CarCondition m_condition_start = EDev_Mod1103::CarCondition::CCD_default,m_condition_stop = EDev_Mod1103::CarCondition::CCD_default;

    EDev_Mod1103::ConditionProcess m_CDP_conditionProcess=EDev_Mod1103::CDP_default;
    //.......................................
    bool m_blinkStatus=false;
    int  m_blinkTime = 500;//1000mSecond
    int  m_blinkCount = 0;
    bool m_processValid = true;
    int  m_processTimeOut = 0;
    int  m_processTimeoutMax = 10000;//10000 mSecond = 10 Second



    QList<EUnits> loadUnits();
    void saveUnits(QList<EUnits> unit);
    void setUnit(EUnits unit);
    EUnits getUnit();
    void updateConditionUnit();
    void updateConditionData();
    void setConditionDisplay(EDev_Mod1103::ESlave slave,EDev_Mod1103::ECar car,EDev_Mod1103::CarCondition condition);
    void setProcessDefault();
};

#endif // MODULE_MOD1103_CONDITION_H
