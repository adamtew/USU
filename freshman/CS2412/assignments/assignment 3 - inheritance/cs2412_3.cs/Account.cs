using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs2412_3.cs
{
    class Account
    {
        private decimal balance;
        public decimal Balance
        {
            get
            {
                return balance;
            }
            set
            {
                try
                {
                    if (value >= 0.0M)
                        balance = value;
                    else
                        Console.WriteLine("Debit amount exceeded account balance.");
                }
                catch (ArgumentOutOfRangeException e)
                {
                    Console.WriteLine("Caught exception {0}", e);
                }
            }
        }

        public Account(decimal initialBalance)
        {
            try
            {
                if (initialBalance >= 0.0M)
                    balance = initialBalance;
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.WriteLine("Caught exception {0}", e);
            }

        }

        public virtual bool Credit(decimal amount)
        {
            if (amount >= 0)
            {
                balance += amount;
                return true;
            }
            return false;
            
        }

        public virtual bool Debit(decimal amount)
        {
            if (amount >= 0)
            {
                if (balance - amount >= 0)
                {
                    balance -= amount;
                    return true;
                }  
                else
                    Console.WriteLine("Debit amount exceeded account balance.");
            }
            return false;
            
        }

    }
}
