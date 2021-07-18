/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           4 Nov 2020
   Assignment:     Homework #8 Exercise #1
   Compiler:       MinGW-w64

   Description: asks for a user input
   and then finds that many prime numbers

 *************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

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
   // declares variables to be used
   int input = 0, i = 1, primecheck = 2;

   // creates object output and opens file "PrimeOut.txt"
   std::ofstream output ("PrimeOut.txt");

   // checks if file opened correctly
   if (!(output)) {
      std::cout << "The file PrimeOut.txt could not be opened please run the program again.";
      return 1;
   } // end if statement

   // input validation loop
   while (input < 1 || input > 100)
   {
      std::cout << "Please enter an integer between 1 and 100 inclusive: ";
      std::cin >> input;
      if (input < 1 || input > 100) {
         std::cout << input << " is not a valid input, please try again." << std::endl;
      } // end if statement
   } // end while loop

   // fixing grammar in the special case the user enters 1
   if (input == 1) {
      std::cout << "The first prime number is: ";
      output << "The first prime number is: ";
   } // end if statement

      // all other cases 2-100
   else {
      std::cout << "The first " << input << " primes: ";
      output << "The first " << input << " primes: ";
   } // end else statement

   // while loop that outputs to the file and console
   while (i <= input)
   {
      // uses my isPrime function to check if a number is prime
      if (isPrime(primecheck))
      {

         // formatting for the output
         if (i % 10 == 1)
         {
            std::cout << std::endl;
            output << std::endl;
         } // end if statement

         std::cout << std::setw(5) << primecheck;
         output << std::setw(5) << primecheck;
         i++;
      } // end if statement
      primecheck++;
   } // end while loop

   // closes the file
   output.close();

   return 0;
} // end main method