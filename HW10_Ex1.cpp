/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           30 Nov 2020
   Assignment:     Homework #10 Exercise #1
   Compiler:       MinGW-w64

   Description: Checks if the values
   of one file appear in another.

 *************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

// linear search algorithm, ewwwww
int searchList (int array[], int arrayMax, int value)
{
   int i = 0;
   while (i <= arrayMax)
   {
      if (array[i] == value)
         return i;
      i++;
   } // end while loop
   return -1;
} // end method searchList

// takes data from an ifstream object and puts into an array
void makeArray(std::ifstream& input, int array[], int& count)
{
   // temporary storage variable
   int x;
   while(input >> x)
   {
      array[count] = x;
      count++;
   } // end while loop
   // corrects the count incrementing after the last element of the array
   count--;
} // end method makeArray

int main()
{
   int testValue, foundIndex;
   int testIndex = 0, stdMax = 0, testMax = 0;
   int standardArray [100];
   int testArray [50];
   std::ifstream LSStandard;
   std::ifstream LSTest;

   LSStandard.open("LSStandard.txt");

   // if LSStandard.txt cannot be opened
   if (!(LSStandard.is_open()))
   {
      std::cout << "The File LSStandard.txt could not be opened.";
      return 1;
   } // end if statement

   LSTest.open("LSTest.txt");

   // if LSTest.txt cannot be opened
   if (!(LSTest.is_open()))
   {
      std::cout << "The File LSTest.txt could not be opened.";
      LSStandard.close();
      return 1;
   } // end if statement

   // generates arrays from both files
   makeArray(LSStandard, standardArray, stdMax);
   makeArray(LSTest, testArray, testMax);

   while (testIndex <= stdMax)
   {
      testValue = standardArray[testIndex];
      foundIndex = searchList(testArray, testMax, testValue);

      // if the value cannot be found
      if (foundIndex == -1)
      {
         std::cout << "Number " << (++testIndex) << " (" << std::setw(3) << testValue << ") was not in the file.";
         std::cout << std::endl;
      } // end if statement

      // if the value is found
      else
      {
         std::cout << "Number " << (++testIndex) << " (" << std::setw(3) << testValue << ") was located at index ";
         std::cout << foundIndex << "." << std::endl;
      } // end else statement
   } // end while loop


   // closes the files
   LSTest.close();
   LSStandard.close();

   return 0;
}