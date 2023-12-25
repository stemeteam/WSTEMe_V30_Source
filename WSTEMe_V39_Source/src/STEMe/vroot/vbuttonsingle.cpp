#include "vbuttonsingle.h"
#include "ui_vbuttonsingle.h"
#include <QSize>
#include <QDebug>


VButtonSingle::VButtonSingle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VButtonSingle)
{
    ui->setupUi(this);
}

VButtonSingle::~VButtonSingle()
{
    delete ui;
}

void VButtonSingle::setDeviceWidget(VDevice dev){
    m_device = dev;
    ui->label->setText(dev.name());
    ui->pushButton->setObjectName(dev.objectName());
    QString style = "background-color: green; border: none;\
                    border-style: outset;\
                    border-width: 0px;\
                    border-radius: 20px;\
                    border-color: black;\
                    ";
   style.append("background-image: url(");
   style.append(dev.iconPath());
   style.append(");");
    ui->pushButton->setStyleSheet(style);

    this->setGeometry(_local_ax,_local_ay,160,160);
    this->updateGeometry();
}

void VButtonSingle::on_pushButton_clicked()
{
    emit this->signal_vbuttonSigle_Clicked(m_device);
}
