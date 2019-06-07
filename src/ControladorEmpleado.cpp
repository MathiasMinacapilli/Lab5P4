//Archivos
#include "../include/ControladorEmpleado.hpp"

ControladorEmpleado::ControladorEmpleado(){}

ControladorEmpleado *ControladorEmpleado::getInstance(){
	if (instance == nullptr)
		instance = new ControladorEmpleado();
	return instance; 
}

