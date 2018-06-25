#ifndef _CRUCIS_SVC_NAME2ID_H_
#define _CRUCIS_SVC_NAME2ID_H_
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>

#define ALL_SERVICEs_CFG "services.cfg"

namespace crucis {

using namespace std;

class SERVICE_NAME2ID {
	
	map<string, unsigned int> _ServiceName2IdTbl;

public:
	inline bool Init()	{
		//ifstream in(ALL_SERVICEs_CFG);
		//if (in.fail())
		//	ErrorRet("Open service cfg Read failed", -1);
		const int MAX_SERVICE_NAME_LEN = 256;
		char ServiceName[MAX_SERVICE_NAME_LEN]="EchoServer";
		unsigned int id = 1;
		//while (in.getline(ServiceName, MAX_SERVICE_NAME_LEN)) {
		//	_ServiceName2IdTbl[ServiceName] = id++;
		//}
		_ServiceName2IdTbl[ServiceName] = id++;
		return true;	
	}

	unsigned int RpcServiceName2Id(const char *service_name) {
		map<string, unsigned int>::iterator the_iter = _ServiceName2IdTbl.find(service_name);
		if (the_iter == _ServiceName2IdTbl.end())
			return INVALID_SERVICE_ID;
		return the_iter->second;
	}
	SERVICE_NAME2ID() {Init();}

	static SERVICE_NAME2ID *instance() {
		static SERVICE_NAME2ID i;
		return &i;
	}
};

} // namespace crucis

#endif // _CRUCIS_SVC_NAME2ID_H_
