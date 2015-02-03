// Fig. 4.8: GradeBookTest.cs
// Create and manipulate a GradeBook object.
using System;

public class GradeBookTest
{
   // Main method begins program execution
   public static void Main( string[] args )
   {
      // create a GradeBook object and assign it to myGradeBook
      GradeBook myGradeBook = new GradeBook();

      // display initial value of CourseName
      Console.WriteLine( "Initial course name is: '{0}'\n",
         myGradeBook.CourseName );

      // prompt for and read course name
      Console.Write( "Please enter the course name: " );
      myGradeBook.CourseName = Console.ReadLine(); // set CourseName
      Console.WriteLine(); // output a blank line

      // display welcome message after specifying course name
      myGradeBook.DisplayMessage();
   } 
} 