using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 截取字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("用Substring方法截取字符串");
            string a = "只要你努力了就能成功!";        //声明一个字符串变量
            Console.WriteLine(a);                      //显示原来的字符串
            Console.WriteLine("截取后");
            string b = a.Substring(2, 8);             //声明并用Substring方法截取字符串
            Console.WriteLine(b);                      //输出字符串变量b的值
            Console.Read();
        }
    }
}
