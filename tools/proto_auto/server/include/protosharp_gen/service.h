
//auto generate code

#ifndef _CRUCIS_SERVICE_H_
#define _CRUCIS_SERVICE_H_
#include <common/common.h>
#include <string>

namespace crucis {

class service  
{
public:
	inline service() {};

	virtual uint32 GetServiceId() = 0;
	virtual uint32 GetMethodCount() = 0;

	virtual void CallMethod(uint32 method_id, const std::string& input, std::string& out_string) = 0;
private:
	CRUCIS_DISALLOW_EVIL_CONSTRUCTORS(service);
	
};

} // namespace crucis

#endif // _CRUCIS_SERVICE_H_

