
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "lists.h"
using namespace std;


void parse() {
  string line;
  string type;
  string event;
  //ListS item[20];

  int i,k,j=0;

  ifstream myfile ("receive.txt");
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



/*=======================create type obj baseon type  */

                k = ++i;
        cout<<">Type:"<<type<<endl;


       // ================cause exceptin here.
         //  event = line.substr(5,3);
     //    for(i; line[i]!=',';i++){ }
        // event = line.substr(k,(i-k));  //move to next type
      //  event = line.substr(5,6);
        //  k = ++i;

       // cout<<">Event:"<<event<<"i="<<i<<endl;

    }
    myfile.close();
  }

  else cout << "Unable to open file";

  //return 0;
}
