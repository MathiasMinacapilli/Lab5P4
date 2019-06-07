//Archivos
#include "../include/DtFactura.hpp"

DtFactura::DtFactura() {}

DtFactura::DtFactura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal) {
    this->codigo = codigo;
    this->fechaYHora = fechaYHora;
    this->productos = productos;
    this->iva = iva;
    this->descuento = descuento;
    this->precioSubTotal = precioSubTotal;
    this->precioTotal = precioTotal;
}

int DtFactura::getCodigo() {
    return this->codigo;
}

DtFechaYHora DtFactura::getFechaYHora() {
    return this->fechaYHora;
}

map<int, DtProductoCantidad> DtFactura::getProductos() {
    return this->productos;
}

float DtFactura::getIva() {
    return this->iva;
}

float DtFactura::getDescuento() {
    return this->descuento;
}

float DtFactura::getPrecioSubTotal() {
    return this->precioSubTotal;
}

float DtFactura::getPrecioTotal() {
    return this->precioTotal;
}

DtFactura::~DtFactura() {}
