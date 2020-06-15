using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 构造方法
{
    public class Myclass
    {
        public string name;
        public int age;
        //构造方法  -  负责初始化对象
        //条件：方法名和类名相同，没有返回值，不需要些void
        //构造方法能够添加参数
        public Myclass()
        {
            Console.WriteLine("你好！");
            //用构造方法初始化字段
            name = "老王";
            age = 44;

        }
        //给方法增加参数，并用参数给字段赋值
        //构造方法允许方法重载，下列为例；
        public Myclass(string name,int age)
        {
            this.name = name;           //使用this的代表是Myclass中的字段，后边的是方法参数
            this.age = age;             
        }

        //如果没有写构造方法，系统它会自动默认构造一个构造方法如
     /*    public Myclass()
          {

           }  */              //里面是空的构造方法，所以没有写构造方法直接使用new来创建对象是不会报错的

    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass P = new Myclass("徐绿国",16);          //使用构造方法给字段赋值后，则创建对象时括号内为构造方法的参数值，如果有方法重载，括号内没有参数则会运行其他方法
            Console.WriteLine("姓名:{0}",P.name);
            Console.WriteLine("年龄：{0}岁",P.age);

        }
    }
}
