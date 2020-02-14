#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
//回到主界面,发射自定义信号
void Form::on_pushButton_clicked()
{
    emit MySignal();
}
