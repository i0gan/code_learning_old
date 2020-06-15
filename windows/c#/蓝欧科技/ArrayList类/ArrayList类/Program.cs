using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;           //引入命名空间

namespace ArrayList类
{
    class Program
    {
        static void Main(string[] args)
        {
            //使用非泛型集合需要引入命名空间 System.Collections
            //Arrayl本身就是一个类 ，再使用时就要创建一个对象
            ArrayList List = new ArrayList();
            //使用Add（）方法添加元素
            List.Add(33);
            List.Add(3.322);
            List.Add("老王");
            //对元素类型没要求
            //获取元素跟一维数组一样
            Console.WriteLine(List[0]);
            //使用Count来获取元素的长度
            Console.WriteLine(List.Count );
            //使用Insert方法插入元素
            List.Insert(3, "wo");
            for (int i = 0; i <List.Count; i++)
            {
                Console.Write(List[i]+"   ");
            }
            //使用Remove方法删除指定元素
           
            List.Remove("wo");           //属于元素方法删除
            List.RemoveAt(2);               //使用下标方法删除 
            for (int j = 0; j < List.Count; j++)
            {
                Console.WriteLine(List[j]);
            }
            //使用Contains方法判断元素是否存在ArrayList中的
            Console.WriteLine(List.Contains("3"));
        }
    }
}
