using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2412_assignment5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

            // Calculate the household energy footprint
        private void F1Calculate_Click(object sender, EventArgs e)
        {
                // getting values from the text boxes
            double electricalBill = Convert.ToDouble(Electricity.Text) * 1.37 * 12;
            double gasBill = Convert.ToDouble(Gas.Text) * 120.61 * 12;
            double oilBill = Convert.ToDouble(Oil.Text) * 22.37 * 12;
            double propaneBill = Convert.ToDouble(Propane.Text) * 12.17 * 12;

                // creating object for calculations
            Footprint HouseHoldEnergy = new HouseholdEnergy();

                    // calling the calculation
            F1TextBox.Text = HouseHoldEnergy.CalculateFootprint(electricalBill, gasBill, oilBill, propaneBill).ToString();
        }
            // Calculate the transportation footprint
        private void F2Calculate_Click(object sender, EventArgs e)
        {
                // creating object for calculations
            Footprint transportation = new Transportation();

                // getting values from the text boxes
            double milesDriven = Convert.ToDouble(Vehicle.Text);
            double mpg = Convert.ToDouble(MPG.Text);
            double airMiles = Convert.ToDouble(Air.Text);
            double weeks = 52;

                    // calling the calculation
            F2TextBox.Text = transportation.CalculateFootprint(milesDriven, weeks, airMiles, mpg).ToString();
        }
            // Calculate the diet and eating habits footprint
        private void F3Calculate_Click(object sender, EventArgs e)
        {
                // creating object for calculations
            Footprint diet = new Diet();

                // getting values from the text boxes
            double mfe = Convert.ToDouble(MeatFishEggs.Text);
            double cb = Convert.ToDouble(CerealsBakery.Text);
            double d = Convert.ToDouble(Dairy.Text);
            double fv = Convert.ToDouble(FruitsVegetables.Text);
            double eo = Convert.ToDouble(EatingOut.Text);
            double of = Convert.ToDouble(OtherFoods.Text);


                // variables to calculate the footprint
            double MFE = 1452;
            double CB = 741;
            double D = 1911;
            double FV = 1176;
            double EO = 368;
            double OF = 467;
            double cost = (mfe + cb + d + fv + eo + of);
            double GTPC = .0022;
            int months = 12;
            
            double emissions = (MFE + CB + D + FV + EO + OF);
            double total = (cost * emissions * months) * GTPC;

                    // calling the calculation
            F3TextBox.Text = diet.CalculateFootprint(cost, emissions, months, GTPC).ToString();

        }

            // Calculate the services and goods footprint
        private void F4Calculate_Click(object sender, EventArgs e)
        {

                    // creating object for calculations
            Footprint GoodServices = new ServiceGoods();

                    // getting values from the text boxes
            double clothing = Convert.ToDouble(Clothing.Text);
            double furnishings = Convert.ToDouble(Furnish.Text);
            double otherGoods = Convert.ToDouble(OtherGoods.Text);
            double services = Convert.ToDouble(Services.Text);
            double spent = (clothing + furnishings + otherGoods + services);


                    // variables to calculate the footprint
            double clothingE = 436;
            double furnishingsE = 459;
            double otherGoodsE = 338;
            double servicesE = 178;
            double emissions = (clothingE + furnishingsE + otherGoodsE + servicesE);

            double gtpc = .0022;

            int months = 12;

                    // calling the calculation
            F4TextBox.Text = GoodServices.CalculateFootprint(spent, emissions, months, gtpc).ToString();
        }

        private void label20_Click(object sender, EventArgs e)
        {
            




        }

        private void label22_Click(object sender, EventArgs e)
        {

        }

                // Getting the total of all the footprints
        private void Total_Click(object sender, EventArgs e)
        {
                // extracting data from the text boxes
            double f1 = Convert.ToDouble(F1TextBox.Text);
            double f2 = Convert.ToDouble(F2TextBox.Text);
            double f3 = Convert.ToDouble(F3TextBox.Text);
            double f4 = Convert.ToDouble(F4TextBox.Text);

                // performing the final calculation of the total
            TotalText.Text = (f1 + f2 + f3 + f4).ToString();
        }

       

       
    }
}
