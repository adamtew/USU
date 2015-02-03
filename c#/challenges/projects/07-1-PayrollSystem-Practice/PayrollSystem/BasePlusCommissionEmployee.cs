// Fig. 12.8: BasePlusCommissionEmployee.cs
// BasePlusCommissionEmployee class that extends CommissionEmployee.
using System;

namespace PayrollSystem
{

    public class BasePlusCommissionEmployee : CommissionEmployee
    {
        private decimal baseSalary; // base salary per week

        // six-parameter constructor
        public BasePlusCommissionEmployee(string first, string last,
           string ssn, decimal sales, decimal rate, decimal salary)
            : base(first, last, ssn, sales, rate)
        {
            BaseSalary = salary; // validate base salary via property
        }

        // property that gets and sets 
        // base-salaried commission employee's base salary
        public decimal BaseSalary
        {
            get
            {
                return baseSalary;
            }
            set
            {
                if (value >= 0)
                    baseSalary = value;
                else
                    throw new ArgumentOutOfRangeException("BaseSalary",
                       value, "BaseSalary must be >= 0");
            }
        }

        // calculate earnings; override method Earnings in CommissionEmployee
        public override decimal Earnings()
        {
            return BaseSalary + base.Earnings();
        }

        // return string representation of BasePlusCommissionEmployee object
        public override string ToString()
        {
            return string.Format("base-salaried {0}; base salary: {1:C}",
               base.ToString(), BaseSalary);
        }
    }
}