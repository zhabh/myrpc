
//auto generate code

#include <services/service_factory.h>

namespace crucis {

service_factory_server::~service_factory_server(){}
void service_factory_server::CallMethod(uint32 method_id, const std::string& input, std::string& out_string)
{
    switch (method_id) {
  case 0:
        {
           ::crucis::NewServiceSingletonRequest request;
           request.ParseFromString(input);
           NewServiceSingleton(out_string, request.serviceType());
           break;
        }
  case 1:
        {
           ::crucis::NewServiceRequest request;
           request.ParseFromString(input);
           NewService(out_string, request.serviceType(),request.objectId());
           break;
        }
  case 2:
        {
           ::crucis::SyncServicesRequest request;
           request.ParseFromString(input);
           SyncServices(out_string, request.serviceTypes(),request.serviceIds());
           break;
        }
  case 3:
        {
           ::crucis::BindServiceRequest request;
           request.ParseFromString(input);
           BindService(out_string, request.serviceType());
           break;
        }
  case 4:
        {
           ::crucis::AuthResultRequest request;
           request.ParseFromString(input);
           AuthResult(out_string, request.result());
           break;
        }
  case 5:
        {
           ::crucis::DeleteServiceRequest request;
           request.ParseFromString(input);
           deleteService(out_string, request.objectId());
           break;
        }
  case 6:
        {
           ::crucis::ReloadServiceRequest request;
           request.ParseFromString(input);
           ReloadService(out_string, request.serviceType(),request.objectId());
           break;
        }
        default:
           break;

    }
}

//======================================

service_factory_stub::service_factory_stub(std::shared_ptr<RpcChannel> channel)
    : channel_(channel){}

    service_factory_stub::~service_factory_stub() {}
    void service_factory_stub::NewServiceSingleton (uint32 method, const ::crucis::NewServiceSingletonRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::NewService (uint32 method, const ::crucis::NewServiceRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::SyncServices (uint32 method, const ::crucis::SyncServicesRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::BindService (uint32 method, const ::crucis::BindServiceRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::AuthResult (uint32 method, const ::crucis::AuthResultRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::deleteService (uint32 method, const ::crucis::DeleteServiceRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }
void service_factory_stub::ReloadService (uint32 method, const ::crucis::ReloadServiceRequest * request)
    {
      channel_->CallMethod(GetServiceId(), method, request);
    }


} // namespace crucis



