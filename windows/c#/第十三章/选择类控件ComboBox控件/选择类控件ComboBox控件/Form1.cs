using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 选择类控件ComboBox控件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //只能查看不能编辑
            comboBox1.DropDownStyle = ComboBoxStyle.DropDown;
            //向里面增加数据
            comboBox1.Items.Add("徐绿国");
            comboBox1.Items.Add("老王！");
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //使用SelectAll方法，当再次拉下列表时，可以再次选中文本框中的内容
            comboBox1.SelectAll();
         
        }

        private void comboBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            string str = "你选中了" + comboBox1.Text;
            label1.Text = str;
        }
    }
}
