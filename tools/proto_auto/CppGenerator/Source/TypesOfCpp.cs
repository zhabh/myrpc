using RazorEngine;
using RazorEngine.Templating;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using CppGenerator;

namespace ProtoSharp
{
  public partial class PSEnum { };
  public static class TypesOfCpp
  {
        public static Dictionary<Type, string> TypeCppMap = new Dictionary<Type, string>
        {
            {typeof(PSVoid),"void"},

            {typeof(PSInt32),"int"},
            {typeof(PSUInt32),"unsigned int"},
            {typeof(PSSInt32),"int"},
            {typeof(PSFixed32),"unsigned int"},
            {typeof(PSSFixed32),"int"},

            {typeof(PSInt64),"long"},
            {typeof(PSUInt64),"unsigned long"},
            {typeof(PSSInt64),"long"},
            {typeof(PSFixed64),"unsigned long"},
            {typeof(PSSFixed64),"long"},

            {typeof(PSFloat),"float"},
            {typeof(PSDouble),"double"},

            {typeof(PSSFloat),"float"},
            {typeof(PSSDouble),"double"},

            {typeof(PSString),  "std::string"},
            {typeof(System.String), "std::string"},
            {typeof(PSBinary),"char*"},

            {typeof(PSBoolean),"bool"},
            {typeof(PSList<>),"list"},
            {typeof(PSChange<>),"change"},
            {typeof(PSUnion<>),"union"},
        };

        
    public static string GetCppTypeName(Type type)
    {
      if (type.IsEnum)
      {
           return CppUtil.EnumModuleName(type.Name);
      }
      else if (type.IsGenericType && type.IsGenericTypeDefinition == false)
      {
        if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
        {
          return GenericTypeCppName(type, type.GetGenericArguments().First());
        }
        throw new System.Exception("无法识别的类型");
      }
      else
      {
           return PSTypeCppName(type);
      }
    }

    static string TypeCppName(Type type)
    {
        string cppType ="";
        if (TypesOfCpp.TypeCppMap.TryGetValue(type, out cppType))
        {
            return cppType;
        }
        else
        {
            var tmp = type.Name.Replace("`1", "");
            return tmp.Replace("PS", "").ToLower();
        }
    }

    static string GenericTypeCppName(Type genericType, Type genericArgType)
    {
        return "" + TypeCppName(genericType) + PSTypeCppName(genericArgType);
    }

    static string PSTypeCppName(Type type)
    {
      if (type.IsEnum)
      {
        return CppUtil.EnumModuleName(type.Name);
      }
      else if (MetaTypes.PSTypeSet.Contains(type))
      {
        return TypeCppName(type);
      }
      return CppUtil.CppStyleName(type.Name);
    }

  }
}

