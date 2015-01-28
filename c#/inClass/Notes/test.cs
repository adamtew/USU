using System;

namespace ArrayTest
{
	class Program
	{
		static void Main(string[] args)
		{
			int firstArrayLength = 5;
			int[] firstArray = new int[firstArrayLength];

			for(int i = 0; i < firstArray.Length; i++)
			{
				Console.Write("Element {0}: ", i);
				firstArray[i] = Convert.ToInt32(Console.ReadLine());
			}

			Console.WriteLine();
			for(int i = 0; i < firstArray.Length; i++)
			{
				Console.WriteLine("Element {0}: {1}", i, firstArray[i]);
			}

			Console.WriteLine();
			foreach(int e in firstArray)
			{
				Console.WriteLine("Element {0}", e);
			}
		}
	}
}