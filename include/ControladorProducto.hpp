#ifndef _CONTROLADORPRODUCTO_HPP
#define _CONTROLADORPRODUCTO_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "IProducto.hpp"
#include "ProductoSimple.hpp"
#include "Menu.hpp"

class ControladorProducto : public IProducto {
private:
	//instancia del singleton y constructor privado
	static ControladorProducto *instance;
	ControladorProducto();
	//pseudoatributos que representan colecciones de 
	map<int, ProductoSimple *> productosSimples;
	map<int, Menu *> menus;
public:
	//operacion patron singleton
	static ControladorProducto *getInstance();
	
	//operaciones de la clase
	void cancelarBajaProducto();
	void cancelarMenu();
	void cancelarProductoSimple();
	bool eliminarProducto();
	void eliminarProductoDeMenu(int cod);
	Producto* encontrarProducto(DtProductoCantidad producto_cantidad);
	bool existeProductoSimple();
	map<int, DtProducto> getProductosDisponibles();
	map<int, DtProductoSimple> getProductosSimples();
	void ingresarDatosProducto(DtProductoSimple datos);
	void ingresarProductoSimple();
	void ingresarDatosMenu(int codigo, string desc);
	void ingresarMenu();
	void seleccionarProducto(int codigo_producto);
	void seleccionarProductoYCantidad (DtProductoCantidad producto_cantidad);



}


#endif