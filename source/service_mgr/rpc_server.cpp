#include <boost/asio/spawn.hpp>
#include <boost/asio/io_context.hpp>
#include <service_mgr/rpc_server.h>
#include <rpc_server/svc_name2id.h>
#include <signal.h>
#include <utility>
#include <boost/fiber/all.hpp>

namespace crucis {

using boost::asio::ip::tcp;

rpc_server::rpc_server(std::shared_ptr< boost::asio::io_context > const& io_context, RpcServiceMgr & srv_mgr)
	: socket_(*io_context),
	signals_(*io_context),
	service_mgr_(srv_mgr),
	connection_manager_()
{
	// Register to handle the signals that indicate when the server should exit.
	// It is safe to register for the same signal multiple times in a program,
	// provided all registration for the specified signal is made through Asio.
	signals_.add(SIGINT);
	signals_.add(SIGTERM);
#if defined(SIGQUIT)
	signals_.add(SIGQUIT);
#endif // defined(SIGQUIT)

	//do_await_stop();

	// Open the acceptor with the option to reuse the address (i.e. SO_REUSEADDR).
	//tcp::resolver resolver(io_context_);
	//tcp::endpoint endpoint =
	//	*resolver.resolve(address, port).begin();
	//acceptor_.open(endpoint.protocol());
	//acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
	//acceptor_.bind(endpoint);
	//acceptor_.listen();

}

void rpc_server::run()
{
	connection_ptr connect_prt = std::make_shared<connection>(
		std::move(socket_), connection_manager_, service_mgr_);

	connection_manager_.start(connect_prt);

}

bool rpc_server::RegisterService(service *service) {
	if (service == NULL)
		return false;
	/*unsigned int svc_id = SERVICE_NAME2ID::instance()->RpcServiceName2Id(sd->name().c_str());*/
	return service_mgr_.RegisterRpcService(service, service->GetServiceId());
}

//void rpc_server::do_accept()
//{
//
//	for (;;) {
//
//		if (!acceptor_.is_open())
//		{
//			return;
//		}
//
//		boost::system::error_code ec;
//		tcp::socket socket(io_context_);
//		connection_ptr connect_prt = std::make_shared<connection>(
//			std::move(socket), connection_manager_, service_mgr_);
//		
//		acceptor_.async_accept(socket, boost::fibers::asio::yield[ec]);
//
//		if (!ec) {
//			// run the new subscriber in its own fiber (one fiber for one client)
//			boost::fibers::fiber(
//				std::bind(&connection::start, connect_prt)).detach();
//		}
//	}
//
//}

//void rpc_server::do_await_stop()
//{
//
//	boost::asio::spawn(io_context_,
//		[this](boost::asio::yield_context yield)
//	{
//		boost::system::error_code ec;
//		//int signo;
//		signals_.async_wait(yield[ec]);
//
//		acceptor_.close();
//		connection_manager_.stop_all();
//
//	});
//
//}

} // namespace crucis
