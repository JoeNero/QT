#ifndef MYQMEDIACONTENT_H
#define MYQMEDIACONTENT_H

#include <QMediaContent>


class Lyric
{
  public:
    int time;
    QString lyric;
};

class MyQMediaContent : public QMediaContent
{
public:
    MyQMediaContent(const QUrl &url);

    QString hash;
    QString album_id;

    QString author_name;
    QString song_name;
    QString album_name;
    QString music_url;
    QString img_url;
    int have_mv;
    int time_length;
    int file_size;

};

#endif // MYQMEDIACONTENT_H
