using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringBuilder类使用
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 1000;
            StringBuilder b = new StringBuilder("努力了梦想就在眼前");
            b.Append("VS放弃注定失败");
            Console.WriteLine(b);
            b.AppendFormat("{0:C}", a);
            Console.WriteLine(b);
            b.AppendLine("你好");
            Console.WriteLine(b);
            b.Insert(3,"呵呵");
            Console.WriteLine(b);
            b.Remove(1, 3);
            Console.WriteLine(b);
            b.Replace("放弃", "失败");
            Console.WriteLine(b);
            Console.ReadLine();

            
        }
    }
}
