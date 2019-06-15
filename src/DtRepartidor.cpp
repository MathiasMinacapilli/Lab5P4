//Archivos
#include "../include/DtRepartidor.hpp"

DtRepartidor::DtRepartidor() : DtEmpleado() {}

DtRepartidor::DtRepartidor(int numero, string nombre, Transporte medioTransporte) : DtEmpleado(numero, nombre) {
    this->medioTransporte = medioTransporte;
}

Transporte DtRepartidor::getTransporteRepartidor() {
    return this -> medioTransporte;
}

DtRepartidor::~DtRepartidor() {}

ostream& operator<<(ostream & os, DtRepartidor datos){
    os << " Nombre: " << datos.getNombre() << "\n" << " Transporte: " << datos.getTransporteRepartidor() << "\n" << " ID de empleado: " << datos.getNumero() + 1 << "\n";
    return os;
}
