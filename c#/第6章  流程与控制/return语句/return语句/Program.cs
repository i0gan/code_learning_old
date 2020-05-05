using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace return语句
{
    class Program
    {
        static string Mystr(string str)                 //创建string方法
        {
            string OutStr;
            OutStr = "你输入的数据是" + str;           
            return OutStr;                              //使用return语句
        }
        static void Main(string[] args)
        {
            Console.WriteLine("请输入你的内容");            //获取用户输入的数据
            string a = Console.ReadLine();
            Console.WriteLine(Mystr(a));                        //输出



        }
    }
}
