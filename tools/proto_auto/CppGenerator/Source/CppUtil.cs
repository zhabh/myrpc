using ProtoSharp;
using RazorEngine;
using RazorEngine.Templating;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CppGenerator
{
    public partial class CppUtil
  {
    //static string root = "/";
    #region 全局变量

    static string root;
    static string writePath;
    static string hrlWritePath;
    static string protoWritePath;

    static Dictionary<string, LoadedTemplateSource> _all_template;

    #endregion

    static CppUtil()
    {
      try
      {
        var s = Environment.GetEnvironmentVariable("COF_DEV_ROOT", EnvironmentVariableTarget.Process);
                //var v = Environment.GetEnvironmentVariables();
                //foreach (var key in v.Keys)
                //{
                //    Console.WriteLine("{0}:{1}", key, v[key]);
                //}

        CppUtil.root = System.Environment.CurrentDirectory;
        Console.WriteLine(CppUtil.root);

        CppUtil.writePath = @"../cppcode/";
        CppUtil.hrlWritePath = @"../cppcode/";
        CppUtil.protoWritePath = @"../proto/";

        CppUtil._projectRoot = root;
        CppUtil.DespatcherPath = @"../cppcode/";
        CppUtil.ProcessorPath = @"../cppcode/";

        CppUtil._all_template = new Dictionary<string, LoadedTemplateSource>();

        LoadBaseTemplate();
        //LoadHandlerTemplate();
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }
    }

    static public string debugString(string name)
    {
        return "";
    }

        static public string PBStyleName(string name)
    {
       return string.Join("", CommonUtil.SplitPascalCase(name).Select(o => Ucfirst(o)));
    }

    static public string CppStyleName(string name)
    {
        //大写字符使用pascal case来分解
        return string.Join("_", CommonUtil.SplitPascalCase(name).Select(o => o.ToLower()));
    }

    static public string Ucfirst(string name)
    {
        CultureInfo cultureInfo = Thread.CurrentThread.CurrentCulture;
        TextInfo textInfo = cultureInfo.TextInfo;
        return textInfo.ToTitleCase(name);
    }

    static public string CppEnumFieldName(string name)
    {
        return string.Format("k{0}", name);
    }


    public static string EnumModuleName(string name)
    {
        return "enum_" + CppStyleName(name);
    }

    public static string StuctFileName(DescriptorStruct jStruct)
    {
        return CppStyleName(jStruct.Name);
    }

    public static string ServiceParamFileName(string name)
    {
        return CppStyleName(name) + "_param_define";
    }

    public static string ServiceFileName(string name)
    {
        return CppStyleName(name);
    }

    public static string ServiceCppClassName(string name)
    {
        return CppStyleName(name)+"_server";
    }

    public static string CppParamStd(string name)
    {
        return "std::"+ name;
    }

    public static string CppParamConstRef(string name)
    {
        return "const std::" + name + "&";
    }

    public static string PBParamFuncName(string name)
    {
            //todo
        return name+"()";
    }

        public static string CppParamJoin(string preStr, List<string> names)
    {
        StringBuilder sbBuild = new StringBuilder();
        for(int i = 0;i < names.Count();i++)
        {
            if(i==0)
            {
                sbBuild.Append(preStr + names[i]);
            }
            else
            {
                sbBuild.Append("," + preStr + names[i]);
            }
                
        }
        return sbBuild.ToString();
    }

    static public string PBMethodReqName(string name)
    {
        return PBStyleName(name) + "Request";
    }

    static public string PBMethodReturnName(string name)
    {
        return PBStyleName(name) + "Response";
    }

    public static string TrimNameSpace(string name,string destStr)
    {
        if(name.Length < destStr.Length)
        {
            return name;
        }
        else if (name == destStr)
        {
            return "";
        }

        int len = destStr.Length;
        if(destStr == name.Substring(0, len))
        {
            return name.Substring(len+1);
        }
        return name;
    }

    public static string NameSpace2Dir(string name)
    {
        if(string.IsNullOrEmpty(name))
        {
            return "";
        }
        string[] arrSpace = name.Split('.');
        StringBuilder sbuild = new StringBuilder();
        for( int i = 0;i <arrSpace.Count(); i++ )
        {
            if(i == 0)
            {
                    sbuild.Append(CppStyleName(arrSpace[i]));
            }
            else
            {
                    sbuild.Append("/");
                    sbuild.Append(CppStyleName(arrSpace[i]));
            }
        }
        sbuild.Append("/");
        return sbuild.ToString();
    }

    public static string StructHeadMacro(string name)
    {
        return "_CRUCIS_" + string.Join("_", CommonUtil.SplitPascalCase(name).Select(o => o.ToUpper()))+ "_H_";
    }

        public static void LoadBaseTemplate()
    {
      var l = new List<string>
        {
            "cof_ps_enum.cshtml",
            "cof_ps_struct_protobuff.cshtml",
            "cof_ps_enum_protobuff.cshtml",
            "cof_ps_service.cshtml",
            "cof_ps_service_param_protobuff.cshtml",
            "cof_ps_service_base_h.cshtml",
            "cof_ps_service_h.cshtml",
        };
      foreach (var s in l)
      {
        _all_template[s] = LoadTemplate("Templates", s);
      }

      _all_template["CofGamerKeys.cshtml"] = LoadTemplate("Templates.GamerKeys", "CofGamerKeys.cshtml");
    }

    public static LoadedTemplateSource LoadTemplate(string Resource, string Name)
    {
      string templateFile = System.IO.Path.Combine(root, Name);
      var assembly = Assembly.GetExecutingAssembly();
      var assemblyName = assembly.GetName().Name;

      var names = assembly.GetManifestResourceNames();
      var resName = string.Join(".", assemblyName, Resource, Name);
      var streamRead = assembly.GetManifestResourceStream(resName);
      string template;
      using (var reader = new System.IO.StreamReader(streamRead))
      {
        template = reader.ReadToEnd();
      }
      return new LoadedTemplateSource(template, templateFile);
    }

  
    public static void GenarateEnum(IEnumerable<DescriptorEnum> enums)
    {
        var templateFileName = "cof_ps_enum.cshtml";
        var templateSource = _all_template[templateFileName];

        var templateFileNamePB = "cof_ps_enum_protobuff.cshtml";
        var templateSourcePB = _all_template[templateFileNamePB];

        foreach (var @enum in enums)
        {
            string nameSpace = NameSpace2Dir(@enum.Namespace);
            var file2Write = CppStyleName(@enum.Name);
            /*暂时不用生成C++ enum*/
            //var result =
            //    Engine.Razor.RunCompile(
            //        templateSource,
            //        templateFileName, null,
            //        new { FileName = file2Write, PSEnum = @enum }
            //    );
            //WriteMsgFile(Path.Combine(root, writePath, file2Write + ".cpp"), result);

            var result = Engine.Razor.RunCompile(templateSourcePB, templateFileNamePB, null, new { FileName = file2Write, PSEnum = @enum });
            CreateDir(Path.Combine(CppUtil.root, CppUtil.protoWritePath, nameSpace));
            WriteMsgFile(Path.Combine(root, protoWritePath, nameSpace, file2Write + ".proto"), result);
        }
    }


    public static void GenarateStruct(IEnumerable<DescriptorStruct> jStructs)
    {
        //var structHrlTemplateFileName = "cof_ps_struct_h.cshtml";
        //var structHrlTemplateSource = _all_template[structHrlTemplateFileName];

        var structTemplateFileName = "cof_ps_struct_protobuff.cshtml";
        var structTemplateProtoFile = _all_template[structTemplateFileName];

        List<DescriptorStruct> etsStructs = new List<DescriptorStruct>();
        foreach (var jStruct in jStructs)
        {
            HashSet<ExportType> exportType = jStruct.ExportType;
            if (exportType.Contains(ExportType.Ets))
            {
                etsStructs.Add(jStruct);
            }
                /*暂不生成C++struct*/
                //var file2Write = StuctFileName(jStruct);
                //var result =
                //    Engine.Razor.RunCompile(
                //        structHrlTemplateSource,
                //        structHrlTemplateFileName, null,
                //        new { FileName = file2Write, JStruct = jStruct }
                //    );
                //WriteMsgFile(Path.Combine(root, hrlWritePath, file2Write + ".h"), result);

            string nameSpace = NameSpace2Dir(jStruct.Namespace);
            var file2Write = CppStyleName(jStruct.Name);
            var result = Engine.Razor.RunCompile(structTemplateProtoFile, structTemplateFileName, null, new { FileName = file2Write, JStruct = jStruct });
            CreateDir(Path.Combine(CppUtil.root, CppUtil.protoWritePath, nameSpace));

            WriteMsgFile(Path.Combine(root, protoWritePath, nameSpace, file2Write + ".proto"), result);
        }

    }

    public static void GenarateService(IEnumerable<DescriptorService> jServices)
    {
        var serviceBaseTemplateFileName = "cof_ps_service_base_h.cshtml";
        var serviceBaseTemplateSource = _all_template[serviceBaseTemplateFileName];

        var serviceHlrTemplateFileName = "cof_ps_service_h.cshtml";
        var serviceHlrTemplateSource = _all_template[serviceHlrTemplateFileName];

        var serviceTemplateFileName = "cof_ps_service.cshtml";
        var serviceTemplateSource = _all_template[serviceTemplateFileName];

        var serviceParamTemplateFileName = "cof_ps_service_param_protobuff.cshtml";
        var serviceParamTemplateSource = _all_template[serviceParamTemplateFileName];
            
        string file2Write;
        string result;

        result =
            Engine.Razor.RunCompile(
                serviceBaseTemplateSource,
                serviceBaseTemplateFileName, null,
                new { FileName = "service"}
            );

            CreateDir(Path.Combine(root, hrlWritePath));
            WriteMsgFile(Path.Combine(root, hrlWritePath, "service.h"), result);


        foreach (var jService in jServices)
        {
            string nameSpace = NameSpace2Dir(jService.Namespace);
            file2Write = ServiceParamFileName(jService.Name);
            result =
                Engine.Razor.RunCompile(
                    serviceParamTemplateSource,
                    serviceParamTemplateFileName, null,
                    new { FileName = file2Write, JService = jService }
                );
            CreateDir(Path.Combine(CppUtil.root, CppUtil.protoWritePath, nameSpace));
            WriteMsgFile(Path.Combine(root, protoWritePath, nameSpace, file2Write + ".proto"), result);


            file2Write = ServiceFileName(jService.Name);
            result =
                Engine.Razor.RunCompile(
                    serviceHlrTemplateSource,
                    serviceHlrTemplateFileName, null,
                    new { FileName = file2Write, JService = jService }
                );
            WriteMsgFile(Path.Combine(root, hrlWritePath, file2Write + ".h"), result);

            result =
                Engine.Razor.RunCompile(
                    serviceTemplateSource,
                    serviceTemplateFileName, null,
                    new { FileName = file2Write, JService = jService }
                );
            CreateDir(Path.Combine(root, writePath));
            WriteMsgFile(Path.Combine(root, writePath, file2Write + ".cpp"), result);

            }
    }

    public static void Generate(Descriptor cofThriftDesc)
    {
      try
      {
        //删除生成的代码,重新生成
        Clear(Path.Combine(CppUtil.root, CppUtil.writePath));
        Clear(Path.Combine(CppUtil.root, CppUtil.hrlWritePath));
        //Clear(Path.Combine(CppUtil.root, CppUtil.protoWritePath));
        //Clear(Path.Combine(CppUtil.root, CppUtil.DespatcherPath));
        //Clear(Path.Combine(CppUtil.root, CppUtil.ProcessorPath));

        foreach (var module in cofThriftDesc.ModuleList)
        {
          GenarateEnum(module.EnumList);
          GenarateStruct(module.StructList);
          GenarateService(module.ServiceList);
        }
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }
    }

    public static void WriteMsgFile(string path, string result)
    {
      //PSUInt64 i = new PSUInt64();
      //i.
      var utf8 = new UTF8Encoding(false);
      using (var fileStream = new StreamWriter(path, false, utf8))
      {

        fileStream.Write(result);
        fileStream.Flush();
      }
    }

    public static void Clear(string path)
    {
      if (Directory.Exists(path))
      {
        Directory.Delete(path, true);
        Console.WriteLine("delete path {0}", path);
      }
      Directory.CreateDirectory(path);
    }

    public static void CreateDir(string path)
    {
        if (!Directory.Exists(path))
        {
            Directory.CreateDirectory(path);
        }
    }
    }
}