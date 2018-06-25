using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace ProtoSharp
{
  public class CommonUtil
  {
    private static Regex reSplitPascalCase = new Regex("([A-Z]+[^A-Z]+)", RegexOptions.Compiled);
    private static Regex reSplitCamelCase = new Regex("(?<=[a-z])([A-Z])", RegexOptions.Compiled);
    private static TextInfo textInfo = new CultureInfo("en-US", false).TextInfo;

    public static Regex RegexPSHeadCheck = new Regex("PS", RegexOptions.Compiled);
    public static Regex RegexPSSHeadCheck = new Regex("PS", RegexOptions.Compiled);

    public static TextInfo TextInfo { get { return textInfo; } }
    public static IEnumerable<string> SplitPascalCase(string input)
    {
      return reSplitPascalCase.Split(input).Where(o => o != "");
    }

    //public static IEnumerable<string> SplitCamelCase(string input)
    //{
    //    return reSplitCamelCase.Split(input).Where(o => o != "");
    //}

    public static IEnumerable<string> SplitCamelCase(string input)
    {
      return Regex.Replace(input, "(?<=[a-z])([A-Z])", "_$1", RegexOptions.Compiled).Split('_');
    }


    public static IEnumerable<string> toCamelCase(IEnumerable<string> names)
    {
      names.First().ToLower();
      yield return names.First().ToLower();
      names = names.Skip(1);
      foreach (var i in names)
      {
        yield return CommonUtil.TextInfo.ToTitleCase(i);
      }
    }
    public static IEnumerable<string> ToTitleCase(IEnumerable<string> names)
    {
      foreach (var i in names)
      {
        yield return CommonUtil.TextInfo.ToTitleCase(i);
      }
    }

    static public IEnumerable<string> SplitCase(string name)
    {
      Char first = name[0];
      if (first >= 'A' && first <= 'Z')
      {
        //大写字符使用pascal case来分解
        return SplitPascalCase(name);
      }
      return SplitCamelCase(name);
    }

    public static IEnumerable<string> Flatten<T>(IEnumerable<T> enumerable)
    {
      foreach (var element in enumerable)
      {
        var candidate = element as IEnumerable<string>;
        if (candidate != null)
        {
          foreach (var nested in candidate)
          {
            yield return nested;
          }
        }
        else
        {
          var type = element as IEnumerable<T>;
          if (type != null)
          {
            foreach (var nested in Flatten(type))
            {
              yield return nested;
            }
          }
          else
          {
            yield return element.ToString();
          }
        }
      }
    }
  }

}
