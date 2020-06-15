using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 判断奇偶数
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入所要判断的数字");
            int a = int.Parse(Console.ReadLine());
            if (a < 0)
            {
                Console.WriteLine("你输入的是负数");
            }
            else
            {
                if (a > 0)
                {


                    bool b;
                    b = a % 2 == 1;

                    string c = b ? "你输入的是奇数" : "你输入的是偶数";
                    Console.WriteLine(c);
                }
                else
                {
                    Console.WriteLine("你输入的是0，它即不是正数也不是负数,也不是奇偶数");
                }
                Console.ReadLine();
            }
        }
    }
}
