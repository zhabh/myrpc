#ifndef _CRUCIS_CLIENT_INVOKE_H_
#define _CRUCIS_CLIENT_INVOKE_H_

#include <common/common.h>
#include <string>
#include <services/echo_test.h>
#include <services/create_user_test.h>

namespace crucis {

class client_invoke
{
public:
	static void Echo(echo_test_stub * ctrl, const std::string& text, uint32 times);
	static void AddUser(create_user_test_stub * ctrl, uint64 uid, const std::string & nick_name, uint32 seq_id, bool online);

};

} // namespace crucis

#endif // _CRUCIS_CLIENT_INVOKE_H_