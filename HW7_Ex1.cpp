/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           2 Nov 2020
   Assignment:     Homework #7 Exercise #1
   Compiler:       MinGW-w64

   Description: A program that reads in
   a user input and outputs various
   triangles to the console.

   Bonus: reads in a user input and
   outputs an hourglass to the console.

 *************************************/

#include <iostream>

// I noticed I was typing this loop quite a few times so I decided it would be easier to make it a function
void printSpaces(int spaces)
{
   while (spaces > 0)
   {
      std::cout << " ";
      spaces--;
   } // end while loop
} // end function printSpaces

// same thing goes for the stars
void printStars(int stars)
{
   while(stars > 0)
   {
      std::cout << "*";
      stars--;
   }
} // end function printStars

// function that outputs a left justified right triangle
void leftTriangle(int height)
{
   // declares a variable for the width of the current row
   int width;

   while (height > 0)
   {
      width = height;
      printStars(width);
      std::cout << std::endl;
      height--;
   } // end while loop
   std::cout << std::endl;
} // end function leftTriangle

void rightTriangle(int height)
{
   int width, spaces, total = height;

   while (height > 0)
   {
      width = height;
      spaces = total - width;
      printSpaces(spaces);
      printStars(width);
      std::cout << std::endl;
      height--;
   } // end while loop
   std::cout << std::endl;
} // end function rightTriangle

void isoscelesTriangle(int height)
{
   // declares variables
   int width, spaces;
   int total = ((2 * height) - 1);
   int i = 1;

   while (i <= height)
   {
      width = ((2 * i) - 1);
      spaces = ((total - width) / 2);
      printSpaces(spaces);
      printStars(width);
      std::cout << std::endl;
      i++;
   } // end while loop
   std::cout << std::endl;
} // end function isoscelesTriangle

void hollowIsosceles(int height)
{
   // declares variables
   int width, spaces;
   int total = ((2 * height) - 1);
   int i = 1;

   while (i < height)
   {
      width = ((2 * i) - 1);
      spaces = ((total - width) / 2);
      printSpaces(spaces);
      std::cout << "*";
      printSpaces(width - 2);
      if (i != 1)
         std::cout << "*";
      printSpaces(spaces);
      std::cout << std::endl;
      i++;
   } // end while loop
   // outputs bottom base
   printStars(total);
   std::cout << std::endl;
   std::cout << std::endl;
} // end function hollowIsosceles

void bonus(int height)
{
   // declares variables for bonus
   int base = height;
   int halfway = (height / 2);
   int i = 1;

   // outputs top base
   while (base > 0)
   {
      if (base > 1)
         std::cout << "* ";
      else
         std::cout << "*";
      base--;
   }
   std::cout << std::endl;

   // output upper half of hourglass
   while (i < halfway)
   {
      printSpaces(2 * i);
      std::cout << "*";
      printSpaces(((2 * height) - 1) - (4 * i + 2));
      std::cout << "*" << std::endl;
      i++;
   }

   // output middle * of hourglass
   printSpaces(2 * i);
   std::cout << "*" << std::endl;
   i--;

   // output lower half of hourglass
   while (i > 0)
   {
      printSpaces(2 * i);
      std::cout << "*";
      printSpaces(((2 * height) - 1) - (4 * i + 2));
      std::cout << "*" << std::endl;
      i--;
   } // end while loop

   // output bottom base of hourglass
   while (height > 0)
   {
      if (height > 1)
         std::cout << "* ";
      else
         std::cout << "*";
      height--;
   } // end while loop
} // end function bonus

int main()
{
   int height = 0;

   // input validation loop
   while (height <= 1 || height >= 15)
   {
      std::cout << "Please enter an integer between 1 and 15: ";
      std::cin >> height;
   } // end while loop

   std::cout << std::endl;

   // outputs the triangle to the console
   leftTriangle(height);
   rightTriangle(height);
   isoscelesTriangle(height);
   hollowIsosceles(height);

   // resets value of height
   height = 0;


   // input validation loop
   while (height <= 1 || height >= 15 || height % 2 != 1)
   {
      std::cout << "For the bonus: Please enter an odd integer between 1 and 15: ";
      std::cin >> height;
   } // end while loop

   std::cout << std::endl;

   //outputs the bonus to the console
   bonus(height);

   return 0;
} // end main method