using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 删除字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "嗨，你好！";
            string b = a.Remove(1, 2);
            Console.WriteLine(b);
            Console.Read();    
        }
    }
}
