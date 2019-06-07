#ifndef _FABRICA_HPP
#define _FABRICA_HPP

//Librerias de C
using namespace std;

//Archivos
#include "include/ICliente"
#include "include/IEmpleado"
#include "include/IFactura"
#include "include/IMesa"
#include "include/IProducto"
#include "include/IVenta"

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
	IFactura getIFactura();
	IMesa getIMesa();
	IProducto getIProducto();
	IVenta getIVenta();

}

#endif