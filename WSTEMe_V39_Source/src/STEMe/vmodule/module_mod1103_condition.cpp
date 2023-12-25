#include "module_mod1103_condition.h"
#include "ui_module_mod1103_condition.h"

Module_MOD1103_Condition::Module_MOD1103_Condition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Module_MOD1103_Condition)
{
    ui->setupUi(this);
    QFont font("PibotoLt", 10, QFont::Bold);
    font.setItalic(true);
    ui->comboBox_Unit->lineEdit()->setFont(font);
    //load unit
    m_unit = this->loadUnits();
    if(m_unit.count()<1){
        EUnits unit;
        unit.name = "Đo quãng đường di chuyển của XE-01";
        unit.unit.start_condition = EDev_Mod1103::CarCondition::CCD_V_Higher;
        unit.unit.start_value = 0;
        unit.unit.stop_condition = EDev_Mod1103::CarCondition::CCD_V_Lower;
        unit.unit.stop_value = 1;
        m_unit.append(unit);
        this->saveUnits(m_unit);
    }
    for(int i=0;i<m_unit.count();i++){
        ui->comboBox_Unit->addItem(m_unit[i].name);
    }
    this->setUnit(m_unit[0]);

    //Display Timer
     if(m_displayTimer)delete m_displayTimer;
     m_displayTimer = new QTimer();
     connect(m_displayTimer,&QTimer::timeout,this,&Module_MOD1103_Condition::on_displayTimer);
     m_displayTimer->start(m_displayInterval);
}

Module_MOD1103_Condition::~Module_MOD1103_Condition()
{
    delete ui;
}

Module_MOD1103_Condition::ECarSave Module_MOD1103_Condition::getCarSave(EDev_Mod1103::ESlave slave)
{
    switch(slave){
    case EDev_Mod1103::ESlave::CAR_01:
        //m_ecar01_save = m_unit[ui->comboBox_Unit->currentIndex()].car01;
        return m_ecar01_save;
    case EDev_Mod1103::ESlave::CAR_02:
        //m_ecar02_save = m_unit[ui->comboBox_Unit->currentIndex()].car02;
        return m_ecar02_save;
    case EDev_Mod1103::ESlave::CAR_ALL:
        //m_ecar01_save = m_unit[ui->comboBox_Unit->currentIndex()].car01;
        return m_ecar01_save;
    }
    //m_ecar01_save = m_unit[ui->comboBox_Unit->currentIndex()].car01;
    return m_ecar01_save;
}

void Module_MOD1103_Condition::setCar(EDev_Mod1103::ESlave slave, EDev_Mod1103::ECar car)
{
    switch(slave){
    case EDev_Mod1103::ESlave::CAR_01: m_ecar01 = car;
        break;
    case EDev_Mod1103::ESlave::CAR_02: m_ecar02 = car;
        break;
    case EDev_Mod1103::ESlave::CAR_ALL:
        m_ecar01 = car;
        m_ecar02 = car;
        break;
    }
}

void Module_MOD1103_Condition::setCar(EDev_Mod1103::ECar car01, EDev_Mod1103::ECar car02)
{
    this->setCar(EDev_Mod1103::ESlave::CAR_01,car01);
    this->setCar(EDev_Mod1103::ESlave::CAR_02,car02);
}

void Module_MOD1103_Condition::setCar(EDev_Mod1103::ECar car01, EDev_Mod1103::ECar car02, bool update)
{
    this->setCar(car01,car02);
    this->updateConditionUnit();
    if(update){
    //Update data here
    }
}

void Module_MOD1103_Condition::setCar(EDev_Mod1103::ECar car01, EDev_Mod1103::ECar car02, EDev_Mod1103::ConditionProcess process)
{
    this->setCar(car01,car02,false);
    m_CDP_conditionProcess = process;
    this->updateConditionData();
}

void Module_MOD1103_Condition::setCar(Module_MOD1103_Condition::ECarSave car01, Module_MOD1103_Condition::ECarSave car02)
{
m_ecar01_save = car01;
m_ecar02_save = car02;
}

void Module_MOD1103_Condition::on_displayTimer()
{
    //Blink
    if(m_blinkCount++>m_blinkTime/m_displayInterval){
        m_blinkCount=0;
        m_blinkStatus = !m_blinkStatus;
    }
    m_processTimeOut++;
    //Update Data
    this->updateConditionData();
}

void Module_MOD1103_Condition::on_pushButton_Cancel_clicked()
{
    emit setCondition(this->getUnit().unit,false);
    this->hide();
}

void Module_MOD1103_Condition::on_pushButton_Run_clicked()
{
    ConditionUnit _unit = this->getUnit().unit;
    if(_unit.start_car==EDev_Mod1103::ESlave::CAR_01||_unit.stop_car==EDev_Mod1103::ESlave::CAR_01){
        if(!m_ecar01.connect){
            if(m_QMessageBox)delete m_QMessageBox;
            m_QMessageBox = new QMessageBox();
            QString str = "Đã có lỗi xảy ra! XE-01 đã ngắt kết nối!";
            m_QMessageBox->setText(str);
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
    }
    if(_unit.start_car==EDev_Mod1103::ESlave::CAR_02||_unit.stop_car==EDev_Mod1103::ESlave::CAR_02){
        if(!m_ecar02.connect){
            if(m_QMessageBox)delete m_QMessageBox;
            m_QMessageBox = new QMessageBox();
            QString str = "Đã có lỗi xảy ra! XE-02 đã ngắt kết nối!";
            m_QMessageBox->setText(str);
            m_QMessageBox->setWindowTitle("Lỗi kết nối");
            m_QMessageBox->setIcon(QMessageBox::Warning);
            m_QMessageBox->show();
            return;
        }
    }
    emit setCondition(_unit,true);
    ui->pushButton_Run->setEnabled(false);
    emit setCondition(this->getUnit().unit,true);
        ui->pushButton_Run->setEnabled(false);
}

QList<Module_MOD1103_Condition::EUnits> Module_MOD1103_Condition::loadUnits()
{
    QList<EUnits> listUnits;
    QSettings settings("ELEVOI","VDAT");
    int size = settings.beginReadArray("mfs0103_units");
    for (int i = 0; i < size; i++) {
        EUnits unit;
        settings.setArrayIndex(i);
        unit.name = settings.value("nameUnit","").toString();
        unit.unit.start_car = EDev_Mod1103::getESlave(settings.value("startCar","0").toInt());
        unit.unit.start_condition = EDev_Mod1103::getCarCondition(settings.value("startCondition","0").toInt());
        unit.unit.start_value = settings.value("startValue","0").toDouble();
        unit.unit.stop_car = EDev_Mod1103::getESlave(settings.value("stopCar","0").toInt());
        unit.unit.stop_condition = EDev_Mod1103::getCarCondition(settings.value("stopCondition","0").toInt());
        unit.unit.stop_value = settings.value("stopValue","0").toDouble();

        //ECar01 save
        unit.car01.unit_s = settings.value("car01_unit_s","0").toInt();
        unit.car01.unit_v = settings.value("car01_unit_v","0").toInt();
        unit.car01.unit_a = settings.value("car01_unit_a","0").toInt();
        unit.car01.unit_t = settings.value("car01_unit_t","0").toInt();
        unit.car01.unit_f = settings.value("car01_unit_f","0").toInt();
        unit.car01.unit_pin = settings.value("car01_unit_pin","0").toInt();

        unit.car01.pre_s = settings.value("car01_pre_s","0").toInt();
        unit.car01.pre_v = settings.value("car01_pre_v","1").toInt();
        unit.car01.pre_a = settings.value("car01_pre_a","1").toInt();
        unit.car01.pre_t = settings.value("car01_pre_t","3").toInt();
        unit.car01.pre_f = settings.value("car01_pre_f","1").toInt();
        unit.car01.pre_pin = settings.value("car01_pre_pin","2").toInt();

        unit.car01.graph_s = settings.value("car01_graph_s","1").toBool();
        unit.car01.graph_v = settings.value("car01_graph_v","0").toBool();
        unit.car01.graph_a = settings.value("car01_graph_a","0").toBool();
        unit.car01.graph_f = settings.value("car01_graph_f","0").toBool();

        unit.car01.vector = settings.value("car01_vector","0").toBool();
        unit.car01.reSign = settings.value("car01_reSign","0").toBool();

        unit.car01.filter_set = settings.value("car01_filter_set","0").toBool();
        unit.car01.filter_lpf = settings.value("car01_filter_lpf","0").toBool();
        unit.car01.filter_freq = settings.value("car01_filter_freq","0").toDouble();

        //ECar02 save
        unit.car02.unit_s = settings.value("car02_unit_s","0").toInt();
        unit.car02.unit_v = settings.value("car02_unit_v","0").toInt();
        unit.car02.unit_a = settings.value("car02_unit_a","0").toInt();
        unit.car02.unit_t = settings.value("car02_unit_t","0").toInt();
        unit.car02.unit_f = settings.value("car02_unit_f","0").toInt();
        unit.car02.unit_pin = settings.value("car02_unit_pin","0").toInt();

        unit.car02.pre_s = settings.value("car02_pre_s","0").toInt();
        unit.car02.pre_v = settings.value("car02_pre_v","1").toInt();
        unit.car02.pre_a = settings.value("car02_pre_a","1").toInt();
        unit.car02.pre_t = settings.value("car02_pre_t","3").toInt();
        unit.car02.pre_f = settings.value("car02_pre_f","1").toInt();
        unit.car02.pre_pin = settings.value("car02_pre_pin","2").toInt();

        unit.car02.graph_s = settings.value("car02_graph_s","0").toBool();
        unit.car02.graph_v = settings.value("car02_graph_v","0").toBool();
        unit.car02.graph_a = settings.value("car02_graph_a","0").toBool();
        unit.car02.graph_f = settings.value("car02_graph_f","0").toBool();

        unit.car02.vector = settings.value("car02_vector","0").toBool();
        unit.car02.reSign = settings.value("car02_reSign","0").toBool();

        listUnits.append(unit);
    }
    settings.endArray();
    return  listUnits;
}

void Module_MOD1103_Condition::saveUnits(QList<Module_MOD1103_Condition::EUnits> unit)
{
    if(unit.count()>0){
        QSettings settings("ELEVOI","VDAT");
        settings.beginWriteArray("mfs0103_units");
        settings.remove("");
        for (int i = 0; i < unit.count(); ++i) {
            settings.setArrayIndex(i);
            settings.setValue("nameUnit", unit[i].name);
            settings.setValue("startCar",EDev_Mod1103::getESlave(unit[i].unit.start_car));
            settings.setValue("startCondition",EDev_Mod1103::getCarCondition(unit[i].unit.start_condition));
            settings.setValue("startValue",unit[i].unit.start_value);
            settings.setValue("stopCar",EDev_Mod1103::getESlave(unit[i].unit.stop_car));
            settings.setValue("stopCondition",EDev_Mod1103::getCarCondition(unit[i].unit.stop_condition));
            settings.setValue("stopValue",unit[i].unit.stop_value);

            //ECar01 save
            settings.setValue("car01_unit_s",unit[i].car01.unit_s);
            settings.setValue("car01_unit_v",unit[i].car01.unit_v);
            settings.setValue("car01_unit_a",unit[i].car01.unit_a);
            settings.setValue("car01_unit_t",unit[i].car01.unit_t);
            settings.setValue("car01_unit_f",unit[i].car01.unit_f);
            settings.setValue("car01_unit_pin",unit[i].car01.unit_pin);

            settings.setValue("car01_pre_s",unit[i].car01.pre_s);
            settings.setValue("car01_pre_v",unit[i].car01.pre_v);
            settings.setValue("car01_pre_a",unit[i].car01.pre_a);
            settings.setValue("car01_pre_t",unit[i].car01.pre_t);
            settings.setValue("car01_pre_f",unit[i].car01.pre_f);
            settings.setValue("car01_pre_pin",unit[i].car01.pre_pin);

            settings.setValue("car01_graph_s",unit[i].car01.graph_s);
            settings.setValue("car01_graph_v",unit[i].car01.graph_v);
            settings.setValue("car01_graph_a",unit[i].car01.graph_a);
            settings.setValue("car01_graph_f",unit[i].car01.graph_f);

            settings.setValue("car01_vector",unit[i].car01.vector);
            settings.setValue("car01_reSign",unit[i].car01.reSign);

            settings.setValue("car01_filter_set",unit[i].car01.filter_set);
            settings.setValue("car01_filter_lpf",unit[i].car01.filter_lpf);
            settings.setValue("car01_filter_freq",unit[i].car01.filter_freq);

            //ECar01 save
            settings.setValue("car02_unit_s",unit[i].car02.unit_s);
            settings.setValue("car02_unit_v",unit[i].car02.unit_v);
            settings.setValue("car02_unit_a",unit[i].car02.unit_a);
            settings.setValue("car02_unit_t",unit[i].car02.unit_t);
            settings.setValue("car02_unit_f",unit[i].car02.unit_f);
            settings.setValue("car02_unit_pin",unit[i].car02.unit_pin);

            settings.setValue("car02_pre_s",unit[i].car02.pre_s);
            settings.setValue("car02_pre_v",unit[i].car02.pre_v);
            settings.setValue("car02_pre_a",unit[i].car02.pre_a);
            settings.setValue("car02_pre_t",unit[i].car02.pre_t);
            settings.setValue("car02_pre_f",unit[i].car02.pre_f);
            settings.setValue("car02_pre_pin",unit[i].car02.pre_pin);

            settings.setValue("car02_graph_s",unit[i].car02.graph_s);
            settings.setValue("car02_graph_v",unit[i].car02.graph_v);
            settings.setValue("car02_graph_a",unit[i].car02.graph_a);
            settings.setValue("car02_graph_f",unit[i].car02.graph_f);

            settings.setValue("car02_vector",unit[i].car02.vector);
            settings.setValue("car02_reSign",unit[i].car02.reSign);
        }
        settings.endArray();
    }
}

void Module_MOD1103_Condition::setUnit(Module_MOD1103_Condition::EUnits unit)
{
ui->comboBox_Unit->setCurrentText(unit.name);
ui->comboBox_Condition_Start_Car->setCurrentIndex(EDev_Mod1103::getESlave(unit.unit.start_car));
ui->comboBox_Condition_Start->setCurrentIndex(EDev_Mod1103::getCarCondition(unit.unit.start_condition));
ui->lineEdit_Condition_Start->setText(QString::number(unit.unit.start_value));
ui->comboBox_Condition_Stop_Car->setCurrentIndex(EDev_Mod1103::getESlave(unit.unit.stop_car));
ui->comboBox_Condition_Stop->setCurrentIndex(EDev_Mod1103::getCarCondition(unit.unit.stop_condition));
ui->lineEdit_Condition_Stop->setText(QString::number(unit.unit.stop_value));
m_ecar01_save = unit.car01;
m_ecar02_save = unit.car02;
}

Module_MOD1103_Condition::EUnits Module_MOD1103_Condition::getUnit()
{
    EUnits unit;
    bool ok;
    double val=0;
    val = QString(ui->lineEdit_Condition_Start->text()).toDouble(&ok);
    if(!ok){
        if(m_QMessageBox)delete m_QMessageBox;
        m_QMessageBox = new QMessageBox();
        QString str = "Đã có lỗi xảy ra! Giá trị của điều kiện\n\r \"" + ui->comboBox_Condition_Start->currentText() + "\" không đúng!";
        m_QMessageBox->setText(str);
        m_QMessageBox->setWindowTitle("Lỗi cài đặt");
        m_QMessageBox->setIcon(QMessageBox::Warning);
        m_QMessageBox->show();
        return unit;
        }
    unit.unit.start_value = val;
    val = QString(ui->lineEdit_Condition_Stop->text()).toDouble(&ok);
    if(!ok){
        if(m_QMessageBox)delete m_QMessageBox;
        m_QMessageBox = new QMessageBox();
        QString str = "Đã có lỗi xảy ra! Giá trị của điều kiện\n\r \"" + ui->comboBox_Condition_Stop->currentText() + "\" không đúng!";
        m_QMessageBox->setText(str);
        m_QMessageBox->setWindowTitle("Lỗi cài đặt");
        m_QMessageBox->setIcon(QMessageBox::Warning);
        m_QMessageBox->show();
        return unit;
        }
    unit.unit.stop_value = val;
    unit.name = ui->comboBox_Unit->currentText();
    unit.unit.start_car = EDev_Mod1103::getESlave(ui->comboBox_Condition_Start_Car->currentIndex());
    unit.unit.start_condition = EDev_Mod1103::getCarCondition(ui->comboBox_Condition_Start->currentIndex());
    unit.unit.stop_car = EDev_Mod1103::getESlave(ui->comboBox_Condition_Stop_Car->currentIndex());
    unit.unit.stop_condition = EDev_Mod1103::getCarCondition(ui->comboBox_Condition_Stop->currentIndex());

    //update carSave
    unit.car01 = m_ecar01_save;
    unit.car02 = m_ecar02_save;
    return unit;
}

void Module_MOD1103_Condition::updateConditionUnit()
{
    if(m_car_start==EDev_Mod1103::ESlave::CAR_02)ui->label_Condition_Start_Unit->setText(EDev_Mod1103::getCarConditionUnit(m_condition_start,m_ecar02));
        else ui->label_Condition_Start_Unit->setText(EDev_Mod1103::getCarConditionUnit(m_condition_start,m_ecar01));
    if(m_car_stop==EDev_Mod1103::ESlave::CAR_02)ui->label_Condition_Stop_Unit->setText(EDev_Mod1103::getCarConditionUnit(m_condition_stop,m_ecar02));
    else ui->label_Condition_Stop_Unit->setText(EDev_Mod1103::getCarConditionUnit(m_condition_stop,m_ecar01));
}


void Module_MOD1103_Condition::setProcessDefault()
{
    ui->pushButton_Run->setEnabled(true);
    ui->frame_Condition->setEnabled(true);
    ui->label_Blink_Start->setStyleSheet("color: rgb(0, 170, 127);");
    ui->label_Blink_Start->setHidden(false);
    ui->label_Blink_Stop->setHidden(false);
    ui->label_runBlink->setHidden(false);
    ui->label_Blink_Stop->setStyleSheet("color: rgb(85, 170, 255);");
    ui->label_Blink_Stop->setText("Điều kiện kết thúc");
    ui->label_Run_Comment->setText("Chọn bài thực hành, thiết lập các điều kiện và nhấn \"Thực hiện\"");
}

void Module_MOD1103_Condition::updateConditionData()
{
    QString _str="";
    switch(m_CDP_conditionProcess){
    case EDev_Mod1103::CDP_default:
        if(m_processValid){
            this->setProcessDefault();
            m_processValid = false;
        }
        ui->label_arrowBlink->setHidden(!m_blinkStatus);
        this->setConditionDisplay(m_car_start,EDev_Mod1103::getCar(m_car_start,m_ecar01,m_ecar02),m_condition_start);

        break;
    case EDev_Mod1103::CDP_init:
        ui->label_arrowBlink->setHidden(false);
        ui->frame_Condition->setEnabled(false);
        ui->label_Blink_Start->setStyleSheet("color: rgb(255, 0, 0);");
        _str = "Di chuyển XE-0" + QString::number(EDev_Mod1103::getESlave(m_car_start)+1)+ " để tìm kiếm điều kiện thỏa mãn "\
                +ui->comboBox_Condition_Start->currentText()+" "+ui->lineEdit_Condition_Start->text()+" "+ui->label_Condition_Start_Unit->text();
        ui->label_Run_Comment->setText(_str);
        m_processValid = true;
        break;
    case EDev_Mod1103::CDP_startCheck:
        this->setConditionDisplay(m_car_start,EDev_Mod1103::getCar(m_car_start,m_ecar01,m_ecar02),m_condition_start);
        ui->label_Blink_Start->setHidden(m_blinkStatus);
        break;
    case EDev_Mod1103::CDP_start:
        m_processTimeOut=0;
        ui->label_Blink_Start->setHidden(false);
        ui->label_Blink_Start->setStyleSheet("color: rgb(0, 170, 127);");
        ui->label_Blink_Stop->setStyleSheet("color: rgb(255, 0, 0);");
        _str = "Đang đợi XE-0" + QString::number(EDev_Mod1103::getESlave(m_car_stop)+1)+ " thỏa mãn điều kiện "\
                +ui->comboBox_Condition_Stop->currentText()+" "+ui->lineEdit_Condition_Stop->text()+" "+ui->label_Condition_Stop_Unit->text();
        ui->label_Run_Comment->setText(_str);
        break;
    case EDev_Mod1103::CDP_stopCheck:
        this->setConditionDisplay(m_car_stop,EDev_Mod1103::getCar(m_car_stop,m_ecar01,m_ecar02),m_condition_stop);
        ui->label_Blink_Stop->setHidden(m_blinkStatus);
        ui->label_runBlink->setHidden(m_blinkStatus);
        _str = "Điều kiện kết thúc (" + QString::number(QVariant(((m_processTimeoutMax/m_displayInterval)-m_processTimeOut)/100).toInt()) + ")";
        ui->label_Blink_Stop->setText(_str);
        //CheckTimeOut
        if(m_processTimeOut>m_processTimeoutMax/m_displayInterval){
            m_QMessageBox = new QMessageBox();
            m_QMessageBox->setText("Lỗi thời gian! Quá trình thực hành đã bị hủy.");
            m_QMessageBox->setWindowTitle("Lỗi điều kiện");
            emit setCondition(this->getUnit().unit,false);
            m_processTimeOut=0;
            m_CDP_conditionProcess = EDev_Mod1103::CDP_default;
            m_QMessageBox->show();
        }
        break;
    case EDev_Mod1103::CDP_stop:
        ui->label_Blink_Stop->setHidden(false);
        ui->label_runBlink->setHidden(false);
        ui->label_Blink_Stop->setStyleSheet("color: rgb(85, 170, 255);");
        ui->label_Run_Comment->setText("Đang đợi xử lý dữ liệu...");
        break;
    case EDev_Mod1103::CDP_end:
        ui->pushButton_Run->setEnabled(true);
        ui->frame_Condition->setEnabled(true);
        ui->label_Run_Comment->setText("Chọn bài thực hành, thiết lập các điều kiện và nhấn \"Thực hiện\"");
        m_processValid = false;
        this->hide();
        break;
    }
}

void Module_MOD1103_Condition::setConditionDisplay(EDev_Mod1103::ESlave slave,EDev_Mod1103::ECar car,EDev_Mod1103::CarCondition condition)
{
    QString val = "";
    QString sl = QString::number(EDev_Mod1103::getESlave(slave)+1);
    switch(condition){
    case EDev_Mod1103::CarCondition::CCD_default:val = "Quãng đường XE-0"+sl+": "+QString::number(car.s.value)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_S_Higher:val = "Quãng đường XE-0"+sl+": "+QString::number(car.s.value,'f',car.s.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_S_Lower:val = "Quãng đường XE-0"+sl+": "+QString::number(car.s.value,'f',car.s.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_V_Higher:val = "Vận tốc XE-0"+sl+": "+QString::number(car.v.value,'f',car.v.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_V_Lower:val = "Vận tốc XE-0"+sl+": "+QString::number(car.v.value,'f',car.v.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_A_Higher:val = "Gia tốc XE-0"+sl+": "+QString::number(car.a.value,'f',car.a.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_A_Lower:val = "Gia tốc XE-0"+sl+": "+QString::number(car.a.value,'f',car.a.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_F_Higher:val = "Lực tác động XE-0"+sl+": "+QString::number(car.f.value,'f',car.f.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_F_Lower:val = "Lực tác động XE-0"+sl+": "+QString::number(car.f.value,'f',car.f.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    case EDev_Mod1103::CarCondition::CCD_T_Higher:val = "Thời gian XE-0"+sl+": "+QString::number(car.t.value,'f',car.t.pre)+" "+EDev_Mod1103::getCarConditionUnit(condition,car);
        break;
    }
    ui->label_Blink_Process->setText(val);
}


void Module_MOD1103_Condition::on_pushButton_Save_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn chỉnh sửa lại bài thực hành\'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    if (msg.result() == QMessageBox::Yes) {
         if(ui->comboBox_Unit->currentIndex()>=m_unit.count()) return;
         m_unit.replace(ui->comboBox_Unit->currentIndex(),getUnit());
         this->saveUnits(m_unit);
     }

}

void Module_MOD1103_Condition::on_pushButton_New_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn tạo bài thực hành mới\'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    if (msg.result() == QMessageBox::Yes) {
         m_unit.append(getUnit());
         this->saveUnits(m_unit);
         ui->comboBox_Unit->addItem(m_unit.last().name);
         this->setUnit(m_unit.last());
     }
}

void Module_MOD1103_Condition::on_pushButton_Delete_clicked()
{
    QMessageBox  msg;
    msg.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msg.setText("Bạn có chắc chắn muốn xóa bài thực hành\'" + this->windowTitle() + "\' không?\n");
    msg.setWindowTitle(this->windowTitle());
    msg.setParent(nullptr);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowIcon(this->windowIcon());
    msg.exec();
    if (msg.result() == QMessageBox::Yes) {
         if(ui->comboBox_Unit->currentIndex()>=m_unit.count()) return;
         if(m_unit.count()<=1)return;
         m_unit.removeAt(ui->comboBox_Unit->currentIndex());
         this->saveUnits(m_unit);
         ui->comboBox_Unit->removeItem(ui->comboBox_Unit->currentIndex());
         this->setUnit(m_unit[ui->comboBox_Unit->currentIndex()]);
     }
}

void Module_MOD1103_Condition::on_comboBox_Unit_currentIndexChanged(int index)
{
    if(m_unit.count()>index){
        this->setUnit(m_unit[index]);
        emit this->setSetting(m_ecar01_save,m_ecar02_save);
    }
}

void Module_MOD1103_Condition::on_comboBox_Condition_Start_currentIndexChanged(int index)
{
    m_condition_start = EDev_Mod1103::getCarCondition(index);
    this->updateConditionUnit();
}

void Module_MOD1103_Condition::on_comboBox_Condition_Stop_currentIndexChanged(int index)
{
    m_condition_stop = EDev_Mod1103::getCarCondition(index);
    this->updateConditionUnit();
}

void Module_MOD1103_Condition::on_comboBox_Condition_Start_Car_currentIndexChanged(int index)
{
    m_car_start = EDev_Mod1103::getESlave(index);
    this->updateConditionUnit();
}

void Module_MOD1103_Condition::on_comboBox_Condition_Stop_Car_currentIndexChanged(int index)
{
    m_car_stop = EDev_Mod1103::getESlave(index);
    this->updateConditionUnit();
}


