#include "mylable.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QPalette>

MyLable::MyLable(QWidget *parent) : QWidget(parent)
{
    disp = new QLabel(this);
    disp->setFixedSize(QSize(20,20));
    //设置游标背景为白色
    disp->setAutoFillBackground(true);
    QPalette palette1;
    palette1.setColor(QPalette::Background,Qt::white);
    disp->setPalette(palette1);
    disp->setAlignment(Qt::AlignCenter);
    disp->setVisible(false);
    disp->move(0,3);

    /*拉bar1*/
    QLabel *label1 = new QLabel(this);
    QSlider *slider1 =new QSlider(Qt::Horizontal,this);
    QSpinBox *spin1 = new QSpinBox(this);
    /*拉bar2*/
    QLabel *label2 = new QLabel(this);
    QSlider *slider2 =new QSlider(Qt::Horizontal,this);
    QSpinBox *spin2 = new QSpinBox(this);
	
	QPieSlice *slice_1 = new QPieSlice(QStringLiteral("A数据"),0.6,this);
    QPieSlice *slice_2 = new QPieSlice(QStringLiteral("B数据"),0.4,this);

    //设置最大最小值
    slider1->setMaximum(100);
    slider2->setMaximum(100);

    slider1->setMinimum(0);
    slider2->setMinimum(0);

    spin1->setMaximum(100);
    spin2->setMaximum(100);

    //饼图
    slice_1->setLabelVisible(true); //显示饼状区对应的数据Alabel
    slice_2->setLabelVisible(true); //显示饼状区对应的数据Blabel

    slice_1->setBrush(Qt::green);
    slice_2->setBrush(Qt::blue);

    //将两个饼状区加入series
    QPieSeries *series = new QPieSeries(this);
    series->append(slice_1);
    series->append(slice_2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations);  //设置显示时的动画效果

    QChartView *chartView = new QChartView(this);
    chartView->show();
    chartView->setChart(chart);
		
    label1->setText(s1);
    label2->setText(s2);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QHBoxLayout *hlayout1 = new QHBoxLayout(this);
    QHBoxLayout *hlayout2 = new QHBoxLayout(this);

    hlayout1->addWidget(label1);
    hlayout1->addWidget(slider1);
    hlayout1->addWidget(spin1);

    hlayout2->addWidget(label2);
    hlayout2->addWidget(slider2);
    hlayout2->addWidget(spin2);
	
    //vlayout->addWidget(hlayout);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
	vlayout->addWidget(chartView);

    //默认值
    spin1->setValue(defalutSpin1);
    spin2->setValue(defalutSpin2);
    slider1->setValue(defalutSlider1);
    slider2->setValue(defalutSlider2);

    connect(spin1,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider1,
            &QSlider::setValue
            );
    connect(spin2,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider2,
            &QSlider::setValue
            );

    connect(slider1,&QSlider::valueChanged,spin1,&QSpinBox::setValue);
    connect(slider2,&QSlider::valueChanged,spin2,&QSpinBox::setValue);

    connect(slider1,&QSlider::valueChanged,
            [=]()
    {
         int i = slider1->value();
         slider2->setValue(100-i);
         double temp = i/100.0;
         slice_1->setValue(temp);
         slice_2->setValue(1-temp);
    });

    connect(slider2,&QSlider::valueChanged,
            [=]()
    {
        int i = slider2->value();
        slider1->setValue(100-i);
        double temp = i/100.0;
        slice_2->setValue(temp);
        slice_1->setValue(1-temp);
    });
}


