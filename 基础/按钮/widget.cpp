#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QDebug>
#include <QMenu>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Button4种样式");
    //1正常
    btn1 = new QPushButton("NormalButton",this);
    //2.可停驻
    btn2 = new QPushButton("ToggleButton",this);
    btn2->setCheckable(true);
    btn2->setChecked(true);
    //3.带弹出式菜单
    btn3 = new QPushButton("Popup Button",this);
    QMenu* menu = new QMenu;
    menu->addAction("Open Item");
    menu->addAction("Save Item");
    menu->addMenu("More Item");
    menu->addSeparator();
    menu->addAction("Close Item");
    btn3->setMenu(menu);
    //4.平坦样式
    btn4 = new QPushButton("Flat Button",this);
    btn4->setFlat(true);

    QGridLayout *glayout = new QGridLayout(this);

//    glayout->setRowStretch(2,1);        //设置行比例系数
//    glayout->setColumnStretch(2,1);     //设置列比例系数

    glayout->addWidget(btn1,0,0);
    glayout->addWidget(btn2,0,1);
    glayout->addWidget(btn3,1,0);
    glayout->addWidget(btn4,1,1);
}

Widget::~Widget()
{
    delete ui;
}


