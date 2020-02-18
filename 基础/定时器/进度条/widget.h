#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QProgressBar>
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
    void updateProgress();
    void on_btnRestart_clicked();

private:
    Ui::Widget *ui;
    QTimer *m_pTimer;
};

#endif // WIDGET_H
