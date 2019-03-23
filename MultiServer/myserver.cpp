#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
   server = new QTcpServer(this);


    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}


void MyServer::StartServer()
{


 //  connect(server,SIGNAL(newConnection()),this,SLOT(incomingConnection()));
    if(!this->listen(QHostAddress::Any,9999))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening.oooo..";
    }
}


void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    MyThread *thread = new MyThread(socketDescriptor,this);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start(); // call run funciton
}
