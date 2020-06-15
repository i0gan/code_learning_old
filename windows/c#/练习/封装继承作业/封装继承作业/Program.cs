using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 封装继承作业                //作业要求：创建一个人类，至少添加三个特征和三个行为。再分别创建老师类、学生类、校长类，继承人类并添加自己独特的特征和行为。
{
    public class Person
    {
        public string name;
        public string xin;
        public int age;
        public string yuqi;
        public string food;
        public string HomeAddress;
    }
    public class thichur : Person
    {
        public string LovePerson = "街上小妞";
    }
    public class student:Person
    {
        public string GoodAt = "打架";
    }
    public class xiao:Person 
    {
        public string love = "好色";
    }
    class Program
    {
        static void Main(string[] args)
        {
            thichur T = new thichur();
            T.age = 28;
            T.name = "讨乱咸";
            T.xin = "男";
            T.yuqi = "太猖狂";
            T.food = "臭豆腐";
            T.HomeAddress = "小板当";
            
            //作业完成**************
        }
    }
}
