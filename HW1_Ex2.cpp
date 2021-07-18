/**************************************************

   Author:         Daniel Stanev
   Course:         CS1336.501
   Date:           2 Sep 2020
   Assignment:     Homework #1 Exercise #2
   Compiler:       MinGW-w64

   Description:


 **************************************************/

#include <stdio.h>

int main()
{
   float timeVal = 5.36;                                      // The amount of time traveled
   float acceleration = 32.0;                                 // The constant acceleration during that time
   double distanceVal = (1.0/2)*acceleration*timeVal*timeVal; // The distance traveled based on the acceleration and time

   printf("The time was:               %.1f\n", timeVal);
   printf("The acceleration was:       %.1f\n", acceleration);
   printf("The distance traveled was:  %.1f\n", distanceVal);

   return 0;
} // end main method