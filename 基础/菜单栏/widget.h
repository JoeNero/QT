#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QTextEdit>
#include <QStatusBar>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:

public slots:

private slots:
    void fileSave();            //文件保存
    void fileArrayOpen();
    void fileOpen();            //文件打开

private:
    Ui::Widget *ui;

    QTextEdit *textEdit;        //写入的文本框
    QStatusBar *sBar;           //状态栏
    QLabel *label;              //状态栏第一个标签
};

#endif // WIDGET_H
