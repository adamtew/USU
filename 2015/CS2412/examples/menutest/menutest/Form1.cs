using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace menutest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private  void clearColor()
        {
            redToolStripMenuItem1.Checked = false;
            greenToolStripMenuItem.Checked = false;
            blueToolStripMenuItem1.Checked = false;
            blackToolStripMenuItem1.Checked = false;
        }


        private void redToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            clearColor();
            redToolStripMenuItem1.Checked = true;

            Field.ForeColor = Color.Red;
        }

        private void greenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            clearColor();
            greenToolStripMenuItem.Checked = true;

            Field.ForeColor = Color.Green;
        }

        private void blueToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            clearColor();
            blueToolStripMenuItem1.Checked = true;
            

            Field.ForeColor = Color.Blue;
        }

        private void blackToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            clearColor();
            blackToolStripMenuItem1.Checked = true; 
            Field.ForeColor = Color.Black;
        }

        private void boldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            boldToolStripMenuItem.Checked = !boldToolStripMenuItem.Checked;
            Field.Font = new Font(Field.Font, FontStyle.Bold ^ Field.Font.Style);
        }

        private void italicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            italicToolStripMenuItem.Checked = !italicToolStripMenuItem.Checked;
            Field.Font = new Font(Field.Font, FontStyle.Italic ^ Field.Font.Style);
        }

        private void clearFont()
        {
            timesNewRomanToolStripMenuItem.Checked = false;
            courToolStripMenuItem.Checked = false;
            sanToolStripMenuItem.Checked = false;
        }

        private void timesNewRomanToolStripMenuItem_Click(object sender, EventArgs e)
        {
            clearFont();

            timesNewRomanToolStripMenuItem.Checked = true;
            Field.Font = new Font("Times New Romans", 14, Field.Font.Style);
        }

        private void courToolStripMenuItem_Click(object sender, EventArgs e)
        {
            clearFont();

            courToolStripMenuItem.Checked = true;
            Field.Font = new Font("Courier", 14, Field.Font.Style);
        }

        private void sanToolStripMenuItem_Click(object sender, EventArgs e)
        {
            clearFont();

            sanToolStripMenuItem.Checked = true;
            Field.Font = new Font("Comic Sans", 14, Field.Font.Style);
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DateTime dropOffDate = dateTimePicker1.Value;
            if(dropOffDate.DayOfWeek == DayOfWeek.Friday ||
                dropOffDate.DayOfWeek == DayOfWeek.Saturday ||
                dropOffDate.DayOfWeek == DayOfWeek.Sunday)
            {
                deliveryText.Text = dropOffDate.AddDays(3).ToLongDateString();
            }
            else
            {
                deliveryText.Text = dropOffDate.AddDays(2).ToLongDateString();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dateTimePicker1.Value = DateTime.Now;
            dateTimePicker1.MaxDate = DateTime.Now.AddYears(1);
        }
    }
}
