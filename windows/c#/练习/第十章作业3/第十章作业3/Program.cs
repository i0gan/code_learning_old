using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 第十章作业3
{
    sealed class Player
    {
        string accrunt;
        string password;
        public string Accrunt
        {
            get
            {
                return accrunt;
            }
            set
            {
                accrunt = value;
            }
        }
        public string Password
             {
            get
            {
                return password;
            }
            set
            {
                password = value;
            }
           
        }
        public string Play()
        {
            string a = "账户:" + accrunt + "    "+"密码:" + password;
            return a;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Player P = new Player();
            P.Accrunt = "418894113";
            P.Password = "1314520";
            Console.WriteLine(P.Play());
        }
    }
}
