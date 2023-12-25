#include "emessagebox.h"
#include "ui_emessagebox.h"

EMessageBox::EMessageBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EMessageBox)
{
    ui->setupUi(this);
}

EMessageBox::~EMessageBox()
{
    delete ui;
}
