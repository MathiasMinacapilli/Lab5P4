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
	//Instancia patrón Singleton
	static ControladorCliente *instance;
	//Constructor
	ControladorCliente();
	//Colección de Clientes -- Pseudoatributo
	set<Cliente *> clientes;
	//Atributos recordados
	string telefono_recordado;
	string nombre_recordado;
	DtDireccion direccion_recordada;

public:
	//Operación patrón stingleton
	static ControladorCliente *getInstance();

	set<Cliente *> getClientes();
	bool existeCliente(string telefono);

	//ALTA CLIENTE
	void ingresarDatosCliente(string telefono, string nombre, DtDireccion direccion);
	DtCliente getDatosIngresados();
	void ingresarCliente();
	void cancelarCliente();

	Cliente* getCliente(string telefono);

};

#endif
