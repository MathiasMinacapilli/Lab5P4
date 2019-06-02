#include "../include/ControladorProducto.hpp";

ControladorProducto::ControladorProducto(){}

ControladorProducto ControladorProducto::getInstance(){
	if (instance == nullptr)
		instance = new ControladorProducto();
	return instance; 
}

