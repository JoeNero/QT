#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QPainter>
#include <QList>

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

private:
    Ui::Widget *ui;
    QList<double> data; //存储数据
    QChart *chart;
    QChartView *chartView;
};



#endif // WIDGET_H
