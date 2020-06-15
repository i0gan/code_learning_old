using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace for语句
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = new int[5];               //声明具有5个元素的数组
            a[0] = 0;                            //向数组中添加元素
            a[1] = 2;
            a[2] = 4;
            a[3] = 6;
            a[4] = 8;
            for (int b = 0; b < a.Length; b++)                  //使用for语句
            {
                Console.WriteLine("数列{0}为{1}", b, a[b]);             //注意("数列{0}为{1}", b, a[b])中的a[b]       输出
            }
            Console.WriteLine("for语句二重循环");
            for (int c = 1; c < 10; c++)
            {
                Console.WriteLine();
                for (int d = 1; d <= c; d++)
                {
                    Console.Write("{0}*{1}={2}\t",c,d,c*d);
                }

            }

            Console.ReadLine();
           
        }
    }
}
