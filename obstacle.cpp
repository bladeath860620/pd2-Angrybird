#include "obstacle.h"

Obstacle::Obstacle(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, int type, b2World *world, QGraphicsScene *scene):Item(world)
{
    SE = new QMediaPlayer;
    SE->setMedia(QUrl("qrc:/snd/sound effects/SND_FILES/wood_break.wav"));
    TYPE = type;
    HP = MID_WOOD_HP;
    death = false;
    Pixmap.setPixmap(pixmap);
    Pixmap.setTransformOriginPoint(Pixmap.boundingRect().width()/2,Pixmap.boundingRect().height()/2);
    size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    Body = world->CreateBody(&bodydef);
    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/2,h/2);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = WOOD_DENSITY;
    fixturedef.friction = WOOD_FRICTION;
    fixturedef.restitution = WOOD_RESTITUTION;
    Body->SetAngularDamping(3);
    Body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&Pixmap);
}

void Obstacle::collision()
{
    //qDebug() << "rect Bumped" << death;
    b2Vec2 speed = Body -> GetLinearVelocity();
    double V = qSqrt(qPow(speed.x,2)+qPow(speed.y,2));
    HP -= 500*V;
    if(HP<=0)
    {
        SE->play();
        death = true;
        HP = 0;
    }
    else if(HP <= MID_WOOD_HP/2)
    {
        if(playable)
        {
            SE->play();
            playable = false;
        }
        if(TYPE == 1)
            Pixmap.setPixmap(QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical_damaged.png"));
        else if(TYPE == 0)
            Pixmap.setPixmap(QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal_damaged.png"));

    }
}
