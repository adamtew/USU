using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BreakContinueTest
{
    class Program
    {
        static void Main(string[] args)
        {
            int count; // control variable also used after loop terminates

            for (count = 1; count <= 10; ++count) // loop 10 times
            {
                if (count == 5) // if count is 5, 
                    break; // terminate loop

                Console.Write("{0} ", count);
            } // end for

            Console.WriteLine("\nBroke out of loop at count = {0}", count);

            for (count = 1; count <= 10; ++count) // loop 10 times
            {
                if (count == 5) // if count is 5, 
                    continue; // skip remaining code in loop

                Console.Write("{0} ", count);
            } // end for

            Console.WriteLine("\nUsed continue to skip displaying 5");
        }
    }
}
