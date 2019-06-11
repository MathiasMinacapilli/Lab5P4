//Archivos
#include "../include/DtCliente.hpp"

//constructor por parametros 1
DtCliente::DtCliente(string telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos) {
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
    this->etapaPedidos = etapaPedidos;
}

string DtCliente::getTelefono() {
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

ostream& operator<<(ostream & os, DtCliente datos){
    os << "Telefono: " << datos.getTelefono() << "\n" << "Nombre: " << datos.getNombre() << "\n" << "Direccion: " <<datos.getDireccion();
    return os;
}
