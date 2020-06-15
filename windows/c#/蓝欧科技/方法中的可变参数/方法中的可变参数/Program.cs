using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法中的可变参数
{
    public class Myclass                                 //不知道调用传递多少个参数时，则可使用可变参数params关键字
    {                                                   //使用可变参数
        public int My(params int[] a)
        {
            int i = 0;
            foreach (int num in a)                  
            {
                i += num;                         //进行和运算
            }
            return i;
        }
        class Program
        {
            static void Main(string[] args)
            {
                Myclass P = new Myclass();
                int i = 0;
                 P.My(1,6,3,6,7);                           //传入参数
                i = P.My(1, 6, 3, 6, 7);
                Console.WriteLine(i);
            }
        }
    }
}
