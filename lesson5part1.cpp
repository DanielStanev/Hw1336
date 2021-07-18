/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           13 Oct 2020
   Assignment:     Lesson 5 Part 1
   Compiler:       MinGW-w64

   Description: A program that takes
   the medium and distance through
   which sound is traveling and
   displays howw long it took

 *************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // creates variables to be used
   double distance, time;
   unsigned int medium;

   // prompts the user to select a medium
   cout << "Select the medium that sound is traveling through:\n1 Air\n2 Water\n3 Steel\n";
   cin >> medium;
   cout << fixed << setprecision(4);

   switch (medium)
   {
      case 1: // executes if the user selected air
         cout << "Enter distance (in feet)" << endl;
         cin >> distance;
         if (distance <= 0) // executes if user does not enter valid distance
            cout << "The distance must be greater than zero" << endl;
         else
         {
            time = distance / 1100;
            cout << "Air: " << distance << " ft" << endl;
            cout << "Traveled for " << time << " seconds" << endl;
         }
         break;
      case 2: // executes if the user selected water
         cout << "Enter distance (in feet)" << endl;
         cin >> distance;
         if (distance <= 0) // executes if user does not enter valid distance
            cout << "The distance must be greater than zero" << endl;
         else
         {
            time = distance / 4900;
            cout << "Water: " << distance << " ft" << endl;
            cout << "Traveled for " << time << " seconds" << endl;
         }
         break;
      case 3: // executes if the user selected steel
          cout << "Enter distance (in feet)" << endl;
          cin >> distance;
          if (distance <= 0) // executes if user does not enter valid distance
             cout << "The distance must be greater than zero" << endl;
          else
          {
             time = distance / 16400;
             cout << "Steel: " << distance << " ft" << endl;
             cout << "Traveled for " << time << " seconds" << endl;
          }
          break;
      default: // executes if the user does not select valid input
         cout << "The menu value is invalid. Please run the program again." << endl;
         break;
   }

   return 0;
} // end main method