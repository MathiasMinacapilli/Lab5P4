#ifndef _CONTROLADORCLIENTE_HPP
#define _CONTROLADORCLIENTE_HPP

//Librerias de C
using namespace std;

//Archivos
#include "Cliente.hpp"

class ControladorCliente {
private:
	static ControladorCliente *instance;
	ControladorCliente();
	map<int, Cliente *> clientes;
public:
    ~ControladorCliente() {};
};

#endif
