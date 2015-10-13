using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LinkTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void CDrive_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            CDrive.LinkVisited = true;
            System.Diagnostics.Process.Start("C:\\");
        }

        private void Google_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Google.LinkVisited = true;
            System.Diagnostics.Process.Start("https://www.google.com");
        }

        private void Notepad_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Notepad.LinkVisited = true;
            System.Diagnostics.Process.Start("Notepad.exe");
        }
    }
}
