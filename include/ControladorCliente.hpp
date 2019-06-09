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
	//instancia patron Singleton
	static ControladorCliente *instance;
	//Constructor
	ControladorCliente();
	//coleccion de clientes -- pseudoatributo
	map<int, Cliente *> clientes;
	//atributos recordados
	int telefono;
	string nombre_recordado;
	DtDireccion direccion_recordada;

public:
	//operacion patron singleton
	static ControladorCliente *getInstance();

	void ingresarTelefono(int telefono);
	map <int, Cliente*> getClientes();

	//caso de uso Alta Cliente
	void ingresarDatosCliente(int telefono, string nombre, DtDireccion direccion);
	DtCliente getDatosIngresados();
	void ingresarCliente();
	void cancelarCliente();


};

#endif
