#ifndef CONTROL_H
#define CONTROL_H
#include <QObject>

class control : public QObject
{

Q_OBJECT

public:
  //  control(QObject *parent =0);
   control() {}
public slots:
    void draw(QByteArray myArray);

};

#endif // CONTROL_H
