/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           4 Nov 2020
   Assignment:     Homework #8 Exercise #1
   Compiler:       MinGW-w64

   Description: Takes in 5 different
   test grades, finds and drops the
   lowest and then calculates the
   average.

 *************************************/

#include <iostream>
#include <iomanip>

void getScore(int& score)
{
   // input validation loop
   while(score < 0  || score > 100)
   {
      std::cout << "please enter a test score between 0 and 100: ";
      std::cin >> score;
      if (score < 0  || score > 100)
      {
         std::cout << "That score is not valid, please try again." << std::endl;
      } // end if statement
   } // end while loop
} // end function getScore

int findLowest(int score1, int score2, int score3, int score4, int score5)
{
   int min = score1;

   // filters out for min
   if (score2 < min)
      min = score2;
   if (score3 < min)
      min = score3;
   if (score4 < min)
      min = score4;
   if (score5 < min)
      min = score5;

   return min;
} // end function findLowest

// calculates average and outputs a report
void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
   int min = findLowest(score1, score2, score3, score4, score5);
   double average;

   // calculates average
   average = (double(score1 + score2 + score3 + score4 + score5 - min)  /  4);

   // outputs a report to the console
   std::cout << std::fixed << std::setprecision(2);
   std::cout << std::endl;
   std::cout << "The lowest test is dropped from being calculated from the average." << std::endl;
   std::cout << "Dropped grade: " << min << std::endl;
   std::cout << "Average:       " << average << std::endl;
} // end function calcAverage

int main()
{
   int score1 = -1, score2 = -1, score3 = -1, score4 = -1, score5 = -1;

   // gets all 5 scores
   getScore(score1);
   getScore(score2);
   getScore(score3);
   getScore(score4);
   getScore(score5);

   calcAverage(score1, score2, score3, score4, score5);

   return 0;
} // end main method