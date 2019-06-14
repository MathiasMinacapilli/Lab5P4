#ifndef _DTMOZO_HPP
#define _DTMOZO_HPP

//Librerias de C
#include <string>
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
};

#endif
