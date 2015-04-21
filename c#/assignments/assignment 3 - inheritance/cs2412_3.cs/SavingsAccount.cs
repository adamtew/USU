using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs2412_3.cs
{
    class SavingsAccount : Account
    {
        private decimal interestRate;
        public decimal InterestRate
        {
            get
            {
                return interestRate;
            }
            set
            {
                try
                {
                    if (value >= 0)
                    {
                        interestRate = value;
                    }
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine("Caught exception: {0}", e);
                }
              
            }
        }

        public SavingsAccount(decimal initialBalance, decimal interestRate) :
            base(initialBalance)
        {
            try
            {
                if (interestRate >= 0.0M)
                InterestRate = interestRate;
            }
            catch (ArgumentException e)
            {
                Console.WriteLine("Caught exception: {0}", e);
            }
        }

        public decimal CalculateInterest()
        {
            return InterestRate * Balance;
        }
    }
}
