#include "mythread.h"
#include "control.h"
class control;

MyThread::MyThread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
     mycontrol = new control();
}

void MyThread::run()
{
    //thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();

    //========================
  //  mycontrol = new control();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    //================== myThread::dataCome(), send signal to Control::draw()
     connect(this,SIGNAL(dataCome(newData)),mycontrol,SLOT(draw(myArray)),Qt::DirectConnection);

    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";

    exec();
}

void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();

     qDebug() << socketDescriptor << " Data in: " << Data;
//=================================

     QString mFilename = "/home/lisa/Desktop/a.txt";

     QFile mFile(mFilename);
     if(!mFile.open(QFile::WriteOnly | QFile::Text))
     {
         qDebug() << "cnat open for writeing";

         return;
     }

     QTextStream out( &mFile);
     out << Data;
     mFile.flush();
     mFile.close();
     //=============================
     socket->write(Data);

     //=====================

    emit dataCome(Data);
}



void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    exit(0);
}

