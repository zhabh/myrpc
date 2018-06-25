using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace ProtoSharp
{
    public class Descriptor
    {
        private Assembly DescriptAssambly;
        public Descriptor(Type Entry)
        {
            DescriptAssambly = Assembly.GetAssembly(Entry);
        }

        public Descriptor(String DLLNAME)
        {
            DescriptAssambly = Assembly.LoadFile(DLLNAME);
        }

        IEnumerable<DescriptorModule> _moduleList;
        public IEnumerable<DescriptorModule> ModuleList
        {
            get
            {
                if (_moduleList == null)
                {
                    _moduleList = DescriptAssambly.Modules.Select(o => new DescriptorModule(o));
                }
                return _moduleList;
            }
        }

        static HashSet<Type> _primitiveTypes = new HashSet<Type>()
            {
                typeof(UInt32),
                typeof(Int32),
                typeof(UInt64),
                typeof(Int64),
                typeof(Single),
                typeof(Double),
                typeof(String),
                typeof(Byte[]),
            };
        public static HashSet<Type> PrimitiveTypes
        {
            get { return _primitiveTypes; }
        }

        public static bool IsPrimitiveType(Type type)
        {
            return PrimitiveTypes.Contains(type);
        }
    }

    public class DescriptorFiled
    {
        private FieldInfo _fieldInfo;
        public DescriptorFiled(FieldInfo fieldInfo)
        {
            _fieldInfo = fieldInfo;
        }
        public string Name { get { return _fieldInfo.Name; } }
        public Type Type { get { return _fieldInfo.FieldType; } }

        public string Namespace { get { return _fieldInfo.FieldType.Namespace; } }

        public UInt32 Index
        {
            get
            {
                IndexAttribute indexAttribute = _fieldInfo.GetCustomAttribute<IndexAttribute>();
                return indexAttribute.Index;
            }
        }

        public LabelType Label
        {
            get
            {
                var indexAttribute = _fieldInfo.GetCustomAttribute<LabelAttribute>();
                return indexAttribute.Label;
            }
        }

        public string Desc
        {
            get
            {
                var indexAttribute = _fieldInfo.GetCustomAttribute<DescAttribute>();
                return indexAttribute!=null?indexAttribute.Desc:"";
            }
        }

        public bool hasLabel
        {
            get
            {
                var indexAttribute = _fieldInfo.GetCustomAttribute<LabelAttribute>();
                return indexAttribute != null;
            }
        }

        public bool HasPrimary
        {
            get
            {
                PrimaryAttribute primaryAttribute = _fieldInfo.GetCustomAttribute<PrimaryAttribute>();
                return primaryAttribute != null;
            }
        }

        public PrimaryType Primary
        {
            get
            {
                PrimaryAttribute primaryAttribute = _fieldInfo.GetCustomAttribute<PrimaryAttribute>();
                return primaryAttribute.Primary;
            }
        }

        public bool hasDefault
        {
            get
            {
                var defaultValue = _fieldInfo.GetCustomAttribute<DefaultValueAttribute>();
                return defaultValue != null;
            }
        }

        public string DefaultValue
        {
            get
            {
                var defaultValue = _fieldInfo.GetCustomAttribute<DefaultValueAttribute>();
                if (defaultValue == null)
                {
                    return null;
                }
                Type enumType = defaultValue.Value.GetType();
                if (enumType.IsEnum)
                {
                    int v = (int)enumType.InvokeMember(defaultValue.Value.ToString(), BindingFlags.GetField, null, null, null);
                    return v.ToString();
                }
                return defaultValue.Value.ToString();
            }
        }
    }

    public class DescriptorStruct
    {
        private Type psStruct;
        public DescriptorStruct(Type _struct)
        {
            psStruct = _struct;
        }
        public Type Type { get { return psStruct; } }

        /// <summary>
        /// 
        /// </summary>
        public string Name { get { return psStruct.Name; } }

        public string Namespace { get { return psStruct.Namespace; } }

        public HashSet<ExportType> ExportType
        {
            get 
            {
                return new HashSet<ExportType>(psStruct.GetCustomAttributes<ExportAttribute>().Select(o => o.ExportType)); 
            }
        }


        /// <summary>
        /// 
        /// </summary>
        DescriptorFiled[] _fieldList;
        public DescriptorFiled[] FieldList
        {
            get
            {
                if (_fieldList == null)
                {
                    _fieldList = psStruct.GetFields().Select(o => new DescriptorFiled(o)).ToArray();
                }
                return _fieldList;
            }
        }
    }

    public class DescriptorParam
    {
        ParameterInfo ParameterInfo;
        public DescriptorParam(ParameterInfo parameterInfo)
        {
            ParameterInfo = parameterInfo;
        }
        /// <summary>
        /// 
        /// </summary>
        public string Name { get { return ParameterInfo.Name; } }

        public Type Type
        {
            get { return ParameterInfo.ParameterType; }
        }

        public int Position
        {
            //protobuf要求field顺序大于0，所以改为从1开始
            get { return ParameterInfo.Position+1; }
        }

        public bool hasDefaultValue
        {
            get { return ParameterInfo.HasDefaultValue; }
        }

        public string DefaultValue
        {
            get { return ParameterInfo.DefaultValue.ToString(); }
        }

    }

    public class DescriptorMethod
    {
        private MethodInfo Method;
        DescriptorService _Service;

        static string MethodName(MethodInfo method)
        {
            //Char first = method.Name.First();
            //if (first >= 'A' && first <= 'Z')
            //{
            //    //大写字符使用pascal case来分解
            //    return string.Join("_", CommonUtil.SplitPascalCase(method.Name).Select(o=>o.ToLower()));
            //}
            //return string.Join("_", CommonUtil.SplitCamelCase(method.Name).Select(o => o.ToLower())); ;
            return method.Name;
        }

        public DescriptorMethod(DescriptorService service, MethodInfo method)
        {
            Method = method;
            _Service = service;
            processOnAttribute = Method.GetCustomAttribute<ProcessOnAttribute>(true);
        }
        /// <summary>
        /// 
        /// </summary>
        public string Name { get { return MethodName(Method); } }

        public UInt32 Index
        {
            get
            {
                IndexAttribute indexAttribute = Method.GetCustomAttribute(typeof(IndexAttribute)) as IndexAttribute;
                return indexAttribute.Index;
            }
        }

        public UInt32 ServiceIndex
        {
            get
            {
                return _Service.Index;
            }
        }

        public DescriptorService Service
        {
            get
            {
                return _Service;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        private DescriptorParam[] _paramList;
        public DescriptorParam[] ParamList
        {
            get
            {
                if (_paramList == null)
                {
                    _paramList = Method.GetParameters().Select(o => new DescriptorParam(o)).ToArray();
                }
                return _paramList;
            }
        }

        public bool isVoidReturn
        {
            get { return ReturnType == typeof(PSVoid); }
        }


        #region 特殊返回类型处理
        public bool IsPSList
        {
            get
            {
                if (ReturnType.IsGenericType && !ReturnType.IsGenericTypeDefinition)
                {
                    return ReturnType.GetGenericTypeDefinition() == typeof(PSList<>);
                }
                return false;
            }
        }

        public Type GetPSListGenericArgument
        {
            get { return ReturnType.GetGenericArguments().First(); }
        }

        public bool IsChangeType
        {
            get
            {
                if (ReturnType.IsGenericType && !ReturnType.IsGenericTypeDefinition)
                {
                    return ReturnType.GetGenericTypeDefinition() == typeof(PSChange<>);
                }
                return false;
            }
        }

        public Type GetPSChangeGenericArgument
        {
            get { return ReturnType.GetGenericArguments().First(); }
        }

        public bool IsUnionType
        {
            get
            {
                if (ReturnType.IsGenericType && !ReturnType.IsGenericTypeDefinition)
                {
                    return ReturnType.GetGenericTypeDefinition() == typeof(PSUnion<>);
                }
                return false;
            }
        }

        public Type GetPSUnionGenericArgument
        {
            get { return ReturnType.GetGenericArguments().First(); }
        }
        # endregion

        /// <summary>
        /// 
        /// </summary>
        public Type ReturnType { get { return Method.ReturnType; } }
        /// <summary>
        /// 
        /// </summary>
        public KeyValuePair<ushort, Type>[] ExceptionList
        {
            get
            {
                var attribute = Method.GetCustomAttribute<MethodExceptionsAttribute>(true);
                if (attribute == null)
                {
                    return null;
                }
                return attribute.exceptions.ToArray();
            }
        }

        ProcessOnAttribute processOnAttribute;
        /// <summary>
        /// 
        /// </summary>
        public ProcessOnType ProcessOn
        {
            get
            {
                if (processOnAttribute == null)
                {
                    return ProcessOnType.All;
                }
                return processOnAttribute.ProcessorType;
            }
        }
    }

    /// <summary>
    /// 
    /// </summary>
    public class DescriptorService
    {
        private Type psService;
        public DescriptorService(Type service)
        {
            psService = service;
        }

        /// <summary>
        /// 
        /// </summary>
        public string Name { get { return psService.Name; } }

        public string Namespace { get { return psService.Namespace; } }

        public UInt32 Index
        {
            get
            {
                IndexAttribute indexAttribute = psService.GetCustomAttribute(typeof(IndexAttribute)) as IndexAttribute;
                return indexAttribute.Index;
            }
        }

        /// <summary>
        /// 服务的处理器类型
        /// </summary>
        public ProcessorType ProcessorType
        {
            get
            {
                ProcessorTypeAttribute singleton = psService.GetCustomAttribute(typeof(ProcessorTypeAttribute)) as ProcessorTypeAttribute;
                if (singleton == null)
                {
                    return ProtoSharp.ProcessorType.Server;
                }
                return singleton.ProcessorType;
            }
        }

        /// <summary>
        /// 这个服务是否需要生成服务端处理器
        /// </summary>
        public bool NeedServerProcessor
        {
            get
            {
                foreach (var method in MethodList)
                {
                    if (method.ProcessOn == ProcessOnType.All || method.ProcessOn == ProcessOnType.Server)
                    {
                        return true;
                    }
                }
                return false;
            }
        }

        /// <summary>
        /// 这个服务是否需要生成客户端处理器
        /// </summary>
        public bool NeedClientProcessor
        {
            get
            {
                foreach (var method in MethodList)
                {
                    if (method.ProcessOn == ProcessOnType.All || method.ProcessOn == ProcessOnType.Client)
                    {
                        return true;
                    }
                }
                return false;
            }
        }

        /// <summary>
        /// 服务是否是单例的服务
        /// </summary>
        public bool IsSingleton
        {
            get
            {
                PSSingletonAttribute singleton = psService.GetCustomAttribute(typeof(PSSingletonAttribute)) as PSSingletonAttribute;
                return singleton != null;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        private DescriptorMethod[] _methodList;
        public DescriptorMethod[] MethodList
        {
            get
            {
                if (_methodList == null)
                {
                    _methodList = psService.GetMethods().Select(o => new DescriptorMethod(this, o)).ToArray();
                }
                return _methodList;
            }
        }
    }

    public class DescriptorEnum
    {
        private Type psEnum;
        public DescriptorEnum(Type _enum)
        {
            psEnum = _enum;
        }

        public Type Type { get { return psEnum; } }

        public string Name { get { return psEnum.Name; } }
        public FieldInfo[] Fields { get { return psEnum.GetFields(BindingFlags.Static | BindingFlags.Public); } }

        public string Desc(FieldInfo field)
        {
            var indexAttribute = field.GetCustomAttribute<DescAttribute>();
            return indexAttribute != null ? indexAttribute.Desc : "";
        }

        public string Namespace { get { return psEnum.Namespace; } }

    }

    public class DescriptorModule
    {
        private Module Module;
        public DescriptorModule(Module module)
        {
            Module = module;
        }

        public string Name { get { return Module.Name; } }

        IEnumerable<DescriptorStruct> _structList;
        public IEnumerable<DescriptorStruct> StructList
        {
            get
            {
                if (_structList == null)
                {
                    _structList = Module.GetTypes().Where(o => o.IsClass).Select(o => new DescriptorStruct(o));
                }
                return _structList;
            }
        }

        public int StructCount
        {
            get
            {
                return StructList.Count();
            }
        }

        DescriptorService[] _serviceList;
        public DescriptorService[] ServiceList
        {
            get
            {
                if (_serviceList == null)
                {
                    _serviceList = Module.GetTypes().Where(o => o.IsInterface).Select(o => new DescriptorService(o)).ToArray();
                }
                return _serviceList;
            }
        }

        public int ServiceCount
        {
            get
            {
                return ServiceList.Count();
            }
        }

        IEnumerable<DescriptorEnum> _enumList;
        public IEnumerable<DescriptorEnum> EnumList
        {
            get
            {
                if (_enumList == null)
                {
                    _enumList = Module.GetTypes().Where(o => o.IsEnum).Select(o => new DescriptorEnum(o));
                }
                return _enumList;
            }
        }

        public int EnumCount
        {
            get
            {
                return _enumList.Count();
            }
        }
    }
}
