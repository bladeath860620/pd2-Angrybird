#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qApp->installEventFilter(this);
    ui->setupUi(this);
    results = new Results;
    scene = new QGraphicsScene(0,0,1600,700);
    ui -> graphicsView -> setScene(scene);
    world = new b2World(b2Vec2(0.0f,-9.8f));//set gravity
    worldMeter = QSizeF(80,35);
    worldPixel = this->size();
    pointTransfer::setSize(worldMeter, worldPixel);

    contact = new BumpChecker;
    world->SetContactListener(contact);
    shootbird = new QMediaPlayer;
    shootbird->setMedia(QUrl("qrc:/snd/sound effects/bird.wav"));

    land = new Land(-4000000.0f, 0.0f, 16000000, 1, world, scene);

    bird1 = new Bird(1,7.0f, 10.7f/*meter(x,y)*/,BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(":/bird/img/Angry Birds Seasons/Angry_Bird_red.png"), world, scene);
    BIRD.push_back(bird1);
    Bit = BIRD.begin();
    //BIRD.push_back(land);
    //-------------------------------------------------
    //land2 = new Land(-40.0f, 0.0f, 1, 80, world, scene);
    land3 = new Land(0.0f, 80.0f, 160, 1, world, scene);
    //land4 = new Land(120.0f, 0.0f, 1, 80, world, scene);
    wall = new Land(70.0f, 10.0f, 5, 10, world, scene);
    //-------------------------------------------------
    wood1 = new Obstacle(40.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood1);
    wood2 = new Obstacle(44.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood2);
    wood3 = new Obstacle(42.0,8.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood3);
    wood4 = new Obstacle(42.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood4);
    wood5 = new Ball_Obstacle(41.75,11.5,1.9,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_ball.png"),world,scene);
    WOOD.push_back(wood5);
    wood6 = new Obstacle(36.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood6);
    wood7 = new Obstacle(48.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood7);
    wood8 = new Obstacle(38.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood8);
    wood9 = new Obstacle(46.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood9);


    pig1 = new Pig(42.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig1);
    pig2 = new Pig(38.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig2);
    pig3 = new Pig(46.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig3);


    WOOD.push_back(land);
    PIG.push_back(wall);

    arrow = new QGraphicsPixmapItem;
    arrow->setPixmap(QPixmap(":/arrow/img/arrow.png").scaled(200, 18, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    arrow->setTransformOriginPoint(arrow->pixmap().width()/2, arrow->pixmap().height()/2);
    arrow->setTransformationMode(Qt::SmoothTransformation);
    arrow->setVisible(false);
    scene->addItem(arrow);

    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(60/1000);//FPS
    //bird1->setLinearVelocity(b2Vec2(1,1));
    //scene->addItem(new QGraphicsRectItem(0,0,100,100));
}

void MainWindow::tick()
{
    if((pig_count==0&&bird_count==6) || score==33000)
    {
        qDebug() << "pig_count : " << pig_count;
        qDebug() << "bird_count : " << bird_count;
        qDebug() << "score : " << score;
        showResult();
    }
    ui->lcdNumber->display(score);
    ui->lcdNumber_2->display(pig_count);
    ui->lcdNumber_3->display(6-bird_count);
    if(shot)
    {
        CD = (*Bit)->available;
        b2Vec2 speed = (*Bit)->Body->GetLinearVelocity();
        VB = qSqrt(qPow(speed.x,2)+qPow(speed.y,2));
        b2Vec2 X = (*Bit)->Body->GetPosition();;
        if((X.y>120 || X.x<-20) || X.x>100)
            outer = true;
        if((VB==0 || outer) && bird_count == 2)
        {
            bird2 = new Bird(2,6.8f, 10.7f,BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(":/bird/img/Angry Birds Seasons/angry-bird-yellow-icon.png"), world, scene);
            BIRD.push_back(bird2);
            delete (*Bit);
            BIRD.erase(Bit);
            shot = false;
            newed = true;
            outer = false;
        }
        else if((VB==0 || outer) && bird_count == 3)
        {
            bird3 = new Bird(3,6.8f, 10.7f,BIRD_DENSITY*4, 1.5, &timer, QPixmap(":/bird/img/Angry Birds Seasons/BLOCK_STEEL_BALL.png"), world, scene);
            BIRD.push_back(bird3);
            delete (*Bit);
            BIRD.erase(Bit);
            shot = false;
            newed = true;
            outer = false;
        }
        else if((VB==0 || outer) && bird_count == 4)
        {
            bird4 = new Bird(4,6.8f, 10.7f,BIRD_DENSITY, BIRD_RADIUS*1.75, &timer, QPixmap(":/bird/img/Angry Birds Seasons/BIRD_GREY_YELL.png"), world, scene);
            BIRD.push_back(bird4);
            delete (*Bit);
            BIRD.erase(Bit);
            shot = false;
            newed = true;
            outer = false;
        }
        else if((VB==0 || outer) && bird_count == 5)
        {
            bird5 = new Bird(5,7.1f, 10.9f,BIRD_DENSITY, BIRD_RADIUS*2, &timer, QPixmap(":/bird/img/Angry Birds Seasons/TA.png"), world, scene);
            BIRD.push_back(bird5);
            delete (*Bit);
            BIRD.erase(Bit);
            shot = false;
            newed = true;
            outer = false;
        }
        else if((VB==0 || outer) && bird_count == 6)
        {
            bird6 = new Bird(6,6.8f, 10.7f,BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(""), world, scene);
            BIRD.push_back(bird6);
            delete (*Bit);
            BIRD.erase(Bit);
            shot = false;
            newed = true;
            outer = false;
            showResult();
        }
    }
    for(it = WOOD.begin(); it!= WOOD.end(); ++it)
    {
        if((*it)->death)
        {
            delete (*it);
            WOOD.erase(it);
            score += 2000;
            //qDebug() << score;
        }
    }
    for(it = PIG.begin(); it!= PIG.end(); ++it)
    {
        if((*it)->death)
        {
            delete (*it);
            PIG.erase(it);
            score += 5000;
            --pig_count;
            //qDebug() << score;
        }
    }
    world->Step(1.0/60.0, 6, 2);
    scene->update();
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(pressed && event->type() == QEvent::MouseButtonRelease)
    {
        arrow->setVisible(false);
        Force_pos = static_cast<QMouseEvent*>(event)->pos();
        if(pressed && bird_count!=3 && bird_count!=5)
            shootbird->play();
        pressed = false;
        b2Vec2 linearV = b2Vec2((clicked_point.x()-Force_pos.x())/15,(Force_pos.y()-clicked_point.y())/15);
        if(bird_count == 1)
        {
            bird1->setLinearVelocity(linearV);
            bird1->Body->SetGravityScale(1);
            ++bird_count;
            shot = true;
            skill = true;
            /*BIRD.push_back(bird1);
            Bit = BIRD.begin();*/
            newed = false;
        }
        else if(bird_count == 2 && newed)
        {
            bird2->setLinearVelocity(linearV);
            bird2->Body->SetGravityScale(1);
            ++bird_count;
            shot = true;
            skill = true;
            //BIRD.push_back(bird2);
            //++Bit;
            newed = false;
        }
        else if(bird_count == 3 && newed)
        {
            bird3->setLinearVelocity(linearV);
            bird3->Body->SetGravityScale(1);
            ++bird_count;
            shot = true;
            skill = true;
            //BIRD.push_back(bird3);
            //++Bit;
            newed = false;
        }
        else if(bird_count == 4 && newed)
        {
            bird4->setLinearVelocity(linearV);
            bird4->Body->SetGravityScale(1);
            ++bird_count;
            shot = true;
            skill = true;
            //BIRD.push_back(bird4);
            //++Bit;
            newed = false;
        }
        else if(bird_count == 5 && newed)
        {
            bird5->setLinearVelocity(linearV);
            bird5->Body->SetGravityScale(1);
            ++bird_count;
            shot = true;
            skill = true;
            //BIRD.push_back(bird5);
            //++Bit;
            newed = false;
        }
    }
    else if(event->type() == QEvent::MouseMove)
    {
        //Force_pos = static_cast<QMouseEvent*>(event)->pos();
        if(pressed && !BIRD.empty() && !shot && VB == 0)
        {
            //qDebug() << "ARROW!";
            QPointF temp = static_cast<QMouseEvent*>(event)->pos();
            arrow->resetTransform();
            arrow->setPos(QPointF(50, 400));
            arrow->setRotation(qAtan2(-temp.y()+clicked_point.y(), -temp.x()+clicked_point.x())*180/pi);
            arrow->setScale(qSqrt(qPow(temp.y()-clicked_point.y(), 2) + qPow(temp.x()-clicked_point.x(), 2))/300);
            arrow->setVisible(true);
        }
    }
    return false;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    pressed = true;
    clicked_point = static_cast<QMouseEvent*>(event)->pos();

    if(skill && shot && pressed && CD)
    {
        b2Vec2 gravity;
        b2Vec2 speed = (*Bit)->Body->GetLinearVelocity();
        b2Vec2 gravity_center;
        b2Vec2 bodypos;
        float dist;
        switch(bird_count-1)
        {
            case 1:
                qDebug() << "red";
                skill = false;
                pressed = false;
            break;
            case 2:
                qDebug() << "yellow";
                (*Bit)->Body->SetLinearVelocity(b2Vec2(speed.x*10,speed.y*10));
                skill = false;
                pressed = false;
            break;
            case 3:
                qDebug() << "iron";
                (*Bit)->Body->SetLinearVelocity(b2Vec2(0,-300));
                skill = false;
                pressed = false;
            break;
            case 4:
                qDebug() << "black";
                gravity_center = (*Bit)->Body->GetPosition();
                for(it=WOOD.begin(); it!=WOOD.end(); ++it)
                {
                    bodypos = (*it)->Body->GetPosition();
                    dist = qSqrt(qPow(gravity_center.x-bodypos.x,2)+qPow(gravity_center.y-bodypos.y,2));
                    if(dist<=4)
                    {
                        gravity = b2Vec2(4000000/dist,4000000/dist);
                        (*it)->Body->ApplyForceToCenter(gravity, true);
                    }
                }
                for(it=PIG.begin(); it!=PIG.end(); ++it)
                {
                    bodypos = (*it)->Body->GetPosition();
                    dist = qSqrt(qPow(gravity_center.x-bodypos.x,2)+qPow(gravity_center.y-bodypos.y,2));
                    gravity = b2Vec2(800000/dist,800000/dist);
                    (*it)->Body->ApplyForceToCenter(gravity, true);
                }
                skill = false;
                pressed = false;
            break;
            case 5:
                qDebug() << "TA NUCLEAR";
                gravity_center = (*Bit)->Body->GetPosition();
                for(it=WOOD.begin(); it!=WOOD.end(); ++it)
                {
                    bodypos = (*it)->Body->GetPosition();
                    dist = qSqrt(qPow(gravity_center.x-bodypos.x,2)+qPow(gravity_center.y-bodypos.y,2));
                    gravity = b2Vec2(20000000000/dist,20000000000/dist);
                    (*it)->Body->ApplyForceToCenter(gravity, true);
                }
                for(it=PIG.begin(); it!=PIG.end(); ++it)
                {
                    bodypos = (*it)->Body->GetPosition();
                    dist = qSqrt(qPow(gravity_center.x-bodypos.x,2)+qPow(gravity_center.y-bodypos.y,2));
                    gravity = b2Vec2(20000000000/dist,20000000000/dist);
                    (*it)->Body->ApplyForceToCenter(gravity, true);
                }
                (*Bit)->Body->ApplyLinearImpulse(b2Vec2(400000,400000),gravity_center,true);
                skill = false;
                pressed = false;
            break;
            default:
                qDebug() << "nothing happens";
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    qDebug() << "EXIT";
    emit quitGame();
}

void MainWindow::showResult()
{
    this->hide();
    results->show();
    results->showScore(score);
    results->showText(pig_count, score, 6-bird_count);
    if(results->exec())
    {
        this->show();
        results->close();
        resetGame();
    }
}

void MainWindow::resetGame()
{
    results = new Results;
    bird_count = 1;
    pig_count = 3;
    shot = false;
    newed = false;
    skill = true;
    score = 0;
    //bool available;
    outer = false;
    for(it=WOOD.begin();it!=WOOD.end();++it)
    {
        delete (*it);
    }
    WOOD.clear();
    qDebug() << "WOOD ERASED";
    for(it=PIG.begin();it!=PIG.end();++it)
    {
        //qDebug() << it;
        delete (*it);
    }
    PIG.clear();
    qDebug() << "PIG ERASED";

    /*for(Bit=BIRD.begin();Bit!=BIRD.end();++Bit)
    {
        bool jump = false;
        if(Bit == BIRD.end())
        {
            bird1 = new Bird(1,7.0f, 10.7fmeter(x,y),BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(":/bird/img/Angry Birds Seasons/Angry_Bird_red.png"), world, scene);
            BIRD.push_back(bird1);
            jump = true;
            qDebug() << "END?";
        }
        delete (*Bit);
        BIRD.erase(Bit);
        if(jump)
            break;
    }*/
    bird1 = new Bird(1,7.0f, 10.7f/*meter(x,y)*/,BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(":/bird/img/Angry Birds Seasons/Angry_Bird_red.png"), world, scene);
    BIRD.push_back(bird1);
    delete (*Bit);
    BIRD.erase(Bit);
    qDebug() << "HERE?";
    land = new Land(-4000000.0f, 0.0f, 16000000, 1, world, scene);

    //bird1 = new Bird(1,7.0f, 10.7f/*meter(x,y)*/,BIRD_DENSITY, BIRD_RADIUS, &timer, QPixmap(":/bird/img/Angry Birds Seasons/Angry_Bird_red.png"), world, scene);
    //BIRD.push_back(bird1);
    //Bit = BIRD.begin();
    //BIRD.push_back(land);
    //-------------------------------------------------
    /*land2 = new Land(-40.0f, 0.0f, 1, 80, world, scene);
    land3 = new Land(0.0f, 80.0f, 160, 1, world, scene);
    land4 = new Land(120.0f, 0.0f, 1, 80, world, scene);*/
    wall = new Land(70.0f, 10.0f, 5, 10, world, scene);
    //-------------------------------------------------
    wood1 = new Obstacle(40.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood1);
    wood2 = new Obstacle(44.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood2);
    wood3 = new Obstacle(42.0,8.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood3);
    wood4 = new Obstacle(42.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood4);
    wood5 = new Ball_Obstacle(41.75,11.5,1.9,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_ball.png"),world,scene);
    WOOD.push_back(wood5);
    wood6 = new Obstacle(36.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood6);
    wood7 = new Obstacle(48.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),1,world,scene);
    WOOD.push_back(wood7);
    wood8 = new Obstacle(38.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood8);
    wood9 = new Obstacle(46.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),0,world,scene);
    WOOD.push_back(wood9);


    pig1 = new Pig(42.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig1);
    pig2 = new Pig(38.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig2);
    pig3 = new Pig(46.0f, 2.0f, 1.0f, &timer, QPixmap(":/pig/img/Angry Birds Seasons/pig.png"), world, scene);
    PIG.push_back(pig3);


    WOOD.push_back(land);
    PIG.push_back(wall);
}

void MainWindow::on_pushButton_clicked()
{
    resetGame();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
