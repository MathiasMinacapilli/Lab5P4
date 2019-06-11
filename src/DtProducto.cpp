//Librerias
#include <string>

//Archivos
#include "../include/DtProducto.hpp"

//constructor por defecto
DtProducto::DtProducto(){}

//constructor por parametros
DtProducto::DtProducto(int codigo, string descripcion, float precio) {
 	this -> codigo = codigo;
 	this -> descripcion = descripcion;
 	this -> precio = precio;
}

int DtProducto::getCodigo() {
    return this->codigo;
}

string DtProducto::getDescripcion() {
    return this->descripcion;
}

float DtProducto::getPrecio() {
    return this->precio;
}

DtProducto::~DtProducto(){
}

ostream &operator<< (ostream& o, DtProducto dtp) {
     o << " " << dtp.getCodigo()
        << " - $" << dtp.getPrecio()
        << "    " << dtp.getDescripcion();
    return o;
}
