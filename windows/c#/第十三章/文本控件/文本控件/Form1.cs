using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 文本控件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            textBox1.ReadOnly= true;
            textBox1.Text = "徐绿国";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            MessageBox.Show("登录成功！");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.AcceptButton = button1;
            this.CancelButton = button2;
            textBox2.PasswordChar = '*';
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("发送信息祝你一生倒霉自QQ418894113");
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
