#ifndef WIDGET_H
#define WIDGET_H

#include <ctime>

#include <Qfile>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QWidget>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QListWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QSlider>

#include <QRegularExpression>

#include <QSize>
#include <QList>

#include "myitem.h"
#include "myqmediacontent.h"

#define COOKIE "kg_mid=389132ff84b0c9f94970079c3ca8861d; Hm_lvt_aedee6983d4cfc62f509129360d6bb3d=1573038798; kg_dfid=3du7U529UMkR0TePsq37aEzw; kg_dfid_collect=d41d8cd98f00b204e9800998ecf8427e; kg_mid_temp=389132ff84b0c9f94970079c3ca8861d; Hm_lpvt_aedee6983d4cfc62f509129360d6bb3d=1573039620"
#define PLAYURL "https://wwwapi.kugou.com/yy/index.php?r=play/getdata&hash=%1&album_id=%2"
#define SEARCHURL "http://songsearch.kugou.com/song_search_v2?keyword=%1&page=%2&pagesize=10"

namespace Ui {
class Widget;
}


//typedef struct{
//    QString hash;
//    QString album_id;

//    QString img_url;
//    QString author_name;
//    QString song_name;
//    QString lyrics;
//    QString play_url;
//    QString album_name;
//    int have_mv;
//    int time_length;
//    int file_size;
//} info;

class Music_Info
{
public:

    QString hash;
    QString album_id;

    QString img_url;
    QString author_name;
    QString song_name;
    QString lyrics;
    QString play_url;
    QString album_name;
    int have_mv;
    int time_length;
    int file_size;

};

class Widget : public QWidget
{
    Q_OBJECT

signals:
    void requestFinshed(int);
    void createListFinish();
    void requestLyric();
    void tosearch();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_search_btn_clicked();

    void httpReply(QNetworkReply *reply);
    void httpReplyMusicInfo(QNetworkReply *);
    void httpReplyLyrics(QNetworkReply *);
    void httpReplyImg(QNetworkReply *);
    void createMusicList(int);
    void playMusic(QListWidgetItem*);
    void funcDoubleClick(QListWidgetItem*);
    void showList();
    void nextPage();
    void previousPage();
    void palyBtn();
    void addBtn();
    void musicChanged(QMediaContent);
    void musicPositionChanged(qint64);
    void progressMoved(int);
    void palyTimeChanged(int);
    void musicStatusChange();
    void musicStatusChanged();
    void nextSong();
    void proviousSong();
    void voiceChange(int value);
    void modeChange();
    void numPage();
    void lyricShow();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Widget *ui;
    QNetworkRequest *request, *request_music, *request_lyrics;
    QNetworkAccessManager *manager, *manager_music, *manager_lyrics;
    QNetworkAccessManager *manager_img;
    QNetworkRequest *request_img;

    QString play_url;
    QString search_url;

    QListWidgetItem *music_hall, *video, *local;
    QListWidgetItem *label_item;
    QWidget *label_widget;
    QHBoxLayout *info_layout;

    QLabel *music, *author, *special, *paly_time, *bgm;

    MyItem *bt;
    LyricItem *lyric_item[7];
    MyPageItem *pt;
    MyItem *music_item[10];
    Music_Info *music_info[10];

    QMediaPlayer *player;
    QMediaPlaylist *play_list;
    QList<MyQMediaContent> music_list;
    QList<Lyric> lyric_list;

    int page_size;
    int page;
    int count;
    int total_time;

    QSlider *progress_slider, *voice;
    QLabel *music_name, *time_ratio, *music_img;
    QPushButton *paly_mode, *provious_song, *paly_song, *next_song, *paly_list, *islyric;
    QHBoxLayout *paly_layout;
    QVBoxLayout *slider_layout;
    QHBoxLayout *lyirc_widget;

    QPixmap *pm;

private:
    void initPage();
    void initData();
    void palyListAddMusic(int i);
    void resizeEvent(QResizeEvent *event);

};

#endif // WIDGET_H
