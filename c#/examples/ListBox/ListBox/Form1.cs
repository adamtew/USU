using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ListBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            listbox.Items.Add(itemBox.Text);
            itemBox.Clear();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(listbox.SelectedIndex != -1)
            {
                listbox.Items.Remove(listbox.SelectedIndex);
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkedListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkedListBox_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            if(e.NewValue == CheckState.Checked)
            listBox1.Items.Add(checkedListBox.SelectedIndex);
            else
                listBox1.Items.Remove(checkedListBox.SelectedIndex);
        }

        private void shapeCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            Graphics graphics = CreateGraphics();
            Pen pen = new Pen(Color.Black);
            SolidBrush brush = new SolidBrush(Color.Black);

            graphics.Clear(Color.White);

            switch(shapeCombo.SelectedIndex)
            {
                case 0:
                    graphics.DrawEllipse(pen, 50, 50, 150, 150);
                    break;
                case 1:
                    graphics.DrawRectangle(pen, 50, 50, 150, 150);
                    break;
                    case 2:
                    graphics.DrawEllipse(pen, 50, 50, 150, 150);
                    break;
                    case 3:
                    graphics.DrawEllipse(pen, 50, 50, 150, 150);
                    break;
            }
        }
    }
}
