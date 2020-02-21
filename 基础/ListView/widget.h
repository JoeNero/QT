#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
    void init();
    void initBtn();
    QString Type2String(int);


private slots:
    void showClick(QModelIndex index);

private:
    Ui::Widget *ui;
    QStringList strList;
};

#endif // WIDGET_H
