using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二位数组
{
    class Program
    {
        static void Main(string[] args)                                                         //静态二维数组
        {
            int[,] a = new int[2, 2] { { 1, 2 }, { 3, 4 } };                                //定义二维数组
            Console.Write("数组的行数为：{0}\n", a.Rank);                                   //获取数列行数并输出
            Console.WriteLine("数组的列数为：{0}", a.GetUpperBound(a.Rank - 1) + 1);  //获取数列列数并输出
            foreach(int num in a)                                   //使用foreach语句输出
            {
                Console.Write(num);
            }


            Console.Write("\n");



            for (int i = 0; i < a.Rank; i++)                                //循环输出
            {
                string str = "";
                for (int j = 0; j < a.GetUpperBound(a.Rank - 1) + 1; j++)
                {
                    str = str + Convert.ToString(a[i, j]) + " ";

                }                                                                                   
                Console.Write(str);
                Console.Write("\n");
            }
        }
                                                                                            //——————————LYXF——————————
    }
}
