#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "lists.h"
#include "mythread.h"
#include <QObject>

#include "ui_mainwindow.h"
namespace Ui {
    class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();

private:
    Ui::myDialog *ui;
  //  QGraphicsScene *scene;
    ListS  *lS;
    MyThread   *mThread;

 protected:
    void paintEvent(QPaintEvent *e);

public slots:
    void onNumberChanged(int);

private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
};

#endif // MYDIALOG_H
