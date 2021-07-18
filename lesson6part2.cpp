/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           17 Oct 2020
   Assignment:     Lesson 6 Part 2
   Compiler:       MinGW-w64

   Description: A program that takes
   in a range of fahrenheit
   temperatures and converts to
   celsius and kelvin

 *************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // creates all variables to be used, two lines are used to maintain readability
   double startTemp, endTemp, increment;
   double fahrenheit, celsius, kelvin;

   // styling for the table
   cout << fixed << setprecision(4);

   // user inputs values until they are valid
   while (true)
   {
      cin >> startTemp >> endTemp >> increment;

      // if inputs are invalid, asks user to put in new inputs and restarts the loop
      if (startTemp > endTemp || increment <= 0)
      {
         cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
         continue;
      } // end if statement

      // if the inputs are valid the loop ends
      else
      {
         break;
      } // end else statement
   } // end while loop

   // prints out the the top row of the table
   cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin" << endl;

   // assigns the startTemp to fahrenheit for readability inside the while loop
   fahrenheit = startTemp;

   // calculates the temperatures and prints out a report until the end value is reached
   while (fahrenheit <= endTemp )
   {
      celsius = (fahrenheit - 32) / 1.8;
      kelvin = celsius + 273.15;
      cout << setw(18) << fahrenheit << setw(18) << celsius << setw(18) << kelvin << endl;
      fahrenheit += increment;
   } // end while loop

   return 0;
} // end main method