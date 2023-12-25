#ifndef DIALOGSHOWICON_H
#define DIALOGSHOWICON_H

#include <QDialog>
#include <QIcon>

namespace Ui {
class DialogShowIcon;
}

class DialogShowIcon : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowIcon(QWidget *parent = nullptr);
    ~DialogShowIcon();

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Select_Icon_Clicked();
    void on_pushButton_Cancel_clicked();

signals:
    void signal_SelectIcon(QIcon icon,QString iconPath);

protected:
    bool eventFilter(QObject *target, QEvent *event) override;
private:
    Ui::DialogShowIcon *ui;
    QIcon m_icon;
    QString m_pathIcon="";
};

#endif // DIALOGSHOWICON_H
