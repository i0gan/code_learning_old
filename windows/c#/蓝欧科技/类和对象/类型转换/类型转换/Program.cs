using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 类型转换
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 18;
            float b;
            b = (int)a;             //隐式转换，由低精度向高精度转换
            Console.WriteLine(b);

            float c=3.5f;
            int d = (int)c;             //强制类型转换，由高精度向低精度转换，会造成精度丢失,并且舍去后面的小时
            Console.WriteLine(d);
            //Int32表示32位的整数类型
            int e = Convert.ToInt32(c); // 强制系统转换，由高精度向低精度转换，会造成精度丢失,用四舍五入方法舍去后面的小数
            Console.WriteLine(e);
            //Int16刚好是shoot类型
            short f = Convert.ToInt16(c);
            Console.WriteLine(f);

            int h = 15;
            //Single表示单精度浮点数
            float i = Convert.ToSingle(h);      //强制转换位float类型
            
            //字符串类转值类
            string str = "1415";
            int num = Convert.ToInt32(str);         //字符串类型强制转换为值类型，字符串中只能含有数字
            //值类转字符串类
            int num2 = 14123;
            str=Convert.ToString(num2);                 //使用系统强制转换
            Console.WriteLine(str);
            //使用解析方法转换
            //Parse表示解析
            num = int.Parse(str);                       //使用解析法将字符串类强制转换为值类
            Console.WriteLine(num);
            float flo = float.Parse(str);           //使用解析法强制转换
            Console.WriteLine(flo);
        }

    }
}
