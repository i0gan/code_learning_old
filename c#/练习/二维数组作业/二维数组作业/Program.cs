using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二维数组作业                    //作业要求：1 有一个3行4列的二维数组，使用编程找出元素中的最大值，并输出所在的行和列
{                                         //2 将一个二维数组的行和列进行交换，储存到另一个二维数组中
                                          //3 int[] intArray ={1,2,3,4,5}:使用foreach遍历，求所有元素之积
    class Program
    {
        static void Main(string[] args)
        {
            int[,] arr = new int[2, 3]
            {
                {2,53,3 },
                {3,6,9 }
            };
            int[,] arr2 = new int[3, 2];
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(arr[0,i]);
            }
        }
    }
}
