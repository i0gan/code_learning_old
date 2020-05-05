using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习3
{
    public   struct run                     //定义一个公共类型结构体
    {
       public int num;
       public int num2;
        
    }
    public class run2                       //定义一个公共类
    {


        public string str2 = "你是";
        public struct run3                      //在类中嵌套一个结构体
        {
            public string str;
        }
    }
     public class run3                                      //创建一个公共类
    {
        public void Fangfa(int i)                           //创建一个方法
        {
            Console.WriteLine(i);
        }
        public void Fangfa2(int y, int z)                       //创建一个方法
        {
            int i = y * z;
            Console.WriteLine(i);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            run a = new run();                  //使用结构体创建一个a对象
            a.num = 3;
            Console.WriteLine(a.num);             
            run2 b = new run2();              //使用结构体创建一个a对象
            Console.WriteLine(b.str2);
            run3 c = new run3();
            c.Fangfa(3);

            run3 o = new run3();                    //
            o.Fangfa2(3, 5);
            run2.run3 str = new run2.run3();  //****************************结构体，类，方法的使用，LYXF**********************************
            str.str = "你是";
            Console.WriteLine(str.str);  //****************************结构体，类，方法的使用，LYXF**********************************
            run g = new run();
            int num6 = int.Parse(Console.ReadLine());  //****************************结构体，类，方法的使用，LYXF**********************************
            g.num2 = num6;
            Console.WriteLine("你输入的值为:{0}",g.num2);         //输出
           
    //****************************结构体，类，方法的使用，LYXF**********************************
        }
    }
}
