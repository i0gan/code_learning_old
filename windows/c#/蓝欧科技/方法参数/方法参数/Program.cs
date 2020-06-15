using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 方法参数
{
    public class Myclass            //定义一个公共类
    {
        public int My(int a,int b)              //定义一个公共方法，a和b叫做形式参数-形参
        {
            int temp = a;
            a = b;
            b = temp;
            return a;                 //给方法返回值
        }
        public void shuzu(int [] arr )    //创建一个参数为引用类型的参数方法
                                          //作用可以修改外界的值
        {
            arr[0] = 2001;
            
        }
        public void Ooo (ref int num,ref int num2)          //在值类型前面加上ref关键字可是它变为引用类型效果
        {
            int temp = num;
            num = num2;
            num2 = temp;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Myclass A = new Myclass();
            int i = 1;
            int i2 = 0;
            A.My(i,i2);
            Console.WriteLine(A.My(i,i2));            //调用方法，4和8叫做实既参数-实参
            int[] arr1 = new int[1] { 5 };
            A.shuzu(arr1);
            Console.WriteLine(arr1[0]);             //输出这时传入方法的值发生了改变
            int num3 = 6;
            int num4 = 8;
            A.Ooo(ref num3,ref num4);               //必须使用ref关键字加在前面
            Console.WriteLine("    "+"num3的值为{0},num4的值为{1}",num3,num4);            //输出，方法中的参数已影响了外界的参数


        }
    }
}
