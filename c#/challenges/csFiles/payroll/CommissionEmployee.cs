// Fig. 12.7: CommissionEmployee.cs
// CommissionEmployee class that extends Employee.
using System;

namespace PayrollSystem
{

    public class CommissionEmployee : Employee
    {
        private decimal grossSales; // gross weekly sales
        private decimal commissionRate; // commission percentage

        // five-parameter constructor
        public CommissionEmployee(string first, string last, string ssn,
           decimal sales, decimal rate)
            : base(first, last, ssn)
        {
            GrossSales = sales; // validate gross sales via property
            CommissionRate = rate; // validate commission rate via property
        }

        // property that gets and sets commission employee's gross sales
        public decimal GrossSales
        {
            get
            {
                return grossSales;
            }
            set
            {
                if (value >= 0)
                    grossSales = value;
                else
                    throw new ArgumentOutOfRangeException(
                       "GrossSales", value, "GrossSales must be >= 0");
            }
        }

        // property that gets and sets commission employee's commission rate
        public decimal CommissionRate
        {
            get
            {
                return commissionRate;
            }
            set
            {
                if (value > 0 && value < 1)
                    commissionRate = value;
                else
                    throw new ArgumentOutOfRangeException("CommissionRate",
                       value, "CommissionRate must be > 0 and < 1");
            }
        }

        // calculate earnings; override abstract method Earnings in Employee
        public override decimal Earnings()
        {
            return CommissionRate * GrossSales;
        }

        // return string representation of CommissionEmployee object
        public override string ToString()
        {
            return string.Format("{0}: {1}\n{2}: {3:C}\n{4}: {5:F2}",
               "commission employee", base.ToString(),
               "gross sales", GrossSales, "commission rate", CommissionRate);
        }
    }
}