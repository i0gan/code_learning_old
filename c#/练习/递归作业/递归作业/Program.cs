using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 递归作业                  //作业要求：1 利用递归计算1+2+3+4+5+........+99+100; 2 求n=18时，1*2*3*4*.....*18;

{
    public class Myclass
    {
        public int My (int x)               //注意只有声明一个变量           
        {
            if(x>1)
            {
                return  My (x - 1) + x;                                     //注意 My  进行递归
            }
            else
            {
                return 1;
            }
        }
        public long  MY(long  x)                    //声明一个long类型的方法
        {
            if (x > 1)
            {
               return MY (x-1)  *  x;                   //进行递归
            }
            else
            {
                return 1;
            }
        }
        
        
        }

    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass();
            Console.WriteLine(P.My(100));
            Console.WriteLine(P.MY(18));
            //作业完成******************徐绿国
        }
    }
}
