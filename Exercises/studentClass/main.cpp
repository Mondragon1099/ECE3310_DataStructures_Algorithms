//// Class6_sec2.cpp : This file contains the 'main' function. Program execution begins and ends there.
////

#include <iostream>


using namespace std;

#include "Student.h"

Student dummy_function(Student t);

int main()
{
    Student s0;
    
    Student s1("Johnny",32); // Student class has a default constructor with 2 arguments

    Student s2 = s1; //Use of copy constructor

    cin >> s0;
    
    cin >> s2; 



    Student s3; //default constructor with no arguments used for s3

    s3 = dummy_function(s1); // Assigning the result of print_student to s3, using the Assignment operator

    cout << s3.get_age(); //print on the standard output stream using the regular print on basic data types

    cout << s3; //print on the standard output stream using the redefined output operator

    return 0;
}

Student dummy_function(Student t) {
    


    t.set_age(30); // Assuming set_age() is a method of Student class to change the age

    return t; // Return the modified student object
}