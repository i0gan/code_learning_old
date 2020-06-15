using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法中输出参数
{
    public class Myclass
    {
        //使用out修饰符来输出
        public int Max(int a,int b,int c,out  int min)          //使用out来实现同时输出两个值
        {
            min = a;            //注意使用out关键字时需要初始化&&&&&&&&&&     
            if (min>b)
            {
                min = b;
            }
            if (min > c)
            {
                min = c;
            }



            int unm=a;                      //方法作用同时输出最大值和最小值，则需要out来实现
            if (unm<b)
            {
                unm = b;
            }
           
            if(unm<c)
            {
                unm = c;
            }
            return unm;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass();
            int i = 6;
            int x = 7;
            int y = 77;
            int z =0;                                
            P.Max(i, x, y,out z);                   //传入参数，必须加out
            Console.WriteLine("值的最大值为：{0}最小值为{1}",P.Max(i,x,y,out  z),z);
            //如果要获取哪个参数的返回值就在其参数前面加入out关键字，************************
        }
    }
}
