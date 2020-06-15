using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace switch语句
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入月份");
            int a = int.Parse(Console.ReadLine());
            string b;
            switch(a)
            {
                case 12:
                case 1:
                case 2:
                    b = "你输入的月份是冬季";           break;
                case 3:
                case 4:
                case 5:
                    b = "你输入的月份是春季";           break;

                case 6:
                case 7:
                case 8:
                    b = "你输入的月份是夏季";           break;
                case 9:
                case 10:
                case 11:
                    b = "你输入的月份是秋季";           break;

                default:
                    b = "你输入的月份有误！";            break;

            }
            Console.WriteLine(b);
            Console.Read();

        }
    }
}
