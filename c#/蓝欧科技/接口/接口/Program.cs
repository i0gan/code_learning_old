using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口
{
    //定义一个接口
 public interface My
    {
        string name
        {
            set;
            get;
        }
    }
    public class My2 : My       //类My2实现接口My
    {
        string  a;
        public string name
        {
            set
           {
               a=value;
           }
            get
            {
                return a;
            }
        }
    }
        class Program
    {
        static void Main(string[] args)
        {
            My2 M = new My2();
            M.name = "我是徐绿国";
            Console.WriteLine(M.name);          //接口不能实例化
        }
    }
}
