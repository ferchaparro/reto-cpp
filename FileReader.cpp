#include "Empleado.cpp"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class FileReader
{

public:
    FileReader() {

    }

    Empleado* read() {
        fstream newfile;
        Empleado* employees = new Empleado[15];
        newfile.open("c:\\empleados.txt", ios::in);
        if (newfile.is_open()) {
            string line;
            int i = 0;
            while (getline(newfile, line)) {
                size_t find = line.find("|");
                if (!line.empty() && find>=0 && find < 1000) {
                    string nombre = line.substr(0, find);
                    double sueldo = stod(line.substr(find + 1));
                    employees[i] = Empleado(nombre, sueldo, sueldo >= 5000 ? sueldo * 1.1 : sueldo * 1.15);
                    i++;
                    if (i >= 15) {
                        break;
                    }
                }
                
            }
        }
        newfile.close();
        return employees;

    }
};