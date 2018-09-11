/*
 Name        : udp_dev.cpp
 Author      : Lisa
 Description : Udp device boost wrapper
 	 	 	 	 /* Send and receive are independent with each other.
				 * Receiving: it will receive all the packets sent to it. An application callback is used to relay the data out.
				 *	Sending: it is separated from reading. It can send data to any specified destinations (IP address & port number).
				 *	After network unreached issue, it will cancel previous all async work and re initialized
 */

#include <iostream>
#include "UdpDevice.h"


using namespace boost::asio;
namespace Oal{


void udp_dev::read()
	{
		pSocket->mIo.post(boost::bind(&udp_dev::startReceive, this));//create work for io_service
		boost::thread t(boost::bind(&asio::io_service::run, &pSocket->mIo)); //  create thread to run io_service
		pSocket->mThread.swap(t); //start thread of run(),give io_service oppertunity to run the work
	}

void udp_dev::start()
{
 read();
}
void udp_dev::stop()
{
	pSocket->mSocket.cancel();
}
bool udp_dev::isOpen()
{
	return pSocket->mSocket.is_open();
}
	void udp_dev::sendMessage(boost::shared_ptr<std::string> message, string ip, unsigned short port )
	{
		std::cout << "sendMessage...." << std::endl;
		boost::asio::ip::address_v4 targetIP = boost::asio::ip::address_v4::from_string(ip);
		udp::endpoint endp;
		endp.address(targetIP);
		endp.port(port);

		pSocket->mSocket.async_send_to(boost::asio::buffer(*message), endp,
		boost::bind(&udp_dev::handleSend, this,// message,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
	}
	//sending message with data size limit
	void udp_dev::sendMessage(boost::shared_ptr<std::string> message,size_t bytes, string ip, unsigned short port )
		{
			std::cout << "sendMessage...." << std::endl;
			boost::asio::ip::address_v4 targetIP = boost::asio::ip::address_v4::from_string(ip);
			udp::endpoint endp;
			endp.address(targetIP);
			endp.port(port);

			pSocket->mSocket.async_send_to(boost::asio::buffer(*message,bytes), endp,
			boost::bind(&udp_dev::handleSend, this,// message,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
		}
    /** set an application callback for receiving
     */
    void udp_dev::setAppRcvCallback(const boost::function<void (const char*, size_t, udp::endpoint&)>& callback)
    {
    	mCallBack=callback;
    }


  void udp_dev::startReceive()
  {
	  	pSocket->mSocket.async_receive_from(
        boost::asio::buffer(mRecvBuffer), mRemoteEndpoint,
        boost::bind(&udp_dev::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
  }

  void udp_dev::handleReceive(const boost::system::error_code& error, std::size_t bytes_transferred)
  {
    if (!error || error == boost::asio::error::message_size)
    {
    	if (mCallBack)
    	{
    		mCallBack(mRecvBuffer.data(), bytes_transferred, mRemoteEndpoint);
    	}
    	else
    	{
    		//to do: buffer the data
     		cout << __FUNCTION__ << " rcvd from: " << mRemoteEndpoint.address() << ":"<< mRemoteEndpoint.port()
    		  << ":" << mRecvBuffer.data() << endl;
    	}

    	startReceive();
    }
    else
    {
  	  std::cout << " hancle_receive_ error = " << error << std::endl;
  	  read();
    }
  }


  void udp_dev::handleSend(const boost::system::error_code& error, std::size_t bytes_transferred )
  {
	  if(!isOpen())    //in case socket is closed , return and cancel
	  return;
	  std::cout << "handle _send ...error code =" << error <<std::endl; // for debug
      if(error== error::network_unreachable)
      {
    	  std::cout << "Net work unreachable ! close socket re send" <<std::endl;
    	  stop();   //any async send receive was cancelled. return with error of operation_aborted error
      }
      else if (error== error::network_down)
      {
    	  std::cout << "Net work down ! pls re_send " <<std::endl;
      }
  }

} //end namesapve Oal




