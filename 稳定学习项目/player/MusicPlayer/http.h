#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QNetworkAccessManager>

class Http : public QObject
{
    Q_OBJECT
public:
    explicit Http(const QString &filename,QObject *parent = 0);
    QString getFileName() const;
    void setFileName(const QString &value);

signals:
    void finishedSearchMusic(void);
    void finishedSearchMp3Url(void);
    void finishedSearchLyric(void);
    void finishedSearchPicUrl(void);
    void finishedDownloadPicture(void);

public slots:
    void readData();
    void searchMusic(const QString &name);
    void searchMp3Url(const QString &musicId);
    void searchLyric(const QString &musicId);
    void searchPictureUrl(const QString &picId);
    void downloadPicture(const QString &picUrl);

private:
    QNetworkAccessManager *networkManager;
    QString fileName;

};

#endif // HTTP_H
