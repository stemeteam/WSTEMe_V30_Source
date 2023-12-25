#ifndef MODULE_MSG1101_H
#define MODULE_MSG1101_H

#include <QMainWindow>

namespace Ui {
class Module_Msg1101;
}

class Module_Msg1101 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Module_Msg1101(QWidget *parent = nullptr);
    ~Module_Msg1101();

    enum MsgSystem{
        MSG_SYSTEM_WATER,
        MSG_SYSTEM_SPRINGS,
        MSG_SYSTEM_SENSOR
    };

    void setRadioButton(MsgSystem n);
signals:
    void set_selectModule1101(MsgSystem n);
private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::Module_Msg1101 *ui;
};

#endif // MODULE_MSG1101_H
