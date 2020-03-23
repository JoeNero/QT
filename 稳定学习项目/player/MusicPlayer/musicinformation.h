#ifndef MUSICINFORMATION_H
#define MUSICINFORMATION_H
#include <QString>

class MusicInformation
{
public:
    MusicInformation(int id,const QString &name,const QString &artist,
                     const QString &album,const QString &picid);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getArtist() const;
    void setArtist(const QString &value);

    QString getAlbum() const;
    void setAlbum(const QString &value);

    QString getPicid() const;
    void setPicid(const QString &value);

private:
    int  id;
    QString name;
    QString artist;
    QString album;
    QString picid;
};

#endif // MUSICINFORMATION_H
