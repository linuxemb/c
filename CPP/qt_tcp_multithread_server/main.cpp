#include <QtCore/QCoreApplication>
#include "myserver.h"
#include "control.h"
#include "mythread.h"

class MyThread;
int main(int argc, char *argv[])
{   //QObject;
    QCoreApplication a(argc, argv);
// control *mycontrol = new control();


 //QObject::connect(mThread,SIGNAL(dataCome(newData)),mycontrol,SLOT(draw(myArray)),Qt::DirectConnection);
    MyServer Server;
    Server.StartServer();

    return a.exec();
}
