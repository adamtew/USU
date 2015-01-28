// Fig. 7.10: MethodOverload.cs
// Overloaded method declarations.
using System;

public class MethodOverload
{
    // test overloaded square methods
    public static void Main(string[] args)
    {
        Console.WriteLine("Square of integer 7 is {0}", Square(7));
        Console.WriteLine("Square of double 7.5 is {0}", Square(7.5));
    }

    // square method with int argument
    public static int Square(int intValue)
    {
        Console.WriteLine("Called square with int argument: {0}",
           intValue);
        return intValue * intValue;
    }

    // square method with double argument
    public static double Square(double doubleValue)
    {
        Console.WriteLine("Called square with double argument: {0}",
           doubleValue);
        return doubleValue * doubleValue;
    }
}