#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QGridLayout>
#include <QSplineSeries>
#include <QLineSeries>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

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
//    void timerEvent(QTimerEvent *event);
private slots:
//    double createData(double time);
private:
    Ui::Widget *ui;
    QGridLayout *layout;

    QChart *chart1;
    QChartView *chartView1;
    QValueAxis *axisX1;
    QValueAxis *axisY1;

    QChart *chart2;
    QChartView *chartView2;
    QValueAxis *axisX2;
    QValueAxis *axisY2;

    QSplineSeries *series1;

    QTimer *mTimer;
    void initAxis1();
    void initAxis2();
    void bulidChart1();
    void bulidChart2();
};



#endif // WIDGET_H
