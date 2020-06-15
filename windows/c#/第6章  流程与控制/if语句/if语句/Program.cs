using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace if语句
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 12;
            int b = 18;
            int c = 22;
            int d = 30;
            int e = 50;
            Console.WriteLine("请输入你的年龄");
            int f = int.Parse(Console.ReadLine());
            if (f <= a)
            {
                Console.WriteLine("你还是童年");
            }
            else
            {
                if (a < f && f < b)
                {
                    Console.WriteLine("你已是青少年哦，是奋斗的黄金时期");
                }

                else
                {
                    if (b <= f && f < c)
                    {
                        Console.WriteLine("你已成年了，可以自由了");
                    }
                    else
                    {
                        if (c <= f && f < d)
                        {
                            Console.WriteLine("你现在正是努力的黄金时期，并且可以取老婆了");
                        }
                        else
                        {
                            if (d <= f && f < e)
                            {
                                Console.WriteLine("你现在是人生的黄金时期，享受人生吧！");

                            }
                            else
                            {
                                Console.WriteLine("你已进入更年期了注意身体哦！");
                            }
                        }
                    }
                }
            }
            Console.ReadLine();
        }
    }
}
        