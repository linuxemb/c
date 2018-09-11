#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("ZoomIn");
//   setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDraw_triggered()
{
   // myDialog mDialog;
 //setCentralWidget(ui->plainTextEdit);
  //  mDialog.setModal(false);
  //  mDialog.show();

   mDialog = new myDialog(this);
    yDialog = new Dialog(this);
    mDialog->show();
     yDialog->show();
}




