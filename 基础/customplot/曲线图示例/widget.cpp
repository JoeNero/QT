#include "widget.h"
#include "ui_widget.h"
#include "qcustomplot.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QCustomPlot *customPlot = ui->widget;
    customPlot->legend->setVisible(true);                     //图例 显示
    customPlot->legend->setFont(QFont("Helvetica",9));        //图例 字体
    QPen pen;                 //画笔
    QStringList lineNames;    //图例中曲线名字链表
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    // add graphs with different line styles:（增加曲线，并设置相应的样式）
    for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
    {
      customPlot->addGraph();        //增加曲线
      pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));                                //给pen设置新颜色
      customPlot->graph()->setPen(pen);      //给曲线增加pen
      customPlot->graph()->setName(lineNames[i]);                    //图例名字
      customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);     //曲线样式
      customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));    //曲线上点的样式

      // generate data:(生成曲线)
      QVector<double> x(15), y(15);
      for (int j=0; j<15; ++j)
      {
        x[j] = j/15.0 * 5*3.14 + 0.01;
        y[j] = 7*qSin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
      }
      customPlot->graph()->setData(x, y);
      customPlot->graph()->rescaleAxes(true);
    }
    // zoom out a bit:
    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
    // set blank axis lines:
    customPlot->xAxis->setTicks(false);
    customPlot->yAxis->setTicks(true);
    customPlot->xAxis->setTickLabels(false);
    customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    customPlot->axisRect()->setupFullAxesBox();
}

Widget::~Widget()
{
    delete ui;
}
