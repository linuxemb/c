#include "mysq.h"

mySq::mySq()
{
    setFlag(ItemIsMovable);
}

void mySq::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

QRectF rec = boundingRect();
QBrush brush(Qt::blue);
painter ->fillRect(rec,brush);
painter-> drawEllipse(rec);
painter-> drawRect(rec);
}

QRectF mySq::boundingRect() const
{
    return QRectF(0,0,10,10);
}
