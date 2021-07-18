/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           17 Nov 2020
   Assignment:     Homework #9 Exercise #2
   Compiler:       MinGW-w64

   Description: calculates which values
   of n, P(n) = n² + n + 41 is prime

 *************************************/

#include <iostream>
#include <iomanip>

// checks if an integer is a prime number
bool isPrime(int num)
{
   // declares variables for the function
   int check = 2;
   bool prime = true;

   while (check <= num / 2)
   {
      // checks if prime
      if (num % check == 0)
      {
         prime = false;
         break;
      } // end if statement
      check++; // increments the checker
   } // end while loop

   // special cases since the while loop does integer division
   if (num == 2 || num == 3)
      prime = true;
   if (num == 1)
      prime = false;

   return prime; // returns either true or false
} // end function isPrime

int main()
{
   // declares necessary variables
   int n = 0;
   int primeCheck, firstComposite;
   bool checkFirstComposite = true;

   // Checks every P(n), 0 <= n <= 100
   while (n <= 100)
   {
      primeCheck = (n * n) + n + 41;
      std::cout << "P(" << std::setw(2) << n << ")\t";
      if (isPrime(primeCheck))
         std::cout << "prime" << std::endl;
      else
      {
         std::cout << "not prime" << std::endl;
         if (checkFirstComposite)
         {
            checkFirstComposite = false;
            firstComposite = n;
         } // end if statement
      } // end else statement
      n++; // increments the counter
   } // end while loop

   // prints out the first number that is composite (not prime)
   std::cout << "The first value of n for which P(n) is not prime is " << firstComposite << std::endl;
   return 0;
} // end main method