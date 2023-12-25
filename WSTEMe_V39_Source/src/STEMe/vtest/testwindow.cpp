#include "testwindow.h"
#include "ui_testwindow.h"
#include "vfile/vfile.h"
#include "vdevice/vdevice.h"
#include "vdevice/vlistdevice.h"
#include <QMessageBox>

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::on_pushButton_clicked()
{
    VFile file;
    VListDevice listDev;
    VDevice dev = listDev.device(5);

    QVector<double> data;
    QList<QVector<double>> lst;

    for(int i=0;i<50;i++)data.append(i);
    lst.append(data);
    data.clear();
    for(int i=50;i<90;i++)data.append(i);
    lst.append(data);
    data.clear();
    for(int i=90;i<200;i++)data.append(i);
    lst.append(data);

    file.saveDatas(dev,lst,1000);

        //QMessageBox::information(nullptr,"Save file", "Error save file",QMessageBox::Ok);


}
