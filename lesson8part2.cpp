/************************************

   Author:         Daniel Stanev
   Course:         CS 1136.118
   Date:           6 Nov 2020
   Assignment:     Lesson 8 Part 2
   Compiler:       MinGW-w64

   Description: calculates the
   initial value was based on the
   interest rate, number of years, and
   future value

 *************************************/

#include <cmath>
#include <iostream>
#include <iomanip>

double presentValue(double futureValue, double interestRate, int numberYears)
{
   double presentValue = futureValue / pow((1 + interestRate), numberYears);
   return presentValue;
} // end function presentValue

double readFuture() {
   double future = -1;

   // input validation loop
   while (!(future > 0))
   {
      std::cout << "Enter future value" << std::endl;
      std::cin >> future;
      if (!(future > 0))
         std::cout << "The future value must be greater than zero" << std::endl;
   } // end while loop
   return future;
} // end function readFuture

double readInterest() {
   double interest = -1;

   // input validation loop
   while(!(interest > 0))
   {
      std::cout << "Enter annual interest rate" << std::endl;
      std::cin >> interest;
      if (!(interest > 0))
         std::cout << "The annual interest rate must be greater than zero" << std::endl;
   } // end while loop
   interest /= 100;
   return interest;
} // end function readInterest

double readYear()
{
   int year = -1;

   // input validation loop
   while (!(year > 0))
   {
      std::cout << "Enter number of years" << std::endl;
      std::cin >> year;
      if (!(year > 0))
         std::cout << "The number of years must be greater than zero" << std::endl;
   } //end while loop
   return year;
} // end function readYear

void displayResult(double presentValue, double futureValue, double interestRate, int numberYears)
{
   // prints out a report
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Present value: $" << presentValue << std::endl;
   std::cout << "Future value: $" << futureValue << std::endl;
   std::cout << "Annual interest rate: " << std::setprecision(3) << (interestRate * 100.0) << "%" << std::endl;
   std::cout << "Years: " << numberYears << std::endl;
} // end function display result

int main()
{
   double futureValue = readFuture();
   double interestRate = readInterest();
   int numberYears = readYear();
   displayResult(presentValue(futureValue, interestRate, numberYears), futureValue, interestRate, numberYears);

   return 0;
} // end main method