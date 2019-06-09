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

void ControladorCliente::ingresarTelefono(int telefono) {
	this -> telefono = telefono;
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
		this->telefono = telefono;
		this->nombre_recordado = nombre;
		this->direccion_recordada = direccion;
	}
	else throw new invalid_argument("Error. Ya existe un cliente con ese telefono ingresado en el sistema.");
}

DtCliente ControladorCliente::getDatosIngresados(){
	set<DtActualizacion>

}
