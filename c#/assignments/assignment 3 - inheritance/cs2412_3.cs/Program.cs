using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs2412_3.cs
{
    class Program
    {
        static void Main(string[] args)
        {
            /************************************************************
             *                      Account Testing
             ************************************************************/

                    // Checking normal functionality
            decimal initialBalance = 500;
            Account a = new Account(initialBalance);
            a.Credit(500);
            a.Debit(1000);
            Console.WriteLine("a's balance: {0}", a.Balance);

                    // Checking exceed debit
            Account A = new Account(100);
            A.Credit(50);
            Console.Write("A's withdrawl: ");
            A.Debit(151);

                    // Checking negative values
            Account aa = new Account(-10);           
            aa.Credit(50);
            aa.Debit(-51);
            Console.WriteLine("aa's balance: {0}", aa.Balance);

            /************************************************************
             *                  SavingsAccount Testing
             ************************************************************/ 

                    // Checking normal functionality
            decimal interestRate = 1;
            SavingsAccount b = new SavingsAccount(initialBalance, interestRate);
            b.Credit(400);
            b.Debit(250);
            b.CalculateInterest();
            Console.WriteLine("\nb's interest {0}", b.CalculateInterest());

                    // Checking normal inheritance
            SavingsAccount B = new SavingsAccount(100, 5);
            B.Credit(50);
            Console.Write("B's withdrawl: ");
            B.Debit(151);
            Console.WriteLine("B's interest: {0}", B.CalculateInterest());

                    // Checking negative values
            SavingsAccount bb = new SavingsAccount(-10, -5);
            bb.Credit(-50);
            bb.Debit(-70);
            Console.WriteLine("bb's balance: {0}", bb.Balance);

                    // Checking CalculateInterest with
            SavingsAccount BB = new SavingsAccount(500, 0.05m);
            decimal interest = BB.CalculateInterest();
            BB.Credit(interest);
            Console.WriteLine("BB's balance: {0}", BB.Balance);

            /************************************************************
             *                  CheckingAccount Testing
             ************************************************************/

                    // Checking normal functionality
            decimal fee = 50;
            CheckingAccount c = new CheckingAccount(initialBalance, fee);
            c.Credit(300);
            c.Debit(250);
            Console.WriteLine("\nc's balance: {0}", c.Balance);

                    // Checking normal inheritance
            CheckingAccount C = new CheckingAccount(500, 100);
            C.Credit(300);
            Console.Write("C's withdrawal: ");
            C.Debit(751);
            Console.WriteLine("C's balance: {0}", C.Balance);

                    // Checking negative values
            Account cc = new Account(-10);
            cc.Credit(-50);
            cc.Debit(-51);
            Console.WriteLine("cc's balance: {0}", cc.Balance);
        }
    }
}
