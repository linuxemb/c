#include "control.h"
/*

void Control::parse()
{
    int i,k,j;
    j=0;
      ifstream myfile ("a.txt");
      if (myfile.is_open())
      {
        while ( myfile.good() )
        {
          getline (myfile,line);
          cout << line << endl;
              i=0;
                for(i; line[i]!=',';i++){ }
             type = line.substr(0,i);  //move to next type
           if (type=="list")
               {
                   cout <<"j rm list item created....."<<j<<endl;
                 //   item[j] =  new ListS;
                    j++;
               }
               // else if (type == "tree")
             //   item[j] =  new
               // cout  <<"tree" <<endl;
            }
      }
}
*/
void Control::Read(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open file for reading";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();


    qDebug() << mText;

    mFile.close();
}



/*int main(int argc, char *argv[])

{
    QCoreApplication a(argc, argv);

    Read(":/MyFile/receive.txt");

    return a.exec();
}
*/
