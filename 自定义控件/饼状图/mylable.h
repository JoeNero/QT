#ifndef MYLABLE_H
#define MYLABLE_H

#include <QWidget>
#include <QLabel>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QString>
#include <QSlider>

QT_CHARTS_USE_NAMESPACE

class MyLable : public QWidget
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = nullptr);
    const QString s1 = "数据A";
    const QString s2 = "数据B";

    /*拉bar1*/
    QLabel *label1;
    QSlider *slider1;
    QSpinBox *spin1;
    /*拉bar2*/
    QLabel *label2;
    QSlider *slider2;
    QSpinBox *spin2;

    QPieSlice *slice_1;
    QPieSlice *slice_2;
protected:

signals:
public slots:
private:
    //默认值
    const int defalutSpin1 = 50;
    const int defalutSpin2 = 50;
    const int defalutSlider1 = 50;
    const int defalutSlider2 = 50;
    QLabel* disp;
};

#endif // MYLABLE_H
