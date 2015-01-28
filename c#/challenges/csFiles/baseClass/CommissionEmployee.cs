// CommissionEmployee.cs
// CommissionEmployee with protected instance variables.
using System;

namespace BasePlusCommissionEmployee
{

public class CommissionEmployee : object
{
   protected string firstName;
   protected string lastName;
   protected string socialSecurityNumber;
   protected decimal grossSales; // gross weekly sales       
   protected decimal commissionRate; // commission percentage

   // five-parameter constructor
   public CommissionEmployee( string first, string last, string ssn,
      decimal sales, decimal rate )
   {
      // implicit call to object constructor occurs here             
      firstName = first;
      lastName = last;
      socialSecurityNumber = ssn;
      GrossSales = sales; // validate gross sales via property       
      CommissionRate = rate; // validate commission rate via property
   } 

   // read-only property that gets commission employee's first name
   public string FirstName
   {
      get
      {
         return firstName;
      } 
   } 

   // read-only property that gets commission employee's last name
   public string LastName
   {
      get
      {
         return lastName;
      }
   } 

   // read-only property that gets 
   // commission employee's social security number
   public string SocialSecurityNumber
   {
      get
      {
         return socialSecurityNumber;
      }
   } 

   // property that gets and sets commission employee's gross sales
   public decimal GrossSales
   {
      get
      {
         return grossSales;
      } 
      set
      {
         if ( value >= 0 )
            grossSales = value;
         else 
            throw new ArgumentOutOfRangeException(
               "GrossSales", value, "GrossSales must be >= 0" );
      } 
   } 

   // property that gets and sets commission employee's commission rate
   public decimal CommissionRate
   {
      get
      {
         return commissionRate;
      } 
      set
      {
         if ( value > 0 && value < 1 )
            commissionRate = value;
         else 
            throw new ArgumentOutOfRangeException( "CommissionRate", 
               value, "CommissionRate must be > 0 and < 1" );
      } 
   } 

   // calculate commission employee's pay
   public virtual decimal Earnings()
   {
      return commissionRate * grossSales;
   } 

   // return string representation of CommissionEmployee object         
   public override string ToString()
   {
      return string.Format(
         "{0}: {1} {2}\n{3}: {4}\n{5}: {6:C}\n{7}: {8:F2}",
         "commission employee", FirstName, LastName,
         "social security number", SocialSecurityNumber,
         "gross sales", GrossSales, "commission rate", CommissionRate );
   } 
} 

}