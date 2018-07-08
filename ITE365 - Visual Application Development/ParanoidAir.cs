// William Kelley
// ReverseApp.cs
// ITE365-Lab02

using System;

namespace ParanoidAir
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.Write("(Integer Reverse)Enter an integer (-1 to exit): ");
            int number = Convert.ToInt32(Console.ReadLine());
            while (number != -1) {
                Console.WriteLine("{0} reversed as an integer is {1}",
                   number, ReverseDigits(number));
                Console.Write("(Integer Reverse)Enter an integer (-1 to exit): ");
                number = Convert.ToInt32(Console.ReadLine());
            }

            Console.WriteLine("(String Reverse)Enter an integer (-1 to exit): ");
            string num = Console.ReadLine();
            while (num != "-1") {
                Console.WriteLine("{0} reverse as a string is {1}",
                    num, ReverseDigitsUsingStrings(num));
                Console.Write("(String Reverse)Enter a number (-1 to exit): ");
                num = Console.ReadLine();
            }
        }

        // display parameter number with digits reversed as an integer
        public static int ReverseDigits(int number)
        {
            int reverseNumber = 0;
            int placeValue;

            while (number>0) {
                placeValue = number % 10;
                number = number / 10;
                reverseNumber = reverseNumber * 10 + placeValue;
            }

            return reverseNumber;
        }
        // display parameter num with digits reversed as a string
        public static string ReverseDigitsUsingStrings(string num)
        {
            char[] charArray = num.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
    }
}