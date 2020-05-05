using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 枚举
{
    enum week                   //定义一个枚举
    {
        Sun,                        //定义星期   注：枚举类型从上往下从0开始逐步增加1
        Mon,
        Tue,
        Wed,
        Thu,
        Fir,
        Sat,
    }
    class Program
    {
        static void Main(string[] args)
        {
            week a = week.Wed;                  //把week枚举中的wed赋给a
            Console.WriteLine(a);                   //输出a
            Console.WriteLine("使用强制转换后a为：{0}",(int)a);          //强制转换为int类型输出
        }
    }
}
