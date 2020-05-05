using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 第十章作业2
{
    public abstract class Person
    {
        const float ip = 3.1415926f;
        public float jisuan(float R)
        {
            return R * R * ip;
        }
    }
    public class My:Person
    {

    }
    class Program
    {
        static void Main(string[] args)
        {
            My M = new My();
            Person P = M;
            Console.WriteLine("请输入半径");
            float r = float.Parse(Console.ReadLine());
            Console.WriteLine("圆的面积为：{0}",P.jisuan(r));
        }
    }
}
