
//auto generate code

#include <services/echo_test.h>

namespace crucis {

echo_test_server::~echo_test_server(){}
void echo_test_server::CallMethod(uint32 method_id, const std::string& input, std::string& out_string)
{
    switch (method_id) {
  case 0:
        {
           ::crucis::EchoRequest request;
           request.ParseFromString(input);
           Echo(out_string, request.text(),request.times());
           break;
        }
        default:
           break;

    }
}

//======================================

echo_test_stub::echo_test_stub(std::shared_ptr<RpcChannel> channel)
    : channel_(channel){}

    echo_test_stub::~echo_test_stub() {}
    void echo_test_stub::Echo (uint32 method, const ::crucis::EchoRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }


} // namespace crucis



