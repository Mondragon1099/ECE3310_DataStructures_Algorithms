#include <iostream>
using namespace std;

// Create a program with a function that has an array as argument, but it doesn’t allow 
// any changes to the array elements, i.e., it can only read value of the array


void displayArray(const int sampleArray[], int size) {
    for(int i = 0; i < size; i++) {
        // sampleArray[i] = i; // causes error as the array is READONLY because of const modifier 
    
        cout << sampleArray[i] << " "; 

    }

}

int main()
{
    int SIZE = 3;
    int myArray[SIZE] = {3,4,5}; 

    cout << "Copy of the array: ";
    displayArray(myArray, SIZE);

    cout << endl;

    cout << "Orginal array values: ";

    for(int i = 0; i < SIZE; i ++) {
        cout << myArray[i] << " ";

    }
    cout << endl;

}
