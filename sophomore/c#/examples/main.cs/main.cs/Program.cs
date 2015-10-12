using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace main.cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Triangle triangle = new Triangle();
            for (int i = 1; i < 500; i++)
                for (int j = 1; j < 500; j++)
                    for (int k = 1; k < 500; k++)
                    {
                        if (triangle.pythagorean(i, j, k))
                        {
                            Console.WriteLine("Triple: ({0}^2) + ({1}^2) = ({2}^2)", i, j, k);
                        }
                    }
        }
    }

    class Triangle
    {
        private int a, b, c;

        public Triangle()
        {
            a = 0;
            b = 0;
            c = 0;
        }

        public bool pythagorean(int rA, int rB, int rC)
        {
            if(Math.Pow(rA, 2) + Math.Pow(rB, 2) == Math.Pow(rC, 2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
