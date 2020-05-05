using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法
{
    public class Name                                               //创建一个公共类
    {
    private    string Str = "徐绿国";                  //定义内部string类型变量
        public string GetName()                         //使用Get方法把str修饰符改为公共
        {
            return Str;             //Get方法有返回值
        }
        //使用Set方法，没有返回值，使它重新赋值
        public void Set(string NewName)          //参数类型要和所需修改的类型相同,这里为string类型，后面是参数名，可随便取，
        {
         string   Str=NewName;           ///////使Name重新赋值
        }





    }
    class Program
    {
        static void Main(string[] args)
        {
            Name wo = new Name();
            //wo.str = "";
            //  Console.WriteLine(wo.GetName());   */            // 输出,注意结构！！！！！！！！！！！！
            wo.Set("我是徐绿国");                    //给字符串重新赋值
            Console.WriteLine(wo.GetName());
            Console.ReadLine();
        }
    }
}
