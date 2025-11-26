// Class_1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
void swap(int&, int&);
int main()
{
int a = 1, b = 10;
cout << endl << "Before swap";
cout << endl << " a is " << a << " and b is " << b;
swap(a, b);
cout << endl << "After swap";
cout << endl << " a is " << a << " and b is "<<b;
}
void swap(int& x , int& y) {
int temp = x;
x = y;
y = temp;
}
