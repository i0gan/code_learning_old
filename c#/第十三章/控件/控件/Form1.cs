
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 控件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox2.ReadOnly = true;
            textBox2.Text = "徐绿国\n床前明月光，疑是地上霜。举头望明月，低头思故乡。";
            textBox2.SelectionStart = 0;
            textBox2.SelectionLength = 4;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
           
        }
    }
}
