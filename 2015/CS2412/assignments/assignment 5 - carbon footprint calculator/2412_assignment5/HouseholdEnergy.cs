using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



            /// A class to calculate the household energy footprint
namespace _2412_assignment5
{
    class HouseholdEnergy : Footprint
    {
        double Footprint.CalculateFootprint(double e, double g, double o, double p)
        {
            return (e + g + o + p);
        }
    }
}
