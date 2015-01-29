// Fig. 12.9: PayrollSystemTest.cs
// Employee hierarchy test application.
using System;

namespace PayrollSystem
{
    public class PayrollSystemTest
    {
        public static void Main(string[] args)
        {
            // create four-element IPayable array
            IPayable[] payableObjects = new IPayable[4];

            // populate array with objects that implement IPayable
            payableObjects[0] = new Invoice("01234", "seat", 2, 375.00M);
            payableObjects[1] = new Invoice("56789", "tire", 4, 79.95M);
            payableObjects[2] = new SalariedEmployee("John", "Smith",
               "111-11-1111", 800.00M);
            payableObjects[3] = new SalariedEmployee("Lisa", "Barnes",
               "888-88-8888", 1200.00M);

            Console.WriteLine(
               "Invoices and Employees processed polymorphically:\n");

            // generically process each element in array payableObjects
            foreach (var currentPayable in payableObjects)
            {
                // output currentPayable and its appropriate payment amount
                Console.WriteLine("{0}\npayment due: {1:C}\n",
                   currentPayable, currentPayable.GetPaymentAmount());
            }
        }
    }
}