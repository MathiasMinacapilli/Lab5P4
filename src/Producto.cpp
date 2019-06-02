//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/Producto.hpp";

Producto::Producto(int codigo, string descripcion, float precio) {
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
}

Producto::~Producto(){}

int Producto::getCodigo(){
	return this->codigo;
}

string Producto::getDescripciom(){
	return this->descripcion;
}

int Producto::getPrecio(){
	return this->precio;
}
DtProducto Producto::getDatosProducto() {
    DtProducto dtprod = DtProducto(this->codigo, this->descripcion, this->precio);
    return dtprod;    
}


