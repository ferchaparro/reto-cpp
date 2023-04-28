#include <string>

using namespace std;

class Employee
{

private:
	string name;
	double salary;
	double newSalary;
public:
	Employee(string name, double salary, double newSalary) {
		this->name = name;
		this->salary = salary;
		this->newSalary = newSalary;
	}

	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}

	double getSalary() {
		return salary;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}

	double getNewSalary() {
		return newSalary;
	}
	void setNewSalary(double newSalary) {
		this->newSalary = newSalary;
	}

};

