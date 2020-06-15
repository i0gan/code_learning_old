using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串作业
{                                                               //作业要求：将字符串中的每个单词分别输出在控制台上"LanOuKeJi/JinWuXing/Qinghe/Haidian/Beijing2016"
    class Program
    {
        static void Main(string[] args)
        {
            string str = "LanOuKeJi/JinWuXIng/Qinghe/Beijing2016";
            string[] str2 = str.Split(new char[] { '/' }, 4);
            for (int i = 0; i <str2.Length; i++)
            {
                Console.Write(str2[i]+"    ");
            }
            //作业完成       徐绿国
        }
    }
}
