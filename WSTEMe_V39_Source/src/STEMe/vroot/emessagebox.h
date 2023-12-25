#ifndef EMESSAGEBOX_H
#define EMESSAGEBOX_H

#include <QMainWindow>

namespace Ui {
class EMessageBox;
}

class EMessageBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit EMessageBox(QWidget *parent = nullptr);
    ~EMessageBox();

private:
    Ui::EMessageBox *ui;
};

#endif // EMESSAGEBOX_H
