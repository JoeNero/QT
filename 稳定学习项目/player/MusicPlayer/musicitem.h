#ifndef MUSICITEM_H
#define MUSICITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QImage>
#include <QPropertyAnimation>

class MusicItem :public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(qreal anagle READ rotation WRITE setRotation)

public:
    explicit MusicItem(const QString &filename,QObject *parent = 0);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void startRotationAnimation(int duration,int startAnagle,int endAnagle,int loopCount);

signals:

public slots:

private:
    QImage image;
    QPropertyAnimation *animation;
};

#endif // MUSICITEM_H
