using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2412_Base_Form
{
    public partial class baseForm : Form
    {
        public baseForm()
        {
            InitializeComponent();
        }

        private void buttonLearn_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Bugs, bugs, bugs...", "Learn More", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }
    }
}
