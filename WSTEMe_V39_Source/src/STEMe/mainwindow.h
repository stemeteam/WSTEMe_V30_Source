#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//system
#include <QGuiApplication>
#include <QMainWindow>
#include <QCloseEvent>
#include <QVector>
#include <QList>
#include <QColor>
#include <QMetaType>
#include <QModbusDataUnit>
#include <QScreen>

//User
#include <vcommunication/vcommunicationmodbus.h>
#include <vroot/vbuttonsingle.h>
#include <vlogin/vuser.h>
#include <vroot/formuseraccount.h>
#include <vroot/addnewdevice.h>
#include <vdevice/vlistdevice.h>
#include <vroot/vsettingdevice.h>
#include <aboutsteme.h>

//form sensor
#include "vsensors/sensor_sen0101.h"
#include "vsensors/sensor_sen0102.h"
#include "vsensors/sensor_sen0103.h"
#include "vsensors/sensor_sen0104.h"
#include "vsensors/sensor_sen0105.h"
#include "vsensors/sensor_sen0106.h"
#include "vsensors/sensor_sen0107.h"
#include "vsensors/sensor_sen0108.h"
#include "vsensors/sensor_sen0109.h"
#include "vsensors/sensor_sen0110.h"
#include "vsensors/sensor_sen0111.h"
#include "vsensors/sensor_sen0112.h"
#include "vsensors/sensor_sen0113.h"
#include "vsensors/sensor_sen0114.h"
#include "vsensors/sensor_sen0115.h"
#include "vsensors/sensor_sen0116.h"
#include "vsensors/sensor_sen0120.h"
#include "vsensors/sensor_sen0121.h"
#include "vsensors/sensor_sen0150.h"
#include "vsensors/sensor_sen0151.h"
#include "vsensors/sensor_sen0132.h"

//form Module
#include "vmodule/module_msg1101.h"
#include "vmodule/module_mod0020.h" //Module for tester
#include "vmodule/module_mod1101.h"
#include "vmodule/module_mod1102.h"
#include "vmodule/module_mod1103.h"
namespace Ui {

class MainWindow;
}

class VCommunicationModbus;
//class VButtonSingle;





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    inline void setNamePort(QString port){m_namePort = port;}

    void close();


    static int mainWindow_Width;
    static int mainWindow_Height;
    static int mainWindow_LocalX;
    static int mainWindow_LocalY;
    static QColor VBackgroud_Color;

    //Form main Size.....................

    int _formWidth = 1280,_formHeight=800;
    //int Width(){return _formWidth;}
    //int Hight(){return _formHeight;}
    void Refresh();
    void setUserLogin(VUser user);
    bool connectModbus(){return this->reConnectModbus();}

signals:
    void set_loggout();
private slots:
    void on_AddNewDevice();
    void on_vbuttonSigle_Clicked(VDevice dev);
    void on_actionExit_triggered();
    void on_pushButton_Loggout_clicked();
    void on_selectModule1101(Module_Msg1101::MsgSystem n);

    void on_pushButton_Loggout_2_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    VCommunicationModbus *vcomModbus;
    VUser m_userLogin;
    VDevice m_vdev;
    QString m_namePort="COM1";
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  m_rec = screen->geometry();

    void deleteWidgetAvailable(VDevice dev);

    //Declares about form of sensors...................................
    FormUserAccount *m_frmUserAccount = nullptr;
    AddNewDevice *m_frmAddNewDevice = nullptr;
    VSettingDevice *m_frmsettingDevice= nullptr;


    //Sensor form......................................................

    Sensor_SEN0101 *m_frmSEN0101 = nullptr;
    Sensor_SEN0102 *m_frmSEN0102 = nullptr;
    Sensor_SEN0103 *m_frmSEN0103 = nullptr;
    Sensor_SEN0104 *m_frmSEN0104 = nullptr;
    Sensor_SEN0105 *m_frmSEN0105 = nullptr;
    Sensor_SEN0106 *m_frmSEN0106 = nullptr;
    Sensor_SEN0107 *m_frmSEN0107 = nullptr;
    Sensor_SEN0108 *m_frmSEN0108 = nullptr;
    Sensor_SEN0109 *m_frmSEN0109 = nullptr;
    Sensor_SEN0110 *m_frmSEN0110 = nullptr;
    Sensor_SEN0111 *m_frmSEN0111 = nullptr;
    Sensor_SEN0112 *m_frmSEN0112 = nullptr;
    Sensor_SEN0113 *m_frmSEN0113 = nullptr;
    Sensor_SEN0114 *m_frmSEN0114 = nullptr;
    Sensor_SEN0115 *m_frmSEN0115 = nullptr;
    Sensor_SEN0116 *m_frmSEN0116 = nullptr;
    Sensor_SEN0120 *m_frmSEN0120 = nullptr;
    Sensor_SEN0121 *m_frmSEN0121 = nullptr;
    Sensor_SEN0150 *m_frmSEN0150 = nullptr;
    Sensor_SEN0151 *m_frmSEN0151 = nullptr;
    Sensor_SEN0132 *m_frmSEN0132 = nullptr;

    //for Module
    Module_Msg1101 *m_frmMSG1101 = nullptr;
    Module_MOD1101 *m_frmMOD1101 = nullptr;
    Module_MOD1102 *m_frmMOD1102 = nullptr;
    Module_MOD0020 *m_frmMOD0020 = nullptr;
    Module_MOD1103 *m_frmMOD1103 = nullptr;



    VButtonSingle *vbuttonSingle = nullptr;
    QFrame *m_frameButtonSensors = nullptr;
    QFrame *m_frameButtonModules= nullptr;
    QFrame *m_frameButtonSystems = nullptr;
    QFrame *m_frameButtonSettings = nullptr;
    AboutSteme *m_aboutSteme = nullptr;
    //size of main form...

    //Modbus Communication
    bool reConnectModbus();
    //load/write widgets on frameWidget......
    void refreshFrameWidget();
    void setFrameDevice();


    //getLocalForWidget
    int getLocal_X(int width){
        return ((m_rec.width()-width)/2);
    }
    int getLocal_Y(int height){
    return ((m_rec.height()-height)/2);
    }

};

#endif // MAINWINDOW_H
