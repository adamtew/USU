using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lambdaTest
{
    class Program
    {
        delegate int Transfer(int x);
        static void Main(string[] args)
        {
            Transfer sqr = new Transfer(Square);

            Console.WriteLine("Square: " + sqr);
            Console.WriteLine("square: {0}", sqr(10));

            Transfer sqr2 = x => x * x;

            Console.WriteLine("Square: " + sqr2);
            Console.WriteLine("Square: {0}", sqr2(10));

            Transfer sqr3 = x => x + x;

            Console.WriteLine("Square: {0}", sqr3(10));
        }

        static int Square(int x)
        {
            return x * x;
        }
    }
}
