#include "pig.h"

Pig::Pig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Item(world)
{
    HP = PIG_HP;
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
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    Body->SetAngularDamping(3);
    Body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&Pixmap);
}

void Pig::collision()
{
    //qDebug() << " HP : " << HP;
    b2Vec2 speed = Body -> GetLinearVelocity();
    double V = qSqrt(qPow(speed.x,2)+qPow(speed.y,2));
    HP -= 500*V;
    if(HP<=0)
    {
        death = true;
        qDebug() << "KILLED";
    }
        else if(HP<=PIG_HP/2)
        Pixmap.setPixmap(QPixmap("img/Angry Birds Seasons/pig_damaged.png"));
}
