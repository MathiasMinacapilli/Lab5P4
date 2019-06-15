//Archivos
#include "../include/ControladorCliente.hpp"

//instancia patron Singleton
ControladorCliente *ControladorCliente::instance = nullptr;

//Constructor por defecto
ControladorCliente::ControladorCliente(){}

//operacion getInstance de patron Singleton
ControladorCliente *ControladorCliente::getInstance(){
	if (instance == nullptr)
		instance = new ControladorCliente();
	return instance;
}


//devuelve la coleccion de clientes
set<Cliente *> ControladorCliente::getClientes() {
	return this -> clientes;
}

bool ControladorCliente::existeCliente(string telefono) {
	set<Cliente *>::iterator it;
	bool encontre = false;
	for (it = this->clientes.begin(); it != this->clientes.end() && !encontre; ++it){
		Cliente *cliente = *it;
		encontre = (cliente->getTelefono() == telefono);
	}
	return encontre;
}


//ALTA CLIENTE
void ControladorCliente::ingresarDatosCliente(string telefono, string nombre, DtDireccion direccion){
	if (! (this->existeCliente(telefono)) ){
		this->telefono_recordado = telefono;
		this->nombre_recordado = nombre;
		this->direccion_recordada = direccion;
	}
	else throw new invalid_argument("Error. Ya existe un cliente con ese telefono ingresado en el sistema.");
}

void ControladorCliente::ingresarCliente(){
	vector<DtActualizacion> actualizaciones;
	actualizaciones.clear();
	Cliente *nuevo_cliente = new Cliente(this->telefono_recordado, this->nombre_recordado, this->direccion_recordada, actualizaciones);
	clientes.insert(nuevo_cliente);
	this->telefono_recordado = ' ';
}

void ControladorCliente::cancelarCliente(){
	this->telefono_recordado = "no valido";
	this->nombre_recordado = "no valido";
}

DtCliente ControladorCliente::getDatosIngresados(){
	set<DtActualizacion> actualizaciones;
	actualizaciones.clear();
	DtCliente datos = DtCliente(this->telefono_recordado, this->nombre_recordado, this->direccion_recordada, actualizaciones);
	return datos;
}

Cliente* ControladorCliente::getCliente(string telefono) {
	set<Cliente *>::iterator it;
	Cliente *cliente;
	bool encontre = false;
	for (it = this -> clientes.begin(); it != this -> clientes.end() && !encontre; ++it){
		cliente = *it;
		encontre = (cliente -> getTelefono() == telefono);
	}
	if (encontre)
		return cliente;
	else
		throw new invalid_argument ("No existe un cliente con ese número. ");
}
