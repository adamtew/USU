using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KeyPress
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            KeyPress.Text =
                "Alt: " + (e.Alt) ? "Yes" : "No" + "\n" +
                "Ctrl: " + (e.Control) ? "Yes" : "No" + "\n" +
                "Shift: " + (e.Control) ? "Yes" : "No" + "\n" +
                "KeyCode: " + e.KeyCode + "\n" +
                "KeyDate: " + (e.KeyData) + "\n" +
                "Key";
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {

        }
    }
}
