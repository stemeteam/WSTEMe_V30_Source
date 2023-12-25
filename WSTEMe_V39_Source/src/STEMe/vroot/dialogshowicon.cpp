#include "dialogshowicon.h"
#include "ui_dialogshowicon.h"
#include <QTextStream>
#include <QPushButton>
#include <QIcon>
#include <QMessageBox>
#include <QStringList>
#include <QEvent>
#include <QDir>

DialogShowIcon::DialogShowIcon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowIcon)
{
    ui->setupUi(this);
    ui->pushButton_OK->setEnabled(false);
    ui->scrollArea_Icon->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_Icon->setWidgetResizable( true );
    //assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory(":/image");
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG",QDir::Files);
    QStringList icon;

    foreach(QString filename, images) {
    //do whatever you need to do
        icon.append(":/image/" + filename);
    }
    QPushButton *btn;
    int btn_width=70,btn_height=70;
    int btn_X = 0,btn_Y=0;
    for(int i=0;i<icon.count();i++){
        btn = new QPushButton(ui->scrollArea_Icon);
        QString sheet = "Border:1px";
        btn->setObjectName(icon[i]);
        btn->setGeometry(btn_X,btn_Y,btn_width,btn_height);
        btn->setStyleSheet(sheet);
        btn->setIconSize(QSize(btn_width,btn_height));
        btn->setIcon(QIcon(icon.at(i)));
        btn->installEventFilter(this);
 //       connect(btn,&QPushButton::clicked,this,&DialogShowIcon::on_pushButton_Select_Icon_Clicked);
        btn->show();
        btn_X+=btn_width+20;
        if((btn_X+btn_width)>ui->scrollArea_Icon->width()){
            btn_Y+=btn_height+20;
            btn_X = 0;
        }

        //ui->scrollArea_Icon->scroll(ui->scrollArea_Icon->width(),btn_Y);
    }
          // ui->scrollArea_Icon->resize(ui->scrollArea_Icon->width(),btn_Y+1000);

}

DialogShowIcon::~DialogShowIcon()
{
    delete ui;
}

void DialogShowIcon::on_pushButton_OK_clicked()
{
emit signal_SelectIcon(m_icon,m_pathIcon);
    this->close();

}

void DialogShowIcon::on_pushButton_Select_Icon_Clicked()
{
//    QPoint p = ui->scrollArea_Icon->mapFromGlobal(QCursor::pos());
//    QObject *obj = childAt(p);

}

void DialogShowIcon::on_pushButton_Cancel_clicked()
{
    this->close();
}

bool DialogShowIcon::eventFilter(QObject *target, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress){
            m_icon = QIcon(target->objectName());
            m_pathIcon = target->objectName();
            ui->pushButton_OK->setEnabled(true);
            return true;
    }
    if(event->type()==QEvent::MouseButtonDblClick){
            m_icon = QIcon(target->objectName());
            ui->pushButton_OK->setEnabled(true);
            return true;
    }
    return QObject::eventFilter(target,event);
}

