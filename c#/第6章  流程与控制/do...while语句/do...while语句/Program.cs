using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace @do._._.while语句
{
    class Program
    {
        static void Main(string[] args)
        {
            bool a = false;
            int[] b = new int[4] { 0, 1, 2, 3, };
            do
            {
                for (int i = 0; i < b.Length; i++)
                {
                    Console.WriteLine(b[i]);
                }
            }
            while (a);

            Console.Read();


        }
    }
}
