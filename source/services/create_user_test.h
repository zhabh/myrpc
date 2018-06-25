
//auto generate code
#ifndef _CRUCIS_CREATE_USER_TEST_H_
#define _CRUCIS_CREATE_USER_TEST_H_

#include <string>
#include <common/common.h>
#include <services/service.h>
#include <rpc_server/rpc_channel.h>
#include <services/crucis/create_user_test_param_define.pb.h>

namespace crucis {

class create_user_test_server
 : public service
{
protected:
	// This class should be treated as an abstract interface.
	inline create_user_test_server() {};

public:
    virtual ~create_user_test_server();
    virtual void AddUser (std::string & out
                           , unsigned long uid
                           , std::string nick_name
                           , unsigned int seq_id
                           , bool online
                           ){}


    uint32 GetMethodCount() { return 1; }
    uint32 GetServiceId() { return 1; }
    void CallMethod(uint32 method_id, const std::string& input, std::string& out_string);

private:
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(create_user_test_server);
};

class create_user_test_stub
: public create_user_test_server
{
public:
    create_user_test_stub(std::shared_ptr<RpcChannel> channel);
    ~create_user_test_stub();

    inline std::shared_ptr<RpcChannel> channel() { return channel_; }

// implements ------------------------------------------
    void AddUser (uint32 method, const ::crucis::AddUserRequest * request);


private:
    std::shared_ptr<RpcChannel> channel_;
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(create_user_test_stub);
};


} // namespace crucis

#endif // _CRUCIS_CREATE_USER_TEST_H_





