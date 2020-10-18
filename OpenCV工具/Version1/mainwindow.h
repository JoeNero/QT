#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QFile>
#include <QString>
#include <opencv.hpp>
#include <QFileDialog>
#include <QTextEdit>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/videoio/videoio_c.h>

using namespace cv;
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateImage();
    void on_btnBreak_clicked();

private slots:
    void on_btnOpen_clicked();

private:
    Ui::MainWindow *ui;
    QTimer Timer;
    Mat srcImg;
    VideoCapture videoCap;
    QString fileName;			//文件名字

    string s;
    int width = 0;
    int height = 0;
    long totalFrameNumber = 0;
    double rate = 0;
};
#endif // MAINWINDOW_H
