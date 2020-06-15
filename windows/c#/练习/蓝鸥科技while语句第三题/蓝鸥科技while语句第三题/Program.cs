using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 蓝鸥科技while语句第三题
{
    class Program           //作业要求：使用while循环打印出满足下列条件的值：处于100-10000之间的并且各位数之和是7（如241：2+4+1=7）
    {
        static void Main(string[] args)
        {
            int a, b, c, d = 100;
            while (d <= 1000)
            {
                a = d / 100;
                b = (d - a * 100) / 10;
                c = d - a * 100-b*10;
                if ((a + b + c )== 7)
                {
                    Console.WriteLine(d);
                }
                d++;
            }
            //抄完了，大概能理解，，，，2017.8.10            徐绿国；；；；；
        }
    }
}
