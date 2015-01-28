using System;

namespace Exceptions
{
	class Program
	{
		static void Main(string[] args)
		{
			int x = 0;

			try
			{
				x = Convert.ToInt32(Console.ReadLine());
			}
			catch (Exception e)
			{
				Console.WriteLine("Exception catched: Message: {0}", e.Message);
			}
		}
	}
}