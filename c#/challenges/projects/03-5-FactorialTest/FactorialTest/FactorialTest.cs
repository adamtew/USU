// Fig. 7.14: FactorialTest.cs
// Recursive Factorial method.
using System;

public class FactorialTest
{
   public static void Main( string[] args )
   {
      // calculate the factorials of 0 through 10
      for ( long counter = 0; counter <= 10; ++counter )
         Console.WriteLine( "{0}! = {1}",
            counter, Factorial( counter ) );
   } 

   // recursive declaration of method Factorial  
   public static long Factorial( long number )
   {
      // base case                               
      if ( number <= 1 )
         return 1;
      // recursion step                          
      else
         return number * Factorial( number - 1 );
   } 
} 
