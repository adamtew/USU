// Fig. 14.28: RadioButtonTestForm.cs
// Using RadioButtons to set message window options.
using System;
using System.Windows.Forms;

namespace RadioButtonTest
{
    // Form contains several RadioButtons--user chooses one
    // from each group to create a custom MessageBox
    public partial class RadioButtonTestForm : Form
    {
        // create variables that store the user's choice of options
        private MessageBoxButtons buttonType;

        // default constructor
        public RadioButtonTestForm()
        {
            InitializeComponent();
        }

        // change Buttons based on option chosen by sender
        private void buttonType_CheckedChanged(
           object sender, EventArgs e)
        {
            if (sender == okRadioButton) // display OK Button
                buttonType = MessageBoxButtons.OK;

            // display OK and Cancel Buttons
            else
                buttonType = MessageBoxButtons.OKCancel;
        }

    }
}