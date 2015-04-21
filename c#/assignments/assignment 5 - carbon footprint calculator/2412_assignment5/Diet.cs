using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


        // A class to calculate the diet footprint
namespace _2412_assignment5
{
    class Diet : Footprint
    {
        double Footprint.CalculateFootprint(double spent, double emissions, double months, double gtpc)
        {
            return ((spent * emissions * months) / gtpc);
        }
    }
}
