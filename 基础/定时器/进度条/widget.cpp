#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pTimer = new QTimer();

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    // 设置超时间隔
    m_pTimer->setInterval(100);

    // 连接信号槽
    connect(ui->btnStart, SIGNAL(clicked(bool)), m_pTimer, SLOT(start()));
    connect(ui->btnStop, SIGNAL(clicked(bool)), m_pTimer, SLOT(stop()));
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(updateProgress()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateProgress()
{
// 获取当前进度值，+1
int nCurrentValue = ui->progressBar->value();
    nCurrentValue++;
if (nCurrentValue >= 100)
    m_pTimer->stop();

// 设置新的进度值
ui->progressBar->setValue(nCurrentValue);
}

void Widget::on_btnRestart_clicked()
{
    ui->progressBar->setValue(0);
    if(m_pTimer->isActive())
    m_pTimer->start();

}
