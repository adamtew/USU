using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    public abstract class Shape 
    {
        protected double volume;
        protected double Volume 
        { 
            get
            {
                return volume;
            }
            set
            {
                volume = value;
            }
        }
        protected double area;
        protected double Area { get; set; }
        protected Shape()
        {

        }      

    }
}
