#include <iostream>
using namespace std;


#ifndef STUDENT
#define STUDENT

#define NUMBER_OF_EXAMS 20

class Student {
private:
	string name;
	int age;
	string ID;

	int* grades;


	//ostream& operator<<(ostream& out, const Student& c);
	

public:
	//constructor with no arguments
	Student();
	//constructor with 2 arguments
	Student(string some_name, int some_age);
	//copy constructor
	Student(Student& t); //Required for the Rule of 3
	//Destructor
	~Student(); //Required for the Rule of 3

	//Overloaded operators
	//Unary operators
	Student& operator=(const Student&);  //Required for the Rule of 3

	//Binary operators
	bool operator==(const Student&);


	
	/***** Input/Output *****/
	void display(ostream& out) const; //const after memeber functions guarantees that the functioin will not change the object 
	void read(istream& in);
	

	//Getters and Setters
	string get_name();
	int get_age();

	void set_age(const int some_age);
	void set_name(const string some_name);

};

//stream operators defined as global functions
//the functions need to rely on public member functions on the class Student
std::ostream& operator<<(std::ostream&, const Student& a);

std::istream& operator>>(istream& in, Student& t);


#endif