#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //动态分配空间，不能指定父对象
    myT = new MyThread;
    //创建子线程
    thread = new QThread(this);
    //将自定义的线程加入到子线程中
    myT->moveToThread(thread);

    connect(myT,&MyThread::mySignal,this,&Widget::dealSignal);

    qDebug() << "主线程号:" << QThread::currentThread();

    connect(this,&Widget::startThread,myT,&MyThread::myTimeout);

    connect(this,&Widget::destroyed,this,&Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealClose()
{
    on_buttonStop_clicked();
}

void Widget::on_buttonStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }
    //启动线程，但是没有启动线程处理函数
    thread->start();
    myT->setFlag(false);
    //不能直接调用线程处理函数，导致线程处理函数和主要线程在同一个线程
    // myT->myTimeout();

    //只能通过信号和槽的方法调用
    emit startThread();
}

void Widget::on_buttonStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}

void Widget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}
