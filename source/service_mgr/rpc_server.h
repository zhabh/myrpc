#ifndef _CRUCIS_RPC_SERVER_H_
#define _CRUCIS_RPC_SERVER_H_

#include <boost/asio.hpp>
#include <string>
#include <service_mgr/service_mgr.h>
#include <connect_mgr/connection_manager.h>

namespace crucis {
	using boost::asio::ip::tcp;

class rpc_server : public std::enable_shared_from_this<rpc_server>
{
public:
	rpc_server(const rpc_server&) = delete;
	rpc_server& operator=(const rpc_server&) = delete;

	/// Construct the server to listen on the specified TCP address and port, and
	/// serve up files from the given directory.
	explicit rpc_server(std::shared_ptr< boost::asio::io_context > const& io_context, RpcServiceMgr & srv_mgr);

	/// Run the server's io_context loop.
	void run();

	bool RegisterService(service *service);

	/// Perform an asynchronous accept operation.
	void do_accept();

	tcp::socket& socket() {
		return socket_;
	}

private:

	/// Wait for a request to stop the server.
	void do_await_stop();

	/// The io_context used to perform asynchronous operations.
	//boost::asio::io_context io_context_;

	/// The signal_set is used to register for process termination notifications.
	boost::asio::signal_set signals_;

	/// Acceptor used to listen for incoming connections.
	//boost::asio::ip::tcp::acceptor acceptor_;

	tcp::socket socket_;

	/// The connection manager which owns all live connections.
	connection_manager connection_manager_;

	/// The service manager
	RpcServiceMgr& service_mgr_;
};

typedef std::shared_ptr<rpc_server> rpc_server_ptr;

} // namespace crucis

#endif // _CRUCIS_RPC_SERVER_H_