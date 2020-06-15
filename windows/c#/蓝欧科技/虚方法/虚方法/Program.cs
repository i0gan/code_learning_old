using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 虚方法           //使用类继承，方法替换，方法名一样，并且类型前面加上一个关键字new

{
    public class Myclass
    {
        public void My()
        {
            Console.WriteLine("Hello");
        }
        //定义一个虚方法,等待重写
        public virtual void My2()
        {
            Console.WriteLine("我叫老王");
        }
    }
    public class Myclass2:Myclass
    {
        //方法替换，方法名一样，并在类型前面加上new
        public new void  My()
        {
            Console.WriteLine("你好！");
        }
        public override void My2()
        {
            Console.WriteLine("老王好！");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {   //使用父类类型引用父类对象
            Myclass M = new Myclass();
            M.My();
            M.My2();
            //使用子类类型引用子类对象
            Myclass2 M2 = new Myclass2();
            M2.My();
            M2.My2();
            //使用父类类型引用子类对象
            Myclass M3 = new Myclass2();
            M3.My();
            M3.My2();           //多态：使用父类类型调用子类中实现的方法
            

            }
        }
    }
