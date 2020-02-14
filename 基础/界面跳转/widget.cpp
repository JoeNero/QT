#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&f1,Form::MySignal,this,&Widget::subSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::subSlot()
{
   f1.hide();
   this->show();
}

//跳转到子界面
void Widget::on_pushButton_clicked()
{
    f1.show();
    this->hide();
}
