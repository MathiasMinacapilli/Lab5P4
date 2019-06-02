#ifndef _CONTROLADORCLIENTE_HPP
#define _CONTROLADORCLIENTE_HPP

//Librerias de C
using namespace std;
#include <map>

//Archivos
#include "Cliente.hpp"
#include "ICliente.hpp"

class ControladorCliente : public ICliente {
private:
	static ControladorCliente *instance;
	ControladorCliente();
	map<int, Cliente *> clientes;

};

#endif
