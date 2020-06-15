using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法重载作业
{
    class Program                                                           //作业要求：创建一个重载方法，求两个数的乘积，参数类型分别为：int，float，double。
    {
        public class Myclass
        {
            public int My(int a,int b)
            {
                return a * b;
            }

            public float My(float a, float b)
            {
                return a * b;
            }
            public double My(double a,double b)
            {
                return a * b;
            }

        }
        static void Main(string[] args)
        {
            Myclass P = new Myclass();                
            Console.WriteLine( P.My(1,6));                  //为整数类型
            Console.WriteLine(P.My (1.55f,6.85f));          //为浮点数float类型
            Console.WriteLine(P.My(1.73d,88.4d));           //为浮点数double类型
            //作业完成 *********************徐绿国
        }
    }
}
