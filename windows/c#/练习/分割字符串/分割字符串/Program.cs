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
            string str = "你好/徐绿国，我来自/贵州/紫云";
            string[] str2 = str.Split(new char[] {'/'},5);
            for (int i = 0; i <str2.Length; i++)
            {
                Console.WriteLine(str2[i]);
            }
            
        }
    }
}
