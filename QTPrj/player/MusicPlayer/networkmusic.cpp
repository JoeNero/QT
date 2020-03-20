#include "networkmusic.h"
#include "musicinformation.h"
#include <QDebug>

NetworkMusic::NetworkMusic(QObject *parent) : QObject(parent)
{
    http = new Http("music.json");
    connect(this,SIGNAL(searchMusic(QString)),http,SLOT(searchMusic(QString)));
    connect(http,SIGNAL(finishedSearchMusic()),this,SLOT(analysisNetworkMusic()));

    analysis = new AnalysisJson("music.json");
}

void NetworkMusic::analysisNetworkMusic()
{
    QList<MusicInformation> musicList = analysis->analysisMusic();

    for(int i = 0;i < musicList.size();i ++){
       emit musicReady(musicList[i]);
    }

    return;
}
