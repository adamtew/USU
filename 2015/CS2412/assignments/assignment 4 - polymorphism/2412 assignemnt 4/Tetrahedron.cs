using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    public class Tetrahedron : ThreeDimensionalShape
    {
        private double a;
        private double A
        {
            get
            {
                return a;
            }
            set
            {
                a = value;
            }
        }

        public Tetrahedron()
            : base()
        {
            A = 0;
        }
        public Tetrahedron(double rA)
            : base()
        {
            A = rA;
            setVolume(rA);
            setArea(rA);
        }

        public new void setVolume(double rA)
        {
            Volume = (Math.Pow(rA, 3) / 6 * Math.Sqrt(2));
        }
        public new void setArea(double rA)
        {
            Area = (Math.Sqrt(3) * Math.Pow(rA, 2));
        }
    }
}
