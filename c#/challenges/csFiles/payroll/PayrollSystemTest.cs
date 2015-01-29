// Fig. 12.9: PayrollSystemTest.cs
// Employee hierarchy test application.
using System;

namespace PayrollSystem
{

    public class PayrollSystemTest
    {
        public static void Main(string[] args)
        {
            // create derived class objects
            SalariedEmployee salariedEmployee =
               new SalariedEmployee("John", "Smith", "111-11-1111", 800.00M);
            HourlyEmployee hourlyEmployee =
               new HourlyEmployee("Karen", "Price",
               "222-22-2222", 16.75M, 40.0M);
            CommissionEmployee commissionEmployee =
               new CommissionEmployee("Sue", "Jones",
               "333-33-3333", 10000.00M, .06M);
            BasePlusCommissionEmployee basePlusCommissionEmployee =
               new BasePlusCommissionEmployee("Bob", "Lewis",
               "444-44-4444", 5000.00M, .04M, 300.00M);

            Console.WriteLine("Employees processed individually:\n");

            Console.WriteLine("{0}\nearned: {1:C}\n",
               salariedEmployee, salariedEmployee.Earnings());
            Console.WriteLine("{0}\nearned: {1:C}\n",
               hourlyEmployee, hourlyEmployee.Earnings());
            Console.WriteLine("{0}\nearned: {1:C}\n",
               commissionEmployee, commissionEmployee.Earnings());
            Console.WriteLine("{0}\nearned: {1:C}\n",
               basePlusCommissionEmployee,
               basePlusCommissionEmployee.Earnings());
        }
    }
}