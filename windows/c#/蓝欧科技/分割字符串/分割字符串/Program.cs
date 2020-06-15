using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 分割字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "你/好！老/王";
            string[] str2 = str.Split(new char[] { '/'}, 3);                    //使用Split来实现分割字符，注意要使用字符串数组
            for (int i = 0; i < str2.Length; i++)
            {
                Console.WriteLine(str2[i]);
            }
            Console.ReadLine();
        }
    }
}
