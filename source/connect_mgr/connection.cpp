#include <connect_mgr/connection.h>
#include <service_mgr/service_mgr.h>
#include <rpc_server/rpc_controller.h>
#include <connect_mgr/process_queue.h>
#include <cstdlib>
#include <utility>
#include <vector>
#include <memory>

namespace crucis {

connection::connection(boost::asio::ip::tcp::socket socket,
    connection_manager& manager, RpcServiceMgr& rpc_service_mgr)
  : socket_(std::move(socket)),
    connection_manager_(manager),
    rpc_service_mgr_(rpc_service_mgr)
{
}

void connection::start()
{

	try {
		boost::system::error_code ec;
		std::size_t length;
		thread_local boost::fibers::asio::yield_t yield;

		for (;;) {

			memset(head_buff_, 0, sizeof(head_buff_));
			length = boost::asio::async_read(
				socket_,
				boost::asio::buffer(head_buff_, sizeof(unsigned int)),
				yield[ec]);
			if (ec == boost::asio::error::eof) {
				break; //connection closed cleanly by peer
			}
			else if (ec) {
				throw boost::system::system_error(ec); //some other error
			}

			std::cout << "server receive head len=" << length << std::endl;

			unsigned int uLength = 0;
			char* len = (char*)&uLength;
			memcpy(len, head_buff_, sizeof(uLength));

			memset(buffer_, 0, sizeof(buffer_));

			length = boost::asio::async_read(socket_, 
				boost::asio::buffer(buffer_, uLength), 
				yield[ec]);

			if (ec == boost::asio::error::eof) {
				break; //connection closed cleanly by peer
			}
			else if (ec) {
				throw boost::system::system_error(ec); //some other error
			}

			std::cout << "server receive body len=" << length << std::endl;
			  
			boost::fibers::fiber(
				std::bind(&connection::do_work, shared_from_this(), buffer_, strlen(buffer_))).detach();
			  
		}
	}
	catch (std::exception const& e) {
		std::cerr << "read msg failed: " << e.what() << std::endl;
	}
	stop();
}

void connection::stop()
{
  socket_.close();
}

void connection::do_work(const char * req, size_t length)
{
	rpc_service_mgr_.DispathReq(req, length, [this](std::string const& msg) {
		do_write(msg);
	}
	);
}
void connection::do_write(std::string const& msg)
{
	boost::system::error_code ec;
	thread_local boost::fibers::asio::yield_t yield;

	unsigned int tLen = msg.size();
	//if (tLen < 1) return buffers;
	char* pLen = (char*)&tLen;
	std::string *pMsg = new std::string();
	pMsg->append(pLen, sizeof(tLen));
	pMsg->append(msg);

	boost::asio::async_write(
		socket_,
		boost::asio::buffer(pMsg->c_str(), pMsg->length()),
		yield[ec]);
	if (ec == boost::asio::error::eof) {
		//connection closed cleanly by peer
	}
	else if (ec) {
		//throw boost::system::system_error(ec); //some other error
	}

}

} // namespace crucis
