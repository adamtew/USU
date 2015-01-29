// Fig. 12.4: Employee.cs
// Employee abstract base class.

namespace PayrollSystem
{
    public abstract class Employee
    {
        // read-only property that gets employee's first name
        public string FirstName { get; private set; }

        // read-only property that gets employee's last name
        public string LastName { get; private set; }

        // read-only property that gets employee's social security number
        public string SocialSecurityNumber { get; private set; }

        // three-parameter constructor
        public Employee(string first, string last, string ssn)
        {
            FirstName = first;
            LastName = last;
            SocialSecurityNumber = ssn;
        }

        // return string representation of Employee object, using properties
        public override string ToString()
        {
            return string.Format("{0} {1}\nsocial security number: {2}",
               FirstName, LastName, SocialSecurityNumber);
        }

        // abstract method overridden by derived classes
        public abstract decimal Earnings(); // no implementation here
    }
}