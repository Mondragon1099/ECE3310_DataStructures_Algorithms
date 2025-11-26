// Class_4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
void swap(int* x, int* y);
struct Person {
int age;
string name;
};
int main()
{
int x = 10;
int* xptr = &x;
cout << endl << "Pointer value: " << xptr << " and Pointed value: " << *xptr;
//cout << endl << "Next Pointer value: " << (xptr + 1);
int y = 20;
int* yptr = &y;
cout << endl << " x + y = " << *xptr + *yptr;
cout << endl << " x and y before swap: " << x << " " << y;
//swap(&x, &y);
int* tmp_ptr = xptr;
xptr = yptr;
yptr = tmp_ptr;
cout << endl << " x and y after swap: " << *xptr << " " << *yptr;
struct Person some_person;
Person* some_person_ptr = & some_person;
some_person_ptr->age = 25;
some_person_ptr->name = "Bob";
Person array_of_persons[3];
cout << endl;
for (int i = 0; i < 3; i++) {
cout << "set the name for person " << i + 1 << " : ";
cin >> array_of_persons[i].name;
cout << endl << "set the age for person " << i + 1 << " : ";
cin >> array_of_persons[i].age;
}
for (int i = 0; i < 3; i++) {
cout << endl << "Name for person " << i + 1 << " : "<<
array_of_persons[i].name;
cout << endl << "Name for person " << i + 1 << " : "<<
array_of_persons[i].age;
}
}
void swap(int* a, int* b) {
int tmp_ptr = *a;
*a = *b;
*b = tmp_ptr;
}
