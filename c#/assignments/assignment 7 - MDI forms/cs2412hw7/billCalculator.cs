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
    public partial class billCalculator : Form
    {
        public billCalculator()
        {
            InitializeComponent();
        }

        private void addBevButton_Click(object sender, EventArgs e)
        {
            addPrice(Convert.ToDouble(bevPrice.Text),Convert.ToInt16(bevNum.Value));
        }

        private void addAppButton_Click(object sender, EventArgs e)
        {
            addPrice(Convert.ToDouble(appPrice.Text), Convert.ToInt16(appNum.Value));
        }

        private void addMaiButton_Click(object sender, EventArgs e)
        {
            addPrice(Convert.ToDouble(maiPrice.Text), Convert.ToInt16(maiNum.Value));
        }

        private void addDesButton_Click(object sender, EventArgs e)
        {
            addPrice(Convert.ToDouble(desPrice.Text), Convert.ToInt16(desNum.Value));
        }

        private void addPrice(double cost, int quantity)
        {
            subText.Text = (Math.Round(( Convert.ToDouble(subText.Text) + cost * quantity), 2)).ToString();
            taxText.Text = (Math.Round((Convert.ToDouble(subText.Text) * .07), 2)).ToString();
            totalText.Text = (Math.Round((Convert.ToDouble(subText.Text) + Convert.ToDouble(taxText.Text)), 2)).ToString();
        }


        private void clearButton_Click(object sender, EventArgs e)
        {
            bevCombo.Text = "Beverages";
            appCombo.Text = "Appetizers";
            maiCombo.Text = "Main Course";
            desCombo.Text = "Desserts";
            bevPrice.Text = "0.00";
            appPrice.Text = "0.00";
            maiPrice.Text = "0.00";
            desPrice.Text = "0.00";
            bevNum.Value = 1;
            appNum.Value = 1;
            maiNum.Value = 1;
            desNum.Value = 1;
            subText.Text = "0.00";
            taxText.Text = "0.00";
            totalText.Text = "0.00";
        }

        private void bevCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch(bevCombo.SelectedIndex)
            {
                case 0: bevPrice.Text = "1.95"; break;
                case 1: bevPrice.Text = "1.50"; break;
                case 2: bevPrice.Text = "1.25"; break;
                case 3: bevPrice.Text = "2.95"; break;
                case 4: bevPrice.Text = "2.50"; break;
                case 5: bevPrice.Text = "1.50"; break;
                default:
                    break;
            }
        }

        private void appCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (appCombo.SelectedIndex)
            {
                case 0: appPrice.Text = "8.95"; break;
                case 1: appPrice.Text = "10.95"; break;
                case 2: appPrice.Text = "12.95"; break;
                case 3: appPrice.Text = "6.95"; break;
                default:
                    break;
            }
        }

        private void maiCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (maiCombo.SelectedIndex)
            {
                case 0: maiPrice.Text = "15.95"; break;
                case 1: maiPrice.Text = "13.95"; break;
                case 2: maiPrice.Text = "13.95"; break;
                case 3: maiPrice.Text = "11.95"; break;
                case 4: maiPrice.Text = "19.95"; break;
                case 5: maiPrice.Text = "20.95"; break;
                case 6: maiPrice.Text = "18.95"; break;
                case 8: maiPrice.Text = "13.95"; break;
                case 9: maiPrice.Text = "14.95"; break;
                default:
                    break;
            }
        }

        private void desCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (desCombo.SelectedIndex)
            {
                case 0: desPrice.Text = "5.95"; break;
                case 1: desPrice.Text = "3.95"; break;
                case 2: desPrice.Text = "5.95"; break;
                case 3: desPrice.Text = "4.95"; break;
                case 4: desPrice.Text = "5.95"; break;
                default:
                    break;
            }
        }
    }
}
