using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法

{
    class son
    {
        //定义一个方法,语法格式为：访问修饰符  返回值类型  方法名  (参数列表) {语句,...，retern返回值;)            //retern有些有有些没有
        //void表示没有返回值
        public void run() {
            Console.WriteLine("往前开");
        }
        public int he(int a, int b) {
            Console.WriteLine(a+b);
            return b;
        }


    }
    class Program
    {
        static void Main(string[] args)
        {
            son a = new son();
            a.run();                //调用son类中的方法
            son b = new son();
            int o;
            o=b.he(1, 6);
        }
    }
}
