#ifndef _CONTROLADORCLIENTE_HPP
#define _CONTROLADORCLIENTE_HPP

//Librerias de C
#include <map>
#include <string>
using namespace std;

//Archivos
#include "Cliente.hpp"
#include "ICliente.hpp"

class ControladorCliente : public ICliente {
private:
	int telefono;
	//instancia patron Singleton
	static ControladorCliente *instance;
	//Constructor
	ControladorCliente();
	//coleccion de clientes -- pseudoatributo
	map<int, Cliente *> clientes;
public:
	//operacion patron singleton
	void ingresarTelefono(int telefono);
	static ControladorCliente *getInstance();

};

#endif
