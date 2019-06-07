#ifndef _FABRICA_HPP
#define _FABRICA_HPP

//Librerias de C
using namespace std;

//Archivos
#include "include/ICliente.hpp"
#include "include/IEmpleado.hpp"
#include "include/IMesa.hpp"
#include "include/IProducto.hpp"
#include "include/IVenta.hpp"

class Fabrica{
private:
	//instancia del patron Singleton
	static Fabrica *instance;
	//constructor
	Fabrica();
public:
	//funcion patron Singleton
	static Fabrica getInstance();

	//obtener las interfaces
	ICliente getICliente();
	IEmpleado getIEmpleado();
	IMesa getIMesa();
	IProducto getIProducto();
	IVenta getIVenta();

}

#endif