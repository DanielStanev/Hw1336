/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           31 Oct 2020
   Assignment:     Lesson 7 Part 1
   Compiler:       MinGW-w64

   Description: Reads a file and then
   writes the correct information based
   on the file in saleschart.txt

 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
   // creates variables to be used in the program
   std::string ifname, ofname;
   unsigned int storeNumber;
   long long salesValue;
   bool header = true;
   int numstars, i;

   // prompts the user to select an input file
   std::cout << "Enter input file name" << std::endl;
   std::cin >> ifname;

   // creates an inputfile object and opens the file
   std::ifstream inputfile (ifname);

   // error message if the file could not be opened
   if(!(inputfile))
   {
      std::cout << "File \"" << ifname << "\" could not be opened" << std::endl;
      return 1;
   } // end if statement

   // creates an outputfile object and opens the file saleschart.txt
   std::ofstream outputfile ("saleschart.txt");

   // error message if the file could not be opened
   if (!(outputfile))
   {
      inputfile.close();
      return 1;
   } // end if statement

   // while the input file has information to read
   while (inputfile >> storeNumber >> salesValue)
   {
      // checks   if store number is valid
      if(storeNumber < 1 || storeNumber > 99)
      {
         std::cout << "The store number " << storeNumber << " is not valid" << std::endl;
      } // end if statement
      else
      {

         // outputs the header only if it hasn't been outputted before
         if (header)
         {
            outputfile << "SALES BAR CHART" << std::endl;
            outputfile << "(Each * equals 5,000 dollars)" << std::endl;
            header = false;
         } // end if statement

         // if the sales value is invalid
         if (salesValue < 0)
         {
            std::cout << "The sales value for store " << storeNumber << " is negative" << std::endl;
         } // end if statement

         // if the sales value is valid outputs the row
         else
         {
            outputfile << "Store " << std::setw(2) << storeNumber << ": ";
            numstars = salesValue / 5000;

            // for to output the correct number of stars
            for (i = 0 ; i < numstars ; i++)
            {
               outputfile << "*";
            } // end for loop

            // outputs a newline character after the row is finished
            outputfile << std::endl;

         } // end else statement
      } // end else statement
   } // end while loop

   // closes the files
   inputfile.close();
   outputfile.close();

   return 0;
} // end main method