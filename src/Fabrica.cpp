//Librerias de C
using namespace std;

//Archivos
#include "../include/Fabrica.hpp"


class Fabrica{
private:
	//instancia del patron Singleton
	static Fabrica *instance;
public:
	//funcion patron Singleton
	static Fabrica getInstance();

	//getters de las interfaces
	ICliente getICliente();
	IEmpleado getIEmpleado();
	IMesa getIMesa();
	IProducto getIProducto();
	IVenta getIVenta();

}

Fabrica Fabrica::getInstance(){
	if (instance == nullptr)
		instance = new Fabrica();
	return instance; 
}

ICliente Fabrica::getICliente(){
	return ControladorCliente::getInstance();
}

IEmpleado Fabrica::getIEmpleado(){
	return ControladorEmpleado::getInstance();
}

IMesa Fabrica::getIMesa(){
	return ControladorMesa::getInstance();
}

IVenta Fabrica::getIVenta(){
	return ControladorVenta::getInstance();
}