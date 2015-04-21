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
    public partial class loginForm : Form
    {
        private string login;
        public string Login  { get { return login; } }
        private string password;
        public string Password { get { return password; } }

        public loginForm()
        {
            login = "user";
            password = "1234";
            InitializeComponent();
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            if (loginTextBox.Text != Login)
                MessageBox.Show("Incorrect username. \nTry again.");
            else if(passwordTextBox.Text != Password)
                MessageBox.Show("Incorrect password. \nTry again." + Password + " " + passwordTextBox.Text);

            if(passwordTextBox.Text == Password && loginTextBox.Text == Login)
            {
                billCalculator b = new billCalculator();
                b.MdiParent = this.MdiParent;
                b.Show();
                this.Hide();
                MessageBox.Show("Success!");
            }
        }
    }
}
