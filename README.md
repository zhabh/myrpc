
# 简介
客户端和服务器端网络通信协议生成以及调度功能模组
* 采用rpc架构，客户端像调用本地服务一样调用远程服务，让远程服务调用更简单、透明
* 根据游戏功能不断迭代的特点，增加服务不影响原有服务，通过修改配置文件能快速部署新服务接口
* 支持服务实例的扩展，相同服务可部署多个服务实例提高服务能力。


## 服务定义简单
用户只需要编辑C#的通信协议文件，支持直接加载协议的dll文件，使用proto_auto工具便可自动生成自定义格式的协议文件和rpc服务C++代码，开发人员仅需要实现相关服务代码的逻辑并注册到服务上，就能实现整个rpc通信。

## 支持数据类型灵活
用户协议支持的参数类型包括enum类型，struct类型和string,uint64,uint32,bool,float,double等原生类型,从而可以满足大部分游戏业务需要。

## 内部通信高效且轻量级
底层网络通信使用boost-asio异步通信,使用第三方高效率的通信库,系统更稳定代码简洁易懂.

##自定义网络通信格式
采用自定义网络包的设计，保证数据的可靠性和安全性，一方面由TCP协议保证，同时可扩展加密算法和防伪造包验证等功能。

# rpc实现模型
现代rpc框架实现大部分基于上世纪80年代Bruce Jay Nelson的论文模型,crucis_proto的rpc实现同样基于如下几个组件
* User

* User-stub

* RPCRuntime

* erver-stub

* Server
 
    关系如下图所示：![rpc-frame.png](doc/rpc-frame.png)


# 底层通信消息定义
每个请求包结构为: RpcRequestData长度 + RpcRequestData结构

返回包同理, 由RpcResponseData 长度 + RpcResponseData 内容组成, content 保存返回结构体序列化后的数据

# 快速入门
下面以 create_user_test 服务为例子介绍怎么生成服务和调用。该服务定义一个创建角色的接口
## 1.添加服务
首先定义协议文件create_user_test.cs,加入到myrpc\tools\proto_auto\CofProtoDesc文件夹下，编译myrpc\tools\proto_auto\proto_auto.sln工程。
create_user_test.cs内容摘要:

```csharp
    [Desc("错误码")]
    public enum ErrorCode
    {
        [Desc("成功")]
        OK = 1,
       ...
    }

    [Desc("返回结果")]
    public class AddUserRes
    {
        [Index(1)]
        [Label(LabelType.Required)]
        [Desc("card_id")]
        public PSString CardId;
		...
    }

    [Index(1)]
    [ImitateSingleton]
    interface create_user_test
    {
        [Index(1)]
        [Desc("创建用户例子")]
        AddUserRes AddUser(PSUInt64 uid, 
                           PSString nick_name, 
                           PSUInt32 seq_id, 
                           PSBoolean online);
    }
```

## 2.生成代码
运行\myrpc\tools\auto.bat，该文件自动进行如下几步操作:

* 1)文件可以生成自定义的协议文件create_user_test_param_define,它包含接口的输入和输出参数的结构

* 2)自动生成服务实现的基础代码create_user_test.{h,cpp}

* 3)并拷贝上面所有的{.h,.cpp}文件到C++工程目录myrpc\source\services

## 3.实现服务
在如下代码中添加服务器端的逻辑代码 "myrpc\source\services\implement.h"

```c++
class create_user_test_impl : public create_user_test_server {
 public:
  virtual void AddUser(std::string & out, uint64 uid, 
      const std::string & nick_name, uint32 seq_id, bool online) {
      ...
  }
};
```

## 4.注册服务
```c++
create_user_test_impl *msg_impl = new create_user_test_impl();

RpcServiceMgr service_mgr;
service_mgr.RegisterRpcService(msg_impl, msg_impl->GetServiceId());	
```

## 5.客户端调用服务
```c++
boost::asio::io_context io_context;
std::shared_ptr<RpcChannel> channel = 
    std::make_shared<RpcChannel>(io_context,"127.0.0.1:3005");

create_user_test_stub msg_clt(channel);
client_invoke::AddUser(&msg_clt, (uint64)100, "aaa", 333, true);
io_context.run();
```
## 6.客户端接收返回结果
```c++
RpcResponseData rpc_data;
rpc_data.ParseFromArray(buffer_, strlen(buffer_));
AddUserResponse rep;
rep.ParseFromArray(rpc_data.content().c_str(), rpc_data.content().length());

std::cout << "client AddUserResponse seq_id=" << rpc_data.seq_id() << std::endl;
std::cout << "client AddUserResponse card_id=" << rep.ret().card_id() << std::endl;
std::cout << "client AddUserResponse code=" << rep.ret().code() << std::endl;
```

# 测试和运行
编译完成 C++ 工程，找到可执行文件目录

开启服务器并开启客户端调用(客户端和服务器在同进程下的不同线程中)
```bash	
./unit-rpc_service
```

结果如下:
```bash
service recv :param uid=100,nick_name=aaa,seq_id=1000003

client AddUserResponse seq_id=1000004

client AddUserResponse card_id=1001111

client AddUserResponse code=1
```
