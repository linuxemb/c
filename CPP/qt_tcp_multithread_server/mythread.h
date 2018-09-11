#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include "control.h"
class control;



class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID, QObject *parent = 0);
    void run();


signals:
    void error(QTcpSocket::SocketError socketerror);
    void dataCome(QByteArray myData);

public slots:
    void readyRead();
    void disconnected();

public slots:

private:
    QTcpSocket *socket;
    control  *mycontrol;
    int socketDescriptor;
    QByteArray myData;


};

#endif // MYTHREAD_H
