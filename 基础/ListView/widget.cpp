#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    initBtn();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
//    QStringList strlist;
//    strlist << "A" << "B" << "C" << "D" ;
//    Model = new QStringListModel(strlist);
//    ui->listView->setModel(Model);

    ItemModel = new QStandardItemModel(this);
    QString strList;
    strList.append("A");
    strList.append("B");
    strList.append("C");
    strList.append("D");

    int nCout = strList.size();
    for(int i = 0;i < nCout; i++)
    {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    ui->listView->setModel(ItemModel);
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));

}

void Widget::initBtn()
{
    ItemModel = new QStandardItemModel(this);

    strList.append("事件1");
    strList.append("事件2");
    strList.append("事件3");
    strList.append("事件4");

    for(int i = 0; i < 4; i++ )
    {
        QStandardItem *item = new QStandardItem(Type2String(i));
        ItemModel->appendRow(item);
    }

    ui->listView_2->setModel(ItemModel);
}

QString Widget::Type2String(int n)
{
    return strList[n];
}

void Widget::showClick(QModelIndex index)
{
    QString strTemp;
    strTemp = index.data().toString();
    QMessageBox msg;
    msg.setText(strTemp);
    msg.exec();
}
