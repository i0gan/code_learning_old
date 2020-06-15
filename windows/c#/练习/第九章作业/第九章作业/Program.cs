using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 第九章作业
{
   public  struct Mystruct
    {
        float r;
        public float My
        {
            set
            {
                r = value;
            }
        }
        public float My2()
        {
            float num=3.1416f;
            float num2 = r * r * num;
            return num2;
        }

    }
    public class Juxing
    {
       private float chang()
        {
            float num = 0;
            return num;
        }
        private float kuan()
        {
            float num2 = 0;
            return num2;
        }
        public virtual float Xu()
        {
            float
        }
    }
    public class Juxing2:Juxing
    {

    }
    class Program
    {
        static void Main(string[] args)
        {
            Mystruct M = new Mystruct();
            Console.WriteLine("请输入半径");
            float num3 = float.Parse(Console.ReadLine());
            M.My = num3;
            Console.WriteLine("圆的面积为{0}",M.My2());
        }
    }
}
