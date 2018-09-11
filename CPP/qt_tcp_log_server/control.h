#ifndef CONTROL_H
#define CONTROL_H
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
//for string parrase

#include "lists.h"
#include <iostream>
#include <fstream>

#include <string>
using namespace std;

class Control
{
 private :
        string line;
      string type;
      string event;
      ListS ls[20];
public:
   void Read(QString Filename);
  // void parse();
};

#endif // CONTROL_H
