using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 分组类控件_Panel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.Visible = false;     //隐藏panel控件
                                        //设置Richtext控件的Text属性
            richTextBox1.ReadOnly = true;
            richTextBox1.Text = "姓名:徐绿国\n性别：男\n年龄:16\n学历：高中";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox2.Text == "")
            {
                MessageBox.Show("请输入姓名");
                textBox2.Focus();
            }
            else
            {
                if (textBox2.Text.Trim() == "徐绿国")
                {
                    panel1.Show();
                   
                }
                else
                {
                    MessageBox.Show("查找无此人");
                    textBox2.Text = "";
                    panel1.Visible = false;
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult a = MessageBox.Show("你是否关闭窗体","",MessageBoxButtons.YesNo);
            if (DialogResult.Yes == a)
            {
                MessageBox.Show("你不能关闭窗体");
            }
        }
    }
}
