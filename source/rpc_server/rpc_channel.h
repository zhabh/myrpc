#ifndef _CRUCIS_RPC_CHANNEL_H_
#define _CRUCIS_RPC_CHANNEL_H_

#include <google/protobuf/service.h>
#include <string>
#include <rpc_server/request_info.h>
#include <boost/fiber/all.hpp>

//暂时测试，后面分离开
#include <services/crucis/echo_test_param_define.pb.h>
#include <services/crucis/create_user_test_param_define.pb.h>

namespace crucis {
using boost::asio::ip::tcp;
using google::protobuf::Message;

class RpcChannel : public std::enable_shared_from_this<RpcChannel>
{
public:
	RpcChannel(boost::asio::io_context& io_context, const char *connect_str);

	/*RpcChannel(const std::string& server_ip,
		uint32 server_port) {};*/

	virtual ~RpcChannel();
	virtual void CallMethod(uint32 service_id, uint32 method, const Message *request);

	bool Connect();

	void close();

	bool is_closed() { return !connected_; }

	void set_connect_state(bool b) { connected_ = b; }

	bool Init_request(unsigned int service_id, int method_id, int msg_type, const Message *request);

	void do_write();
	void do_read();

	//void do_read_body();

	void stop_context();
private:
	bool connected_;

	boost::asio::io_context& io_context_;
	tcp::socket socket_;

	char head_buff_[4] = { 0 };

	/// Buffer for incoming data.
	char buffer_[8192] = { 0 };

	request_info req_info_;

private:
	//RpcClient* _client;
	std::string _conn_str;		//"0.0.0.0:1234"
};

} // namespace crucis

#endif // _CRUCIS_RPC_CHANNEL_H_