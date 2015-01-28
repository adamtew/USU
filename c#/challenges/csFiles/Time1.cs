// Fig. 10.1: Time1.cs
// Time1 class declaration maintains the time in 24-hour format.
using System; // namespace containing ArgumentOutOfRangeException

public class Time1
{
   private int hour; // 0 - 23
   private int minute; // 0 - 59
   private int second; // 0 - 59

   Time1()
   {
      hour = 0;
      minute = 1;
      second = 2;
   }

   // set a new time value using universal time; throw an 
   // exception if the hour, minute or second is invalid
   public void SetTime( int hour, int minute, int second )
   {
      // validate hour, minute and second
      if ( ( hour >= 0 && hour < 24 ) && ( minute >= 0 && minute < 60 ) && 
         ( second >= 0 && second < 60 ) ) 
      {
         this.hour = hour;
         this.minute = minute;
         this.second = second;
      } 
      else
         throw new ArgumentOutOfRangeException();
   } 

   // convert to string in universal-time format (HH:MM:SS)
   public string ToUniversalString()
   {
      return string.Format( "{0:D2}:{1:D2}:{2:D2}",
         hour, minute, second );
   } 

   // convert to string in standard-time format (H:MM:SS AM or PM)
   public override string ToString()
   {
      return string.Format( "{0}:{1:D2}:{2:D2} {3}",
         ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ),
         minute, second, ( hour < 12 ? "AM" : "PM" ) );
   } 
} 