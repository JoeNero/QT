#include "widget.h"
#include "ui_widget.h"
#include <QPen>
#include <QPainter>
#include "qmath.h"

const int maxSize = 1024;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QGridLayout();
    initAxis1();
    initAxis2();

    bulidChart1();
    bulidChart2();
    ui->widget->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initAxis1()
{
    chart1 = new QChart;
    chartView1 = new QChartView(this);

    axisX1 = new QValueAxis;
    axisY1= new QValueAxis;

    axisX1->setRange(0,10);              //设置范围
    axisY1->setRange(0,10);

    axisX1->setLabelFormat("%u");        //设置刻度的格式
    axisY1->setLabelFormat("%u");

    axisX1->setGridLineVisible(true);    //网格线可见
    axisY1->setGridLineVisible(true);

    axisX1->setTickCount(6);            //设置多少个大格
    axisY1->setTickCount(6);

    axisX1->setMinorTickCount(1);        //设置每个大格里面小刻度线的数目
    axisY1->setMinorTickCount(1);

    axisX1->setTitleText("X");           //设置描述
    axisY1->setTitleText("Y");
    axisX1->setLabelsVisible(true);//设置刻度是否可见
}

void Widget::initAxis2()
{
    chart2 = new QChart;
    chartView2 = new QChartView(this);

    axisX2 = new QValueAxis;
    axisY2 = new QValueAxis;

    axisX2->setRange(-10,10);              //设置范围
    axisY2->setRange(-10,10);

    axisX2->setLabelFormat("%d");        //设置刻度的格式
    axisY2->setLabelFormat("%d");

    axisX2->setGridLineVisible(true);    //网格线可见
    axisY2->setGridLineVisible(true);

    axisX2->setTickCount(6);            //设置多少个大格
    axisY2->setTickCount(6);

    axisX2->setMinorTickCount(1);        //设置每个大格里面小刻度线的数目
    axisY2->setMinorTickCount(1);

    axisX2->setTitleText("X");           //设置描述
    axisY2->setTitleText("Y");
    axisX1->setLabelsVisible(true);//设置刻度是否可见
}

//静态曲线图
void Widget::bulidChart1()
{
    series1 = new QSplineSeries;
    chart1->addAxis(axisX1, Qt::AlignBottom); //下：Qt::AlignBottom  上：Qt::AlignTop
    chart1->addAxis(axisY1, Qt::AlignLeft);   //左：Qt::AlignLeft    右：Qt::AlignRight
    //创建数据源
    series1->setPen(QPen(Qt::red,1,Qt::SolidLine));//设置曲线显示效果

    series1->append(0, 6); //这里是添加数据的两种方式
    series1->append(2, 4);
    series1->append(3, 8);
    series1->append(6, 4);
    series1->append(8, 6);
    series1->append(10, 5);
    *series1 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    chart1->setTitle("静态曲线图实例1");
    chart1->setAnimationOptions(QChart::SeriesAnimations);//设置曲线动画模式
    chart1->legend()->hide(); //隐藏图例
    chart1->addSeries(series1);//输入数据
    chart1->setAxisX(axisX1, series1);
    chart1->setAxisY(axisY1, series1);

 // chart->createDefaultAxes(); //建立默认坐标轴，不需要QValueAxis
 //  chart->axisY()->setRange(0, 10);//默认坐标轴限定范围

    chartView1->show();
    chartView1->setChart(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);//防止图形走样
    //在ui里面添加了一个Widget并把曲线图添加进去
    layout->addWidget(chartView1,0,0);

}
//动态曲线图
void Widget::bulidChart2()
{
    QSplineSeries* series2 = new QSplineSeries;
    QSplineSeries* series3 = new QSplineSeries;
    QSplineSeries* series4 = new QSplineSeries;
    chart2->addAxis(axisX2, Qt::AlignBottom); //下：Qt::AlignBottom  上：Qt::AlignTop
    chart2->addAxis(axisY2, Qt::AlignLeft);   //左：Qt::AlignLeft    右：Qt::AlignRight
    //创建数据源
    series2->setPen(QPen(Qt::red,1,Qt::SolidLine));//设置曲线显示效果
    series3->setPen(QPen(Qt::blue,1,Qt::SolidLine));//设置曲线显示效果
    series4->setPen(QPen(Qt::red,2,Qt::DashLine));//设置曲线显示效果
    for(double x = 0;x <10 ;x+=0.1)
    {
        series2->append(x,5*sin(x));
        series3->append(x,9*sin(x));
    }
    //笛卡尔曲线
    for(double t = 0; t <=2*M_PI;t+=0.01)
    {
        double x=3*(2*sin(t)+sin(2*t));
        double y=3*(2*cos(t)+cos(2*t));

        series4->append(x,y);
    }

    chart2->setTitle("正弦曲线图实例2");
    chart2->setAnimationOptions(QChart::SeriesAnimations);//设置曲线动画模式
    chart2->legend()->hide(); //隐藏图例
    chart2->addSeries(series2);//输入数据
    chart2->addSeries(series3);//输入数据
    chart2->addSeries(series4);//输入数据

    chart2->setAxisX(axisX2, series2);
    chart2->setAxisY(axisY2, series2);

    chart2->setAxisX(axisX2, series3);
    chart2->setAxisY(axisY2, series3);

    chart2->setAxisX(axisX2, series4);
    chart2->setAxisY(axisY2, series4);
 // chart->createDefaultAxes(); //建立默认坐标轴，不需要QValueAxis
 //  chart->axisY()->setRange(0, 10);//默认坐标轴限定范围

    chartView2->show();
    chartView2->setChart(chart2);
    chartView2->setRenderHint(QPainter::Antialiasing);//防止图形走样
    //在ui里面添加了一个Widget并把曲线图添加进去
    layout->addWidget(chartView2,0,1);
}
