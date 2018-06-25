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
  public static class TypesOfPB
  {

    public static string GetLabelName(LabelType type)
    {
        if(type == LabelType.Optional)
        {
            return string.Format("optional");
        }
        else if (type == LabelType.Repeated)
        {
            return string.Format("repeated");
        }
        else if(type == LabelType.Required)
        {
            return string.Format("required");
        }
        else
        {
            return string.Format("NULL");
        }
    }


    public static string GetPBName(Type type)
    {
      if (type.IsEnum)
      {
        return EnumPBName(type.FullName);
      }
      else if (type.IsGenericType && type.IsGenericTypeDefinition == false)
      {
        if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
        {
            return "repeated " + PSTypePBName(type.GetGenericArguments().First());
        }
        throw new System.Exception("无法识别的类型");
      }
      else
      {
        return PSTypePBName(type);
      }
    }

    static string TypePBName(string name)
    {
        if (name == "PSBoolean")
            return "bool";
        else if (name == "PSBinary")
            return "bytes";
        return name.Replace("PS", "").ToLower();
    }

    static string EnumPBName(string name)
    {
        return name;
     }

    static string[] GenericTypePBName1(Type genericType, Type genericArgType)
    {
      return new string[]
      {
                TypePBName(genericType.Name.Replace("`1", "")),
                PSTypePBName(genericArgType)
      };
    }

    public static string GenericTypePBName(Type genericType, Type genericArgType)
    {
      return string.Join("_", GenericTypePBName1(genericType, genericArgType));
    }

    public static string GenericTypePBTuple(Type genericType, Type genericArgType)
    {
      return "{" + string.Join(",", GenericTypePBName1(genericType, genericArgType)) + "}";
    }

    public static string GenericTypePBTuple(Type type)
    {
      if (type.IsEnum)
      {
        return EnumPBName(type.Name);
      }
      else if (type.IsGenericType && type.IsGenericTypeDefinition == false)
      {
        if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
        {
          return GenericTypePBTuple(type, type.GetGenericArguments().First());
        }
        throw new System.Exception("无法识别的类型");
      }
      else
      {
        return PSTypePBName(type);
      }
    }

    public static string PBMetaTypeName(Type type)
    {
      if (type.IsEnum)
      {
        return EnumPBName(type.Name);
      }
      else if (type.IsGenericTypeDefinition)
      {
        if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
        {
          return TypePBName(type.Name.Replace("`1", ""));
        }
        throw new System.Exception("无法识别的类型");
      }
      else
      {
        return PSTypePBName(type);
      }
    }

    static string PSTypePBName(Type type)
    {
      if (type.IsEnum)
      {
        return EnumPBName(type.FullName);
      }
      else if (MetaTypes.PSTypeSet.Contains(type))
      {
        return TypePBName(type.Name);
      }
      return type.FullName;
    }

    public static bool IsNeedImport(Type type)
    {
        if (MetaTypes.PSTypeSet.Contains(type))
        {
            return false;
        }
        else if (type.IsGenericType && type.IsGenericTypeDefinition == false)
        {
            if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
            {
                return IsNeedImport(type.GetGenericArguments().First());
            }
            throw new System.Exception("无法识别的类型");
        }
        else
        {
            return true;
        }
    }

    public static string GetTypeFileName(Type type)
    {
        if (type.IsEnum)
        {
            return CppUtil.CppStyleName(type.Name);
        }
        else if (MetaTypes.PSTypeSet.Contains(type))
        {
            return TypePBName(type.Name);
        }
        else if (type.IsGenericType && type.IsGenericTypeDefinition == false)
        {
            if (MetaTypes.PSGenericTypeTypeSet.Contains(type.GetGenericTypeDefinition()))
            {
                return GetTypeFileName(type.GetGenericArguments().First());
            }
            throw new System.Exception("无法识别的类型");
        }
        else
        {
            return CppUtil.CppStyleName(type.Name);
        }
            
    }

    }

}
