using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 乘法口诀表程序
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("乘法口诀表");
          
            for( int a=1;a<10;a++)                              //运用单循环控制行数
            {
                Console.WriteLine();
                for(int b=1;b<= a;b++)                          //利用二重循环控制列数
                {
                    Console.Write("{0}*{1}={2}\t",a,b,a*b);             //输出
                }
             }
            Console.Read();
        }
    }
}
