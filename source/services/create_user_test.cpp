
//auto generate code

#include <services/create_user_test.h>

namespace crucis {

create_user_test_server::~create_user_test_server(){}
void create_user_test_server::CallMethod(uint32 method_id, const std::string& input, std::string& out_string)
{
    switch (method_id) {
  case 0:
        {
           ::crucis::AddUserRequest request;
           request.ParseFromString(input);
           AddUser(out_string, request.uid(),request.nick_name(),request.seq_id(),request.online());
           break;
        }
        default:
           break;

    }
}

//======================================

create_user_test_stub::create_user_test_stub(std::shared_ptr<RpcChannel> channel)
    : channel_(channel){}

    create_user_test_stub::~create_user_test_stub() {}
    void create_user_test_stub::AddUser (uint32 method, const ::crucis::AddUserRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }


} // namespace crucis



