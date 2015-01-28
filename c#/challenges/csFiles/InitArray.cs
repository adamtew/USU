// Fig. 8.19: InitArray.cs
// Initializing rectangular and jagged arrays.
using System;

public class InitArray
{
    public static void Main(string[] args)
    {
        // with rectangular arrays,
        // every row must be the same length.
        int[,] rectangular = { { 1, 2, 3 }, { 4, 5, 6 } };

        // with jagged arrays,
        // we need to use "new int[]" for every row,
        // but every row does not need to be the same length.
        int[][] jagged = { new int[] { 1, 2 }, 
                         new int[] { 3 }, 
                         new int[] { 4, 5, 6 } };

        OutputArray(rectangular);
        Console.WriteLine();
        OutputArray(jagged);
    }

    // output rows and columns of a rectangular array
    public static void OutputArray(int[,] array)
    {
        Console.WriteLine("Values in the rectangular array by row are");
        for(int i = 0; i < array.GetLength(0); i++)
        {
            for(int j = 0; j < array.GetLength(1); j++)
            {
                Console.WriteLine("First Dimension {0}, Second Dimension {1}", i, j);
            }

        }
		// Write two nested for statement to print all the elements in the array
		// Use array.GetLength(0) to get the number of rows
		// Use array.GetLength(1) to get the number of columns
    }

    // output rows and columns of a jagged array
    public static void OutputArray(int[][] array)
    {
        Console.WriteLine("Values in the jagged array by row are");
        for(int i = 0; i < array.GetLength(0); i++)
        {
            Console.WriteLine("Row: {0}", i);
        }
        Console.WriteLine("For loop");
        
        // Write two nested for statement to print all the elements in the array
		// Use array.GetLength(0) to get the number of rows
		// Use array.GetLength(1) to get the size of each row
        

        Console.WriteLine("foreach loop");
        // Write two nested foreach statement to print all the elements in the array
        foreach(int[] row in array)
        {
            foreach(int e in row)
            {
                Console.WriteLine("Element: " + e);
            }

        }
    }
}