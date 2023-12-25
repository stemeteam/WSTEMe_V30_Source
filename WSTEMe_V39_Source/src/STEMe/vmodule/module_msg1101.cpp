#include "module_msg1101.h"
#include "ui_module_msg1101.h"

Module_Msg1101::Module_Msg1101(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Module_Msg1101)
{
    ui->setupUi(this);
}

Module_Msg1101::~Module_Msg1101()
{
    delete ui;
}

void Module_Msg1101::setRadioButton(MsgSystem n)
{
    switch(n){
    case MSG_SYSTEM_WATER:ui->radioButton_WT->setChecked(true);
        break;
    case MSG_SYSTEM_SPRINGS:ui->radioButton_LX->setChecked(true);
        break;
    case MSG_SYSTEM_SENSOR:ui->radioButton_LC->setChecked(true);
        break;
    }
}

void Module_Msg1101::on_pushButton_OK_clicked()
{
if(ui->radioButton_WT->isChecked())emit set_selectModule1101(MSG_SYSTEM_WATER);
if(ui->radioButton_LX->isChecked())emit set_selectModule1101(MSG_SYSTEM_SPRINGS);
if(ui->radioButton_LC->isChecked())emit set_selectModule1101(MSG_SYSTEM_SENSOR);
this->close();
}
