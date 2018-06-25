using ProtoSharp;
using RazorEngine;
using RazorEngine.Templating;
using System;
using System.Collections.Generic;
using System.IO;
using System.Web;

namespace CppGenerator
{
    public partial class CppUtil
    {
    #region 全局变量

    static string _projectRoot = CppUtil.root;
    static string DespatcherPath = @"server/src/protosharp_gen";
    static string ProcessorPath = @"server/src/protosharp_processor";

    #endregion

    public static void LoadHandlerTemplate()
    {
      var l = new List<string>
            {
                "cof_ps_dispatcher.cshtml",
                "cof_ps_gen_handler.cshtml",
            };

      foreach (var s in l)
      {
        _all_template[s] = LoadTemplate("Templates.Handler", s);
      }
    }

    public static string ProjectRoot
    {
      get
      {
        return _projectRoot;
      }
    }


    public static void GenarateProcessor(DescriptorService[] jServices)
    {
      string pr = ProjectRoot;
      var serviceTemplateFileName = "cof_ps_dispatcher.cshtml";
      var serviceTemplateSource = _all_template[serviceTemplateFileName];

      var serviceHandlerTemplateFileName = "cof_ps_gen_handler.cshtml";
      var serviceHandlerTemplateSource = _all_template[serviceHandlerTemplateFileName];

      //var serviceStructReturnFileName = "cof_ps_struct_return.cshtml";
      //var serviceStructReturnTemplateSource = _all_template[serviceStructReturnFileName];

      //var serviceStructParamFileName = "cof_ps_struct_param.cshtml";
      //var serviceStructParamTemplateSource = _all_template[serviceStructParamFileName];


      string file2Write;
      string result;
      file2Write = "ps_dispatcher";
      result =
          Engine.Razor.RunCompile(
          serviceTemplateSource,
          serviceTemplateFileName, null,
          new { FileName = file2Write, JServices = jServices }
          );
      WriteMsgFile(Path.Combine(ProjectRoot, DespatcherPath, file2Write + ".erl"), result);

      foreach (var service in jServices)
      {
        if (service.NeedServerProcessor)
        {
          file2Write = "gen_processor_" + CppStyleName(service.Name);
          result =
              Engine.Razor.RunCompile(
              serviceHandlerTemplateSource,
              serviceHandlerTemplateFileName, null,
              new { FileName = file2Write, JService = service }
              );
          WriteMsgFile(Path.Combine(ProjectRoot, ProcessorPath, file2Write + ".erl"), result);
        }
      }

    }
  }
}
