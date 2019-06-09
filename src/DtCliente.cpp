//Archivos
#include "../include/DtCliente.hpp"

//constructor por parametros 1
DtCliente::DtCliente(int telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos) {
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
    this->etapaPedidos = etapaPedidos;
}

int DtCliente::getTelefono() {
    return this->telefono;
}

string DtCliente::getNombre() {
    return this->nombre;
}

DtDireccion DtCliente::getDireccion() {
    return this->direccion;
}

set<DtActualizacion> DtCliente::getEtapaPedidos() {
    return this->etapaPedidos;
}

DtCliente::~DtCliente() {}
