using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    public class Cube : ThreeDimensionalShape
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
        public Cube()
            : base()
        {
            Side = 0;
        }
        public Cube(double rSide)
            : base()
        {
            Side = rSide;
            setVolume(Side);
            setArea(Side);
        }
        public new void setVolume(double rSide)
        {
            Volume = Math.Pow(Side, 3);
        }
        public new void setArea(double rSide)
        {
            Area = Math.Pow(Side, 2);
        }
    }
}
