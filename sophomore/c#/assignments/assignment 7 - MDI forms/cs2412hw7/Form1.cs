using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cs2412hw7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            loginForm f = new loginForm();
            f.MdiParent = this;

            f.Show();
            this.Hide();
            //billCalculator b = new billCalculator();
            //b.Show();
            this.Hide();
        }
    }
}
