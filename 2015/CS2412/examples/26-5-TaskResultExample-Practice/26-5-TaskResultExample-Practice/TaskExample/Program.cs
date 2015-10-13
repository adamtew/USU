using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TaskExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // TODO: run a Task<long> instanse, which calculates 40th Fibonacci number



            // TODO: print out the result of the task using Result property


        }

        // recursive method Fibonacci; calculates nth Fibonacci number
        static long Fibonacci(long n)
        {
            if (n == 0 || n == 1)
                return n;
            else
                return Fibonacci(n - 1) + Fibonacci(n - 2);
        } 
    }
}
