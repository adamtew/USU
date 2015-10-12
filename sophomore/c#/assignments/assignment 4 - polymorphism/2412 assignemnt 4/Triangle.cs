using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    class Triangle : TwoDimensionalShape
    {
        private double b;
        private double B 
        {
            get
            {
                return b;
            }
            set
            {
                b = value;
            }
        }

        private double h;
        private double H
        {
            get
            {
                return h;
            }
            set
            {
                h = value;
            }
        }

        public Triangle()
            : base()
        {
            B = 0;
            H = 0;
        }

        public Triangle(double rB, double rH)
            : base()
        {
            B = rB;
            H = rH;
            setArea(B, H);
        }

        public new void setArea(double x, double y)
        {
            Area = .5 * (x * y);
        }
        public double getArea()
        {
            return Area;
        }
    }
}
