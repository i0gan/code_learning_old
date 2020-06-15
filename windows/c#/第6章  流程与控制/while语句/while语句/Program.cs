using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace while语句
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 1;         //定义变量a
            int b = 2;
            while (a <= 10)         //使用while方法
            {
                b = (a*a+a)/2;
                Console.WriteLine(b);               //输出
                a++;
            }

        }
    }
}
