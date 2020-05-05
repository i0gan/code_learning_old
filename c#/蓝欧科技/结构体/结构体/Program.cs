using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 结构体
{
    struct Person           //定义一个结构体，结构体中的成员不能进行赋值
    {
        public string Name;         //定义一个公共名称      
        public int Age;                 //定义一个公共年龄

    }
    struct Person2
    {
        public float x;
        public float y;
        public float z;
    }
    class Program
    {
        static void Main(string[] args)
        { 
            Person p;           //定义一个结构体变量
            p.Name = "徐绿国";                 //使用结构体中的成员赋一个字符串
            p.Age = 16;
            Console.WriteLine("姓名：{0}年龄{1}", p.Name,p.Age);
            Person2 r;
            r.x = 2.321f;
            r.y = 3.4f;
            r.z = 2.6f;
            Console.WriteLine("坐标为：({0},{1},{2}）",r.x,r.y,r.z);
            Console.Read();

        }
    }
}
