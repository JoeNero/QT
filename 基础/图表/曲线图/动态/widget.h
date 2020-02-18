#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QSplineSeries>
#include <QScatterSeries>
#include "qmath.h"

using namespace QtCharts;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void timerEvent(QTimerEvent *event)Q_DECL_OVERRIDE;
private:
    Ui::Widget *ui;
    void dataRec(int value);
    int timerId;
    int maxSize;        //data最多存储maxSize个元素
    int maxX;
    int maxY;
    QList<double> data; //存储数据
    QChart *chart;
    QChartView *chartView;
    QSplineSeries *splineSeries;
    QScatterSeries *scatterSeries;
    QSplineSeries *sinline;
};



#endif // WIDGET_H
