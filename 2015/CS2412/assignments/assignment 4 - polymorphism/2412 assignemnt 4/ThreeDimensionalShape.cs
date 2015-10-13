using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
     public abstract class ThreeDimensionalShape : Shape
    {

        public ThreeDimensionalShape()
            : base()
        {

        }
        public double getVolume()
        {
            return Volume;
        }
        virtual public void setVolume(double side)
        {

        }
        public double getArea()
        {
            return Area;
        }
        public virtual void setArea(double side)
        {

        }
    }
}
