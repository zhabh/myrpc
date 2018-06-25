#include <service_mgr/service_mgr.h>
#include <boost/fiber/all.hpp>
#include <cstdlib>
#include <vector>
#include <string>
#include <functional>


namespace crucis {

	using namespace ::google::protobuf;

RpcServiceMgr::~RpcServiceMgr() {

	if (local_service_.size() > 0)
	{
		for (MapServerId::iterator itor = local_service_.begin(); itor != local_service_.end(); itor++)
		{
			for (MapObjId::iterator itor2 = itor->second.begin(); itor2 != itor->second.end(); itor2++)
			{
				delete itor2->second;
			}
			itor->second.clear();
		}

		local_service_.clear();
	}

}


bool RpcServiceMgr::AddMethod (ServiceData & svc_data, uint32 method_id, service *rpc_service) {
		if ( method_id < 0) {
			//"Method Id is INVALID");
			return false;
		}

		ServiceData *service_data = &svc_data;
		service_data->rpc_service_ = rpc_service;

		//MethodData *method_data = &service_data->_methods[method_id];
		//method_data->request_proto_ = request_proto;
		//method_data->response_proto_ = response_proto;
		return true;
}

void RpcServiceMgr::AddServer(ServiceData & svc_data, service *rpc_service) {

	ServiceData *service_data = &svc_data;
	service_data->rpc_service_ = rpc_service;
}

bool RpcServiceMgr::RegisterRpcService(service *rpc_service, uint32 service_id) 
{
	if (service_id < 0)return false;

	MapServerId::iterator itor = local_service_.find(service_id);
	if (itor != local_service_.end())
	{
		MapObjId& mapObj = itor->second;
		ServiceData *service_data = new ServiceData();

		//for(uint32 i = 0; i< rpc_service->GetMethodCount(); i++)
		//{ 
		//	//const Message *request_proto = &rpc_service->GetRequestPrototype(i);
		//	//const Message *response_proto = &rpc_service->GetResponsePrototype(i);
		//	if (!AddMethod(*service_data, i, rpc_service))
		//		return false;
		//}
		AddServer(*service_data, rpc_service);
		mapObj.insert(std::make_pair(service_data->service_obj_id_, service_data));
	}
	else
	{
		MapObjId *mapObj_new = new MapObjId();
		ServiceData *service_data_new = new ServiceData();

		//for (uint32 i = 0; i< rpc_service->GetMethodCount(); i++)
		//{
		//	//const Message *request_proto = &rpc_service->GetRequestPrototype(i);
		//	//const Message *response_proto = &rpc_service->GetResponsePrototype(i);
		//	if (!AddMethod(*service_data_new, i, rpc_service))
		//		return false;
		//}
		AddServer(*service_data_new, rpc_service);
		mapObj_new->insert(std::make_pair(service_data_new->service_obj_id_, service_data_new));
		local_service_.insert(std::make_pair(service_id, *mapObj_new));
	}

	return true;
}


service * RpcServiceMgr::GetService(uint32 service_id, uint64 service_obj_id)
{

	MapServerId::iterator itor = local_service_.find(service_id);
	if (itor == local_service_.end())
	{
		//LOG("cannot find service_id id=%d",service_id);
		return NULL;
	}

	MapObjId& mapObj = itor->second;
	MapObjId::iterator itor2 = mapObj.find(service_obj_id);
	if (itor2 != mapObj.end())
	{
		ServiceData* svc_data = itor2->second;
		return svc_data->rpc_service_;
	}
	if (mapObj.size() == 0)
	{
		return NULL;
	}

	return mapObj.begin()->second->rpc_service_;
}

//MethodData * RpcServiceMgr::GetMethod(uint32 service_id, uint32 method_id, uint64 service_obj_id)
//{
//	MapServerId::iterator itor = local_service_.find(service_id);
//	if (itor == local_service_.end())
//	{
//		//LOG("cannot find method id=%d",method_id);
//		return NULL;
//	}
//
//	MapObjId& mapObj = itor->second;
//	MapObjId::iterator itor2 = mapObj.find(service_obj_id);
//	if (itor2 != mapObj.end())
//	{
//		ServiceData* svc_data = itor2->second;
//		return &svc_data->_methods[method_id];
//	}
//	if (mapObj.size() == 0)
//	{
//		return NULL;
//	}
//
//	return &mapObj.begin()->second->_methods[method_id];
//}

void RpcServiceMgr::HandleRpcCall(std::shared_ptr< PromiseResponse > ptr_promise, const char *call_data, size_t length)
{
	std::string ret_data;
	RpcRequestData rpc_data;
	rpc_data.ParseFromArray(call_data, length);

	//RpcServiceMgr::MethodData *the_method = GetMethod(rpc_data.service_id(), rpc_data.function(), rpc_data.service_object());
	service *rpc_service = GetService(rpc_data.service_id(), rpc_data.service_object());

	std::cout << "server receive seq_id=" << rpc_data.seq_id() << std::endl;
	std::string out;
	rpc_service->CallMethod(rpc_data.function(), rpc_data.content(), out);

	RpcResponseData response_data;
	response_data.set_type(crucis::MessageType::message_type_reply);
	response_data.set_seq_id(rpc_data.seq_id()+1);
	response_data.set_service_object(rpc_data.service_id());	//暂时传服务id用于客户端测试
	response_data.set_content(out);
	response_data.SerializeToString(&ret_data);

	ptr_promise->success(ret_data);
}

void RpcServiceMgr::DispathReq(const char *call_data, size_t length, const std::function<void(std::string&)>& func)
{
	//
	auto promisep(std::make_shared< PromiseResponse >());
	boost::fibers::future< std::string > fi(promisep->get_future());

	HandleRpcCall(promisep, call_data, length);

	func(fi.get());
}

} // namespace crucis
