#ifndef _ICLIENTE_HPP
#define _ICLIENTE_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "DtApto.hpp"
#include "DtCliente.hpp"

class ICliente {
protected:
	//constructor -- protected porque es abstracta
	ICliente();
public:
	//caso de uso Alta Cliente
	virtual void ingresarDatosCliente(int telefono, string nombre, DtDireccion direccion) = 0;
	virtual DtCliente getDatosIngresados() = 0;
	virtual void ingresarCliente() = 0;
	virtual void cancelarCliente() = 0;

	//destructor
    ~ICliente();
};

#endif
