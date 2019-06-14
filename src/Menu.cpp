//Librerias de C
#include <map>
#include <iostream>
using namespace std;

//Archivos
#include "../include/Menu.hpp"

//operaciones
Menu::Menu(int codigo, string descripcion) : Producto(codigo, descripcion, 0){
	this->precio = 0;
}

Menu::~Menu(){}


map<int, ProductoEnMenu *> Menu::getProductos() {
    return this -> productos;
}


void Menu::agregarProducto(ProductoSimple *prod, int cantidad){
	//busco el producto en el menu
	map<int, ProductoEnMenu *>::iterator it = productos.find(prod->getCodigo());
	//si el producto no esta
	if (it == productos.end()){
		//se crea el nuevo producto en menu
		ProductoEnMenu *pm = new ProductoEnMenu(cantidad, prod);
		productos[prod->getCodigo()] = pm;
	}
	else
		it->second->aumentarCantidad(cantidad);
	this->precio += (prod->getPrecio()*cantidad*0.9);

}

bool Menu::esVacio(){
	return productos.empty();
}

bool Menu::eliminarProducto(int cod){
	map<int, ProductoEnMenu *>::iterator it = productos.find(cod);
	//si el producto esta en el menu
	if (it != productos.end()) {
		ProductoEnMenu* prod_menu = (it -> second);
		productos.erase(cod);
		delete prod_menu;
	}
	if (this->esVacio()) {
		return true;
	} else {
		return false;
	}
}

void Menu::eliminar(){
	map<int, ProductoEnMenu *>::iterator it;
	for (it=productos.begin(); it!=productos.end(); ++it)
		delete (it->second);
	productos.clear();
	delete this;
}
