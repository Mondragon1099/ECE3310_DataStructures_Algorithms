/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
    Queue q1;
    cout << "Queue created. " << endl;

    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(-2);
    q1.enqueue(230);
    q1.enqueue(79);
    q1.enqueue(29);

    cout << endl << "Current elements in the queue: ";
    q1.display(cout);

    cout << endl << "Current size: " << q1.size();

    
}