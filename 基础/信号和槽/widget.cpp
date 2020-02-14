#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn1.setParent(this);
    btn1.setText("按钮1");
    connect(&btn1,&QPushButton::clicked,this,&Widget::chang1);

    btn2 = new QPushButton(this);
    btn2->setText("按钮2");
    connect(btn2,&QPushButton::clicked,this,&Widget::chang2);

    QPushButton *btn3 = new QPushButton(this);
    btn3->setText("按钮3");
    connect(btn3,&QPushButton::clicked,this,&Widget::chang1);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(&btn1);
    hlayout->addWidget(btn2);
    hlayout->addWidget(btn3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::chang1()
{
    btn1.setText("111");
}

void Widget::chang2()
{
    btn1.setText("222");
    btn2->setText("222");
}
