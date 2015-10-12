using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2412assignment_9
{
    public partial class Form1 : Form
    {
        bool paint = false;
        Color myColor;
        ColorsLibrary.SortedColors colors = new ColorsLibrary.SortedColors();
        SortedDictionary<string, Color> myColors;
        int mySize;
        public Form1()
        {
            InitializeComponent();
             myColors = colors.getColors();
        }

        private void paintPanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void paintPanel_MouseDown_1(object sender, MouseEventArgs e)
        {
            paint = true;
            var checkedColor =
                colorPanel.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);

            myColor = myColors[checkedColor.Name];

            var checkedSize =
                sizePanel.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);
            
            mySize =  Int32.Parse(checkedSize.Text);
        }

        private void paintPanel_MouseMove_1(object sender, MouseEventArgs e)
        {
            
            if (paint)
            {
                using (Graphics graphics = paintPanel.CreateGraphics())
                {
                    graphics.FillEllipse(new SolidBrush(myColor), e.X, e.Y, (int)mySize, (int)mySize);
                }
            }
        }

        private void paintPanel_MouseUp_1(object sender, MouseEventArgs e)
        {
            paint = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            paintPanel.BackColor = Color.Black;
            paintPanel.ForeColor = Color.Black;
            paintPanel.BackColor = Color.White;
            paintPanel.ForeColor = Color.White;
        }
    }
}
