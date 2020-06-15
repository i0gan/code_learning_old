using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace foreach语句
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList a = new ArrayList();              //实例化ArrayList类
            a.Add("失败是成功之母");                       //使用Add方法向对象中添加数据
            a.Add("没有努力就没有收获");
            a.Add("想梦想进发");
            foreach(string b in a)                          //使用foreach语句
            {
                Console.WriteLine(b);                       //输出
            }
            Console.Read();
        }
    }
}
