#ifndef PIG_H
#define PIG_H

#include "pointtransfer.h"
#include "item.h"

class Pig : public Item
{
public:
    Pig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void collision();
    double HP;
};

#endif // PIG_H
