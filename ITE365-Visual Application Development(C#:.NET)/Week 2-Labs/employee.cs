//
// File:   employee.cs
// Author: Adam.Lewis@athens.edu
// Purpose:
// Define supporting class for ITE365 Lab 08, based on code taken
// from Deitel's Visual C# text, 5th edition
//
public class Employee
{
   private decimal monthlySalaryValue; // monthly salary of employee
   
   // auto-implemented property FirstName
   public string FirstName { get; set; }

   // auto-implemented property LastName
   public string LastName { get; set; }

   // constructor initializes first name, last name and monthly salary
   public Employee( string first, string last, decimal salary )
   {
      FirstName = first;
      LastName = last;
      MonthlySalary = salary;
   } // end constructor

   // property that gets and sets the employee's monthly salary
   public decimal MonthlySalary
   {
      get
      {
         return monthlySalaryValue;
      } // end get
      set
      {
         if ( value >= 0M ) // if salary is non-negative
         {
            monthlySalaryValue = value;
         } // end if
      } // end set
   } // end property MonthlySalary

   // return a String containing the employee's information
   public override string ToString() 
   {
      return string.Format( "{0,-10} {1,-10} {2,10:C}", 
         FirstName, LastName, MonthlySalary );
   } // end method ToString
} // end class Employee

