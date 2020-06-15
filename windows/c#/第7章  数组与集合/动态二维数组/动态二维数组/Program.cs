using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 动态二维数组
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入数组的行数");                      //提示用户输入行数
            Console.WriteLine("请输入数组的列数");                          //提示用户输入列数
            int a = int.Parse(Console.ReadLine());                          //获取用户数据
            int b=int.Parse(Console.ReadLine());
            int[,] i = new int[a, b];                                  //获取用户数据
            Console.WriteLine("结果");
            for (int c = 0; c < a; c++)                     //使用for循环语句
            {
                for (int o = 0; o < b; o++)                         //二重循环
                {

                    Console.Write(c + o.ToString() + "  ");                //输出
                }
              
            }
            Console.ReadLine();
        }
    }
}
