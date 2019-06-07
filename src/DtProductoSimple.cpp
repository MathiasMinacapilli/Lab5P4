//Archivos
#include "../include/DtProductoSimple.hpp"


DtProductoSimple::DtProductoSimple() : DtProducto() {
}

DtProductoSimple::DtProductoSimple(int codigo, string descripcion, float precio)
:DtProducto(codigo, descripcion, precio) {
}

DtProductoSimple::~DtProductoSimple() {}
