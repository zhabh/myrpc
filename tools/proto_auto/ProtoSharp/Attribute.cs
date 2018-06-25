using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProtoSharp
{
    public enum LabelType
    {
        Required,
        Optional,
        Repeated,
    }

    public enum MessageType
    {
        Call = 1,
        Reply = 2,
        Exception = 3,
        Oneway = 4
    }

    public enum ProcessOnType
    {
        All,
        Client,
        Server,
    }

    public enum ProcessorType
    {
        FSM,
        Server
    }

    public enum ExportType
    {
        //ReadSQL,      //生成该结构的sql读取函数(主键)
        //WriteSQL,     //生成该结构的sql写入函数
        //ReadRedis,      //生成该结构的redis读取函数
        //WriteRedis,     //生成该结构的redis写入函数
        //ReadEts,        //生成该结构的ets读取函数
        //WiriteEts,      //生成该结构的ets写入函数
        Redis,//生成该结构的redis的增,删,查,改 函数
        Ets,//生成该结构的ets的增,删,查,改 函数
        MySQL,//生成该结构的mysql的增,删,查,改 函数
    }

    public enum PrimaryType
    {
        Id,//实例ID
        OwnerId,//所属ID
        Type,//分类ID
        ParentId,//父ID
    }

    [AttributeUsage(AttributeTargets.Field, AllowMultiple = true, Inherited = true)]
    public class LabelAttribute : System.Attribute
    {
        public LabelAttribute(LabelType label)
        {
            this.Label = label;
        }
        // 类型
        public LabelType Label;
    }

    [AttributeUsage(AttributeTargets.All, AllowMultiple = true, Inherited = true)]
    public class DescAttribute : Attribute
    {
        public DescAttribute(string desc)
        {
            this.Desc = desc;
        }

        // 类型
        public string Desc;
    }

    [AttributeUsage(AttributeTargets.All, AllowMultiple = true, Inherited = true)]
    public class IndexAttribute : Attribute
    {
        public IndexAttribute(UInt32 index)
        {
            this.Index = index;
        }

        public UInt32 Index;
    }

    [AttributeUsage(AttributeTargets.All, AllowMultiple = true, Inherited = true)]
    public class PrimaryAttribute : Attribute
    {
        public PrimaryAttribute(PrimaryType type)
        {
            this.Primary = type;
        }

        public PrimaryType Primary;
    }

    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true, Inherited = true)]
    public class OnewayAttribute : Attribute
    {
    }

    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true, Inherited = true)]
    public class MethodExceptionsAttribute : Attribute
    {
        public MethodExceptionsAttribute(params System.Type[] types)
        {
            this.exceptions = new Dictionary<ushort, System.Type>();
            for (ushort i = 0; i < types.Length; i++)
            {
                this.exceptions.Add(i, types[i]);
            }
        }
        public Dictionary<ushort, System.Type> exceptions;
    }

    [AttributeUsage(AttributeTargets.Field, AllowMultiple = true, Inherited = true)]
    public class DefaultValueAttribute : Attribute
    {
        public DefaultValueAttribute(object value)
        {
            Value = value;
        }
        public object Value;
    }

    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
    public class PSSingletonAttribute : Attribute
    {
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false, Inherited = true)]
    public class PSException : Attribute
    {
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false, Inherited = true)]
    public class MonitorPointAttribute : Attribute
    {
    }


    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
    public class ImitateSingletonAttribute : Attribute
    {
    }


    /// <summary>
    /// 方法将在网络连接的那一端进行处理
    /// 如果没有设定这个属性的话,当作ProcessOnType.All
    /// </summary>
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = false, Inherited = true)]
    public class ProcessOnAttribute : Attribute
    {
        public ProcessOnAttribute(ProcessOnType type)
        {
            _processorType = type;
        }

        ProcessOnType _processorType;
        public ProcessOnType ProcessorType { get { return _processorType; } }
    }

    /// <summary>
    /// 指示处理器的行为模式,服务端使用
    /// </summary>
    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
    public class ProcessorTypeAttribute : Attribute
    {
        public ProcessorTypeAttribute(ProcessorType pt)
        {
            _p_type = pt;
        }
        ProcessorType _p_type;
        public ProcessorType ProcessorType { get { return _p_type; } }
    }

    /// <summary>
    /// 指示结构的导出方式,可以有多个
    /// </summary>
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true, Inherited = true)]
    public class ExportAttribute : Attribute
    {
        public ExportAttribute(ExportType pt)
        {
            _p_type = pt;
        }
        ExportType _p_type;
        public ExportType ExportType { get { return _p_type; } }
    }

    public static class AttributeTypesList
    {
        public static List<Type> Attributes =
            new List<Type>
            {
                typeof(LabelAttribute),
                typeof(DescAttribute),
                typeof(IndexAttribute),
                typeof(OnewayAttribute),
                typeof(MethodExceptionsAttribute),
                typeof(DefaultValueAttribute),
                typeof(PSException),
            };
    }


}
