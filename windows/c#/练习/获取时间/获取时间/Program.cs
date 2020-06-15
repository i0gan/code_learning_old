using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 获取时间
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime time = DateTime.Now;
            string str = string.Format("{0:F}", time);
            Console.WriteLine("今天是{0}", str);
            int num = (int)DateTime.Now.DayOfWeek;
            if (num == 0)
            {
                Console.WriteLine("今天是星期天");
            }
            else
            {
                if (num == 1)
                {
                    Console.WriteLine("今天是星期一 ");
                }
                else
                {
                    if (num == 2)
                    {
                        Console.WriteLine("今天是星期二");
                    }
                    else
                    {
                        if (num == 3)
                        {
                            Console.WriteLine("今天是星期三");
                        }
                        else
                        {
                            if (num == 4)
                            {
                                Console.WriteLine("今天是星期四");
                            }
                            else
                            {
                                if (num == 5)
                                {
                                    Console.WriteLine("今天是星期五");
                                }
                                else
                                {
                                    Console.WriteLine("今天是星期六");
                                }
                            }
                        }
                    }
                }
            } 
        }
    }
}
