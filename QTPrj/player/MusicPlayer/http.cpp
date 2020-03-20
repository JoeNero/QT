#include "http.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QFile>

Http::Http(const QString &filename,QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    this->fileName = filename;
}

void Http::searchMusic(const QString &name)
{
    QFile::remove(fileName);
    QString httpUrl = "http://music.zhuolin.wang/api.php";
    QNetworkRequest request(httpUrl);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded;charset=UTF-8");
    QString data = QString("types=search&count=20&source=netease&pages=1&name=%1").arg(name);
    QNetworkReply *reply = networkManager->post(request,data.toUtf8());
    connect(reply,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finishedSearchMusic()));
}

void Http::searchMp3Url(const QString &musicId)
{
    QFile::remove(fileName);
    QString httpUrl = "http://music.zhuolin.wang/api.php";
    QNetworkRequest request(httpUrl);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded;charset=UTF-8");
    QString data = QString("types=url&id=%1&source=netease").arg(musicId);
    QNetworkReply *reply = networkManager->post(request,data.toUtf8());
    connect(reply,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finishedSearchMp3Url()));
}

void Http::searchLyric(const QString &musicId)
{
    QFile::remove(fileName);
    QString httpUrl = "http://music.zhuolin.wang/api.php";
    QNetworkRequest request(httpUrl);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded;charset=UTF-8");
    QString data = QString("types=lyric&id=%1&source=netease").arg(musicId);
    QNetworkReply *reply = networkManager->post(request,data.toUtf8());
    connect(reply,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finishedSearchLyric()));
}

void Http::searchPictureUrl(const QString &picId)
{
    QFile::remove(fileName);
    QString httpUrl = "http://music.zhuolin.wang/api.php";
    QNetworkRequest request(httpUrl);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded;charset=UTF-8");
    QString data = QString("types=pic&id=%1&source=netease").arg(picId);
    QNetworkReply *reply = networkManager->post(request,data.toUtf8());
    connect(reply,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finishedSearchPicUrl()));
}

void Http::downloadPicture(const QString &picUrl)
{
    QFile::remove(fileName);
    QNetworkRequest request(picUrl);
    QNetworkReply *reply = networkManager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(reply,SIGNAL(finished()),this,SIGNAL(finishedDownloadPicture()));
}

QString Http::getFileName() const
{
    return fileName;
}

void Http::setFileName(const QString &value)
{
    fileName = value;
}

void Http::readData()
{
    QNetworkReply *reply = (QNetworkReply *)this->sender();//获取发送信号的对象地址
    QByteArray data = reply->readAll();
    QFile file(fileName);
    bool ok = file.open(QIODevice::Append);
    if(!ok){
        qDebug() << "Fail to open : " << file.errorString();
        return;
    }
    file.write(data);
    file.close();

    return;
}

