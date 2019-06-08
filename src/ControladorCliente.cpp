//Archivos
#include "../include/ControladorCliente.hpp"

ControladorCliente *ControladorCliente::instance = nullptr;

ControladorCliente::ControladorCliente(){}

ControladorCliente *ControladorCliente::getInstance(){
	if (instance == nullptr)
		instance = new ControladorCliente();
	return instance;
}

void ControladorCliente::ingresarTelefono(string telefono) {
	this -> telefono = telefono;
}

map <int, Cliente*> ControladorCliente::getClientes() {
	return this -> clientes;
}
