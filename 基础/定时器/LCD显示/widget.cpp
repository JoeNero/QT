#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mTimer = new QTimer(this);
    ui->lcdNumber->setDecMode();
    ui->lcdNumber->display(0);


    connect(mTimer,SIGNAL(timeout()),this,SLOT(upDate()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::upDate()
{
    int num  = ui->lcdNumber->value();
    num++;
    ui->lcdNumber->display(num);
}

void Widget::on_btnStart_clicked()
{
    //若定时器活跃，则不操作，反之开启
    if(mTimer->isActive())
    {
        return;
    }
    mTimer->setInterval(100);
    mTimer->start();
}

void Widget::on_btnStop_clicked()
{
    //若定时器不活跃，则不操作，反之关闭
    if(mTimer->isActive()==0)
    {
        return;
    }
    mTimer->stop();
}

void Widget::on_btnRestart_clicked()
{
    if(mTimer->isActive())
    {
        mTimer->stop();
    }
    ui->lcdNumber->display(0);
}
