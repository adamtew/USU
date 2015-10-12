using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Threading;

namespace TaskExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // TODO: run a task, which calculate the 40th Fibonacci number

            for(int i = 0; i < 5; i++)
                Console.WriteLine(Fibonacci(i));

            Task fibTask = Task.Run(() => {
                Console.WriteLine("Fib 20: {0}", Fibonacci(20));
            });

            fibTask.Wait();
            

            Task task = Task.Run(() =>
            {
                for (int i = 0; i < 20; i++)
                    Console.WriteLine("Fib {0} = {1}", i, Fibonacci(i));
            });

            Console.WriteLine("Task completed? " + task.IsCompleted);
            task.Wait();
            
            Console.WriteLine("Task completed? " + task.IsCompleted);

            Task<long> task2 = Task.Run(() => { return Fibonacci(5); });

            long result = task2.Result;
            Console.WriteLine(result);
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
