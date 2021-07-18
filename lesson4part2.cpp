/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           11 Oct 2020
   Assignment:     Lesson 4 Part 2
   Compiler:       MinGW-w64

   Description: A program that takes
   the a number of seconds and converts
   it to days, hours, minutes, and
   remaining seconds

 *************************************/

#include <iostream>

using namespace std;

int main()
{
   // prompts the user for seconds and then displays the seconds
   long long int seconds;
   cout << "Enter seconds" << endl;
   cin >> seconds;
   cout << "Total seconds: " << seconds << endl << endl;

   // error message for seconds are less than or equal to zero
   if (seconds <= 0)
   {
      cout << "Total seconds must be greater than zero" << endl;
      return 1; // ends the function early, returns 1 to show there was an error
   }

   // calculates the conversion
   long long int days = seconds / 86400;
   seconds %= 86400;
   long long int hours = seconds / 3600;
   seconds %= 3600;
   long long int minutes = seconds / 60;
   seconds %= 60;

   //prints out the conversion
   if (days > 0)
      cout << days << " day(s)" << endl;
   if (hours > 0)
       cout << hours << " hour(s)" << endl;
   if (minutes > 0)
       cout << minutes << " minute(s)" << endl;
   if (seconds > 0)
       cout << seconds << " second(s)" << endl;


   return 0;
}