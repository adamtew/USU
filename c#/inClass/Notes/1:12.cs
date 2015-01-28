// Local vs. Instance variables example
using System;
using System.Collections.Generic;
using System.Ling;
using System.Text;
using System.Threading.Tasks;

namespace GradeBook
{
	public class Course
	{
		// Class attribute
		private string courseName;

		// Should be the same type and the same name but with a capital first letter
		// Also, they should be public
		public string CourseName;
		{
			get
			{
				return courseName;
			}
			set
			{
				courseName = value;
			}
		}

		// Another way you can do the above is:
		// public string CourseName { get; set;}
	}
}