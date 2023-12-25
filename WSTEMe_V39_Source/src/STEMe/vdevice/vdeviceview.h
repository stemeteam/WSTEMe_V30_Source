#ifndef VDEVICEVIEW_H
#define VDEVICEVIEW_H

#include <QWidget>
#include <vdevice/vdevice.h>
#include <vdevice/vlistdevice.h>
#include "QStandardItemModel"

namespace Ui {
class VDeviceView;
}

class VDeviceView : public QWidget
{
    Q_OBJECT

public:
    explicit VDeviceView(QWidget *parent = nullptr);
    ~VDeviceView();

private slots:
    void on_tableView_Device_pressed(const QModelIndex &index);

    void on_pushButton_SelectDevice_clicked();

    void on_pushButton_RemoveDevice_clicked();

    void on_pushButton_Cancel_clicked();

    void on_tableView_Select_pressed(const QModelIndex &index);

    void on_pushButton_Apply_clicked();

private:
    Ui::VDeviceView *ui;



    QList<VDevice> m_listDevice;

    QList<VDevice> m_listDeviceSelect;
    VDevice  m_deviceSelect;
    int m_indexSelect=0;

    bool checkDevice(VDevice dev, QList<VDevice> listDevice) const;
    void refreshTableView();
    void refreshTableSelect();
};

#endif // VDEVICEVIEW_H
