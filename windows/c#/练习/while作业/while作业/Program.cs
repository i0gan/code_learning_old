using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace while作业                   //作业要求：1 使用while循环计算1+2+.....+100的值
{                                     //2 使用while打印出1....100之间的偶数                        
                                      //3 使用while打印出满足下列条件值：处于100-1000之间并且各位数之和为7，如（241：2+4+1=7）
    class Program
    {
        static void Main(string[] args)
        {
            int a = 0;
            int i = 0;
            while (a < 100)
            {
                a++;
                i += a;
            }
            Console.WriteLine(i);
            a = 0;
            while (a < 100)
            {
                a++;
                if (a % 2 == 0)
                {
                    Console.WriteLine(a);
                }
            }
        }
    }
}                                       //作业未完成 ******
