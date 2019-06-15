//Archivos
#include "../include/DtProductoCantidad.hpp"

//constructor por defecto
DtProductoCantidad::DtProductoCantidad(){}

//constructor por parametros
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

ostream &operator<< (ostream& o, DtProductoCantidad dtpc) {
    o << dtpc.getProducto()
      << "\nCantidad: "<< dtpc.getCantidad();
    return o;
}
