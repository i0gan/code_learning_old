using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 转义字符
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "你好老王！";
            string str2 = "我是徐绿国";
            Console.WriteLine(str +str2);
            string str3 = "'";
            Console.WriteLine(str3);
            Console.WriteLine("今天是二零         一七年\n大家好");             //使用\n换行
            Console.WriteLine("我相信明天会\"更加美好");              //使用\表示加入双引号
            Console.WriteLine("\t我相信\\明天会\'更加美好");                  //使用\表示加入单引号
            Console.WriteLine("\r");
            Console.ReadLine();
        }
    }
}
