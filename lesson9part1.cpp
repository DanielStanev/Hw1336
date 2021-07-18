/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           8 Nov 2020
   Assignment:     Lesson 9 Part 1
   Compiler:       MinGW-w64

   Description: Reads in an order for
   spools and calculates the price
   and prints out a report

 *************************************/

#include <iostream>
#include <iomanip>

void readSpools(int& ordered, int& stock, char& check, double& price)
{
   // input validation loop
   while (ordered < 1)
   {
      std::cout << "Spools to be ordered" << std::endl;
      std::cin >> ordered;
      if (ordered < 1)
         std::cout << "Spools order must be 1 or more" << std::endl;
   } // end while loop

   // input validation loop
   while (stock < 0)
   {
      std::cout << "Spools in stock" << std::endl;
      std::cin >> stock;
      if (stock < 0)
         std::cout << "Spools in stock must be 0 or more" << std::endl;
   } // end while loop
   std::cout << "Special shipping and handling (y or n)" << std::endl;
   std::cin >> check;
   if (check == 'y')
   {
      do
      {
         std::cout << "Shipping and handling amount" << std::endl;
         std::cin >> price;
         if (price < 0)
            std::cout << "The spool shipping and handling charge must be 0.0 or more" << std::endl;
      } // end do-while loop
      while (price < 0);
   } // end if statement
} // end function readSpools

void displayReport(int ordered, int stock, double shippingPrice)
{
   // calculations
   int ship;
   if (ordered >= stock)
      ship = stock;
   else
      ship = ordered;
   ordered -= ship;
   double subtotal = 104.0 * double(ship);
   shippingPrice *= double(ship);
   double total = subtotal + shippingPrice;

   // prints out a report
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Spools ready to ship: " << ship << std::endl;
   std::cout << "Spools on back-order: " << ordered << std::endl;
   std::cout << "Subtotal ready to ship: $" << std::setw(10) << subtotal << std::endl;
   std::cout << "Shipping and handling:  $" << std::setw(10) << shippingPrice << std::endl;
   std::cout << "Total shipping charges: $" << std::setw(10) << total << std::endl;
} // end function displayReport

int main()
{
   // declares necessary variables
   int ordered = -1, stock = -1;
   char check;
   double price = 12.99;

   // reads the information and prints out a report
   readSpools(ordered, stock, check, price);
   displayReport(ordered, stock, price);

   return 0;
} // end main method