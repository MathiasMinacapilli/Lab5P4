//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/ProductoSimple.hpp"

ProductoSimple::ProductoSimple(int codigo, string descripcion, float precio) {
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
}

DtProductoSimple Producto::getDatos() {
    DtProductoSimple dtprodsimple = DtProductoSimple(this->codigo, this->descripcion, this->precio);                                                                                                                                                                   
    return dtprod;    
}


