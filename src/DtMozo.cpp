//Archivos
#include "../include/DtMozo.hpp"

//constructor por defecto
DtMozo::DtMozo(): DtEmpleado(){}

//constructor por parametros
DtMozo::DtMozo(int numero, string nombre)
:DtEmpleado(numero, nombre) {

}
//destructor
DtMozo::~DtMozo() {}

ostream& operator<<(ostream & os, DtMozo datos){
    os << " Nombre: " << datos.getNombre() << "\n" << " ID de empleado: " << datos.getNumero() + 1 << "\n";
    return os;
}
