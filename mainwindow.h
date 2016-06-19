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
#include "pig.h"

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
    int bird_count = 1;
    int pig_count = 3;
    bool shot = false;
    bool newed = false;
    bool skill = true;
    int score = 0;
    //bool available;
    bool CD;
    bool outer = false;
    void closeEvent(QCloseEvent *);

signals:
    void quitGame();

public slots:
    void tick();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;
    QSizeF worldMeter;
    QSizeF worldPixel;
    Land *land;
    Bird *bird1;
    Bird *bird2;
    Bird *bird3;
    Bird *bird4;
    Bird *bird5;
    Bird *bird6;
    Pig *pig1;
    Pig *pig2;
    Pig *pig3;
    bool pressed;
    QPointF Force_pos;
    Land *land2;
    Land *land3;
    Land *land4;
    Land *wall;
    Obstacle *wood1;
    Obstacle *wood2;
    Obstacle *wood3;
    Obstacle *wood4;
    Obstacle *wood6;
    Obstacle *wood7;
    Obstacle *wood8;
    Obstacle *wood9;
    Ball_Obstacle *wood5;
    BumpChecker *contact;
    QVector<Item*> WOOD;
    QVector<Item*> PIG;
    QVector<Item*> ::iterator it;
    QVector<Bird*> BIRD;
    QVector<Bird*> ::iterator Bit;
    QMediaPlayer *MEDIA;
    QGraphicsPixmapItem * arrow;
    QPointF clicked_point;
    QPointF drag_start;
};

#endif // MAINWINDOW_H
