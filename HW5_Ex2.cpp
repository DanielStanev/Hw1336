/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           13 Oct 2020
   Assignment:     Homework #5 Exercise #2
   Compiler:       MinGW-w64

   Description: A program that asks
   the user to select a package and
   enter minutes used, and prints out
   their total bill, and notifies the
   user if they selected the cheapest
   package

 *************************************/

#include <iostream>

using namespace std;

int main()
{
   // creates variables for calculations
   double costA, costB, costC;
   char package;
   int minutes;

   //prints out a menu
   cout << "The mobile phone service provider offers 3 monthly packages" << endl;
   cout << "Package A:  $39.99 for 450 minutes, and $0.45 per additional minute" << endl;
   cout << "Package B:  $59.99 for 900 minutes, and $0.40 per additional minute" << endl;
   cout << "Package C:  $99.99 for unlimited minutes" << endl;

   // prompts user to select a menu option
   cout << "Please select a package by typing the letter of the package and pressing enter: ";
   cin >> package;

   // checks if valid package was selected
   if (package >= 97)
      package = package - 32;
   if (package < 65 || package > 67)
   {
      cout << "That package is invalid. Please run the program again and select a valid package";
      return 1;
   }

   // asks the user for the number of minutes used
   cout << "You have selected Package " << package << endl;
   cout << "Please enter the number of minutes used: ";
   cin >> minutes;

   if (minutes <= 0)
   {
      cout << "The minutes must be greater than zero. Please run the program again.";
      return 1;
   }

   // the cost of package c is not dependent on minutes
   costC = 69.99;

   // condition: user selected less than or 450 minutes
   if (minutes <= 450)
   {
      costA = 39.99;
      costB = 59.99;
   } // end if statement

   // condition: user selected less than or 900 minutes
   else if (minutes <= 900)
   {
      costA = 39.99 + ((0.45) * (double(minutes) - 450));
      costB = 59.99;
   } // end else if statement

   // condition: user selected more than 900 minutes
   else if (minutes > 900)
   {
      costA = 39.99 + ((0.45) * (double(minutes) - 450));
      costB = 59.99 + ((0.40) * (double(minutes) - 900));
   } // end else if statement

   // condition: user selected package A
   if (package == 'A')
   {
      cout << "Your monthly bill is $ " << costA << endl;
      if (costA < costB && costA < costC)
         cout << "Congratulations, You have selected the cheapest package" << endl;
   } // end if statement

   // condition: user selected package B
   else if (package == 'B')
   {
      cout << "Your monthly bill is $ " << costB << endl;
      if (costB < costA && costB < costC)
         cout << "Congratulations, You have selected the cheapest package" << endl;
   } // end else if statement

   // condition: user selected package C
   else if (package == 'C')
   {
      cout << "Your monthly bill is $ " << costC << endl;
      if (costC < costA && costC < costB)
         cout << "Congratulations, You have selected the cheapest package" << endl;
   } // end else if statement

   return 0;
} // end main method
