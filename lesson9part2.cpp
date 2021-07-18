/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           18 Nov 2020
   Assignment:     Lesson 9 Part 2
   Compiler:       MinGW-w64

   Description: opens a file and calculates
   the future value based on interest and
   writes to output.xls

 *************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

// calculates future value
double futureValue(double presentValue, double interestRate, int months)
{
   double future = presentValue * pow((interestRate + 1), months);
   return future;
} // end method futureValue

int main()
{
   // declares necessary variables
   std::string inputfile;
   std::string errorValues = "";
   std::string outputValues = "";
   double future, present, interest;
   int months;

   // asks for the user to enter the input file name
   std::cout << "Enter input file name" << std::endl;
   std::cin >> inputfile;

   // creates an input stream object and opens the input file
   std::ifstream input (inputfile);

   // checks if the input file could be opened
   if(!(input))
   {
      std::cout << "File \"" << inputfile << "\" could not be opened" << std::endl;
      return 1;
   } // end if statement

   // creates an output stream object and opens output.xls
   std::ofstream output ("output.xls");

   // checks if output.xls can open
   if(!(output))
   {
      std::cout << "File output.xls could not be opened" << std::endl;
      return 1;
   } // end if statement

   output << "Future Value\tPresent Value\tMonthly Interest\tMonths" << std::endl;

   std::cout << std::fixed;

   while (input >> present >> interest >> months)
   {
      if (present <= 0 || interest <= 0 || months <= 0)
      {
         std::cout << std::setprecision(2) << present << " " << std::setprecision(3) << interest << " " << months << std::endl;
         std::cout << "One or more of the above values are not greater than zero" << std::endl;
      } // end if statement
      else
      {
         interest /= 100;
         future = futureValue(present, interest, months);
         interest *= 100;
         output << std::fixed << std::setprecision(2) << future << "\t" << present << "\t" << std::setprecision(3) << interest << "\t"<< months << std::endl;
      } // end else statement
   } // end while loop

   // closes the files
   input.close();
   output.close();

   return 0;
} // end main method