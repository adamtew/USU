using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2412_3_19
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void flower1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //ChildForm child = new ChildForm("item", "item");
        }

        private void radioRed_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.BackColor = Color.Black;
            tabLabel.ForeColor = Color.Red;
        }

        private void radioGreen_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.BackColor = Color.Black;
            tabLabel.ForeColor = Color.Green;
        }

        private void radioBlue_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.BackColor = Color.Black;
            tabLabel.ForeColor = Color.Blue;
        }

        private void radioYellow_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.BackColor = Color.Black;
            tabLabel.ForeColor = Color.Yellow;
        }

        private void radio10_CheckedChanged(object sender, EventArgs e)
        {
            //tabLabel.Font.size = 10;
           tabLabel.Font =  new Font(tabLabel.Font.Name, 10);
        }

        private void radio20_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Font = new Font(tabLabel.Font.Name, 20);
        }

        private void radio30_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Font = new Font(tabLabel.Font.Name, 30);
        }

        private void radio40_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Font = new Font(tabLabel.Font.Name, 40);
        }

        private void radioHello_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Text = radioHello.Text;
        }

        private void radioWelcome_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Text = radioWelcome.Text;
        }

        private void radioHow_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Text = radioHow.Text;
        }

        private void radioGoodbye_CheckedChanged(object sender, EventArgs e)
        {
            tabLabel.Text = radioGoodbye.Text;
        }
    }
}
