#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QTextCodec>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();//打印qt支持的数据库类型
        setWindowTitle("SQL");//设置窗口的标题

        QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//设置显示中文

        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("test");
//        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("123456");


        if(!db.open()) //如果数据库打开失败，会弹出一个警告窗口
        {
            QMessageBox::warning(this, "警告", "数据库打开失败");
        }
        else
        {
            ui->textEdit->setText("数据库打开成功");
        }

//            QString str = "create table student(num int, name varchar(32), score double);";
//            QSqlQuery query;
//            query.exec(str);
}

Widget::~Widget()
{
    delete ui;
}

//插入信息到数据库
void Widget::on_BtnInsert_clicked()
{
    //获取名字，学号，分数信息
    QString nameStr = ui->lineEditName->text();
    int num = ui->lineEditNum->text().toInt();
    double score = ui->lineEditScore->text().toDouble();
    if((nameStr == NULL )||(0 == num)||(ui->lineEditScore == NULL))
    {
        ui->textEdit->setText("请输入完整的信息");
    }
    else
    {
        QString str = QString("insert into student(num, name, score) value('%1', '%2', '%3')").arg(num).arg(nameStr).arg(score);
        QSqlQuery query;
        query.exec(str);
        ui->lineEditName->clear();
        ui->lineEditNum->clear();
        ui->lineEditScore->clear();
        ui->textEdit->setText("插入成功");
    }
}

//删除数据库中的信息
void Widget::on_BtnDelete_clicked()
{
    QString name = ui->lineEditName->text();//从行编辑框中获取需要删除的人名
    if(NULL == name)
    {
        ui->textEdit->setText("请输入需要删除的人和名字");
    }
    else
    {
        //先查询数据库中是否存在这个人
        QString temp = QString("select * from student where name = '%1'").arg(name);
        QSqlQuery query;
        query.exec(temp);
        QString deleteName;
        while(query.next())
        {
            deleteName = query.value(1).toString();
        }
        if(deleteName == NULL)
        {
            QString a = QString("没有叫%1的人，删除失败").arg(name);
            ui->textEdit->setText(a);
            ui->lineEditName->clear();
            ui->lineEditNum->clear();
            ui->lineEditScore->clear();
        }
        else
        {
            QString str =  QString("delete from student where name = '%1'").arg(name);
            query.exec(str);    //删除信息
            ui->lineEditName->clear();
            ui->lineEditNum->clear();
            ui->lineEditScore->clear();
            ui->textEdit->setText("删除成功");
        }

    }
}

//修改数据库中的内容
void Widget::on_BtnChange_clicked()
{
    //从界面获取我们需要的信息
    QString updatename = ui->lineEditName->text();
    int number = ui->lineEditNum->text().toInt();
    double score = ui->lineEditScore->text().toDouble();
    if((updatename == NULL)||(number == 0)||(ui->lineEditScore->text() == NULL))
    {
        ui->textEdit->setText("请输入需要修改的人学号,姓名以及成绩");
    }
    else
    {
        QString temp = QString("select *from student where name ='%1'").arg(updatename);
        QSqlQuery query;
        query.exec(temp);//查询信息
        QString a;
        while(query.next())
        {
            a = query.value(1).toString();
        }

        if(a == NULL)
        {
            QString b = QString("没有名叫%1的人,修改失败").arg(updatename);
            ui->textEdit->setText(b);
            ui->lineEditName->clear();
            ui->lineEditNum->clear();
            ui->lineEditScore->clear();
        }
        else
        {
            QString temp = QString("update student set num = '%1' , score = '%2' where name = '%3'").arg(number).arg(score).arg(updatename);
            query.exec(temp);//执行修改信息的操作
            ui->textEdit->setText("修改成功");
            ui->lineEditName->clear();
            ui->lineEditNum->clear();
            ui->lineEditScore->clear();
        }
    }


}

//查询数据库的信息
void Widget::on_BtnRead_clicked()
{
    QString searchname = ui->lineEditName->text();
    if(NULL == searchname)
    {
        ui->textEdit->setText("请输入需要查询的人名");
    }
    else
    {
        QString str = QString("select *from student where name = '%1'").arg(searchname);
        QSqlQuery query;
        query.exec(str);
        QString name;
        int number;
        double score;

        while (query.next())
        {
            number = query.value(0).toInt();
            name = query.value(1).toString();
            score =  query.value(2).toDouble();
        }
        if(NULL == name)
        {
            QString a = QString("没有叫%1的人,请重新输入人名").arg(searchname);
            ui->textEdit->setText(a);
            ui->lineEditName->clear();
            ui->lineEditNum->clear();
            ui->lineEditScore->clear();
        }
        else
        {
            ui->lineEditName->setText(name);
            ui->lineEditNum->setText(QString().setNum(number));
            ui->lineEditScore->setText(QString().setNum(score));
            ui->textEdit->setText("查询成功");
        }
    }
}

//查询数据库的所有信息
void Widget::on_BtnAll_clicked()
{
    QString name[100];//用来存储从数据库中找出来的信息
     int number[100];
     double score[100];
     int i = 0;
     QSqlQuery query;
     query.exec("select * from student");//查询所有的信息
     while(query.next())
     {
         number[i] = query.value(0).toInt();
         name[i] = query.value(1).toString();
         score[i] = query.value(2).toDouble();
         i++;
     }
     ui->textEdit->clear();
     int j = 0;
     for(j = 0; j < i; j++)//将这些信息都显示在下方的文本编辑框中
     {
         QString str = QString("学号：%1   姓名：%2  成绩：%3").arg(number[j]).arg(name[j]).arg(score[j]);
         ui->textEdit->append(str);
     }
}
