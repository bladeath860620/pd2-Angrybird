#ifndef BIRD_H
#define BIRD_H

#include "pointtransfer.h"
#include "item.h"

class Bird : public Item
{
public:
    Bird(int type, float x, float y,float dense , float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    double VB;
    void collision();
    bool available = true;
    int TYPE;
    ~Bird();
};

#endif // BIRD_H
