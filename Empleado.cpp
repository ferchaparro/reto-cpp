#include <string>

using namespace std;


class Empleado
{

private:
	string nombre;
	double sueldo;
	double sueldoAumento;
public:
	Empleado() {
		nombre = "";
		sueldo = 0;
		sueldoAumento = 0;
	}
	Empleado(string nombre, double sueldo, double sueldoAumento) {
		this->nombre = nombre;
		this->sueldo = sueldo;
		this->sueldoAumento = sueldoAumento;
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

	double getSueldoAumento() {
		return sueldoAumento;
	}
	void setSueldoAumento(double sueldoAumento) {
		this->sueldoAumento = sueldoAumento;
	}

};

