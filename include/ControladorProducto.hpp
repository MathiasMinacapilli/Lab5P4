#ifndef _CONTROLADORPRODUCTO_HPP
#define _CONTROLADORPRODUCTO_HPP

//Librerias de C
#include <map>
#include <string>
using namespace std;

//Archivos
#include "IProducto.hpp"
#include "ProductoSimple.hpp"
#include "DtProducto.hpp"
#include "Menu.hpp"
#include "Producto.hpp"
#include "DtProductoSimple.hpp"
#include "DtMenu.hpp"
#include "DtProductoEnMenu.hpp"
#include "ControladorVenta.hpp"

class ControladorProducto : public IProducto {
private:
	//instancia del singleton y constructor privado
	static ControladorProducto *instance;
	ControladorProducto();
	//pseudoatributos que representan colecciones de productos simples y menus
	map<int, ProductoSimple *> productosSimples;
	map<int, Menu *> menus;
	//atributos de cosas que debe recordar
	DtProductoSimple datos_prod_simple; //ingresarDatosProductoSimple
	int codigo_menu;//ingresarMenu
	string desc_menu; //ingresarMenu
	map<int, DtProductoCantidad> prod_cants_recordados; //seleccionarProductoYCantidad
	Producto *producto_recordado; //seleccionarProducto
	int codigoProductoAConsultar;

public:
	//operacion patron singleton
	static ControladorProducto *getInstance();

	//operaciones de la clase
	//caso de uso: alta producto
	bool existeProductoSimple();
	void ingresarDatosProducto(DtProductoSimple datos);
	void ingresarProductoSimple();
	void cancelarProductoSimple();
	void ingresarDatosMenu(int codigo, string desc);
	map<int, DtProducto> getProductosSimples();
	void seleccionarProductoYCantidad (DtProductoCantidad producto_cantidad);
	void ingresarMenu();
	void cancelarMenu();

	//caso de uso: baja producto
	map<int, DtProducto> getProductosDisponibles();
	void seleccionarProducto(int codigo_producto);
	bool eliminarProducto();
	void cancelarBajaProducto();
	//baja producto -- eliminar() en ProductoSimple
	void eliminarProductoDeMenu(int cod);

	//caso de uso: agregar producto a venta -- seleccionarProdYCant
	Producto* encontrarProducto(DtProductoCantidad producto_cantidad);

	//caso de uso: informacion de un producto
	bool ingresarCodigoProductoAConsultar(int codigo);
    void cancelarInformacion();
    DtProducto getProducto();
    int getCantidadProductoTotalVendidos();

	void agregarProductoSimple(ProductoSimple *ps);
	void agregarMenu(Menu *menu);
	
};


#endif
