

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   // creates variables the program will use
   double rate, principal, interest, saved;
   int numCompound;

   // prompts the user for variables
   cout << "Please enter the Principal: " << endl;
   cin >> principal;
   cout << "Please enter the Interest Rate: " << endl;
   cin >> rate;
   cout << "Please enter the Times Compounded: " << endl;
   cin >> numCompound;
   cout << endl;

   // calculates the amount saved and the total interest
   saved = principal * (pow (1 + (rate / numCompound), numCompound));
   interest = saved - principal;
   cout << fixed << setprecision(2);

   // prints a report out to the screen
   cout << "Interest Rate:        " << right << setw(10) << rate * 100 << "%" << endl;
   cout << "Times Compounded:     " << right << setw(11) << numCompound << endl;
   cout << "Principal:            " << right << setw(4) << "$ " << principal << endl;
   cout << "Interest:             " << right << setw(6) << "$ " << interest << endl;
   cout << "Amount in Savings:    " << right << setw(4) << "$ " << saved << endl;

   return 0;
}// end main method
