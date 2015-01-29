using System;

namespace PayrollSystem
{
	class HourlyEmployee : Employee
	{
		public HourlyEmployee(string first, string last, string ssn) : base(first, last, ssn)
		{
			
		}

		public override string ToString()
		{
			return "absa";
		}
	}
}