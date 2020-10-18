#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QFileInfo>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    connect(&Timer, &QTimer::timeout, this, &MainWindow::updateImage);
    //cap
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnBreak_clicked()
{
//    Mat temp;
//    srcImg = imread("timg.jpeg");
//    if(srcImg.empty())
//    {

//    }
//    cvtColor(srcImg, temp, COLOR_BGR2RGB);
//    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
//    ui->imagelable->setPixmap(QPixmap::fromImage(Qtemp));

    videoCap.open(s);
    Mat frameImg;

    stringstream ss;
    int num=0;
    int numRate = 0;
    string str;
    char imagename[100];

//    QString cmd1= "rm -rf ";
//    QString cmd2= "mkdir ";
//    cmd1.append(fileName);
//    cmd2.append(fileName);
//    QByteArray c1 = cmd1.toLatin1();
//    QByteArray c2 = cmd2.toLatin1();
//    const char* A = c1.data();
//    const char* B = c2.data();
//    system(A);
//    system(B);"
        system("rm -rf out");
        system("mkdir out");
    if (!videoCap.isOpened())
    {

    }
    else
    {
        while (videoCap.read(frameImg))
        {
         ss << num;
         ss >> str;
         ++num;
         sprintf(imagename, "%s%d%s","out/image_", num,".bmp");
         numRate = num*100/totalFrameNumber ;
         imwrite(imagename, frameImg);
         ui->progressBar->setValue(numRate);
         }
    }
}

void MainWindow::updateImage()
{

}

void MainWindow::on_btnOpen_clicked()
{
    QString path = QFileDialog::getOpenFileName(
                                                this,
                                                "open",
                                                "../",
                                                "all(*.*);;"
                                                "source(*.cpp *.h);;"
                                                "txt(*.txt)");
    s = path.toStdString();
    videoCap.open(s);
    if (!videoCap.isOpened())
    {

    }
    else
    {
        QFile file(path);
        QFileInfo fileInfo(file);
        fileName =fileInfo.fileName();

        QString w ="width  =";
        QString h ="height =";
        QString frame = "frame:";
        QString fps = "avFps:";

        width = videoCap.get(CAP_PROP_FRAME_WIDTH);
        height = videoCap.get(CAP_PROP_FRAME_HEIGHT);
        totalFrameNumber = videoCap.get(CV_CAP_PROP_FRAME_COUNT);
        rate = videoCap.get(CV_CAP_PROP_FPS);

        w.append(QString::number(width));
        h.append(QString::number(height));
        frame.append(QString::number(totalFrameNumber,'g',10));
        fps.append(QString::number(rate,'g',4));

        ui->label_file->setText(fileName);
        ui->labelW->setText(w);
        ui->labelH->setText(h);
        ui->label_fps->setText(frame);
        ui->label_av->setText(fps);
    }
}
