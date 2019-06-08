//Archivos
#include "../include/ProductoEnMenu.hpp"

ProductoEnMenu::ProductoEnMenu(int cantidad, ProductoSimple *producto){
	this->cantidad = cantidad;
	this->producto = producto;
}

bool ProductoEnMenu::estaProducto(int cod){
	return (this->producto->getCodigo() == cod);
}

int ProductoEnMenu::getCantidad(){
	return this->cantidad;
}

void aumentarCantidad(int cant){
	this->cantidad += cant;
}

ProductoEnMenu::~ProductoEnMenu(){}
