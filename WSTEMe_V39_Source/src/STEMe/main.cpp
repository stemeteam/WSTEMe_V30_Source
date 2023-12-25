#include "mainwindow.h"
#include "vlogin/vformlogin.h"
#include "vtest/testwindow.h"
#include "vroot/addnewdevice.h"
#include <QApplication>
#include <vmodule/module_mod0050.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    VFormLogin login;
    //TestWindow test;
    Module_MOD0050 mod05;
 //   login.setGeometry(0,30,1024,600);

    login.show();
    //                                                                                                                                                                                                      mod05.show();
    //test.show();
    //w.show();

//    AddNewDevice add;
//    add.show();

//    DialogShowIcon dialogIcon;
//    dialogIcon.show();

    return a.exec();
}
