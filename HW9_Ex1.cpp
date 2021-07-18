/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           17 Nov 2020
   Assignment:     Homework #9 Exercise #1
   Compiler:       MinGW-w64

   Description: finds a goldbach
   partition of all even integers
   between 4 and 100

   Bonus 1: 3 prime numbers that add
   up to each number between 5 and 100

   Bonus 2: finds all of the golbach
   partitions for all even integers
   between 4 and 100, and then prints
   out which integer had the most
   partitions

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
} // end method isPrime

// finds the next prime number
int findNextPrime(int num)
{
   while (true)
   {
      num++;
      if(isPrime(num))
         break;
   } // end while loop
   return num;
} // end method findNextPrime

// method golbachPartition
void goldbachPartition(int num)
{
   int prime1, prime2;
   for (int check = 4; check <= num; check += 2)
   {
      prime1 = 2;
      prime2 = check - prime1;
      while(true)
      {
         if(isPrime(prime1) && isPrime(prime2))
            break;
         else
         {
            prime1++;
            prime2--;
         } // end else statement
      } // end while loop
      std::cout << "Even integer" << std::setw(4) << check << " =" << std::setw(4) << prime1 << " +" << std::setw(4) << prime2 << std::endl;
   } // end for loop
} // end method goldbachPartition

// method bonus1
void bonus1(int num)
{
   int prime1, prime2, prime3;
   for (int check = 6; check <= num; check++)
   {
      // resets variables each iteration
      // fun side note, it isn't necessary to reset the variables until check = 100
      prime1 = 2;
      prime2 = 2;
      prime3 = 2;
      while(true)
      {
         if (prime1 + prime2 + prime3 == check)
            break;
         else if (prime3 - (prime1 + prime2) > check)
         {
            prime3 = 2;
            prime2 = findNextPrime(prime2);
            continue;
         } // end else if statement
         else if (prime2 - (prime1 + prime3) > check)
         {
            prime2 = 2;
            prime3 = 2;
            prime1 = findNextPrime(prime1);
         } // end else if statement
         else
         {
            prime3 = findNextPrime(prime3);
         } // end else statement
      } // end while loop
      std::cout << "Integer" << std::setw(4) << check << " =";
      std::cout << std::setw(4) << prime1 << " +" << std::setw(4) << prime2 << " +" << std::setw(4) << prime3 << std::endl;
   } // end for loop
} // end method bonus1

// method bonus2
void bonus2(int num)
{
   int prime1, prime2, numPartitions = 0, partitionsCheck = 0, highestPartitions = 0;
   bool firstPartition = true;
   for (int check = 4; check <= num; check += 2)
   {
      std::cout << "Even integer" << std::setw(4) << check << " =";
      prime1 = 2;
      prime2 = check - prime1;
      while (true)
      {
         if (prime1 > prime2)
            break;
         if(isPrime(prime1) && isPrime(prime2))
         {
            if(firstPartition)
            {
               firstPartition = false;
               std::cout << std::setw(4) << prime1 << " +" << std::setw(4) << prime2;
            } // end if statement
            else
            {
               std::cout << "," << std::setw(4) << prime1 << " +" << std::setw(4) << prime2;
            } // end else statement
            partitionsCheck++;
         } // end if statement
         prime1++;
         prime2--;
      } // while loop
      firstPartition = true;
      if (partitionsCheck > numPartitions)
      {
         numPartitions = partitionsCheck;
         highestPartitions = check;
      } // end if statement
      partitionsCheck = 0;
      std::cout << std::endl;
   } // end for loop
   std::cout << "The number with the highest number of Goldbach partitions is " << highestPartitions << " with " << numPartitions << " partitions" << std::endl;
} // end method bonus2

int main()
{
   goldbachPartition(100);
   bonus1(100);
   bonus2(100);


   return 0;
} // end main method