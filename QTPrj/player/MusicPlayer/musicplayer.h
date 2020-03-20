#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include "http.h"
#include "analysisjson.h"
#include <QList>

class MusicPlayer:public QMediaPlayer
{
    Q_OBJECT

public:
    MusicPlayer();
    void processLyric(const QString &lyricText);
    void processLineLyric(QString &lineLyric);

signals:
    void displayLyric(const QString &lyricText);
    void updatePlayLyric(int line);
    void updatePicture();

public slots:
    void playMusic(const QString &musicId,const QString &picId);
    void startPlayMusic(void);
    void startDisplayLyric(void);
    void startDownloadPic(void);
    void findLyricLineNumber(qint64 position);

private:
    Http *mp3Http;
    Http *lyricHttp;
    Http *picUrlHttp;
    Http *downloadPic;
    AnalysisJson *mp3Analysis;
    AnalysisJson *lyricAnalysis;
    AnalysisJson *picurlAnalysis;
    QString lyricText;
    QList<qint64> timeList;

};

#endif // MUSICPLAYER_H
