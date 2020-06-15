using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace while作业2                              //作业要求：使用while和continue来实现：1-100之间3的整数倍；
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            while (i < 100)
            {
                i++;
                if (i % 3 == 0)
                {
                    Console.WriteLine(i);
                    continue;
                }
            }
        }
    }
}               //完成
