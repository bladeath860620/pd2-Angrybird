#ifndef LAND_H
#define LAND_H

#include "pointtransfer.h"
#include "item.h"

class Land : public Item
{
public:
    Land(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene);
    double VB = 1;
};

#endif // LAND_H
