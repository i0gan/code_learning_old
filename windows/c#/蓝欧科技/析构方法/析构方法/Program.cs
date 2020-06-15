using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 析构方法
{
    //析构方法和构造方法刚好相反，构造方法是初始化对象，析构方法是在对象要被销毁时来调用
    public class Myclass
    {
        public string str;
       
        //创建一个析构方法，*****************注意 1 每个类只能有一个析构方法，2 没有返回值，没有void，3 没有访问修饰符  4 不能加方法参数，更没有方法重载，由系统自动调用
        ~Myclass()                      //注意方法名前面的波浪符号
        {
            Console.WriteLine("嗨！你们好！");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass();
            P.str = "老王";
            Console.WriteLine(P.str);
            Console.WriteLine("程序运行结束");
            //结论：使用析构方法时，析构方法会在对象销毁时才执行，把剩下的内存空间分配给析构方法里面的字段
        }
    }
}
