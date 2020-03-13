#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void dealSignal();
    void dealClose();

private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

signals:
    void startThread();     //启动子线程信号

private:
    Ui::Widget *ui;

    MyThread *myT;
    QThread *thread;
};

#endif // WIDGET_H
