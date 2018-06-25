#include <services/echo_test.h>
#include <services/create_user_test.h>
#include <thread>

namespace crucis {

	class echo_test_impl
		: public echo_test_server
	{
	public:
		echo_test_impl() {}
		virtual void Echo(std::string & out
			, std::string text
			, int times
		)
		{

			std::string str;
			std::string tmp = text;
			for (int i = 1; i < times; i++)
				str += tmp;

			::crucis::EchoResponse response;
			response.set_ret(str);
			response.SerializeToString(&out);

		}


	};

	class create_user_test_impl
		: public create_user_test_server
	{
	public:
		create_user_test_impl() {}
		virtual void AddUser(std::string & out, uint64 uid, const std::string & nick_name, uint32 seq_id, bool online)
		{
			std::cout << "param uid=" << uid << ",nick_name=" << nick_name << ",seq_id=" << seq_id << std::endl;

			::crucis::AddUserResponse response;
			AddUserRes * pRes = response.mutable_ret();
			pRes->set_card_id("1001111");
			pRes->set_code((crucis::ErrorCode)1);
			response.SerializeToString(&out);

		}

	};

} // namespace crucis



