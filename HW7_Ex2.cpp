/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           2 Nov 2020
   Assignment:     Homework #7 Exercise #2
   Compiler:       MinGW-w64

   Description:  A program that reads
   from input.txt and then outputs a
   report to the console on the data

 *************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
   // declares variables to be used in program
   int total, sum, max, min, max2, min2, current;
   double average;
   bool firstIteration = true, secondIteration = true;

   // creates an object and opens random.txt
   std::ifstream input ("random.txt");

   // checks if file was sucessfully opened
   if(!input)
   {
      std::cout << "The input file could not be opened, the program will now terminate" << std::endl;
      return 1;
   }

   // while there are values to read executes loop
   while (input >> current)
   {
      // checks if its the first iteration
      if (firstIteration)
      {
         max = current;
         min = current;
         firstIteration = false;
      } // end if statement

      // checks if its the second iteration
      if (secondIteration)
      {
         if (current < max)
            max2 = current;
         else
            max2 = max;
         if (current > min)
            min2 = current;
         else
            min2 = min;
         secondIteration = false;
      } // end if statement

      if (current > max)
         max = current;
      if (current < min)
         min = current;
      if (current < max && current > max2)
         max2 = current;
      if (current > min && current < min2)
         min2 = current;

      // increments total and updates sum
      sum += current;
      total++;
   } // end while loop

   // calculates average
   average = sum / double(total);

   // outputs a report to the console
   std::cout << std::fixed << std::setprecision(1);
   std::cout << "Number of numbers:      " << std::right << std::setw(6) << total << std::endl;
   std::cout << "Sum of numbers:         " << std::right << std::setw(6) << sum << std::endl;
   std::cout << "Average of numbers:     " << std::right << std::setw(6) << average << std::endl;
   std::cout << "Largest number:         " << std::right << std::setw(6) << max << std::endl;
   std::cout << "Smallest number:        " << std::right << std::setw(6) << min << std::endl;
   std::cout << "Second largest number:  " << std::right << std::setw(6) << max2 << std::endl;
   std::cout << "Second smallest number: " << std::right << std::setw(6) << min2 << std::endl;

   // closes file
   input.close();

   return 0;
} // end main method