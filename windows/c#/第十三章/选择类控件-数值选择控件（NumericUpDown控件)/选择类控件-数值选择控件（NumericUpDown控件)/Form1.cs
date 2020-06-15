using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 选择类控件_数值选择控件_NumericUpDown控件_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            label1.Text = "当前值为：" + numericUpDown1.Value;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            numericUpDown1.Maximum = 60;
            numericUpDown1.DecimalPlaces = 5;
        }
    }
}
