using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs2412_3.cs
{
    class CheckingAccount : Account
    {
        private decimal transactionFee;
        public decimal TransactionFee
        {
            get
            {
                return transactionFee;
            }
            set
            {
                if (value >= 0)
                    transactionFee = value;
                else
                    throw new ArgumentOutOfRangeException();
            }
        }

        public CheckingAccount(decimal initialBalance, decimal fee):
            base(initialBalance)
        {
            if (fee >= 0)
                transactionFee = fee;
            else
                throw new ArgumentOutOfRangeException();
        }

        public override bool Credit(decimal amount)
        {
            if (base.Credit(amount))
            {
                ChargeFee();
                return true;
            }
            return false;
        }

        public override bool Debit(decimal amount)
        {
            if (base.Debit(amount))
            {
                ChargeFee();
                return true;
            }
            return false;
        }

        private void ChargeFee()
        {
            Balance -= transactionFee;
        }
    }
}
