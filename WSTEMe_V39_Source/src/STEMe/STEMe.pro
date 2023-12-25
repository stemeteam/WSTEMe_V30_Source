#-------------------------------------------------
#
# Project created by QtCreator 2020-09-22T11:36:06
#
#-------------------------------------------------

QT       += core gui serialbus charts serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = STEMe
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += static
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    vcommunication/vcommunicationmodbus.cpp \
    vroot/vbuttonsingle.cpp \
    vroot/addnewdevice.cpp \
    vlogin/vformlogin.cpp \
    vroot/formuseraccount.cpp \
    vroot/dialogshowicon.cpp \
    vlogin/vuser.cpp \
    vlogin/vlistuser.cpp \
    vdevice/vdevice.cpp \
    vdevice/vlistdevice.cpp \
    vcommunication/vnetworkdataunit.cpp \
    vchart/vdynamicspline.cpp \
    vsensors/sensor_sen0150.cpp \
    vsensors/sensor_sen0151.cpp \
    vsensors/sensor_sen0112.cpp \
    vsensors/sensor_sen0116.cpp \
    vsensors/sensor_sen0104.cpp \
    vsensors/sensor_sen0110.cpp \
    vsensors/sensor_sen0106.cpp \
    vsensors/sensor_sen0109.cpp \
    vsensors/sensor_sen0115.cpp \
    vsensors/sensor_sen0105.cpp \
    vsensors/sensor_sen0114.cpp \
    vsensors/sensor_sen0111.cpp \
    vsensors/sensor_sen0113.cpp \
    vsensors/sensor_sen0107.cpp \
    vsensors/sensor_sen0120.cpp \
    vsensors/sensor_sen0132.cpp \
    vchart/vchart_zoom.cpp \
    vmodule/module_mod1101.cpp \
    vmodule/module_mod0020.cpp \
    vroot/vsettingdevice.cpp \
    vmodule/module_mod1102.cpp \
    vtest/testwindow.cpp \
    vfile/vfile.cpp \
    vmodule/module_mod0050.cpp \
    vdevice/vdeviceview.cpp \
    vchart/vchart.cpp \
    vchart/chart.cpp \
    vchart/chartview.cpp \
    vroot/vdevicecalibration.cpp \
    vsensors/sensor_sen0101.cpp \
    vsensors/sensor_sen0102.cpp \
    vsensors/sensor_sen0103.cpp \
    vsensors/sensor_sen0108.cpp \
    esensor/esensors.cpp \
    esensor/esensor_base.cpp \
    esensor/edev_mod1101.cpp \
    esensor/echarts.cpp \
    esensor/echartgesture.cpp \
    vmodule/module_mod1103.cpp \
    esensor/edev_mod1103.cpp \
    esensor/edev_sen0101.cpp \
    esensor/edev_sen0121.cpp \
    vsensors/sensor_sen0121.cpp \
    esensor/edev_sen0102.cpp \
    esensor/edev_sen0150.cpp \
    esensor/edev_sen0151.cpp \
    esensor/edev_sen0105.cpp \
    esensor/edev_sen0106.cpp \
    esensor/edev_sen0104.cpp \
    vroot/emessagebox.cpp \
    vmodule/module_msg1101.cpp \
    esensor/edev_sen0103.cpp \
    esensor/edev_sen0107.cpp \
    esensor/edev_sen0108.cpp \
    esensor/edev_sen0109.cpp \
    esensor/edev_sen0110.cpp \
    esensor/edev_sen0111.cpp \
    esensor/edev_sen0112.cpp \
    esensor/edev_sen0113.cpp \
    esensor/edev_sen0114.cpp \
    esensor/edev_sen0115.cpp \
    esensor/edev_sen0116.cpp \
    esensor/edev_sen0120.cpp \
    esensor/edev_sen0132.cpp \
    aboutsteme.cpp \
    efilter/elowpassfilter.cpp \
    vmodule/module_mod1103_condition.cpp \
    echart/ecallout.cpp \
    echart/crosshairs.cpp \
    echart/echartlines.cpp \
    efilter/efrequency.cpp


HEADERS += \
        mainwindow.h \
    vcommunication/vcommunicationmodbus.h \
    vroot/vbuttonsingle.h \
    vroot/addnewdevice.h \
    vlogin/vformlogin.h \
    vroot/formuseraccount.h \
    vroot/dialogshowicon.h \
    vlogin/vuser.h \
    vlogin/vlistuser.h \
    vdevice/vdevice.h \
    vdevice/vlistdevice.h \
    vcommunication/vnetworkdataunit.h \
    vchart/vdynamicspline.h \
    vsensors/sensor_sen0150.h \
    vsensors/sensor_sen0151.h \
    vsensors/sensor_sen0112.h \
    vsensors/sensor_sen0116.h \
    vsensors/sensor_sen0104.h \
    vsensors/sensor_sen0110.h \
    vsensors/sensor_sen0106.h \
    vsensors/sensor_sen0109.h \
    vsensors/sensor_sen0115.h \
    vsensors/sensor_sen0105.h \
    vsensors/sensor_sen0114.h \
    vsensors/sensor_sen0111.h \
    vsensors/sensor_sen0113.h \
    vsensors/sensor_sen0107.h \
    vsensors/sensor_sen0120.h \
    vchart/vchart_zoom.h \
    vmodule/module_mod1101.h \
    vmodule/module_mod0020.h \
    vroot/vsettingdevice.h \
    vmodule/module_mod1102.h \
    vtest/testwindow.h \
    vfile/vfile.h \
    vmodule/module_mod0050.h \
    vdevice/vdeviceview.h \
    vchart/vchart.h \
    vchart/chart.h \
    vchart/chartview.h \
    vroot/vdevicecalibration.h \
    vsensors/sensor_sen0101.h \
    vsensors/sensor_sen0102.h \
    vsensors/sensor_sen0103.h \
    vsensors/sensor_sen0108.h \
    esensor/esensors.h \
    esensor/esensor_base.h \
    esensor/edev_mod1101.h \
    esensor/echarts.h \
    esensor/echartgesture.h \
    vmodule/module_mod1103.h \
    esensor/edev_mod1103.h \
    esensor/edev_sen0101.h \
    esensor/edev_sen0121.h \
    vsensors/sensor_sen0121.h \
    vsensors/sensor_sen0132.h \
    esensor/edev_sen0102.h \
    esensor/edev_sen0150.h \
    esensor/edev_sen0151.h \
    esensor/edev_sen0105.h \
    esensor/edev_sen0106.h \
    esensor/edev_sen0104.h \
    vroot/emessagebox.h \
    vmodule/module_msg1101.h \
    esensor/edev_sen0103.h \
    esensor/edev_sen0107.h \
    esensor/edev_sen0108.h \
    esensor/edev_sen0109.h \
    esensor/edev_sen0110.h \
    esensor/edev_sen0111.h \
    esensor/edev_sen0112.h \
    esensor/edev_sen0113.h \
    esensor/edev_sen0114.h \
    esensor/edev_sen0115.h \
    esensor/edev_sen0116.h \
    esensor/edev_sen0120.h \
    esensor/edev_sen0132.h \
    aboutsteme.h \
    efilter/elowpassfilter.h \
    vmodule/module_mod1103_condition.h \
    echart/ecallout.h \
    echart/crosshairs.h \
    echart/echartlines.h \
    efilter/efrequency.h


FORMS += \
        mainwindow.ui \
    vroot/vbuttonsingle.ui \
    vroot/addnewdevice.ui \
    vlogin/vformlogin.ui \
    vroot/formuseraccount.ui \
    vroot/dialogshowicon.ui \
    vsensors/sensor_sen0150.ui \
    vsensors/sensor_sen0151.ui \
    vsensors/sensor_sen0112.ui \
    vsensors/sensor_sen0116.ui \
    vsensors/sensor_sen0104.ui \
    vsensors/sensor_sen0110.ui \
    vsensors/sensor_sen0106.ui \
    vsensors/sensor_sen0109.ui \
    vsensors/sensor_sen0115.ui \
    vsensors/sensor_sen0105.ui \
    vsensors/sensor_sen0114.ui \
    vsensors/sensor_sen0111.ui \
    vsensors/sensor_sen0113.ui \
    vsensors/sensor_sen0107.ui \
    vsensors/sensor_sen0120.ui \
    vchart/vchart_zoom.ui \
    vmodule/module_mod1101.ui \
    vmodule/module_mod0020.ui \
    vroot/vsettingdevice.ui \
    vmodule/module_mod1102.ui \
    vtest/testwindow.ui \
    vmodule/module_mod0050.ui \
    vdevice/vdeviceview.ui \
    vroot/vdevicecalibration.ui \
    vsensors/sensor_sen0101.ui \
    vsensors/sensor_sen0102.ui \
    vsensors/sensor_sen0103.ui \
    vsensors/sensor_sen0108.ui \
    vmodule/module_mod1103.ui \
    vsensors/sensor_sen0121.ui \
    vsensors/sensor_sen0132.ui \
    vroot/emessagebox.ui \
    vmodule/module_msg1101.ui \
    aboutsteme.ui \
    vmodule/module_mod1103_condition.ui



#QMAKE_LFLAGS += -static

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
RC_ICONS = image/Steme_icon.ico
