using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 数组的使用
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] a = new int[2, 3] { { 1, 5, 6 }, { 1, 6, 3 }, };
            a[2,2]= 3;
            Console.WriteLine(a[2,2]);
        }
    }
}
