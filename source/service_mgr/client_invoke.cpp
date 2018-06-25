#include <service_mgr/client_invoke.h>

namespace crucis {

	void client_invoke::Echo(echo_test_stub * ctrl, const std::string& text, uint32 times)
	{
		crucis::EchoRequest request;
		request.set_text(text);
		request.set_times(times);

		ctrl->Echo(0, &request);
	}

	void client_invoke::AddUser(create_user_test_stub * ctrl, uint64 uid, const std::string & nick_name, uint32 seq_id, bool online)
	{
		crucis::AddUserRequest request;
		request.set_uid(uid);
		request.set_nick_name(nick_name);
		request.set_seq_id(seq_id);
		request.set_online(online);

		ctrl->AddUser(0, &request);
	}
} // namespace crucis