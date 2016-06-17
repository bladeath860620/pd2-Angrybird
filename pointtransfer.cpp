#include "pointtransfer.h"

pointTransfer::pointTransfer()
{

}

QSizeF pointTransfer::db2_worldSize = QSizeF();
QSizeF pointTransfer::db2_pixelSize = QSizeF();

QPointF pointTransfer::toPixel(b2Vec2 bodyPos, QSizeF bodySize)
{
    QPointF pos;
    pos.setX(((bodyPos.x - bodySize.width() / 2) / db2_worldSize.width()) * db2_pixelSize.width());
    pos.setY((1.0f - ((bodyPos.y + bodySize.height() / 2) / db2_worldSize.height())) * db2_pixelSize.height());
    return pos;
}

QPointF pointTransfer::toMeter(QPointF Pixel)
{
    QPointF pos;
    pos.setX((Pixel.x() / db2_pixelSize.width()) * db2_worldSize.width());
    pos.setY((1.0f - Pixel.y() / db2_pixelSize.height()) * db2_worldSize.height());
    return pos;
}

void pointTransfer::setSize(QSizeF worldMeter, QSizeF worldPixel)
{
    db2_worldSize = worldMeter;
    db2_pixelSize = worldPixel;
}
