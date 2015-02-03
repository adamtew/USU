using System;
using System.Windows.Forms;

namespace Form
{
	public partial class MyForm : Form
	{
		public MyForm()
		{
			InitializeComponent();
			{
				
			}	
		}

		private void myButton_Click(object sender, EvntArgs e)
		{
			MessageBox.Show("Test");
		}
		
	}
}