// Fig. 9.7: LINQWithListCollection.cs
// LINQ to Objects using a List< string >.
using System;
using System.Linq;
using System.Collections.Generic;

public class LINQWithListCollection
{
   public static void Main( string[] args )
   {
      // populate a List of strings 
      List< string > items = new List< string >();

      // add "aQua" to the end of the List
      items.Add("aQua");

      // add "RusT" to the end of the List
      items.Add("RusT");

      // add "yElLow" to the end of the List
      items.Add("yElLow");

      // add "rEd" to the end of the List
      items.Add("rEd");


      // convert all strings to uppercase; select those starting with "R"
      var startWithR =
          from item in items
          let itemUpper = item.ToUpper()
          where itemUpper.StartsWith("R")
          orderby itemUpper
          select itemUpper;
          





      // display query results
      Console.WriteLine("Query results:");
      foreach (var r in startWithR)
          Console.WriteLine("{0}", r);




      Console.WriteLine(); // output end of line

      items.Add("rUbY");
      items.Add("ReGisTEr");
      items.Add("somTHIng");



      // display updated query results
      Console.WriteLine("\nQuery results after adding new items:");
      foreach (var r in startWithR)
          Console.WriteLine("{0}", r);



      Console.WriteLine(); // output end of line

      Console.WriteLine("\nThe original list:");
      foreach (var r in items)
          Console.WriteLine("{0}", r);



      Console.WriteLine(); 
   } 
}