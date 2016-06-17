#include "land.h"

Land::Land(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene):Item(world)
{
    size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    Body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    Body->CreateFixture(&bodyBox,9.0f);

    //paint();
}
