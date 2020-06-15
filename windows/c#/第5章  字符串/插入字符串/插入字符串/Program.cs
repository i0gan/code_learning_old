using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 插入字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            string str1 = "在干嘛,";
            string str2 = str1.Insert(1, "那");                          //插入字符串
            string str3 = str2.Insert(5, "还不赶快回家！");
            Console.WriteLine(str3);
        }
    }
}
