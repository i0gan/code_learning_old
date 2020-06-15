using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 属性
{
    public class Person
    {
        string name = "wo";
        //属性格式：访问修饰符  属性类型  属性名 {set{....};get{....}}
        public  string Name         //创建一个属性
        {
            get                 //get叫做get访问器,他只能让外界  获取值
            {
                return name;
            }
            set                     //set叫做set访问器,它能让外界  修改值
            {
                name = value;                   //value只有在属性的set中才是关键字，在其他地方不是
            }
        }
                                    
    }
    class Program           //*****************属性中的访问器只能设置一个额外访问权限*************
    {
        static void Main(string[] args)
        {
            Person a = new Person();
            a.Name = ("我是徐绿国");                         //注意a的后面是属性名
            Console.WriteLine(a.Name);
        }
    }
}                            /////////////////////////属性可为只读属性和只写属性
                             ////////////////////////////只读属性只有get访问器，只写属性只有set访问器
