using System;
using System.Collections.Generic;
using System.Reflection;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections;
using RazorEngine;
using RazorEngine.Configuration;
using RazorEngine.Templating;
using RazorEngine.Text;
using Newtonsoft.Json;
using System.IO;
using Newtonsoft.Json.Linq;
using ProtoSharp;
using System.Security;
using System.Security.Permissions;
using System.Security.Policy;

namespace CppGenerator
{
    class Program
    {
        const string root = "/";

        static int MainGenerate(string dllPath)
        {
            if (AppDomain.CurrentDomain.IsDefaultAppDomain())
            {
                // RazorEngine cannot clean up from the default appdomain...
                Console.WriteLine("Switching to secound AppDomain, for RazorEngine...");
                AppDomainSetup adSetup = new AppDomainSetup();
                adSetup.ApplicationBase = AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
                var current = AppDomain.CurrentDomain;
                // You only need to add strongnames when your appdomain is not a full trust environment.
                var strongNames = new StrongName[0];

                var domain =
                    AppDomain.CreateDomain(
                    "MyMainDomain", null,
                    current.SetupInformation, new PermissionSet(PermissionState.Unrestricted),
                    strongNames
                    );

                //return domain.ExecuteAssemblyByName(Assembly.GetExecutingAssembly().Location);
            }

            //var file = @"D:\dev\cof\server\cof\cof_port\src\protocol\thrift\cof.json";
            //var jsonString = File.ReadAllText(file);
            //JObject jsonObject = JsonConvert.DeserializeObject(jsonString) as JObject;

            //DescriptorProtoFile.Descriptor.ToString();
            var config = new TemplateServiceConfiguration();
            var service = RazorEngineService.Create(config);
            config.Language = Language.CSharp; // csharp.NET as template language.
            config.EncodedStringFactory = new RawStringFactory(); // Raw string encoding.
            config.EncodedStringFactory = new HtmlEncodedStringFactory(); // Html encoding.
            config.Debug = true;
            Engine.Razor = service;
            //ExtensionRegistry extensionRegistry = ExtensionRegistry.CreateInstance();
            //CSharpOptions.RegisterAllExtensions(extensionRegistry);
            //var descriptor = new Descriptor(typeof(crucis.ServiceFactory));
            var descriptor = new Descriptor(dllPath);

            try
            {
                CppUtil.Generate(descriptor);
                return 0;
            }
            catch (Exception e)
            {
                e.ToString();
                return 1;
            }
        }
        static void Main(string[] args)
        {
            if(args.Length < 1)
            {
                Console.WriteLine("Usage:" +
                    "CppGenerator.exe --import=D:/dir/abc.dll");
            }

            List<string> param_list = new List<string>();

            string param_dir="";
            for(int i = 0; i < args.Length; i++)
            {
                param_list.Add(args[i]);
                int pos = -1;
                if((pos = args[i].IndexOf("import")) >=0)
                {
                    int pos2 = args[i].IndexOf('=');
                    param_dir = args[i].Substring(pos2 + 1).Trim();
                }
            }

            if(param_dir.Length < 0)
            {
                Console.WriteLine("Usage:" +
                    "CppGenerator.exe --import=D:/dir/abc.dll");
                return;
            }

            Console.WriteLine("Usage:" + param_dir);
            MainGenerate(param_dir);
        }
    }
}
