using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 对数组进行排序
{
    class Program
    {
        static void Main(string[] args)

        {
            Console.WriteLine("请输入四个数");
            int num = int.Parse(Console.ReadLine());                //输入数组中的元素值
            int num1 = int.Parse(Console.ReadLine());
            int num2 = int.Parse(Console.ReadLine());
            int num3 = int.Parse(Console.ReadLine());

            int[] a = new int[4] { num, num1, num2,num3 };                  //定义数组
           
            int c, d;
            for (int i=0;i<a.Length-1;i++)                      //根据数组下标的值遍历数组
            {
                c = i + 1;
                id:
                if(a[i]>a[c])                   //判断数的大小
                {
                    d = a[i];                           //将比较古大的元素赋给定义的int变量
                    a[i]= a[c];                         //将后一个元素的值赋值给前一个元素
                    a[c] = d;                           //将int变量中储存的元素值赋值给后一个元素
                    goto id;                            //返回标识，继续判断后面的元素
                }
                else
                {
                    if(c<a.Length-1)                    //判断是否执行到最后一个元素
                    {
                        c++;                            //如果没有，则在往后判断
                        goto id;                        //返回标识,继续判断后面的元素
                    }
                }
            }
            Console.WriteLine("数组按从小到大排序为");
            foreach (int e in a) 
            Console.Write(e+" ");

        }
    }
}
