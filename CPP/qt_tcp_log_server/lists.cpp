#include "lists.h"



  void ListS::paintEvent(QPaintEvent *e)


  {
 /*     QPolygon poly;
    poly  << QPoint(x,y);
      poly  << QPoint(x,y+90);
      poly  << QPoint(x+90,x);
      poly << QPoint(x+90,+90y);
*/
      QPolygon poly;
      poly  << QPoint(20,20);
      poly  << QPoint(20,100);
      poly  << QPoint(100,20);
      poly << QPoint(100,100);


      QPoint p4;
      p4.setX(200);
      p4.setY(200);

      QPainter painter;
        QPen linepen(Qt::red);
      painter.setPen(linepen);

      painter.drawPolygon(poly);


  }

  void ListS::draw()
  {
     QPainter painter;
      QPen linepen(Qt::red);
       painter.setPen(linepen);
      painter.drawRect(10,10,20,20);


  }

 /*void ListS::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
  {
      QRectF rec = boundingRect();
      QBrush brush(Qt::blue);
      painter ->fillRect(rec,brush);
      painter-> drawEllipse(rec);
      painter-> drawRect(rec);
  }

  QRectF ListS::boundingRect() const
  {
      return QRectF(0,0,100,100);
  }
*/
