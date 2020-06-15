using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace for循环作业
{
    class Program                                   //作业要求：1、 使用for循环打印1-100中不能被7整除的数，不包括7，2、 使用for循环计算1+3+5+7.....+99的数，3 、打印出乘法口诀表
    {
        static void Main(string[] args)
        {
            for (int i = 1; i <= 100; i++)
            {
                if (i % 7 == 0)                                 //把能整除7的数去掉
                {
                }
                else
                {
                    Console.Write(i + "  ");                  //输出
                }
            }
            int a = 0;
            for (int y = 1; y < 100; y = y + 2)
            {
                a += y;
            }
            Console.WriteLine();
            Console.WriteLine("计算从1到99的奇数和为：{0}", a);
            for (int x = 1; x <10; x++)
            {
                Console.Write("\n");
                for (int y = 1; y<= x; y++)
                {
                    Console.Write("{0}*{1}={2}\t",x,y,x*y);
                }
            }
            //作业完成**************************徐绿国*************
            
        }
    }
}
