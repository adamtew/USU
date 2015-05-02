using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Paint
{
    public partial class Form1 : Form
    {
        bool paint = false;
        private enum BrushSize
        {
            SMALL = 5,
            MEDIUM = 10,
            LARGE = 15
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            paint = true;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {


            if(paint)
            {
                Color color = Color.Red;
                BrushSize size = BrushSize.LARGE;
                if(Blue.Checked)
                {
                    color = Color.Blue;
                }
                else if (Red.Checked)
                {
                    color = Color.Red;
                }

                if(small.Checked)
                {
                    size = BrushSize.SMALL;
                }
                else if(medium.Checked)
                {
                    size = BrushSize.MEDIUM;
                }
                using (Graphics graphics = panel1.CreateGraphics())
                {
                    graphics.FillEllipse(new SolidBrush(color), e.X, e.Y, (int)size, (int)size);
                }
            }
                
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            paint = false;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
