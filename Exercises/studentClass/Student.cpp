#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "Student.h"

Student::Student() {

	name = "No Name";
	age = 0;
	ID = "No ID assigned";

	grades = new int[NUMBER_OF_EXAMS];

	for (int i = 0; i < NUMBER_OF_EXAMS; i++) grades[i] = -1; //default grade for each exam is -1


	cout << endl << "Constructor with no arguments is called";
}



Student::Student(string some_name, int some_age): Student(){
	
	name = some_name;
	age = some_age;

	cout << endl << "Constructor with 2 arguments is called";

}



Student::Student(Student& t) {
	cout << endl << "Copy constructor 1 is called...";
	
	name = t.name;
	age = t.age;
	ID = t.ID;
	
	grades = new int[NUMBER_OF_EXAMS];

	for (int i = 0; i < NUMBER_OF_EXAMS; i++) {
		grades[i] = t.grades[i];
	}

}



Student::~Student() {
	cout << endl << "destructor is being called now...";
	
	delete[] grades;

}

bool Student::operator==(const Student& t) {
	
		if (ID == t.ID) //we assume two students are the same if they have the same ID
			return true;
		return false;
	
}


Student& Student::operator=(const Student& t) {

	cout << endl << "Assignment operator is being called now...";

	if (this != &t) {     //avoiding self-reference, like x = x;
		delete[] grades; 
		name = t.name;
		age = t.age;
		ID = t.ID;
		grades = new int[NUMBER_OF_EXAMS]; //new allocation
		for (int i = 0; i < NUMBER_OF_EXAMS; i++) grades[i] = t.grades[i]; //deep copy
	}
	
	return *this;
}



string Student::get_name() {
	return name;
}

int Student::get_age() {
	return age;
}

void Student::set_age(const int some_age) {
	age = some_age;
}
void Student::set_name(const string some_name) {
	name = some_name;
}


/***** Input/Output *****/
void Student::display(ostream& out) const {
	out << endl<< "Student Name: "<< name 
		<< " - Student ID: " << ID
		<< " - Student age: " << age;
}

void Student::read(istream& in)
{

	string some_name = "-",    // Local variables to hold input values from in so
		some_id = "-";  //    they can be checked against the class invariant
	unsigned int some_age = 0;       
	

	cout << endl << "Provide details of student. ";
	cout << endl << "Full Name: ";
		
	getline(in, some_name); //requires #include <string>

	cout << endl << "ID: ";
	getline(in, some_id);
	
	cout << endl << "Age: "; 
	in >> age;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //required to ignore the return pressed to enter previous input(needs #include <limits>)


	// Check the class invariant (here only age not negative or too large
	if ((0<age) && (age<100))
	{
		age = some_age;
		ID = some_id;
		name = some_name;
	}
	else
		cerr << "*** Invalid input for Student object. Age must be in range 0-100 ***\n"; //program quits here
}


std::ostream& operator<<(std::ostream& out, const Student& a) {
	a.display(out);
	return out;
}

std::istream& operator>>(istream& in, Student& a)
{
	a.read(in);
	return in;
}