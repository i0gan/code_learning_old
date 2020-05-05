using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public int a;
        public int b;
        public int c;
        public bool oo1 = false;
        public bool oo2 = false;
        public bool oo3 = false;
        public bool oo4 = false;
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
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("你是否关闭此程序，关闭后会面临病毒的威胁。", "病毒侵入提示！", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                e.Cancel = false;
            }
            else
            {
                e.Cancel = true;
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            a = int.Parse(richTextBox1.Text);
            richTextBox1.Text = "";
            textBox1.Text = "+";
            oo1 = true;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            a = int.Parse(richTextBox1.Text);
            richTextBox1.Text = "";
            textBox1.Text = "-";
            oo2 = true;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            a = int.Parse(richTextBox1.Text);
            richTextBox1.Text = "";
            textBox1.Text = "*";
            oo3 = true;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            a = int.Parse(richTextBox1.Text);
            richTextBox1.Text = "";
            textBox1.Text = "/";
            oo4 = true;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            if (oo1 == true)
            {
                b = int.Parse(richTextBox1.Text);
                c = a + b;
                richTextBox1.Text =Convert.ToString(c);
                textBox1.Text = "+";
                oo1 = false;
            }
            if (oo2 == true)
            {
                b = int.Parse(richTextBox1.Text);
                c = a - b;
                richTextBox1.Text = Convert.ToString(c);
                oo2 = false;
            }
            if (oo3 == true)
            {
                b = int.Parse(richTextBox1.Text);
                c = a * b;
                richTextBox1.Text = Convert.ToString(c);
                oo3 = false;
            }
            if (oo4 == true)
            {
                b = int.Parse(richTextBox1.Text);
                c = a / b;
                richTextBox1.Text = Convert.ToString(c);
                oo4 = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "1";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "2";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "3";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "4";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "5";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "6";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "7";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "8";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "9";
        }

        private void button15_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = richTextBox1.Text + "0";
        }

        private void button16_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
        }

        private void button17_Click(object sender, EventArgs e)
        {
            DateTime T = DateTime.Now;
            string str = string.Format("{0:F}", T);
            label1.Text = str;
            int Week = (int)DateTime.Now.DayOfWeek;
            switch (Week)
            {
                case (int)week.Sun: label3.Text = "星期天"; break;
                case (int)week.Mon: label3.Text = "星期一"; break;
                case (int)week.Tur: label3.Text = "星期二"; break;
                case (int)week.Wed: label3.Text = "星期三"; break;
                case (int)week.Thi: label3.Text = "星期四"; break;
                case (int)week.Fir: label3.Text = "星期五"; break;
                case (int)week.Sat: label3.Text = "星期六"; break;
            }
        }

       
    }
}
