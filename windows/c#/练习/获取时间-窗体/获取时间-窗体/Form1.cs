using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 获取时间_窗体
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public string time(){ 
            DateTime Time = DateTime.Now;
            string str = string.Format("{0:F}", Time);
            return str;
        }   
        DateTime Time = DateTime.Now;
        private void Form1_Load(object sender, EventArgs e)
        {
            MessageBox.Show("时间获取中", "",MessageBoxButtons.OK);
        }



        private void textBox1_TextChanged(object sender, EventArgs e)
        {
                textBox1.ReadOnly = true;
                string str2 = time();
                textBox1.Text = str2;
        }

        private void textBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult oo = MessageBox.Show("系统核心程序损坏\n你已破坏此计算机系统的核心系统！", "", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
    }
}
