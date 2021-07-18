/************************************

   Author:         Daniel Stanev
   Course:         CS1336.501
   Date:           21 Sep 2020
   Assignment:     Homework #3 Exercise #1
   Compiler:       MinGW-w64

 *************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string monthOne, monthTwo, monthThree; // create variables to store the month names

    double rainOne, rainTwo, rainThree; // create variables to store the rainfalls

    // prompts the user to enter the name and rainfall of month 1
    cout << "Please enter the name of month 1: ";
    cin >> monthOne;
    cout << "Please enter the rainfall for " << monthOne << ": ";
    cin >> rainOne;

    // prompts the user to enter the name and rainfall of month 2
    cout << "\nPlease enter the name of month 2: ";
    cin >> monthTwo;
    cout << "Please enter the rainfall for " << monthTwo << ": ";
    cin >> rainTwo;

    // prompts the user to enter the name and rainfall of month 3
    cout << "\nPlease enter the name of month 3: ";
    cin >> monthThree;
    cout << "Please enter the rainfall for " << monthThree << ": ";
    cin >> rainThree;

    // calculates and prints the average rainfall of the 3 months
    double average = (rainOne + rainTwo + rainThree) / 3;
    cout << "\nThe average rainfall for " << monthOne << ", " << monthTwo << ", and " << monthThree << " was " << average << " inches.";

    // calculates the length of each string
    int lengthOne = monthOne.length();
    int lengthTwo = monthTwo.length();
    int lengthThree = monthThree.length();

    // prints the length of each string
    cout << "\nThe length of \"" << monthOne << "\" is:" << setw(11 - lengthOne) << lengthOne << " characters";
    cout << "\nThe length of \"" << monthTwo << "\" is:"<< setw(11 - lengthTwo) << lengthTwo << " characters";
    cout << "\nThe length of \"" << monthThree << "\" is:"<< setw(11 - lengthThree)<< lengthThree << " characters";

    return 0;
} // end main method