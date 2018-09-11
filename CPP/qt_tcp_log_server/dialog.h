#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "mysq.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    mySq  *mysquare_arr[10] ;
     mySq  *mysquare;
    QGraphicsEllipseItem  *ellipse;
};

#endif // DIALOG_H
