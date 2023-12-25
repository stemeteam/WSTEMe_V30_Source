//user
#include "module_mod0050.h"
#include "ui_module_mod0050.h"

QT_CHARTS_USE_NAMESPACE



/////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....
Module_MOD0050::Module_MOD0050(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Module_MOD0050)
{
}

Module_MOD0050::~Module_MOD0050()
{
    delete ui;
}

void Module_MOD0050::closeEvent(QCloseEvent *event)
{

}

