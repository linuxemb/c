/*
 * test.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: lisa
 * Description :UDP device boost wrapper test example
 */


#include "udp_dev.h"
using namespace Oal;

/* define the receive call back function which is used to relay the data out. */
	class receiver
	{
	public:
		void Received(const char *data, size_t len, udp::endpoint &ep)//string ip, unsigned short port)
		{
			string s(data,len);
			unsigned short port = ep.port();
			cout << format("[Received from %d:%d] '%s'\r\n") % ep.address() % port % s;
		}
	};

int main(int argc, char* argv[])
{
	udp_dev *socket_server;
	receiver socket_receiver;
	unsigned short localPort;

    if (argc != 2)
    {
      std::cerr << "Usage: udp_server <local port>" << std::endl;
      return 1;
    }
    localPort = atoi(argv[1]);
    try
	{
    	//Create udp device instance and set up call back function
    	socket_server = new udp_dev(localPort);
		socket_server->setAppRcvCallback(boost::bind(&receiver::Received,socket_receiver,_1,_2,_3));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

/*  Test sending message, which is very similar to what should have in your application
	    std::string msgpkt = "testmessage";
		boost::shared_ptr<std::string> pPkt (new std::string(msgpkt));
		socket_server->sendMessage(pPkt, "20.0.250.224", 8005);
		boost::this_thread::sleep(boost::posix_time::seconds(10));
*/


//	sending char * data
					char* data ="myhello";
					int size = 4;
					boost::shared_ptr<std::string> pPkt (new std::string(data,size));
					socket_server->sendMessage(pPkt, "127.0.0.1", 8005);
//	end

//===========test with prompt input  ==============
/*		char buff[100];
		char ckcmd;
			while(1)
			{
				std::string ip;
				unsigned short port;
				std::string msg;
				char* msgChar = new char [100] ;   //char point
				int bytes;

				cout << "\n ========= UDP Socket Test =========" << endl;
				cout << " Please key in the following commands: " << endl;
				cout << "\tq - quit\n"
						"\ts [dst IP addr] [port number] [message]\r\n";
				cout << "To do: ";
				cin >> ckcmd;
				switch (ckcmd)
				{
				case 'q':
					cout << "Good day!\n\n";
					return 0;
				case 's':
					{
						//cin >> ip >> port >> msg >> bytes ;
						cin >> ip >> port >> msg ;
						sprintf(buff, "%s from %d", msg.data(), localPort);
						std::string msgpkt = buff;
						boost::shared_ptr<std::string> pPkt (new std::string(msgpkt));
					//	boost::shared_ptr<std::string> pPkt (new std::string(msgpkt,bytes));
						socket_server->sendMessage(pPkt, ip, port);
						cout << format("[SEND to %s:%d from local %d] '%s'") % ip % port % localPort % msgpkt.data() ;
					}
					break;
				}
			}
		  return 0;
		}

*/

//===========test with prompt input with limited size of message==============
		char buff[100];
		char ckcmd;
			while(1)
			{
				std::string ip;
				unsigned short port;
				std::string msg;
				char* msgChar = new char [100] ;   //char point
				size_t  bytes;

				cout << "\n ========= UDP Socket Test =========" << endl;
				cout << " Please key in the following commands: " << endl;
				cout << "\tq - quit\n"
						"\ts [dst IP addr] [port number] [message]\r\n";
				cout << "To do: ";
				cin >> ckcmd;
				switch (ckcmd)
				{
				case 'q':
					cout << "Good day!\n\n";
					return 0;
				case 's':
					{
						cin >> ip >> port >> msgChar >> bytes ;
						//sprintf(buff, "%s from %d", msg.data(), localPort);
						std::string msgpkt = buff;
					    boost::shared_ptr<std::string> pPkt (new std::string(msgChar,bytes));
						socket_server->sendMessage(pPkt, ip, port);
						cout << format("[SEND to %s:%d from local %d] '%s'") % ip % port % localPort % msgpkt.data() ;
					}
					break;
				}
			}
		  return 0;
		}


