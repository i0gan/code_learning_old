using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 访问过修饰符
{
    class Program                                   ////////访问修饰符有public,private,protected,internal//////
    {                                                   //访问修饰符不仅能赋给结构体中的变量，还可以赋给结构体
        struct str                              // 如果没有注明结构体类型，默认internal，只能在程序集中使用，
        {
            public int num;                         //定义公共int类型变量
            private byte num2;                      //定义byte类型公共变量
            internal float num3;            //只能在类中或子类使用
            int num4;               //默认为private
        }
        static void Main(string[] args)
        {
            str a;
            a.num = 3;      //给公共成员num赋值
                            //不能给private和internal类型成员赋值，不可以使用

            Console.WriteLine(a.num);
        }                                               
    }                                                  
}
