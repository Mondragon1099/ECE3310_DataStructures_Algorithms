#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Car
{
private:
	string make;
	string model;
	int* year_last_service;

public:
	Car(string make = "NA", string model = "NA") {
		this->make = make;
		this->model = model;
		year_last_service = new int;
		*year_last_service = 1940; //1940 default
	}



	Car& operator=(const Car& right_obj) {
		cout << endl << "Assignment operator is being called now...";

		if (this != &right_obj) {     //avoiding self-reference, like x = x;
			delete year_last_service; //deallocation for safety
			make = right_obj.make;
			model = right_obj.model;
			year_last_service = new int; //new allocation
			*year_last_service = *(right_obj.year_last_service); //deep copy from right_obj to this object
		}
		return *this;
	}

	//-------------------------------------------METHODS TO BE IMPLEMENTED--------------------------------------

	~Car(); //DESTRUCTOR TO BE IMPLEMENTED

	Car(const Car& t); //COPY CONSTRUCTOR TO BE IMPLEMENTED

	bool operator==(const Car& t); //Assignment operator to be implemented

	void read(istream& in); //read function used for the redefinition of operator>>

	//---------------------------------------------------------------------------------------------------------


	void setMake(string a_make) {
		make = a_make;
	}

	void setModel(string a_model) {
		model = a_model;
	}

	void setService() {
		do {
			cout << endl << "Please provide year of last service for the car: ";
			cin >> *year_last_service;
		} while (*year_last_service < 1940 || *year_last_service > 2024);
	}


	void display(ostream& out) const {
		cout << endl << "Car make: " << make << " | Car model: " << model << " | Last serviced in: " << *year_last_service;
	}


};

std::ostream& operator<<(std::ostream& out, const Car& a) {
	a.display(out);
	return out;
}

std::istream& operator>>(istream& in, Car& a)
{
	a.read(in);
	return in;
}



//---------------------AREA MAIN FOR TESTING--------------------------------------


int main() {
	cout << "----- Testing Default Constructor and Display -----" << endl;
	Car car1; // Should initialize with default values ("NA", "NA")
	cout << "Car1: " << car1 << endl;

	cout << "\n----- Testing Input (operator>>) -----" << endl;
	cout << "Enter details for Car2 (make model year_last_service):" << endl;
	Car car2;
	cin >> car2;  // Calls the read function � try entering valid values
	cout << "Car2: " << car2 << endl;

	cout << "\n----- Testing Copy Constructor -----" << endl;
	Car car3(car2); // Uses copy constructor to create a copy of Car2
	cout << "Car3 (copy of Car2): " << car3 << endl;

	cout << "\n----- Testing Assignment Operator -----" << endl;
	Car car4;
	car4 = car2;  // Uses assignment operator to copy Car2's data to Car4
	cout << "Car4 (assigned from Car2): " << car4 << endl;

	cout << "\n----- Testing Equality Operator (operator==) -----" << endl;
	if (car2 == car3)
		cout << "Car2 and Car3 are equal." << endl;
	else
		cout << "Car2 and Car3 are not equal." << endl;

	if (car1 == car2)
		cout << "Car1 and Car2 are equal." << endl;
	else
		cout << "Car1 and Car2 are not equal." << endl;

	cout << "\n----- Testing Setter Functions and setService -----" << endl;
	car1.setMake("Toyota");
	car1.setModel("Camry");
	cout << "For Car1, update the service year:" << endl;
	car1.setService();  // Prompts for a valid service year
	cout << "Updated Car1: " << car1 << endl;

	// End of main will call destructors for all objects.
	return 0;
}

//---------------------FUNCTIONS TO BE COMPLETED (CURRENTLY EMPTY)--------------------------------------
// Destructor
Car::~Car() {
	cout << "Calling car destructor now" << endl;
    delete year_last_service;
}

// Copy constructor
Car::Car(const Car& t) {
    cout << "Calling car copy constructor now" << endl;

    make = t.make;
    model = t.model;
    year_last_service = new int;
    *year_last_service = *t.year_last_service;

}

// Equality operator
bool Car::operator==(const Car& t) {
    if (make == t.make) {
        return true;
    }
    else {
        return false;
    }

    if (model == t.model) {
        return true;
    }
    else {
        return false;
    }

    if (year_last_service == t.year_last_service) {
        return true;
    }
    else {
        return false;
    }

}

// read function for operator>>
void Car::read(istream& in) {
    cout << "Provide make: ";
    in >> make;
    cout << "Provide model: ";
    in >> model;
    cout << "Provide last year of service: "; 
    in >> *year_last_service;

}
