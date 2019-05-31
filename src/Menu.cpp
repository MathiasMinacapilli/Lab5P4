//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/Menu.hpp";

//operaciones
void Menu::agregarProducto(ProductoSimple *prod, int cantidad){
	ProductoEnMenu *pm = new ProductoEnMenu(cantidad, prod);
	productos[prod->getCodigo()] = pm;
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