using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 控制台输入输出
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "我是徐绿国";
            //Console表示控制台，Write表示写
            Console.WriteLine("str");
            Console.WriteLine("他是谁?{0},那又是谁{0},那他呢？{1}",str,"我是上帝!");       //{0}表示索引，是从零开始，可以重复使用
            Console.Write("你好！");       //使用Console.Write表示输出在一行
            Console.Write("嗯嗯！");
        }
    }
}
