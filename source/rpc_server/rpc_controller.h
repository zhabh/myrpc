#ifndef _CRUCIS_RPC_CONTROLLER_H_
#define _CRUCIS_RPC_CONTROLLER_H_
#include <google/protobuf/service.h>
#include <string>

namespace crucis {

using std::string;

class RpcController : public google::protobuf::RpcController 
{
	string _error_str;
	bool _is_failed;
	public:
	RpcController() { Reset(); }
	void Reset() {
		_error_str = "";
		_is_failed = false;
	}
	bool Failed() const {
		return _is_failed;
	}
	string ErrorText() const {
		return _error_str;
	}
	void StartCancel() { // NOT IMPL
		return ;
	}
	void SetFailed(const string &reason) {
		_is_failed = true;
		_error_str = reason;
	}
	bool IsCanceled() const { // NOT IMPL
		return false;
	}
  		
	void NotifyOnCancel(google::protobuf::Closure* callback) { // NOT IMPL
		return;
	}
};

} // namespace crucis

#endif // _CRUCIS_RPC_CONTROLLER_H_