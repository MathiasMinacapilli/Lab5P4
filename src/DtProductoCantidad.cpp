//Archivos
#include "../include/DtProductoCantidad.hpp"

DtProductoCantidad::DtProductoCantidad(DtProducto producto, int cantidad) {
    this->producto = producto;
    this->cantidad = cantidad;
}

DtProducto DtProductoCantidad::getProducto() {
    return this->producto;
}

int DtProductoCantidad::getCantidad() {
    return this->cantidad;
}

DtProductoCantidad::~DtProductoCantidad() {
    //liberar memoria de producto??
}
