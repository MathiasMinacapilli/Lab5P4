//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/Menu.hpp";

//operaciones
Menu::Menu(int codigo, string descripcion) : Producto(codigo, descripcion, 0){
	this->precio = 0;
}

Menu::~Menu(){}

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

void Menu::eliminarProducto(int cod){
	map<int, ProductoEnMenu *>::iterator it = productos.find(cod);
	//si el producto esta en el menu
	if (it != productos.end()){
		productos.erase(cod);
		delete (it->second);
	}
	if (this->esVacio())
		this->eliminar();
}

void Menu::eliminar(){
	map<int, ProductoEnMenu *>::iterator it;
	for (it=productos.begin(); it!=productos.end(); ++it)
		delete (it->second);
	productos.clear();
	delete this;
}