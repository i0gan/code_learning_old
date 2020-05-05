using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 逻辑运算
{
    class Program
    {
        static void Main(string[] args)
        {
            //逻辑与运算
            bool a;
            bool b;
            bool c;

            a = (3 == 4) & (3+6== 4);              //与运算必须两个为真才为真
            b = (3 == 3) | (3 + 6 == 4);            //或运算必须有一个或两个都是真才为真            
            c=(3 == 8) | (3 + 6 == 4);              //异或运算必须两个为假才为真
            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(c);
            //逻辑与和逻辑或的短路现象
            int d = 6;
            a = (3 == 4) && ((d = d + d) <= 12);
            Console.WriteLine(d);                   //现象d没有增加，，，，结论当逻辑与计算前面的值为假时，则后面的值不用计算
            a = (3 == 3) || ((d = d + d) <= 12);
            Console.WriteLine(d);                    //现象d没有增加，，，，结论当逻辑与计算前面的值为真时，则后面的值不用计算
            //逻辑非运算符
            bool oo = true;
            a = !oo;                                //只连接一个操作数
            Console.WriteLine(a);                   //逻辑非是将值取反
            
            
              
        }
    }
}
