#include <string>

using namespace std;


class Empleado
{

private:
	string nombre;
	double sueldo;
public:
	Empleado() {
		nombre = "";
		sueldo = 0;
	}
	Empleado(string nombre, double sueldo) {
		this->nombre = nombre;
		this->sueldo = sueldo;
	}

	string getNombre() {
		return nombre;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}

	double getSueldo() {
		return sueldo;
	}
	void setSueldo(double sueldo) {
		this->sueldo = sueldo;
	}









};

