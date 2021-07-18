/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           5 Nov 2020
   Assignment:     Lesson 8 Part 1
   Compiler:       MinGW-w64

   Description: takes in a user input
   for seconds and calculates the
   distance traveled on earth and the
   moon.

 *************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

double readSeconds()
{
   double seconds;
   std::cout << "Enter the time (in seconds)" << std::endl;
   std::cin >> seconds;
   if (seconds < 0)
      std::cout << "The time must be zero or more" << std::endl;
   return seconds;
} // end function readSeconds

double calculateEarthDistance(double seconds)
{
   double distance = 0.5 * 9.8 * pow(seconds, 2);
   return distance;
} // end function calculateEarthDistance

double calculateMoonDistance(double seconds)
{
   double distance = 0.5 * 1.6 * pow(seconds, 2);
   return distance;
} // end function calculateMoonDistance

void displayResults(double seconds, double earthDistance, double moonDistance)
{
   std::cout << std::fixed;
   std::cout << "The object traveled " << std::setprecision(4) << earthDistance;
   std::cout << " meters in " << std::setprecision(2) << seconds << " seconds on Earth" << std::endl;
   std::cout << "The object traveled " << std::setprecision(4) << moonDistance;
   std::cout << " meters in " << std::setprecision(2) << seconds << " seconds on the Moon" << std::endl;
} // end function displayResults

int main()
{
   double seconds = -1;

   // while loop executes until it reaches break statement
   while (true)
   {
      // input validation loop
      while (seconds < 0)
      {
         seconds = readSeconds();
      } // end inner while loop
      if (seconds == 0)
         break; // loop terminates if the user enters 0 for seconds
      displayResults(seconds, calculateEarthDistance(seconds), calculateMoonDistance(seconds));
      seconds = -1;
   } // end while loop

   return 0;
} // end main method