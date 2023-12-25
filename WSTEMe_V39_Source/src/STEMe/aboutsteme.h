#ifndef ABOUTSTEME_H
#define ABOUTSTEME_H

#include <QMainWindow>

namespace Ui {
class AboutSteme;
}

class AboutSteme : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutSteme(QWidget *parent = nullptr);
    ~AboutSteme();

private slots:
    void on_pushButton_Cancel_clicked();

private:
    Ui::AboutSteme *ui;
};

#endif // ABOUTSTEME_H
