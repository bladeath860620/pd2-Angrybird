#ifndef ITEM_H
#define ITEM_H

#include "pointtransfer.h"

class Item : public QObject
{
    Q_OBJECT
public:
    Item(b2World *world);
    void setSize(QSizeF worldSize, QSizeF pixelSize);
    b2Body *Body;
    b2World *World;
    QSizeF size;
    QGraphicsPixmapItem Pixmap;

public slots:

    void paint();

private:
    static QSizeF db2_worldSize, db2_pixelSize;

};

#endif // ITEM_H
