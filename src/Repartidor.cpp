//Archivos
#include "../include/Repartidor.hpp"

Repartidor::Repartidor(int numero, string nombre, Transporte medioTransporte) : Empleado(numero, nombre) {
  this -> medioTransporte = medioTransporte;
}

Repartidor::~Repartidor() {
}
Transporte Repartidor::getTransporte() {
    return this -> medioTransporte;
}
