using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入判断的次数");
            Console.WriteLine("请输入a,d,w,s判断走向");
            int num = int.Parse(Console.ReadLine());
            const string w = "w";
            const string s = "s";
            const string a = "a";
            const string d = "d";
           
             int i = 1;
            while (i <= num)
            {
                i = i + 1;
                string b = Console.ReadLine();
                switch (b)
                {       
                    case w: Console.WriteLine("向前走"); break;
                    case s: Console.WriteLine("向后走"); break;
                    case a: Console.WriteLine("向左走"); break;
                    case d: Console.WriteLine("向右走"); break;
                    default:
                        Console.WriteLine("输入有误"); break;
                }
            }
            Console.Read();
        }
    }
}
