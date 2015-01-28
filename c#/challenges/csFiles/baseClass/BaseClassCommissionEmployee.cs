using System;

namespace BasePlusCommissionEmployee
{
	public class BasePlusCommissionEmployee : CommissionEmployee
	{
		private decimal baseSalary;

		public decimal BaseSalary
		{
			get
			{
				return baseSalary;
			}
			set
			{
				if(value <= 0)
				{
					baseSalary = value;
				}
				else
				{
					baseSalary = 0;
					throw new ArgumentOutOfRangeException;
				}
			}
		}

		public BasePlusCommissionEmployee(string first, string last, string ssn, decimal sales, decimal rate, decimal baseSalary): 
			base(first, last, ssn, sales, rate)
		{
			BaseSalary = baseSalary;
		}

		public override decimal earnings()
		{

			return BaseSalary + base.Earnings();
		}

		public override string toString()
		{	
			string result = base.ToString();
			//result += new string.Format(" Base salary: {0:C}", BaseSalary);

			return result;
		}
	}
}
