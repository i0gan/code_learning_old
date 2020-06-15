using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            //声明char类型的字符变量
            char a = 'a';
            a = 'b';
            Console.WriteLine(a);
            //声明一个char类型的数组
            char[] b = new char[6];
            b[0] = 'N';
            b[1] = 'S';                         //char类型的数组本质跟string的字符串一样
            string c = "你是哪个？";
            Console.WriteLine(c[2]);            //输出
            string str = "abcdefg";
            bool oo = str.Contains("cde");          //使用Contains方法判断cde是否在str字符串中，其返回值为布尔类型
            Console.WriteLine(oo);
            int num = str.IndexOf('f');            //使用IndexOf来判断f在哪个下标位置，其返回值为值类型
            Console.WriteLine(num);
            num = str.IndexOf("oooo");             //如果所要搜寻的字符没有在里面或不符合逻辑，则输出为-1
            Console.WriteLine(num);
            num = str.IndexOf("def");
            Console.WriteLine(num);                //如果所要搜寻的字符连接在一起的，则搜索到的索引将会是第一个字符串的下标位置
            string str2 = str.Remove(2, 5);         //使用Remove来删除str中指定位置的字符串，其返回值为字符串类型
            Console.WriteLine(str2);
            string str3 = str.Replace('a', 'c');
            Console.WriteLine(str3);

        }
    }
}
