#include "musicinformation.h"

MusicInformation::MusicInformation(int id, const QString &name, const QString &artist, const QString &album, const QString &picid)
{
    this->id = id;
    this->name = name;
    this->artist = artist;
    this->album = album;
    this->picid = picid;
}

int MusicInformation::getId() const
{
    return id;
}

void MusicInformation::setId(int value)
{
    id = value;
}

QString MusicInformation::getName() const
{
    return name;
}

void MusicInformation::setName(const QString &value)
{
    name = value;
}

QString MusicInformation::getArtist() const
{
    return artist;
}

void MusicInformation::setArtist(const QString &value)
{
    artist = value;
}

QString MusicInformation::getAlbum() const
{
    return album;
}

void MusicInformation::setAlbum(const QString &value)
{
    album = value;
}

QString MusicInformation::getPicid() const
{
    return picid;
}

void MusicInformation::setPicid(const QString &value)
{
    picid = value;
}
