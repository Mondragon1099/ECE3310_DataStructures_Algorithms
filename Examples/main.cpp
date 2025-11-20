#include <iostream>
using namespace std;

int main() {

int x = 7;

int * x_ptr = &x;

*x_ptr = 10;

*x_ptr = *x_ptr + x;

printf("%d", x);


    return 0;
}