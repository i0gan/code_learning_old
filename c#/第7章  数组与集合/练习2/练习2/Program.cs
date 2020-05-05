using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = (int)DateTime.Now.DayOfWeek;
            DateTime b = DateTime.Now;

            switch(a)
            {
                case 1:
                    Console.WriteLine("今天是星期一");
                    break;
                case 2:
                    Console.WriteLine("今天是星期二");
                    break;
                case 3:
                    Console.WriteLine("今天是星期三");
                    break;
                case 4:
                    Console.WriteLine("今天是星期四");
                    break;
                case 5:
                    Console.WriteLine("今天是星期五");
                    break;
                case 6:
                    Console.WriteLine("今天是星期六");
                    break;
                case 0:
                    Console.WriteLine("今天是星期天");
                    break;
            }
            Console.WriteLine("{0:F}",b);
            Console.ReadLine();
        }
    }
}
