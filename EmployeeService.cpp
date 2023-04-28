#include <vector>
#include <sstream>
#include <iomanip>
#include <codecvt>
#include "EmployeeMapper.cpp"
#include "FileReader.cpp"

class EmployeeService {
public:
	vector<Employee> getEmployeesData(const char * fileName = "c:\\empleados.txt") {
		vector<pair<string, double>> fileData = FileReader::read(fileName);
		vector<Employee> employees;
		for (const auto& data : fileData) {
			employees.push_back(EmployeeMapper::mapToEmployee(data, 5000, 1.1, 1.15));
		}
		return employees;
	}

	string currencyFormat(double number) {
		std::stringstream stream;
		stream.imbue(std::locale(""));
		stream << std::fixed << std::setprecision(2) << number;
		string currency = stream.str();
		stream.clear();
		stream.flush();
		return stream.str();
	}

	wstring parseString(string row) {
		wstring_convert<codecvt_utf8<wchar_t>> converter;
		return converter.from_bytes(row);
	}
};