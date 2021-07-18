/************************************

   Author:         Daniel Stanev
   Course:         CS1336.501
   Date:           21 Sep 2020
   Assignment:     Homework #3 Exercise #2
   Compiler:       MinGW-w64

 *************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
   double loan, rate, monPay, paidBack, interestPaid;
   int numPay;

   cout << "Please enter the loan amount in dollars : ";
   cin >> loan;
   cout << "Please enter the annual interest rate as a percentage: ";
   cin >> rate;
   cout << "Please enter the number of payments: ";
   cin >> numPay;

   rate = rate / 100; // converts the rate from a percentage to a decimal
   monPay = (loan) * ((rate * (pow((1+rate), numPay))) / ((pow((1 + rate), numPay)) -1) );
   interestPaid = 36 * (monPay - (loan / numPay));
   paidBack = loan + interestPaid;
   setprecision(2);

   cout << "Loan Amount:           " << right << setw(6) << "$ " << setw(9) << loan << endl;
   cout << "Monthly interest Rate: " << right << setw(13) << rate * 100 << " %" << endl;
   cout << "Number of Payments:    " << right << setw(6) << "$ " << setw(9) << numPay << endl;
   cout << "Monthly Payment:       " << right << setw(6) << "$ " << setw(9) << monPay << endl;
   cout << "Amount Paid Back:      " << right << setw(6) << "$ " << setw(9) << paidBack << endl;
   cout << "Interest Paid:         " << right << setw(6) << "$ " << setw(9) << interestPaid << endl;


   return 0;
} // end main method