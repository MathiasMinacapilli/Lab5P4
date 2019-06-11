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

ProductoSimple* ProductoEnMenu::getProducto() {
	return this->producto;
}

void ProductoEnMenu::aumentarCantidad(int cant){
	this->cantidad += cant;
}

ProductoEnMenu::~ProductoEnMenu(){}
