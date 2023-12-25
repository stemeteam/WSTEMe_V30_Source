#include "aboutsteme.h"
#include "ui_aboutsteme.h"

AboutSteme::AboutSteme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutSteme)
{
    ui->setupUi(this);
    this->setGeometry(640-(this->width()/2),400-(this->height()/2),this->width(),this->height());
}

AboutSteme::~AboutSteme()
{
    delete ui;
}

void AboutSteme::on_pushButton_Cancel_clicked()
{
    this->close();
}
