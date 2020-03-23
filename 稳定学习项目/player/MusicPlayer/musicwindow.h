#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QMainWindow>
#include "musicinformation.h"
#include <QTableWidget>
#include "musicplayer.h"
#include <QGraphicsScene>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicWindow(QWidget *parent = 0);
    ~MusicWindow();
    void initTableWidget(QTableWidget *tableWidget);

signals:
    void searchMusic(const QString &music);
    void playMusic(const QString &musicId,const QString &picId);

private slots:
    void on_searchLineEdit_returnPressed();
    void displayMusic(const MusicInformation &music);
    void on_networkMusicTable_cellDoubleClicked(int row, int column);
    void updateCurrentTime(qint64 position);
    void updateTotalTime(qint64 duration);
    void updateMusicLyric(const QString &lyricText);
    void updatePlayLyric(int line);

    void on_pushButton_3_clicked(bool checked);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MusicWindow *ui;
    MusicPlayer *musicPlayer;
    QGraphicsScene *scene;
};

#endif // MUSICWINDOW_H
