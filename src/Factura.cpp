//Archivos
#include "../include/Factura.hpp"

Factura::Factura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal) {
    this->codigo = codigo;
    this->fechaYHora = fechaYHora;
    this->productosCantidad = productosCantidad;
    this->iva = iva;
    this->descuento = descuento;
    this->precioSubTotal = precioSubTotal;
    this->precioTotal = precioTotal;
}

Factura::~Factura() {
}

int Factura::getCodigo(){
	return this->codigo;
}

DtFechaYHora Factura::getFechaYHora(){
	return this->fechaYHora;
}

float Factura::getPrecioSubtotal(){
	return this->precioSubTotal;
}

float Factura::getPrecioTotal(){
	return this->precioTotal;
}

DtFactura Factura::getDatosFactura(){
	DtFactura datos = DtFactura(this->codigo, this->fechaYHora, this->productosCantidad, this->iva, this->descuento, this->precioSubTotal, this->precioTotal);
	return datos;
}
