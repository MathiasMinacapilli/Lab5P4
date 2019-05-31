
#include "../include/DtMenu.hpp";

DtProductoSimple::DtProductoSimple(int codigo, string descripcion, float precio, set<DtProductoEnMenu> productos)
:DtProducto(codigo, descripcion, precio) {
    this->productos = productos;
}

set<DtProductoEnMenu> DtProductoSimple::getProductos() {
    return this->productos;
}

DtProductoSimple::~DtProductoSimple() {
    //liberar memoria de productos?
}
