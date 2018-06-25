# # 文件夹结构

**.** *crucis_proto*  
**├─source** *C++代码目录*  
**│  ├─common** *全局函数工具类*  
**│  ├─connect_mgr** *服务端网络连接管理和消息处理*  
**│  ├─rpc_server** *客户端连接和消息处理*  
**│  ├─service_mgr** *封装客户端调用和服务注册类*   
**│  └─services** *服务定义和逻辑处理*   
**├─tests** *测试目录*  
**│  └─source** *测试代码*  
**│      └─unit-rpc_service.cpp** *rpc服务端客户端调用测试*  
**├─tools** *代码工具目录*  
**│  ├─tool** *代码自动生成的exe文件*  
**│  ├─proto_auto** *自动生成协议和服务的工程*  
**│  ├─proto** *临时生成.proto文件夹*  
**│  ├─auto.bat** *代码生成和代码拷贝脚本*  
**│  └─cppcode** *临时生成C++代码文件夹*  
