#ifndef _DTMOZO_HPP
#define _DTMOZO_HPP

//Librerias de C
#include <string>
#include <iostream>
using namespace std;

//Archivos
#include "DtEmpleado.hpp"

class DtMozo: public DtEmpleado {
private:

public:
	//Constructor
	DtMozo();
    DtMozo(int numero, string nombre);

	//Destructor
    ~DtMozo();
};\

//Sobrecarga operador cout
ostream& operator<<(ostream &, DtMozo);

#endif
