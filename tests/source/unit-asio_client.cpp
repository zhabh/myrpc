#include <cstdlib>
#include <cstring>
#include <iostream>
#include "catch.hpp"
#include "boost/asio.hpp"
#include "spdlog/spdlog.h"  

using boost::asio::ip::tcp;
enum { max_length = 1024 };

TEST_CASE("CLIENT")
{
	boost::asio::io_context io_context;

	auto console = spdlog::stderr_logger_mt("console");
	console->info("hi,this a first info log!");

	tcp::socket s(io_context);
	tcp::resolver resolver(io_context);
	boost::asio::connect(s, resolver.resolve("127.0.0.1", "3005"));

	std::cout << "Enter message: ";
	char request[max_length];
	char sName[10];
	char param[32];
	std::cin >> sName >> param;
	snprintf(request, max_length, "%s:%s", sName, param);
	
	size_t request_length = std::strlen(request);
	boost::asio::write(s, boost::asio::buffer(request, request_length));

	char reply[max_length];
	size_t reply_length = boost::asio::read(s,
		boost::asio::buffer(reply, request_length));
	std::cout << "Reply is: ";
	std::cout.write(reply, reply_length);
	std::cout << "\n";

	Sleep(2000);
	auto my_logger = spdlog::basic_logger_mt("basic_logger", "E:/file_log");
	my_logger->info("ok,end test case.");
}

		

