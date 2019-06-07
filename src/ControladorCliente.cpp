//Archivos
#include "../include/ControladorCliente.hpp"

ControladorCliente::ControladorCliente(){}

ControladorCliente *ControladorCliente::getInstance(){
	if (instance == nullptr)
		instance = new ControladorCliente();
	return instance; 
}

