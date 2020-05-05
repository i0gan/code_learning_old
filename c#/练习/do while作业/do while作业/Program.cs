using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace do_while作业                            //作业要求：使用do while语句求：sum=1+2+3+....+N;sum不超个10000；求N的最大值；
{
    class Program
    {
        static void Main(string[] args)
        {
            int sum = 1;
            int N = 0;
            do
            {   
                sum =sum+ N;
                N++;                
            }
            while (sum<=10000);
            N = N - 1;
            Console.WriteLine("N的最大值为：{0}",N);
            //作业完成

        }
    }
}
