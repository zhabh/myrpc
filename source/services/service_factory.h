
//auto generate code
#ifndef _CRUCIS_SERVICE_FACTORY_H_
#define _CRUCIS_SERVICE_FACTORY_H_

#include <string>
#include <common/common.h>
#include <services/service.h>
#include <rpc_server/rpc_channel.h>
#include <services/crucis/service_factory_param_define.pb.h>

namespace crucis {

class service_factory_server
 : public service
{
protected:
	// This class should be treated as an abstract interface.
	inline service_factory_server() {};

public:
    virtual ~service_factory_server();
    virtual void NewServiceSingleton (std::string & out
                           , unsigned int serviceType
                           ){}
virtual void NewService (std::string & out
                           , unsigned int serviceType
                           , unsigned long objectId
                           ){}
virtual void SyncServices (std::string & out
                           , listunsigned int serviceTypes
                           , listunsigned int serviceIds
                           ){}
virtual void BindService (std::string & out
                           , int serviceType
                           ){}
virtual void AuthResult (std::string & out
                           , enum_auth_error_code result
                           ){}
virtual void deleteService (std::string & out
                           , unsigned long objectId
                           ){}
virtual void ReloadService (std::string & out
                           , unsigned int serviceType
                           , unsigned long objectId
                           ){}


    uint32 GetMethodCount() { return 7; }
    uint32 GetServiceId() { return 0; }
    void CallMethod(uint32 method_id, const std::string& input, std::string& out_string);

private:
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(service_factory_server);
};

class service_factory_stub
: public service_factory_server
{
public:
    service_factory_stub(std::shared_ptr<RpcChannel> channel);
    ~service_factory_stub();

    inline std::shared_ptr<RpcChannel> channel() { return channel_; }

// implements ------------------------------------------
    void NewServiceSingleton (uint32 method, const ::crucis::NewServiceSingletonRequest * request);
void NewService (uint32 method, const ::crucis::NewServiceRequest * request);
void SyncServices (uint32 method, const ::crucis::SyncServicesRequest * request);
void BindService (uint32 method, const ::crucis::BindServiceRequest * request);
void AuthResult (uint32 method, const ::crucis::AuthResultRequest * request);
void deleteService (uint32 method, const ::crucis::DeleteServiceRequest * request);
void ReloadService (uint32 method, const ::crucis::ReloadServiceRequest * request);


private:
    std::shared_ptr<RpcChannel> channel_;
    CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(service_factory_stub);
};


} // namespace crucis

#endif // _CRUCIS_SERVICE_FACTORY_H_





