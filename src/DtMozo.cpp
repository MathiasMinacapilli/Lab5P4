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
