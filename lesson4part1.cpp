/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           11 Oct 2020
   Assignment:     Lesson 4 Part 1
   Compiler:       MinGW-w64

   Description: A program that takes
   the mass of an object and displays
   its weight in newtons on earth, the
   moon and venus

 *************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // constants for the acceleration on the earth, moon, and venus
   const double earthAccel = 9.81;
   const double moonAccel = 1.62;
   const double venusAccel = 8.87;

   // prompts the user to enter the mass
   double mass;
   cout << "Enter the mass in kg" << endl;
   cin >> mass;
   cout << fixed << setprecision(4);
   cout << "The mass is " << mass << " kg" << endl;

   // error message for mass is less than or equal to zero
   if (mass <= 0 )
   {
      cout << "The mass must be greater than zero" << endl;
      return 1; // ends the function early, returns 1 to show there was an error
   }

   // calculates the weight in various locations
   double earthWeight = mass * earthAccel;
   double moonWeight = mass * moonAccel;
   double venusWeight = mass * venusAccel;

   // prints out the weights on various locations
   cout << left << setw(8) << "Location" << right << setw(14) << "Weight (N)" << endl;
   cout << left << setw(8) << "Earth" << right << setw(14) << earthWeight << endl;
   cout << left << setw(8) << "Moon" << right << setw(14) << moonWeight << endl;
   cout << left << setw(8) << "Venus" << right << setw(14) << venusWeight << endl;

   // checks if the object is heavy or light
   if (earthWeight < 5)
   {
      cout << "The object is light" << endl;
   }
   else if (earthWeight >= 1500)
   {
      cout << "The object is heavy" << endl;
   }

   return 0;
} // end main method