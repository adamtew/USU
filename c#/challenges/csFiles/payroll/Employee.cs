using System;

namespace PayrollSystem
{
	public abstract class Empolyee : IPayable
	{
		public string Firstname { get; private set;}
		public string Lastname { get; private set;}
		public string SSN { get; private set;}

		public Employee(string firstname, string lastname, string ssn)
		{
			Firstname = firstname;
			Lastname = lastname;
			SSN = ssn;
		}

		public abstract decimal Earnings();

		public override string ToString()
		{
			return string.Format("First name: {0}, Last name: {1}, SSN: {2}", 
				Firstname, Lastname, SSN);
		}
	}
}