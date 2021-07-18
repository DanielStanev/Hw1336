/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           17 Oct 2020
   Assignment:     Lesson 6 Part 1
   Compiler:       MinGW-w64

   Description: A program that takes
   in two ascii values and prints out
   all characters in their range

 *************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
   // creates variables used in program
   unsigned int lower, upper;
   string final;
   char ch;

   // executes until a valid input is entered for lower and upper
   while (true)
   {
      // prompts the user to input lower and upper values and stores them
      cout << "Enter lower and upper values" << endl;
      cin >> lower >> upper;

      if (lower < 32 || upper > 126 || lower > upper) {
         cout << "Values must be in range 32 to 126 inclusive" << endl;
         continue;
      } // ends if statement

      // breaks out of the loop when the lower and upper values are valid
      else
      {
         break;
      } // end else statement
   } // end while loop

   // prints out first part of output before the lower value is changed
   cout << "Characters for ASCII values between " << lower << " and " << upper << endl;

   // appends each ascii character between the lower and upper value to the end of the string
   while (lower <= upper)
   {
      // appends a newline character to the end of the string every 20 non-newline characters
      if (final.length() == 20 || final.length() == 41 || final.length() == 62 || final.length() == 83)
      {
         final += '\n';
      } // end if statement

      ch = lower;
      final += ch;
      lower++;
   } // end while loop

   // prints the final output
   cout << "----+----+----+----+"<< endl;
   cout << final << endl;
   cout << "----+----+----+----+" << endl;

   return 0;
} // end main method