#ifndef POINTTRANSFER_H
#define POINTTRANSFER_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <QSizeF>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QVector>
#include <QtMultimedia/QMediaPlayer>

#define pi 3.14159

#define BIRD_DENSITY 20.0
#define BIRD_FRICTION 1.0
#define BIRD_RESTITUTION 0.4
#define BIRD_RADIUS 1.0

#define WOOD_DENSITY 10.0
#define WOOD_FRICTION 1.0
#define WOOD_RESTITUTION 0.3

#define MID_WOOD_HP 48000.0
#define BALL_WOOD_HP 96000.0
#define PIG_HP 40000.0

# define start_X -34
#define start_Y -7.5

class pointTransfer
{
public:
    pointTransfer();
    static QPointF toPixel(b2Vec2 bodyPos, QSizeF bodySize);
    static QPointF toMeter(QPointF);
    static void setSize(QSizeF worldsize, QSizeF pixelsize);

private:
    static QSizeF db2_worldSize;
    static QSizeF db2_pixelSize;
};

#endif // POINTTRANSFER_H
