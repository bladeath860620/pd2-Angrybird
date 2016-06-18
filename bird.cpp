#include "bird.h"

Bird::Bird(float x, float y,float dense, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Item(world)
{
    Pixmap.setPixmap(pixmap);
    Pixmap.setTransformOriginPoint(Pixmap.boundingRect().width()/2,Pixmap.boundingRect().height()/2);
    size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    Body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = dense;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    Body->SetAngularDamping(3);
    Body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&Pixmap);
    Body->SetGravityScale(0);
    b2Vec2 speed = Body -> GetLinearVelocity();
    VB = qSqrt(qPow(speed.x,2)+qPow(speed.y,2));
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    Body->SetLinearVelocity(velocity);
}

Bird::~Bird()
{
    //World->DestroyBody(Body);
}
