
//auto generate code
#ifndef _CRUCIS_ECHO_TEST_H_
#define _CRUCIS_ECHO_TEST_H_

#include <string>
#include <common/common.h>
#include <services/service.h>
#include <rpc_server/rpc_channel.h>
#include <services/crucis/echo_test_param_define.pb.h>

namespace crucis {

class echo_test_server
 : public service
{
protected:
	// This class should be treated as an abstract interface.
	inline echo_test_server() {};

public:
    virtual ~echo_test_server();
    virtual void Echo (std::string & out
                           , std::string text
                           , int times
                           ){}


    uint32 GetMethodCount() { return 1; }
    uint32 GetServiceId() { return 1; }
    void CallMethod(uint32 method_id, const std::string& input, std::string& out_string);

private:
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(echo_test_server);
};

class echo_test_stub
: public echo_test_server
{
public:
    echo_test_stub(std::shared_ptr<RpcChannel> channel);
    ~echo_test_stub();

    inline std::shared_ptr<RpcChannel> channel() { return channel_; }

// implements ------------------------------------------
    void Echo (uint32 method, const ::crucis::EchoRequest * request);


private:
    std::shared_ptr<RpcChannel> channel_;
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(echo_test_stub);
};


} // namespace crucis

#endif // _CRUCIS_ECHO_TEST_H_





