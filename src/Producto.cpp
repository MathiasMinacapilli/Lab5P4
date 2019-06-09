//Librerias de C
using namespace std;

//Archivos
#include "../include/Producto.hpp"

Producto::Producto(int codigo, string descripcion, float precio) {
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
    this->cantidadVendidos = 0;
}

Producto::~Producto(){}

int Producto::getCodigo(){
	return this->codigo;
}

string Producto::getDescripcion(){
	return this->descripcion;
}

float Producto::getPrecio(){
	return this->precio;
}
int Producto::getCantidadVendidos() {
    return this->cantidadVendidos;
}
DtProducto Producto::getDatosProducto() {
    DtProducto dtprod = DtProducto(this->codigo, this->descripcion, this->precio);
    return dtprod;    
}
/* Aumenta el atributo cantidadVendidos sumandole el valor i */
void Producto::aumentarCantidadVendidos(int i) {
    this->cantidadVendidos += i;
}


