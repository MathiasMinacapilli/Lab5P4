//Librerias de C
using namespace std;

//Archivos
#include "../include/Fabrica.hpp"

Fabrica *Fabrica::instance = nullptr;

Fabrica::Fabrica(){}

Fabrica *Fabrica::getInstance(){
	if (instance == nullptr)
		instance = new Fabrica();
	return instance; 
}

ICliente *Fabrica::getICliente(){
	return ControladorCliente::getInstance();
}

IEmpleado *Fabrica::getIEmpleado(){
	return ControladorEmpleado::getInstance();
}

IMesa *Fabrica::getIMesa(){
	return ControladorMesa::getInstance();
}

IProducto *Fabrica::getIProducto(){
	return ControladorProducto::getInstance();
}

IVenta *Fabrica::getIVenta(){
	return ControladorVenta::getInstance();
}