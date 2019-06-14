//Archivos
#include "../include/DtRepartidor.hpp"

DtRepartidor::DtRepartidor() : DtEmpleado() {}

DtRepartidor::DtRepartidor(int numero, string nombre, Transporte medioTransporte) : DtEmpleado(numero, nombre) {
    this->medioTransporte = medioTransporte;
}

string DtRepartidor::getNombreRepartidor() {
    return getNombre();
}

Transporte DtRepartidor::getTransporteRepartidor() {
    return this -> medioTransporte;
}

DtRepartidor::~DtRepartidor() {}

ostream& operator<<(ostream & os, DtRepartidor datos){
    os << " Nombre: " << datos.getNombreRepartidor() << "\n" << " Transporte: " << datos.getTransporteRepartidor() << "\n";
    return os;
}
