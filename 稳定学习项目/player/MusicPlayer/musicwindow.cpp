#include "musicwindow.h"
#include "ui_musicwindow.h"
#include <QMovie>
#include <QDebug>
#include "networkmusic.h"
#include "musicplayer.h"
#include <QTime>
#include <QTextBlock>
#include <QGraphicsEllipseItem>
#include "musicitem.h"

MusicWindow::MusicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    initTableWidget(ui->networkMusicTable);

    ui->lyricTextEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));

    QPalette palette = ui->lyricTextEdit->palette();
    palette.setColor(QPalette::Highlight,QColor(Qt::transparent));
    palette.setColor(QPalette::HighlightedText,QColor(Qt::red));
    ui->lyricTextEdit->setPalette(palette);

    QMovie *movie = new QMovie(":/images/loading.gif");
    ui->loadingLabel->setMovie(movie);
    movie->start();
    ui->loadingLabel->hide();


    NetworkMusic *networkMusic = new NetworkMusic;
    connect(this,SIGNAL(searchMusic(QString)),networkMusic,SIGNAL(searchMusic(QString)));
    connect(networkMusic,SIGNAL(musicReady(MusicInformation)),this,SLOT(displayMusic(MusicInformation)));

    musicPlayer = new MusicPlayer;
    connect(this,SIGNAL(playMusic(QString,QString)),musicPlayer,SLOT(playMusic(QString,QString)));
    connect(musicPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(updateCurrentTime(qint64)));
    connect(musicPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateTotalTime(qint64)));
    connect(musicPlayer,SIGNAL(displayLyric(QString)),this,SLOT(updateMusicLyric(QString)));
    connect(musicPlayer,SIGNAL(updatePlayLyric(int)),this,SLOT(updatePlayLyric(int)));


    scene = new QGraphicsScene;
    int width = ui->graphicsView->width();
    int height= ui->graphicsView->height();
    scene->setSceneRect(QRect(-width/2,-height/2,width,height));
    ui->graphicsView->setScene(scene);

    MusicItem *disk = new MusicItem(":/images/defaultDisk.png");
    disk->setPos(0,0);
    disk->setFlags(QGraphicsItem::ItemIsMovable);
    scene->addItem(disk);
    disk->startRotationAnimation(5000,0,360,-1);

    MusicItem *needle = new MusicItem(":/images/magnetNeedle.png");
    int pos_x = -width/2  + needle->boundingRect().width()/2;
    int pos_y = -height/2 + needle->boundingRect().height()/2;
    needle->setPos(pos_x,pos_y);
    scene->addItem(needle);

    needle->setFlags(QGraphicsItem::ItemIsMovable);
    float needleWidth = needle->boundingRect().width();
    float needleHeight= needle->boundingRect().height();
    float originPointX = needle->boundingRect().topLeft().x() + needleWidth /7;
    float originPointY = needleHeight/2;
    needle->setTransformOriginPoint(originPointX,originPointY);
    needle->startRotationAnimation(2000,0,15,-1);

}

MusicWindow::~MusicWindow()
{
    delete ui;
}

void MusicWindow::initTableWidget(QTableWidget *tableWidget)
{
    tableWidget->horizontalHeader()->setFixedHeight(25);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setHighlightSections(false);
    tableWidget->verticalHeader()->hide();
    tableWidget->setColumnHidden(0,true);
    tableWidget->setColumnHidden(1,true);
}

void MusicWindow::on_searchLineEdit_returnPressed()
{
    ui->networkMusicTable->clearContents();
    ui->networkMusicTable->setRowCount(0);
    ui->loadingLabel->show();

    QString music = ui->searchLineEdit->text();
    emit searchMusic(music);

    return;
}

void MusicWindow::displayMusic(const MusicInformation &music)
{
    ui->loadingLabel->hide();
    int line = ui->networkMusicTable->rowCount();
    ui->networkMusicTable->insertRow(line);
    ui->networkMusicTable->setItem(line,0,new QTableWidgetItem(QString::number(music.getId())));
    ui->networkMusicTable->setItem(line,1,new QTableWidgetItem(music.getPicid()));
    ui->networkMusicTable->setItem(line,2,new QTableWidgetItem(music.getName()));
    ui->networkMusicTable->setItem(line,3,new QTableWidgetItem(music.getArtist()));
    ui->networkMusicTable->setItem(line,4,new QTableWidgetItem(music.getAlbum()));
}

void MusicWindow::on_networkMusicTable_cellDoubleClicked(int row, int column)
{
   Q_UNUSED(column);
   QString musicId = ui->networkMusicTable->item(row,0)->text();
   QString picId   = ui->networkMusicTable->item(row,1)->text();
   emit playMusic(musicId,picId);
   ui->pushButton_3->setStyleSheet("border-image: url(:/images/playButton.png);");
}

void MusicWindow::updateCurrentTime(qint64 position)
{
    QTime time = QTime::fromMSecsSinceStartOfDay(position);
    ui->currentTimeLabel->setText(time.toString("mm:ss"));
    ui->horizontalSlider->setValue(position);

}

void MusicWindow::updateTotalTime(qint64 duration)
{
     QTime time = QTime::fromMSecsSinceStartOfDay(duration);
     ui->totalTimeLabel->setText(time.toString("mm:ss"));
     ui->horizontalSlider->setMaximum(duration);
}

void MusicWindow::updateMusicLyric(const QString &lyricText)
{
    ui->lyricTextEdit->clear();
    ui->lyricTextEdit->insertPlainText(lyricText);

    QTextDocument *doc =  ui->lyricTextEdit->document();
    QTextCursor textcursor = ui->lyricTextEdit->textCursor();
    for(QTextBlock it = doc->begin(); it !=doc->end();it = it.next())
    {
        QTextBlockFormat tbf = it.blockFormat();
        tbf.setLineHeight(6,QTextBlockFormat::LineDistanceHeight);
        textcursor.setPosition(it.position());
        textcursor.setBlockFormat(tbf);
        ui->lyricTextEdit->setTextCursor(textcursor);
    }
}

void MusicWindow::updatePlayLyric(int line)
{
    QTextCursor tc2 = ui->lyricTextEdit->textCursor();
    int pos2 = ui->lyricTextEdit->document()->findBlockByLineNumber(line).position();
    tc2.setPosition(pos2,QTextCursor::MoveAnchor);
    tc2.movePosition(QTextCursor::EndOfLine,QTextCursor::KeepAnchor);
    ui->lyricTextEdit->setTextCursor(tc2);
}

void MusicWindow::on_pushButton_3_clicked(bool checked)
{
    if(checked){
      musicPlayer->pause();
      ui->pushButton_3->setStyleSheet("border-image: url(:/images/originalPlayButton.png);");
    }else{
      musicPlayer->play();
      ui->pushButton_3->setStyleSheet("border-image: url(:/images/playButton.png);");
    }

    return;
}

void MusicWindow::on_horizontalSlider_sliderMoved(int position)
{
    if(musicPlayer->mediaStatus() == QMediaPlayer::EndOfMedia){
       musicPlayer->play();
    }
    musicPlayer->setPosition(position);

    return;
}
