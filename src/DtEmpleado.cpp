//Archivos
#include "../include/DtEmpleado.hpp"

//constructor por defecto
DtEmpleado::DtEmpleado(){}

//constructor por parametros
DtEmpleado::DtEmpleado(int numero, string nombre) {
    this->numero = numero;
    this->nombre = nombre;
}

int DtEmpleado::getNumero() {
    return this->numero;
}

string DtEmpleado::getNombre() {
    return this->nombre;
}

DtEmpleado::~DtEmpleado() {}
