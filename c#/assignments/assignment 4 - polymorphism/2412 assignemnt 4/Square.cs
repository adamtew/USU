using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    class Square : TwoDimensionalShape
    {
        private double side;
        private double Side
        {
            get
            {
                return side;
            }
            set
            {
                side = value;
            }
        }
        
        public Square(int side)
            : base()
        {
            setArea(side);
        }
        public Square()
            : base()
        {
            side = 0;
        }


        public new void setArea(double x)
        {
            Area = x * x;
        }
    }
}
