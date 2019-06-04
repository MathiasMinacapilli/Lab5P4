#include "../include/ControladorProducto.hpp";

using namespace std;

ControladorProducto::ControladorProducto(){}

ControladorProducto ControladorProducto::getInstance(){
	if (instance == nullptr)
		instance = new ControladorProducto();
	return instance; 
}

bool ControladorProducto::existeProductoSimple(){
	return !productosSimples.empty();
}

void ControladorProducto::ingresarDatosProducto(DtProductoSimple datos){
	this->datos_prod_simple = datos;
}

void ControladorProducto::ingresarProductoSimple(){
	ProductoSimple *nuevo_prod_simple = new ProductoSimple(this->datos_prod_simple.getCodigo(), this->datos_prod_simple.getDescripcion(), this->datos_prod_simple.getPrecio());
	this->productosSimples[nuevo_prod_simple.getCodigo()] = nuevo_prod_simple;
}

void ControladorProducto::cancelarProductoSimple(){
}

void ControladorProducto::ingresarDatosMenu(int codigo, string desc){
	this->codigo_menu = codigo;
	this->desc_menu = desc;
}

map<int, DtProductoSimple> ControladorProducto::getProductosSimples(){
	map<int, DtProductoSimple> resultado; 
	map<int, ProductoSimple *>::iterator it;
	for (it = this->productosSimples.begin(); it != this->productosSimples.end(); ++it)
		resultado[it->second->getCodigo()] = it->second->getDatos();
	return resultado;
}

void ControladorProducto::seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad){
	this->prod_cants_recordados[DtProductoCantidad.getProducto().getCodigo()] = producto_cantidad;			
}


//TERMINAR ESTA FUNCIONNNNNN!!!
void ControladorProducto::ingresarMenu(){
	Menu *nuevo_menu = new Menu(this->codigo_menu, this->desc_menu);
	menus[nuevo_menu.getCodigo()] = nuevo_menu;
	map<int, DtProductoCantidad>::iterator it;
	for (it = prod_cants_recordados.begin(); it != prod_cants_recordados.end(); ++it){
		Producto *p = productosSimples.find(it->second->getProducto()->getCodigo());
		//FALTA TERMINARRRRR
		//FALTA TERMINAR 
		//FALTA TERMINAR
	}
}
