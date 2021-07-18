/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           1 Nov 2020
   Assignment:     Lesson 7 Part 2
   Compiler:       MinGW-w64

   Description: Reads an input file
   and calculates the average of all
   valid grades while outputting the
   invalid grades to invalid-values.txt

 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
   // declares
   std::string ifname;
   int total = 0, valid = 0, invalid = 0;
   double currentValue, sumValues, average;

   // prompts the user to enter the name of the input file
   std::cout << "Enter input file name" << std::endl;
   std::cin >> ifname;

   // opens the input file
   std::ifstream inputfile (ifname);

   // error message if the input file cannot be opened
   if(!(inputfile))
   {
      std::cout << "File \"" << ifname << "\" could not be opened" << std::endl;
      return 1;
   } // end if statement
   else
   {
      std::cout << "Reading from file \"" << ifname << "\"" << std::endl;
   }

   //  opens invalid-values.txt
   std::ofstream outputfile ("invalid-values.txt");

   // formatting for console-out and writing to invalid-values.txt
   std::cout << std::fixed << std::setprecision(4);
   outputfile << std::fixed << std::setprecision(5);

   while (inputfile >> currentValue)
   {
      // saves invalid values to invalid-values.txt
      if (currentValue < 0 || currentValue > 105)
      {
         invalid++;
         outputfile << currentValue << std::endl;
      } // end if statement

      // increments the number of valid values and adds the current value to the sum of values
      else
      {
         valid++;
         sumValues += currentValue;
      } // end else statement
      total++;
   } // end while loop

   // calulates average
   average = sumValues / double(valid);

   // prints out a report
   std::cout << "Total values: " << total << std::endl;
   std::cout << "Invalid values: " << invalid << std::endl;
   std::cout << "Valid values: " << valid << std::endl;
   if(!valid)
      std::cout << "An average cannot be calculated" << std::endl;
   else
      std::cout << "Average of valid values: " << average << std::endl;


   // closes the input and output files
   inputfile.close();
   outputfile.close();

   return 0;
} // end main method