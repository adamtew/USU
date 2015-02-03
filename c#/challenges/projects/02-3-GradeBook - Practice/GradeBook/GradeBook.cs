// Fig. 6.9: GradeBook.cs
// GradeBook class uses switch statement to count letter grades.
using System;

public class GradeBook
{
   private int total; // sum of grades
   private int gradeCounter; // number of grades entered
   private int aCount; // count of A grades (90 - 100)
   private int bCount; // count of B grades (80 - 89)
   private int cCount; // count of C grades (70 - 79)
   private int dCount; // count of D grades (60 - 69)
   private int fCount; // count of F grades (< 60)

   // automatic property CourseName
   public string CourseName { get; set; }

   // constructor initializes automatic property CourseName; 
   // int instance variables are initialized to 0 by default
   public GradeBook( string name )
   {
      CourseName = name; // set CourseName to name
   } 

   // display a welcome message to the GradeBook user
   public void DisplayMessage()
   {
      // CourseName gets the name of the course
      Console.WriteLine( "Welcome to the grade book for\n{0}!\n",
         CourseName );
   } 

   // input arbitrary number of grades from user
   public void InputGrades()
   {
      int grade; // grade entered by user
      string input; // text entered by the user

      Console.WriteLine( "{0}\n{1}",
         "Enter the integer grades in the range 0-100.",
         "Type <Ctrl> z and press Enter to terminate input:" );

      // Write a loop to 
      // 1. read all of the grades and
      // 2. calculate total of all grades and the number of grades entered
      // 3. call IncrementLetterGradeCounter method to increment appropriate counter
      // The loop should stops when user enters the end-of-file indicator (<Ctrl> z)
     
   } 

   // add 1 to appropriate counter for specified grade
   private void IncrementLetterGradeCounter( int grade )
   {
      // Write a switch case statement to determine which grade was entered 
      // and increment the appropriate counter
      
   } 

   // display a report based on the grades entered by the user 
   public void DisplayGradeReport()
   {
      Console.WriteLine( "\nGrade Report:" );

      // if user entered at least one grade...
      if ( gradeCounter != 0 )
      {
         // calculate average of all grades entered
         double average = ( double ) total / gradeCounter;

         // output summary of results
         Console.WriteLine( "Total of the {0} grades entered is {1}",
            gradeCounter, total );
         Console.WriteLine( "Class average is {0:F}", average );
         Console.WriteLine( "{0}A: {1}\nB: {2}\nC: {3}\nD: {4}\nF: {5}",
            "Number of students who received each grade:\n",
            aCount, 
            bCount,
            cCount,
            dCount,
            fCount ); 
      } 
      else 
         Console.WriteLine( "No grades were entered" );
   } 
} 
