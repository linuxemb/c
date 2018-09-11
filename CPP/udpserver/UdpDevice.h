/*
 * udp_dev.h
 * Udp device boost wrapper header file, need been include in your application
 * Send and receive are independent with each other.
 * Receiving: it will receive all the packets sent to it. An application callback is used to relay the data out.
 * Sending: it is separated from reading. It can send data to any specified destinations (IP address & port number).
 *  After network unreached issue, it will cancel previous all async work and re initialized
 *
 *  Created on: Feb 18, 2015
 *      Author: lisa
 */

#ifndef UDP_DEV_H_
#define UDP_DEV_H_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/format.hpp>
using boost::asio::ip::udp;
using namespace std;
using namespace boost;
namespace Oal
{
class udpSocketobj: private boost::noncopyable
{
public:
	udpSocketobj(unsigned short localport)
	: mIo()
	, mSocket(mIo, udp::endpoint(udp::v4(), localport))
	, mThread()
	{}
	virtual ~udpSocketobj()
	{
		mSocket.close();
		mThread.join();
		mIo.stop();
	}


	boost::asio::io_service mIo; ///< Io service object
    udp::socket mSocket;
    boost::thread mThread; ///< Thread that runs read/write operations
};

class udp_dev
{
public:
	const static unsigned short LOCAL_PORT = 65000;

	udp_dev(unsigned short localport = LOCAL_PORT)
	:mLocalPort(localport)
	, pSocket(new udpSocketobj(mLocalPort))
  {
		read();
  }
	void start();
	void stop();
	bool isOpen();
	void read();

	void sendMessage(boost::shared_ptr<std::string> message, string ip, unsigned short port) ;
	void sendMessage(boost::shared_ptr<std::string> message, size_t bytes, string ip, unsigned short port) ;
    /** set an application call back for receiving    */

    void setAppRcvCallback(const boost::function<void (const char*, size_t, udp::endpoint&)>& callback);



private:

 	unsigned short mLocalPort;
    boost::function<void (const char*, size_t, udp::endpoint&)> mCallBack;

  void startReceive();


  void handleReceive(const boost::system::error_code& error, std::size_t bytes_transferred);


  void handleSend(const boost::system::error_code& error,  std::size_t bytes_transferred ) ;

  udp::endpoint mRemoteEndpoint;
  boost::array<char, 512>mRecvBuffer;
  boost::shared_ptr<udpSocketobj> pSocket;
};

} //end namesapve Oal

#endif /* UDP_DEV_H_ */
