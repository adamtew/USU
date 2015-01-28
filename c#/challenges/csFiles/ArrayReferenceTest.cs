using System;

public class ArrayReferenceTest
{
    public static void Main(string[] args)
    {
        int[] firstArray = { 1, 2, 3 };
        int[] firstArrayCopy = firstArray;

        Console.WriteLine("Test passing firstArray reference by value");
        Console.Write("\nContents of firstArray " + "before calling FirstDouble:\n\t");

        for (int i = 0; i < firstArray.Length; ++i)
            Console.Write("{0} ", firstArray[i]);

        SecondDouble(ref firstArray);

        Console.Write("\n\nContents of firstArray after calling FirstDouble\n\t");
        for (int i = 0; i < firstArray.Length; ++i)
            Console.Write("{0} ", firstArray[i]);
        if (firstArray == firstArrayCopy)
            Console.WriteLine("\n\nThe references refer to the same array");
        else
            Console.WriteLine("\n\nThe references refer to different arrays");

        int[] secondArray = { 1, 2, 3 };
        int[] secondArrayCopy = secondArray;

        Console.WriteLine("\nTest passing secondArray " + "reference by reference");
        Console.Write("\nContents of secondArray " + "before calling SecondDouble:\n\t");
        for (int i = 0; i < secondArray.Length; ++i)
            Console.Write("{0} ", secondArray[i]);

        // Call SecondDouble method with secondArray as argument
        


        Console.Write("\n\nContents of secondArray " + "after calling SecondDouble:\n\t");
        for (int i = 0; i < secondArray.Length; ++i)
            Console.Write("{0} ", secondArray[i]);
        if (secondArray == secondArrayCopy)
            Console.WriteLine("\n\nThe references refer to the same array");
        else
            Console.WriteLine("\n\nThe references refer to different arrays");
    }

    // modify elements of array and attempt to modify reference
    public static void SecondDouble(ref int[] array)
    {
        for (int i = 0; i < array.Length; ++i)
            array[i] *= 2;

        array = new int[] { 11, 12, 13 };
    } 
    
    // Todo: Define a new method called SecondDouble that
    // 1. modify elements of array and change reference array
    // 2. refer to a new array                            
    
}