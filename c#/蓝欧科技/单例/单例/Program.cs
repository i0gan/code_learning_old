using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 单例        //单例：保证程序运行期间，一个类最懂同时存在唯一的一个对象，可以更方便的访问对象
{   
    //定义一个玩家属性类
    //把类改为单例：1 把类改为私有化构造方法  -  作用：不让外界随意的创建对象
    //2 在类的内部提供一个静态实例
    //3提供获取实例的接口
    //在玩游戏中时玩家不能随便创建角色，一个玩家只能控制一个角色，所以使用单例来完成
    public class Player
    {
      public  string Nmae;
      public  int  level;
      public  int HP;
      public  int MaxHp;
      

       
            //在类的内部创建一个静态实例
        private static Player _instance;
        //提供获取实例接口
        public static Player GetInstance()
        {
            if (null == _instance)
            {
                _instance = new Player();
            }
            return _instance;
        }
        private Player()//创建私有构造方法
        { }
        ~Player()
        {
            Console.WriteLine("程序结束");
        }
    }
    public class Bag
    {
        public void hp(Player P)
        {
            P.HP+= 10;
            P.HP = P.HP > P.MaxHp ? P.HP = P.MaxHp : P.HP = P.HP;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Player P = Player.GetInstance();            //不能用new来创建实例
            P.Nmae = "徐绿国";
            P.level = 1;
            P.HP = 40;
            P.MaxHp = 80;
            Bag H = new Bag();
            Player P2 = Player.GetInstance();           //创建一个另一个对象
            H.hp(P);
            Console.WriteLine(P.HP);
            Console.WriteLine(P2.Nmae);
        }
    }
}
                                        //类中的书写格式
                                        //1 字段
                                        //2 属性
                                        //3 方法
                                        //把公共的放上层，私有的放下层