#include "item.h"

Item::Item(b2World *world):
    Body(NULL),World(world)
{

}

QSizeF Item::db2_worldSize = QSizeF();
QSizeF Item::db2_pixelSize = QSizeF();

void Item::setSize(QSizeF worldSize, QSizeF pixelSize)
{
    //saves the size of world and pixel;
    db2_worldSize = worldSize;
    db2_pixelSize = pixelSize;
}

void Item::paint()
{
    b2Vec2 bodyPos = Body->GetPosition();
    QPointF pos = pointTransfer::toPixel(bodyPos, size);
    Pixmap.setPos(pos.x()-size.width()/2, pos.y());
    Pixmap.setRotation(-Body->GetAngle()*180/pi);

    Pixmap.resetTransform();
    //qDebug() << "PAINT" << bodyPos.x << bodyPos.y;
}
