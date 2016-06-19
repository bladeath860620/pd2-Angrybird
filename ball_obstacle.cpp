#include "ball_obstacle.h"

Ball_Obstacle::Ball_Obstacle(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Item(world)
{
    SE = new QMediaPlayer;
    SE->setMedia(QUrl("qrc:/snd/sound effects/SND_FILES/wood_break.wav"));
    HP = BALL_WOOD_HP;
    death = false;
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

void Ball_Obstacle::collision()
{
    b2Vec2 speed = Body -> GetLinearVelocity();
    double V = qSqrt(qPow(speed.x,2)+qPow(speed.y,2));
    HP -= 500*V;
    if(HP<=0)
    {
        SE->play();
        death = true;
        HP = 0;
    }
    else if(HP<=BALL_WOOD_HP/2)
    {
        if(playable)
        {
            SE->play();
            playable = false;
        }
        Pixmap.setPixmap(QPixmap(":/obstacle/img/Angry Birds Seasons/wood_ball_damaged.png"));
    }
}


