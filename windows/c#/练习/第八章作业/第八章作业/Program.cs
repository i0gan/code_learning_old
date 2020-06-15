using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 第八章作业
{
    public class Week
    {
        int day;
        public int  Day
        {
            get
            {
                return day;
            }
            set
            {
                if (value>7)
                {
                    Console.WriteLine("输入有误");
                }
                else
                {
                    if (value < 0)
                    {
                        Console.WriteLine("输入有误");
                    }
                    else
                    {
                        day = value;
                    }
                }
            }

        }
    }
    public class Myclass
    {
        public string  My()
        {
            string str1 = "方法示例";
            return str1;
        }
        public string My2()
        {
            Program P = new Program();
            string str =P.My2()+this.My() ;
            return str;
        }

    }
    class Program
    {   
        public string My2 ()
            {
            string str2 = "这是一个";
            return str2;
        }

        
        static void Main(string[] args)
        {
            Console.WriteLine("请输入是一周之内的数字1");
            int num = Convert.ToInt16(Console.ReadLine());
            Week W = new Week();
            W.Day = num;
            Myclass M = new Myclass();
            Console.WriteLine( M.My2());
            //作也未完成**********************徐绿国     
        }
    }
}
