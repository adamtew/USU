using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    public abstract class TwoDimensionalShape : Shape
    {
        protected TwoDimensionalShape() 
            : base()
        {

        }

        virtual public void setArea(double x)
        {

        }
        public double getArea()
        {
            return Area;
        }

    }

    
}
