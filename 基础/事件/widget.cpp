#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("事件");
}

Widget::~Widget()
{
    delete ui;
}

//重写键盘按下事件
void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    ui->label->setText(QString((char)e->key()));
}
//重写鼠标点击事件
void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) //如果是左键按下
       {
 //          qDebug() << "按下的是左键";
           ui->label->setText(QString("左键按下"));
           //事件接收后,就不会往下传递
           e->ignore();    //忽略,事件继续往下传递,给谁传递
                         //
       }
    else if(e->button() == Qt::RightButton)
    {
        ui->label->setText(QString("右键按下"));
        //事件接收后,就不会往下传递
        e->ignore();    //忽略,事件继续往下传递,给谁传递
    }
   else
   {
        //不做处理
         e->ignore();
        //事件的忽略,事件继续往下传递
   }
}
