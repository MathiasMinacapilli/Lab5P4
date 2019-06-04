#ifndef _CONTROLADORPRODUCTO_HPP
#define _CONTROLADORPRODUCTO_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "IProducto.hpp"
#include "ProductoSimple.hpp"
#include "Menu.hpp"
#include "Producto.hpp"
#include "DtProductoSimple.hpp"

class ControladorProducto : public IProducto {
private:
	//instancia del singleton y constructor privado
	static ControladorProducto *instance;
	ControladorProducto();
	//pseudoatributos que representan colecciones de productos simples y menus
	map<int, ProductoSimple *> productosSimples;
	map<int, Menu *> menus;
	//atributos de cosas que debe recordar
	DtProductoSimple datos_prod_simple;
	int codigo_menu, cantidad_recordada;
	string desc_menu; 
	map<int, DtProductoCantidad> prod_cants_recordados; 


public:
	//operacion patron singleton
	static ControladorProducto *getInstance();
	
	//operaciones de la clase
	bool existeProductoSimple();
	void ingresarDatosProducto(DtProductoSimple datos);
	void ingresarProductoSimple();
	void cancelarProductoSimple();
	void ingresarDatosMenu(int codigo, string desc);
	map<int, DtProductoSimple> getProductosSimples();
	void seleccionarProductoYCantidad (DtProductoCantidad producto_cantidad);
	void ingresarMenu();
	void cancelarMenu();
	
	bool eliminarProducto();
	void eliminarProductoDeMenu(int cod);
	void cancelarBajaProducto();
	
	Producto* encontrarProducto(DtProductoCantidad producto_cantidad);
	map<int, DtProducto> getProductosDisponibles();
	
	void seleccionarProducto(int codigo_producto);
	



}


#endif