#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void StartServer();
signals:

public slots:


    void incomingConnection(int socketDescriptor);

private:
    QTcpServer *server;

};

#endif // MYSERVER_H
