#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "pointtransfer.h"
#include "item.h"

class Obstacle : public Item
{
public:
    Obstacle(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, int type, b2World *world, QGraphicsScene *scene);
    void collision();
    double HP;
    int TYPE;
    QMediaPlayer *SE;
};

#endif // OBSTACLE_H
