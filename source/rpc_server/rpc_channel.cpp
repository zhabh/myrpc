#include <boost/asio.hpp>
#include <rpc_server/rpc_channel.h>
#include <rpc_server/svc_name2id.h>
#include <google/protobuf/message.h>
#include <connect_mgr/process_queue.h>



namespace crucis {

	//thread_local boost::fibers::asio::yield_t yield;

	RpcChannel::RpcChannel(boost::asio::io_context& io_context, const char *connect_str)
		:io_context_(io_context),
		socket_(io_context),
		_conn_str(connect_str)
	{
		Connect();
	}

	RpcChannel::~RpcChannel() {
		close();
	}

	void RpcChannel::CallMethod(uint32 service_id, uint32 method, const Message *request)
	{
		if (is_closed())
		{
			if (!Connect())
			{
				return;
			}
		}
		
		Init_request(service_id, method, (MessageType)0, request);
		
		do_write();
		//boost::fibers::fiber(
		//	std::bind(&RpcChannel::do_write, shared_from_this())).detach();

	}

	bool RpcChannel::Connect() 
	{
		size_t split_pos = _conn_str.find(':');
		if (split_pos == std::string::npos) {
			return false;
		}
		std::string ip_str = _conn_str.substr(0, split_pos);
		std::string port_str = _conn_str.substr(split_pos + 1);

		tcp::resolver resolver(io_context_);
		boost::asio::connect(socket_, resolver.resolve(ip_str, port_str));
		set_connect_state(true);
		
		return true;
	}

	bool RpcChannel::Init_request(unsigned int service_id, int method_id, int msg_type, const Message *request)
	{
		return req_info_.Init(service_id, method_id, msg_type, request);
	}

	void RpcChannel::do_write()
	{
		boost::system::error_code ec;
		thread_local boost::fibers::asio::yield_t yield;

		std::string *pMsg = new std::string();
		req_info_.to_buffers(*pMsg);

		boost::asio::write(
			socket_,
			boost::asio::buffer(pMsg->c_str(), pMsg->length()));
		if (ec == boost::asio::error::eof) {
			//connection closed cleanly by peer
		}
		else if (ec) {
			//throw boost::system::system_error(ec); //some other error
		}

		do_read();
		/*boost::fibers::fiber(
			std::bind(&RpcChannel::do_read, shared_from_this())).detach();*/

	}

	void RpcChannel::do_read()
	{
		boost::system::error_code ec;
		std::size_t length;
		thread_local boost::fibers::asio::yield_t yield;

		memset(head_buff_, 0, sizeof(head_buff_));
		length = boost::asio::read(
			socket_,
			boost::asio::buffer(head_buff_, sizeof(unsigned int)));
		if (ec == boost::asio::error::eof) {
			//connection closed cleanly by peer
		}
		else if (ec) {
			throw boost::system::system_error(ec); //some other error
		}


		unsigned int uLength = 0;
		char* len = (char*)&uLength;
		memcpy(len, head_buff_, sizeof(uLength));

		memset(buffer_, 0, sizeof(buffer_));

		length = boost::asio::read(socket_,
			boost::asio::buffer(buffer_, uLength));

		if (ec == boost::asio::error::eof) {
			//connection closed cleanly by peer
		}
		else if (ec) {
			throw boost::system::system_error(ec); //some other error
		}
		std::cout << "client receive body len=" << length << std::endl;


		RpcResponseData rpc_data;
		rpc_data.ParseFromArray(buffer_, strlen(buffer_));

		if (1 == rpc_data.service_object())
		{
			EchoResponse echo_response;
			echo_response.ParseFromArray(rpc_data.content().c_str(), rpc_data.content().length());

			std::cout << "client EchoResponse seq_id=" << rpc_data.seq_id() << std::endl;
			std::cout << "client EchoResponse ret=" << echo_response.ret().c_str() << std::endl;
		}
		else if(2 == rpc_data.service_object())
		{
			AddUserResponse rep;
			rep.ParseFromArray(rpc_data.content().c_str(), rpc_data.content().length());

			std::cout << "client AddUserResponse seq_id=" << rpc_data.seq_id() << std::endl;

			std::cout << "client AddUserResponse card_id=" << rep.ret().card_id() << std::endl;
			std::cout << "client AddUserResponse code=" << rep.ret().code() << std::endl;


		}

		std::cout << "\n\n";

		stop_context();
	}

	/*void RpcChannel::do_read_body()
	{
		auto self(shared_from_this());

		unsigned int uLength = 0;
		char* len = (char*)&uLength;
		memcpy(len, head_buff_, sizeof(uLength));

		memset(buffer_, 0, sizeof(buffer_));

		boost::asio::async_read(socket_,
			boost::asio::buffer(buffer_, uLength),
			[this, self](boost::system::error_code ec, std::size_t length)
		{
			std::cout << "client receive body len=" << length << std::endl;

			if (!ec)
			{
				RpcResponseData rpc_data;
				EchoResponse echo_response;
				rpc_data.ParseFromArray(buffer_, strlen(buffer_));
				echo_response.ParseFromArray(rpc_data.content().c_str(), rpc_data.content().length());

				rpc_data.content();
				std::cout << "return seq_id=" << rpc_data.seq_id() << std::endl;
				std::cout << "return ret="<< echo_response.ret().c_str() << std::endl;

				stop_context();
			}
		});
	}*/

	void RpcChannel::stop_context()
	{
		io_context_.stop();
	}

	void RpcChannel::close()
	{
		set_connect_state(false);

		socket_.close();
	}


} // namespace crucis
