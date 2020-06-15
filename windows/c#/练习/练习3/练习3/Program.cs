using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习3
{
    public class Person
    {
        private string str1 = "我是？";
        //使用Get方法
        public string Get()             //使用Get方法，使str1修饰变为公共的
        {
            return str1;
        }
        public void Set (string str0)               //使用Set方法，使str1重新赋值
        {
            str1 = str0;
        }

        class Program
        {
            static void Main(string[] args)
            {
                Person A = new Person();
                A.str1="我叫";                       //也可使用A.Set("我叫");
                Console.WriteLine(A.str1);          //也可使用Console.WriteLine(A.Get());
                Console.ReadLine();


            }
        }
    }
}
