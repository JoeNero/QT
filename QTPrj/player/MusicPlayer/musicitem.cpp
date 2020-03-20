#include "musicitem.h"
#include <QPainter>

MusicItem::MusicItem(const QString &filename, QObject *parent) : QObject(parent)
{
    image.load(filename);
    animation = new QPropertyAnimation(this,"anagle");
}

QRectF MusicItem::boundingRect() const
{
    int width = image.width();
    int height= image.height();

    return QRectF(-width/2,-height/2,width,height);
}

void MusicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(this->boundingRect(),image);
}

void MusicItem::startRotationAnimation(int duration, int startAnagle, int endAnagle, int loopCount)
{
    animation->setDuration(duration);
    animation->setStartValue(startAnagle);
    animation->setEndValue(endAnagle);
    animation->setLoopCount(loopCount);
    animation->start();
}
