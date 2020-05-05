using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习5
{
    public class Person
    {
        public int My(int a,int b,int c)                            //实现功能输入三个数，将它们从小到大进行排序
        {
            int[] num = new int[] { a, b, c };
            Array.Sort(num);                                        //用Array中的Sort方法对一维数组进行从小到大排序
            foreach (int e in num)                                   //进行遍历
            {
                Console.Write(e+"   ");
            }
            return a;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Person P = new Person();
            Console.WriteLine("请输入三个数字");
            int x = Convert.ToInt32(Console.ReadLine());                //输入
            int y = Convert.ToInt32(Console.ReadLine());
            int z = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("排序后");
            P.My(x, y, z);                                               //发送其值
        }
    }
}
