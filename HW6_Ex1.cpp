/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           24 Oct 2020
   Assignment:     Homework #6 Exercise #1
   Compiler:       MinGW-w64

   Description: Completes parts
   a, b, c, and d using for, do-while
   and while loops.

   part e: prints out all multiples of 100
   less than 1336

 *************************************/

#include <iostream>
#include <iomanip>

int main()
{
   // Creates the variables for parts a-d and assigns values for part a
   int counter = 0, num = 2;

   // part a
   for (int num = 2; num <= 100; num+=2)
   {

      // every ten numbers a newline character is printed
      if (counter % 10 == 0 && counter != 0)
      {
         std::cout << std::endl;
      } // end if statement

      // increments the counter and prints a number
      counter++;
      std::cout << std::setw(5) << num;

   } // end for loop

   // prints out number of numbers for part a
   std::cout << std::endl << "Number of numbers = " << counter << ".\n\n";

   // sets counter and num for part b
   counter = 0;
   num = 99;

   // part b
   do
   {
      // every ten numbers a newline character is printed
      if (counter % 10 == 0 && counter != 0)
      {
         std::cout << std::endl;
      } // end if statement

      // increments the counter and prints a number and shifts num to next value
      counter++;
      std::cout << std::setw(5) << num;
      num -= 3;
   } // end do-while loop
   while (num >= 3); // condition of the do-while loop.

   // prints out number of numbers for part b
   std::cout << std::endl << "Number of numbers = " << counter << ".\n\n";

   // sets counter and num for part c
   counter = 0;
   num = 2;

   // part c
   while (num <= 1048576)
   {
      // every eight numbers a newline character is printed
      if (counter % 8 == 0 && counter != 0)
      {
         std::cout << std::endl;
      }// end if statement

      // increments the counter and prints a number and shifts num to next value
      counter++;
      std::cout << std::setw(8) << num;
      num *= 2;
   } // end while loop

   std::cout << std::endl << "Number of numbers = " << counter << ".\n\n";

   // sets counter and num for part d
   counter = 0;
   num = 1048576;

   // part d
   while (num >= 2)
   {
      // every eight numbers a newline character is printed
      if (counter % 8 == 0 && counter != 0)
      {
         std::cout << std::endl;
      } // end if statement

      // increments the counter and prints a number and shifts num to next value
      counter++;
      std::cout << std::setw(8) << num;
      num /= 2;
   } // end while loop

   // prints out number of numbers for part d
   std::cout << std::endl << "Number of numbers = " << counter << ".\n\n";

   // part e prints out all multiples of 100 under 1336
   num = 1;
   counter = 0;
   int check = 1;

   // I decided to do this loop a bit differently and have it iterate through all numbers to see if it would work
   while (num <= 1336 )
   {
      // every eight numbers a newline character is printed
      if (counter % 8 == 0 && check != 1)
      {
         std::cout << std::endl;
         check = 1;
      } // end if statement

      // checks if the number is divisible by 100
      if (num % 100 == 0)
      {
         std::cout << std::setw(5) << num;
         counter++;
         check = 0;
      } // end if statement
      num ++; // increment the number
   } // end while loop

   std::cout << std::endl << "Number of numbers = " << counter << ".";

   return 0;
} // end main method