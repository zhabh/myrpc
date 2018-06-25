#include <iostream>
#include <thread>
#include <common/rpc_helper.h>
#include "catch.hpp"
#include "boost/asio.hpp"


using namespace crucis;


void gen1(int cnt)
{
	while (cnt--)
	{
		std::cout <<GenerateSequenceId() << std::endl;
	}
}


TEST_CASE("generator id")
{
	int cnt = 10;
	init_id_generator(12, 5);

	std::thread t1(gen1,cnt);
	std::thread t2(gen1,cnt);
	std::thread t3(gen1,cnt);

	t1.join();
	t2.join();
	t3.join();

	Sleep(10000);
}



