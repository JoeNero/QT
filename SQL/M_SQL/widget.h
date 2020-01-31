#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QSqlDatabase db;


private slots:
    void on_BtnInsert_clicked();

    void on_BtnDelete_clicked();

    void on_BtnChange_clicked();

    void on_BtnRead_clicked();

    void on_BtnAll_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
