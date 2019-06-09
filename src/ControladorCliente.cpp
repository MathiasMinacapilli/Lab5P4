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
map <int, Cliente*> ControladorCliente::getClientes() {
	return this -> clientes;
}

bool ControladorCliente::existeCliente(int telefono) {
	map<int, Cliente*>::iterator it = clientes.find(telefono);
	return (it != clientes.end());
}


//ALTA CLIENTE
void ControladorCliente::ingresarDatosCliente(int telefono, string nombre, DtDireccion direccion){
	map<int, Cliente*>::iterator it = this->clientes.find(telefono);
	if (it == this->clientes.end()){
		this->telefono_recordado = telefono;
		this->nombre_recordado = nombre;
		this->direccion_recordada = direccion;
	}
	else throw new invalid_argument("Error. Ya existe un cliente con ese telefono ingresado en el sistema.");
}

void ControladorCliente::ingresarCliente(){
	set<DtActualizacion> actualizaciones;
	actualizaciones.clear();
	Cliente *nuevo_cliente = new Cliente(this->telefono_recordado, this->nombre_recordado, this->direccion_recordada, actualizaciones);
	this->clientes[this->telefono_recordado] = nuevo_cliente;
}

void ControladorCliente::cancelarCliente(){
	//SE LIBERA MEMORIA
	//QUE ES ESO
	//AYUDA
}

DtCliente ControladorCliente::getDatosIngresados(){
	set<DtActualizacion> actualizaciones;
	actualizaciones.clear();
	DtCliente datos = DtCliente(this->telefono_recordado, this->nombre_recordado, this->direccion_recordada, actualizaciones);
	return datos;
}


