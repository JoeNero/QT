#include "musicplayer.h"
#include "QDebug"

MusicPlayer::MusicPlayer()
{
    mp3Http = new Http("mp3.json");
    connect(mp3Http,SIGNAL(finishedSearchMp3Url()),this,SLOT(startPlayMusic()));

    lyricHttp = new Http("lyric.json");
    connect(lyricHttp,SIGNAL(finishedSearchLyric()),this,SLOT(startDisplayLyric()));

    picUrlHttp = new Http("pic.json");
    connect(picUrlHttp,SIGNAL(finishedSearchPicUrl()),this,SLOT(startDownloadPic()));

    downloadPic = new Http("music.jpg");
    connect(downloadPic,SIGNAL(finishedDownloadPicture()),this,SIGNAL(updatePicture()));

    mp3Analysis   = new AnalysisJson("mp3.json");
    lyricAnalysis = new AnalysisJson("lyric.json");
    picurlAnalysis= new AnalysisJson("pic.json");

    connect(this,SIGNAL(positionChanged(qint64)),this,SLOT(findLyricLineNumber(qint64)));
    this->setNotifyInterval(500);
}

void MusicPlayer::processLyric(const QString &lyricText)
{
    QStringList lyricList = lyricText.split('\n');
    for(int i = 0;i < lyricList.size();i ++){
        processLineLyric(lyricList[i]);
    }

    return;
}

void MusicPlayer::processLineLyric(QString &lineLyric)
{
    if(lineLyric.isEmpty()){
        return;
    }

    lineLyric.remove('[');
    QStringList list  = lineLyric.split(']');
    QString timeString  =  list[0];
    QString lyric       =  list[1];
    lyric.remove(' ');
    if(timeString.isEmpty() || lyric.isEmpty()){
        return;
    }

    QTime time = QTime::fromString(timeString,"m:s.z");
    qint64 milliseconds = time.minute() * 60 * 1000 + time.second()*1000 +  time.msec();

    timeList << milliseconds;
    this->lyricText = this->lyricText + lyric + "\n";

    return;
}

void MusicPlayer::playMusic(const QString &musicId, const QString &picId)
{
    mp3Http->searchMp3Url(musicId);
    lyricHttp->searchLyric(musicId);
    picUrlHttp->searchPictureUrl(picId);
}

void MusicPlayer::startPlayMusic()
{
   QString mp3Url =  mp3Analysis->analysisMp3Url();
   this->setMedia(QMediaContent(mp3Url));
   this->setVolume(100);
   this->play();
}

void MusicPlayer::startDisplayLyric()
{
   this->lyricText.clear();
   this->timeList.clear();

   QString lyricText = lyricAnalysis->analysisLyric();
   processLyric(lyricText);

   emit displayLyric(this->lyricText);

   return;
}

void MusicPlayer::startDownloadPic()
{
    QString picurl = picurlAnalysis->analysisPicUrl();
    downloadPic->downloadPicture(picurl);
}

void MusicPlayer::findLyricLineNumber(qint64 position)
{
    int i;

    for(i = 0;i < timeList.size();i ++){
        if(timeList[i] > position){
            break;
        }
    }

    emit updatePlayLyric(i - 1);
}
