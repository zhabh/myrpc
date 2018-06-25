#include <cstdlib>
#include <cstring>
#include <iostream>
#include "catch.hpp"
#include "boost/asio.hpp"
#include <thread>
#include "spdlog/spdlog.h" 
#include <rpc_server/rpc_channel.h>

#include <service_mgr/rpc_server.h>
#include <service_mgr/client_invoke.h>
#include <services/implement.h>
#include <boost/fiber/all.hpp>
#include <common/round_robin.hpp>

using namespace crucis;
using boost::asio::ip::tcp;

void send_test()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	boost::asio::io_context io_context;
	std::shared_ptr<RpcChannel> channel = std::make_shared<RpcChannel>(io_context,"127.0.0.1:3005");
	echo_test_stub echo_clt(channel);
	create_user_test_stub msg_clt(channel);

	client_invoke::Echo(&echo_clt, "test1", 4);
	io_context.run();

	io_context.restart();
	client_invoke::Echo(&echo_clt, "test2", 5);

	io_context.restart();
	client_invoke::AddUser(&msg_clt, (uint64)100, "aaa", 333, true);


}

void accept_delate(std::shared_ptr< boost::asio::io_service > const& io_svc, 
	tcp::acceptor & acceptor, 
	RpcServiceMgr & srv_mgr) {

	thread_local boost::fibers::asio::yield_t yield;

	// loop for accepting connection requests
	for (;;) {

		if (!acceptor.is_open())
		{
			return;
		}

		boost::system::error_code ec;

		rpc_server_ptr new_rpc_server =
			std::make_shared< rpc_server >(io_svc, std::ref(srv_mgr));

		acceptor.async_accept(
			new_rpc_server->socket(),
			yield[ec]);
		if (!ec) {
			// run the new subscriber in its own fiber (one fiber for one client)
			boost::fibers::fiber(
				std::bind(&rpc_server::run, new_rpc_server)).detach();
		}
	}
}

void init_server()
{
	std::shared_ptr< boost::asio::io_context > io_context = std::make_shared< boost::asio::io_context >();
	boost::fibers::use_scheduling_algorithm< boost::fibers::asio::round_robin >(io_context);

	echo_test_impl *impl = new echo_test_impl();
	create_user_test_impl *msg_impl = new create_user_test_impl();

	RpcServiceMgr service_mgr;
	service_mgr.RegisterRpcService(impl, impl->GetServiceId());
	service_mgr.RegisterRpcService(msg_impl, msg_impl->GetServiceId());

	tcp::acceptor a(*io_context, tcp::endpoint(tcp::v4(), 3005));

	boost::fibers::fiber(
		accept_delate, io_context, std::ref(a), std::ref(service_mgr)).detach();


	io_context->run();
}

TEST_CASE("RPC server")
{
	
	std::thread t1(init_server);
	std::thread t2(send_test);

	t1.detach();
	t2.detach();

	Sleep(100000);
}



