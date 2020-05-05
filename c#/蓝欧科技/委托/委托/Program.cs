using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 委托
{
    public class Wo
    {
        
       private string hi;
        //定义一个委托格式： 访问修饰符 delegate 返回值类型 委托名 （参数列表);
        public delegate void OO(string hi );
        public Wo(string hi)
        {   
            this.hi = hi;
        }
        //可以像普通方法一样传递
        public void Do(OO oo)
        {   //可以像普通方法一样调用
            oo(hi );
        }
    }
    public class Ni
    {
        public void chi()
        {
            Wo W = new Wo("老徐");
            OO O = new OO(); 
        }
        public void jiao()
        {
            Console.WriteLine("赶紧过来!");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
           
        }
    }
}
