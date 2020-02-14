#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void valueChange();
public slots:
    void chang1();
    void chang2();
private:
    Ui::Widget *ui;
    QPushButton btn1;
    QPushButton *btn2;
};

#endif // WIDGET_H
