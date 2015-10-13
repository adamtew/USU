using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



        // A class to calculate the transportation footprint
namespace _2412_assignment5
{
    class Transportation : Footprint
    {
        double Footprint.CalculateFootprint(double miles, double weeks, double airMiles, double mpg=1)
        {
            double Vehicle = ((miles * weeks) / mpg) * 19.4 * (100 / 95);
            double AirTravel = airMiles * (223 * 1.2 * 1.9) * .0022;
            double total = Vehicle + AirTravel;
            return total;
        }
    }
}
