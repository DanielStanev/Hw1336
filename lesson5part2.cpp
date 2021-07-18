/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           13 Oct 2020
   Assignment:     Lesson 5 Part 2
   Compiler:       MinGW-w64

   Description: A program that takes
   the medium and time with
   which sound is traveling and
   displays the distance travelled.

 *************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // creates variables for calculations
   double time, distance;
   unsigned int menu;

   // prints out a menu and prompts user for input
   cout << "Select the medium that sound is traveling through:" << endl;
   cout << "1 Carbon Dioxide" << endl;
   cout << "2 Air" << endl;
   cout << "3 Helium" << endl;
   cout << "4 Hydrogen" << endl;

   // stores input for the menu value
   cin >> menu;

   if (menu == 0 || menu > 4)
      cout << "The menu value is invalid. Please run the program again." << endl;
   else if (menu == 1)
   {
      //prompts the user to enter the time
      cout << "Enter time (in seconds)" << endl;
      cin >> time;

      // checks if the time is valid
      if (time < 0 || time > 30)
      {
         cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
      }
      else
      {
         distance = 258.0 * time;
         cout << "Carbon Dioxide: " << fixed << setprecision(3) << time << " seconds" << endl;
         cout << "Traveled " << setprecision(4) << distance << " meters" << endl;
      }
   }
   else if (menu == 2)
   {
      //prompts the user to enter the time
      cout << "Enter time (in seconds)" << endl;
      cin >> time;

      // checks if the time is valid
      if (time < 0 || time > 30)
      {
         cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
      }
      else
      {
         distance = 331.5 * time;
         cout << "Air: " << fixed << setprecision(3) << time << " seconds" << endl;
         cout << "Traveled " << setprecision(4) << distance << " meters" << endl;
      }
   }
   else if (menu == 3)
   {
      //prompts the user to enter the time
      cout << "Enter time (in seconds)" << endl;
      cin >> time;

      // checks if the time is valid
      if (time < 0 || time > 30)
      {
         cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
      }
      else
      {
         distance = 972.0 * time;
         cout << "Helium: " << fixed << setprecision(3) << time << " seconds" << endl;
         cout << "Traveled " << setprecision(4) << distance << " meters" << endl;
      }
   }
   else if (menu == 4)
   {
      //prompts the user to enter the time
      cout << "Enter time (in seconds)" << endl;
      cin >> time;

      //checks if the time is valid
      if (time < 0 || time > 30)
      {
         cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
      }
      else
      {
         distance = 1270.0 * time;
         cout << "Hydrogen: " << fixed << setprecision(3) << time << " seconds" << endl;
         cout << "Traveled " << setprecision(4) << distance << " meters" << endl;
      }
   }

   return 0;
} // end main method