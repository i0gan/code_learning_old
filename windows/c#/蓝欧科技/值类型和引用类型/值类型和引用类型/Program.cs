using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 值类型和引用类型
{
    public class Person                                         //类属于引用类型
    {
        public string a;
        public string b;
    }
    class Program
    {
        static void Main(string[] args)
        {
            //定义两个值类型变量
            Console.WriteLine("值类型");                           //值类型操作时，后面的变量发生改变时，其前面的变量不会发生改变
            int a = 4;                                            //引用类型在同一空间操作时后面的变量发生改变时，其前面的变量会同时发生改变，并且值相同
            int b;
            b = a + 5;
            Console.WriteLine("a值为{0},b值为{1}",a,b);
            Console.WriteLine("引用类型");
            Person A;           //定义两个引用类型变量
            Person B;
            A = new Person();
            B = new Person();
            A = B;
            A.a = B.a;                  //A.a和B.a都属于在同一空间
            A.a = "老王";
            B.a = "徐绿国";
            Console.WriteLine(A.a);
            Console.WriteLine(B.a);
            //值类型是在栈中分配空间的，它自动分配空间，引用类型是在堆中分配空间的，需要手动分配空间*************
          
        }
    }
}
