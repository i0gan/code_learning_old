using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 一维数组
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = new int[4] { 1, 2, 3, 4 };                                //定义一个值类型数组
            foreach (int b in a)                                               //使用foreach语句
            {
                Console.WriteLine(b);                                           //输出
             
            }
            string[] str = new string[3] { "I", "You","They" };                 //定义一个字符串数组
           foreach(string c in str)                                              //使用foreach语句
            {
                Console.WriteLine(c);                                             //输出
            }
        }
    }
}
