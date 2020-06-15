using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法参数作业                    
{
    public class Myclass
    {
        public int My(ref int a, ref int b, ref int c)                                 //作业要求：实现一个方法，能够交换参数的值，并从小到大进行排序，提示使用ref实现                                            //使用ref使值类型跟引用类型效果一样，对外界产生影响
        {   int e;                      //互换a，b，c的值
            e = a;
            a = b;
            b = e;
            e = c;
            c = b;
            b = e;
            int[] A = new int[3] { a, b, c };                   //定义一个数组
            Array.Sort(A);                                      //使用Array.Sort方法使数组从小到大进行排序
            int o = 0;
            for (int i = 0; i < A.Length; i++)
            {
                o = A[i];
                Console.Write(o+"  ");                           //遍历排序后的数组
            }   return 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass();
            int x = 65;
            int y = 54;
            int z = 523;
            Console.WriteLine("互换前值为{0},{1},{2}",x,y,z);
            Console.WriteLine("从小到大排序为:");
            P.My(ref x, ref y, ref z);
            Console.Write("\n");
            Console.WriteLine("互换值后{0} {1} {2}", x,y,z)     //作业完成         *******************                    徐绿国    2017·7·26

        }
    }
}
