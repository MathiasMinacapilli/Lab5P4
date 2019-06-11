#ifndef _CONTROLADORCLIENTE_HPP
#define _CONTROLADORCLIENTE_HPP

//Librerias de C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "Cliente.hpp"
#include "ICliente.hpp"
#include "DtCliente.hpp"

class ControladorCliente : public ICliente {
private:
	//instancia patron Singleton
	static ControladorCliente *instance;
	//Constructor
	ControladorCliente();
	//coleccion de clientes -- pseudoatributo
	set<Cliente *> clientes;
	//atributos recordados
	string telefono_recordado;
	string nombre_recordado;
	DtDireccion direccion_recordada;

public:
	//operacion patron singleton
	static ControladorCliente *getInstance();

	set<Cliente *> getClientes();
	bool existeCliente(string telefono);

	//caso de uso Alta Cliente
	void ingresarDatosCliente(string telefono, string nombre, DtDireccion direccion);
	DtCliente getDatosIngresados();
	void ingresarCliente();
	void cancelarCliente();

};

#endif
