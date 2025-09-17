#include <iostream>
using namespace std;
//function to swap two variables passed by reference
void swap(int&, int&);
struct Results {
int sum;
int reminder;
int multiplication;
};
//function having multiple outputs: passed as output parameter by reference, returned as a structure (redundant)
Results a_function(const int, const int, int&, int&, int&);
int main()
{
bool h = true;
cout << "Boolean variable h is: "<<boolalpha<< h <<"\n";
int j;
float k;
char l;
printf("Input in the order: an integer, a float, a character \n");
scanf_s("%d", &j);
scanf_s("%f", &k);
scanf_s(" %c", &l);
printf("you wrote %10.5d, %10.5f, %10.5c", j, k, l);
int x = 3, y = 11;
cout << endl << "x: " << x << " y: " << y;
swap(x, y);
cout << endl << "x: " << x << " y: " << y;
Results some_struct;
int sum, multiplication, reminder;
some_struct = a_function(x, y, sum, multiplication, reminder);
cout << endl << "sum: "<<sum << " multiplication: " << multiplication << " reminder: " << reminder;
cout << endl << "sum: " << some_struct.sum << " multiplication: " <<
some_struct.multiplication << " reminder: " << some_struct.reminder;
}
void swap(int& a, int& b) {
int temp = a;
a = b;
b = temp;
}
Results a_function(const int x1, const int x2, int& sum , int& mult, int& rem) {
sum = x1 + x2;
mult = x1 * x2;
rem = (x2 != 0) ? x1%x2 : 0;
Results temp;
temp.sum = sum;
temp.reminder = rem;
temp.multiplication = mult;
return temp;
}