using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 显示当前日期程序
{
    class Program
    {
        enum week
        {
            Sun=0,
            Mon=1,
            Tur=2,
            Wed=3,
            Thi=4,
            Fir=5,
            Sat=6,
        }
                    
        static void Main(string[] args)
        {
            
            int b = (int)DateTime.Now.DayOfWeek;            //获取系统当前日期
            Console.WriteLine("今天是：");                  
            DateTime time = DateTime.Now;
            string c = String.Format("{0:F}", time);            //格式化日期格式
            Console.WriteLine("{0}\t",c);
            
            switch (b)
            {
                case (int)week.Sun: Console.WriteLine("星期天"); break;        //输出日期
                case (int)week.Mon: Console.WriteLine("星期一"); break;
                case (int)week.Tur: Console.WriteLine("星期二"); break;
                case (int)week.Wed: Console.WriteLine("星期三"); break;
                case (int)week.Thi: Console.WriteLine("星期四"); break;
                case (int)week.Fir: Console.WriteLine("星期五"); break;
                case (int)week.Sat: Console.WriteLine("星期六"); break;
            }
            Console.WriteLine("LYXF小程序,QQ:418894113");
            Console.Read();

        }
    }
}
