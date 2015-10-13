using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    class Circle : TwoDimensionalShape
    {
        private double r;
        private double R
        {
            get
            {
                return r;
            }
            set
            {
                r = value;
            }
        }
        public Circle()
            : base()
        {
            r = 0;
        }
        public Circle(double radius)
            : base()
        {
            setArea(radius);
        }

        public new void setArea(double x)
        {
            Area = (Math.PI * (x * x));
        }
    }
}
