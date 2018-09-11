#ifndef LISTS_H
#define LISTS_H
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>



class ListS:QPainter{


public:
   // ListS();

    void draw();
     void paintEvent(QPaintEvent *e);
private :
     ListS * lS;


};

/*class ListS :  public QGraphicsItems{


public:
    ListS();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option , QWidget *widget );

};


 */


#endif // LISTS_H
