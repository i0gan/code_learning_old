using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 选项卡控件_TabControl
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            tabPage1.ImageIndex = 0;
            tabPage1.Text = "选项卡1";
            tabPage2.ImageIndex = 1;
            tabPage2.Text = "选项卡2";
            Button but = new Button();
            but.Text = "老王";
            tabPage1.Controls.Add(but);
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Title = "选项卡" + (tabControl1.TabCount + 1).ToString(); //声明字符串类型变量用于生成新增选项卡名称
            TabPage page = new TabPage();
            tabControl1.TabPages.Add(page);
            page.Text = Title;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 0)            //判断是否选择了选项卡
            {
                MessageBox.Show("请选择选项卡");
            }
            else
            {
                tabControl1.TabPages.Remove(tabControl1.SelectedTab);
            }
        }
    }
}
