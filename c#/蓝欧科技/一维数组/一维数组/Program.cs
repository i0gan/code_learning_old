using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 一维数组
{
    class Program
    {
        static void Main(string[] args)
        {
            //定义一个一维数组
            //数组中元素的默认值为零
            int[] a = new int[4];
            a[0] = 6;               //给数组中的第一个值赋值
            Console.WriteLine(a[0]);
            //直接给数组中的元素确定元素值
            int[] b = new int[3] { 4, 6, 9 };
            Console.WriteLine(b[2]);                //注意，这其中的2表示索引，它表示第三个元素
            //使用new关键字赋值叫做动态赋值
            //声明一个静态赋值的数组
            string [] c = { "你好", "你是", "老王" };
            Console.WriteLine(c[2]+c[1]);           //数组元素拼接
                                                    //使用循环来遍历数组元素                                       //数组名不能参与运算  
                                                    //窍门，写下for之后按下TAB可以帮助你写代码，然后写好之后打上控制循环的变量名可以统一修改
                                                    //变量名修改之后再按下TAB可以修改K的范围
            for (int k = 0; k < 3; k++)             //3表示数组元素的个数             
            {                                               
                Console.WriteLine(c[k]);            //输出c数组中的每个元素
            }                                       //使用b.Length可以获取b数组中的长度/元素个数
            for (int i = 0; i < b.Length; i++)
            {
                Console.Write(b[i]+"  ");
            }
        }
    }
}
