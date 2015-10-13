using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    public class Sphere : ThreeDimensionalShape
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

        public Sphere()
            : base()
        {
            R = 0;
        }
        public Sphere(double rRadius)
            : base()
        {
            R = rRadius;
            setArea(rRadius);
            setVolume(rRadius);
        }

        public new void setArea(double rRadius)
        {
            Area = (4 * Math.PI * (rRadius * rRadius));
        }

        public new void setVolume(double rRadius)
        {
            Volume = 5; //(3 / 4 * (Math.PI * (rRadius * rRadius * rRadius)));
        }
    }
}
