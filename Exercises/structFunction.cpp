// Class_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
struct results {
int multiplication = 0;
int reminder = 0;
int sum = 0;
};
results operations(const int& x, const int& y, int& multiplicaiton, int& reminder,
int& sum);
int main()
{
int a = 5, b = 3, multip =0 , remind=0, add=0;
results results_in_struct;
results_in_struct = operations(a, b, multip, remind, add);
cout << endl << "Result of multiplication between " << a << " and " << b << " is " << results_in_struct.multiplication;
cout << endl << "Result of multiplication between " << a << " and " << b << " is " << multip;
return 0;
}
results operations(const int& x, const int& y, int& mult, int& reminder, int& sum)
{
results temp_results;
mult = x * y;
temp_results.multiplication = mult;
reminder = x % y;
temp_results.reminder = reminder;
sum = x + y;
temp_results.sum = sum;
return temp_results;
}