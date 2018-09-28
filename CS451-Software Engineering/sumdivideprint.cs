using System;
using System.Collections.Generic;

namespace exam451question15
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            const int SIZE = 11;
            List<double> list = new List<double>();

            double sum = 0;
            double div = 0;

            Console.WriteLine("User will be requested to enter 10 numbers and then a number" +
                              "\nto divide the sum of those first 10 numbers by");


            for (int counter = 0; counter < (SIZE - 1); ++counter) {
                Console.WriteLine("Enter number for location {0}:", counter + 1);
                list.Add(Convert.ToDouble(Console.ReadLine()));
            }

            Console.WriteLine("Values entered were:");
            foreach(var item in list) {
                Console.WriteLine(item);
                sum = sum + item;
            } 

            Console.WriteLine("Enter value to divide the total sum by: ");
            div = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Total sum for values entered  \t: {0}", sum);
            Console.WriteLine("Resulting value after division\t: {0}", (sum / div));
        }
    }
}

/*
User will be requested to enter 10 numbers and then a number
to divide the sum of those first 10 numbers by
Enter number for location 1:
1
Enter number for location 2:
2
Enter number for location 3:
3
Enter number for location 4:
4
Enter number for location 5:
5
Enter number for location 6:
6
Enter number for location 7:
7
Enter number for location 8:
8
Enter number for location 9:
9
Enter number for location 10:
10
Values entered were:
1
2
3
4
5
6
7
8
9
10
Enter value to divide the total sum by: 
10
Total sum for values entered    : 55
Resulting value after division  : 5.5

Press any key to continue...
*/