using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace CS451Average
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double average = 0;
            string inputFile = "/Users/williamkelley/Documents/GitHub/school/CS451-Software Engineering/Assignment 1/testnumbers.txt";

            Console.WriteLine("Values in input file must be within range 0 - 999");

            string[] lines = System.IO.File.ReadAllLines(inputFile);

            if (AreTheyNumbers(lines) == true)
            {
                ConvertToInts(lines, ref average);
                WriteAverageToFile(average);
            }
            else
            {
                return;
            }

        }

        public static bool AreTheyNumbers(string[] input)
        {
            bool numbersTrue = true;
            foreach (string l in input)
            {
                if (Regex.IsMatch(l, @"^\d+$"))
                {
                    numbersTrue = true;
                }
                else
                {
                    Console.WriteLine("Invalid Inputs");
                    numbersTrue = false;
                    return numbersTrue;
                }
            }
            return numbersTrue;
        }

        public static void ConvertToInts(string[] numbers, ref double avg)
        {
            int[] values = numbers.Select((n) => int.Parse(n)).ToArray();
            avg = values.Average();

            Console.WriteLine("{0} was the average", avg);
        }

        public static void WriteAverageToFile(double printVal)
        {
            string createText = "William Kelley" + Environment.NewLine
                                                              + "Output For Average" + Environment.NewLine
                                                              + printVal + " was the average." + Environment.NewLine;
            string path = "/Users/williamkelley/Documents/GitHub/school/CS451-Software Engineering/Assignment 1/average_results.txt";

            File.WriteAllText(path, createText);
        }
    }
}