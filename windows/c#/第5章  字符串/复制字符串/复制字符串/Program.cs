using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 复制字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "来吧，come!";              //用copy方法复制
            string b = String.Copy(a);
            Console.WriteLine(b);
            char[] c = new char[100];               //用CopyTo方法复制
            a.CopyTo(1, c, 5,6);
            Console.WriteLine(c);
            Console.Read();
        }
    }
}
