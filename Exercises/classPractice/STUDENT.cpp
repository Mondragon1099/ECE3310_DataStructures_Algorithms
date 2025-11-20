#include "STUDENT.h"
#include <iostream>


STUDENT::STUDENT() { //Default constructor
    this->name = "NPC";
    this->ID = "100";
    this->age = 10;
}

STUDENT::STUDENT(string name, int age, string ID)
{
    this->name = name;
    this->age = age;
    this->ID = ID;
}