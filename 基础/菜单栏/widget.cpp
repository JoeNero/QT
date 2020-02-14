#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QToolBar>
#include <QDockWidget>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Test1界面测试");
    QMenuBar *mBar = menuBar();
//添加菜单
    QMenu *pFile        =   mBar->addMenu("文件");
    QMenu *pEdit        =   mBar->addMenu("编辑");
    QMenu *pSearch      =   mBar->addMenu("搜索");
    QMenu *pView        =   mBar->addMenu("视图");
    QMenu *pCode        =   mBar->addMenu("编码");
    QMenu *pDialogBox   =   mBar->addMenu("对话框");

    QAction *pNew   = pFile->addAction("新建");
    connect(pNew,&QAction::triggered,
            [=]()
    {
            qDebug() << "New";
    });
    pFile->addSeparator();  //添加分割线
    QAction *pOpen  = pFile->addAction("打开");
    connect(pOpen,&QAction::triggered,
            [=]()
    {
           fileOpen();
    });

    QAction *pSave  = pFile->addAction("保存");
    connect(pSave,&QAction::triggered,
            [=]()
    {
            fileSave();
    });
    //工具栏,菜单栏快捷方式
        QToolBar *toolBar = addToolBar("toolBar");
    //工具栏添加快捷键
        toolBar->addAction(pNew);
        toolBar->addAction(pSave);
    //工具栏添加小控件
        QPushButton *b = new QPushButton(this);
          b->setText("数据流打开");
          //添加小控件
          toolBar->addWidget(b);
          connect(b, &QPushButton::clicked,
                  [=]()
                  {
              fileArrayOpen();//数据流打开
//                      b->setText("123");
                  }
          );
      //状态栏
          sBar = statusBar();
          label = new QLabel(this);
          label->setText("Normal text file");
      //从左往右添加
      sBar->addWidget(label);
      sBar->addWidget(new QLabel("2",this));

      //从右往左
      sBar->addPermanentWidget(new QLabel("3",this));

      //核心控件
      textEdit = new QTextEdit(this);
      setCentralWidget(textEdit);

      //浮动窗口
       QDockWidget *dock = new QDockWidget;
       addDockWidget(Qt::RightDockWidgetArea,dock);
       QTextEdit *textEdit1 = new QTextEdit(this);
       dock->setWidget(textEdit1);

       //对话框下的动作添加
       QAction *p1   = pDialogBox->addAction("静态对话框");
       QAction *p2   = pDialogBox->addAction("动态对话框");
       QAction *p3   = pDialogBox->addAction("关于对话框");
       QAction *p4   = pDialogBox->addAction("问题对话框");
       QAction *p5   = pDialogBox->addAction("文件对话框");
       //静态对话框
       connect(p1, &QAction::triggered,
               [=]()
               {
                   QDialog dlg1;
                   dlg1.resize(100,80);
                   dlg1.exec();
                   qDebug() << "1";
               }
               );
       //关于对话框
       connect(p2, &QAction::triggered,
               [=]()
               {
                   QDialog *p = new QDialog;
                   p->setAttribute(Qt::WA_DeleteOnClose);
                   p->resize(100,80);
                   p->show();
                   qDebug() << "2";

               }
               );
       //关于对话框
       connect(p3, &QAction::triggered,
               [=]()
               {
                   QMessageBox::about(this,"about","关于qt");
               }
               );
       //问题对话框
       connect(p4, &QAction::triggered,
               [=]()
               {
                  int ret = QMessageBox::question(this,"question","are you ok?",
                                                  QMessageBox::Ok|QMessageBox::Cancel);
                  switch (ret) {
                  case QMessageBox::Ok:
                           qDebug() << "Yes!";
                      break;
                  case QMessageBox::Cancel:
                           qDebug() << "No!";
                      break;
                  default:
                      break;
                  }
               }
               );
       //文件对话框
       connect(p5, &QAction::triggered,
               [=]()
               {
                   QString path=QFileDialog::getOpenFileName(
                               this,
                               "open",
                               "../",
                               "souce(*.cpp *.h);;"
                               "Text(*.txt);;"
                               "all(*.*)"
                               );
                   qDebug() << path;
               }
               );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::fileSave()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../",  "(*.txt);;"
                                                                     "(*.cpp);;"
                                                                     "(*.h)");
     if(path.isEmpty() == false)
     {
         QFile file;                 //创建文件对象
         file.setFileName(path);     //关联文件名字
         //打开文件，只写方式
         bool isOk = file.open(QIODevice::WriteOnly);
         if(isOk == true)
         {
             //获取编辑区内容
             QString str = textEdit->toPlainText();
             //写文件
             //file.write(str.toUtf8());
             //file.write(str.toStdString().data());

             file.write(str.toLocal8Bit());

             //QString->QByteArrays
             QString buf = "123";
             QByteArray a = buf.toUtf8();    //中文
             a = buf.toLocal8Bit();  //转换成本地编码

             //QByteArray->char*
 //            char *b = a.data();

 //            //char* ->QString
 //            char *p = "abc";
 //            QString c = QString(p);

         }
         file.close();

         //获取文件信息
         QFileInfo info(path);
         qDebug() << "文件名字" << info.fileName().toUtf8().data();
         qDebug() << "文件后缀" << info.suffix();
         qDebug() << "文件大小" << info.size();
         qDebug() << "文件创建时间" << info.created().toString("yyyy-MM-dd hh:mm:ss");//2020-1-16
     }
}

void Widget::fileArrayOpen()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","all(*.*);;"
                                                                   "source(*.cpp *.h);;"
                                                                   "txt(*.txt)");
     if(path.isEmpty() == false)
     {
         //文件对象
         QFile file(path);

         //打开文件,只读方式打开
         bool isOke = file.open(QIODevice::ReadOnly);
         if(isOke == true)
         {

          QByteArray array;
          while (file.atEnd() == false)
          {
              //读一行
              array += file.readLine();
          }
 #if 0
             //读文件,默认只识别utf8编码
             QByteArray array = file.readAll();
             //显示到编辑区
            // ui->textEdit->setText(QString(array));
  #endif
             textEdit->setText(array);
             label->setText("数据流打开");
         }
         //关闭文件
         file.close();
     }
}

void Widget::fileOpen()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(true == isOk)
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            QString str = stream.readAll();
            textEdit->setText(str);
            label->setText("编码方式UTF-8");        //标签状态栏显示编码方式
        }
    }
}

