/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           24 Oct 2020
   Assignment:     Homework #6 Exercise #2
   Compiler:       MinGW-w64

   Description:

 *************************************/

#include <iostream>

int main()
{
   // creates all the variables to be used in the program
   int storeOne, storeTwo, storeThree, storeFour, storeFive, numStars;

   // input validation loop for store 1
   while (true)
   {
      // prompts the user for and stores value of store 1
      std::cout << "Enter today's sales for store 1: ";
      std::cin >> storeOne;

      // error message if the user enters invalid input
      if(storeOne < 0)
      {
         std::cout << "The number of sales must be greater than or equal to 0" << std::endl;
         continue;
      } // end if statement
      break;
   } // end while loop

   // input validation loop for store 2
   while (true)
   {
      // prompts the user for and stores value of store 2
      std::cout << "Enter today's sales for store 2: ";
      std::cin >> storeTwo;

      // error message if the user enters invalid input
      if(storeTwo < 0)
      {
         std::cout << "The number of sales must be greater than or equal to 0" << std::endl;
         continue;
      } // end if statement
      break;
   } // end while loop

   // input validation loop for store 3
   while (true)
   {
      // prompts the user for and stores value of store 3
      std::cout << "Enter today's sales for store 3: ";
      std::cin >> storeThree;

      // error message if the user enters invalid input
      if(storeThree < 0)
      {
         std::cout << "The number of sales must be greater than or equal to 0" << std::endl;
         continue;
      } // end if statement
      break;
   } // end while loop

   // input validation loop for store 4
   while (true)
   {
      // prompts the user for and stores value of store 4
      std::cout << "Enter today's sales for store 4: ";
      std::cin >> storeFour;

      // error message if the user enters invalid input
      if(storeFour < 0)
      {
         std::cout << "The number of sales must be greater than or equal to 0" << std::endl;
         continue;
      } // end if statement
      break;
   } // end while loop

   // input validation loop for store 5
   while (true)
   {
      // prompts the user for and stores value of store 5
      std::cout << "Enter today's sales for store 5: ";
      std::cin >> storeFive;

      // error message if the user enters invalid input
      if(storeFive < 0)
      {
         std::cout << "The number of sales must be greater than or equal to 0" << std::endl;
         continue;
      } // end if statement
      break;
   } // end while loop

   // Prints the Title of the report
   std::cout << std::endl;
   std::cout << "SALES BAR CHART" << std::endl;
   std::cout << "(Each * = $100)" << std::endl;

   // prints out stars for store 1
   numStars = 0;
   std::cout << "Store 1: ";
   while (numStars < (storeOne / 100))
   {
      std::cout << "*";
      numStars++;
   } // end while loop
   std::cout << std::endl;

   // prints out stars for store 2
   numStars = 0;
   std::cout << "Store 2: ";
   while (numStars < (storeTwo / 100))
   {
      std::cout << "*";
      numStars++;
   } // end while loop
   std::cout << std::endl;

   // prints out stars for store 3
   numStars = 0;
   std::cout << "Store 3: ";
   while (numStars < (storeThree / 100))
   {
      std::cout << "*";
      numStars++;
   } // end while loop
   std::cout << std::endl;

   // prints out stars for store 4
   numStars = 0;
   std::cout << "Store 4: ";
   while (numStars < (storeFour / 100))
   {
      std::cout << "*";
      numStars++;
   } // end while loop
   std::cout << std::endl;

   // prints out stars for store 5
   numStars = 0;
   std::cout << "Store 5: ";
   while (numStars < (storeFive / 100))
   {
      std::cout << "*";
      numStars++;
   } // end while loop
   std::cout << std::endl;

   return 0;
} // end main method