using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProtoSharp;

namespace crucis
{
  public enum ServicResult
  {
    UNKNOWN = 0,
  }

  [PSException()]
  public class ServiceError
  {
    [Index(1)]
    public ServicResult Error;
  }

  public enum AuthErrorCode
  {
    [Desc("密码错误")]
    Pass = 1,

    [Desc("密码错误")]
    ErrorPassword = 2,

    [Desc("账号认证通过但是没有注册角色")]
    GamerNotFound = 3
  }

  [Index(0)]
  [PSSingleton()]
  [Desc("远端的服务对象生成器,用于在远程生成服务对象")]
  public interface ServiceFactory
  {
    //创建一个新的服务
    [Index(1)]
    PSVoid NewServiceSingleton(PSUInt32 serviceType);

    [Index(2)]
    [Desc("将本地已经存在的服务同步到远端")]
    PSVoid NewService(PSUInt32 serviceType, PSUInt64 objectId);

    [Index(3)]
    [Desc("将本地已经存在的服务同步到远端")]
    PSBoolean SyncServices(PSList<PSUInt32> serviceTypes, PSList<PSUInt32> serviceIds);

    // 在连接上绑定一个服务,这个服务是全局唯一服务(type和Oid相同)
    [Index(4)]
    [MethodExceptions(typeof(ServiceError))]
    PSBoolean BindService(PSInt32 serviceType);

    [Index(5)]
    [ProcessOn(ProcessOnType.Client)]
    PSVoid AuthResult(AuthErrorCode result);

    [Index(6)]
    [ProcessOn(ProcessOnType.Client)]
    PSVoid deleteService(PSUInt64 objectId);

    [Index(7)]
    [ProcessOn(ProcessOnType.Client)]
    PSVoid ReloadService(PSUInt32 serviceType, PSUInt64 objectId);

  }
}
