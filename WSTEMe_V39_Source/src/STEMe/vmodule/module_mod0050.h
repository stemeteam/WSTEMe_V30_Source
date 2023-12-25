#ifndef MODULE_MOD0050_H
#define MODULE_MOD0050_H

//system
#include <QWidget>
#include <QCloseEvent>
#include <QModbusDataUnit>

//user
#include <vcommunication/vcommunicationmodbus.h>
#include <vdevice/vdevice.h>
#include <vchart/vchart_zoom.h>
#include <vdevice/vdeviceview.h>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Module_MOD0050;
}

class Module_MOD0050 : public QWidget
{
    Q_OBJECT


   /////////////////////////////////////////////////////////////////////////////////////////////////Main Function for Module.....

public:
    explicit Module_MOD0050(QWidget *parent = nullptr);
    ~Module_MOD0050();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Module_MOD0050 *ui;

};


#endif // MODULE_MOD1101_H
