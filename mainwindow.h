#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pointtransfer.h"
#include "item.h"
#include "land.h"
#include "bird.h"
#include "obstacle.h"
#include "ball_obstacle.h"
#include "bumpchecker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();

public slots:
    void tick();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<Item *> itemList;
    QTimer timer;
    QSizeF worldMeter;
    QSizeF worldPixel;
    Land *land;
    Bird *bird1;
    bool pressed;
    QPointF Force_pos0;
    QPointF Force_pos;
    Land *land2;
    Land *land3;
    Land *land4;
    Obstacle *wood1;
    Obstacle *wood2;
    Obstacle *wood3;
    Obstacle *wood4;
    Ball_Obstacle *wood5;
    BumpChecker *contact;
    QVector<Item*> WOOD;
    QVector<Item*> ::iterator it;
};

#endif // MAINWINDOW_H
