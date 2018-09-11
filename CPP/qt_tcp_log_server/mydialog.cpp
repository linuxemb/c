#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

class ListS;
myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);


    //add thread starff ===============

    mThread = new MyThread(this);
    connect(mThread,SIGNAL(NumberChanged(int)), this, SLOT(onNumberChanged(int)));


   //-------add below

 /*   scene = new QGraphicsScene(this);
    ui->graphicsView ->setScene(scene);

    lS = new listS;
    scene-> addItem(lS);  */

}

myDialog::~myDialog()
{
    delete ui;
}
 void myDialog:: paintEvent(QPaintEvent *e)

{
    QPainter painter(this);
    QPen paintpen(Qt::black);
    paintpen.setWidth(12);

    QPen linepen(Qt::red);
    linepen.setWidth(4);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);
    painter.setPen(paintpen);
    painter.drawPoint(p1);

    QPoint p2;
    p2.setX(10);
    p2.setY(250);
    painter.setPen(linepen);
  painter.drawLine(p1,p2);
  //painter.drawText("Type");

    //for x axis
    QPoint p3;
    p3.setX(10);
    p3.setY(250);


    QPoint p4;
    p4.setX(400);
    p4.setY(250);

    painter.setPen(linepen);

     painter.drawLine(p3,p4);
     painter.setPen(paintpen);
     painter.drawPoint(p4);

     //painter.drawLine(10,10,100,100);


    //==========================================
     //make polygon

     QPolygon poly;
     poly  << QPoint(10,10);
     poly  << QPoint(10,100);
     poly  << QPoint(100,10);
     poly << QPoint(100,100);


     //make a pen

     linepen.setWidth(8);
     linepen.setColor(Qt::yellow);

     painter.setPen(linepen);

     painter.drawPolygon(poly);


    //======================call list

    // ListS *lS = new listS(this);
     lS -> paintEvent(e);
     lS ->draw();


}

 void myDialog::onNumberChanged(int Number)
 {
     ui->label->setText(QString::number(Number));

 }

void myDialog::on_pushButton_clicked()
{//started
    mThread ->start();
  qDebug() <<"started";

}

void myDialog::on_pushButton_2_clicked()
{
    //stop
        qDebug() <<"stoped";

    mThread -> Stop = true;
}
