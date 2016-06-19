#ifndef BALL_OBSTACLE_H
#define BALL_OBSTACLE_H

#include "pointtransfer.h"
#include "item.h"
class Ball_Obstacle : public Item
{
public:
    Ball_Obstacle(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    double HP;
    void collision();
    QMediaPlayer *SE;
};

#endif // BALL_OBSTACLE_H
