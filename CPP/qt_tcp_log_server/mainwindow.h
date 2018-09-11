#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"
#include "dialog.h"
#include "mythread.h"



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionDraw_triggered();

private:
    Ui::MainWindow *ui;
    myDialog *mDialog;
    Dialog *yDialog;

};

#endif // MAINWINDOW_H
