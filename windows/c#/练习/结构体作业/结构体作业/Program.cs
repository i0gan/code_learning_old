using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 结构体作业                     /*作业要求：1 创建一个英雄结构体变量，成员包括英雄姓名、HP、MP等，2定义一个vector3，包括x，y，z三个float类型公共成员变量，
                                          然后结构体声明三个变量,从小到大输出它们*/
{
    struct Yingxiong
    {
      public  string name;
      public  float HP;
      public  float MP;
    }
    public struct vector3
    {
      public  float x;
      public  float y;
      public  float z;
    }
    class Program
    {
        static void Main(string[] args)
        {
            Yingxiong P = new Yingxiong();
            P.name = "徐绿国";
            P.HP = 9999999f;
            P.MP = 9999999f;
            Console.WriteLine("英雄姓名：{0}",P.name);
            Console.WriteLine("英雄HP值：{0}",P.HP);
            Console.WriteLine("英雄MP值：{0}",P.MP);
            
             //作业未完成
          
                        
           
            

    }
    }
}
