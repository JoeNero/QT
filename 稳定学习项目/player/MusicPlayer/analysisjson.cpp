#include "analysisjson.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

AnalysisJson::AnalysisJson(const QString &fileName, QObject *parent) : QObject(parent)
{
    this->fileName = fileName;
}

QList<MusicInformation> AnalysisJson::analysisMusic()
{
    QList<MusicInformation> musicList;
    QByteArray jsonData = readJsonFile();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&jsonError);
    if(jsonDoc.isNull() || jsonError.error != QJsonParseError::NoError){
        qDebug() << "Fail to parse json data : " << jsonError.errorString();
        return musicList;
    }


    QJsonArray jsonArray = jsonDoc.array();
    for(int i = 0;i < jsonArray.size();i ++){
        QJsonObject jsonObject = jsonArray[i].toObject();
        int id = jsonObject["id"].toInt();
        QString name = jsonObject["name"].toString();
        QJsonArray artistArray = jsonObject["artist"].toArray();
        QString artist = artistArray[0].toString();
        QString album  = jsonObject["album"].toString();
        QString picid   = jsonObject["pic_id"].toString();
        musicList.push_back(MusicInformation(id,name,artist,album,picid));
    }

    return musicList;
}

QString AnalysisJson::analysisMp3Url()
{
    QByteArray jsonData = readJsonFile();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&jsonError);
    if(jsonDoc.isNull() || jsonError.error != QJsonParseError::NoError){
        qDebug() << "Fail to parse json data : " << jsonError.errorString();
        return "";
    }
    QJsonObject jsonObject = jsonDoc.object();
    return jsonObject["url"].toString();
}

QString AnalysisJson::analysisLyric()
{
    QByteArray jsonData = readJsonFile();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&jsonError);
    if(jsonDoc.isNull() || jsonError.error != QJsonParseError::NoError){
        qDebug() << "Fail to parse json data : " << jsonError.errorString();
        return "";
    }
    QJsonObject jsonObject = jsonDoc.object();
    return jsonObject["lyric"].toString();
}

QString AnalysisJson::analysisPicUrl()
{
    QByteArray jsonData = readJsonFile();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&jsonError);
    if(jsonDoc.isNull() || jsonError.error != QJsonParseError::NoError){
        qDebug() << "Fail to parse json data : " << jsonError.errorString();
        return "";
    }
    QJsonObject jsonObject = jsonDoc.object();
    return jsonObject["url"].toString();
}

QByteArray AnalysisJson::readJsonFile()
{
    QByteArray data;

    QFile file(fileName);
    bool ok = file.open(QIODevice::ReadOnly);
    if(!ok){
        qDebug() << "Fail to open : " << file.errorString();
        return data;
    }

    data = file.readAll();
    file.close();

    return data;
}

QString AnalysisJson::getFileName() const
{
    return fileName;
}

void AnalysisJson::setFileName(const QString &value)
{
    fileName = value;
}
