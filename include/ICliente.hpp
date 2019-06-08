#ifndef _ICLIENTE_HPP
#define _ICLIENTE_HPP

//Librerias de C
#include <string>
using namespace std;

class ICliente {
protected:
	ICliente();
public:
	virtual void ingresarTelefono(string telefono) = 0;
    ~ICliente();
};

#endif
