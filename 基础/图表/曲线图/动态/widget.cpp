#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    maxSize = 31;           //只存储最新的31个数据
    maxX = 300;
    maxY = 100;
    splineSeries = new QSplineSeries();
    scatterSeries = new QScatterSeries();
    sinline = new QSplineSeries();

    scatterSeries->setMarkerSize(8);
    chart = new QChart();

    chart->addSeries(splineSeries);
    chart->addSeries(scatterSeries);
    chart->addSeries(sinline);

    chart->legend()->hide();
    chart->setTitle("实时动态曲线");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0,300);
    chart->axisY()->setRange(0,maxY);
    chartView = new QChartView(chart);

    QValueAxis *axisx = new QValueAxis;
    axisx->setGridLineVisible(false);
    axisx->setTitleText("sample time(s)");
    chartView->chart()->setAxisX(axisx,splineSeries);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->setContentsMargins(0,0,0,0);
    ui->horizontalLayout->addWidget(chartView);
    timerId = startTimer(100);
    qsrand(QDateTime::currentDateTime().toTime_t());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerId){
        int newDate = qrand()%(maxY+1);
        dataRec(newDate);
    }
}

void Widget::dataRec(int value)
{
    data << value;
    //数据个数超过最大的数量，则删除所有的数据，从头开始
    while (data.size()>maxSize) {
        data.clear();
    }
    if(isVisible()){
        splineSeries->clear();
        scatterSeries->clear();
        sinline->clear();
        int dx = maxX/(maxSize-1);
        for(int i = 0;i<data.size();++i){
            splineSeries->append(i*dx,data.at(i));
            scatterSeries->append(i*dx,data.at(i));
            sinline->append(i*dx,10*sin(i)+10);
        }
    }
}

