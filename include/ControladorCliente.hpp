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
	//instancia patron Singleton
	static ControladorCliente *instance;
	//Constructor
	ControladorCliente();
	//coleccion de clientes -- pseudoatributo
	map<int, Cliente *> clientes;
public:
	//operacion patron singleton
	static ControladorCliente *getInstance();
	
};

#endif
