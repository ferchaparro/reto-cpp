#include <string>
#include <vector>
#include "Employee.cpp"

using namespace std;

class EmployeeMapper {
public:
	static Employee mapToEmployee(pair<string, double> data, double geAmount, double geFactor, double ltFactor) {
		double increment = data.second >= geAmount ? data.second * geFactor : data.second * ltFactor;
		return Employee(data.first, data.second, increment);
	}
};