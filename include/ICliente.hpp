#ifndef _ICLIENTE_HPP
#define _ICLIENTE_HPP

//Librerias de C
using namespace std;

class ICliente {
protected:
	ICliente();
public:
	virtual void ingresarTelefono(int telefono) = 0;
    ~ICliente();
};

#endif
