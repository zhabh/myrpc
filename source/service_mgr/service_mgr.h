#ifndef _CRUCIS_SERVICE_MGR_H_
#define _CRUCIS_SERVICE_MGR_H_
#include "boost/asio.hpp"
#include <common/common.h>
#include <common/rpc_helper.h>
#include <rpc_server/pb_header.h>
#include <services/service.h>
#include <connect_mgr/future_t.h>

namespace crucis {

class RpcServiceMgr  {
public:

	struct MethodData {
		
	};

	struct ServiceData {
		ServiceData() 
		{
			service_obj_id_ = GetnerateServiceObjectID(); 
		}
		uint64 service_obj_id_;
		service *rpc_service_;
		//MethodData _methods[MAX_SERVICE_METHODs];
	};

private:
	typedef std::map<uint64, ServiceData* > MapObjId;
	typedef std::map<uint32, MapObjId > MapServerId;
	MapServerId local_service_;
	//MapContainer _remote_service;
	ServiceData *services_;

protected:
	bool AddMethod(ServiceData& svc_data, uint32 method_id, service *rpc_service);
	void AddServer(ServiceData & svc_data, service *rpc_service);

	service * GetService(uint32 service_id, uint64 service_obj_id);

public:
	RpcServiceMgr(){/*_services = new ServiceData[MAX_RPC_SERVICEs];*/}
	~RpcServiceMgr();

	//MethodData * GetMethod(uint32 service_id, uint32 method_id, uint64 service_obj_id);
	void HandleRpcCall(std::shared_ptr< PromiseResponse > ptr_promise, const char *call_data, size_t length);
	bool RegisterRpcService(service *rpc_service, uint32 service_id);

	void DispathReq(const char *call_data, size_t length, const std::function<void(std::string&)>& func);
};

} // namespace crucis

#endif // _CRUCIS_SERVICE_MGR_H_
