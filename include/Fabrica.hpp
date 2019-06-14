#ifndef _FABRICA_HPP
#define _FABRICA_HPP

//Librerias de C
using namespace std;

//Archivos
#include "ControladorCliente.hpp"
#include "ControladorEmpleado.hpp"
#include "ControladorMesa.hpp"
#include "ControladorProducto.hpp"
#include "ControladorVenta.hpp"

class Fabrica{
private:
	//Instancia del patrón Singleton
	static Fabrica *instance;
	//Constructor
	Fabrica();
public:
	//Función patrón Singleton
	static Fabrica *getInstance();

	//Funciones de obtención de interfaces
	ICliente *getICliente();
	IEmpleado *getIEmpleado();
	IMesa *getIMesa();
	IProducto *getIProducto();
	IVenta *getIVenta();
};

#endif
