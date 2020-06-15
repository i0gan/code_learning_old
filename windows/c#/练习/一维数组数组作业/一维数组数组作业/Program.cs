using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 一维数组数组作业
{
    class Program
    {
        //作业要求： 将数组 int[] intArray = { 2, 3, 5, 7, 11, 13, 17 };把所有数组元素反向打印出来，求数组元素的和，求出数组中的最大值和最小值
        static void Main(string[] args)
        {
            int[] intArray = { 2, 3, 5, 7, 11, 13, 17 };
            Console.WriteLine("反向输出为：");
            for (int i = intArray.Length-1;i>=0; i=i-1)         //使用for中i逐渐递减来实现数组反向输出
            {
                Console.Write(intArray[i]+"  ");                //输出
            }
            int num=0;
            for (int j = 0; j < intArray.Length; j++)
            {   
                num = intArray[j]+num;                          //求和
                
            }
            Console.WriteLine("\n");
            Console.WriteLine("数组和为:");
            Console.WriteLine(num);
            Array.Sort(intArray);                                   //使用Array.Sort对数组进行从小到大进行排序
            Console.WriteLine("最大值为：{0},最小值为:{1}",intArray[intArray.Length-1],0);           //输出
            //作业完成************                徐绿国
        }
    }
}
