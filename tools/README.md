

# proto_auto 指南
这个文档介绍了如何使用C#语法描述自定义协议文件，以及协议生成过程

# proto_auto 所做的工作
###  1.协议文件生成 
proto_auto 工程可以根据DLL文件生成自定义的协议格式，使C++程序能够识别（如C++的enum或struct），客户端和服务器都读取统一的协议代码文件，简化了协议定义。不同的服务生成的代码保存到不同的C++文件，
这样的好处是，当修改某个服务的时候重新生成所有代码，只有被修改的协议的C++文件变化了，这样可以减少重新编译系统的时间。
###  2.rpc 服务的客户端和服务端代码生成
能生成各个服务的所有接口的rpc接口，具体业务逻辑只需要继承相关基类完成接口逻辑即可，具体见[crucis_proto介绍](../README.md)

## 注释
注释遵循C#语法，使用双斜杠"//"可以整行注释，多行注释使用/**/

## 可选标签
### Desc标签
描述文字统一使用[Desc("xx")]的形式放在类型之前，生成协议的时候可以将括号里的内容取出生成注释。
### Label标签
类似[Label(LabelType.Required)]，目前仅支持LabelType.Required类型，表示必须不为空
### PSSingleton标签
表示的是单例类型，一般用来描述interface的接口, ImitateSingleton 类似
### ProcessOn标签
类似 [ProcessOn(ProcessOnType.Client)]，只能在接口函数上使用，表示该接口主要给哪方调用，ProcessOnType定义为
```csharp
 public enum ProcessOnType
 {
    All,
    Client,
    Server,
 } 
```
	
## 基本类型
支持如下标准数据类型：
* PSVoid 对应C++中的 void
* PSInt32 对应C++中的 int32_t
* PSUInt32 对应C++中的 uint32_t
* PSSInt32 对应C++中的 int32_t, 但是会在传输过程中对负数进行压缩传输
* PSFixed32 对应C++中的 uint32_t，不会进行任何压缩操作
* PSInt64 对应C++中的 int64_t
* PSUInt64 对应C++中的 uint64_t
* PSDouble 对应C++中的 double
* PSFloat 对应C++中的 float
* PSString 对应C++中的 std::string
* PSBinary 对应C++中的 uint8_t[]

## List类型
支持复杂类型定义列表，示例如：PSList<PSUInt32>，其中尖括号里的类型目前只支持前文标准数据类型

## 枚举
用来定义枚举类型数据，格式为:修饰符类型 + enum + 名字{},每个枚举类型用逗号分隔，示例如下
```csharp
[Desc("消息行为类型")]
public enum MessageType
{
    [Desc("调用")]
    Call = 1,
    [Desc("返回")]
    Reply = 2,
    [Desc("异常")]
    Exception = 3,
    [Desc("单路")]
    Oneway = 4
}
```
## 结构体
用来定义结构类型，格式为:修饰符类型+class+名字{}，其中每个字段前需要加上[Index(xx)]标签，并且其中的xx编号从1依次递增,示例：
```csharp
 public class RpcRequestData
 {
    [Index(1)]
    [Label(LabelType.Required)]
    [Desc("服务类型id号")]
    public PSUInt32 ServiceId;

    [Index(2)]
    [Label(LabelType.Required)]
    [Desc("函数的id号")]
    public PSUInt32 Function;
}
```
## 接口类型
用来定义服务和接口，格式为修饰符类型 + interface + 名字{}，下面的例子定义了ServiceFactory 服务下的NewServiceSingleton接口和NewService接口
```csharp
[Index(0)]
[PSSingleton()]
[Desc("远端的服务对象生成器, 用于在远程生成服务对象")]
public interface ServiceFactory
{
  //创建一个新的服务
  [Index(1)]
  PSVoid NewServiceSingleton(PSUInt32 serviceType);

  [Index(2)]
  [Desc("将本地已经存在的服务同步到远端")]
  PSVoid NewService(PSUInt32 serviceType, PSUInt64 objectId);
}
```
其中输入输出参数支持前文提及的标准数据类型以及 enum, struct 类型.

**注意** : 服务定义一般会给服务加上Index标签，编号全局唯一，便于通过编号能直接定位服务类。接口上的Index编号则表示对应的接口。这样通过以上两个 Index 编号则可以定位某个具体的接口.

 