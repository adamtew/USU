// Fig. 12.5: SalariedEmployee.cs
// SalariedEmployee class that extends Employee.
using System;

namespace PayrollSystem
{

    public class SalariedEmployee : Employee
    {
        private decimal weeklySalary;

        // four-parameter constructor
        public SalariedEmployee(string first, string last, string ssn,
           decimal salary)
            : base(first, last, ssn)
        {
            WeeklySalary = salary; // validate salary via property
        }

        // property that gets and sets salaried employee's salary
        public decimal WeeklySalary
        {
            get
            {
                return weeklySalary;
            }
            set
            {
                if (value >= 0) // validation
                    weeklySalary = value;
                else
                    throw new ArgumentOutOfRangeException("WeeklySalary",
                       value, "WeeklySalary must be >= 0");
            }
        }

        // calculate earnings; override abstract method Earnings in Employee
        public override decimal Earnings()
        {
            return WeeklySalary;
        }

        // return string representation of SalariedEmployee object
        public override string ToString()
        {
            return string.Format("salaried employee: {0}\n{1}: {2:C}",
               base.ToString(), "weekly salary", WeeklySalary);
        }
    }
}