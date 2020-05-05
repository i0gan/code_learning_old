using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 类和对象
{   class Person                //定义一个类，类的默认修饰符是internal
    {                              
        public int a;                 //类的使用  
    }
    class Person2                   //类的使用  
    {
        public string b;                                  //类的使用  
    }
    class Person3
    {
        public string c;                                           //类的使用  
    }
    class Person4
    {
        public string v;
    }
    class Program
    {
        static void Main(string[] args)
        {
            Person wo = new Person();        //创建对象wo并进行初始化，对象也可以叫做类的实例    
            wo.a = 3;                           //使用类创建对象的过程也叫做实例化
            Console.WriteLine(wo.a);
            Person2 ni = new Person2();
            ni.b = "你是？";
            Console.WriteLine(ni.b);
            Person3 ta = new Person3();
            ta.c = "他是";
            Console.WriteLine(ta.c);
            Person4 tamen = new Person4();
            tamen.v = "哦";
            Console.WriteLine(tamen.v);
        }
    }
}
