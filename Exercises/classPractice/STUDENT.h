#include <string>
#ifndef STUDENT_H //prevents multiple class definitions
#define STUDENT_H

using namespace std;

class STUDENT {
    public:
    //constructor with 0 arguments
    STUDENT();

    // overloaded constuctor with 3 arguments
    STUDENT(string name, int age, string ID);

    private:
    string name;
    int age;
    string ID;

};
#endif 