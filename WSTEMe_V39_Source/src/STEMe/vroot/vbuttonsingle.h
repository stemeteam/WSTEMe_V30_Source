#ifndef VBUTTONSINGLE_H
#define VBUTTONSINGLE_H

#include <QWidget>
#include <QMetaType>
#include <QList>
#include <QSize>
#include <vdevice/vdevice.h>

namespace Ui {
class VButtonSingle;
}

class VButtonSingle : public QWidget
{
    Q_OBJECT

public:
    explicit VButtonSingle(QWidget *parent = nullptr);
    ~VButtonSingle();


    void setDeviceWidget(VDevice dev);
    void setLocal_ax(int ax){
        _local_ax = ax;
    }
    void setLocal_ay(int ay){
        _local_ay = ay;
    }
public: signals:
    void signal_vbuttonSigle_Clicked(VDevice dev);

private slots:
    void on_pushButton_clicked();

private:
    Ui::VButtonSingle *ui;
    VDevice m_device;

    int _local_ax = 0,_local_ay = 0;
};

#endif // VBUTTONSINGLE_H
