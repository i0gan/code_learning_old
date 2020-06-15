using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 构造方法和析构方法作业                                      //作业要求：1  创建一个老师类，特征：姓名，性别，授课内容，并使用构造方法初始化所有特征
{   public class Thicurh     //创建老师类                             // 2  创建一个学生类，特征：姓名，性别，授课教师，并使用构造方法初始化所有特征
    {
        public string name;
        public string xin;
        public string ke;
        public Thicurh()
        {
            name = "阮贤";
            xin = "男";
            ke = "数学";
        }
    }     
                         
    public class Sdiudent           //创建学生类
    {
        public string name;
        public int ID;
        public string thi;
        public Sdiudent()
        {
            name = "徐绿国";
            ID = 57;
            thi = "阮贤";
        }
    } 
                        
    class Program
    {
        static void Main(string[] args)
        {
            //创建一个老师对象
            Thicurh T = new Thicurh();
            Console.WriteLine("老师姓名：{0},",T.name);
            Console.WriteLine("老师性别：{0},", T.xin);
            Console.WriteLine("老师授课内容：{0},", T.ke);
            //创建一个学生对象
            Sdiudent S = new Sdiudent();
            Console.WriteLine("学生姓名：{0},", S.name);
            Console.WriteLine("学生学号：{0},", S.ID);
            Console.WriteLine("学生老师：{0},", S.thi);
            //作业完成****************************
        }
    }
}
