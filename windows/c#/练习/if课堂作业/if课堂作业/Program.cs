using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace if课堂作业
{                                                               //作业要求：输入一个年份，判断出输入的年份是否是闰年
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入年份");
            int a = int.Parse(Console.ReadLine());
            bool b;
            b = (a % 400 == 0) || ((a % 100 != 0) && (a % 4 == 0));             //注意100，200，300，不是闰年
            string str = b ? "是闰年" : "不是闰年";
            Console.WriteLine(str);
        }
    }
}
