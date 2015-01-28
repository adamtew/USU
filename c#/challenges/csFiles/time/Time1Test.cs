// Fig. 10.2: Time1Test.cs
// Time1 object used in an application.
using System;

public class Time1Test
{
   public static void Main( string[] args )
   {
      // create and initialize a Time1 object
      Time1 time = new Time1(); // invokes Time1 constructor


      // output string representations of the time
      Console.Write( "The initial universal time is: " );
      Console.WriteLine( time.ToUniversalString() );
      Console.Write( "The initial standard time is: " );
      Console.WriteLine( time.ToString() );
      Console.WriteLine(); // output a blank line

      // change time and output updated time 
      time.SetTime( 11, 27, 6 );
      Console.Write( "Universal time after SetTime is: " );
      Console.WriteLine( time.ToUniversalString() );
      Console.Write( "Standard time after SetTime is: " );
      Console.WriteLine( time.ToString() );
      Console.WriteLine(); // output a blank line

      // attempt to set time with invalid values
      //try
      //{
      //   time.SetTime( 99, 99, 99 );
      //} 
      //catch ( ArgumentOutOfRangeException ex )
      //{
      //   Console.WriteLine( ex.Message + "\n" );
      //} 

      // display time after attempt to set invalid values
      Console.WriteLine( "After attempting invalid settings:" );
      Console.Write( "Universal time: " );
      Console.WriteLine( time.ToUniversalString() );
      Console.Write( "Standard time: " );
      Console.WriteLine( time.ToString() );
   } 
} 