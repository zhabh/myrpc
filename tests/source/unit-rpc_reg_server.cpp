#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include "catch.hpp"
#include "boost/asio.hpp"
#include <thread>
#include <common/common.h>
#include <common/rpc_helper.h>
#include <rpc_server/rpc_channel.h>
#include <service_mgr/rpc_server.h>
#include <service_mgr/client_invoke.h>
#include <services/implement.h>
#include "spdlog/spdlog.h" 

using namespace crucis;

class player
{
public:
	player(uint64 obj_id):obj_id_(obj_id){}
	virtual ~player(){}
	void ShowSelf() { std::cout << "player id =" << obj_id_ << std::endl; }
private:
	uint64 obj_id_;
};

class player_mgr
{
public:
	~player_mgr()
	{
		if (MapPlayer_.size() < 1)
			return;
		typedef std::map<uint64, player*>::iterator ITOR;
		for (ITOR itor = MapPlayer_.begin(); itor != MapPlayer_.end(); itor++)
		{
			delete itor->second;
		}

		MapPlayer_.clear();
	}

	bool CreatePlayer()
	{
		uint64 id = 1000 + GenerateSequenceId();
		MapPlayer_.insert(std::make_pair(id,new player(id)));
		return true;
	}

	static player_mgr * Instance()
	{
		static player_mgr ins_;
		return &ins_;
	}
private:
	std::map<uint64, player*> MapPlayer_;

private:
	player_mgr() {}
	CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(player_mgr);

};

void send_test()
{

}

void init_server()
{
	
}

TEST_CASE("RPC server")
{
	
	
}



