/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           13 Oct 2020
   Assignment:     Homework #5 Exercise #1
   Compiler:       MinGW-w64

   Description: A program that takes
   the a number of seconds and
   converts it to either days, hours,
   minutes, or seconds based on the
   amount

 *************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // creates the variables used for calculations and storage
   long long int seconds;
   double conversion;

   // prompts and stores user input
   cout << "Please enter the number of seconds: ";
   cin >> seconds;

   // formats the future outputs
   cout << fixed << setprecision(2);

   // condition: if the user enters an invalid input
   if ( seconds <= 0 )
   {
      cout << "The number of seconds must be greater than zero. Please run the program again." << endl;
   } // ends if statement

   // condition: there are less seconds than in a minute
   else if (seconds < 60)
   {
      conversion = seconds * 1;
      cout << seconds << " seconds is " << conversion << " seconds.";
   } // ends else if statement

   // condition: there are less seconds than in an hour
   else if (seconds < 3600)
   {
      conversion = double(seconds) / 60;
      cout << seconds << " seconds is " << conversion << " minutes.";
   } // ends else if statement

   // condition: there are less seconds than in a day
   else if (seconds < 86400)
   {
      conversion = double(seconds) / 3600;
      cout << seconds << " seconds is " << conversion << " hours.";
   } // ends else if statement

   // condition: there are as many or more seconds than in a day
   else
   {
      conversion = double(seconds) / 86400;
      cout << seconds << " seconds is " << conversion << " days.";
   } // ends else statement


   return 0;
} // end main method