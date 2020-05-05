namespace MDI窗体
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.加载窗体ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.水平排序ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.垂直排序ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.叠层排序ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.加载窗体ToolStripMenuItem,
            this.水平排序ToolStripMenuItem,
            this.垂直排序ToolStripMenuItem,
            this.叠层排序ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(382, 25);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 加载窗体ToolStripMenuItem
            // 
            this.加载窗体ToolStripMenuItem.Name = "加载窗体ToolStripMenuItem";
            this.加载窗体ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.加载窗体ToolStripMenuItem.Text = "加载窗体";
            this.加载窗体ToolStripMenuItem.Click += new System.EventHandler(this.加载窗体ToolStripMenuItem_Click);
            // 
            // 水平排序ToolStripMenuItem
            // 
            this.水平排序ToolStripMenuItem.Name = "水平排序ToolStripMenuItem";
            this.水平排序ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.水平排序ToolStripMenuItem.Text = "水平排序";
            this.水平排序ToolStripMenuItem.Click += new System.EventHandler(this.水平排序ToolStripMenuItem_Click);
            // 
            // 垂直排序ToolStripMenuItem
            // 
            this.垂直排序ToolStripMenuItem.Name = "垂直排序ToolStripMenuItem";
            this.垂直排序ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.垂直排序ToolStripMenuItem.Text = "垂直排序";
            this.垂直排序ToolStripMenuItem.Click += new System.EventHandler(this.垂直排序ToolStripMenuItem_Click);
            // 
            // 叠层排序ToolStripMenuItem
            // 
            this.叠层排序ToolStripMenuItem.Name = "叠层排序ToolStripMenuItem";
            this.叠层排序ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.叠层排序ToolStripMenuItem.Text = "叠层排序";
            this.叠层排序ToolStripMenuItem.Click += new System.EventHandler(this.叠层排序ToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(382, 219);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 加载窗体ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 水平排序ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 垂直排序ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 叠层排序ToolStripMenuItem;
    }
}

