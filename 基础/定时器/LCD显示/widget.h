#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnStart_clicked();
    void upDate();
    void on_btnStop_clicked();

    void on_btnRestart_clicked();

private:
    Ui::Widget *ui;
    QTimer *mTimer;
};



#endif // WIDGET_H
