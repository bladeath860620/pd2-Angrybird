#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qApp->installEventFilter(this);
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1600,700);
    ui -> graphicsView -> setScene(scene);
    world = new b2World(b2Vec2(0.0f,-9.8f));//set gravity
    worldMeter = QSizeF(80,35);
    worldPixel = this->size();
    pointTransfer::setSize(worldMeter, worldPixel);
    land = new Land(-40.0f, 0.0f, 160, 1, world, scene);
    bird1 = new Bird(7.0f, 10.7f/*meter(x,y)*/, 1.25f, &timer, QPixmap(":/bird/img/Angry Birds Seasons/Angry_Bird_red.png"), world, scene);
    //-------------------------------------------------
    land2 = new Land(0.0f, 0.0f, 1, 35, world, scene);
    land3 = new Land(0.0f, 35.0f, 80, 1, world, scene);
    land4 = new Land(80.0f, 0.0f, 1, 35, world, scene);
    //-------------------------------------------------
    wood1 = new Obstacle(40.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),world,scene);
    wood2 = new Obstacle(44.0,2.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),world,scene);
    wood3 = new Obstacle(42.0,8.0,1,4,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_vertical.png"),world,scene);
    wood4 = new Obstacle(42.0,6.0,4,1,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_mid_horizontal.png"),world,scene);
    wood5 = new Ball_Obstacle(41.8,11.5,1.9,&timer, QPixmap(":/obstacle/img/Angry Birds Seasons/wood_ball.png"),world,scene);
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(60/1000);//FPS
    //bird1->setLinearVelocity(b2Vec2(1,1));
    //scene->addItem(new QGraphicsRectItem(0,0,100,100));
}

void MainWindow::tick()
{
    world->Step(1.0/60.0, 6, 2);
    scene->update();
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(pressed && event->type() == QEvent::MouseButtonRelease)
    {
        pressed = false;
        Force_pos = static_cast<QMouseEvent*>(event)->pos();
        bird1->setLinearVelocity(b2Vec2((Force_pos0.x()-Force_pos.x())/15,(Force_pos.y()-Force_pos0.y())/15));
        bird1->Body->SetGravityScale(1);
    }
    else if(pressed && event->type() == QEvent::MouseMove)
    {

    }
    return false;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "pressed = true";
    Force_pos0 = event->pos();
    pressed = true;
    if(pressed)
        return;
}

MainWindow::~MainWindow()
{
    delete ui;
}





