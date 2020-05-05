using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习4
{
    public class Myclass
    {
        public int My ( ref  int a,ref   int b,ref   int c)
        {
            

            int max = a;
            if(max<b)
            {
                max = b;
            }
            if(max<c)
            {
                max= c;
            }
            int min = a;
            if(min>b)
            {
                min = b;
            }
            if(min>c)
            {
                min = c;
            }
            
            

            return 0;

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass();
            int x = 5;
            int y = 7;
            int z = 3;
            P.My(ref  x, ref  y,ref  z);
            Console.WriteLine("排序后:");
            Console.WriteLine("x值为：{0} y值为：{1} z值为{2}", x, y, z);


        }
    }
}
