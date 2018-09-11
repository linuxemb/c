#ifndef MYSQ_H
#define MYSQ_H
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>



class mySq :public QGraphicsItem
{
public:
    mySq();

    QRectF boundingRect() const;
    void paint(QPainter *painter,  const     QStyleOptionGraphicsItem *option,
    QWidget *widget);
};

#endif // MYSQ_H
