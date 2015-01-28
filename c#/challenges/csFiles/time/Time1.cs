// Fig. 10.1: Time1.cs
// Time1 class declaration maintains the time in 24-hour format.
using System; // namespace containing ArgumentOutOfRangeException

public class Time1
{
   private int hour; // 0 - 23
   private int minute; // 0 - 59
   private int second; // 0 - 59

   public int Hour
   {
      get
      {
         return hour;
      }
      set
      {
         if(value >= 0 && value < 13)
         {
            hour = value;
         }
         else
         {
            throw new ArgumentOutOfRangeException();
         }
      }
   }

   public int Minute
   {
      get
      {
         return minute;
      }
      set
      {
         if(value >= 0 && value < 60)
         {
            minute = value;
         }
         else
         {
            throw new ArgumentOutOfRangeException();
         }
      }
   }

   public int Second
   {
      get
      {
         return second;
      }
      set
      {
         if(value >= 0 && value < 60)
         {
            second = value;   
         }
         else
         {
            throw new ArgumentOutOfRangeException();  
         }
      }
   }

   public Time1(int rHour = 0, int rMinute = 0, int rSecond = 0)
   {
      Hour = rHour;
      Minute = rMinute;
      Second = rSecond;
   }

   public void Time2(int rH, int rM, int rS)
   {
      SetTime(rH, rM, rS);
   }

   // set a new time value using universal time; throw an 
   // exception if the hour, minute or second is invalid
   public void SetTime( int hour, int minute, int second )
   {
      Hour = hour;
      Minute = minute;
      Second = second;
      
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