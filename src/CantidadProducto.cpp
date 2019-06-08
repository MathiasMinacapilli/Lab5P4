#include "../include/CantidadProducto.hpp"

CantidadProducto::CantidadProducto(int cantidad, Producto *producto){
	this->cantidad = cantidad;
	this->producto = producto;
}

int CantidadProducto::getCantidad(){
	return this->cantidad;
}

Producto* CantidadProducto::getProducto(){
	return this->producto;
}

void CantidadProducto::setCantidad(int cantidad){
	this->cantidad = cantidad;
}

void CantidadProducto::aumentarCantidad(int cantidad){
	this->cantidad += cantidad;
}

//devuelve true si la cantidad llega a cero
bool CantidadProducto::disminuir(int cant){
	if(cant >= this->cantidad){
		this->cantidad = 0;
		return true;
	}
	else{
		this->cantidad -= cant;
		return false;
	}

}

bool CantidadProducto::estaProducto(int codigo){
	return (this->producto->getCodigo() == codigo);
}

DtProducto CantidadProducto::obtenerDatosProducto(){
	return this->producto->getDatosProducto();
}

void CantidadProducto::quitarProducto(){
	this->producto = nullptr;
	this->cantidad = 0;
}

CantidadProducto::~CantidadProducto(){}