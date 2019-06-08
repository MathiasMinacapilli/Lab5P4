//Archivos
#include "../include/DtCliente.hpp"

DtCliente::DtCliente(int telefono, string nombre, DtDireccion direccion, string mail, string clave, set<DtActualizacion> etapaPedidos) {
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
    this->mail = mail;
    this->clave = clave;this->etapaPedidos = etapaPedidos;
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

string DtCliente::getMail() {
    return this->mail;
}

string DtCliente::getClave() {
    return this->clave;
}

set<DtActualizacion> DtCliente::getEtapaPedidos() {
    return this->etapaPedidos;
}

DtCliente::~DtCliente() {}
