using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 第十章作业1
{
   public interface Ijisaun
    {
        float Chang
        {
            get;
            set;
        }
        float Kuan
        {
            get;
            set;
        }
        float Jisuan();
    }  
    public class My:Ijisaun
    {
       private  float chang;
       private  float kuan;
       public  float Chang
        {
            get
            {
                return chang;
            }
            set
            {
                chang = value;
            }
        }
        public  float Kuan
        {
            get
            {
                return kuan;
            }
            set
            {
                kuan = value;
            }
        }
       public  float Jisuan()
        {
            return chang * kuan;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            My M = new My();
            M.Chang = 3.64f;
            M.Kuan = 6.666f;
            Console.WriteLine("面积为：{0}",M.Jisuan());
           
        }
    }
}
