using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace taskExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Task task = Task.Run(() =>
            {
                for (int i = 0; i < 1000; i++)
                    Console.Write('Y');
            });

            task.Wait();

            for (int i = 0; i < 1000; i++)
                Console.Write('X');

            
        }
    }
}
