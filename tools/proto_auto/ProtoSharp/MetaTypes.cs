using System;
using System.Collections.Generic;

namespace ProtoSharp
{
  /// <summary>
  /// 该模块用于定义编解码所需的原生类型
  /// </summary>
  public enum WireType : uint
  {
    Varint = 0,             //PSUInt32, PSInt64, PSUInt32, PSUInt64, PSSInt32, PSSInt64, PSBoolean, enum
    Stop = 1,               //字段终止符
    Fixed32 = 2,            //PSFixed32, PSSFixed32, PSFloat
    Fixed64 = 3,            //PSFixed64, PSSFixed64, PSDouble
    LengthDelimited = 4,    //PSString, PSBinary
    Struct = 5,             //embedded messages, PSList<T>, PSChange<T>
  }

  public enum StructType : uint
  {
    PSStruct = 0,           //普通的结构体
    PSList = 1,             //列表
    PSChangeSet = 2,        //某个结构体中的有效字段的集合
    PSUnion = 3,            //Union结构,结构中有且只有一个字段是有效的
  }


  #region 原生类型
  public partial class PSVoid { };

  public partial class PSInt32 { public System.Int32 data; };
  public partial class PSUInt32 { public System.UInt32 data; };
  public partial class PSSInt32 { public System.Int32 data; };
  public partial class PSFixed32 { public System.UInt32 data; };
  public partial class PSSFixed32 { public System.Int32 data; };

  public partial class PSInt64 { public System.Int64 data; };
  public partial class PSUInt64 { public System.UInt64 data; };
  public partial class PSSInt64 { public System.Int64 data; };
  public partial class PSFixed64 { public System.UInt64 data; };
  public partial class PSSFixed64 { public System.Int64 data; };

  public partial class PSDouble { public System.Double data; };
  public partial class PSFloat { public System.Single data; };

  /// <summary>
  /// 压缩型的浮点数,保留浮点数两位的精度
  /// 将浮点数转换为PSSInt64进行传输
  /// 接收端收到数据后反转化回来
  /// </summary>
  public partial class PSSDouble { }
  public partial class PSSFloat { }

  public partial class PSString { public System.String data; };
  public partial class PSBinary { public System.Byte[] data; };

  /// <summary>
  /// 全局唯一id,这个id由4个部分组成{[节点id],[顺序数,20bit],[从2015年1月1日零点到id生成时的毫秒数,29bit],[服务端|客户端,1bit]}
  /// </summary>
  public class PSGUID { }

  public partial class PSBoolean { public System.Boolean data; };

  public partial class PSList<T> { System.Collections.Generic.List<T> memeber; }
  public partial class PSChange<T> { System.Collections.Generic.List<int> indexs; T memeber; }
  public partial class PSUnion<T> { int indexs; T memeber; }

  #endregion

  public partial class MetaTypes
  {
    public static HashSet<Type> PSTypeSet = new HashSet<Type>
        {
            typeof(PSVoid),

            typeof(PSInt32),
            typeof(PSUInt32),
            typeof(PSSInt32),
            typeof(PSFixed32),
            typeof(PSSFixed32),

            typeof(PSInt64),
            typeof(PSUInt64),
            typeof(PSSInt64),
            typeof(PSFixed64),
            typeof(PSSFixed64),

            typeof(PSDouble),
            typeof(PSFloat),

            typeof(PSSDouble),
            typeof(PSSFloat),

            typeof(PSString),
            typeof(System.String),
            typeof(PSBinary),

            typeof(PSBoolean),
        };

    public static HashSet<Type> PSGenericTypeTypeSet = new HashSet<Type>
        {
            typeof(PSList<>),
            typeof(PSChange<>),
            typeof(PSUnion<>),
        };

    public static Dictionary<Type, WireType> TypeWireTypeMap = new Dictionary<Type, WireType>
        {
            {typeof(PSVoid),WireType.Varint},

            {typeof(PSInt32),WireType.Varint},
            {typeof(PSUInt32),WireType.Varint},
            {typeof(PSSInt32),WireType.Varint},
            {typeof(PSFixed32),WireType.Fixed32},
            {typeof(PSSFixed32),WireType.Fixed32},

            {typeof(PSInt64),WireType.Varint},
            {typeof(PSUInt64),WireType.Varint},
            {typeof(PSSInt64),WireType.Varint},
            {typeof(PSFixed64),WireType.Fixed64},
            {typeof(PSSFixed64),WireType.Fixed64},

            {typeof(PSFloat),WireType.Fixed32},
            {typeof(PSDouble),WireType.Fixed64},

            {typeof(PSSDouble),WireType.Varint},
            {typeof(PSSFloat),WireType.Varint},


            {typeof(PSString),WireType.LengthDelimited},
            {typeof(System.String),WireType.LengthDelimited},
            {typeof(PSBinary),WireType.LengthDelimited},

            {typeof(PSBoolean),WireType.Varint},
            {typeof(PSList<>),WireType.Struct},
            {typeof(PSChange<>),WireType.Struct},
            {typeof(PSUnion<>),WireType.Struct},
        };

  }


}
