using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 逻辑运算作业
{
    class Program
    {                                            //作业要求：从控制台输入三个数a,b,c,使用关系运算符和逻辑运算来判断a是否为最大数，是就输出true，否则输出false
        static void Main(string[] args)
        {
            Console.WriteLine("请输入三个数，a,b,c");
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            int c = Convert.ToInt32(Console.ReadLine());
            bool d;
            d =( a > b) && (a > c);
            string e = d ? "a是最大数" : "a不是最大数";
            Console.WriteLine(e);




        }
    }
}
