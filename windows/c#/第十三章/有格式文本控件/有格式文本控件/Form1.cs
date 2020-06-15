using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 有格式文本控件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richTextBox1.Multiline = true;
            richTextBox1.ScrollBars = RichTextBoxScrollBars.Vertical;
            richTextBox1.ReadOnly = false;
            richTextBox1.Text = Time();

            
        }
        private string Time()
        {
            DateTime time = DateTime.Now;
            string str = String.Format("{0:F}", time);
            return str;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult a = MessageBox.Show("你是否要关闭窗体？", "提示", MessageBoxButtons.YesNo);
            if (a == DialogResult.Yes)
            {
                e.Cancel = false;
            }
            else
            {
                e.Cancel = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            f2.MdiParent = this;
        }
    }
}
